// Advent of Code 2020

#include <cassert>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#include "../helper-classes/list-reader.h"
#include "../helper-classes/string-manipulation.h"
#include "bag_rules.h"

// class BagGraph;

// BagRule::BagRule(const std::string& input_line, BagGraph& bag_graph) {
//   assert(input_line[input_line.size() - 1] != '.');

//   std::vector<std::string> rule_data = data::string_split(input_line, " bags
//   contain "); assert(rule_data.size() == 2); _color = rule_data[0];
//   bag_graph.nodes.insert(std::make_pair(rule_data[0],
//   std::shared_ptr<BagRule>(this)));
// }

using Edge = std::pair<std::string, int>;
using BagRule = std::tuple<std::string /* origin */, int /* weight */,
                           std::string /* destination */>;
using BagMap = std::unordered_map<std::string, std::vector<Edge>>;

constexpr char filepath[] = "../day-07/test_input.txt";
constexpr char target_bag[] = "shiny gold";
constexpr char no_bags[] = "no other bags";

namespace {

std::vector<BagRule> CreateBagRule(const std::string &line) {
  assert(line[line.size() - 1] != '.');
  std::vector<BagRule> ret;

  std::vector<std::string> rule_data =
      data::string_split(line, " bags contain ");
  assert(rule_data.size() == 2);
  std::string origin_color = rule_data[0];

  int weight = -1;
  std::string dest_color;

  if (rule_data[1] != no_bags) {
    for (const auto &rule : data::string_split(rule_data[1], ", ")) {
      const auto &split_rule = data::string_split(rule, " ");

      assert(split_rule[0].find_first_not_of("0123456789") ==
             std::string::npos);
      weight = std::stoi(split_rule[0]);
      // split_rule[3] == "bags", and therefore can be discarded
      dest_color = split_rule[1] + " " + split_rule[2];
      ret.push_back(std::make_tuple(origin_color, weight, dest_color));
    }
  }

  return ret;
}

} // namespace

void operator<<(std::ostream &os,
                std::tuple<std::string, int, std::string> obj) {
  os << "\"" << std::get<0>(obj) << "\""
     << ":" << std::get<1>(obj) << ":"
     << "\"" << std::get<2>(obj) << "\"" << std::endl;
}

void operator<<(std::ostream &os, const Edge& obj) {
  os << "\"" << obj.first << "\""
     << ":" << obj.second << std::endl;
}

// Generate a directed map of reverse edges, where each node knows the edges
// that point to it
BagMap BuildBagRulesMap(bool inverted = false) {
  std::unordered_map<std::string, std::vector<Edge>> ret;
  for (const std::string &line : data::GetStringList(filepath)) {
    // Delete last character to remove '.' at end of every line
    const auto &rule_list = CreateBagRule(line.substr(0, line.size() - 1));

    // TODO: add an entry if there are no rules / node is a sink
    if (rule_list.empty())
      ret.insert();
    for (const auto &rule : rule_list) {
      const std::string &key_color =
          inverted ? std::get<2>(rule) : std::get<0>(rule);
      const std::string &dest_color =
          inverted ? std::get<0>(rule) : std::get<2>(rule);

      if (ret.find(key_color) == ret.end()) {
        ret.insert(std::make_pair(key_color, std::vector<Edge>()));
      }

      auto &edge_list = ret.find(key_color)->second;
      edge_list.push_back(std::make_pair(dest_color, std::get<1>(rule)));
    }
  }

  return ret;
}

void ComputePart1() {
  const auto &node_map = BuildBagRulesMap(true);
  assert(node_map.find(target_bag) != node_map.end());

  std::unordered_set<std::string> gold_accessible_bags;
  std::queue<std::string> bfs_queue;
  std::string target(target_bag);

  bfs_queue.push(target);
  while (!bfs_queue.empty()) {
    std::string current_bag = bfs_queue.front();
    bfs_queue.pop();
    gold_accessible_bags.insert(current_bag);

    if (node_map.find(current_bag) != node_map.end()) {
      const auto &edge_list = node_map.find(current_bag)->second;
      for (const auto &edge : edge_list) {
        bfs_queue.push(edge.first);
      }
    }
  }
  gold_accessible_bags.erase(std::string(target));

  std::cout << "Part 1 - Num of Bags that can access '" << target
            << "' bags: " + std::to_string(gold_accessible_bags.size())
            << std::endl;
}

// void ComputePart2() {
// const auto &node_map = BuildBagRulesMap(false);
// assert(node_map.find(target_bag) != node_map.end());

//   std::unordered_set<std::string> seen_bags;
//   std::queue<std::string> bfs_queue;
//   int edge_count = 0;
//   std::string target(target_bag);

//   bfs_queue.push(target);
//   while (!bfs_queue.empty()) {
//     std::string current_bag = bfs_queue.front();
//     bfs_queue.pop();
//     seen_bags.insert(current_bag);

//     if (node_map.find(current_bag) != node_map.end()) {
//       const auto &edge_list = node_map.find(current_bag)->second;
//       for (const auto &edge : edge_list) {
//         bfs_queue.push(edge.first);
//         edge_count += edge.second;
//       }
//     }
//   }
//   std::cout << "Part 2 - Num of Bags inside '" << target
//             << "' bags: " + std::to_string(edge_count) << std::endl;
// }

int WeightedDfsExpansion(const std::string& key, const BagMap* const node_map, std::unordered_set<std::string>* const seen_nodes) {
  // if (seen_nodes->find(key) != seen_nodes->end())
  //   return 1;

  std::cout << "Key: " << key << std::endl;
  // A key with no entry in the map is a sink
  // Recursion ends when a node has no rules / the list is empty.
  if (node_map->find(key) == node_map->end()) {
    std::cout<< "Found sink" << std::endl << std::endl;
    return 1;
  }

  int count = 1;
  const std::vector<Edge> &rule_list = node_map->find(key)->second;

  for (const auto &rule : rule_list) {
    std::cout << key << "->";
    std::cout << rule;
    count += rule.second * WeightedDfsExpansion(rule.first, node_map, seen_nodes);
    // seen_nodes->insert(rule.first);
  }
  return count;
}

void ComputePart2() {
  const auto &node_map = BuildBagRulesMap(false);
  assert(node_map.find(target_bag) != node_map.end());

  std::unordered_set<std::string> seen_nodes;
  int total = WeightedDfsExpansion(target_bag, &node_map, &seen_nodes);
  std::cout << "Part 2 - Total bags within '" << target_bag << "'"
            << " bags: "
            << std::to_string(total) << std::endl;;
}

int main(int argc, char **argv) {
  ComputePart1();
  ComputePart2();
}

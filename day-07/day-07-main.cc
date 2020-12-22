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

using Edge = std::pair<std::string, int>;
using BagRule = std::pair<std::string /* origin */, Edge>;
using BagMap = std::unordered_map<std::string, std::vector<Edge>>;

constexpr char filepath[] = "../day-07/advent-day-07-data.txt";
constexpr char target_bag[] = "shiny gold";
constexpr char no_bags[] = "no other bags";

namespace {

// Return a list of bag rules, which describes information regarding how a
// certain color of bag can contain other types of bags. A bag rule specifies
// a given edge to another bag, which can be empty (representing a sink in the
// bag directed graph).
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
      ret.push_back(
          std::make_pair(origin_color, std::make_pair(dest_color, weight)));
    }
  } else {
    ret.push_back(std::make_pair(origin_color, Edge()));
  }

  return ret;
}

int WeightedDfsExpansion(const std::string &key, const BagMap *const node_map,
                         std::unordered_set<std::string> *const seen_nodes) {
  // A key with no entry in the map is a sink
  // Recursion ends when a node has no rules / the list is empty.
  if (node_map->find(key) == node_map->end()) {
    return 1;
  }

  int count = key == target_bag ? 0 : 1;
  const std::vector<Edge> &rule_list = node_map->find(key)->second;

  for (const auto &rule : rule_list) {
    count +=
        rule.second * WeightedDfsExpansion(rule.first, node_map, seen_nodes);
  }
  return count;
}

} // namespace

void operator<<(std::ostream &os, const BagRule &obj) {
  os << "\"" << obj.first << "\""
     << ":" << obj.second.second << ":"
     << "\"" << obj.second.first << "\"" << std::endl;
}

void operator<<(std::ostream &os, const Edge &obj) {
  os << "\"" << obj.first << "\""
     << ":" << obj.second << std::endl;
}

// Generate a directed graph of bags, represented as a hash map of nodes
// associated with weighted edges to other bags. If |inverted| is set to true,
// the direction of the edges is reversed and represent all egdes that point to
// the specified bag.
BagMap BuildBagRulesMap(bool inverted = false) {
  std::unordered_map<std::string, std::vector<Edge>> ret;
  for (const std::string &line : data::GetStringList(filepath)) {
    // Delete last character to remove '.' at end of every line
    auto rule_list = CreateBagRule(line.substr(0, line.size() - 1));

    for (auto &rule : rule_list) {
      // Handle inverting the edges, if there is a valid edge
      bool is_sink = rule.second.first.empty();
      if (!is_sink && inverted) {
        std::string temp = rule.second.first;
        rule.second.first = rule.first;
        rule.first = temp;
      }

      // Every bag needs to have an entry in the map
      if (ret.find(rule.first) == ret.end()) {
        ret.insert(std::make_pair(rule.first, std::vector<Edge>()));
      }

      // If the node is a sink, there is no valid entry in an inverted graph for
      // this specific rule
      if (is_sink && inverted) {
        continue;
      }
      ret.find(rule.first)->second.push_back(rule.second);
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

void ComputePart2() {
  const auto &node_map = BuildBagRulesMap(false);
  assert(node_map.find(target_bag) != node_map.end());

  std::unordered_set<std::string> seen_nodes;
  int total = WeightedDfsExpansion(target_bag, &node_map, &seen_nodes);
  std::cout << "Part 2 - Total bags within '" << target_bag << "'"
            << " bags: " << std::to_string(total) << std::endl;
  ;
}

int main(int argc, char **argv) {
  ComputePart1();
  ComputePart2();
}

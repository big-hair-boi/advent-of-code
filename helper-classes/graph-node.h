// Advent of Code 2020

#ifndef HELPER_CLASSES_GRAPH_NODE_H_
#define HELPER_CLASSES_GRAPH_NODE_H_

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

class GraphNode {
public:
  using EdgeInfo = std::pair<std::string, int>;

  // explicit GraphNode(const std::string &key,
  //                    std::vector<std::string> &edge_str_list)
  //     : _key(key), _edge_str_list(edge_str_list), _edges() {};

  explicit GraphNode(const std::string &key);
  explicit GraphNode(const std::string &key, std::vector<EdgeInfo> edges)
      : GraphNode(key), _edges(edges){};

  ~GraphNode() = default;
  GraphNode(GraphNode &&) = default;
  GraphNode &operator=(GraphNode &&) = default;
  GraphNode(GraphNode &) = delete;
  GraphNode &operator=(GraphNode &) = delete;

  void SetEdge(const EdgeInfo &edge);
  std::optional<int> GetEdge(const std::string &key);

private:
  // virtual EdgeInfo ExtractInfoFromEdgeStr(const std::string& edge_str) = 0;

  // const std::string _key;
  // std::vector<std::string> _edge_str_list;
  // std::unordered_map<GraphNode *, int> _edges;

  const std::string &_key;
  const std::unordered_map<std::string, int> _edges;

  static std::unordered_map<std::string, std::unique_ptr<GraphNode>> node_map;
};

#endif // HELPER_CLASSES_GRAPH_NODE_H_

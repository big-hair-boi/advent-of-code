// // Advent of Code

// #ifndef HELPER_CLASSES_DIRECTED_GRAPH_H_
// #define HELPER_CLASSES_DIRECTED_GRAPH_H_

// #include <memory>
// #include <string>
// #include <unordered_map>
// #include <vector>

// // // A directed graph of value_T objects referenced by key_T keys
// // template <typename key_T, typename value_T>
// // class DirectedGraph {
// //  public:
// //   // Construct a graph for a given file
// //   explicit DirectedGraph(const std::string& filepath);

// //   value_T* GetNode(const key_T& name);

// //  private:
// //   template<typename input_type>
// //   value_T CreateNode(const input_type& node_input) = 0;

// //   // Create a list of inputs that can be fed into CreateNode() to instantiate
// //   // nodes from file.
// //   virtual std::vector<input_type> CreateInputList() = 0;

// //   // member variables
// //   std::unordered_map<std::string, std::unique_ptr<value_T>> _nodes;
// //   const std::string& _filepath;
// // };

// // A node associated with a string key and instantiated from a list of strings
// class Node {
// private:
//   // Constructor can't be made abstract, so add layer of indirection
//   virtual void Initialize(const std::vector<std::string> &input_list) = 0;

// public:
//   Node(const std::vector<std::string> &input_list) : _key(std::string()) {
//     Initialize(input_list);
//   };
//   virtual ~Node() = default;
//   Node(Node &&) = default;
//   Node &operator=(Node &&) = default;
//   Node(const Node &) = delete;
//   const Node &operator=(const Node &) = delete;

// private:
//   std::string _key;
//   std::unordered_map<std::string, int> _edges;
// };

// class Graph {
//   Graph(const std::string &filepath);
//   ~Graph() = default;
//   Graph(Graph &&) = default;
//   Graph &operator=(Graph &&) = default;
//   Graph(const Graph &) = delete;
//   const Graph &operator=(const Graph &) = delete;

//   Node *GetNode(const std::string &key);
//   virtual Node CreateNode(const std::vector<std::string> &input_list) = 0;
//   virtual std::vector<std::vector<std::string>> CreateInputLists() = 0;

// private:
//   std::string _filepath;
//   std::unordered_map<std::string, std::unique_ptr<Node>> _nodes;
// };

// #endif // HELPER_CLASSES_DIRECTED_GRAPH_H_
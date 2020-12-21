// // Advent of Code 2020

// #include "graph.h"

// #include <cassert>


// // template <typename key_T, typename value_T>
// // DirectedGraph<key_T, value_T>::DirectedGraph(const std::string& filepath)
// //     : _nodes(std::unordered_map<std::string, std::unique_ptr<value_T>>),
// //       _filepath(filepath) {
// //   template<typename input_type>
// //   for (const input_type& input : DirectedGraph<key_T, value_T>::CreateInputList()) {

// //   }
// // }

// // template <typename key_T, typename value_T>
// // value_T* DirectedGraph<key_T, value_T>::GetNode(const key_T& key) {
//   // auto node_uptr = _nodes.find(key);
//   // if (node_uptr && node_uptr != _nodes.end()) {
//   //   return node_uptr->get();
//   // }
//   // else {
//   //   return nullptr;
//   // }
// // }

// Graph::Graph(const std::string& filepath) : _filepath(filepath) {
//   for (const auto& input_list : CreateInputLists()) {
//     Node node = CreateNode(input_list);
//   }
// }

// Node* Graph::GetNode(const std::string& key) {
//   const auto& node = _nodes.find(key);
//   if (node != _nodes.end()) {
//     return node->second.get();
//   }
//   else {
//     return nullptr;
//   }
// }

#include "node.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

Node::Node() : value_{nullptr}, next_node_{nullptr} {}

// Node::Node(std::unique_ptr<unsigned int> value)
//     : value_{std::move(value)}, next_node_{nullptr} {}

auto Node::SetValue(std::unique_ptr<unsigned int> value) -> Node& {
  value_ = std::move(value);

  return *this;
}

auto Node::GetValue() const -> unsigned int* { return value_.get(); }

auto Node::SetNextNode(std::unique_ptr<Node> next_node) -> Node& {
  next_node_ = std::move(next_node);

  return *this;
}

auto Node::GetNextNode() const -> Node* { return next_node_.get(); }

auto Node::GetNextNodeOwnership() -> std::unique_ptr<Node> {
  return std::move(next_node_);
}

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

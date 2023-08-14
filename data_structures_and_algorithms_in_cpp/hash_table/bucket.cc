#include "bucket.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

Bucket::Bucket() : first_node_{nullptr} {}

auto Bucket::SetFirstNode(std::unique_ptr<Node> first_node) -> void {
  first_node_ = std::move(first_node);
}

auto Bucket::GetFirstNode() const -> Node* { return first_node_.get(); }

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

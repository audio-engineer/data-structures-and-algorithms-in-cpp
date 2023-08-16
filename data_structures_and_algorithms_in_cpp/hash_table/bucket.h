#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_BUCKET_H
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_BUCKET_H

#include "node.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

class Bucket {
 private:
  std::unique_ptr<Node> first_node_;

 public:
  Bucket();
  auto SetFirstNode(std::unique_ptr<Node> first_node) -> void;
  [[nodiscard]] auto GetFirstNode() const -> Node*;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_BUCKET_H

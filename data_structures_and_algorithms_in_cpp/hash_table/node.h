#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_ITEM_H_
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_ITEM_H_

#include <memory>

namespace data_structures_and_algorithms_in_cpp::hash_table {

class Node {
 private:
  std::unique_ptr<unsigned int> value_;
  std::unique_ptr<Node> next_node_;

 public:
  Node();
  //  explicit Node(std::unique_ptr<unsigned int> value);
  auto SetValue(std::unique_ptr<unsigned int> value) -> Node&;
  [[nodiscard]] auto GetValue() const -> unsigned int*;
  auto SetNextNode(std::unique_ptr<Node> next_node) -> Node&;
  [[nodiscard]] auto GetNextNode() const -> Node*;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_ITEM_H_

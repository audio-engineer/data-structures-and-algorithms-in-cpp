#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_ITEM_H_
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_ITEM_H_

namespace data_structures_and_algorithms_in_cpp::hash_table {

class Item {
 private:
  unsigned int *value_;

 public:
  Item();
  explicit Item(unsigned int value);
  [[nodiscard]] auto GetValue() const -> unsigned int *;
  auto SetValue(unsigned int *value) -> void;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_ITEM_H_

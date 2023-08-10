#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_HASH_TABLE_H_
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_HASH_TABLE_H_

#include <vector>

#include "item.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

class HashTable {
 private:
  unsigned int hash_table_size_{0};
  std::vector<Item> items_;
  [[nodiscard]] auto GetHash(unsigned int value) const -> unsigned int;

 public:
  explicit HashTable(unsigned int size);
  auto Insert(Item item) -> void;
  auto Remove(unsigned int value) -> bool;
  [[nodiscard]] auto Find(unsigned int value) const -> const Item*;
  [[nodiscard]] auto GetItems() const -> std::vector<Item>;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_HASH_TABLE_H_

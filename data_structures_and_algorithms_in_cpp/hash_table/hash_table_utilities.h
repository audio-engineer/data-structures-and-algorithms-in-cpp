#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_UTILITIES_H_
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_UTILITIES_H_

#include "hash_table.h"
#include "node.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

struct HashTableUtilities {
 public:
  static auto Insert(HashTable &hash_table) -> void;
  static auto Find(const HashTable &hash_table, unsigned int value) -> void;
  static auto Remove(HashTable &hash_table, unsigned int value) -> void;
  static auto PrintHashTable(const HashTable &hash_table) -> void;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_UTILITIES_H_

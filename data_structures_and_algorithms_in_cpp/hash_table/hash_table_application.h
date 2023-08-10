#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_APPLICATION_H_
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_APPLICATION_H_

#include <string>

#include "hash_table.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

class HashTableApplication {
 private:
  static auto NumericPrompt(const std::string &prompt_text) -> unsigned int;
  static auto Find(const HashTable &hash_table) -> void;
  static auto Remove(HashTable &hash_table) -> void;
  static auto PrintMenu() -> void;

 public:
  static auto Run() -> void;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_APPLICATION_H_

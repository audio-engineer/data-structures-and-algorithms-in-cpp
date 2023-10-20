#ifndef DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_HASH_TABLE_H_
#define DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_HASH_TABLE_H_

#include <memory>
#include <tuple>
#include <variant>
#include <vector>

#include "bucket.h"
#include "node.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

class HashTable {
 private:
  unsigned int hash_table_size_{0};
  std::unique_ptr<std::vector<std::unique_ptr<Bucket>>> buckets_;
  [[nodiscard]] auto GetHash(unsigned int value) const -> unsigned int;

 public:
  explicit HashTable(unsigned int size);
  auto Insert(std::unique_ptr<Node> node) -> void;
  auto Remove(unsigned int value) -> bool;
  [[nodiscard]] auto Find(unsigned int value) const
      -> std::variant<Node*, std::tuple<Node*, Node*>>;
  [[nodiscard]] auto GetBuckets() const
      -> std::vector<std::unique_ptr<Bucket>>&;
};

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

#endif  // DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_HASH_TABLE_HASH_TABLE_H_

#include "hash_table.h"

#include <iostream>

namespace data_structures_and_algorithms_in_cpp::hash_table {

HashTable::HashTable(unsigned int size) : hash_table_size_{size} {
  buckets_ = std::make_unique<std::vector<std::unique_ptr<Bucket>>>();

  buckets_->reserve(hash_table_size_);

  for (auto i = 0; i < hash_table_size_; i++) {
    buckets_->push_back(std::make_unique<Bucket>());
  }
}

auto HashTable::GetHash(unsigned int value) const -> unsigned int {
  return value % hash_table_size_;
}

auto HashTable::Insert(std::unique_ptr<Node> node) -> void {
  const unsigned int kHash{GetHash(*node->GetValue())};

  if (buckets_->operator[](kHash)->GetFirstNode() == nullptr) {
    buckets_->operator[](kHash)->SetFirstNode(std::move(node));

    return;
  }

  auto* current_node = buckets_->operator[](kHash)->GetFirstNode();

  while (current_node->GetNextNode() != nullptr) {
    current_node = current_node->GetNextNode();
  }

  current_node->SetNextNode(std::move(node));
}

auto HashTable::Remove(unsigned int value) -> bool {
  const unsigned int kHash{GetHash(value)};
  const auto* kItem = Find(value);

  if (kItem == nullptr) {
    return false;
  }

  buckets_->operator[](kHash)->GetFirstNode()->SetValue(nullptr);

  return true;
}

auto HashTable::Find(unsigned int value) const -> Node* {
  const unsigned int kHash{GetHash(value)};

  auto* current_node = buckets_->operator[](kHash)->GetFirstNode();

  while (current_node->GetNextNode() != nullptr) {
    current_node = current_node->GetNextNode();

    if (*current_node->GetValue() != value) {
      continue;
    }

    return current_node;
  }

  return nullptr;
}

auto HashTable::GetBuckets() const -> std::vector<std::unique_ptr<Bucket>>& {
  return *buckets_;
}

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

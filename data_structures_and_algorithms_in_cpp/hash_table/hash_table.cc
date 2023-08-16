#include "hash_table.h"

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
  const auto& kBucket{buckets_->operator[](kHash)};
  Node* current_node{kBucket->GetFirstNode()};

  if (current_node == nullptr) {
    kBucket->SetFirstNode(std::move(node));

    return;
  }

  while (current_node->GetNextNode() != nullptr) {
    current_node = current_node->GetNextNode();
  }

  current_node->SetNextNode(std::move(node));
}

auto HashTable::Remove(unsigned int value) -> bool {
  const unsigned int kHash{GetHash(value)};
  const auto& kBuckets = *buckets_;
  const auto kSearchResult{Find(value)};

  std::visit(
      [&kBuckets, kHash](const auto& data) {
        using T = std::decay_t<decltype(data)>;

        if constexpr (std::is_same_v<T, Node*>) {
          if (data != nullptr && kBuckets[kHash]->GetFirstNode() == data) {
            kBuckets[kHash]->SetFirstNode(nullptr);
          }
        }

        if constexpr (std::is_same_v<T, std::tuple<Node*, Node*>>) {
          Node* previous_node{std::get<0>(data)};
          Node* current_node{std::get<1>(data)};

          if (previous_node != nullptr &&
              current_node->GetNextNode() != nullptr) {
            previous_node->SetNextNode(
                std::move(current_node->GetNextNodeOwnership()));

            return;
          }

          if (previous_node != nullptr) {
            previous_node->SetNextNode(nullptr);
          }
        }
      },
      kSearchResult);

  return true;
}

auto HashTable::Find(unsigned int value) const
    -> std::variant<Node*, std::tuple<Node*, Node*>> {
  const unsigned int kHash{GetHash(value)};
  Node* current_node{buckets_->operator[](kHash)->GetFirstNode()};
  Node* previous_node{nullptr};

  while (current_node->GetNextNode() != nullptr) {
    previous_node = current_node;
    current_node = current_node->GetNextNode();

    if (*current_node->GetValue() != value) {
      continue;
    }

    return std::tuple<Node*, Node*>{previous_node, current_node};
  }

  return current_node;
}

auto HashTable::GetBuckets() const -> std::vector<std::unique_ptr<Bucket>>& {
  return *buckets_;
}

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

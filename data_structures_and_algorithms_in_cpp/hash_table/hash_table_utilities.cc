#include "hash_table_utilities.h"

#include <iomanip>
#include <iostream>

namespace data_structures_and_algorithms_in_cpp::hash_table {

auto HashTableUtilities::Insert(HashTable &hash_table) -> void {
  std::string input;
  unsigned int int_input{0};

  std::cout << "Enter the value to insert: ";
  std::getline(std::cin, input);

  int_input = std::stoi(input);

  auto node = std::make_unique<Node>();
  node->SetValue(std::move(std::make_unique<unsigned int>(int_input)));
  hash_table.Insert(std::move(node));
}

auto HashTableUtilities::Find(const HashTable &hash_table, unsigned int value)
    -> void {
  const auto *kItem{hash_table.Find(value)};

  if (kItem == nullptr) {
    std::cout << "The value " << value
              << " could not be found in the hash table." << '\n';

    return;
  }

  std::cout << "Node with value " << value << " found at index "
            << "" << '\n';
}

auto HashTableUtilities::Remove(HashTable &hash_table, unsigned int value)
    -> void {
  const bool kSuccess = hash_table.Remove(value);

  if (!kSuccess) {
    std::cout << "Operation failed." << '\n';

    return;
  }
}

auto HashTableUtilities::PrintHashTable(const HashTable &hash_table) -> void {
  const int kColumnWidth{15};

  std::cout << std::setw(kColumnWidth) << std::left << "Hash"
            << "Values" << '\n';

  size_t index{0};
  const auto *buckets = &hash_table.GetBuckets();

  for (auto const &bucket : *buckets) {
    if (bucket->GetFirstNode() == nullptr) {
      std::cout << std::setw(kColumnWidth) << std::left << index << "*" << '\n';
      ++index;

      continue;
    }

    if (bucket->GetFirstNode()->GetNextNode() != nullptr) {
      auto *current_node = bucket->GetFirstNode();

      std::cout << std::setw(kColumnWidth) << std::left << index;

      while (current_node->GetNextNode() != nullptr) {
        std::cout << *current_node->GetValue() << " -> ";

        current_node = current_node->GetNextNode();
      }

      std::cout << *current_node->GetValue() << '\n';

      ++index;

      continue;
    }

    std::cout << std::setw(kColumnWidth) << std::left << index
              << *bucket->GetFirstNode()->GetValue() << '\n';

    ++index;
  }
}

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

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

  hash_table.Insert(Item{int_input});
}

auto HashTableUtilities::Find(const HashTable &hash_table, unsigned int value)
    -> void {
  const Item *kItem{hash_table.Find(value)};

  if (kItem == nullptr) {
    std::cout << "The value " << value
              << " could not be found in the hash table." << '\n';

    return;
  }

  std::cout << "Item with value " << value << " found at index "
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
            << "Value" << '\n';

  size_t index{0};
  for (Item const &item : hash_table.GetItems()) {
    if (item.GetValue() == nullptr) {
      std::cout << std::setw(kColumnWidth) << std::left << index << "*" << '\n';
      ++index;

      continue;
    }

    std::cout << std::setw(kColumnWidth) << std::left << index
              << *item.GetValue() << '\n';
    ++index;
  }
}

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

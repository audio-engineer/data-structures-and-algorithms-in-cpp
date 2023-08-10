#include "hash_table.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

HashTable::HashTable(unsigned int size)
    : hash_table_size_{size}, items_{hash_table_size_, Item{}} {}

auto HashTable::GetHash(unsigned int value) const -> unsigned int {
  return value % hash_table_size_;
}

auto HashTable::Insert(Item item) -> void {
  unsigned int hash{GetHash(*item.GetValue())};

  while (items_[hash].GetValue() != nullptr) {
    ++hash;
    hash %= hash_table_size_;
  }

  items_[hash] = item;
}

auto HashTable::Remove(unsigned int value) -> bool {
  const unsigned int kHash{GetHash(value)};
  const Item* kItem = Find(value);

  if (kItem == nullptr) {
    return false;
  }

  items_[kHash].SetValue(nullptr);

  return true;
}

auto HashTable::Find(unsigned int value) const -> const Item* {
  unsigned int hash{GetHash(value)};
  const unsigned int* kValue{items_[hash].GetValue()};

  while (kValue != nullptr) {
    if (*kValue == value) {
      return &items_[hash];
    }

    ++hash;
    kValue = items_[hash].GetValue();
  }

  return nullptr;
}

auto HashTable::GetItems() const -> std::vector<Item> { return items_; }

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

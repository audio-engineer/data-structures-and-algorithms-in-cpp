#include "item.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

Item::Item() : value_{nullptr} {}

Item::Item(unsigned int value) : value_{new unsigned int{value}} {}

auto Item::GetValue() const -> unsigned int* { return value_; }

auto Item::SetValue(unsigned int* value) -> void { value_ = value; }

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

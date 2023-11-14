#include "hash_table_application.h"

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <variant>

#include "hash_table.h"
#include "hash_table_utilities.h"

namespace data_structures_and_algorithms_in_cpp::hash_table {

using FunctionVariants =
    std::variant<void (*)(const HashTable&), void (*)(HashTable&),
                 void (*)(const HashTable&, const unsigned int)>;
using CommandDictionary = std::map<Commands, FunctionVariants>;

auto HashTableApplication::NumericPrompt(const std::string& prompt_text)
    -> unsigned int {
  std::string string_input;
  unsigned int int_input{0};

  while (true) {
    std::cout << prompt_text;
    std::getline(std::cin, string_input);

    try {
      int_input = std::stoi(string_input);

      break;
    } catch (std::out_of_range const& ex) {
      std::cout << "Size " << string_input
                << " is bigger than the allowed size of the type \"int\"."
                << '\n';
    } catch (std::invalid_argument const& ex) {
      std::cout << "Invalid input. Please enter a valid integer." << '\n';
    }
  }

  return int_input;
}

auto HashTableApplication::Find(const HashTable& hash_table) -> void {
  HashTableUtilities::Find(
      hash_table, NumericPrompt("Enter the value you are searching for: "));
}

auto HashTableApplication::Remove(HashTable& hash_table) -> void {
  HashTableUtilities::Remove(
      hash_table, NumericPrompt("Enter the value you want to remove: "));
}

auto HashTableApplication::PrintMenu() -> void {
  std::cout << "Hash table interactive CLI" << '\n'
            << "Press a number to select one of the following options:" << '\n'
            << "\t(1) Add" << '\n'
            << "\t(2) Remove" << '\n'
            << "\t(3) Find" << '\n'
            << "\t(4) Print" << '\n'
            << "\t(5) Quit" << '\n'
            << '\n';
}

auto HashTableApplication::Run() -> void {
  HashTable hash_table{NumericPrompt("Enter the size of the hash table: ")};

  CommandDictionary command_dictionary;
  command_dictionary[Commands::kInsert] = &HashTableUtilities::Insert;
  command_dictionary[Commands::kRemove] = &HashTableApplication::Remove;
  command_dictionary[Commands::kFind] = &HashTableApplication::Find;
  command_dictionary[Commands::kPrint] = &HashTableUtilities::PrintHashTable;

  PrintMenu();

  while (const auto kCommand = NumericPrompt("Enter a command: ")) {
    switch (static_cast<Commands>(kCommand)) {
      case Commands::kInsert: {
        const auto kInsertCommand = std::get<void (*)(HashTable& hash_table)>(
            command_dictionary[Commands::kInsert]);
        kInsertCommand(hash_table);
        break;
      }
      case Commands::kRemove: {
        const auto kRemoveCommand = std::get<void (*)(HashTable& hash_table)>(
            command_dictionary[Commands::kRemove]);
        kRemoveCommand(hash_table);
        break;
      }
      case Commands::kFind: {
        const auto kFindCommand =
            std::get<void (*)(const HashTable& hash_table)>(
                command_dictionary[Commands::kFind]);
        kFindCommand(hash_table);
        break;
      }
      case Commands::kPrint: {
        const auto kPrintCommand =
            std::get<void (*)(const HashTable& hash_table)>(
                command_dictionary[Commands::kPrint]);
        kPrintCommand(hash_table);
        break;
      }
      case Commands::kQuit: {
        return;
      }
      default:
        std::cout << "Invalid command." << '\n';
    }
  }
}

}  // namespace data_structures_and_algorithms_in_cpp::hash_table

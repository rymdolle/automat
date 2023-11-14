#include <iostream>
#include <vector>

#include "item.h"

void print_menu(std::vector<Item> &supply)
{
  std::cout << "\tMENU\n";
  std::cout << "\t====\n";

  // Find width of names
  size_t width = 10;
  for (auto &it : supply)
    width = std::max(width, it.name().size());

  for (int i = 0; i < supply.size(); i++) {
    std::cout << std::setw(4)     << std::right << i + 1 << ". "
              << std::setw(width+2) << std::left  << supply[i].name()
              << supply[i].cost() << " kr"
              << '\n';
  }
  std::cout << '\n';
}


std::vector<Item> supply = {
  Item("Coffee",     20),
  Item("Chocolate",  15),
  Item("Espresso",   22),
  Item("Latte",      24),
  Item("Cappuccino", 27),
};

int main(int argc, char *argv[])
{
  print_menu(supply);

  int choice;
  std::cout << "Choose a drink between 1 and " << supply.size() << ".\n";
  std::cin >> choice;
  if (choice < 1 || choice > supply.size()) {
    std::cout << "Invalid input.\n";
    exit(1);
  }

  Item drink = supply[choice - 1];
  std::cout << "You chose " << drink.name() << " (" << drink.cost() << " kr)\n";

  int change = drink.pay();
  drink.get_change(change);

  std::cout << '\n'
            << "Here is your hot " << drink.name() << ".\n"
            << "  Enjoy!"                << '\n'
            << "         {"              << '\n'
            << "      {   }"             << '\n'
            << "       }_{ __{"          << '\n'
            << "    .-{   }   }-."       << '\n'
            << "   (   }     {   )"      << '\n'
            << "   |`-.._____..-'|"      << '\n'
            << "   |             ;--."   << '\n'
            << "   |            (__  \\" << '\n'
            << "   |             | )  )" << '\n'
            << "   |             |/  /"  << '\n'
            << "   |             /  /"   << '\n'
            << "   |            (  /"    << '\n'
            << "   \\             y'"    << '\n'
            << "    `-.._____..-'"       << '\n'
            << '\n';
  return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>

#include "item.hpp"

void print_menu(std::vector<Item> &supply) {
  std::cout << "MENY" << std::endl;
  std::cout << "====" << std::endl;

  // Get max width of items
  size_t width = 10;
  for (auto it : supply)
    width = std::max(width, it.name.size());

  for (size_t i = 0; i < supply.size(); i++) {
    double cost = static_cast<double>(supply[i].cost) / 100.d;
    std::cout << std::setw(2)         << std::right << i + 1 << ". "
              << std::setw(width)     << std::left  << supply[i].name << " "
              << std::setprecision(2) << std::fixed << cost
              << std::endl;
  }
  std::cout << std::endl;
}

std::vector<Item> supply = {
  Item("Kaffe",      2000),
  Item("Choklad",    1500),
  Item("Espresso",   2200),
  Item("Latte",      2400),
  Item("Cappuccino", 2700),
};

int main(int argc, char *argv[]) {
  print_menu(supply);

  std::cout << "Välj en dryck du vill köpa mellan 1 och " << supply.size() << "."
            << std::endl;
  size_t choice;
  std::cin >> choice;
  choice = std::max(1UL, choice);
  choice = std::min(choice, supply.size());

  Item drink = supply[choice-1];

  int change  = 0;
  std::cout << "Du har valt " << drink.name << " (" << drink.cost << ")"
            << std::endl
            << "Lägg i mynt (skriv myntets valör i ören t.ex. 100,200,500,1000). "
            << std::endl;
  while ( change < drink.cost ) {
    std::cout << "Att betala: " << drink.cost - change << " öre"
              << std::endl;
    int payment;
    std::cin >> payment;
    switch (payment) {
    case 50:
    case 100:
    case 200:
    case 500:
    case 1000:
      change += payment;
      break;
    default:
      std::cout << "Okänd valör. Försök igen."
                << std::endl;
      break;
    }
  }
  std::cout << "Tillbaka: " << std::abs(drink.cost - change) << " öre."
            << std::endl
            << std::endl;

  std::cout << "Här är din varma dryck." << std::endl
            << "  Varsågod!"             << std::endl
            << "         {"              << std::endl
            << "      {   }"             << std::endl
            << "       }_{ __{"          << std::endl
            << "    .-{   }   }-."       << std::endl
            << "   (   }     {   )"      << std::endl
            << "   |`-.._____..-'|"      << std::endl
            << "   |             ;--."   << std::endl
            << "   |            (__  \\" << std::endl
            << "   |             | )  )" << std::endl
            << "   |             |/  /"  << std::endl
            << "   |             /  /"   << std::endl
            << "   |            (  /"    << std::endl
            << "   \\             y'"    << std::endl
            << "    `-.._____..-'"       << std::endl
            << std::endl;
  return 0;
}

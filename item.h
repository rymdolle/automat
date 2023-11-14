#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>
#include <string>

class Item {
private:
  std::string name_;
  int cost_;

public:
  Item(std::string name, int cost)
  {
    name_ = name;
    cost_ = cost;
  }

  std::string name() { return name_; }
  int cost() { return cost_; }

  int pay()
  {
    std::cout << "Insert coins.\n"
              << "Write coin denomination in kronor e.g. 1,2,5,10 "
              << "or abort with '0'.\n";
    int payment = 0;
    while (payment < cost_) {
      std::cout << "Left to pay: " << cost_ - payment << " kr\n";
      int coin;
      std::cin >> coin;
      switch (coin) {
      case 1:
      case 2:
      case 5:
      case 10:
        payment += coin;
        break;
      case 0:
        std::cout << "You have chosen to abort.\n";
        // Give back change and exit program if user aborts
        get_change(payment);
        exit(1);
      default:
        std::cout << "Invalid denomination. Try again or abort with '0'.\n";
        break;
      }
    }
    return payment - cost_;
  }

  static void get_change(int change)
  {
    std::cout << '\n'
              << "Change back: " << change << " kr.\n";

    int coin = 10;
    do {
      int amount = change / coin;
      if (amount > 0) {
        change -= amount * coin;
        std::cout << amount << " x " << coin << " kr.\n";
      }
      // Use integer division to get next coin
      coin /= 2;
    } while (change > 0);
  }
};

#endif // ITEM_H

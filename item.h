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
    int change = 0;
    while (change < cost_) {
      std::cout << "Left to pay: " << cost_ - change << " kr\n";
      int payment;
      std::cin >> payment;
      switch (payment) {
      case 1:
      case 2:
      case 5:
      case 10:
        change += payment;
        break;
      case 0:
        std::cout << "You have chosen to abort.\n";
        // Give back change and exit program if user aborts
        get_change(change + cost_);
        exit(1);
      default:
        std::cout << "Invalid denomination. Try again or abort with '0'.\n";
        break;
      }
    }
    return change;
  }

  void get_change(int change)
  {
    // Get the absolute value for the change
    int back = std::abs(cost_ - change);
    std::cout << '\n'
              << "Change back: " << back << " kr.\n";

    int coin = 10;
    do {
      int amount = back / coin;
      if (amount > 0) {
        back -= amount * coin;
        std::cout << amount << " x " << coin << " kr.\n";
      }
      // Use integer division to get next coin
      coin /= 2;
    } while (back > 0);
  }
};

#endif // ITEM_H

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
public:
    int cost;
    std::string name;
  Item(std::string name, int cost) {
    this->name = name;
    this->cost = cost;
  }
};

#endif // ITEM_HPP

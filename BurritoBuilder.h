#pragma once
#include "Kitchen.h"

class BurritoBuilder : public FoodBuilder { //Burrito builder which inherits the abstract builder
public:
    vector<string> getToppings(Order order);
    string getStyle(Order order);
    string getSauce(Order order);
    string getType();
};
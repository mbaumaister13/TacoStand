#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "Kitchen.h"
#include "BowlBuilder.h"
#include "TacoBuilder.h"
#include "BurritoBuilder.h"

using namespace std;

class Menu { //Menu header
private:
    int order, item, style, t1, t2, t3, sauce; //User input vars
public:
    void displayAndPrompt();
    void styleChoices(Kitchen*);
    vector<string> customOrder();
    void displayToppings();
    void displaySauces();
    string chooseTopping(int);
    string chooseSauce(int);
};


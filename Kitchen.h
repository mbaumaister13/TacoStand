#pragma once
#include <string>
#include <queue>
#include <iostream>
#include "Order.h"

using namespace std;

//Builder derived from https://gist.github.com/pazdera/1121152

class Food { //Product class
public:
    vector<string> toppings;
    string style;
    string sauce;
    string type;

    void display();
};

class FoodBuilder { //Abstract builder class
public:
    virtual vector<string> getToppings(Order order) = 0;
    virtual string getStyle(Order order) = 0;
    virtual string getSauce(Order order) = 0;
    virtual string getType() = 0;
};

class Kitchen { //Director class
private:
    FoodBuilder* builder;
    queue<Order> orders; //Queue for storing orders
public:
    void setBuilder(FoodBuilder* builder);
    Food* getFoodItem();
    void addFoodItem(Order order);
};

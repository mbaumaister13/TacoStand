#include "Order.h"

Order::Order(string style, string topping1, string topping2, string topping3, string sauce) { //Order constructor which populates the attributes
    this->style = style;
    toppings.push_back(topping1);
    toppings.push_back(topping2);
    toppings.push_back(topping3);
    this->sauce = sauce;
}

//Getters
string Order::getStyle() {
    return this->style;
}

vector<string> Order::getToppings() {
    return this->toppings;
}

string Order::getSauce() {
    return this->sauce;
}
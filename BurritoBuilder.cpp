#include "BurritoBuilder.h"
//Burrito builder implementation

string BurritoBuilder::getStyle(Order order) {
    return order.getStyle();
}

string BurritoBuilder::getSauce(Order order) {
    return order.getSauce();
}

vector<string> BurritoBuilder::getToppings(Order order) {
    return order.getToppings();
}

string BurritoBuilder::getType() {
    return "Burrito";
}
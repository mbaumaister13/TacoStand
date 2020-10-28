#include "TacoBuilder.h"
//Taco builder implementation

string TacoBuilder::getStyle(Order order) {
    return order.getStyle();
}

string TacoBuilder::getSauce(Order order) {
    return order.getSauce();
}

vector<string> TacoBuilder::getToppings(Order order) {
    return order.getToppings();
}

string TacoBuilder::getType() {
    return "Taco";
}
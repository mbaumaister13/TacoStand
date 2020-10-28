#include "BowlBuilder.h"
//Bowl builder implementation

string BowlBuilder::getStyle(Order order) {
    return order.getStyle();
}

string BowlBuilder::getSauce(Order order) {
    return order.getSauce();
}

vector<string> BowlBuilder::getToppings(Order order) {
    return order.getToppings();
}

string BowlBuilder::getType() {
    return "Bowl";
}
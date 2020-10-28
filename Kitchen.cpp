#include "Kitchen.h"
void Food::display() { //Display the food attributes
    cout << this->style << " " << this->type << endl;
    cout << "Toppings: " << this->toppings[0] << ", " << this->toppings[1] << ", and " << this->toppings[2] << endl;
    cout << "Sauce: " << this->sauce << endl;
}

void Kitchen::setBuilder(FoodBuilder *builder) { //Sets which builder to use
    this->builder = builder;
}

Food* Kitchen::getFoodItem() { //Builds the food item
    Food* food = new Food();

    food->type = builder->getType();

    food->style = builder->getStyle(orders.front());

    vector<string> toppings = builder->getToppings(orders.front());

    food->toppings.push_back(toppings[0]);
    food->toppings.push_back(toppings[1]);
    food->toppings.push_back(toppings[2]);

    food->sauce = builder->getSauce(orders.front());

    orders.pop();
    return food;
}

void Kitchen::addFoodItem(Order order) { //Adds order to the kitchen queue
    orders.push(order);
}


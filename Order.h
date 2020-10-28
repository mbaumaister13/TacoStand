#pragma once
#include <string>
#include <vector>

using namespace std;

class Order { //Order object for storing unmade orders
private:
    string style, sauce;
    vector<string> toppings;
public:
    Order(string, string, string, string, string);
    string getStyle();
    vector<string> getToppings();
    string getSauce();
};


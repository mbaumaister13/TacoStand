#include "Menu.h"

//Menu class acts as both menu and "Cashier" of sorts, handles user input

void Menu::displayAndPrompt() {
    Kitchen* kitchen = new Kitchen; //Main prompt controller
    string temp;
    cout << "Hello Welcome to Taco Stand Home of the Taco May I take your order?" << endl;
    while(true) {
        cout << "1) Place Order\n2) Walk Away" << endl; //Option prompt
        getline(cin, temp);

        try { //Input handling (all input follows this same format for handling)
           order = stoi(temp);
        } catch (exception e) {
            cout << "Not a valid option." << endl;
            continue;
        }

        if(order == 2) { //Leave stand
            cout << "Hope to see you again!" << endl;
            break;
        }
        else if (order == 1) { //Place order
            Order:
            cout << "What would you like to order today?" << endl;
            cout << "1) Taco\n2) Burrito\n3) Bowl" << endl;
            getline(cin, temp);

            try {
                item = stoi(temp);
            } catch (exception e) {
                cout << "Sorry, we don't have that here!" << endl;
                goto Order;
            }

            if (item < 1 || item > 3) { //Item input handling/selection
                cout << "Sorry, we don't have that here!" << endl;
                goto Order;
            } else {
                styleChoices(kitchen);
            }

        }
        else { //Input handling
            cout << "Not a valid option." << endl;
            continue;
        }


        switch(item) { //Creates builder based on item order and sets kitchen builder to that item
            case 1: {
                TacoBuilder builder;
                kitchen->setBuilder(&builder);
                break;
            }
            case 2: {
                BurritoBuilder builder;
                kitchen->setBuilder(&builder);
                break;
            }
            case 3: {
                BowlBuilder builder;
                kitchen->setBuilder(&builder);
                break;
            }
            default:
                break;
        }
        Food* myOrder = kitchen->getFoodItem();
        cout << "Your order has arrived!\n" << endl;
        myOrder->display();
        cout << endl;
        delete myOrder;
    }
    delete kitchen;
}

void Menu::styleChoices(Kitchen* kitchen) {
    string temp;
    Style:
    cout << "How do you want it prepared?" << endl;
    cout << "1) Classic (Beef, Lettuce, Cheese, Mild sauce)" << endl;
    cout << "2) Toilet Wrecker (Beans, Beans, Beans, Volcano sauce)" << endl;
    cout << "3) Plain (Nothing, Nothing, Nothing, No sauce)" << endl;
    cout << "4) Custom Order" << endl;
    getline(cin, temp);

    try {
        style  = stoi(temp);
    } catch (exception e) {
        cout << "We don't have that option here!" << endl;
        goto Style;
    }

    switch(style) { //Style switch
        case 1: {
            Order order("Classic", "Beef", "Lettuce", "Cheese", "Mild"); //Creates new order object and adds to the order queue
            kitchen->addFoodItem(order);
            break;
        }
        case 2: {
            Order order("Toilet Wrecker", "Beans", "Beans", "Beans", "Volcano");
            kitchen->addFoodItem(order);
            break;
        }
        case 3: {
            Order order("Plain", "Nothing", "Nothing", "Nothing", "None");
            kitchen->addFoodItem(order);
            break;
        }
        case 4: {
            vector<string> custom = customOrder();
            Order order("Custom", custom[0], custom[1], custom[2], custom[3]);
            kitchen->addFoodItem(order);
            break;
        }
        default:
            cout << "We don't have that option here!" << endl;
            goto Style;
    }
}

vector<string> Menu::customOrder() { //Custom order prompts
    string temp;
    vector<string> custom;
    cout << "You chose custom order. Epic!" << endl;
    displayToppings();

    T1: //Topping 1 selection
    cout << "Choose first topping: " << endl;
    getline(cin, temp);
    try {
        t1 = stoi(temp);
        if(t1 < 0 || t1 > 9)
            throw exception();
    } catch (exception e) {
        cout << "We don't have that option here!" << endl;
        goto T1;
    }

    T2: //Topping 2 selection
    cout << "Choose second topping: " << endl;
    getline(cin, temp);
    try {
        t2 = stoi(temp);
        if(t2 < 0 || t2 > 9)
            throw exception();
    } catch (exception e) {
        cout << "We don't have that option here!" << endl;
        goto T2;
    }

    T3: //Topping 3 selection
    cout << "Choose third topping: " << endl;
    getline(cin, temp);
    try {
        t3 = stoi(temp);
        if(t3 < 0 || t3 > 9)
            throw exception();
    } catch (exception e) {
        cout << "We don't have that option here!" << endl;
        goto T3;
    }

    displaySauces();
    Sauce: //Sauce selection
    cout << "Choose a sauce: " << endl;
    getline(cin, temp);
    try {
        sauce = stoi(temp);
        if(sauce < 0 || sauce > 5)
            throw exception();
    } catch (exception e) {
        cout << "We don't have that option here!" << endl;
        goto Sauce;
    }
    //Add all attributes to vector and return
    custom.push_back(chooseTopping(t1));
    custom.push_back(chooseTopping(t2));
    custom.push_back(chooseTopping(t3));
    custom.push_back(chooseSauce(sauce));
    return custom;
}

void Menu::displayToppings() { //Topping display
    cout << "Toppings: " << endl;
    cout << "1) Beef" << endl;
    cout << "2) Chicken" << endl;
    cout << "3) Beans" << endl;
    cout << "4) Lettuce" << endl;
    cout << "5) Pico de Gallo" << endl;
    cout << "6) Veggies" << endl;
    cout << "7) Cheese" << endl;
    cout << "8) Sour Cream" << endl;
    cout << "9) Guacamole" << endl;
    cout << "0) None" << endl;
}

void Menu::displaySauces() { //Sauce display
    cout << "Sauces: " << endl;
    cout << "1) Mild" << endl;
    cout << "2) Medium" << endl;
    cout << "3) Hot" << endl;
    cout << "4) Volcano" << endl;
    cout << "5) Green" << endl;
    cout << "0) None" << endl;
}

string Menu::chooseTopping(int option) { //Topping switch
    switch(option) {
        case 1:
            return "Beef";
        case 2:
            return "Chicken";
        case 3:
            return "Beans";
        case 4:
            return "Lettuce";
        case 5:
            return "Pico de Gallo";
        case 6:
            return "Veggies";
        case 7:
            return "Cheese";
        case 8:
            return "Sour Cream";
        case 9:
            return "Guacamole";
        case 0:
            return "None";
        default:
            return "";
    }
}

string Menu::chooseSauce(int option) { //Sauce switch
    switch(option) {
        case 1:
            return "Mild";
        case 2:
            return "Medium";
        case 3:
            return "Hot";
        case 4:
            return "Volcano";
        case 5:
            return "Green";
        case 0:
            return "None";
        default:
            return "";
    }
}
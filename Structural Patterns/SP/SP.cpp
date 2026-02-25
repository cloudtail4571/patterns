#include <iostream>
#include <string>
using namespace std;

class Beverage {
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
};

class Espresso : public Beverage {
public:
    string getDescription() override {
        return "Эспрессо";
    }
    double cost() override { return 1.99; }
};

class Tea : public Beverage {
public:
    string getDescription() override {
        return "Чай";
    }
    double cost() override { return 1.50; }
};

class CondimentDecorator : public Beverage {
protected:
    Beverage* bev;
public:
    CondimentDecorator(Beverage* b) : bev(b) {}
    string getDescription() override {
        return bev->getDescription();
    }
    double cost() override { return bev->cost(); }
};

class Milc : public CondimentDecorator {
public:
    Milc(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Молоко";
    }
    double cost() override { return bev->cost() + 0.10; }
};

class Sugar : public CondimentDecorator {
public:
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Сахар";
    }
    double cost() override { return bev->cost() + 0.05; }
};

class Syrop : public CondimentDecorator {
public:
    Syrop(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Сироп";
    }
    double cost() override { return bev->cost() + 0.15; }
};

class Choco : public CondimentDecorator {
public:
    Choco(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Шоколад";
    }
    double cost() override { return bev->cost() + 0.20; }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    Beverage* drink = new Espresso();
    drink = new Milc(drink);
    drink = new Sugar(drink);
    drink = new Choco(drink);

    cout << drink->getDescription() << " стоит $" << drink->cost() << endl;

    Beverage* simpleDrink = new Espresso();
    cout << simpleDrink->getDescription() << " стоит $" << simpleDrink->cost() << endl;

    delete drink;
    delete simpleDrink;

    cout << "-------------------" << endl;

    Beverage* drink1 = new Tea();
    drink1 = new Milc(drink1);
    drink1 = new Syrop(drink1);

    cout << drink1->getDescription() << " стоит $" << drink1->cost() << endl;

    Beverage* simpleDrink1 = new Tea();
    cout << simpleDrink1->getDescription() << " стоит $" << simpleDrink1->cost() << endl;

    delete drink1;
    delete simpleDrink1;

}
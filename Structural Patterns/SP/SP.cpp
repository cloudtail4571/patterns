#include <iostream>
#include <string>
using namespace std;

/// \brief Класс-шаблон для напитков
class Beverage {
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
};

/// \brief Класс напитка "Эспрессо"
class Espresso : public Beverage {
public:
    /**
    * \brief Функция для получения названия напитка
    * \return string - строку, название напитка
    */
    string getDescription() override {
        return "Эспрессо";
    }
    /**
    * \brief Функция для получения цены напитка
    * \return double - возвращение цены напитка
    */
    double cost() override { return 1.99; }
};

/// \brief Класс напитка "Чай"
class Tea : public Beverage {
public:
    /**
    * \brief Функция для получения названия напитка
    * \return string - строку, название напитка
    */
    string getDescription() override {
        return "Чай";
    }
    /**
    * \brief Функция для получения цены напитка
    * \return double - возвращение цены напитка
    */
    double cost() override { return 1.50; }
};

/// \brief Класс-шаблон для добавок
class CondimentDecorator : public Beverage {
protected:
    Beverage* bev;
public:
    /**
    * \brief Функция для получения названия добавки
    * \return bev - получение названия добавки
    */
    CondimentDecorator(Beverage* b) : bev(b) {}
    string getDescription() override {
        return bev->getDescription();
    }
    /**
    * \brief Функция для определения цены добавки
    * \return bev - получение цены добавки
    */
    double cost() override { return bev->cost(); }
};

/// \brief Класс для добавки "Молоко"
class Milc : public CondimentDecorator {
public:
    /**
    * \brief Функция для получения названия добавки
    * \return bev - получение названия добавки
    */
    Milc(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Молоко";
    }
    /**
    * \brief Функция для получения цены добавки
    * \return bev - получение цены добавки
    */
    double cost() override { return bev->cost() + 0.10; }
};

/// \brief Класс для добавки "Сахар"
class Sugar : public CondimentDecorator {
public:
    /**
    * \brief Функция для получения названия добавки
    * \return bev - получение названия добавки
    */
    Sugar(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Сахар";
    }
    /**
    * \brief Функция для получения цены добавки
    * \return bev - получение цены добавки
    */
    double cost() override { return bev->cost() + 0.05; }
};

/// \brief Класс для добавки "Сироп"
class Syrop : public CondimentDecorator {
public:
    /**
    * \brief Функция для получения названия добавки
    * \return bev - получение названия добавки
    */
    Syrop(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Сироп";
    }
    /**
    * \brief Функция для получения цены добавки
    * \return bev - получение цены добавки
    */
    double cost() override { return bev->cost() + 0.15; }
};

/// \brief Класс для добавки "Шоколад"
class Choco : public CondimentDecorator {
public:
    /**
    * \brief Функция для получения названия добавки
    * \return bev - получение названия добавки
    */
    Choco(Beverage* b) : CondimentDecorator(b) {}
    string getDescription() override {
        return bev->getDescription() + ", Шоколад";
    }
    /**
    * \brief Функция для получения цены добавки
    * \return bev - получение цены добавки
    */
    double cost() override { return bev->cost() + 0.20; }
};

/// \brief Функция для запуска тестовых чеков с использованием комбинации разных напитков
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
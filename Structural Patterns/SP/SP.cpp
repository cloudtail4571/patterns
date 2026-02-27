#include <iostream>
#include <string>
using namespace std;

/// \brief Абстрактный базовый класс для всех напитков
/// \details Определяет интерфейс для получения описания напитка и его стоимости
class Beverage {
public:
    /// \brief Получить описание напитка
    /// \return Название напитка с добавками
    virtual string getDescription() = 0;

    /// \brief Получить стоимость напитка
    /// \return Итоговая стоимость напитка
    virtual double cost() = 0;

    /// \brief Виртуальный деструктор для корректного удаления через базовый класс
    virtual ~Beverage() {}
};

/// \brief Класс напитка "Эспрессо"
/// \details Конкретная реализация базового напитка
class Espresso : public Beverage {
public:
    /// \brief Возвращает название напитка
    /// \return Строка с названием напитка
    string getDescription() override {
        return "Эспрессо";
    }

    /// \brief Возвращает стоимость напитка
    /// \return Цена эспрессо
    double cost() override { return 1.99; }
};

/// \brief Класс напитка "Чай"
/// \details Конкретная реализация базового напитка
class Tea : public Beverage {
public:
    /// \brief Возвращает название напитка
    /// \return Строка с названием напитка
    string getDescription() override {
        return "Чай";
    }

    /// \brief Возвращает стоимость напитка
    /// \return Цена чая
    double cost() override { return 1.50; }
};

/// \brief Базовый класс-декоратор для добавок
/// \details Наследуется от Beverage и содержит указатель на декорируемый объект
class CondimentDecorator : public Beverage {
protected:
    /// \brief Указатель на декорируемый напиток
    Beverage* bev;

public:
    /// \brief Конструктор декоратора
    /// \param b Указатель на декорируемый напиток
    CondimentDecorator(Beverage* b) : bev(b) {}

    /// \brief Возвращает описание напитка
    /// \return Описание декорируемого напитка
    string getDescription() override {
        return bev->getDescription();
    }

    /// \brief Возвращает стоимость напитка
    /// \return Стоимость декорируемого напитка
    double cost() override { 
        return bev->cost(); 
    }

    /// \brief Виртуальный деструктор
    virtual ~CondimentDecorator() {
        delete bev;
    }
};

/// \brief Декоратор добавки "Молоко"
/// \details Добавляет к описанию "Молоко" и увеличивает стоимость
class Milc : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Указатель на декорируемый напиток
    Milc(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Возвращает описание напитка с добавкой молока
    /// \return Описание с добавкой
    string getDescription() override {
        return bev->getDescription() + ", Молоко";
    }

    /// \brief Возвращает стоимость с учетом молока
    /// \return Итоговая стоимость
    double cost() override { 
        return bev->cost() + 0.10; 
    }
};

/// \brief Декоратор добавки "Сахар"
/// \details Добавляет к описанию "Сахар" и увеличивает стоимость
class Sugar : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Указатель на декорируемый напиток
    Sugar(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Возвращает описание напитка с сахаром
    /// \return Описание с добавкой
    string getDescription() override {
        return bev->getDescription() + ", Сахар";
    }

    /// \brief Возвращает стоимость с учетом сахара
    /// \return Итоговая стоимость
    double cost() override { 
        return bev->cost() + 0.05; 
    }
};

/// \brief Декоратор добавки "Сироп"
/// \details Добавляет к описанию "Сироп" и увеличивает стоимость
class Syrop : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Указатель на декорируемый напиток
    Syrop(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Возвращает описание напитка с сиропом
    /// \return Описание с добавкой
    string getDescription() override {
        return bev->getDescription() + ", Сироп";
    }

    /// \brief Возвращает стоимость с учетом сиропа
    /// \return Итоговая стоимость
    double cost() override { 
        return bev->cost() + 0.15; 
    }
};

/// \brief Декоратор добавки "Шоколад"
/// \details Добавляет к описанию "Шоколад" и увеличивает стоимость
class Choco : public CondimentDecorator {
public:
    /// \brief Конструктор
    /// \param b Указатель на декорируемый напиток
    Choco(Beverage* b) : CondimentDecorator(b) {}

    /// \brief Возвращает описание напитка с шоколадом
    /// \return Описание с добавкой
    string getDescription() override {
        return bev->getDescription() + ", Шоколад";
    }

    /// \brief Возвращает стоимость с учетом шоколада
    /// \return Итоговая стоимость
    double cost() override { 
        return bev->cost() + 0.20; 
    }
};

/// \brief Точка входа в программу
/// \details Демонстрация работы паттерна "Декоратор" с различными комбинациями напитков и добавок
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
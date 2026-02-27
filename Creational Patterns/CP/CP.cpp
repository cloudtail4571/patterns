#include <iostream>
#include <string>
using namespace std;

/// \brief Интерфейс для персонажей
class Character {
    int health;
public:
    virtual string getType() = 0;
    virtual void attack() = 0;
    virtual int getHealth()
    {
        return health;
    }
};

/// \brief Класс с настройками для персонажа "Воин"
class Warrior : public Character {
public: 
    /**
    * \brief Функция для получения типа персонажа
    * \return string - строку, название персонажа
    * \remark Получаем только имя персонажа т.к это учебный код
    */
    string getType() override { return "Воин"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Воин атакует мечом!" << endl; }
    /**
    * \brief Функция для получения типа персонажа
    * \return int - число, количество здоровья персонажа
    * \note Не влияет ни на что. Это учебный код
    */
    int getHealth() override { return 100; }
};

/// \brief Класс с настройками для персонажа "Маг"
class Mage : public Character {
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - строку, название персонажа
    * \remark Получаем только имя персонажа т.к это учебный код 
    */
    string getType() override { return "Маг"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }
    /**
    * \brief Функция для получения типа персонажа
    * \return int - число, количество здоровья персонажа
    * \note Не влияет ни на что. Это учебный код
    */
    int getHealth() override { return 50; }
};

/// \brief Класс с настройками для персонажа "Лучник"
class Archer : public Character {
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - строку, название персонажа
    * \remark Получаем только имя персонажа т.к это учебный код
    */
    string getType() override { return "Лучник"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }
    int getHealth() override { return 100; }
};

/// \brief Класс с настройками для персонажа "Рыцарь"
class Knight : public Character {
public:
    /**
    * \brief Функция для получения типа персонажа
    * \return string - строку, название персонажа
    * \remark Получаем только имя персонажа т.к это учебный код
    */
    string getType() override { return "Рыцарь"; }
    /**
    * \brief Функция для выполнения действий персонажа
    * \note Не влияет ни на что. Это учебный код
    * \todo Добавить возможность отбирать жизни у того, на кого нападаем
    */
    void attack() override { cout << "Рыцарь атакует копьем!" << endl; }
    int getHealth() override { return 70; }
};

/**
* \brief Абстрактная фабрика для генерации персонажей
* 
* \Используется для примера работы паттерна проектирования 
*/

class CharacterFactory{
public:
    virtual Character* createCharacter() = 0;
    /**
    * \brief Функция для создания персонажей и выполнения базовых его действий
    * \note После создания объекта, выполняет действие персонажа и уничтожает объект
    * \warning Нельзя будет использовать созданных персонажей в других частях кода
    */
    void spawnAndAttack() {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getType() << ". ";
        chara->attack();
        cout << "Здоровье: " << chara->getHealth() << endl;
        delete chara;
    }


};

/// \brief Класс для создания Воина
class WarriorFactory : public CharacterFactory {
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Warrior(); }
};

class MageFactory : public CharacterFactory {
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Mage(); }
};

class ArcherFactory : public CharacterFactory {
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Archer(); }
};

class KnightFactory : public CharacterFactory {
public:
    /**
    * \brief Функция для выделения памяти на класс персонажа
    * \return Возвращает указатель на созданного персонажа
    */
    Character* createCharacter() override { return new Knight(); }
};


/// \brief Функция для запуска конвеера с персонажами
/// \note Используется для учебного кода
int main()
{
    setlocale(LC_ALL, "RUS");

    CharacterFactory* factory = new WarriorFactory();
    factory->spawnAndAttack();
    factory = new MageFactory();
    factory->spawnAndAttack();
    factory = new ArcherFactory();
    factory->spawnAndAttack();
    factory = new KnightFactory();
    factory->spawnAndAttack();
}
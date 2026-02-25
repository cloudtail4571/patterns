#include <iostream>
#include <string>
using namespace std;

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

class Warrior : public Character {
public: 
    string getType() override { return "Воин"; }
    void attack() override { cout << "Воин атакует мечом!" << endl; }
    int getHealth() override { return 100; }
};

class Mage : public Character {
public:
    string getType() override { return "Маг"; }
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }
    int getHealth() override { return 50; }
};

class Archer : public Character {
public:
    string getType() override { return "Лучник"; }
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }
    int getHealth() override { return 100; }
};

class Knight : public Character {
public:
    string getType() override { return "Рыцарь"; }
    void attack() override { cout << "Рыцарь атакует копьем!" << endl; }
    int getHealth() override { return 70; }
};

class CharacterFactory{
public:
    virtual Character* createCharacter() = 0;
    void spawnAndAttack() {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getType() << ". ";
        chara->attack();
        cout << "Здоровье: " << chara->getHealth() << endl;
        delete chara;
    }


};

class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Warrior(); }
};

class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Mage(); }
};

class ArcherFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Archer(); }
};

class KnightFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Knight(); }
};

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
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// \brief Класс-получатель (Receiver) для выполнения операций компьютерной системы
/// \details Содержит реальные действия, которые будут вызываться через команды
class ComputerSystem {
public:
    /// \brief Открыть файл
    /// \param file Имя файла для открытия
    void openFile(const string& file) {
        cout << "Открываем файл: " << file << endl;
    }

    /// \brief Выключить компьютер
    void shutDown() {
        cout << "Выключаем компьютер" << endl;
    }

    /// \brief Запустить браузер
    void launchBrowser() {
        cout << "Запускаем браузер" << endl;
    }
};

/// \brief Абстрактный базовый класс команды
/// \details Определяет интерфейс для выполнения и отмены операций
class Command {
public:
    /// \brief Выполнить команду
    virtual void execute() = 0;

    /// \brief Отменить выполнение команды
    virtual void undo() = 0;

    /// \brief Виртуальный деструктор для корректного удаления через базовый указатель
    virtual ~Command() {}
};

/// \brief Конкретная команда открытия файла
/// \details Реализует выполнение операции открытия файла
class OpenFileCommand : public Command {
private:
    /// \brief Указатель на систему-получатель
    ComputerSystem* system;

    /// \brief Имя файла
    string filename;

public:
    /// \brief Конструктор команды открытия файла
    /// \param s Указатель на объект ComputerSystem
    /// \param fn Имя файла для открытия
    OpenFileCommand(ComputerSystem* s, const string& fn)
        : system(s), filename(fn) {
    }

    /// \brief Выполняет открытие файла
    void execute() override {
        system->openFile(filename);
    }

    /// \brief Отменяет операцию открытия файла
    /// \details В демонстрационной версии выводит сообщение о закрытии файла
    void undo() override {
        cout << "Закрываем файл" << endl;
    }
};

/// \brief Конкретная команда выключения компьютера
/// \details Реализует выполнение операции завершения работы системы
class ShutdownCommand : public Command {
private:
    /// \brief Указатель на систему-получатель
    ComputerSystem* system;

public:
    /// \brief Конструктор команды выключения
    /// \param s Указатель на объект ComputerSystem
    ShutdownCommand(ComputerSystem* s) : system(s) {}

    /// \brief Выполняет выключение компьютера
    void execute() override {
        system->shutDown();
    }

    /// \brief Отменяет выключение (демонстрационная реализация)
    void undo() override {
        cout << "Отмена: возвращаем систему в рабочее состояние" << endl;
    }
};

/// \brief Конкретная команда запуска браузера
/// \details Реализует выполнение операции запуска браузера
class LaunchBrowserCommand : public Command {
private:
    /// \brief Указатель на систему-получатель
    ComputerSystem* system;

public:
    /// \brief Конструктор команды запуска браузера
    /// \param s Указатель на объект ComputerSystem
    LaunchBrowserCommand(ComputerSystem* s) : system(s) {}

    /// \brief Выполняет запуск браузера
    void execute() override {
        system->launchBrowser();
    }

    /// \brief Отменяет запуск браузера (закрывает браузер)
    void undo() override {
        cout << "Закрываем браузер" << endl;
    }
};

/// \brief Класс-инициатор (Invoker)
/// \details Хранит список команд и управляет их выполнением
class RemoteControl {
private:
    /// \brief Список зарегистрированных команд
    vector<Command*> commands;

public:
    /// \brief Добавить команду в список
    /// \param cmd Указатель на объект команды
    void addCommand(Command* cmd) {
        commands.push_back(cmd);
    }

    /// \brief Выполнить все добавленные команды
    void pressButton() {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }

    /// \brief Отменить последнюю добавленную команду
    /// \details Удаляет команду из списка после отмены
    void undoLast() {
        if (!commands.empty()) {
            commands.back()->undo();
            commands.pop_back();
        }
    }
};

/// \brief Точка входа в программу
/// \details Демонстрация работы паттерна "Команда"
int main()
{
    setlocale(LC_ALL, "RUS");

    ComputerSystem system;

    Command* openCmd = new OpenFileCommand(&system, "document.txt");
    Command* shutdownCmd = new ShutdownCommand(&system);
    Command* browserCmd = new LaunchBrowserCommand(&system);

    RemoteControl remote;
    remote.addCommand(openCmd);
    remote.addCommand(browserCmd);
    remote.addCommand(shutdownCmd);

    remote.undoLast();

    delete openCmd;
    delete shutdownCmd;
    delete browserCmd;
}
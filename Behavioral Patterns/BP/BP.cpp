#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ComputerSystem {
public:
    void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
    void shutDown() { cout << "Выключаем компьютер" << endl; }
    void launchBrowser() { cout << "Запускаем браузер" << endl; }
};

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class OpenFileCommand : public Command {
private:
    ComputerSystem* system;
    string filename;
public:
    OpenFileCommand(ComputerSystem* s, const string& fn) : system(s), filename(fn) {}
    void execute() override { system->openFile(filename); }
    void undo() override { cout << "Закрываем файл" << endl; }
};

class ShutdownCommand : public Command {
private:
    ComputerSystem* system;
public:
    ShutdownCommand(ComputerSystem* s) : system(s) {}
    void execute() override { system->shutDown(); }
    void undo() override { cout << "Отмена: Выключаем компьютер обратно" << endl; }
};

class LaunchBrowserCommand : public Command {
private:
    ComputerSystem* system;
public:
    LaunchBrowserCommand(ComputerSystem* s) : system(s) {}
    void execute() override { system->launchBrowser(); }
    void undo() override { cout << "Закрываем браузер" << endl; }
};

class RemoteControl {
private:
    vector<Command*> commands;
public:
    void addCommand(Command* cmd) { commands.push_back(cmd); }
    void pressButton() {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }
    void undolast() {
        if (!commands.empty()) {
            commands.back()->undo();
            commands.pop_back();
        }
    }
};

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

    remote.undolast();

    delete openCmd;
    delete shutdownCmd;
    delete browserCmd;

}

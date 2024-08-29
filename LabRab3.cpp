#include <iostream> 
#include <fstream> 
#include <string> 
#include <Windows.h> 

using namespace std;

void write() {
    
    ofstream out("FILE_NEW.txt");

    if (out.is_open()) {
     
        string Team = "";
        string Name = "";
        string Age = "";
        string Exit = "";

        do {
            cout << "> Команда: ";
            getline(cin, Team);
            cout << "> ФИО игрока: ";
            getline(cin, Name);
            cout << "> Возраст: ";
            getline(cin, Age);
            cout << "*** Введите `exit` для выхода: ";
            getline(cin, Exit);

            out << Team << endl;
            out << Name << endl;
            out << Age << endl;

        } while (Exit != "exit");
        out.close();
    }
}

void read() {

    ofstream out("FILE_ANSWER.txt");

    if (out.is_open()) {

        ifstream in("FILE_NEW.txt");

        if (in.is_open()) {

            string Team = "";
            string Name = "";
            string Age = "";

            int i = 0;

            while (!in.eof()) {
                getline(in, Team);
                if (Team == "") break;
                getline(in, Name);
                getline(in, Age);
                if (stoi(Age) < 18) {
                    i++;
                    cout << i << ")" << " " << Team << " / " << Name << " / " << Age << endl;
                    out << i << ")" << " " << Team << " / " << Name << " / " << Age << endl;
                }
            }
            in.close();
        }
        out.close();
    }
}

int main() {
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian");

    while (true) {
        cout << "- Нажмите 1 для записи \n- Нажмите 2 для вывода \n- Нажмите 3 для выхода " << endl;
        
        string work;
        getline(cin, work);
        
        if (work == "1") write();
        else if (work == "2") read();
        else if (work == "3") break;
    }
    return 0;
}

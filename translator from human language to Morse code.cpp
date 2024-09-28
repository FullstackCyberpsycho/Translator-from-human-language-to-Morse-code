// translator from human language to Morse code.cpp
//добавить русский язык и просмотр предыдущих фраз.
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, string> morze = {
       {'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
       {'D', "-.."}, {'E', "."}, {'F', "..-."},
       {'G', "--."}, {'H', "...."}, {'I', ".."},
       {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
       {'M', "--"}, {'N', "-."}, {'O', "---"},
       {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
       {'S', "..."}, {'T', "-"}, {'U', "..-"},
       {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
       {'Y', "-.--"}, {'Z', "--.."},
       {'a', ".-"}, {'b', "-..."}, {'c', "-.-."},
       {'d', "-.."}, {'e', "."}, {'f', "..-."},
       {'g', "--."}, {'h', "...."}, {'i', ".."},
       {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
       {'m', "--"}, {'n', "-."}, {'o', "---"},
       {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},
       {'s', "..."}, {'t', "-"}, {'u', "..-"},
       {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
       {'y', "-.--"}, {'z', "--.."}
};

string getMorzeLetter(char letter) {
    auto it = morze.find(letter);
    if (it != morze.end()) {
        return it->second;
    }
    return string(1, letter);
}

string getMorzeWord(string& word) {
    string result;
    for (char letter : word) {
        result.append(getMorzeLetter(letter));
    }
    return result;
}
string getMorzeString(const string& input) {
    string morzeStr, current;
    for (char letter : input) {
        if (letter == ' ') {
            morzeStr.append(getMorzeWord(current) + "/");
            current = "";
        }
        else {
            current += letter;
        }
    }

    if (!current.empty()) {
        morzeStr.append(getMorzeWord(current));
    }

    return morzeStr;
}

int main() {
    
    setlocale(LC_ALL, "Rus");
    string morzeOutput, input, enter;
    cout << "переводить можно только с английского языка(Beta version)" << endl;
    do
    {
        cout << "BETA.ПЕРЕВОДЧИК ФРАЗ НА АЗБУКУ МОРЗЕ!" << endl << endl;

        cout << "чтобы выйти введите: " << "\"exit\" " << endl;
        cout << "Введите фразу для перевода: ";
        getline(cin, input);

        if (input == "exit") {
            system("cls");
            cout << "программа завершена:( включи обратно!" << endl;
            return 0;
        }
        morzeOutput = getMorzeString(input);
        cout << endl << "код морзе: " << morzeOutput << endl;
        cout << "фраза: " << input << endl;
        cout << endl << "введите что угодно чтобы продолжить или введите " <<
            "\"exit\" " << "чтобы выйти: ";
        getline(cin, enter);
        system("cls");

    } while (enter != "exit");
    cout << "программа завершена:( включи обратно!" << endl;
    return 0;
}
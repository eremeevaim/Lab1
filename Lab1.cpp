#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe {
    string name;
    float length;
    int diametr;
    bool check;
    bool isAdded = false;
};

struct KS {
    string name2;
    int KC;
    int KCV;
    bool isAdded = false;
};

string checkString() {
    string input;
    while (true) {
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        cout << "Ошибка! Ввод не может быть пустым, попробуйте снова: ";
    }
}


bool checkBool() {
    while (true) {
        string input;
        getline(cin, input);
        if (input == "1") return true;
        if (input == "0") return false;
        cout << "Ошибка! Введите 0 или 1: ";
    }
}


int checkInt() {
    string input;
    while (true) {
        getline(cin, input);
        try {
            size_t pos;
            int result = stoi(input, &pos);
            if (pos == input.size()) {
                return result;
            }
        }
        catch (...) {
        }
        cout << "Ошибка! Введите целое число: ";
    }
}

float checkFloat() {
    string input;
    while (true) {
        getline(cin, input);
        try {
            size_t pos;
            float result = stof(input, &pos);
            if (pos == input.size()) {
                return result;
            }
        }
        catch (...) {
            
        }
        cout << "Ошибка! Введите число: ";
    }
}

int checkMenuChoice() {
    string input;
    while (true) {
        getline(cin, input);
        if (input.size() == 1 && input[0] >= '0' && input[0] <= '7') {
            return input[0] - '0';
        }
        cout << "Некорректный выбор. Пожалуйста, выберите пункт от 0 до 7: ";
    }
}

int checkEditChoice(int max) {
    string input;
    while (true) {
        getline(cin, input);
        try {
            int choice = stoi(input);
            if (choice >= 0 && choice <= max) {
                return choice;
            }
        }
        catch (...) {
        }
        cout << "Некорректный выбор. Пожалуйста, выберите пункт от 0 до " << max << ": ";
    }
}

void saveToFile(const Pipe& truba, const KS& station, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Pipe" << endl;
        file << truba.name << endl;
        file << truba.length << endl;
        file << truba.diametr << endl;
        file << truba.check << endl;
        file << truba.isAdded << endl;

        file << "KS" << endl;
        file << station.name2 << endl;
        file << station.KC << endl;
        file << station.KCV << endl;
        file << station.isAdded << endl;

        file.close();
        cout << "Данные успешно сохранены в файл: " << filename << endl;
    }
    else {
        cout << "Ошибка! не удалось открыть файл для записи." << endl;
    }
}

void FileLoad(Pipe& truba, KS& station, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string type;
        while (file >> type) {
            if (type == "Pipe") {
                file.ignore();
                getline(file, truba.name);
                file >> truba.length;
                file >> truba.diametr;
                file >> truba.check;
                file >> truba.isAdded;
            }
            else if (type == "KS") {
                file.ignore();
                getline(file, station.name2);
                file >> station.KC;
                file >> station.KCV;
                file >> station.isAdded;
            }
        }
        file.close();
        cout << "Данные успешно загружены из файла: " << filename << endl;
    }
    else {
        cout << "Ошибка! не удалось открыть файл для чтения." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    Pipe truba;
    KS station;
    int chosen = 0;
    string filename = "data.txt";

    while (true) {
        cout << "МЕНЮ КНОПОК: '1' - Добавить трубу, '2' - Добавить КС, '3' - Просмотр всех объектов, '4' - Редактировать трубу, '5' - Редактировать КС, '6' - Сохранить, '7' - Загрузить, '0' - Выход. " << endl;
        chosen = checkMenuChoice();
        if (chosen == 1) {
            cout << "Введите характеристики для трубы." << endl;

            cout << "Название: ";
            truba.name = checkString();

            cout << "Длина (км): ";
            truba.length = checkFloat();
            while (truba.length <= 0) {
                cout << "Длина должна быть положительной! Повторите ввод: ";
                truba.length = checkFloat();
            }

            cout << "Диаметр: ";
            truba.diametr = checkInt();
            while (truba.diametr <= 0) {
                cout << "Диаметр должен быть положительным! Повторите ввод: ";
                truba.diametr = checkInt();
            }

            cout << "В ремонте ли труба? (Да - '1', Нет - '0') ";
            truba.check = checkBool();

            truba.isAdded = true;
            cout << "Данные трубы успешно добавлены." << endl;
        }
        else if (chosen == 2) {
            cout << "Введите характеристики для станции." << endl;

            cout << "Название: ";
            station.name2 = checkString();

            cout << "Количество цехов: ";
            station.KC = checkInt();
            while (station.KC <= 0) {
                cout << "Количество цехов должно быть положительным! Повторите ввод: ";
                station.KC = checkInt();
            }

            cout << "Количество цехов (в работе): ";
            station.KCV = checkInt();
            while (station.KCV < 0 || station.KCV > station.KC) {
                cout << "Количество работающих цехов должно быть от 0 до " << station.KC << "! Повторите ввод: ";
                station.KCV = checkInt();
            }

            station.isAdded = true;
            cout << "Данные КС успешно добавлены." << endl;
        }
        else if (chosen == 3) {
            bool bothAdded = false;
            if (truba.isAdded) {
                cout << "ХАРАКТЕРИСТИКИ ТРУБЫ" << endl;
                cout << "Название: " << truba.name << endl;
                cout << "Длина (км): " << truba.length << endl;
                cout << "Диаметр: " << truba.diametr << endl;
                cout << "В ремонте: " << (truba.check ? "Да" : "Нет") << endl;
                bothAdded = true;
            }
            if (station.isAdded) {
                cout << "ХАРАКТЕРИСТИКИ КС" << endl;
                cout << "Название: " << station.name2 << endl;
                cout << "Количество цехов: " << station.KC << endl;
                cout << "Количество цехов (в работе): " << station.KCV << endl;
                bothAdded = true;
            }

            if (!bothAdded) {
                cout << "Никаких данных не было введено." << endl;
            }
        }
        else if (chosen == 4) {
            if (!truba.isAdded) {
                cout << "Нет данных о трубе для редактирования. Сначала добавьте трубу." << endl;
            }
            else {
                cout << "Редактирование трубы. Текущие значения:" << endl;
                cout << "1. Название: " << truba.name << endl;
                cout << "2. Длина: " << truba.length << " км" << endl;
                cout << "3. Диаметр: " << truba.diametr << endl;
                cout << "4. Статус ремонта: " << (truba.check ? "В ремонте" : "Не в ремонте") << endl;

                cout << "Что вы хотите изменить? (1-4, 0 - отмена): ";
                int editChoice = checkEditChoice(4);

                if (editChoice == 0) {
                    cout << "Редактирование отменено." << endl;
                }
                else if (editChoice == 1) {
                    cout << "Введите новое название: ";
                    truba.name = checkString();
                    cout << "Название обновлено." << endl;
                }
                else if (editChoice == 2) {
                    cout << "Введите новую длину (км): ";
                    truba.length = checkFloat();
                    while (truba.length <= 0) {
                        cout << "Длина должна быть положительной! Повторите ввод: ";
                        truba.length = checkFloat();
                    }
                    cout << "Длина обновлена." << endl;
                }
                else if (editChoice == 3) {
                    cout << "Введите новый диаметр: ";
                    truba.diametr = checkInt();
                    while (truba.diametr <= 0) {
                        cout << "Диаметр должен быть положительным! Повторите ввод: ";
                        truba.diametr = checkInt();
                    }
                    cout << "Диаметр обновлен." << endl;
                }
                else if (editChoice == 4) {
                    cout << "В ремонте ли труба? (Да - '1', Нет - '0') ";
                    truba.check = checkBool();
                    cout << "Статус ремонта обновлен." << endl;
                }
            }
        }
        else if (chosen == 5) {
            if (!station.isAdded) {
                cout << "Нет данных о КС для редактирования. Сначала добавьте КС." << endl;
            }
            else {
                cout << "Редактирование КС. Текущие значения:" << endl;
                cout << "1. Название: " << station.name2 << endl;
                cout << "2. Количество цехов: " << station.KC << endl;
                cout << "3. Количество цехов в работе: " << station.KCV << endl;

                cout << "Что вы хотите изменить? (1-3, 0 - отмена): ";
                int editChoice = checkEditChoice(3);

                if (editChoice == 0) {
                    cout << "Редактирование отменено." << endl;
                }
                else if (editChoice == 1) {
                    cout << "Введите новое название: ";
                    station.name2 = checkString();
                    cout << "Название обновлено." << endl;
                }
                else if (editChoice == 2) {
                    cout << "Введите новое количество цехов: ";
                    station.KC = checkInt();
                    while (station.KC <= 0) {
                        cout << "Количество цехов должно быть положительным! Повторите ввод: ";
                        station.KC = checkInt();
                    }
                    // Проверка, чтобы количество работающих цехов не превышало общее количество
                    if (station.KCV > station.KC) {
                        station.KCV = station.KC;
                    }
                    cout << "Количество цехов обновлено." << endl;
                }
                else if (editChoice == 3) {
                    cout << "Введите новое количество цехов в работе: ";
                    station.KCV = checkInt();
                    while (station.KCV < 0 or station.KCV > station.KC) {
                        cout << "Количество работающих цехов должно быть от 0 до " << station.KC << "! Повторите ввод: ";
                        station.KCV = checkInt();
                    }
                    cout << "Количество цехов в работе обновлено." << endl;
                }
            }
        }
        else if (chosen == 0) {
            cout << "Выход из программы." << endl;
            break;
        }
        else if (chosen == 6) {
            saveToFile(truba, station, filename);
        }
        else if (chosen == 7) {
            FileLoad(truba, station, filename);
        }
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pipe {
	string name;
	float length;
	int diametr;
	bool check;
};

struct KS {
	string name2;
	int KC;
	int KCV;
};


int main() {
	setlocale(LC_ALL, "RU");

	Pipe truba;
	KS station;
	int chosen = 0;

	while (true) { 
		cout << "МЕНЮ КНОПОК: '1' - Добавить трубу, '2' - Добавить КС , '3' -  Просмотр всех объектов, '4' - Редактировать трубу, '5' - Редактировать КС, '6' -  Сохранить, '7' - Загрузить, '0' - Выход. " << endl;
		cin >> chosen;
		if (chosen == 1) {
			cout << "Ввведите характеристики для трубы." << endl;
			cout << "Название: ";
			cin >> truba.name;

			cout << "Длина (км): ";
			cin >> truba.length;

			cout << "Диаметр: ";
			cin >> truba.diametr;

			cout << "В ремонте ли труба? (Да - '1', Нет - '0') ";
			cin >> truba.check;
		}

		else if (chosen == 2) {
			
			cout << "Ввведите характеристики для станции." << endl;
			cout << "Название: ";
			cin >> station.name2;

			cout << "Количество цехов: ";
			cin >> station.KC;

			cout << "Количество цехов (в работе): ";
			cin >> station.KCV;
		}

		
		else if (chosen == 0) {
			cout << "Выход из программы." << endl;
			break;
		}
	}
	
	return 0;
}


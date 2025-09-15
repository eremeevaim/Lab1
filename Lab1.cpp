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

			truba.isAdded = true;
			cout << "Данные трубы успешно добавлены." << endl;
		}

		else if (chosen == 2) {
			
			cout << "Введите характеристики для станции." << endl;
			cout << "Название: ";
			cin >> station.name2;

			cout << "Количество цехов: ";
			cin >> station.KC;

			cout << "Количество цехов (в работе): ";
			cin >> station.KCV;

			station.isAdded = true;
			cout << "Данные КС успешно добавлены." << endl;
		}
		else if (chosen == 3) {
			bool bothAdded = false;
			if (truba.isAdded) {
				cout << "ХАРАКАТЕРИСТИКИ ТРУБЫ" << endl;
				cout << "Название: " << truba.name << endl;
				cout << "Длина (км): " << truba.length << endl;
				cout << "Диаметр: " << truba.diametr << endl;
				cout << "В ремонте ли труба? (Да - '1', Нет - '0') " << truba.check << endl;
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
			else
			{
				cout << "Редактирование трубы. Текущие значения:" << endl;
				cout << "1. Название: " << truba.name << endl;
				cout << "2. Длина: " << truba.length << " км" << endl;
				cout << "3. Диаметр: " << truba.diametr << endl;
				cout << "4. Статус ремонта: " << (truba.check ? "В ремонте" : "Не в ремонте") << endl;

				cout << "Что вы хотите изменить? (1-4, 0 - отмена): ";
				int editChoice;
				cin >> editChoice;
				if (editChoice == 0) {
					cout << "Редактирование отменено." << endl;
				}
				else if (editChoice == 1) {
					cout << "Введите новое название: ";
					cin >> truba.name;
					cout << "Название обновлено." << endl;
				}
				else if (editChoice == 2) {
					cout << "Введите новую длину (км): ";
					cin >> truba.length;
					cout << "Длина обновлена." << endl;
				}
				else if (editChoice == 3) {
					cout << "Введите новый диаметр: ";
					cin >> truba.diametr;
					cout << "Диаметр обновлен." << endl;
				}
				else if (editChoice == 4) {
					cout << "В ремонте ли труба? (Да - '1', Нет - '0') ";
					cin >> truba.check;
					cout << "Статус ремонта обновлен." << endl;
				}
				else {
					cout << "Неверный выбор." << endl;
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
				int editChoice;
				cin >> editChoice;

				if (editChoice == 0) {
					cout << "Редактирование отменено." << endl;
				}
				else if (editChoice == 1) {
					cout << "Введите новое название: ";
					cin >> station.name2;
					cout << "Название обновлено." << endl;
				}
				else if (editChoice == 2) {
					cout << "Введите новое количество цехов: ";
					cin >> station.KC;
					cout << "Количество цехов обновлено." << endl;
				}
				else if (editChoice == 3) {
					cout << "Введите новое количество цехов в работе: ";
					cin >> station.KCV;

					if (station.KCV > station.KC) {
						cout << "Ошибка!Количество цехов в работе не может превышать общее количество цехов." << endl;
						station.KCV = station.KC;
					}
					else {
						cout << "Количество цехов в работе обновлено." << endl;
					}
				}
				else {
					cout << "Неверный выбор." << endl;
				}
			}
		}
		else if (chosen == 0) {
			cout << "Выход из программы." << endl;
			break;
		}
	}

	return 0;
}


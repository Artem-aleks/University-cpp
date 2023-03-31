#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Centr(const char* Date, int wLine) {

	int w = strlen(Date);
	int delta = ((wLine - w) / 2) - 1;
	cout << left;
	cout.width(delta); cout << " ";
	cout << Date;
	cout.width(delta); cout << " "; cout << " |" << endl;
}

struct Date {
	short day;
	short month;
	short year;
};

struct Record {
	char Naz[16];
	char simvol[3];
	char gectar[5];
	int rabotnic[3];
	struct Date date;
};

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[20];

	records[0] = { "Заря","Д","0300",120,{07, 03, 2022} };
	records[1] = { "Заря","Д","0300",120,{07, 04, 2022} };
	records[2] = { "Заря","Д","0300",120,{07, 05, 2022} };

	cout << "|";
	cout.width(100);
	cout.fill('-');
	cout << "|" << endl;

	cout.fill(' ');
	cout.width(100);
	cout << left << "|Сельскохозяйственные предприятия";
	cout << "|" << endl;
	cout.width(100); cout.fill('-'); cout << "|" << "|" << endl;
	cout.fill(' ');

	//Заголовок таблицы
	cout.width(20); cout << "|Название";
	cout.width(20); cout << "|Вид собственности";
	cout.width(20); cout << "|Площадь земли (га)";
	cout.width(20); cout << "|Кол.работников";
	cout.width(20); cout << "|Дата документа";
	cout << "|" << endl;
	cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');

	//Вывод строчек
	for (int i = 0; i < 3; i++) {
		cout << "|"; cout << setw(19); cout << left << records[i].Naz;
		cout << "|"; cout << setw(19); cout << left << records[i].simvol;
		cout << "|"; cout << setw(19); cout << left << records[i].gectar;
		cout << "|"; cout << setw(19); cout << right << records[i].rabotnic;
		cout << "|";
		cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
	}

	//Конец таблицы
	cout.width(100); cout << "|Вид собственности: Д - государственная, Ч - частная, К - кооперативная" << right << "|" << endl << "|";
	cout.width(100); cout.fill('-'); cout << "|" << endl;

}
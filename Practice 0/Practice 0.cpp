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
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string Naz[16];
	char simvol[3];
	string gectar[5];
	int rabotnic[3];
	char data[20][20];

	cout << "Введите имя, тип собственности, площадь земли, кол-во работников и дату документа(для 1 строки):" << endl;
	cin >> Naz[0] >> simvol[0] >> gectar[0] >> rabotnic[0] >> data[0];
	cout << "Введите имя, тип собственности, площадь земли, кол-во работников и дату документа(для 2 строки):" << endl;
	cin >> Naz[1] >> simvol[1] >> gectar[1] >> rabotnic[1] >> data[1];
	cout << "Введите имя, тип собственности, площадь земли, кол-во работников и дату документа(для 3 строки):" << endl;
	cin >> Naz[2] >> simvol[2] >> gectar[2] >> rabotnic[2] >> data[2];
	cout << endl;

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

	//Первая строка
	cout << "|"; cout << setw(19); cout << left << Naz[0];
	cout << "|"; cout << setw(19); cout << left << simvol[0];
	cout << "|"; cout << setw(19); cout << left << gectar[0];
	cout << "|"; cout << setw(19); cout << right << rabotnic[0]; cout << "|";
	Centr(data[0], 21);
	cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');

	//Вторая строка
	cout << "|"; cout << setw(19); cout << left << Naz[1];
	cout << "|"; cout << setw(19); cout << left << simvol[1];
	cout << "|"; cout << setw(19); cout << left << gectar[1];
	cout << "|"; cout << setw(19); cout << right << rabotnic[1]; cout << "|";
	Centr(data[1], 21);
	cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');

	//Третья строка
	cout << "|"; cout << setw(19); cout << left << Naz[2];
	cout << "|"; cout << setw(19); cout << left << simvol[2];
	cout << "|"; cout << setw(19); cout << left << gectar[2];
	cout << "|"; cout << setw(19); cout << right << rabotnic[2]; cout << "|";
	Centr(data[2], 21);
	cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');

	//Конец таблицы
	cout.width(100); cout << "|Вид собственности: Д - государственная, Ч - частная, К - кооперативная" << right << "|" << endl << "|";
	cout.width(100); cout.fill('-'); cout << "|" << endl;

}
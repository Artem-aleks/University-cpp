#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record {
	char Naz[16];
	char simvol[3];
	char gectar[5];
	char rabotnic[10];
	struct Date date;
};

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void contabl() {
	//Конец таблицы
	cout.width(100); cout << "|Вид собственности: Д - государственная, Ч - частная, К - кооперативная" << right << "|" << endl << "|";
	cout.width(100); cout.fill('-'); cout << "|" << endl;
}

void zagltabl() {
	//Заголовок таблицы
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

	cout.width(20); cout << "|Название";
	cout.width(20); cout << "|Вид собственности";
	cout.width(20); cout << "|Площадь земли (га)";
	cout.width(20); cout << "|Кол.работников";
	cout.width(20); cout << "|Дата документа";
	cout << "|" << endl;
	cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[20];

	records[0] = { "Заря","Д","0300","120",{07,03,2022} };
	records[1] = { "Росинка","К","0174","27",{03,07,2022} };
	records[2] = { "Петренко","Ч","0056","6",{8,8,2021} };

	zagltabl();

	Record* A;
	Record** B;
	int colvo = 3;
	int colvo1 = 10;

	A = (Record*)malloc(colvo * sizeof(Record)); // выделяем память 

	for (int i = 0; i < colvo; i++) { // заполняем память 
		strcpy_s(A[i].Naz, records[i].Naz);
		strcpy_s(A[i].simvol, records[i].simvol);
		strcpy_s(A[i].gectar, records[i].gectar);
		strcpy_s(A[i].rabotnic, records[i].rabotnic);
		A[i].date = records[i].date;

	}

	A = (Record*)realloc(A, 3 * sizeof(Record)); // увеличиваем память 

	B = (Record**) new Record * [colvo1];

	for (int i = 0; i < colvo1; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = A[i];
	}

	//Вывод строчек
	for (int i = 0; i < 3; i++) {
		cout << "|"; cout << setw(19); cout << left << records[i].Naz;
		cout << "|"; cout << setw(19); cout << left << records[i].simvol;
		cout << "|"; cout << setw(19); cout << left << records[i].gectar;
		cout << "|"; cout << setw(19); cout << right << records[i].rabotnic;
		cout << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 19);
		cout << " |";
		cout << "\n";
		cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
	}
	contabl();

	for (int i = 0; i < colvo1; i++) {
		cout << "Адрес A[i]" << &A[i] << "Значение A[i]" << A[i].Naz << endl;
		cout << "Адрес B[i]" << &B[i] << "Значение B[i]" << (*B[i]).Naz << endl;
	}
	for (int i = 0; i < colvo1; i++) {
		cout << "Адрес B[i]" << &B[i] << "Значение B[i]" << (*B[i]).Naz << endl;
	}
	delete[]B;
	free(A);

}
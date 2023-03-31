#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>

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

	cout << "Вывод таблицы из нулевой практики: \n";

	zagltabl();

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

	//1 Записываем в файл данные из таблицы(в текстовый)
	FILE* Aleksanov;
	fopen_s(&Aleksanov, "Aleksanov.txt", "w+");
	for (int i = 0; i < 3; i++) {
		fprintf(Aleksanov, "%s %s %s %s %d %d %d \n", \
			records[i].Naz, records[i].simvol, \
			records[i].gectar, records[i].rabotnic, \
			records[i].date.day, records[i].date.month, records[i].date.year);
	}
	fclose(Aleksanov);

	//2 Считать 3 записи из файла в текстовом формате
	fopen_s(&Aleksanov, "Aleksanov.txt", "r");

	Record rdRecords[4];

	for (int i = 0; i < 3; i++) {
		fscanf_s(Aleksanov, "%s", &rdRecords[i].Naz, _countof(rdRecords[i].Naz));
		fscanf_s(Aleksanov, "%s", &rdRecords[i].simvol, _countof(rdRecords[i].simvol));
		fscanf_s(Aleksanov, "%s", &rdRecords[i].gectar, _countof(rdRecords[i].gectar));
		fscanf_s(Aleksanov, "%s", &rdRecords[i].rabotnic, _countof(rdRecords[i].rabotnic));
		fscanf_s(Aleksanov, "%d", &rdRecords[i].date.day);
		fscanf_s(Aleksanov, "%d", &rdRecords[i].date.month);
		fscanf_s(Aleksanov, "%d", &rdRecords[i].date.year);
	}
	fclose(Aleksanov);

	cout << "\n";
	cout << "Вывод таблицы с данными из файла(Текстовый):";
	cout << "\n";
	cout << "\n";

	zagltabl();

	//Вывод строчек
	for (int i = 0; i < 3; i++) {
		cout << "|"; cout << setw(19); cout << left << rdRecords[i].Naz;
		cout << "|"; cout << setw(19); cout << left << rdRecords[i].simvol;
		cout << "|"; cout << setw(19); cout << left << rdRecords[i].gectar;
		cout << "|"; cout << setw(19); cout << right << rdRecords[i].rabotnic;
		cout << "|";
		printDate(rdRecords[i].date.day, rdRecords[i].date.month, rdRecords[i].date.year, 19);
		cout << " |";
		cout << "\n";
		cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
	}
	contabl();

	//Записать 3 записи(три строки(records) из таблицы практики 0) в файл в бинарном формате.
	FILE* Aleksanovbin;
	fopen_s(&Aleksanovbin, "Aleksanovbin.bin", "w");
	fwrite(records, sizeof(records), 1, Aleksanovbin);
	fclose(Aleksanovbin);

	//Считать данные из файла бинарного формата
	fopen_s(&Aleksanovbin, "Aleksanovbin.bin", "rb");
	fread_s(rdRecords, sizeof(rdRecords), sizeof(rdRecords), 1, Aleksanovbin);
	fclose(Aleksanovbin);

	cout << "\n";
	cout << "Вывод таблицы с данными из файла(бинарный):";
	cout << "\n";
	cout << "\n";

	zagltabl();

	//Вывод строчек
	for (int i = 0; i < 3; i++) {
		cout << "|"; cout << setw(19); cout << left << rdRecords[i].Naz;
		cout << "|"; cout << setw(19); cout << left << rdRecords[i].simvol;
		cout << "|"; cout << setw(19); cout << left << rdRecords[i].gectar;
		cout << "|"; cout << setw(19); cout << right << rdRecords[i].rabotnic;
		cout << "|";
		printDate(rdRecords[i].date.day, rdRecords[i].date.month, rdRecords[i].date.year, 19);
		cout << " |";
		cout << "\n";
		cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
	}
	contabl();

	//Добавить новую запись в файл в бинарном формате (9 вариант) и прочитать файл
	Record t1Record[4];

	for (int i = 0; i < 3; i++) {
		t1Record[i] = records[i];
	}

	cout << "\n";
	cout << "Введите данные для 4 строки (дату вводить без точек и нулей): \n";
	cin >> t1Record[3].Naz >> t1Record[3].simvol >> t1Record[3].gectar >> t1Record[3].rabotnic >> t1Record[3].date.day >> t1Record[3].date.month >> t1Record[3].date.year;

	fopen_s(&Aleksanovbin, "Aleksanovbin.bin", "wb");
	fwrite(t1Record, sizeof(t1Record), 1, Aleksanovbin);
	fclose(Aleksanovbin);


	fopen_s(&Aleksanovbin, "Aleksanovbin.bin", "rb");
	fread_s(t1Record, sizeof(t1Record), sizeof(t1Record), 1, Aleksanovbin);
	fclose(Aleksanovbin);



	cout << "\n";
	cout << "Вывод таблицы с новой записью из бинарного файла: \n";
	cout << "\n";

	zagltabl();

	//Вывод строчек
	for (int i = 0; i < 4; i++) {
		cout << "|"; cout << setw(19); cout << left << t1Record[i].Naz;
		cout << "|"; cout << setw(19); cout << left << t1Record[i].simvol;
		cout << "|"; cout << setw(19); cout << left << t1Record[i].gectar;
		cout << "|"; cout << setw(19); cout << right << t1Record[i].rabotnic;
		cout << "|";
		printDate(t1Record[i].date.day, t1Record[i].date.month, t1Record[i].date.year, 19);
		cout << " |";
		cout << "\n";
		cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
	}
	contabl();

	//9 вариант.Поменять значения даты в полях 2 и 4.

	fopen_s(&Aleksanovbin, "Aleksanovbin.bin", "rb");
	swap(t1Record[1].date.day, t1Record[3].date.day);
	swap(t1Record[1].date.month, t1Record[3].date.month);
	swap(t1Record[1].date.year, t1Record[3].date.year);
	fclose(Aleksanovbin);

	fopen_s(&Aleksanovbin, "Aleksanovbin.bin", "wb+");
	fread_s(t1Record, sizeof(t1Record), sizeof(t1Record), 1, Aleksanovbin);
	fclose(Aleksanovbin);

	cout << "\n";
	cout << "Вывод таблицы с измененными датами: \n";
	cout << "\n";

	zagltabl();

	//Вывод строчек
	for (int i = 0; i < 4; i++) {
		cout << "|"; cout << setw(19); cout << left << t1Record[i].Naz;
		cout << "|"; cout << setw(19); cout << left << t1Record[i].simvol;
		cout << "|"; cout << setw(19); cout << left << t1Record[i].gectar;
		cout << "|"; cout << setw(19); cout << right << t1Record[i].rabotnic;
		cout << "|";
		printDate(t1Record[i].date.day, t1Record[i].date.month, t1Record[i].date.year, 19);
		cout << " |";
		cout << "\n";
		cout.width(100); cout.fill('-'); cout << "|" << "|" << endl; cout.fill(' ');
	}
	contabl();
}
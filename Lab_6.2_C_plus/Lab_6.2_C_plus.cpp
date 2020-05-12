#include <sys/types.h>
#include <fcntl.h> 
#include <iostream>
#include <string>
#pragma warning(disable : 4996)

using namespace std;

struct Numbers
{
	int Number;				//Ф.И.О

};

void task()
{
	cout << "Размер структуры Human: " << sizeof(Numbers) << " bytes";
	string Surname[] = { "Иванов А.Г.","Соколов В.И.","Марков Н.В.","Громов Д.П." };
	const int N = 4;
	Numbers* number = new Numbers[N];
	char path[] = "db.bin";
	cout << endl << endl << "Список чисел:" << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << (number[i].Number = 0 + rand() % 555) << " ";
	}

	FILE* f_out, * f_in;
	f_out = fopen(path, "wb");
	fwrite(number, sizeof(Numbers), N, f_out);
	fclose(f_out);

	delete[] number;
	number = nullptr;

	cout << endl << endl << "Числа до и после умножения на 2 : " << endl;
	Numbers* restoredDB = new Numbers[N];
	f_in = fopen(path, "rb+");
	fread(restoredDB, sizeof(Numbers), N, f_in);
	fclose(f_in);

	for (size_t i = 0; i < N; i++)
	{
		cout <<"До: " << restoredDB[i].Number <<" "; 
		cout <<"После: "<< restoredDB[i].Number * 2 << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Task 2 \n";
	task();
}
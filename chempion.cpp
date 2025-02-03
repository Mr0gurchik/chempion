#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <Windows.h>


using namespace std;

bool containsOnlySpaces(string& str) {
	return all_of(str.begin(), str.end(), isspace);
}

unique_ptr<string> Prov(string& a, string& b)
{
	stringstream stream(b);
	string ser;

	while (stream >> ser)
	{
		if (a.find(ser) != string::npos) // string::npos это обозначение find не нашел искомый символ
		{
			return make_unique<string>(ser);
		}
	}
	return nullptr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	

	string g, f;

	while (bool o = true)

	{
		cout << "Введите первую строку: ";
		getline(cin, g);

		cout << "Введите вторую строку: ";
		getline(cin, f);

		if (g.empty() || f.empty() || containsOnlySpaces(g) || containsOnlySpaces(f))
		{
			cout << "Произошла непредвиденая ошибка возможно вы написали НИЧТО" << endl;
		}

		else
		{
			break;
		}
	}

	unique_ptr<string> gotovo = Prov(g, f);

	if (gotovo != nullptr)
	{
		cout << "Первое вхождение символа из 2 строки в 1: " << *gotovo << endl;
	}
	else 
	{
		cout << "Ни один символ из 2 строки не входит в 1" << endl;
	}

}
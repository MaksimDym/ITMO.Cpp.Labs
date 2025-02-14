
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int N = 10;

int main()
{
	//Practic
	
	/*double sum = 0;
	int const n = 100;
	double nums[n];
	for (int i = 0; i < n; i++)
	{
		nums[i] = (rand() % 100);
	}
	ofstream out("test", ios::out | ios::binary);
	if (!out) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}
	out.write((char*)nums, sizeof(nums));
	out.close();
	ifstream in("test", ios::in | ios::binary);
	if (!in) {
		cout << "Файл открыть невозможно";
		return 1;
	}
	in.read((char*)&nums, sizeof(nums));

	int k = sizeof(nums) / sizeof(double);
	for (int i = 0; i < k; i++)
	{
		sum = sum + nums[i];
		cout << nums[i] << ' ';
	}
	 cout << "\nsum = " << sum << endl;
	 in.close();*/

	//Control

	// lab1 
	/*ofstream outFile("poem.txt");
	if (!outFile) {
		cerr << "Ошибка: не удалось открыть файл для записи." << endl;
		return 1;
	}
	string line;
	cout << "Введите стихотворение (вводите строки, завершите ввод пустой строкой):" << endl;
	
	while (true) {
		getline(cin, line);
		if (line.empty()) {
			break; 
		}
		outFile << line << endl; 
	}
	outFile.close(); 
	cout << "Стихотворение успешно записано в файл 'poem.txt'." << endl;
	return 0;*/
	// lab 2 

	int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
	int original[N];
	for (int i = 0; i < N; i++) {
		original[i] = a[i];
	}
	for (int i = 0; i < N; i++) {
		int min = i; 
		for (int j = i + 1; j < N; j++) {
			if (a[j] < a[min]) {
				min = j; 
			}
		}
		if (i != min) {
			int buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}
	ofstream outFile("arrays.txt");
	if (!outFile) {
		cerr << "Ошибка: не удалось открыть файл для записи." << endl;
		return 1; 
	}
	outFile << "Исходный массив:\n";
	for (int i = 0; i < N; i++) {
		outFile << original[i] << '\t';
	}
	outFile << "\n\nОтсортированный массив:\n";
	for (int i = 0; i < N; i++) {
		outFile << a[i] << '\t';
	}
	outFile.close(); 
	cout << "Массивы успешно записаны в файл 'arrays.txt'." << endl;
	return 0;




}






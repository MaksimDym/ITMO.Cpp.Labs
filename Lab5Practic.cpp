
#include <iostream>
#include<math.h>
#include <string>
#include <Windows.h>
#include <limits>
#include <cstdlib> 
#include <ctime>  
#include <vector>

using namespace std;

// Прототипы функций
void show_array(const int Arr[], const int N);
bool from_min(const int a, const int b);
bool from_max(const int a, const int b);
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b));

void show_array(const int Arr[], const int N) {
    for (int i = 0; i < N; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

bool from_min(const int a, const int b) {
    return a > b; // Сравнение для сортировки по возрастанию
}

bool from_max(const int a, const int b) {
    return a < b; // Сравнение для сортировки по убыванию
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b)) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if ((*compare)(Arr[j], Arr[j + 1])) {
                swap(Arr[j], Arr[j + 1]);
            }
        }
    }
}


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // lab1 
    //const int n = 10;
    //int mas[n];

    //for (int i = 0; i < n; i++) {
    //    cout << "mas[" << i << "]=";
    //    cin >> mas[i];
    //}
    ////Суммы
    //int sum = 0;
    //int sum_neg = 0;
    //int sum_pos = 0;
    //int sum_even_idx = 0;
    //int sum_odd_idx = 0;
    //// Поиск максимального и минимального элементов
    //int max_elem = numeric_limits<int>::min();
    //int min_elem = numeric_limits<int>::max();
    //int max_index = -1;
    //int min_index = -1;
    //for (int i = 0; i < n; i++) {
    //    sum += mas[i]; // Сумма всех элементов
    //    // Сумма отрицательных элементов
    //    if (mas[i] < 0) {
    //        sum_neg += mas[i];
    //    }
    //    // Сумма положительных элементов
    //    if (mas[i] > 0) {
    //        sum_pos += mas[i];
    //    }
    //    // Сумма элементов с четными индексами
    //    if (i % 2 == 0) {
    //        sum_even_idx += mas[i];
    //    }
    //    // Сумма элементов с нечетными индексами
    //    if (i % 2 != 0) {
    //        sum_odd_idx += mas[i];
    //    }
    //    // Поиск максимального и минимального элементов
    //    if (mas[i] > max_elem) {
    //        max_elem = mas[i];
    //        max_index = i;
    //    }
    //    if (mas[i] < min_elem) {
    //        min_elem = mas[i];
    //        min_index = i;
    //    }
    //}
    //// Вывод результатов
    //cout << "Сумма элементов массива равна: " << sum << endl;
    //cout << "Сумма отрицательных элементов: " << sum_neg << endl;
    //cout << "Сумма положительных элементов: " << sum_pos << endl;
    //cout << "Сумма элементов с четными индексами: " << sum_even_idx << endl;
    //cout << "Сумма элементов с нечетными индексами: " << sum_odd_idx << endl;
    //cout << "Максимальный элемент: " << max_elem << " (индекс: " << max_index << ")" << endl;
    //cout << "Минимальный элемент: " << min_elem << " (индекс: " << min_index << ")" << endl;
    //// Расчет произведения элементов между максимальным и минимальным элементами
    //int product = 1;
    //bool found_elements = false;
    //if (max_index > min_index) {
    //    for (int i = min_index + 1; i < max_index; i++) {
    //        product *= mas[i];
    //        found_elements = true;
    //    }
    //}
    //else {
    //    for (int i = max_index + 1; i < min_index; i++) {
    //        product *= mas[i];
    //        found_elements = true;
    //    }
    //}
    //if (found_elements) {
    //    cout << "Произведение элементов между максимальным и минимальным элементами: " << product << endl;
    //}
    //else {
    //    cout << "Нет элементов между максимальным и минимальным элементами." << endl;
    //}
    //return 0;

    //lab2 

    //const int N = 10;
    //int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    //int min = 0; // для записи минимального значения
    //int buf = 0; // для обмена значениями
    //for (int i = 0; i < N; i++)
    //{
    //    min = i; // номер текущей ячейки, как ячейки с минимальным значением
    //    // в цикле найдем реальный номер ячейки с минимальным значением
    //    for (int j = i + 1; j < N; j++)
    //        min = (a[j] < a[min]) ? j : min;
    //    // перестановка этого элемента, поменяв его местами с текущим
    //    if (i != min)
    //    {
    //        buf = a[i];
    //        a[i] = a[min];
    //        a[min] = buf;
    //    }
    //}
    //for (int i : a)
    //    cout << i << '\t';

    //lab3
      
    /* const int N = 10;
        int my_choose = 0;
        int A[N] = { 9, 8, 7, 6, 1, 2, 3, 5, 4, 9 }; 

        cout << "Исходные данные: ";
        show_array(A, N);

        cout << "1. Сортировать по возрастанию\n";
        cout << "2. Сортировать по убыванию\n";
        cin >> my_choose;*/

       /* if (my_choose == 1) {
            bubble_sort(A, N, from_min);
            cout << "Отсортированные данные по возрастанию: ";
            show_array(A, N);
        }
        else if (my_choose == 2) {
            bubble_sort(A, N, from_max);
            cout << "Отсортированные данные по убыванию: ";
            show_array(A, N);
        }
        else {
            cout << "Некорректный выбор.\n";
        }

        switch (my_choose)
        {
        case 1: bubble_sort(A, N, from_min); break;
        case 2: bubble_sort(A, N, from_max); break;
        default: cout << "\rНеизвестная операция ";
        }*/
       
        //bool (*from_f[2])(int, int) = { from_min,from_max };
        //if (my_choose == 1 || my_choose == 2) {
        //    bubble_sort(A, N, from_f[my_choose - 1]); // Вызов сортировки с указателем на функцию
        //    cout << (my_choose == 1 ? "Отсортированные данные по возрастанию: " : "Отсортированные данные по убыванию: ");
        //    show_array(A, N);
        //}
        //else {
        //    cout << "Некорректный выбор.\n";
        //}

        //return 0;
        //bubble_sort(A, N, (*from_f[my_choose - 1]));
        //return 0;

    // lab 4 

        //int N;
        //cout << "Введите размер массива: ";
        //cin >> N;
        //// Динамическое выделение памяти для массива
        //int* A = new int[N];
        //// Заполнение массива пользователем
        //cout << "Введите " << N << " элементов массива:\n";
        //for (int i = 0; i < N; i++) {
        //    cin >> A[i];
        //}
        //cout << "Исходные данные: ";
        //show_array(A, N);
        //int my_choose;
        //cout << "1. Сортировать по возрастанию\n";
        //cout << "2. Сортировать по убыванию\n";
        //cin >> my_choose;
        //// Массив указателей на функции сравнения
        //bool (*from_f[2])(int, int) = { from_min, from_max };
        //// Проверка выбора пользователя
        //if (my_choose == 1 || my_choose == 2) {
        //    bubble_sort(A, N, from_f[my_choose - 1]); // Вызов сортировки с указателем на функцию
        //    cout << (my_choose == 1 ? "Отсортированные данные по возрастанию: " : "Отсортированные данные по убыванию: ");
        //    show_array(A, N);
        //}
        //else {
        //    cout << "Некорректный выбор.\n";
        //}
        //// Освобождение динамической памяти
        //delete[] A;

        //return 0;

     // lab5 
        srand(time(NULL)); // Инициализация генератора случайных чисел
        int a, b, c;       // Переменные для хранения множителей и ответа
        int k = 0;         // Счетчик ошибок

        const int n = 10;  // Константа для количества вопросов
        vector<int> v1;    // Вектор для хранения правильных ответов
        vector<int> v2;    // Вектор для хранения неправильных ответов

        // Генерация вопросов и ввод ответов
        for (int i = 0; i < n; i++) {
            a = rand() % 10 + 1; // Случайное число от 1 до 10
            b = rand() % 10 + 1; // Случайное число от 1 до 10

            cout << "Сколько будет " << a << " * " << b << "? ";
            cin >> c;            // Ввод ответа

            // Проверка ответа
            if (a * b != c) {
                v2.push_back(c); // Добавляем неправильный ответ в вектор v2
                k++;             // Увеличиваем счетчик ошибок
            }
            else {
                v1.push_back(c); // Добавляем правильный ответ в вектор v1
            }
        }

        // Вывод всех введенных ответов
        cout << "\nВсе ответы: ";
        for (int i = 0; i < n; i++) {
            cout << (i < v1.size() + v2.size() ? (i < v1.size() ? v1[i] : v2[i - v1.size()]) : 0) << " ";
        }
        cout << endl;

        // Вывод количества ошибок
        cout << "Количество ошибок: " << k << endl;

        // Вывод правильных ответов
        cout << "\nПравильные ответы: ";
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " "; // Вывод каждого правильного ответа
        }
        cout << endl;

        // Вывод неправильных ответов
        cout << "\nНеправильные ответы: ";
        for (int i = 0; i < v2.size(); i++) {
            cout << v2[i] << " "; // Вывод каждого неправильного ответа
        }
        cout << endl;

        return 0;


}


#include <iostream>
#include <limits>
#include<Windows.h>
#include<cstdlib>
#include <cstring>

using namespace std;

//lab1.1
 
//void processArray(int size, int* arr) {
//    
//    int sum = 0, sum_neg = 0, sum_pos = 0;
//    int sum_even_idx = 0, sum_odd_idx = 0;
//    int max_elem = numeric_limits<int>::min();
//    int min_elem = numeric_limits<int>::max();
//    int max_index = -1, min_index = -1;
//    int product_between = 1;
//    bool found_elements = false;
//
//    for (int i = 0; i < size; i++) {
//        sum += arr[i]; 
//        if (arr[i] < 0) {
//            sum_neg += arr[i]; 
//        }
//        if (arr[i] > 0) {
//            sum_pos += arr[i];
//        }
//        if (i % 2 == 0) {
//            sum_even_idx += arr[i]; 
//        }
//        else {
//            sum_odd_idx += arr[i]; 
//        }
//        if (arr[i] > max_elem) {
//            max_elem = arr[i];
//            max_index = i; 
//        }
//        if (arr[i] < min_elem) {
//            min_elem = arr[i];
//            min_index = i; 
//        }
//    }
//    if (max_index > min_index) {
//        for (int i = min_index + 1; i < max_index; i++) {
//            product_between *= arr[i];
//            found_elements = true;
//        }
//    }
//    else {
//        for (int i = max_index + 1; i < min_index; i++) {
//            product_between *= arr[i];
//            found_elements = true;
//        }
//    }
//    if (!found_elements) {
//        product_between = 0; 
//    }
//
//    cout << "Сумма элементов массива равна: " << sum << endl;
//    cout << "Сумма отрицательных элементов: " << sum_neg << endl;
//    cout << "Сумма положительных элементов: " << sum_pos << endl;
//    cout << "Сумма элементов с четными индексами: " << sum_even_idx << endl;
//    cout << "Сумма элементов с нечетными индексами: " << sum_odd_idx << endl;
//    cout << "Максимальный элемент: " << max_elem << " (индекс: " << max_index << ")" << endl;
//    cout << "Минимальный элемент: " << min_elem << " (индекс: " << min_index << ")" << endl;
//    cout << "Произведение элементов между максимальным и минимальным элементами: " << product_between << endl;
//}

//lab1.2
void selectionSort(int size, int* arr) {
    for (int i = 0; i < size; i++) {
        int minIndex = i; 
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Обновление индекса минимального элемента
            }
        }
        // Перестановка текущего элемента с минимальным
        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

//lab2

int* max_vect(int kc, int* a, int* b) {
    int* c = new int[kc];
    for (int i = 0; i < kc; i++) {
        c[i] = (a[i] > b[i]) ? a[i] : b[i];
    }
    return c;
}

//lab3

int transpositionSearch(int arr[], int size, int key) {
    if (size == 0) {
        return -1; 
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            if (i > 0) {
                swap(arr[i], arr[i - 1]);
            }
            return i - 1; 
        }
    }
    return -1; 
}

//lab4


int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //lab1.1
    
   /* const int n = 10;
    int mas[n];

    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
    processArray(n, mas);
    return 0;*/

    //lab1.2

   /* const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    selectionSort(N, a);

    cout << "Отсортированный массив: ";
    for (int i : a) {
        cout << i << '\t';
    }

    return 0;*/

    // lab2 

    /*int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };
    int kc = sizeof(a) / sizeof(a[0]); 
    int* c; 
    c = max_vect(kc, a, b);
    for (int i = 0; i < kc; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    delete[] c; 
    return 0;*/

    //lab3

   /* const int size = 6;
    int arr[size] = { 10, 20, 30, 40, 50, 60 };
    int key;
    cout << "Введите элемент для поиска: ";
    cin >> key;
    int index = transpositionSearch(arr, size, key);
    if (index != -1) {
        cout << "Элемент " << key << " найден по индексу " << index << endl;
        cout << "Обновленный массив: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Элемент " << key << " не найден." << endl;
    }
    return 0;*/

    //lab4

    if (argc != 4) {
        cout << "Ошибка: недостаточно аргументов. Используйте -a для сложения или -m для умножения." << endl;
        return 1;
    }
    const char* operation = argv[1];
    if (strncmp(operation, "-a", 1) != 0 && strncmp(operation, "-m", 2) != 0) {
        cout << "Ошибка: неверный флаг. Используйте -a для сложения или -m для умножения." << endl;
        return 1;
    }
    int num1 = atoi(argv[2]); 
    int num2 = atoi(argv[3]); 
    if (strncmp(operation, "-a", 2) == 0) {
        cout << "Результат сложения: " << (num1 + num2) << endl;
    }
    else if (strncmp(operation, "-m", 2) == 0) {
        cout << "Результат умножения: " << (num1 * num2) << endl;
    }
    return 0;

}
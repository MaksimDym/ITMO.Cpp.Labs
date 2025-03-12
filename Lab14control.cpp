#include <iostream>
#include <type_traits>
#include<Windows.h>
#include <vector>
#include <iterator>

//lab1
template <typename T>
double calculateAverage(T* arr, int size) {
    if (size <= 0) {
        return 0.0; 
    }
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size; 
}

//lab2
template <typename Container>
void Print(const Container& container, const std::string& delimiter) {
    // Проверяем, что контейнер не пустой
    if (container.empty()) {
        std::cout << '\n'; // Перевод строки, если контейнер пустой
        return;
    }
    auto it = container.begin();
    std::cout << *it; 

    for (++it; it != container.end(); ++it) {
        std::cout << delimiter << *it;
    }
    std::cout << '\n'; 
}



int main() {
   
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
     //lab1 
   /* int intArray[] = { 1, 2, 3, 4, 5 };
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Average of int array: " << calculateAverage(intArray, intSize) << std::endl;
    long longArray[] = { 100000L, 200000L, 300000L, 400000L, 500000L };
    int longSize = sizeof(longArray) / sizeof(longArray[0]);
    std::cout << "Average of long array: " << calculateAverage(longArray, longSize) << std::endl;

    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Average of double array: " << calculateAverage(doubleArray, doubleSize) << std::endl;

    char charArray[] = { 'a', 'b', 'c', 'd', 'e' };
    int charSize = sizeof(charArray) / sizeof(charArray[0]);

    double charAverage = calculateAverage(reinterpret_cast<int*>(charArray), charSize);
    std::cout << "Average of char array (as int): " << charAverage << std::endl;

    return 0;*/

    //lab2
    std::vector<int> data = { 1, 2, 3 };
    Print(data, ", "); 

    std::vector<std::string> strings = { "Hello", "world", "!" };
    Print(strings, " "); 

    return 0;

}

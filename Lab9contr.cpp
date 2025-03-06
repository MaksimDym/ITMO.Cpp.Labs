#include <iostream>
#include <stdexcept>
#include <cmath> 
#include<Windows.h>
using namespace std;

//lab1

class Triangle {
private:
    double a; 
    double b; 
    double c; 

public:
    Triangle(double side_a, double side_b, double side_c) {
        setSides(side_a, side_b, side_c);
    }
    void setSides(double side_a, double side_b, double side_c) {
        if (side_a <= 0 || side_b <= 0 || side_c <= 0 ||
            side_a >= side_b + side_c ||
            side_b >= side_a + side_c ||
            side_c >= side_a + side_b) {
            throw invalid_argument("Недопустимые длины сторон треугольника.");
        }
        a = side_a;
        b = side_b;
        c = side_c;
    }
    double area() const {
        double s = (a + b + c) / 2; 
        return sqrt(s * (s - a) * (s - b) * (s - c)); 
    }
};

//lab2
class Time {
private:
    int hours;   
    int minutes; 
    int seconds;

public:
    
    Time(int h, int m, int s) {
        setTime(h, m, s);
    }
    void setTime(int h, int m, int s) {
        if (h < 0 || h > 23) {
            throw std::invalid_argument("Часы должны быть в диапазоне от 0 до 23.");
        }
        if (m < 0 || m > 59) {
            throw std::invalid_argument("Минуты должны быть в диапазоне от 0 до 59.");
        }
        if (s < 0 || s > 59) {
            throw std::invalid_argument("Секунды должны быть в диапазоне от 0 до 59.");
        }
        hours = h;
        minutes = m;
        seconds = s;
    }

    string toString() const {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hours, minutes, seconds);
        return std::string(buffer);
    }

    void addTime(int h, int m, int s) {
        seconds += s;
        minutes += m + seconds / 60;
        hours += h + minutes / 60;

        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //lab1
    /*try {
        double a, b, c;
        cout << "Введите длины сторон треугольника (a, b, c): ";
        cin >> a >> b >> c;
        Triangle triangle(a, b, c);
        cout << "Площадь треугольника: " << triangle.area() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;*/

    //lab2
    try {
        int h, m, s;
        cout << "Введите время (часы, минуты, секунды): ";
        cin >> h >> m >> s;
        Time time(h, m, s);
        cout << "Время: " << time.toString() << endl;

        int add_h, add_m, add_s;
        cout << "Введите время для добавления (часы, минуты, секунды): ";
        cin >> add_h >> add_m >> add_s;

        time.addTime(add_h, add_m, add_s);
        cout << "Новое время: " << time.toString() << endl;

    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;

}





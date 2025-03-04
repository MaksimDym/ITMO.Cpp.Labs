#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;


//lab1
  struct Time {
    int hours;
    int minutes;
    int seconds;
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

   
    Time add(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes + result.seconds / 60;
        result.hours = hours + other.hours + result.minutes / 60;
        result.seconds %= 60;
        result.minutes %= 60;
        result.hours %= 24; 
        return result;
    }

    Time subtract(const Time& other) const {
        Time result;
        int totalSecondsThis = toSeconds();
        int totalSecondsOther = other.toSeconds();
        int diff = totalSecondsThis - totalSecondsOther;

        if (diff < 0) {
            diff = 0;
        }

        result.hours = diff / 3600;
        diff %= 3600;
        result.minutes = diff / 60;
        result.seconds = diff % 60;
        return result;
    }
};

  //lab2

  struct QuadraticSolution {
      double root1;
      double root2;
  };

  QuadraticSolution solveQuadratic(double a, double b, double c) {
      QuadraticSolution solution;
      double discriminant = b * b - 4 * a * c;

      if (discriminant > 0) {
          
          solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
          solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
      }
      else if (discriminant == 0) {
          
          solution.root1 = solution.root2 = -b / (2 * a);
      }
      else {
          
          solution.root1 = solution.root2 = NAN; 
      }

      return solution;
  }

  //lab3
      tuple<double, double, bool>
      findQuadraticRoots(double a, double b, double c) {
      double root1, root2;
      double discriminant = b * b - 4 * a * c;

      if (discriminant > 0) {
          
          root1 = (-b + sqrt(discriminant)) / (2 * a);
          root2 = (-b - sqrt(discriminant)) / (2 * a);
          return make_tuple(root1, root2, true);
      }
      else if (discriminant == 0) {
          
          root1 = root2 = -b / (2 * a);
          return make_tuple(root1, root2, true);
      }
      else {
          
          return make_tuple(NAN, NAN, false); 
      }
  }



int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
   
    //lab1
   /* Time t1, t2;

    cout << "Введите время (часы минуты секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    if (t1.hours < 0 || t1.hours >= 24 ||
        t1.minutes < 0 || t1.minutes >= 60 ||
        t1.seconds < 0 || t1.seconds >= 60) {
        cerr << "Ошибка: введены недопустимые значения времени." << endl;
        return 1;
    }

    cout << "Общее количество секунд: " << t1.toSeconds() << endl;
    cout << "Введите второе время (часы минуты секунды): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    if (t2.hours < 0 || t2.hours >= 24 ||
        t2.minutes < 0 || t2.minutes >= 60 ||
        t2.seconds < 0 || t2.seconds >= 60) {
        cerr << "Ошибка: введены недопустимые значения времени." << endl;
        return 1;
    }

    Time sum = t1.add(t2);
    Time difference = t1.subtract(t2);
    cout << "Сумма времени: " << sum.hours << " час " << sum.minutes << " мин " << sum.seconds << " сек" << std::endl;
    cout << "Разность времени: " << difference.hours << " час " << difference.minutes << " мин " << difference.seconds << " сек" << std::endl;

    return 0;*/

    //lab2 

    //double a, b, c;
    //cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    //cin >> a >> b >> c;
    //if (a == 0) {
    //    cerr << "Ошибка: коэффициент 'a' не может быть равен нулю." << endl;
    //    return 1;
    //}
    //QuadraticSolution solution = solveQuadratic(a, b, c);
    //if (isnan(solution.root1)) {
    //    cout << "У квадратного уравнения нет действительных корней." << endl;
    //}
    //else if (solution.root1 == solution.root2) {
    //    cout << "У квадратного уравнения один корень: " << solution.root1 << endl;
    //}
    //else {
    //    cout << "Корни квадратного уравнения: " << solution.root1 << " и " << solution.root2 << endl;
    //}
    //return 0;

    //lab3

    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;
    if (a == 0) {
        cerr << "Ошибка: коэффициент 'a' не может быть равен нулю." << endl;
        return 1;
    }
    auto [root1, root2, hasRoots] = findQuadraticRoots(a, b, c);
    if (!hasRoots) {
        cout << "У квадратного уравнения нет действительных корней." << endl;
    }
    else if (root1 == root2) {
        cout << "У квадратного уравнения один корень: " << root1 << endl;
    }
    else {
        cout << "Корни квадратного уравнения: " << root1 << " и " << root2 << endl;
    }
    return 0;


}
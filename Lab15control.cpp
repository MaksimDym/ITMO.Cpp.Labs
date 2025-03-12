#include <iostream>
#include <map>
#include <string>
#include<Windows.h>

struct StudentGrade {
    std::string name;
    char grade;
};

class GradeBook {
private:
    std::map<std::string, char> grades; // Контейнер для хранения оценок студентов

public:
   
    void assignGrade(const std::string& studentName, char grade) {
        grades[studentName] = grade; 
    }
    char getGrade(const std::string& studentName) const {
        auto it = grades.find(studentName);
        if (it != grades.end()) {
            return it->second; // Возвращаем оценку
        }
        else {
            throw std::runtime_error("Студент не найден");
        }
    }
    void printGrades() const {
        for (const auto& pair : grades) {
            std::cout << "Студент: " << pair.first << ", Оценка: " << pair.second << '\n';
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    GradeBook gradeBook;

    gradeBook.assignGrade("Иванов", 'A');
    gradeBook.assignGrade("Петров", 'B');
    gradeBook.assignGrade("Сидоров", 'C');

    std::cout << "Оценки студентов:\n";
    gradeBook.printGrades();

    try {
        std::string studentName = "Петров";
        char grade = gradeBook.getGrade(studentName);
        std::cout << "Оценка студента " << studentName << ": " << grade << '\n';
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
#include <string>
#include <fstream>
#include "C:\Games\ITMO\ITMO.Cpp.Labs\student.h.cpp" // запустился только с указанием полного пути
using namespace std;

// Конструктор Student
Student::Student(string name, string last_name)
{
    Student::set_name(name);
    Student::set_last_name(last_name);
}

// Деструктор Student
Student::~Student()
{
    Student::save();
}

// Запись данных о студенте в файл
void Student::save()
{
    ofstream fout("students.txt", ios::app);

    fout << Student::get_name() << " "
        << Student::get_last_name() << " ";
    for (int i = 0; i < 5; ++i) {
        fout << Student::scores[i] << " ";
    }
    fout << endl;
    fout.close();
}


void Student::set_name(std::string student_name)
{
    name = student_name; 
}

std::string Student::get_name()
{
    return name; 
}
void Student::set_last_name(std::string student_last_name)
{
    last_name = student_last_name; 
}
std::string Student::get_last_name()
{
    return last_name; 
}
void Student::set_scores(int scores[])
{
    for (int i = 0; i < 5; ++i) {
        this->scores[i] = scores[i]; 
    }
}
void Student::set_average_score(double ball)
{
    average_score = ball; 
}
double Student::get_average_score()
{
    return average_score; 
}





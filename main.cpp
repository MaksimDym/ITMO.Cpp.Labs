#include <iostream>
#include <vector>
#include "human.h.cpp"
#include "student.h.cpp"
#include <Windows.h>
#include"teacher.h.cpp"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
   
    std::vector<int> scores = { 5, 3, 4, 4, 5, 3, 3, 3, 3 };
    human* stud = new student("Петров", "Иван", "Алексеевич", scores);
    std::cout << stud->get_full_name() << std::endl;
    std::cout << "Средний балл : " << dynamic_cast<student*>(stud)->get_average_score() << std::endl;
    unsigned int teacher_work_time = 40;
    human* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);
    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << dynamic_cast<teacher*>(tch)->get_work_time() << std::endl;
    delete stud;
    delete tch;

    return 0;
}



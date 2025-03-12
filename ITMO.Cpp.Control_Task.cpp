#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include<Windows.h>

// Абстрактный класс Person
class Person {
public:
    virtual ~Person() = default;
    virtual void display() const = 0; // Метод для отображения информации о человеке
    virtual std::string getType() const = 0; // Метод для получения типа человека
    virtual std::string getName() const = 0; // Метод для получения имени
    virtual std::string getPhone() const = 0; // Метод для получения телефона
};

// Класс Student
class Student : public Person {
private:
    std::string name;
    std::string phone;
    std::string major;

public:
    Student(const std::string& name, const std::string& phone, const std::string& major)
        : name(name), phone(phone), major(major) {}

    void display() const override {
        std::cout << "Студент: " << name << ", Телефон: " << phone << ", Специальность: " << major << "\n";
    }

    std::string getType() const override {
        return "Студент";
    }

    std::string getName() const override {
        return name;
    }

    std::string getPhone() const override {
        return phone;
    }
};

// Класс Teacher
class Teacher : public Person {
private:
    std::string name;
    std::string phone;
    std::string subject;

public:
    Teacher(const std::string& name, const std::string& phone, const std::string& subject)
        : name(name), phone(phone), subject(subject) {}

    void display() const override {
        std::cout << "Преподаватель: " << name << ", Телефон: " << phone << ", Предмет: " << subject << "\n";
    }

    std::string getType() const override {
        return "Преподаватель";
    }

    std::string getName() const override {
        return name;
    }

    std::string getPhone() const override {
        return phone;
    }
};

// Класс Colleague
class Colleague : public Person {
private:
    std::string name;
    std::string phone;
    std::string position;

public:
    Colleague(const std::string& name, const std::string& phone, const std::string& position)
        : name(name), phone(phone), position(position) {}

    void display() const override {
        std::cout << "Коллега: " << name << ", Телефон: " << phone << ", Должность: " << position << "\n";
    }

    std::string getType() const override {
        return "Коллега";
    }

    std::string getName() const override {
        return name;
    }

    std::string getPhone() const override {
        return phone;
    }
};

// Класс AddressBook
class AddressBook {
private:
    std::vector<std::shared_ptr<Person>> contacts;

public:
    void addContact(const std::shared_ptr<Person>& person) {
        contacts.push_back(person);
    }

    void displayContacts() const {
        for (const auto& contact : contacts) {
            contact->display();
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& contact : contacts) {
                outFile << contact->getType() << ","
                    << contact->getName() << ","
                    << contact->getPhone() << "\n"; // Упрощено для примера
            }
            outFile.close();
        }
        else {
            std::cerr << "Не удалось открыть файл для записи.\n";
        }
    }
};

// Класс FileManager
class FileManager {
public:
    static void loadFromFile(AddressBook& addressBook, const std::string& filename) {
        // Реализация загрузки из файла
        // Для упрощения опустим реализацию
    }
};

// Класс UserInterface
class UserInterface {
private:
    AddressBook addressBook;

public:
    void start() {
        int choice;
        do {
            std::cout << "1. Добавить студента\n" << "2. Добавить преподавателя\n"
                << "3. Добавить коллегу\n"
                << "4. Показать все контакты\n"
                << "5. Сохранить в файл\n"
                << "0. Выход\n"
                << "Выберите действие: ";
            std::cin >> choice;
            std::cin.ignore(); // Игнорируем символ новой строки

            if (choice == 1) {
                addStudent();
            }
            else if (choice == 2) {
                addTeacher();
            }
            else if (choice == 3) {
                addColleague();
            }
            else if (choice == 4) {
                addressBook.displayContacts();
            }
            else if (choice == 5) {
                addressBook.saveToFile("contacts.txt");
            }

        } while (choice != 0);
    }

private:
    void addStudent() {
        std::string name, phone, major;
        std::cout << "Введите ФИО студента: ";
        std::getline(std::cin, name);
        std::cout << "Введите телефон: ";
        std::getline(std::cin, phone);
        std::cout << "Введите специальность: ";
        std::getline(std::cin, major);

        addressBook.addContact(std::make_shared<Student>(name, phone, major));
    }

    void addTeacher() {
        std::string name, phone, subject;
        std::cout << "Введите ФИО преподавателя: ";
        std::getline(std::cin, name);
        std::cout << "Введите телефон: ";
        std::getline(std::cin, phone);
        std::cout << "Введите предмет: ";
        std::getline(std::cin, subject);

        addressBook.addContact(std::make_shared<Teacher>(name, phone, subject));
    }

    void addColleague() {
        std::string name, phone, position;
        std::cout << "Введите ФИО коллеги: ";
        std::getline(std::cin, name);
        std::cout << "Введите телефон: ";
        std::getline(std::cin, phone);
        std::cout << "Введите должность: ";
        std::getline(std::cin, position);

        addressBook.addContact(std::make_shared<Colleague>(name, phone, position));
    }
};


int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    UserInterface ui;
    ui.start();

    return 0;
}


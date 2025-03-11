#include <string>
#include <sstream>
#pragma once 
class human {
public:
    human(std::string last_name, std::string name, std::string second_name)
        : last_name(last_name), name(name), second_name(second_name) {}

    virtual ~human() {} // Виртуальный деструктор

    virtual std::string get_full_name() const {
        return last_name + " " + name + " " + second_name;
    }

private:
    std::string last_name;
    std::string name;
    std::string second_name;
};

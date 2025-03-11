#include "human.h.cpp"
#include <string>

class teacher : public human {
public:
    teacher(std::string last_name, std::string name, std::string second_name, unsigned int work_time)
        : human(last_name, name, second_name), work_time(work_time) {}

    virtual std::string get_full_name() const override {
        return human::get_full_name() + " (преподаватель)";
    }

    unsigned int get_work_time() const {
        return work_time;
    }

private:
    unsigned int work_time;
};


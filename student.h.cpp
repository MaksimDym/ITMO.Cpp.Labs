#include "human.h.cpp"
#include <string>
#include <vector>
#include <numeric>

class student : public human {
public:
    student(std::string last_name, std::string name, std::string second_name, std::vector<int> scores)
        : human(last_name, name, second_name), scores(scores) {}

    virtual std::string get_full_name() const override {
        return human::get_full_name() + " (студент)";
    }

    double get_average_score() const {
        return static_cast<double>(std::accumulate(scores.begin(), scores.end(), 0)) / scores.size();
    }

private:
    std::vector<int> scores;
};
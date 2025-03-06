//#include <iostream>
//
//class Time {
//private:
//    int hours;
//    int minutes;
//    int seconds;
//
//    void normalize() {
//        if (seconds >= 60) {
//            minutes += seconds / 60;
//            seconds %= 60;
//        }
//        if (minutes >= 60) {
//            hours += minutes / 60;
//            minutes %= 60;
//        }
//       
//    }
//
//public:
//    Time() : hours(0), minutes(0), seconds(0) {}
//    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
//        normalize(); 
//    }
//    void display() const {
//        std::cout << (hours < 10 ? "0" : "") << hours << ":"
//            << (minutes < 10 ? "0" : "") << minutes << ":"
//            << (seconds < 10 ? "0" : "") << seconds << std::endl;
//    }
//    Time operator+(const Time& other) const {
//        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
//    }
//};

//int main() {
//    const Time time1(11, 59, 59); 
//    const Time time2(0, 70, 70);   
//    Time time3; 
//    time3 = time1 + time2;
//    time3.display();
//    return 0;
//}
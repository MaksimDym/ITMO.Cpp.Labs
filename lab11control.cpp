#include <iostream>
#include <iomanip>
#include <cmath> 
#include <algorithm>
#include<vector>

using namespace std;

//lab1

class Time {
private:
    int hours;
    int minutes;
    void normalize() {
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (minutes < 0) {
            hours -= (-minutes + 59) / 60;
            minutes = (minutes + 60) % 60;
        }
        if (hours < 0) {
            hours = 0; 
            minutes = 0;
        }
    }

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        normalize();
    }

    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes);
    }

    Time operator-(const Time& other) const {
        return Time(hours - other.hours, minutes - other.minutes);
    }

    Time operator+(double additionalMinutes) const {
        return Time(hours, minutes + static_cast<int>(additionalMinutes));
    }

    friend Time operator+(double additionalMinutes, const Time& time) {
        return time + additionalMinutes;
    }

    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes);
    }

    bool operator!=(const Time& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Time& time) {
        os << setw(2) << setfill('0') << time.hours << ":"
            << setw(2) << setfill('0') << time.minutes;
        return os;
    }
};

//lab2

class Point {
private:
    double x; 
    double y; 
public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
    double distanceToOrigin() const {
        return std::sqrt(x * x + y * y); 
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "Point(" << point.x << ", " << point.y << ")";
        return os;
    }
    bool operator<(const Point& other) const {
        return this->distanceToOrigin() < other.distanceToOrigin();
    }
};

int main() {
   
    //lab1

   /* Time t1(2, 30); 
    Time t2(1, 45); 

    Time sum = t1 + t2; 
    Time difference = t1 - t2; 
    Time addedTime = t1 + 30.5; 
    Time addedTime2 = 15.75 + t2; 
   
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Added 30.5 minutes to t1: " << addedTime << endl;
    cout << "Added 15.75 minutes to t2: " << addedTime2 << endl;
   
    if (t1 == t2) {
        cout << "t1 is equal to t2" << endl;
    }
    else {
        cout << "t1 is not equal to t2" << endl;
    }
    return 0;*/

    //lab2

    vector<Point> v;
   
    v.push_back(Point(1, 2));  
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    sort(v.begin(), v.end());
   
    for (const auto& point : v) {
        cout << point << '\n';
    }
    
    return 0;
}

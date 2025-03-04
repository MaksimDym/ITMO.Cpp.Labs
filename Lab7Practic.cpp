
#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

//lab5

typedef tuple<string, int, double> Tuple;

Tuple funtup(string s, int a, double d)
{
    s.append("!");
    return make_tuple(s, a, d * 10);
}

Tuple modifyTuple(Tuple t)
{
    
    string newString = get<0>(t) + " modified";
    int newInt = get<1>(t) + 10;
    double newDouble = get<2>(t) * 2.0;
    return make_tuple(newString, newInt, newDouble);
}

tuple<double, string> transformTuple(Tuple t)
{
    string transformedString = get<0>(t) + " transformed";
    double transformedDouble = get<2>(t) + 5.5;
    return make_tuple(transformedDouble, transformedString);
}

struct Distance 
{
    int feet;
    double inches;
};

Distance AddDist(const Distance& d1, const Distance& d2)
{
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;
    if (d.inches >= 12.0)
    {
        d.inches -= 12.0;
        d.feet++;
    }
    return d;
}

Distance InputDist()
{
    Distance d;
    cout << "\nВведите число футов: ";
    cin >> d.feet;
    cout << "Введите число дюймов: ";
    cin >> d.inches;
    return d;
}


void ShowDist(Distance d)
{
    cout << d.feet << "\'-" << d.inches << "\"\n";
}

void printTupleOfThree(Tuple t)
{
    cout << "("
        << std::get<0>(t) << ", "
        << std::get<1>(t) << ", "
        << std::get<2>(t) << ")" << endl;
}

//int main()
//{
//
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//
//    //lab 1-3
// /*   Distance d1 = InputDist();
//    Distance d2 = { 1, 6.25 };
//    Distance d3 = AddDist(d1, d2);
//    ShowDist(d1);
//    ShowDist(d2);
//    ShowDist(d3);
//    int n;
//    cout << "Введите размер массива расстояний ";
//    cin >> n;
//    Distance* masDist = new Distance[n];
//    for (int i = 0; i < n; i++)
//    {
//        masDist[i] = InputDist();
//    }
//    for (int i = 0; i < n; i++)
//    {
//        ShowDist(masDist[i]);
//    }
//    delete[] masDist;
//    return 0;*/
//
//    //lab4 
//
//    vector<string> v1{ "one", "two", "three", "four", "five", "six" };
//    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
//    vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
//    
//
//    auto t0 = make_tuple(v1[0], v2[0], v3[0]);
//    auto t1 = funtup(v1[1], v2[1], v3[1]);
//
//    printTupleOfThree(t0);
//    printTupleOfThree(t1); 
//    
//    
//    Tuple modifiedTuple = modifyTuple(t0);
//    cout << "Modified tuple: ";
//    printTupleOfThree(modifiedTuple);
//
//    auto transformedTuple = transformTuple(t0);
//    cout << "Transformed tuple: ("
//        << std::get<0>(transformedTuple) << ", "
//        << std::get<1>(transformedTuple) << ")" << endl;
//
//    return 0;
//
//}


// mytime.h
// Simple Time class that follows C++ Primer Plus
#ifndef MYTIME_H_
#define MYTIME_H_

#include <iostream>

class Time {
public:
    Time();
    Time(int d, int h);

    int GetDays() const;
    int GetHours() const;

    // Overload the + operator
    Time operator+(const Time& t) const;

    // Overload the * operator for Time * int
    Time operator*(int multiplier) const;

    // Friend function for int * Time
    friend Time operator*(int multiplier, const Time& t);

    // Overload the * operator for Time * Time
    Time operator*(const Time& t) const;

    // Overload the << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Time& t);

private:
    int days;
    int hours;
};

#endif // MYTIME_H_

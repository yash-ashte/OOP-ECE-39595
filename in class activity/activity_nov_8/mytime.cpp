// mytime.cpp
#include "mytime.h"

// Default constructor
Time::Time() : days(0), hours(0) {}

// Parameterized constructor
Time::Time(int d, int h) : days(d), hours(h) {
    // Handle overflow of hours > 23
    days += hours / 24;
    hours %= 24;
}

// Getters for days and hours
int Time::GetDays() const { return days; }
int Time::GetHours() const { return hours; }

// Overload the + operator
Time Time::operator+(const Time& t) const {
    int totalHours = hours + t.hours;
    int totalDays = days + t.days + (totalHours / 24);
    totalHours %= 24;
    return Time(totalDays, totalHours);
}

// Overload the * operator for Time * int
Time Time::operator*(int multiplier) const {
    int totalHours = hours * multiplier;
    int totalDays = days * multiplier + (totalHours / 24);
    totalHours %= 24;
    return Time(totalDays, totalHours);
}

// Overload the * operator for int * Time (non-member function)
Time operator*(int multiplier, const Time& t) {
    return t * multiplier; // Reuse the member operator* for Time * int
}

// Overload the * operator for Time * Time
Time Time::operator*(const Time& t) const {
    int totalDays = days * t.days;
    int totalHours = hours * t.hours;
    totalDays += totalHours / 24;
    totalHours %= 24;
    return Time(totalDays, totalHours);
}

// Overload the << operator for printing
std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.days << " days, " << t.hours << " hours";
    return os;
}

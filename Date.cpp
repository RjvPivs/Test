#include "Date.h"

Date::Date() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    hour = 1 + ltm->tm_hour;
    minute = 1 + ltm->tm_min;
}

Date::Date(int day, int month, int year, int hour, int minute) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
}

bool Date::operator<(Date d1) {
    long long sec1 = d1.day * 86400 + 3600 * d1.hour + 60 * d1.minute;
    long long sec2 = day * 86400 + 3600 * hour + 60 * minute;
    if (d1.year > year) {
        return true;
    } else if (d1.year < year) {
        return false;
    } else if (d1.month > month) {
        return true;
    } else if (d1.month < month) {
        return false;
    } else {
        return sec1 > sec2;
    }
}

bool Date::operator>(Date d1) {
    long long sec1 = d1.day * 86400 + 3600 * d1.hour + 60 * d1.minute;
    long long sec2 = day * 86400 + 3600 * hour + 60 * minute;
    if (d1.year > year) {
        return false;
    } else if (d1.year < year) {
        return true;
    } else if (d1.month > month) {
        return false;
    } else if (d1.month < month) {
        return true;
    } else {
        return sec1 < sec2;
    }
}

bool Date::operator==(Date d1) {
    if (day == d1.day && month == d1.month && year == d1.year) {
        return true;
    } else {
        return false;
    }
}

string Date::getDate() {
    string temp;
    if (day < 10) {
        temp += "0";
    }
    temp += std::to_string(day) + ".";;
    if (month < 10) {
        temp += "0";
    }
    temp += std::to_string(month) + "." + std::to_string(year) + " ";
    if (hour < 10) {
        temp += "0";
    }
    temp += std::to_string(hour) + ":";
    if (minute < 10) {
        temp += "0";
    }
    temp += std::to_string(minute);
    return temp;
}
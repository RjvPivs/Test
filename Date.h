#ifndef TEST_DATE_H
#define TEST_DATE_H


#include <ctime>
#include <string>

using std::string;

struct Date {
    Date();

    Date(int, int, int, int, int);

    bool operator<(Date);

    bool operator>(Date);

    bool operator==(Date);
    // Gets the date as string.
    string getDate();

private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
};


#endif //TEST_DATE_H

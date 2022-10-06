//
// Created by Pivs on 06.10.2022.
//

#ifndef TEST_BIRTHDAY_H
#define TEST_BIRTHDAY_H

#include "Date.h"
#include "Name.h"

struct Birthday {
    Birthday(Name, Date, int);

    // Returns the age.
    int getAge();

    // Returns the name.
    string getName();

    // Returns the birthday date as string.
    string getDate();

    // Updates the age.
    void incrementAge();

    bool operator<(Birthday);

    bool operator>(Birthday);

    bool operator==(Birthday);

    // Checks if there was a birthday in this year.
    bool was;
private:
    int age;
    Name name;
    Date date;
};


#endif //TEST_BIRTHDAY_H

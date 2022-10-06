//
// Created by Pivs on 06.10.2022.
//

#ifndef TEST_BIRTHDAY_H
#define TEST_BIRTHDAY_H

#include "Date.h"
#include "Name.h"

struct Birthday {
    Birthday(Name, Date, int);

    int getAge();

    string getName();

    string getDate();

    void incrementAge();

    bool operator<(Birthday);

    bool operator>(Birthday);

    bool operator==(Birthday);

    bool was;
private:
    int age;
    Name name;
    Date date;
};


#endif //TEST_BIRTHDAY_H

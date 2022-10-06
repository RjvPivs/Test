#include "Birthday.h"

Birthday::Birthday(Name name, Date date, int age) {
    this->age = age;
    this->name = name;
    this->date = date;
    was = false;
}

int Birthday::getAge() {
    return age;
}

string Birthday::getName() {
    return name.getName();
}

string Birthday::getDate() {
    return date.getDate();
}

void Birthday::incrementAge() {
    age++;
}

bool Birthday::operator<(Birthday b1) {
    return date < b1.date;
}

bool Birthday::operator>(Birthday b1) {
    return date > b1.date;
}

bool Birthday::operator==(Birthday b1) {
    if (date.getDate() == b1.getDate() && name.getName() == b1.getName()) {
        return true;
    } else {
        return false;
    }
}
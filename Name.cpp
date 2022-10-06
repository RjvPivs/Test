#include "Name.h"

Name::Name() {
    name = "Ivan";
    surname = "Ivanov";
    middleName = "Ivanovich";
}

Name::Name(string surname, string name, string middleName) {
    this->name = name;
    this->surname = surname;
    this->middleName = middleName;
}

string Name::getName() {
    return surname + " " + name + " " + middleName;
}
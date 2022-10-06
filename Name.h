#ifndef TEST_NAME_H
#define TEST_NAME_H

#include <string>

using std::string;

struct Name {
    Name();

    Name(string, string, string);

    string getName();

private:
    string name;
    string surname;
    string middleName;
};


#endif //TEST_NAME_H

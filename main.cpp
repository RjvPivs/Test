#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "Date.h"
#include "Name.h"
#include "Event.h"
#include "Birthday.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::thread;
// Vector for birthdays.
vector<Birthday> bd;
// Vector for events.
vector<Event> ev;

// String splitter.
vector<string> separate(string s, char del) {
    std::stringstream ss(s);
    string word;
    vector<string> temp;
    while (!ss.eof()) {
        std::getline(ss, word, del);
        temp.push_back(word);
    }
    return temp;
}

// Interface for adding new events.
void interfaceAdd() {
    cout << "Please, enter the type of event:\n1. Birthday\n2. Event\n";
    int checker;
    cin >> checker;
    while (checker != 1 && checker != 2) {
        cout << "Please, re-enter the type:\n";
        cin >> checker;
    }
    // Adds a birthday.
    if (checker == 1) {
        cout << "Please, enter the name, the date and the age:\nName:  ";
        string name, surname, middleName, date;
        int age;
        cin >> surname >> name >> middleName;
        cout << "\nDate: ";
        cin >> date;
        cout << "\nAge: ";
        cin >> age;
        auto a = separate(date, '.');
        Birthday b(Name(surname, name, middleName), Date(std::stoi(a[0]), std::stoi(a[1]), std::stoi(a[2]), 0, 0), age);
        if (std::find(bd.begin(), bd.end(), b) == bd.end()) {
            bd.push_back(b);
        } else {
            cout << "This person has been already added!\n";
        }
        // Adds an event.
    } else {
        cout << "Please, enter the expiration date and the description:\nExpiration date: ";
        string date, time, description;
        cin >> date;
        cout << "\nTime: ";
        cin >> time;
        cout << "\nDescription:\n";
        getline(cin, description);
        getline(cin, description);
        auto a = separate(date, '.');
        auto b = separate(time, ':');
        Event e(Date(std::stoi(a[0]), std::stoi(a[1]), std::stoi(a[2]), std::stoi(b[0]), std::stoi(b[1])), description);
        ev.push_back(e);
    }
}

// Prints birthdays by name.
void printNames() {
    std::sort(bd.begin(), bd.end());
    cout << "\nPlease, enter the name: ";
    string name;
    getline(cin, name);
    getline(cin, name);
    for (auto i: bd) {
        if (i.getName() == name) {
            cout << "Name: " << i.getName() << "; Date: " << i.getDate() << "; Age:" << i.getAge() << "\n";
        }
    }
}

// Prints events by date of creation or expiration.
void printDates(bool check) {
    std::sort(bd.begin(), bd.end());
    std::sort(ev.begin(), ev.end());
    cout << "Please, enter the date: ";
    string date;
    cin >> date;
    if (check) {
        cout << "\nBirthdays:\n";
    }
    for (auto i: bd) {
        if (separate(i.getDate(), ' ')[0] == date) {
            cout << "Name: " << i.getName() << "; Date: " << i.getDate() << "; Age:" << i.getAge() << "\n";
        }
    }
    cout << "Events:\n";
    for (auto i: ev) {
        if (!check) {
            if (separate(i.getCreated(), ' ')[0] == date) {
                cout << "Description: " << i.getDescription() << "; Date: " << i.getCreated() << "\n";
            }
        } else {
            if (separate(i.getExpires(), ' ')[0] == date) {
                cout << "Description: " << i.getDescription() << "; Date: " << i.getExpires() << "\n";
            }
        }
    }
}

// Prints events which are going to be expired today.
void printToday() {
    std::sort(ev.begin(), ev.end());
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string temp;
    if (ltm->tm_mday < 10) {
        temp += "0";
    }
    temp += std::to_string(ltm->tm_mday) + ".";;
    if (ltm->tm_mon + 1 < 10) {
        temp += "0";
    }
    temp += std::to_string(ltm->tm_mon + 1) + "." + std::to_string(1900 + ltm->tm_year);
    cout << "\nEvents:\n";
    for (auto i: ev) {
        if (separate(i.getExpires(), ' ')[0] == temp) {
            cout << "Description: " << i.getDescription() << "; Date: " << i.getExpires() << "\n";
        }
    }
}

// Writes the data to a text file.
void writeDown() {
    std::ofstream out;
    out.open("../out.txt");
    if (out.is_open()) {
        out << "Birthdays:\n";
        for (auto i: bd) {

            out << "Name: " << i.getName() << "; Date: " << i.getDate() << "; Age:" << i.getAge() << "\n";

        }
        out << "Events:\n";
        for (auto i: ev) {
            out << "Description: " << i.getDescription() << "; Date: " << i.getExpires() << "\n";
        }
    }
    out.close();
    cout << "The info was written down to a out.txt file\n";
}

// Prints all the data.
void printAll() {
    std::sort(bd.begin(), bd.end());
    std::sort(ev.begin(), ev.end());
    cout << "Birthdays:\n";
    for (auto i: bd) {

        cout << "Name: " << i.getName() << "; Date: " << i.getDate() << "; Age:" << i.getAge() << "\n";

    }
    cout << "Events:\n";
    for (auto i: ev) {
        cout << "Description: " << i.getDescription() << "; Date: " << i.getExpires() << "\n";
    }
}

// Action interface module.
void interfaceShow() {
    cout << "Please, choose the option:\n";
    cout << "1. Print events by names.\n";
    cout << "2. Print events by date of expiration.\n";
    cout << "3. Print events by date of creation.\n";
    cout << "4. Print events which expire today.\n";
    cout << "5. Print to txt.\n";
    cout << "6. Print all events.\n";
    int checker;
    cin >> checker;
    while (checker < 1 || checker > 6) {
        cout << "Please, re-enter the type:\n";
        cin >> checker;
    }
    switch (checker) {
        case 1:
            printNames();
            break;
        case 2:
            printDates(true);
            break;
        case 3:
            printDates(false);
            break;
        case 4:
            printToday();
            break;
        case 5:
            writeDown();
            break;
        case 6:
            printAll();
            break;
        default:
            break;
    }
}

// Stop flag for the threads.
bool stop = true;

// Thread method for birthday updating.
void runDate() {
    while (stop) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string temp;
        if (ltm->tm_mday < 10) {
            temp += "0";
        }
        temp += std::to_string(ltm->tm_mday) + ".";;
        if (ltm->tm_mon + 1 < 10) {
            temp += "0";
        }
        temp += std::to_string(ltm->tm_mon + 1) + "." + std::to_string(1900 + ltm->tm_year);
        for (auto &i: bd) {
            if (separate(i.getDate(), ' ')[0] == temp && !i.was) {
                i.incrementAge();
                i.was = true;
                cout << "Happy birthday " << i.getName() << "!\n";
            } else if (separate(i.getDate(), ' ')[0] != temp) {
                i.was = false;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

// Thread method for events deleting.
void runExpireToday() {
    while (stop) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        string temp;
        if (ltm->tm_mday - 1 < 10) {
            temp += "0";
        }
        temp += std::to_string(ltm->tm_mday - 1) + ".";;
        if (ltm->tm_mon + 1 < 10) {
            temp += "0";
        }
        int e = -1;
        temp += std::to_string(ltm->tm_mon + 1) + "." + std::to_string(1900 + ltm->tm_year);
        for (int i = 0; i < ev.size(); ++i) {
            if (separate(ev[i].getExpires(), ' ')[0] == temp) {
                e = i;
            }
        }
        if (e != -1) {
            cout << "The event was deleted!\n";
            ev.erase(ev.begin() + e);
        }
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

int main() {
    thread t1(runDate);
    thread t2(runExpireToday);
    cout << "Welcome to our console event handler!\n";
    int checker = -1;
    while (checker != 3) {
        cout << "Please, choose an option:\n" << "1. Add a new event.\n" << "2. Work with the current list of events.\n"
             << "3. Exit\n";
        cin >> checker;
        switch (checker) {
            case 1:
                interfaceAdd();
                break;
            case 2:
                interfaceShow();
                break;
            case 3:
                stop = false;
                break;
            default:
                cout << "The input data was incorrect. Please, try again.\n";
                break;
        }
    }
    t1.join();
    t2.join();
    cout << "Thank you for using this application! We`re looking forward to see you again!\n";
    return 0;
}

#ifndef TEST_EVENT_H
#define TEST_EVENT_H

#include "Date.h"

struct Event {
    Event(Date, string);

    Event();

    string getCreated();

    string getExpires();

    string getDescription();

    bool operator<(Event);

    bool operator>(Event);

    bool operator==(Event);

private:
    Date created;
    Date expires;
    string description;

};


#endif //TEST_EVENT_H

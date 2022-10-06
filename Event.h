#ifndef TEST_EVENT_H
#define TEST_EVENT_H

#include "Date.h"

struct Event {
    Event(Date, string);

    Event();

    // Returns the date of creation as string.
    string getCreated();

    // Returns the date of expiration as string.
    string getExpires();

    // Returns the description.
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

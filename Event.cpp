#include "Event.h"

Event::Event(Date expires, string description) {
    this->expires = expires;
    this->description = description;
    created = Date();
}

Event::Event() {

}

string Event::getCreated() {
    return created.getDate();
}
string Event::getExpires() {
    return expires.getDate();
}

string Event::getDescription() {
    return description;
}

bool Event::operator<(Event e1) {
    return expires < e1.expires;
}
bool Event::operator>(Event e1) {
    return expires > e1.expires;
}
bool Event::operator==(Event e1) {
    if (getExpires() == e1.getExpires() || getCreated() == e1.getCreated()) {
        return true;
    } else {
        return false;
    }
}
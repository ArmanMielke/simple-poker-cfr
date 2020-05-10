#include "information_set.h"


std::string InformationSet::str() const {
    std::string output = "Hand: " + std::to_string(hand) + ", History: ";

    for (Action action : history) {
        switch (action) {
            case PASS:
                output += "pass, ";
                break;
            case BET:
                output += "bet, ";
                break;
        }
    }

    return output;
}

bool operator == (const InformationSet& i1, const InformationSet& i2) {
    return i1.hand == i2.hand && i1.history == i2.history;
}

bool operator < (const InformationSet& i1, const InformationSet& i2) {
    if (i1.hand != i2.hand) {
        return i1.hand < i2.hand;
    } else {
        return i1.history < i2.history;
    }
}

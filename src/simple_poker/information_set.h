#ifndef PYKER_INFORMATION_SET_H
#define PYKER_INFORMATION_SET_H


#include "constants.h"


struct InformationSet {
public:
    Card hand;
    Card community_card;
    History history;

    [[nodiscard]] std::string str() const;
};

bool operator == (const InformationSet& i1, const InformationSet& i2);
bool operator < (const InformationSet& i1, const InformationSet& i2);


#endif //PYKER_INFORMATION_SET_H

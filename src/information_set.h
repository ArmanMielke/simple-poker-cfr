#ifndef SIMPLE_POKER_CFR_INFORMATION_SET_H
#define SIMPLE_POKER_CFR_INFORMATION_SET_H


#include "action.h"
#include "deck.h"


struct InformationSet {
public:
    Card hand;
    Card community_card;
    History history;

    [[nodiscard]] std::string str() const;
};

bool operator == (const InformationSet& i1, const InformationSet& i2);
bool operator < (const InformationSet& i1, const InformationSet& i2);


#endif //SIMPLE_POKER_CFR_INFORMATION_SET_H

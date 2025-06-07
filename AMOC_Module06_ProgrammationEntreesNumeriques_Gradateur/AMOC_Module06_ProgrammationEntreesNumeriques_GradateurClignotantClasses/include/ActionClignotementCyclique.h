// ActionClignotementCyclique.h
#ifndef ACTION_CLIGNOTEMENT_CYCLIQUE_H
#define ACTION_CLIGNOTEMENT_CYCLIQUE_H

#include "Action.h"
#include "DEL.h"

class ActionClignotementCyclique : public Action {
private:
    DEL* del;
    int modeActuel;  // 0=éteint, 1=25%, 2=50%, 3=75%, 4=100%

public:
    ActionClignotementCyclique(DEL* del);
    void Executer() override;
    int getModeActuel() const;
};

#endif

#pragma once
#include "Action.h"  // Inclure la classe mère
#include "DEL.h"

class ActionAlerte : public Action {  // Héritage public
    private:
DEL m_rouge;
DEL m_jaune;
DEL m_verte;

public:
    ActionAlerte();
    ~ActionAlerte() override;
    void Executer() override;  // Override explicite
};

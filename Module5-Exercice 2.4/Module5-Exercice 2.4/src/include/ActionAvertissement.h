#pragma once
#include "Action.h"  // Inclure la classe mère
#include "DEL.h"

class ActionAvertissement : public Action
{
        private:
        DEL* m_rouge;
        DEL* m_jaune;
        DEL* m_verte;
public:
    ActionAvertissement(/* args */);
    ~ActionAvertissement()override;
    void Executer() override;  // Override explicite
};



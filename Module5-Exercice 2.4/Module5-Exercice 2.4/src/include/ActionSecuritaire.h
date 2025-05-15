#pragma once
#include "Action.h"  // Inclure la classe mère
#include "DEL.h"
class ActionSecuritaire : public Action
{
private:
DEL* m_rouge;
DEL* m_jaune;
DEL* m_verte;

public:
    ActionSecuritaire(DEL* delRouge, DEL* delJaune, DEL* delVerte);
    ~ActionSecuritaire();
    void Executer() override;  // Override explicite
};


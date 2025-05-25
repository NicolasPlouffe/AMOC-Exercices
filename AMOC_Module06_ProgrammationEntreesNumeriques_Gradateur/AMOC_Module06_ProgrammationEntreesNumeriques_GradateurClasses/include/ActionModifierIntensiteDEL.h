#pragma once
#include "Action.h"  // Inclure la classe mère
#include "DEL.h"

class ActionModifierIntensiteDEL : public Action  {

public:
    ActionModifierIntensiteDEL(DEL* p_del);
    ~ActionModifierIntensiteDEL();
    void Executer() override;

private:
    DEL* m_del;
    float m_pourcentageIntensite;
    float m_pasIntensite;
};





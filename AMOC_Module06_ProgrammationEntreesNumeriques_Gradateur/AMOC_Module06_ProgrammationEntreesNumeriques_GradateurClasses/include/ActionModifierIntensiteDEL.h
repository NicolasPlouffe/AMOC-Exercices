#pragma once

// ActionModifierIntensiteDEL.h
#ifndef ACTION_MODIFIER_INTENSITE_DEL_H
#define ACTION_MODIFIER_INTENSITE_DEL_H

#include "Action.h"
#include "DEL.h"

class ActionModifierIntensiteDEL : public Action {
private:
    DEL* del;

public:
    ActionModifierIntensiteDEL(DEL* del);
    void Executer() override;
};

#endif

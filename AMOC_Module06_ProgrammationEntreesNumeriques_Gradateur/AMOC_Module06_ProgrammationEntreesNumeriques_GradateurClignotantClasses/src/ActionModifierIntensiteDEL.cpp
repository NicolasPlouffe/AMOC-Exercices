// ActionModifierIntensiteDEL.cpp
#include "../include/ActionModifierIntensiteDEL.h"

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL* del) : del(del) {}

void ActionModifierIntensiteDEL::Executer() {
    if (del != nullptr) {
        del->basculer();
    }
}

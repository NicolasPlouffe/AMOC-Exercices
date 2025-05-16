//
// Created by nico on 5/15/25.
//
#include <Arduino.h>
#include "../include/ActionModifierIntensiteDEL.h"

ActionModifierIntensiteDEL::ActionModifierIntensiteDEL(DEL *p_del) {
    this->m_del = p_del;
}

void ActionModifierIntensiteDEL::Executer() {
    if (this->m_del->getEtat == LOW) {
        this->m_del->setEtat(HIGH);
        this->m_del->allumer();
    } else {
        this->m_del->setEtat(LOW);
        this->m_del->eteindre();
    }
}

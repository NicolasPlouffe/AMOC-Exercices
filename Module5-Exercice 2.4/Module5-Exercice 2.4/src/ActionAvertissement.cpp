#include <Arduino.h>
#include <include/ActionAvertissement.h>


ActionAvertissement::~ActionAvertissement(){
    ;
}

void ActionAvertissement::Executer() {
    m_rouge->Eteindre();
    m_jaune->Allumer();
    m_verte->Eteindre();
}
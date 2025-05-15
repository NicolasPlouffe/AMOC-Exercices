#include <Arduino.h>
#include <include/ActionAvertissement.h>

ActionAvertissement::ActionAvertissement(DEL* delRouge, DEL* delJaune, DEL* delVerte){
    this->m_rouge = delRouge;
    this->m_jaune = delJaune;
    this->m_verte = delVerte;
}

ActionAvertissement::~ActionAvertissement(){
    ;
}

void ActionAvertissement::Executer() {
    m_rouge->Eteindre();
    m_jaune->Allumer();
    m_verte->Eteindre();
}
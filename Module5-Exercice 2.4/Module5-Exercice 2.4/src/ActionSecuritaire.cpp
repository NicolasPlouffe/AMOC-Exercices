#include <Arduino.h>
#include <include/ActionSecuritaire.h>

ActionSecuritaire::~ActionSecuritaire(){
    ;
}

void ActionSecuritaire::Executer(){
    m_rouge->Eteindre();
    m_jaune->Eteindre();
    m_verte->Allumer();
}
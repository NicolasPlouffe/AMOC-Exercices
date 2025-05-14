#include <Arduino.h>
#include <include/ActionSecuritaire.h>

ActionSecuritaire::ActionSecuritaire(DEL* delRouge, DEL* delJaune, DEL* delVerte){
    this->m_rouge = delRouge;
    this->m_jaune = delJaune;
    this->m_verte = delVerte;
}

ActionSecuritaire::~ActionSecuritaire(){
    ;
}

void ActionSecuritaire::Executer(){
    m_rouge->Eteindre();
    m_jaune->Eteindre();
    m_verte->Allumer();
}
#include <Arduino.h>
#include <include/ActionAlerte.h>


ActionAlerte::ActionAlerte(DEL* delRouge, DEL* delJaune, DEL* delVerte){
  this->m_rouge = delRouge;
  this->m_jaune = delJaune;
  this->m_verte = delVerte;
}

ActionAlerte::~ActionAlerte(){
    ;
}

  void ActionAlerte::Executer() {
    m_rouge->Allumer();
    m_jaune->Eteindre();
    m_verte->Eteindre();
}



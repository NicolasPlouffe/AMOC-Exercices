#include <Arduino.h>
#include <include/ActionAlerte.h>


ActionAlerte::ActionAlerte(){
  ;
}

ActionAlerte::~ActionAlerte(){
    ;
}

  void ActionAlerte::Executer() {
    m_rouge->Allumer();
    m_jaune->Eteindre();
    m_verte->Eteindre();
}



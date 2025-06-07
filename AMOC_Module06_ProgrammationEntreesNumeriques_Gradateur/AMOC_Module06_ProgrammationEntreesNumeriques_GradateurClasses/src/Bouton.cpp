// Bouton.cpp
#include "Bouton.h"

Bouton::Bouton(uint8_t p_pin, unsigned long p_delaiAntiRebond)
    : m_pin(p_pin),
      m_dernierEtat(HIGH),
      m_dernierEtatStable(HIGH),
      m_derniereDateChangement(0),
      m_delaiAntiRebond(p_delaiAntiRebond),
      m_actionAppui(nullptr),
      m_actionRelachement(nullptr) {}

void Bouton::Initialiser() {
    pinMode(m_pin, INPUT);
    m_dernierEtat = digitalRead(m_pin);
    m_dernierEtatStable = m_dernierEtat;
}

void Bouton::MiseAJour() {
    int etatActuel = digitalRead(m_pin);
    unsigned long tempsActuel = millis();
    
    if (etatActuel != m_dernierEtat) {
        m_derniereDateChangement = tempsActuel;
        m_dernierEtat = etatActuel;
    }
    
    if (tempsActuel - m_derniereDateChangement > m_delaiAntiRebond) {
        if (m_dernierEtatStable == HIGH && etatActuel == LOW) {
            // Bouton appuyé
            if (m_actionAppui != nullptr) {
                m_actionAppui->Executer();
            }
        } else if (m_dernierEtatStable == LOW && etatActuel == HIGH) {
            // Bouton relâché
            if (m_actionRelachement != nullptr) {
                m_actionRelachement->Executer();
            }
        }
        m_dernierEtatStable = etatActuel;
    }
}

void Bouton::SetActionAppui(Action* p_action) {
    m_actionAppui = p_action;
}

void Bouton::SetActionRelachement(Action* p_action) {
    m_actionRelachement = p_action;
}

bool Bouton::EstAppuye() const {
    return m_dernierEtatStable == LOW;
}

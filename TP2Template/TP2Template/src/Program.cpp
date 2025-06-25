#include "Program.h"
#include "Affichage4Digits.h"
#include "Affichage4DigitsProxyTM1637.h"
#include "config.h"

Program::Program()  {
    this->m_affichage4Digits = new Affichage4Digits(new Affichage4DigitsProxyTM1637(pinClk, pinData));
    this->m_connectionReseau = new ConnectionReseau();
}

void Program::loop() {

    if (m_connectionReseau->estConnecte())
    {
        m_horloge.MAJ();

        m_affichage4Digits->afficher(

        m_affichage4Digits->segments[m_horloge.getDizaineHeures()],
        m_affichage4Digits->segments[m_horloge.getUniteHeures()] | 0x80,
        m_affichage4Digits->segments[m_horloge.getDizaineMinutes()],
        m_affichage4Digits->segments[m_horloge.getUniteMinutes()]
        );
    } else
    {
        m_affichage4Digits->afficher(0x3F, 0x3F | 0x80, 0x3F, 0x3F);
    }
    delay(500);
}

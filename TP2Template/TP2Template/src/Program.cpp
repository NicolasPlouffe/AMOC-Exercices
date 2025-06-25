#include "Program.h"
#include "Affichage4Digits.h"
#include "Affichage4DigitsProxyTM1637.h"
#include "Chronometre.h"
#include "config.h"

Program::Program()  {
    this->m_affichage4Digits =
        new Affichage4Digits(new Affichage4DigitsProxyTM1637(pinClk, pinData));
this->m_connectionReseau = new ConnectionReseau();
}

Chronometre chronometre = Chronometre();

void Program::loop() {
    chronometre.Tick();

    m_affichage4Digits->afficher(

        m_affichage4Digits->segments[chronometre.getDizaineHeure()],
         m_affichage4Digits->segments[chronometre.getUniteHeure()] | 0x80,
         m_affichage4Digits->segments[chronometre.getDizaineMinute()],
         m_affichage4Digits->segments[chronometre.getUniteMinute()]



        );

}

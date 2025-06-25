#include "Program.h"

#include "Affichage4Digits.h"

#include "Affichage4DigitsProxyTM1637.h"

#include "Chronometre.h"

Program::Program()  {
    this->m_affichage4Digits =
        new Affichage4Digits(new Affichage4DigitsProxyTM1637(2, 3));
}

Chronometre chronometre = Chronometre();

void Program::loop() {
    chronometre.Tick();

    m_affichage4Digits->afficher(

        m_affichage4Digits->segments[chronometre.getDizaineHeure()],
         m_affichage4Digits->segments[chronometre.getUniteHeure()] | 0x80,
         m_affichage4Digits->segments[chronometre.getDizaineMinute()],
         m_affichage4Digits->segments[chronometre.getUniteMinute()]

         /*m_affichage4Digits->segments[(86340 / 3600) / 10],
         m_affichage4Digits->segments[(86340 / 3600) % 10 ] | 0x80,
         m_affichage4Digits->segments[((86340 % 3600)/60) / 10 ],
         m_affichage4Digits->segments[((86340 % 3600)/60) % 10 ]*/

        );

}

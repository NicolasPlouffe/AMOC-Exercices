#include "Program.h"

#include "Affichage4Digits.h"

#include "Affichage4DigitsProxyTM1637.h"

Program::Program()  {
    this->m_affichage4Digits =
        new Affichage4Digits(new Affichage4DigitsProxyTM1637(2, 3));
}

void Program::loop() {
    /*static uint16_t compteur = 0;

    // Afficher alternance compteur/CACA
    if(compteur % 2 == 0) {
        m_affichage4Digits->AfficherEntier(compteur);
    } else {

    }*/
    m_affichage4Digits->afficher(
               Affichage4Digits::segments[12] , // !
               Affichage4Digits::segments[0] , // F
               Affichage4Digits::segments[12] | 0x80 , // 0
               Affichage4Digits::segments[17] | 0x80 // U
           );
    /*compteur++;
    if(compteur > 9999) compteur = 0;*/

    delay(500);
}

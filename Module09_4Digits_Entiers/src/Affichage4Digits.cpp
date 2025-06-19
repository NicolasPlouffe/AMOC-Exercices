#include "Affichage4Digits.h"
const uint8_t Affichage4Digits::segments[18] = {
    0b00111111, // 0 → Segments A,B,C,D,E,F (0x3F)
    0b00000110, // 1 → Segments B,C (0x06)
    0b01011011, // 2 → Segments A,B,G,E,D (0x5B)
    0b01001111, // 3 → Segments A,B,G,C,D (0x4F)
    0b01100110, // 4 → Segments F,G,B,C (0x66)
    0b01101101, // 5 → Segments A,F,G,C,D (0x6D)
    0b01111101, // 6 → Segments A,F,G,C,D,E (0x7D)
    0b00000111, // 7 → Segments A,B,C (0x07)
    0b01111111, // 8 → Tous segments (0x7F)
    0b01101111, // 9 → Segments A,B,C,D,F,G (0x6F)

    // Lettres A-F
    0b01011111, // A → Segments A,B,C,E,F,G (0x5F)
    0b01111100, // B → Segments D,E,F,G,C (0x7C)
    0b00111001, // C → Segments A,D,E,F (0x39)
    0b01011110, // D → Segments B,C,D,E,G (0x5E)
    0b01111001, // E → Segments A,D,E,F,G (0x79)
    0b01110001, // F → Segments A,E,F,G (0x71)

    // Caractères spéciaux
    0b01110011, // P → Segments A,B,E,F,G (0x73)
    0b00111110  // U → Segments B,C,D,E,F (0x3E)
};
Affichage4Digits::Affichage4Digits(Affichage4DigitsProxy* p_proxy){
    this->m_proxy = p_proxy;
}

void Affichage4Digits::afficher(uint8_t p_d1, uint8_t p_d2, uint8_t p_d3,
                                uint8_t p_d4) const {
    this->m_proxy->afficher(p_d1, p_d2, p_d3, p_d4);
}

void Affichage4Digits::afficherBinaire(uint8_t p_valeur) const {
    this->m_proxy->afficher(segments[p_valeur >> 3 & 1],
                            segments[p_valeur >> 2 & 1],
                            segments[p_valeur >> 1 & 1],
                            segments[p_valeur & 1]);
}

void Affichage4Digits::AfficherEntier(uint16_t p_valeur){
    uint16_t valeur = p_valeur;
    uint8_t d4 = valeur % 10;
    valeur /= 10;
    uint8_t d3 = valeur % 10;
    valeur /= 10;
    uint8_t d2 = valeur % 10;
    valeur /= 10;
    uint8_t d1 = valeur % 10;

    this->m_proxy->afficher(segments[d1], segments[d2], segments[d3],
                          segments[d4]);
}



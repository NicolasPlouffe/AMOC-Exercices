
#include "LCD1602.h"

LCD1602::LCD1602(LCD1602Proxy* p_lcdProxy) : m_lcdProxy(p_lcdProxy) {
    this->m_lcdProxy = p_lcdProxy;
}

void LCD1602::definirPositionCurseur(uint8_t colonne, uint8_t ligne) const {
    m_lcdProxy->definirPositionCurseur(colonne, ligne);
}

void LCD1602::afficher(const String& texte) const {
    m_lcdProxy->afficher(texte);
}

void LCD1602::effacer() const {
    m_lcdProxy->effacer();
}
//
// Created by nico on 5/15/25.
//
#include <Arduino.h>
#include "../include/DEL.h"

DEL::DEL(uint8_t p_pinDel) {
    this->m_pinDel = p_pinDel;
    pinMode(this->m_pinDel, OUTPUT);
    this->m_intensite = 0;
    this->m_etat = LOW;
}

uint8_t DEL::getIntensite() {
    return this->m_intensite;
}

uint8_t DEL::getEtat() {
    return this->m_etat;
}

void DEL::setIntensite(uint8_t p_intensite) {
    if (p_intensite > 100) {
        p_intensite = 100;
    }
    this->m_intensite = p_intensite;
    analogWrite(this->m_pinDel, this->m_intensite);
}

void DEL::setEtat(uint8_t p_etat) {
    this->m_etat = p_etat;
    if (this->m_etat == HIGH) {
        this->allumer();
    } else {
        this->eteindre();
    }
}


void DEL::allumer() {
    digitalWrite(this->m_pinDel, HIGH);
}

void DEL::allumer(float p_ourcentage) {
    ;
}

void DEL::eteindre() {
    digitalWrite(this->m_pinDel, LOW);
}
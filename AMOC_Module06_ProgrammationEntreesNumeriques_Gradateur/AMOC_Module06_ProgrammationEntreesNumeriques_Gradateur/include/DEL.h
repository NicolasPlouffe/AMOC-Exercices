#pragma once

#ifndef DEL_H
#define DEL_H
#include <stdint.h>


class DEL {

public:
    DEL(uint8_t p_pinDel);

    void setIntensite(uint8_t p_intensite);
    void setEtat(uint8_t p_etat);

    uint8_t getIntensite();
    uint8_t getEtat();

    void allumer();
    void allumer(float p_ourcentage);
    void eteindre();

private:
    uint8_t m_pinDel;

    uint8_t m_intensite;

    uint8_t m_etat;
};



#endif //DEL_H

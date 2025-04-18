#pragma once

class DEL
{
private:
    int m_pinDEL;

public:
    DEL(const int& p_pinDEL);

    void allumer() const;
    void eteindre() const;
};
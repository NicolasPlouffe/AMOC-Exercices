#include "../include/CapteurAUltrasons.h"


CapteurAUltrasons::CapteurAUltrasons(ICapteurAUltrasons* p_proxy):
    m_proxy(p_proxy)
{
    ;
}

double CapteurAUltrasons::obtenirDistance() {
    return this->m_proxy->obtenirDistance();
}
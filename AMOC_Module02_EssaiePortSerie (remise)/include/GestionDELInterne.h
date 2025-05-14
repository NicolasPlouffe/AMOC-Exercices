#pragma once    
#include "Arduino.h"

class GestionDELInterne {

    public:
        GestionDELInterne();
        void allumerDELInterne(int p_duree);
        void eteindreDELInterne(int p_duree);
    };

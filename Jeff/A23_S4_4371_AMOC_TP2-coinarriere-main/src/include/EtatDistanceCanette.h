#pragma once

/**
 * @brief Etats possibles de distance
 *
 *   "Trop proche"  (de 0 a 4 cm))
 *   "Conforme"     (de 4 a 30 cm)
 *   "Trop loin"    (de 30 a 50 cm)
 *
 */

enum EtatDistanceCanette
{
    ETAT_TROP_PROCHE,
    ETAT_CONFORME,
    ETAT_TROP_LOIN,
    ETAT_EN_ATTENTE_DE_CANETTE
};
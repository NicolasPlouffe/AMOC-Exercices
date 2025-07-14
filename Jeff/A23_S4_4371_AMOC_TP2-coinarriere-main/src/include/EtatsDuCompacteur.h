#pragma once

/**
 * @brief Etats possibles du compacteur
 *
 *   "En opération" (durant une transaction)
 *   "canette non reconnue et rejetée"
 *   "SVP, NE PAS tirer la canette dans le compacteur"
 *   "Impression du reçu de caisse"
 *   <autres>...
 *
 */

enum EtatsDuCompacteur
{
    ETAT_EN_OPERATION,
    ETAT_ENTRETIEN,
    ETAT_CANETTE_NON_RECONNUE_ET_REJETEE,
    ETAT_SVP_NE_PAS_TIRER_LA_CANETTE_DANS_LE_COMPACTEUR,
    ETAT_IMPRESSION_DU_RECU_DE_CAISSE,
    ETAT_CANETTE_BLOQUEE,
    ETAT_AUTRE
};

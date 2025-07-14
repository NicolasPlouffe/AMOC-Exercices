#pragma once

#include <Arduino.h>
#include <WebServer.h>
#include <FS.h>
#include <detail/RequestHandlersImpl.h>
#include "DonneesCompacteur.h"
#include "IDepotDonneesCompacteur.h"

<<<<<<< Updated upstream
=======
//#define FS LittleFS
>>>>>>> Stashed changes
#define SERVEUR_PORT 80

/**
 * @brief Serveur web pour le compacteur
 * @routes:
 * - /api/canettes/compacte -> GET # retourne le nombre de cannettes compactées
 * - /api/canettes/reinitialise -> PUT # réinitialise le nombre de cannettes compactées
 * - /api/compacteur -> GET # Retourne Etat du compacteur
 * - /api/compacteur -> PUT # active ou déactive le compacteur
 * - /api/montant/verse -> GET # retourne le montant versé
 * - /api/montant/restant -> GET # retourne le montant restant à verser
 * - /api/emplacement -> get # retourne l'emplacement du compacteur
 * - /api/emplacement -> put # modifie l'emplacement du compacteur
**/

class ServeurWeb
{
public:
    ServeurWeb() = default;
    explicit ServeurWeb(DonneesCompacteur& donneesCompacteur,
                        IDepotDonneesCompacteur* depotDonneesCompacteur);
    void tick();

private:
    WebServer* m_serveur;
    DonneesCompacteur& m_donneesCompacteur;
    IDepotDonneesCompacteur* m_depotDonneesCompacteur;
    void afficherRacine();
    void ajouterFichiersStatiques(String const& p_debutNomFichier);
    void ajouterFichiersStatiques(String const& p_debutNomFichier,
                                  String const& p_repertoireCourant,
                                  File& p_fichier);
    void ressourceNonTrouvee(String const& p_nomFichier);
};
# TP02 - Compacteur de canettes

## 1 - Directives

### 1.1 - Déroulement du TP

- Remise du travail : dimanche 28 janvier 2024, 23:59
- Ce travail est réalisé en équipe de 2 membres et seuls les membres de cette équipe y contribuent
- Toutes les réponses fournies doivent être originales (produites par l’étudiant ou un membre de l’équipe)
- Toute copie de code, de portion de code, d’algorithme ou de texte doit faire mention de sa source
- L’emprunt ou la copie de code ou de portions de code est interdite
- Tout constat de plagiat, tricherie ou fraude sera automatiquement déclaré à la Direction et les sanctions prévues seront appliquées
- Vous devez utiliser votre dépôt Git pour faire votre travail : si une situation particulière est détectée, vos commits moduleront votre note dans le groupe.
- Vous devez utiliser SharePoint pour gérer votre document de rapport (Onglet "Fichiers" de votre équipe Teams)
- La remise du travail doit être effectuée sur et à la date indiquée sur la plateforme d'enseignement Léa

### 1.2 - À remettre sur la plateforme d'enseignement Léa

- Un document Word contenant le détail du projet
- Votre code source C++ avec la structure de PlatformIO
- Vous devez fournir le lien d'une vidéo de 5 minutes illustrant le circuit, le code et le fonctionnement :
  - La vidéo doit être déposée sur YouTube
  - En lien non listé
  - La vidéo doit être accessible jusqu'à un an après la remise du travail
  - La vidéo doit être en français

### 1.3 - Structure de la remise

- **Vous devez remplir le fichier** `AUTHORS.md`. Il donne le nom et matricule des équipiers
- Votre code source doit être dans le répertoire `src` du présent dépôt Git
- Le répertoire source doit suivre la structure d’un projet PlatformIO
- Le lien de la vidéo doit être présent dans le document word et dans le fichier `AUTHORS.md` de votre dépôt Git
- La vidéo doit être déposée sur YouTube avec une option de partage « non listée »
- Le répertoire "documents" doit contenir votre rapport de TP

### 1.4 - Évaluation

L'évaluation du travail est effectuée par les enseignants de l'UE en se basant sur :

- L'historique de Git et de Teams/Sharepoint font office de référence pour évaluer la proportion du travail effectué par chaque équipier

- La qualité et le contenu du code source :

  - Conformité du code et des normes d'écriture utilisées dans le cours
  - Fonctionnalité du code
  - Facilité de lecture du code
  - Modularité
  - Modèle objet
  - Paramétrisation du code
  - Utilisation de constantes
  - Utilisation de fichiers de configuration
  - etc.

- La qualité et le contenu du document word :
  
  - Français
  - Schéma
  - Clarté et précision des explications
  - Mise en page
  - Page de présentation
  - etc.

- La qualité et le contenu de la présentation vidéo :

  - Vidéo
  - Audio
  - Explication orale
  - etc.

Tout partage de code, d'explication, de bouts de texte, etc. est considéré comme du plagiat. Pour plus de détails, consultez le site (et ses vidéos) [Sois intègre du Cégep de Sainte-Foy](http://csfoy.ca/soisintegre) ainsi que [l'article 6.1.12 de la PÉA](https://www.csfoy.ca/fileadmin/documents/notre_cegep/politiques_et_reglements/5.9_PolitiqueEvaluationApprentissages_2019.pdf)

## 2 - Description du projet

La coopérative ```SauvonsLaPlanete``` fabrique des robot-compacteurs (nommés "compacteurs") pour canettes en aluminium dans le but de les recycler. Ces compacteurs, sont placés dans divers points de vente, comme les épiceries et les centres d’achat.

Deux personnes s'occupent de l'administration d'un compacteur :

- Sur place, un préposé assure le fonctionnement mécanique du compacteur
- À distance, un responsable assure le fonctionnement logique du compacteur

Ce responsable peut aussi effectuer des actions sur le compacteur.

Les compacteurs de la coopérative offrent les fonctionnalités suivantes :

- Valider, compter et compacter les canettes
- Imprimer le reçu de remboursement, à raison de 10 ¢ l’unité (en date de janvier 2024)
- Pour chaque client, afficher le nombre de canettes et le remboursement durant la transaction
- Désactiver/réactiver la machine par un préposé selon divers situations (trop plein ou défectueuse)

Un compacteur aura les systèmes suivants:

- Afficheur numérique à 4 x 7 segments
- Afficheur LCD 32 caractères X 2 lignes
- Détecteur ultra-sonique HC-SR04
- Bouton "fin de transaction" pour le client
- Bouton "activer/désactiver" le compacteur par le préposé

Un compacteur est une structure JSON décrite comme ceci:

- Numéro unique
- Adresse de l’emplacement
- État (voir la liste plus loin)
- Nombre total de canettes récupérées
- (Autres données au besoin)

L’afficheur LCD indique divers états du compacteur durant la journée. Parmi les choix, vous proposez :

- "En opération" (durant une transaction)
- "canette non reconnue et rejetée"
- "SVP, NE PAS tirer la canette dans le compacteur"
- "Impression du reçu de caisse"
- (Autres statuts)

### 2.1 - Démarrage du programme

Au démarrage, le système lit le fichier json. L’afficheur LCD indique l'état du compacteur selon le dernier état connu avant le démarrage du programme. L’afficheur numérique indique le nombre total de canettes et le remboursement total avant la dernière remise à zéro. Les deux données sont affichées en alternance à toutes les secondes. 

### 2.2 - Déroulement d’une transaction

Lorsqu’un client se présente devant le compacteur, il passe la première canette devant le détecteur ultra-sonique qui "lit" la canette. Une lecture valide doit se située entre 4 cm et 30 cm, sinon la canette est rejetée. Par mesure de sécurité, un délai d’une seconde doit être respecté entre deux lectures successives, sinon le message "SVP, NE PAS tirer la canette dans le compacteur "; la canette est aussi rejetée!

Pendant le déroulement normal, l’afficheur LCD indique "en opération". L’afficheur numérique indique le nombre de canettes passées par le client et le montant du remboursement à venir; les deux données sont affichées en alternance à toutes les secondes. 

Le client passe les autres canettes dans le compacteur. À la fin, il appuie sur le bouton "» "fin de transaction" pour obtenir son reçu de remboursement et rendre le compacteur disponible pour le prochain client.

### 2.3 - Gestion d’un compacteur

Pour gérer à distance son compacteur, votre système doit se servir d’un serveur web en mode client. À l’aide de son téléphone cellulaire, le responsable du compacteur peut :

- Consulter/remettre à zéro le nombre de canettes compactées
- Activer/désactiver le compacteur (même effet que le bouton "activer/désactiver" du préposé)
- Consulter le total de canettes récupérées
- Consulter le montant total reçu par les clients
- Modifier l’adresse d’emplacement du compacteur lors d’un déplacement

Proposez une interface confortable.

### 2.4 - Innovation : bonus 10% (optionnel)

Proposez et mettre en place une évolution originale au projet actuel en ajoutant des fonctions. Le code et la vidéo seront évalués pour l’originalité, le niveau de difficulté et le résultat obtenu. Un bonus pouvant aller jusqu’à 10% sera attribué.

## 4 - Répartition des points

1. Document word (25%)

- Contexte du projet (5%)
- Planification, attribution des tâches (5%)
- Description des étapes du projet (5%)
- Diagramme de classes (5%)
- Schéma du montage (5%)

2. Registre des heures consacrées au projet (5%)

Le registre doit indiquer la répartition des tâches. Le registre doit montrer les tâches respectives que chaque personne aura fait avec le nombre d’heures par tâche.

Il doit correspondre aux données collectées dans l'historique de Git et de Teams/Sharepoint de l'équipe.

3. Vidéo de 5 minutes illustrant le fonctionnement (15%)

- Présentation rapide du circuit (5%)
- Présentation rapide de la structure du code et des choix de conception (5%)
- Présentation du fonctionnement (5%)

4. Code (55%)

- Démarrage/fin du programme avec sauvegarde des données (5%)
- Gestion des canettes acceptées ou rejetées (5%)
- Gestion du fichier JSON pour respecter les mises à jour (5%)
- Affichage alternée sur l’afficheur numérique (5%) (à deux endroits)
- Affichages des états d’une transaction qui respectent les opérations en cours (5%)
- Les 5 fonctions de la gestion web du compacteur (10%)
- Respect des bonnes pratiques de programmation modulaire et orientée objet (20%)

5. Bonus: mise en oeuvre d'une fonction supplémentaire originale (10%)

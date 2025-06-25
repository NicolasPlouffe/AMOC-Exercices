Voici les ressources de référence essentielles pour comprendre la configuration NTP et des fuseaux horaires sur ESP32 :

### 1. Documentation officielle Espressif (ESP-IDF)
- [System Time - ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/system_time.html)  
  Explications techniques sur `configTime()`, `setenv()`, `tzset()` et la gestion du temps.

### 2. Référence Arduino-ESP32
- [Time Library Examples](https://github.com/espressif/arduino-esp32/tree/master/libraries/ESP32/examples/Time)  
  Contient des exemples concrets d'utilisation avec NTP et fuseaux horaires.

### 3. Format des fuseaux horaires POSIX
- [tzset man page (Linux)](https://linux.die.net/man/3/tzset)  
  Documentation complète sur le format des chaînes de fuseaux horaires comme `"EST5EDT,M3.2.0/2,M11.1.0/2"`.

### 4. Base de données des fuseaux horaires
- [IANA Time Zone Database](https://www.iana.org/time-zones)  
  Source officielle des définitions de fuseaux horaires (utilisée par Linux/macOS).

### 5. Explication détaillée du format
Pour la chaîne `"EST5EDT,M3.2.0/2,M11.1.0/2"` :
- `EST5` : Heure standard (EST) avec décalage UTC-5
- `EDT` : Heure avancée (EDT) avec décalage UTC-4 (implicite)
- `M3.2.0/2` : Début heure d'été (2ème dimanche de mars à 2h)
- `M11.1.0/2` : Fin heure d'été (1er dimanche de novembre à 2h)

### 6. Tutoriel pratique
- [ESP32 NTP Client Guide](https://randomnerdtutorials.com/esp32-date-time-ntp-client-server-arduino/)  
  Tutoriel étape-par-étape avec gestion des fuseaux horaires.

### Votre code corrigé
```cpp
// ConnectionReseau.cpp
#include "../include/ConnectionReseau.h"

ConnectionReseau::ConnectionReseau() {
    // ... connexion WiFi ...

    // Configuration NTP
    configTime(0, 0, "pool.ntp.org", "time.nist.gov"); // UTC sans décalage
    
    #define TIMEZONECANADAEST "EST5EDT,M3.2.0/2,M11.1.0/2"
    setenv("TZ", TIMEZONECANADAEST, 1);
    tzset(); // Applique le nouveau fuseau
}
```

### Points clés à retenir :
1. `configTime(0, 0, ...)` initialise avec UTC+0
2. `setenv()` définit le fuseau horaire selon le standard POSIX
3. `tzset()` applique immédiatement le nouveau fuseau
4. Le format `M3.2.0/2` signifie :
   - M3 : Mars
   - .2 : 2ème semaine
   - .0 : Dimanche (0=dimanche)
   - /2 : À 2h du matin

Pour d'autres fuseaux horaires, consultez la [liste complète des timezones POSIX](https://en.wikipedia.org/wiki/List_of_tz_database_time_zones).

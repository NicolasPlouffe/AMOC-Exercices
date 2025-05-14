# include <Arduino.h>
# include <MorseSerie.h>

MorseSerie::MorseSerie(int p_dureePoint)
: Morse(p_dureePoint)
{
}

void MorseSerie::afficherPoint()const
{
    Serial.print(".");
    // delay(getDureePoint());
}

void MorseSerie::afficherTrait()const
{
    Serial.print("_");
    // delay(getDureeTrait());
}
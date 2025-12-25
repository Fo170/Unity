// valeurs_SI.h - Librairie d'unités scientifiques pour l'électronique et l'électricité
// Version: 1.0.0
// Auteur: [FOURNET Olivier]
// Licence: GPL-3.0 license
// Description: Fournit des fonctions pour formater des valeurs physiques avec des unités 
//              appropriées en utilisant les préfixes SI (k, M, G, m, µ, n, p, etc.)

#ifndef VALEURS_SI_H
#define VALEURS_SI_H

#include <Arduino.h>
#include <math.h>

#include "Unity.h"

// ============================================================================
// CLASSES AVEC MÉTHODES SPÉCIFIQUES (DÉFINIES MANUELLEMENT)
// ============================================================================
//  --- Grandeurs Électriques et Magnétiques ---

// Résistance électrique (Ohm)
// Classe Resistance avec méthodes supplémentaires
class Resistance : public C_UNITY {
public:
    Resistance() : C_UNITY() {}
    Resistance(float ohms) : C_UNITY(ohms) {}
    
    // Constructeur de copie
    Resistance(const Resistance& other) : C_UNITY(other) {}
    
    // Opérateur d'affectation
    Resistance& operator=(float ohms) {
        valeur = ohms;
        return *this;
    }
    
    Resistance& operator=(const Resistance& other) {
        if (this != &other) {
            valeur = other.valeur;
        }
        return *this;
    }

    // Affichage
    String afficher(int nbDecimal = 3) const {
        return valeurAvecUnite("Ω", nbDecimal);
    }
    
    static String afficher(float ohms, int nbDecimal = 3) {
        return C_UNITY::valeurAvecUnite(ohms, "Ω", nbDecimal);
    }

    // Opérateurs d'affectation composés
    Resistance& operator+=(const Resistance& other) {
        valeur += other.valeur;
        return *this;
    }
    
    Resistance& operator-=(const Resistance& other) {
        valeur -= other.valeur;
        return *this;
    }
    
    Resistance& operator*=(float scalar) {
        valeur *= scalar;
        return *this;
    }
    
    Resistance& operator/=(float scalar) {
        if (scalar != 0.0) {
            valeur /= scalar;  
            return *this;
        }
    }
    
    // Opérateurs arithmétiques
    Resistance operator+(const Resistance& other) const {
        return Resistance(valeur + other.valeur);
    }
    
    Resistance operator-(const Resistance& other) const {
        return Resistance(valeur - other.valeur);
    }
    
    Resistance operator*(float scalar) const {
        return Resistance(valeur * scalar);
    }
    
    Resistance operator/(float scalar) const {
        if (scalar != 0.0) return Resistance(valeur / scalar); // Évite la division par zéro
        else return NAN;
    }

    // Comparaisons
    bool operator==(const Resistance& other) const {
        return valeur == other.valeur;
    }
    
    bool operator!=(const Resistance& other) const {
        return valeur != other.valeur;
    }
    
    bool operator<(const Resistance& other) const {
        return valeur < other.valeur;
    }
    
    bool operator>(const Resistance& other) const {
        return valeur > other.valeur;
    }
    
    // Conversion
    operator float() const { return valeur; }

    // Méthodes statiques supplémentaires
    static float calculerResistanceSerie(float r1, float r2) {
        return r1 + r2;
    }
    
    static float calculerResistanceParallele(float r1, float r2) {
        if (r1 == 0 || r2 == 0) return 0;
        return (r1 * r2) / (r1 + r2);
    }
    
    static float calculerResistanceSerie(float resistances[], int count) {
        float total = 0;
        for (int i = 0; i < count; i++) {
            total += resistances[i];
        }
        return total;
    }
    
    static float calculerResistanceParallele(float resistances[], int count) {
        float inverseTotal = 0;
        for (int i = 0; i < count; i++) {
            if (resistances[i] != 0) {
                inverseTotal += 1.0 / resistances[i];
            }
        }
        return inverseTotal != 0 ? 1.0 / inverseTotal : 0;
    }
};

// Capacité électrique (Farad)
// Classe Capacite avec méthodes supplémentaires
class Capacite : public C_UNITY {
public:
    Capacite() : C_UNITY() {}
    Capacite(float farads) : C_UNITY(farads) {}

    // Constructeur de copie
    Capacite(const Capacite& other) : C_UNITY(other) {}
    
    // Opérateur d'affectation
    Capacite& operator=(float farads) {
        valeur = farads;
        return *this;
    }
    
    Capacite& operator=(const Capacite& other) {
        if (this != &other) valeur = other.valeur;
        return *this;
    }
    
    // Affichage
    String afficher(int nbDecimal = 3) const {
        return valeurAvecUnite("F", nbDecimal);
    }
    
    static String afficher(float farads, int nbDecimal = 3) {
        return C_UNITY::valeurAvecUnite(farads, "F", nbDecimal);
    }
    
    // Opérateurs d'affectation composés
    Capacite& operator+=(const Capacite& other) {
        valeur += other.valeur;
        return *this;
    }
    
    Capacite& operator-=(const Capacite& other) {
        valeur -= other.valeur;
        return *this;
    }
    
    Capacite& operator*=(float scalar) {
        valeur *= scalar;
        return *this;
    }
    
    Capacite& operator/=(float scalar) {
        if (scalar != 0.0) {
            valeur /= scalar;
            return *this; // Évite la division par zéro
        }
    }

    // Comparaisons
    bool operator==(const Capacite& other) const {
        return valeur == other.valeur;
    }
    
    bool operator!=(const Capacite& other) const {
        return valeur != other.valeur;
    }
    
    bool operator<(const Capacite& other) const {
        return valeur < other.valeur;
    }
    
    bool operator>(const Capacite& other) const {
        return valeur > other.valeur;
    }

    // Conversion
    operator float() const { return valeur; }

    // Opérateurs arithmétiques
    Capacite operator+(const Capacite& other) const {
        return Capacite(valeur + other.valeur);
    }
    
    Capacite operator-(const Capacite& other) const {
        return Capacite(valeur - other.valeur);
    }
    
    Capacite operator*(float scalar) const {
        return Capacite(valeur * scalar);
    }
    
    Capacite operator/(float scalar) const {
        if (scalar != 0.0) return Capacite(valeur / scalar); // Évite la division par zéro
        else return NAN; 
    }
    
    // Méthodes statiques supplémentaires
    static float calculerCapaciteSerie(float c1, float c2) {
        if (c1 == 0 || c2 == 0) return 0;
        return (c1 * c2) / (c1 + c2);
    }
    
    static float calculerCapaciteParallele(float c1, float c2) {
        return c1 + c2;
    }
    
    static float calculerCapaciteSerie(float capacites[], int count) {
        float inverseTotal = 0;
        for (int i = 0; i < count; i++) {
            if (capacites[i] != 0) {
                inverseTotal += 1.0 / capacites[i];
            }
        }
        return inverseTotal != 0 ? 1.0 / inverseTotal : 0;
    }
    
    static float calculerCapaciteParallele(float capacites[], int count) {
        float total = 0;
        for (int i = 0; i < count; i++) {
            total += capacites[i];
        }
        return total;
    }
};
// Inductance (Henry)
// Classe Inductance avec méthodes supplémentaires
class Inductance : public C_UNITY {
public:
    Inductance() : C_UNITY() {}
    Inductance(float henrys) : C_UNITY(henrys) {}
    
     // Constructeur de copie
    Inductance(const Inductance& other) : C_UNITY(other) {}
    
    // Opérateur d'affectation
    Inductance& operator=(float henrys) {
        valeur = henrys;
        return *this;
    }
    
    Inductance& operator=(const Inductance& other) {
        if (this != &other) {
            valeur = other.valeur;
        }
        return *this;
    }
     // Affichage
    String afficher(int nbDecimal = 3) const {
        return valeurAvecUnite("H", nbDecimal);
    }

    static String afficher(float henrys, int nbDecimal = 3) {
        return C_UNITY::valeurAvecUnite(henrys, "H", nbDecimal);
    }
    
    // Opérateurs d'affectation composés
    Inductance& operator+=(const Inductance& other) {
        valeur += other.valeur;
        return *this;
    }
    
    Inductance& operator-=(const Inductance& other) {
        valeur -= other.valeur;
        return *this;
    }
    
    Inductance& operator*=(float scalar) {
        valeur *= scalar;
        return *this;
    }
    
    Inductance& operator/=(float scalar) {
        if (scalar != 0.0) {
            valeur /= scalar;
            return *this; // Évite la division par zéro
        }
    }

    // Comparaisons
    bool operator==(const Inductance& other) const {
        return valeur == other.valeur;
    }
    
    bool operator!=(const Inductance& other) const {
        return valeur != other.valeur;
    }
    
    bool operator<(const Inductance& other) const {
        return valeur < other.valeur;
    }
    
    bool operator>(const Inductance& other) const {
        return valeur > other.valeur;
    }

    // Conversion
    operator float() const { return valeur; }
    
    // Opérateurs arithmétiques
    Inductance operator+(const Inductance& other) const {
        return Inductance(valeur + other.valeur);
    }
    
    Inductance operator-(const Inductance& other) const {
        return Inductance(valeur - other.valeur);
    }

    Inductance operator*(float scalar) const {
        return Inductance(valeur * scalar);
    }

    Inductance operator/(float scalar) const {
        if (scalar != 0.0) return Inductance(valeur / scalar); // Évite la division par zéro
        else return NAN;
    }
    
    // Méthodes statiques supplémentaires
    static float calculerInductanceSerie(float l1, float l2) {
        return l1 + l2;
    }

    static float calculerInductanceParallele(float l1, float l2) {
        if (l1 == 0 || l2 == 0) return 0;
        return (l1 * l2) / (l1 + l2);
    }
    
    static float calculerInductanceParallele(float inductances[], int count) {
        float inverseTotal = 0;
        for (int i = 0; i < count; i++) {
            if (inductances[i] != 0) {
                inverseTotal += 1.0 / inductances[i];
            }
        }
        return inverseTotal != 0 ? 1.0 / inverseTotal : 0;
    }

    static float calculerInductanceSerie(float inductances[], int count) {
        float total = 0;
        for (int i = 0; i < count; i++) {
            total += inductances[i];
        }
        return total;
    }
};

// ============================================================================
// CLASSES SANS UNITÉS C_UNITY (SANS HÉRITAGE DE C_UNITY)
// ============================================================================
#define __Kelvin__  true
#define __Celsius__ false

class Temperature_KC {
private:
    float valeur; // en Kelvin par défaut
    bool enKelvin; // true = Kelvin, false = Celsius

public:
    // Constructeurs
    Temperature_KC() : valeur(0.0), enKelvin(true) {}
    Temperature_KC(float val, bool isKelvin = true) : valeur(val), enKelvin(isKelvin) {}
    
    // Méthodes d'accès
    float getValeur() const { return valeur; }
    bool isKelvin() const { return enKelvin; }
    
    // Opérateur de conversion vers float
    operator float() const {
        return enKelvin ? valeur : valeur + C_UNITY::KELVIN_OFFSET;
    }
    
    // Méthodes d'instance
    String kelvin(int nbDecimal = 2) const {
        return String((float)(*this), nbDecimal) + "°K";
    }
    
    String celsius(int nbDecimal = 2) const {
        return String(enKelvin ? valeur - C_UNITY::KELVIN_OFFSET : valeur, nbDecimal) + "°C";
    }
    
    // Méthodes statiques
    static String kelvin(float kelvin, int nbDecimal = 2) {
        return String(kelvin, nbDecimal) + "°K";
    }
    
    static String celsius(float celsius, int nbDecimal = 2) {
        return String(celsius, nbDecimal) + "°C";
    }
    
    // Conversion entre échelles
    static float celsiusToKelvin(float celsius) {
        return celsius + C_UNITY::KELVIN_OFFSET;
    }
    
    static float kelvinToCelsius(float kelvin) {
        return kelvin - C_UNITY::KELVIN_OFFSET;
    }
    
    static float celsiusToFahrenheit(float celsius) {
        return (celsius * 9.0/5.0) + 32.0;
    }
    
    static float fahrenheitToCelsius(float fahrenheit) {
        return (fahrenheit - 32.0) * 5.0/9.0;
    }
};
//-------------------
// Classe Angle (radians et degrés)
//-------------------
#define __Radians__  true
#define __Degres__   false

class Angle {
private:
    float valeur; // en radians par défaut
    bool enRadians; // true = radians, false = degrés

public:
    Angle() : valeur(0.0), enRadians(true) {}
    Angle(float val, bool isRadians = true) : valeur(val), enRadians(isRadians) {}
    
    // Opérateur de conversion vers float (toujours en radians)
    operator float() const {
        return enRadians ? valeur : valeur * C_UNITY::PI_ / 180.0;
    }
    
    String radian(int nbDecimal = 3) const {
        return String((float)(*this), nbDecimal) + " rad";
    }
    
    String degre(int nbDecimal = 3) const {
        return String(enRadians ? valeur * 180.0 / C_UNITY::PI_ : valeur, nbDecimal) + "°";
    }
    
    static String radian(float radians, int nbDecimal = 3) {
        return String(radians, nbDecimal) + " rad";
    }
    
    static String degre(float degres, int nbDecimal = 3) {
        return String(degres, nbDecimal) + "°";
    }
    
    // Conversion entre unités
    static float degresToRadians(float degres) {
        return degres * C_UNITY::PI_ / 180.0;
    }
    
    static float radiansToDegres(float radians) {
        return radians * 180.0 / C_UNITY::PI_;
    }
};

// ============================================================================
// CLASSES SPÉCIFIQUES PAR TYPE D'UNITÉ (GÉNÉRÉES PAR MACRO)
// ============================================================================

//Grandeurs Électriques et Magnétiques
DECLARE_UNITY_CLASS(Tension, "V")             // Tension électrique (Volt)
DECLARE_UNITY_CLASS(Courant, "A")             // Courant électrique (Ampère)
DECLARE_UNITY_CLASS(Conductance, "S")         // Conductance électrique (Siemens)
DECLARE_UNITY_CLASS(ChampMagnetique, "T")     // Induction magnétique (Tesla)
DECLARE_UNITY_CLASS(FluxMagnetique, "Wb")     // Flux magnétique (Weber)
DECLARE_UNITY_CLASS(ChargeElectrique, "C")    // Charge électrique (Coulomb)
DECLARE_UNITY_CLASS(Conductivite, "S/m")      // Conductivité électrique (Siemens par mètre)
DECLARE_UNITY_CLASS(Resistivite, "Ω·m")       // Résistivité électrique (Ohm-mètre)

// Grandeurs Énergétiques et Puissances
DECLARE_UNITY_CLASS(Energie, "J")             // Énergie (Joule)
DECLARE_UNITY_CLASS(Puissance, "W")           // Puissance active (P) (Watt)
DECLARE_UNITY_CLASS(PuissanceApparente, "VA") // Puissance apparente (S)
DECLARE_UNITY_CLASS(PuissanceReactive, "VAr") // Puissance réactive (Q)
DECLARE_UNITY_CLASS(PuissanceDeformante, "VAD") // Puissance déformante (D)
DECLARE_UNITY_CLASS(EnergieKWh, "kWh")        // Énergie électrique consommée (compteur)
DECLARE_UNITY_CLASS(Energie_Calorie, "cal")       // Calorie (4.184 J)
DECLARE_UNITY_CLASS(Puissance_Cheval, "ch")       // Cheval-vapeur (≈735.5 W)
DECLARE_UNITY_CLASS(Energie_Thermie, "th")   // Thermie = 4.1855 MJ
DECLARE_UNITY_CLASS(DensiteEnergie, "J/m³")   // Densité d'énergie volumique
DECLARE_UNITY_CLASS(DensitePuissance, "W/m²") // Densité de puissance surfacique

// Grandeurs Électriques Avancées (pour le monitoring énergétique)
//DECLARE_UNITY_CLASS(FacteurPuissance, "")     // Facteur de puissance (cos φ, sans dimension, 0 à 1)
DECLARE_UNITY_CLASS(CosPhi, "cos φ")          // Facteur de puissance (cosinus phi)
DECLARE_UNITY_CLASS(Lambda, "λ") // Facteur de puissance en présence d'harmoniques
DECLARE_UNITY_CLASS(TauxHarmonique, "%")      // Taux de distorsion harmonique (THD)
DECLARE_UNITY_CLASS(TensionDC, "V")           // Tension continue (pour systèmes solaires/batteries)
DECLARE_UNITY_CLASS(CourantDC, "A")           // Courant continu
DECLARE_UNITY_CLASS(NiveauBatterie, "%")      // État de charge (State of Charge)

// Standards IEEE courants
DECLARE_UNITY_CLASS(Tension_RMS, "V")                // IEEE 1459 - Mesures d'énergie
DECLARE_UNITY_CLASS(THD, "%")                        // IEEE 519 - Distorsion harmonique
DECLARE_UNITY_CLASS(Puissance_Complexe, "VA")        // IEEE 1459 - Puissances

// Événements réseau
DECLARE_UNITY_CLASS(CreteTension, "V")        // Crête de tension (sur/sous-tensions)
DECLARE_UNITY_CLASS(DureeCrete, "ms")         // Durée de la crête
DECLARE_UNITY_CLASS(Flicker, "Pst")           // Indice de papillotement (Pst)
DECLARE_UNITY_CLASS(Interruption, "s")        // Durée d'interruption

// Analyse temporelle
DECLARE_UNITY_CLASS(DemandeMax, "kW")         // Puissance de demande maximale
DECLARE_UNITY_CLASS(DureeSousCharge, "%")     // Pourcentage du temps sous-chargé
DECLARE_UNITY_CLASS(DureeSurCharge, "%")      // Pourcentage du temps surchargé

// Unités en électricité et magnétisme (CGS)
DECLARE_UNITY_CLASS(ChampMagnetique_Gauss, "G")   // Gauss (1e-4 T)
DECLARE_UNITY_CLASS(FluxMagnetique_Maxwell, "Mx") // Maxwell (1e-8 Wb)

// Unités en radioactivité
DECLARE_UNITY_CLASS(Radioactivite_Curie, "Ci")    // Curie (3.7e10 Bq)
DECLARE_UNITY_CLASS(DoseAbsorbee_Rad, "rad")      // Rad (0.01 Gy)
DECLARE_UNITY_CLASS(DoseEquivalente_Rem, "rem")   // Rem (0.01 Sv)

// Grandeurs Mécaniques
DECLARE_UNITY_CLASS(Force, "N")               // Force (Newton)
DECLARE_UNITY_CLASS(Longueur, "m")            // Longueur (Mètre)
DECLARE_UNITY_CLASS(Vitesse, "m/s")           // Vitesse
DECLARE_UNITY_CLASS(Pression, "Pa")           // Pression (Pascal)

// Grandeurs Photométriques
DECLARE_UNITY_CLASS(FluxLumineux, "lm")       // Flux lumineux (Lumen)
DECLARE_UNITY_CLASS(Eclairement, "lx")        // Éclairement lumineux (Lux)
DECLARE_UNITY_CLASS(IntensiteLumineuse, "cd") // Intensité lumineuse (Candela)
DECLARE_UNITY_CLASS(Eclairement_Footcandle, "fc") // Foot-candle = 10.76 lx
DECLARE_UNITY_CLASS(Luminance_Nit, "nt")       // Nit = cd/m²
DECLARE_UNITY_CLASS(Luminance_Stilb, "sb")     // Stilb = 10⁴ cd/m²

// Grandeurs Temporelles et Fréquentielles
DECLARE_UNITY_CLASS(Frequence, "Hz")          // Fréquence (Hertz)
DECLARE_UNITY_CLASS(Temps, "s")               // Temps (Seconde) - également mécanique

// Grandeurs Sans Dimension ou Facteurs
DECLARE_UNITY_CLASS(Rendement, "ρ")           // Rendement (facteur sans dimension)
DECLARE_UNITY_CLASS(FacteurQualite, "Q")      // Facteur de qualité (sans dimension)
DECLARE_UNITY_CLASS(RapportCyclique, "%")     // Rapport cyclique (pourcentage)

// Grandeurs de Position, Mouvement et Inertie
// Position et angles
DECLARE_UNITY_CLASS(PositionLatitude, "°")    // Latitude (degrés décimaux)
DECLARE_UNITY_CLASS(PositionLongitude, "°")   // Longitude (degrés décimaux)
DECLARE_UNITY_CLASS(Altitude, "m")            // Altitude (mètres au-dessus du niveau de la mer)
DECLARE_UNITY_CLASS(Angle_IMU, "°")               // Angle d'inclinaison, roulis, tangage

// Accélération et vibration
DECLARE_UNITY_CLASS(Acceleration, "g")        // Accélération (g = 9.80665 m/s²) ou m/s²
DECLARE_UNITY_CLASS(Vibration, "m/s²")        // Vibration (amplitude d'accélération)
DECLARE_UNITY_CLASS(FrequenceVibration, "Hz") // Fréquence de vibration

// Vitesse angulaire et champ magnétique terrestre
DECLARE_UNITY_CLASS(VitesseAngulaire, "°/s")  // Taux de rotation (gyroscope)
DECLARE_UNITY_CLASS(ChampMagnetiqueTerrestre, "µT") // Magnétomètre (microTesla)

// ----------  Grandeurs Environnementales et Météorologiques ----------
// Température - Fondamentale pour presque tous les domaines IoT
DECLARE_UNITY_CLASS(Temperature, "°C")        // Degré Celsius (alternativement "K" pour Kelvin)
DECLARE_UNITY_CLASS(Humidite, "%RH")          // Humidité relative (Relative Humidity)
DECLARE_UNITY_CLASS(HumiditeAbsolue, "g/m³")  // Humidité absolue
DECLARE_UNITY_CLASS(PressionAtmospherique, "hPa") // Pression atmosphérique (hectopascal)
DECLARE_UNITY_CLASS(Pression_mmHg, "mmHg")        // Millimètre de mercure
DECLARE_UNITY_CLASS(PointDeRosee, "°C")       // Point de rosée
DECLARE_UNITY_CLASS(IndiceHumidex, "")        // Indice de chaleur humide (sans unité ou °C)
DECLARE_UNITY_CLASS(WindChill, "°C")          // Refroidissement éolien

// Vent et précipitations
DECLARE_UNITY_CLASS(VitesseVent, "m/s")       // Anémomètre (ou km/h)
DECLARE_UNITY_CLASS(DirectionVent, "°")       // Girouette (degrés de 0 à 360)
DECLARE_UNITY_CLASS(Pluviometrie, "mm")       // Hauteur de pluie (mm/h, mm/jour)
DECLARE_UNITY_CLASS(IntensitePluie, "mm/h")   // Intensité des précipitations

// Lumière et rayonnement solaire
DECLARE_UNITY_CLASS(EclairementSolaire, "W/m²") // Irradiance solaire (différent de Lux)
DECLARE_UNITY_CLASS(UV_Index, "")             // Indice UV (sans dimension)
DECLARE_UNITY_CLASS(Luminosite, "lux")        // Déjà présent (Eclairement), mais essentiel pour l'éclairage intelligent

// Grandeurs de Qualité de l'Air
DECLARE_UNITY_CLASS(CO2, "ppm")               // Dioxyde de carbone (Parties par million)
DECLARE_UNITY_CLASS(COV, "ppb")               // Composés Organiques Volatils (Parties par milliard)
DECLARE_UNITY_CLASS(CO, "ppm")                // Monoxyde de carbone
DECLARE_UNITY_CLASS(NO2, "ppb")               // Dioxyde d'azote
DECLARE_UNITY_CLASS(O3, "ppb")                // Ozone
DECLARE_UNITY_CLASS(PM1_0, "µg/m³")           // Particules fines < 1.0 µm
DECLARE_UNITY_CLASS(PM2_5, "µg/m³")           // Particules fines < 2.5 µm
DECLARE_UNITY_CLASS(PM10, "µg/m³")            // Particules fines < 10 µm
DECLARE_UNITY_CLASS(IndiceQA, "")             // Indice de Qualité de l'Air (sans dimension, souvent 0-500)
DECLARE_UNITY_CLASS(Formaldehyde, "ppb")      // Formaldéhyde (HCHO)

// Grandeurs pour l'Agriculture et le Sol
DECLARE_UNITY_CLASS(HumiditeSol, "%")         // Humidité volumique du sol
DECLARE_UNITY_CLASS(TemperatureSol, "°C")     // Température du sol
DECLARE_UNITY_CLASS(ConductiviteElectriqueSol, "dS/m") // Conductivité électrique du sol (salinité)
DECLARE_UNITY_CLASS(pH_Sol, "")               // pH du sol
DECLARE_UNITY_CLASS(NiveauNutriments, "mg/kg")// Azote, Phosphore, Potassium (N-P-K)

// ============================================================================
// ALIAS POUR UNE UTILISATION SIMPLIFIÉE
// ============================================================================

namespace C_UNITY_ALIAS {
    // Fonctions statiques de base
    inline String resistance(float ohms, int nbDecimal = 3) { return Resistance::afficher(ohms, nbDecimal); }
    inline String capacite(float farads, int nbDecimal = 3) { return Capacite::afficher(farads, nbDecimal); }
    inline String tension(float volts, int nbDecimal = 3) { return Tension::afficher(volts, nbDecimal); }
    inline String courant(float amperes, int nbDecimal = 3) { return Courant::afficher(amperes, nbDecimal); }
    inline String puissance(float watts, int nbDecimal = 3) { return Puissance::afficher(watts, nbDecimal); }
    inline String frequence(float hertz, int nbDecimal = 3) { return Frequence::afficher(hertz, nbDecimal); }
    inline String energie(float joules, int nbDecimal = 3) { return Energie::afficher(joules, nbDecimal); }
    inline String temps(float secondes, int nbDecimal = 3) { return Temps::afficher(secondes, nbDecimal); }
    
    // Nouvelles unités
    inline String pression(float pascals, int nbDecimal = 3) { return Pression::afficher(pascals, nbDecimal); }
    inline String conductance(float siemens, int nbDecimal = 3) { return Conductance::afficher(siemens, nbDecimal); }
    inline String fluxLumineux(float lumens, int nbDecimal = 3) { return FluxLumineux::afficher(lumens, nbDecimal); }
    inline String eclairement(float lux, int nbDecimal = 3) { return Eclairement::afficher(lux, nbDecimal); }
    inline String champMagnetique(float teslas, int nbDecimal = 3) { return ChampMagnetique::afficher(teslas, nbDecimal); }
    inline String fluxMagnetique(float webers, int nbDecimal = 3) { return FluxMagnetique::afficher(webers, nbDecimal); }
    inline String chargeElectrique(float coulombs, int nbDecimal = 3) { return ChargeElectrique::afficher(coulombs, nbDecimal); }
    inline String conductivite(float sm, int nbDecimal = 3) { return Conductivite::afficher(sm, nbDecimal); }
    inline String resistivite(float ohmM, int nbDecimal = 3) { return Resistivite::afficher(ohmM, nbDecimal); }
    inline String force(float newtons, int nbDecimal = 3) { return Force::afficher(newtons, nbDecimal); }
    inline String puissanceApparente(float va, int nbDecimal = 3) { return PuissanceApparente::afficher(va, nbDecimal); }
    inline String puissanceReactive(float var, int nbDecimal = 3) { return PuissanceReactive::afficher(var, nbDecimal); }
    
    // Unités non-C_UNITY
    inline String kelvin(float kelvin, int nbDecimal = 2) { return Temperature_KC::kelvin(kelvin, nbDecimal); }
    inline String celsius(float celsius, int nbDecimal = 2) { return Temperature_KC::celsius(celsius, nbDecimal); }
    inline String radian(float radians, int nbDecimal = 3) { return Angle::radian(radians, nbDecimal); }
    inline String degre(float degres, int nbDecimal = 3) { return Angle::degre(degres, nbDecimal); }
    
    // Fonction générique
    inline String generique(float val, String unite, int nbDecimal = 3, bool espace = true) { 
        return C_UNITY::valeurAvecUnite(val, unite, nbDecimal, espace); 
    }
}

#endif // VALEURS_SI_H
// UNITY.h - Librairie d'affichage et gestion des unités scientifiques
// Version: 1.0.0
// Auteur: [FOURNET Olivier]
// Licence: GPL-3.0 license
// Description: Fournit des fonctions pour formater des valeurs physiques avec des unités 
//              appropriées en utilisant les préfixes SI (k, M, G, m, µ, n, p, etc.)

#ifndef C_UNITY_H
#define C_UNITY_H

#include <Arduino.h>
#include <math.h>

// ============================================================================
// CLASSE C_UNITY GÉNÉRIQUE
// ============================================================================

class C_UNITY {
protected:
    float valeur;  // Valeur stockée pour les méthodes d'instance

public:
    // Constructeurs
    C_UNITY() : valeur(0.0) {}
    C_UNITY(float val) : valeur(val) {}
    
    // Méthodes d'accès
    float getValeur() const { return valeur; }
    void setValeur(float val) { valeur = val; }

    // Opérateurs arithmétiques simplifiés (retournent C_UNITY)
    C_UNITY operator+(const C_UNITY& other) const {
        return C_UNITY(valeur + other.valeur);
    }

    C_UNITY operator-(const C_UNITY& other) const {
        return C_UNITY(valeur - other.valeur);
    }
    
    C_UNITY operator*(const C_UNITY& other) const {
        return C_UNITY(valeur * other.valeur);
    }

    C_UNITY operator/(const C_UNITY& other) const {
        if (other.valeur != 0.0) return C_UNITY(valeur / other.valeur); // Évite la division par zéro
        else return NAN;
    }
    
    // Opérateurs avec des floats
    C_UNITY operator+(float val) const {
        return C_UNITY(valeur + val);
    }

    C_UNITY operator-(float val) const {
        return C_UNITY(valeur - val);
    }
    
    C_UNITY operator*(float val) const {
        return C_UNITY(valeur * val);
    }

    C_UNITY operator/(float val) const {
        if (val != 0.0) return C_UNITY(valeur / val); // Évite la division par zéro
        else return NAN;
    }
    
    // Opérateurs de conversion vers float (simplifie les calculs)
    operator float() const {
        return valeur;
    }
    
    // Opérateurs de comparaison
    bool operator==(const C_UNITY& other) const {
        return valeur == other.valeur;
    }
    
    bool operator!=(const C_UNITY& other) const {
        return valeur != other.valeur;
    }
    
    bool operator<(const C_UNITY& other) const {
        return valeur < other.valeur;
    }
    
    bool operator>(const C_UNITY& other) const {
        return valeur > other.valeur;
    }
    
    bool operator<=(const C_UNITY& other) const {
        return valeur <= other.valeur;
    }
    
    bool operator>=(const C_UNITY& other) const {
        return valeur >= other.valeur;
    }
    
    /**
     * Convertit une valeur avec l'unité appropriée en utilisant les préfixes SI
     * (Version statique)
     */
    static String valeurAvecUnite(float val, String unite, int nbDecimal = 3, bool espaceAvantUnite = true) {
        String result;
        if (espaceAvantUnite) result = " ";
        else result = "";
        
        // Gestion des valeurs négatives
        bool isNegative = val < 0;
        if (isNegative) {
            result += "-";
            val = -val;
        }
        
        // Valeur nulle
        if (val == 0.0) {
            result += "0.0";
            result += unite;
            return result;
        }
        
        // Conversion avec préfixes (multiplication par l'inverse pour optimisation)
        if (val >= 1.0e12) {
            result += String(val * 1.0e-12, nbDecimal);
            result += "T" + unite;
        } else if (val >= 1.0e9) {
            result += String(val * 1.0e-9, nbDecimal);
            result += "G" + unite;
        } else if (val >= 1.0e6) {
            result += String(val * 1.0e-6, nbDecimal);
            result += "M" + unite;
        } else if (val >= 1.0e3) {
            result += String(val * 1.0e-3, nbDecimal);
            result += "k" + unite;
        } else if (val >= 1.0) {
            result += String(val, nbDecimal);
            result += unite;
        } else if (val >= 1.0e-3) {
            result += String(val * 1.0e3, nbDecimal);
            result += "m" + unite;
        } else if (val >= 1.0e-6) {
            result += String(val * 1.0e6, nbDecimal);
            result += "µ" + unite;
        } else if (val >= 1.0e-9) {
            result += String(val * 1.0e9, nbDecimal);
            result += "n" + unite;
        } else if (val >= 1.0e-12) {
            result += String(val * 1.0e12, nbDecimal);
            result += "p" + unite;
        } else if (val >= 1.0e-15) {
            result += String(val * 1.0e15, nbDecimal);
            result += "f" + unite;
        } else if (val >= 1.0e-18) {
            result += String(val * 1.0e18, nbDecimal);
            result += "a" + unite;
        } else {
            // Valeur trop petite
            result += "ε"; // GREEK SMALL LETTER EPSILON , code UTF-8 : 0xCEB5  
            result += unite;
        }
        
        return result;
    }
    
    /**
     * Convertit la valeur stockée avec l'unité appropriée
     * (Version d'instance)
     */
    String valeurAvecUnite(String unite, int nbDecimal = 3, bool espaceAvantUnite = true) const {
        return valeurAvecUnite(valeur, unite, nbDecimal, espaceAvantUnite);
    }
    
    /**
     * Formate un nombre avec séparateur de milliers
     */
    static String formatNombre(float valeur, int decimales = 0, char separateur = ' ') {
        String result = String(valeur, decimales);
        
        int pointIndex = result.indexOf('.');
        if (pointIndex == -1) pointIndex = result.length();
        
        String partieEntiere = result.substring(0, pointIndex);
        String partieDecimale = ((unsigned int)pointIndex < result.length()) ? result.substring(pointIndex) : "";
        
        String formatted = "";
        int count = 0;
        for (int i = partieEntiere.length() - 1; i >= 0; i--) {
            if (partieEntiere[i] == '-') {
                formatted = "-" + formatted;
                break;
            }
            formatted = String(partieEntiere[i]) + formatted;
            count++;
            if (count == 3 && i > 0 && partieEntiere[i-1] != '-') {
                formatted = String(separateur) + formatted;
                count = 0;
            }
        }
        
        return formatted + partieDecimale;
    }
    
    /**
     * Formate la valeur stockée avec séparateur de milliers
     */
    String formatNombre(int decimales = 0, char separateur = ' ') const {
        return formatNombre(valeur, decimales, separateur);
    }
    
    // ------------------------------------------------------------------------
    // CONSTANTES PHYSIQUES UTILES
    // ------------------------------------------------------------------------
    
    static constexpr float PI_ = 3.14159265358979323846f;
    static constexpr float KELVIN_OFFSET = 273.15;
    static constexpr float CHARGE_ELEMENTAIRE = 1.602176634e-19;
    static constexpr float CONSTANTE_BOLTZMANN = 1.380649e-23;
    static constexpr float CONSTANTE_PLANCK = 6.62607015e-34;
    static constexpr float VITESSE_LUMIERE = 299792458.0;
    static constexpr float PERMEABILITE_VIDE = 4.0 * PI_ * 1e-7;
    static constexpr float PERMITTIVITE_VIDE = 8.8541878128e-12;
    static constexpr float ACCELERATION_GRAVITE = 9.80665;
    static constexpr float CONSTANTE_GAZ_PARFAIT = 8.314462618;
    static constexpr float CONSTANTE_FARADAY = 96485.33212;
    static constexpr float CONSTANTE_STEFAN_BOLTZMANN = 5.670374419e-8;
};

// ============================================================================
// MACRO POUR CRÉER DES CLASSES D'UNITÉS (RÉDUIT LE CODE RÉPÉTITIF)
// ============================================================================

#define DECLARE_UNITY_CLASS(ClassName, UnitSymbol) \
class ClassName : public C_UNITY { \
public: \
    ClassName() : C_UNITY() {} \
    ClassName(float val) : C_UNITY(val) {} \
    String afficher(int nbDecimal = 3) const { \
        return valeurAvecUnite(UnitSymbol, nbDecimal); \
    } \
    static String afficher(float val, int nbDecimal = 3) { \
        return C_UNITY::valeurAvecUnite(val, UnitSymbol, nbDecimal); \
    } \
    /* Pour faciliter les opérations entre objets de même type */ \
    ClassName operator+(const ClassName& other) const { \
        return ClassName(valeur + other.valeur); \
    } \
    ClassName operator-(const ClassName& other) const { \
        return ClassName(valeur - other.valeur); \
    } \
    ClassName operator*(const ClassName& other) const { \
        return ClassName(valeur * other.valeur); \
    } \
    ClassName operator/(const ClassName& other) const { \
        return ClassName(valeur / other.valeur); \
    } \
};


#endif // C_UNITY_H

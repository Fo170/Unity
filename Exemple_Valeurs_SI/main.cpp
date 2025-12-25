// main.ino - Exemple d'utilisation de la librairie valeurs_SI
// Auteur: [FOURNET Olivier]
// Description: Démonstration des fonctionnalités de formatage d'unités scientifiques

#include <Arduino.h>

#include "Unity.h"
#include "valeurs_SI.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n=== DÉMONSTRATION BIBLIOTHÈQUE VALEURS_SI ===\n");
  
  // =====================================================================
  // 1. UTILISATION DES CLASSES DE BASE
  // =====================================================================
  Serial.println("1. CLASSES DE BASE:");
  Serial.println("===================");
  
  // Tension
  Tension tension(12.5);
  Serial.print("Tension d'exemple: ");
  Serial.println(tension.afficher(2));
  
  // Courant
  Courant courant(0.005); // 5 mA
  Serial.print("Courant d'exemple: ");
  Serial.println(courant.afficher(4));
  
  // Puissance
  Puissance puissance(2500.75); // 2.50075 kW
  Serial.print("Puissance d'exemple: ");
  Serial.println(puissance.afficher(2));
  
  // Fréquence
  Frequence frequence(15000000); // 15 MHz
  Serial.print("Fréquence d'exemple: ");
  Serial.println(frequence.afficher(1));
  
  // =====================================================================
  // 2. CLASSES SPÉCIALISÉES (Résistance, Capacité, Inductance)
  // =====================================================================
  Serial.println("\n2. CLASSES SPÉCIALISÉES:");
  Serial.println("=========================");
  
  // Résistance
  Resistance r1(1000); // 1kΩ
  Resistance r2(4700); // 4.7kΩ
  Resistance r3(100);  // 100Ω
  
  Serial.print("R1 = ");
  Serial.println(r1.afficher(0));
  Serial.print("R2 = ");
  Serial.println(r2.afficher(0));
  Serial.print("R3 = ");
  Serial.println(r3.afficher(0));
  
  // Calculs avec résistances
  Serial.print("\nRésistance série (R1 + R2): ");
  Serial.println(Resistance::afficher(Resistance::calculerResistanceSerie(r1.getValeur(), r2.getValeur()), 0));
  
  Serial.print("Résistance parallèle (R1 // R2): ");
  Serial.println(Resistance::afficher(Resistance::calculerResistanceParallele(r1.getValeur(), r2.getValeur()), 0));
  
  // Capacité
  Capacite c1(0.000001); // 1µF
  Capacite c2(0.0000001); // 100nF
  
  Serial.print("\nC1 = ");
  Serial.println(c1.afficher(3));
  Serial.print("C2 = ");
  Serial.println(c2.afficher(3));
  
  Serial.print("Capacité parallèle (C1 + C2): ");
  Serial.println(Capacite::afficher(Capacite::calculerCapaciteParallele(c1.getValeur(), c2.getValeur()), 3));
  
  // Inductance
  Inductance l1(0.001); // 1mH
  Inductance l2(0.00047); // 470µH
  
  Serial.print("\nL1 = ");
  Serial.println(l1.afficher(3));
  Serial.print("L2 = ");
  Serial.println(l2.afficher(3));
  
  Serial.print("Inductance série (L1 + L2): ");
  Serial.println(Inductance::afficher(Inductance::calculerInductanceSerie(l1.getValeur(), l2.getValeur()), 3));
  
  // =====================================================================
  // 3. OPÉRATIONS MATHÉMATIQUES
  // =====================================================================
  Serial.println("\n3. OPÉRATIONS MATHÉMATIQUES:");
  Serial.println("=============================");
  
  Tension v1(5.0);
  Tension v2(3.3);
  
  Serial.print("v1 = ");
  Serial.println(v1.afficher(1));
  Serial.print("v2 = ");
  Serial.println(v2.afficher(1));
  
  // Utilisation de la méthode statique au lieu de l'opérateur ambigu
  Serial.print("v1 + v2 = ");
  Serial.println(Tension(v1.getValeur() + v2.getValeur()).afficher(1));
  
  Serial.print("v1 - v2 = ");
  Serial.println(Tension(v1.getValeur() - v2.getValeur()).afficher(1));
  
  // Utilisation de getValeur() pour éviter l'ambiguïté
  Serial.print("v1 * 2 = ");
  Serial.println(Tension(v1.getValeur() * 2.0).afficher(1));
  
  Serial.print("v1 / 2 = ");
  Serial.println(Tension(v1.getValeur() / 2.0).afficher(1));
  
  // =====================================================================
  // 4. TEMPÉRATURE ET ANGLE
  // =====================================================================
  Serial.println("\n4. TEMPÉRATURE ET ANGLE:");
  Serial.println("=========================");
  
  // Température
  Temperature_KC tempC(25.0, __Celsius__); // 25°C
  Temperature_KC tempK(300.0, __Kelvin__);  // 300K
  
  Serial.print("Température 25°C en Kelvin: ");
  Serial.println(tempC.kelvin(1));
  Serial.print("Température 300K en Celsius: ");
  Serial.println(tempK.celsius(1));
  
  Serial.print("Conversion 0°C en Kelvin: ");
  Serial.println(Temperature_KC::celsiusToKelvin(0));
  Serial.print("Conversion 100°C en Fahrenheit: ");
  Serial.println(Temperature_KC::celsiusToFahrenheit(100), 1);
  
  // Angle
  Angle angleRad(3.14159, __Radians__); // π rad
  Angle angleDeg(180.0, __Degres__);  // 180°

  Serial.print("\nAngle π rad en degrés: ");
  Serial.println(angleRad.degre(1));
  Serial.print("Angle 180° en radians: ");
  Serial.println(angleDeg.radian(4));
  
  Serial.print("Conversion 90° en radians: ");
  Serial.println(Angle::degresToRadians(90), 4);
  
  // =====================================================================
  // 5. UTILISATION DES ALIAS (C_UNITY_ALIAS)
  // =====================================================================
  Serial.println("\n5. ALIAS (C_UNITY_ALIAS):");
  Serial.println("==========================");
  
  Serial.print("Résistance 1500Ω: ");
  Serial.println(C_UNITY_ALIAS::resistance(1500));
  
  Serial.print("Capacité 0.00000022F: ");
  Serial.println(C_UNITY_ALIAS::capacite(0.00000022));
  
  Serial.print("Tension 230V: ");
  Serial.println(C_UNITY_ALIAS::tension(230));
  
  Serial.print("Courant 0.00015A: ");
  Serial.println(C_UNITY_ALIAS::courant(0.00015));
  
  Serial.print("Fréquence 433000000Hz: ");
  Serial.println(C_UNITY_ALIAS::frequence(433000000));
  
  // Unités spéciales
  Serial.print("Force 9.81N: ");
  Serial.println(C_UNITY_ALIAS::force(9.81));
  
  Serial.print("Pression 101325Pa: ");
  Serial.println(C_UNITY_ALIAS::pression(101325));
  
  // Température et angle via alias
  Serial.print("Température 20°C: ");
  Serial.println(C_UNITY_ALIAS::celsius(20));
  
  Serial.print("Angle 45°: ");
  Serial.println(C_UNITY_ALIAS::degre(45));
  
  // Fonction générique
  Serial.print("Générique 1234567 unités: ");
  Serial.println(C_UNITY_ALIAS::generique(1234567, "U", 2));
  
  // =====================================================================
  // 6. EXEMPLES DIVERS
  // =====================================================================
  Serial.println("\n6. EXEMPLES DIVERS:");
  Serial.println("====================");
  
  // Très petites valeurs
  Serial.print("Courant très faible: ");
  Serial.println(Courant::afficher(0.000000012, 6)); // 12nA
  
  Serial.print("Capacité très petite: ");
  Serial.println(Capacite::afficher(0.000000000001, 6)); // 1pF
  
  // Très grandes valeurs
  Serial.print("Fréquence très élevée: ");
  Serial.println(Frequence::afficher(2400000000, 3)); // 2.4GHz
  
  // Valeurs négatives
  Serial.print("Tension négative: ");
  Serial.println(Tension::afficher(-12.5, 1));
  
  // Formatage avec séparateur de milliers
  Serial.print("Formatage nombre: ");
  Serial.println(C_UNITY::formatNombre(1234567.89, 2, ','));
  
  // Puissance apparente et réactive (utiliser les instances)
  PuissanceApparente pa(3500);
  Serial.print("Puissance apparente: ");
  Serial.println(pa.afficher());
  
  PuissanceReactive pr(1500);
  Serial.print("Puissance réactive: ");
  Serial.println(pr.afficher());
  
  // Rendement et facteur de qualité
  Rendement rendement(0.85);
  Serial.print("Rendement: ");
  Serial.println(rendement.afficher(2));
  
  FacteurQualite q(50);
  Serial.print("Facteur de qualité: ");
  Serial.println(q.afficher(0));
  
  Serial.println("\n=== FIN DE LA DÉMONSTRATION ===");
}

void loop() {
  // Afficher périodiquement quelques valeurs
  static unsigned long lastTime = 0;
  
  if (millis() - lastTime > 5000) {
    lastTime = millis();
    
    // Générer des valeurs aléatoires pour démonstration
    float tensionAleatoire = random(100, 5000) / 100.0;
    float courantAleatoire = random(1, 1000) / 1000000.0;
    float resistanceAleatoire = random(100, 10000);
    
    Serial.println("\n--- MESURES PÉRIODIQUES ---");
    Serial.print("Tension: ");
    Serial.println(Tension::afficher(tensionAleatoire, 2));
    
    Serial.print("Courant: ");
    Serial.println(Courant::afficher(courantAleatoire, 6));
    
    Serial.print("Résistance: ");
    Serial.println(Resistance::afficher(resistanceAleatoire, 0));
    
    // Calcul de puissance (P = V × I)
    float puissance = tensionAleatoire * courantAleatoire;
    Serial.print("Puissance: ");
    Serial.println(Puissance::afficher(puissance, 3));
  }
  
  delay(100);
}

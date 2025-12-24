// main.ino - Exemple d'utilisation de la librairie Unity
// Auteur: [FOURNET Olivier]
// Description: Démonstration des fonctionnalités de formatage d'unités scientifiques

#include <Arduino.h>

#include "Unity.h"

// Déclaration des classes d'unités spécifiques
DECLARE_UNITY_CLASS(Resistance, "Ω")
DECLARE_UNITY_CLASS(Tension, "V")
DECLARE_UNITY_CLASS(Courant, "A")
DECLARE_UNITY_CLASS(Capacite, "F")
DECLARE_UNITY_CLASS(Frequence, "Hz")
DECLARE_UNITY_CLASS(Puissance, "W")

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("=== EXEMPLE BIBLIOTHEQUE UNITY ===");
  Serial.println();
  
  // 1. Utilisation de la classe générique C_UNITY
  Serial.println("1. CLASSE GENERIQUE C_UNITY:");
  
  C_UNITY valeurGenerique(1234567.89);
  Serial.print("Valeur générique: ");
  Serial.println(valeurGenerique.valeurAvecUnite("U"));
  
  Serial.print("Format nombre avec séparateur: ");
  Serial.println(valeurGenerique.formatNombre(2, ','));
  Serial.println();
  
  // 2. Utilisation des classes d'unités spécifiques
  Serial.println("2. UNITES SPECIFIQUES:");
  
  // Résistance
  Resistance r1(4700); // 4.7kΩ
  Resistance r2(0.022); // 22mΩ
  
  Serial.print("R1 = ");
  Serial.println(r1.afficher(2));
  
  Serial.print("R2 = ");
  Serial.println(r2.afficher(2));
  
  // Tension
  Tension v1(3.3); // 3.3V
  Tension v2(0.005); // 5mV
  
  Serial.print("V1 = ");
  Serial.println(v1.afficher(3));
  
  Serial.print("V2 = ");
  Serial.println(v2.afficher(3));
  
  // Courant
  Courant i1(0.0015); // 1.5mA
  Courant i2(2.7e-6); // 2.7µA
  
  Serial.print("I1 = ");
  Serial.println(i1.afficher(3));
  
  Serial.print("I2 = ");
  Serial.println(i2.afficher(3));
  
  // Capacité
  Capacite c1(0.000001); // 1µF
  Capacite c2(100e-12); // 100pF
  
  Serial.print("C1 = ");
  Serial.println(c1.afficher(3));
  
  Serial.print("C2 = ");
  Serial.println(c2.afficher(3));
  Serial.println();
  
  // 3. Opérations mathématiques
  Serial.println("3. OPERATIONS MATHEMATIQUES:");
  
  // Addition de résistances
  Resistance rTotal = r1 + r2;
  Serial.print("R1 + R2 = ");
  Serial.println(rTotal.afficher(3));
  
  // Loi d'Ohm: V = R * I
  Tension vCalc = Tension((float)r1 * (float)i1);
  Serial.print("V = R1 * I1 = ");
  Serial.println(vCalc.afficher(3));
  
  // Division
  Resistance rDiv = Resistance((float)v1 / (float)i1);
  Serial.print("R = V1 / I1 = ");
  Serial.println(rDiv.afficher(3));
  Serial.println();
  
  // 4. Comparaisons
  Serial.println("4. COMPARAISONS:");
  
  Serial.print("R1 > R2 ? ");
  Serial.println(r1 > r2 ? "Oui" : "Non");
  
  Serial.print("V1 == V2 ? ");
  Serial.println(v1 == v2 ? "Oui" : "Non");
  
  Serial.print("I1 < I2 ? ");
  Serial.println(i1 < i2 ? "Oui" : "Non");
  Serial.println();
  
  // 5. Utilisation des constantes physiques
  Serial.println("5. CONSTANTES PHYSIQUES:");
  
  Serial.print("Charge élémentaire: ");
  Serial.println(C_UNITY::valeurAvecUnite(C_UNITY::CHARGE_ELEMENTAIRE, "C", 10));
  
  Serial.print("Constante de Planck: ");
  Serial.println(C_UNITY::valeurAvecUnite(C_UNITY::CONSTANTE_PLANCK, "J.s", 10));
  
  Serial.print("Vitesse de la lumière: ");
  Serial.println(C_UNITY::valeurAvecUnite(C_UNITY::VITESSE_LUMIERE, "m/s", 3));
  
  // 6. Exemples avec des valeurs extrêmes
  Serial.println();
  Serial.println("6. VALEURS EXTREMES:");
  
  // Très grande valeur
  Resistance rGrande(5.6e9); // 5.6GΩ
  Serial.print("Résistance très grande: ");
  Serial.println(rGrande.afficher(3));
  
  // Très petite valeur
  Courant iPetit(1.2e-15); // 1.2fA
  Serial.print("Courant très petit: ");
  Serial.println(iPetit.afficher(3));
  
  // Valeur nulle
  Tension vNulle(0.0);
  Serial.print("Tension nulle: ");
  Serial.println(vNulle.afficher(3));
  
  // Valeur négative
  Tension vNegative(-12.5);
  Serial.print("Tension négative: ");
  Serial.println(vNegative.afficher(3));
  
  Serial.println();
  Serial.println("=== FIN DE L'EXEMPLE ===");
}

void loop() {
  // Rien à faire ici
  delay(1000);
}

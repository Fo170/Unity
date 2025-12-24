# Unity Library - Gestion des Unités Scientifiques pour Arduino
Fournit des fonctions pour formater des valeurs physiques avec des unités  appropriées en utilisant les préfixes SI (k, M, G, m, µ, n, p, etc.)

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-GPL--3.0-green)
![Arduino](https://img.shields.io/badge/platform-Arduino-00979D)

Une bibliothèque légère et puissante pour formater, manipuler et afficher des valeurs physiques avec leurs unités appropriées en utilisant les préfixes SI (kilo, méga, micro, nano, etc.). Parfaite pour les projets scientifiques, instrumentation et électronique.

## ✨ Fonctionnalités Principales

- **📐 Formatage automatique SI** : Conversion automatique avec préfixes (k, M, G, m, µ, n, p, etc.)
- **🔧 Classes d'unités typées** : Création facile de classes spécifiques (Volts, Ohms, Ampères, etc.)
- **🧮 Opérations mathématiques** : Surcharge complète des opérateurs pour calculs naturels
- **⚖️ Comparaisons** : Opérateurs de comparaison pour les grandeurs physiques
- **🌌 Constantes physiques** : Inclut les principales constantes (Planck, Boltzmann, vitesse lumière)
- **🔢 Formatage de nombres** : Séparateurs de milliers pour une meilleure lisibilité
- **🌐 Support UTF-8** : Caractères spéciaux (µ, ε) correctement gérés

## 📦 Installation

### Installation via Arduino IDE
1. Téléchargez la dernière version de la bibliothèque
2. Dans l'IDE Arduino : Croquis → Inclure une bibliothèque → Ajouter bibliothèque .ZIP
3. Sélectionnez le fichier ZIP téléchargé

### Installation Manuelle
```bash
# Clonez le dépôt dans votre dossier de bibliothèques Arduino
cd ~/Documents/Arduino/libraries/
git clone https://github.com/Fo170/Unity.git
```
### Méthode 1 : Via PlatformIO (recommandé)
Ajoutez la dépendance dans votre fichier `platformio.ini` :
```ini
lib_deps = 
    https://github.com/Fo170/Unity.git

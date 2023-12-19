# Gestion d'un Système Hospitalier

## Introduction
Le code couvre la gestion des patients, des médecins, des infirmières, des diagnostics, des plans de traitement, et des hôpitaux.

## Structure du Code

Le code est divisé en plusieurs fichiers, chacun responsable d'une classe spécifique (Person, Doctor, Nurse, Patient, Diagnosis, TreatmentPlan, Hospital). L'utilisation de classes permet une encapsulation claire des fonctionnalités, améliorant ainsi la lisibilité et la maintenance du code.

## Classes Principales

### 1. **Person**

- Représente une personne avec des informations de base telles que le nom, le genre, la date de naissance, le groupe sanguin, l'adresse, le numéro de téléphone et le numéro de sécurité sociale.
  
### 2. **Doctor, Nurse**

- Héritent de la classe Person et ajoutent des informations spécifiques au rôle (spécialité pour le médecin, nombre d'années d'expérience pour l'infirmière).

### 3. **Patient**

- Hérite de la classe Person et contient des informations spécifiques au patient, telles que les symptômes, les allergies, et les résultats des tests.

### 4. **Diagnosis**

- Représente un diagnostic pour un patient, liant les symptômes aux résultats des tests.

### 5. **TreatmentPlan**

- Contient un plan de traitement associé à un patient, avec des informations sur le type de traitement, les descriptions et la date de début.

### 6. **Hospital**

- Gère les médecins, les infirmières et les patients. Permet l'ajout, la suppression, la recherche et l'affichage de ces entités.

## Fonctionnalités Principales

### 1. **Ajout d'Entités**

- Le code permet d'ajouter des médecins, des infirmières, des patients, des diagnostics, et des plans de traitement à un hôpital.

### 2. **Affichage d'Informations**

- Les informations sur les médecins, les infirmières, et les patients peuvent être affichées pour un hôpital spécifique.

### 3. **Modification d'Affiliation**

- Les médecins peuvent changer d'hôpital, et les informations correspondantes sont mises à jour.

### 4. **Suppression d'Entités**

- Les patients décédés peuvent être supprimés de l'hôpital.

### 5. **Examens et Prescription**

- Le code simule des examens médicaux et des prescriptions pour un patient.

### 6. **Diagnostic et Traitement**

- Le diagnostic est associé aux symptômes et aux résultats des tests. Un plan de traitement est également associé à un patient.

## Conclusion

Le code source fournit une structure modulaire pour la gestion d'un système hospitalier en C++. Les classes bien définies et les fonctionnalités spécifiques offrent une base solide pour l'extension du système. L'utilisation de l'héritage permet une réutilisation du code et une séparation claire des responsabilités. Ce document offre une vue d'ensemble complète du fonctionnement du système de gestion hospitalière.
# OnTheRoadAgain 
Un robot suiveur de ligne “from scratch” créer pendant le bureau d'étude à l’Université Paul Sabatier - Toulouse III, 2023 par NGUYEN Minh Khanh Nam.
Vidéo Démonstration:
https://youtube.com/shorts/FbR3X0CkPOg?feature=share

## Outils utilisés:
[Arduino IDE](https://www.arduino.cc/en/software) : IDE pour compiler/charger le code vers l'Arduino
[OpenSCAD](https://openscad.org/downloads.html) : "IDE" pour créer des pièces 3D configurées

## Composants utilisés:
- Arduino: Uno
<img src="https://github.com/user-attachments/assets/79493567-de3a-4c02-8262-b11da3b6cc7a" width="100">

- Shield Moteur: L293 DRI0001
<img src="https://github.com/user-attachments/assets/5723daeb-e320-47ac-a4e1-53ab2531cc2f" width="100">

- Moteur: DAGU_DG01D
<img src="https://github.com/user-attachments/assets/abe0e264-52e2-4222-b915-7b862171a11a" width="100">

- Roues principales: RW002
<img src="https://github.com/user-attachments/assets/d7f4977b-acad-46ae-ac95-439a2399aa1a" width="100">

- Capteur Infrarouge: QTR-3RC
<img src="https://github.com/user-attachments/assets/91e700c3-9a09-4723-b2fc-301599bc7c27" width="100">

- Fils connecteurs
- Batterie externe

## Squelette 3D:
Dans le répertoire Parts, on a:
- Base.scad: la base du squelette
- SupportBat.scad: le support pour la batterie externe
- Support25.scad: le support pour le capteur IR
Il manque aussi le support pour les roues, qui fait parti du répositoire [RobotParts](https://github.com/hcasse/RobotParts) de Hugues Cassé au nom de DAGU_G01D_simple.scad situé à RobotParts-main\sens_act_supports.

## À améliorer:
### Contrôle PID
Littéralement de la magie noire, il faut encore plus changer les variables KP, KI, KD (aléatoirement) pour optimiser la précision et la puissance du robot.
### Propulsion arrière
Avec cette configuration de squelette, j'ai rencontré la propulsion arrière, où l'arrière est trop lourde comparée qu'à l'avant, donc le robot se met à sa fesse... Donc j'ai du rajouter BEAUCOUP de poids à l'avant pour équilibrer le poids mais comme plus de poids = moins de force, le robot sera plus lent. Il faudra considérer une autre concept pour la squelette.

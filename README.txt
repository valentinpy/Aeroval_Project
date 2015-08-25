AEROVAL
Auteur: Valentin Py  - valentin.py@gmail.com
Date: 22.08.15

Ce projet est le développement d'un PCB ainsi que sa programmation.
Ce PCB est prévu pour le contrôle d'un quadri/octocoptère, mais est aussi utilisable pour un avion ou une voiture.
Pour plus de détails: voir le fichier "functionnalities.txt, ci-joint)

Matériel:
Un PCB de prototype a été développé et produit à 3 exemplaires. "Aeroval-v2-PCB1-proto1.pcbdoc" (gerber utilisés fournis)
Ce PCB fonctionne pour la plupart des fonctions prévues, mais il y aurait quelques améliorations /résolution de problèmes à effectuer:
	- connecteur micro-SD: à retourner de 180°, il n'est actuellement pas possible d'insérer une carte uSD.
	- transistors T1, T2, T3, T4: la numérotation du footprint est fausse, il faut corriger, sinon le transistor sera soudé "à l'envers"
	- Le solder mask est à modifier sous U4, afin de ne pas avoir de résine sous le pad thermique. (bien que ça fonctionne quand même dans l'état actuel)
	
La BOM est fournie et les supplier links sont remplis (pour la plupart) sur Altium.

Logiciel:
Le développement n'est pas terminé, il y a encore pas mal de travail à faire, mais les modules et les interfaces sont déjà programmés pour la plupart.



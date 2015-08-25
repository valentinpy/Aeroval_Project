/*
------------------------------------------------------------
Copyright 2003-2013 Haute Ecole ARC Ingénierie,
Switzerland. All rights reserved
------------------------------------------------------------
Nom du fichier : 	gInput.h
Auteurs:			Alexandre Schnegg
					Guillaume Jacot
Date:				23.01.13
But :	Gestionnaire d'entrées
------------------------------------------------------------
*/

#ifndef GINPUT_H_
#define GINPUT_H_

//-----------------------------------------------------------------------------
// Configuration du gestionnaire
//-----------------------------------------------------------------------------
void gInput_Setup(void);

//-----------------------------------------------------------------------------
// Exécution du gestionnaire
//-----------------------------------------------------------------------------
void gInput_Execute(void);
void gInput_ExecuteInt(void);

#endif

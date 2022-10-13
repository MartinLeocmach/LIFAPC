// LIFAP6 - Automne 2017 - R. Chaine
#ifndef _NB_COMP
#define _NB_COMP
//====================================================================
// Nombres Complexes: specification
//====================================================================

// nombreComplexe.h
// Interface du module NombreComplexe offrant le type abstrait Complexe
// ainsi qu'un jeu d'operations, de fonctions et de procedures permettant
// de manipuler les Complexes independamment de leur implantation interne.

// Modules importes-------------------------------------------------------
// (offrant des types, variables, constantes, procedures
//  ou fonctions intervenant dans l'interface de NombreComplexe)
#include "reel.h" //Module offrant le type Reel
#include <iostream>

//  -----------------------------------------------------------------------
//  Types, variables, constantes, procedures et fonctions exportees

// declaration constante globale exportee
extern const Reel PI;

// declaration variable globale exportee
// (aucune ici)

// declaration (et definition!) type exporte
class Complexe {
  public:
    //--declaration constructeurs (pour initialisation)---------------------
    Complexe(); //Constructeur par defaut
    //Precondition : Aucune (*this non initialise)
    //               (Constructeur appele automatiquement a chaque creation
    //               d'un Complexe sans parametres pour proceder a son
    //               initialisation)
    //Postcondition : le Complexe *this initialise vaut 0
    //                et le nombre de Complexes "vivants" est incremente de 1
    Complexe(const Complexe & c); //Constructeur par copie
    //Precondition :  Aucune (*this non initialise)
    //Postcondition : le complexe *this initialise a la meme valeur que c
    //                et le nombre de Complexes vivants est incremente de 1
    Complexe(const Reel & a,const Reel & b); //Constructeur a partir de 2 Reels
    //Precondition : Aucune (*this non initialise)
    //Postcondition : le complexe *this initialise vaut a+ib
    //                et le nombre de Complexes vivants est incremente de 1
    
    //--declaration destructeur ("testament" des Complexes)----------------
    ~Complexe();
    //Precondition : *this prealablement initialise
    //               (Destructeur appele automatiquement quand un Complexe
    //               doit disparaitre pour proceder a son "testament")
    // Postcondition : *this est pret a disparaitre
    //        (le nombre de Complexes vivant est decremente de 1)
    
    // declaration surcharge operator =-----------------------------------
    // qui permettra l'affectation d'un complexe c au complexe *this
    Complexe & operator = (const Complexe & c);
    //Precondition : *this et c initialises
    //Postcondition : le complexe *this a affecter a la meme valeur que c

    /// Affichage d'un Complexe----------------------------------------
    void affiche() const;
    // Precondition : *this initialise
    // Postcondition : Affichage sur la sortie standard du complexe *this
    
    // Fonctions d'acces -----------------------------------------------
    Reel getRe() const {return x;}
    Reel getIm() const {return y;}
    // Fonctions de modification---------------------------------------
    void setRe(const Reel & re){x=re;}
    void setIm(const Reel & im){y=im;}

 private: //donnees membres (champs)------------------------------------
    Reel x,y;
};

//Addition entre Complexes
Complexe operator +(const Complexe & c1,const Complexe & c2);
//Precondition : c1 et c2 initialises
//Resultat : renvoie la somme des complexes codes dans c1 et c2

// Operateurs d'entree-sortie -------------------------------------
std::ostream& operator<< (std::ostream&, const Complexe&);
std::istream& operator>> (std::istream&, Complexe&);

//Nombre de Complexes "vivants"
int nbComplexesVivants();
//Precondition : aucune
//Resultat : renvoie le nombre de Complexes "vivants" au moment de l'appel

//procedure test
void testPassageParValeur(Complexe c);
//Precondition : aucune
//Postcondition : Rien a signaler
//                Procedure permettant juste d'illustrer le passage
//                par valeur d'un Complexe

#endif //_Complexe_H_

#ifndef _ARBREAVL
#define _ARBREAVL
#include "noeud.h"

class AVL
{
    private :
    noeud * racine;

    //rotation pour equilibrage après insertion
    void rotationGauche(noeud** &pN);
    void rotationDroite(noeud** &pN);
    void rotationDoubleGauche(noeud** &pN);
    void rotationDoubleDroite(noeud** &pN);


    public :
    //Constructeurs
    //Par défaut this vide
    AVL();

    //avec un élément e dans le noeud racine
    AVL(Elem e);

    //Par copie profonde de a
    AVL(AVL *a);

    ~AVL();

    //accesseurs
    noeud * getRacine();

    
    //Surcharge de l'affectation
    void operator= (AVL *a);

    void insertion (Elem e);

    //recherche
    //precondition : this et e initialisé
    //postcondition : retourne vrai si e est dans a, faux sinon
    bool recherche(Elem e);

    //affichages :
    //Prefixe
    void affichePrefix();
    //Postfixe
    void affichePostfix();
    //Infixe
    void afficheInfix();
    //Postfixe + hauteur noeud
    void affichePostfixHauteur();
    //Infixe + hauteur noeud
    void afficheInfixHauteur();
};
#endif
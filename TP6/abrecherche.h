#ifndef _ARBREBR
#define _ARBREBR
#include "noeud.h"

class abr
{
    private :
    noeud * racine;
    noeud * minimum;

    public :
    //Constructeurs
    //Par défaut this vide
    abr();

    //avec un élément e dans le noeud racine
    abr(Elem e);

    //Par copie profonde de a
    abr(abr *a);

    ~abr();

    //accesseurs
    noeud * getRacine();

    
    //Surcharge de l'affectation
    void operator= (abr *a);

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

    //Couture de l'arbre
    void coudre();
    //affichage infixe arbre cousu
    void afficheCousu();
    //insertion dans un arbre cousu
    void insertionCousu(Elem e);
};
#endif
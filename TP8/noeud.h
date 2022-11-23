#ifndef _NOEUDBR
#define _NOEUDBR
#include "element.h"

class noeud
{
    private :
        Elem val;
        int hauteur;
        noeud * fils_g;
        noeud * fils_d;


    public :
        //Constructeurs 
        //par défaut
        //post-condtions : les fils sont nullptr, val=0
        noeud();
        //post-condtions : les fils sont nullptr, val = e
        noeud(Elem e);
        //par copie profonde
        //pre-condition : a initialisé
        //post-condition this est une copie profonde de *a
        noeud(noeud *a);


        //Destructeur
        ~noeud();


        //Accesseurs
        Elem getValue();
        noeud * getFils_g();
        noeud * getFils_d();
        int getHauteur();

        //modificateurs
        void changeFils_g(noeud* n);
        void changeFils_d(noeud* n);

        //Surcharge de l'affectation
        void operator= (noeud *a);
        //recherche
        //precondition : this et e initialisé
        //postcondition : retourne vrai si e est dans a, faux sinon
        bool recherche(Elem e);

        void majHauteur();
        bool checkDesequilibre();
        //Precondition : this est un sous-arbre AVL (équilibré)
        //Post-condition : e inséré, retourne le noeud déséquilibré le plus bas pour rééquilibre
        noeud** insertion(Elem e);

        //affichages :
        //Prefixe
        void affichePrefix();
        //Postfixe
        void affichePostfix();
        //Infixe
        void afficheInfix();
        //Infixe + affiche hauteur noeud
        void afficheInfixHauteur();
        //etat interne de l'arbre (affichage graphique)
        void afficheEtat();

        //affichages :
        //Prefixe);
        void affichePrefixRec();
        //Postfixe
        void affichePostfixRec();
        //Infixe
        void afficheInfixRec();
        //Postfixe + affiche hauteur noeud
        void affichePostfixHauteurRec();
        //Infixe + affiche hauteur noeud
        void afficheInfixHauteurRec();
        //Etat interne
        void afficheEtatRec(int indentation);

};

#endif
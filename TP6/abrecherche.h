#ifndef _ARBREBINAIRERECHERCHE
#define _ARBREBINAIRERECHERCHE
#include "element.h"

class abr
{
    private :
        Elem val;
        abr * fils_g;
        abr * fils_d;

    public :
        //Constructeurs 
        //par défaut
        //post-condtions : les fils sont nullptr, val=0
        abr();
        //post-condtions : les fils sont nullptr, val = e
        abr(Elem e);
        //par copie profonde
        //pre-condition : a initialisé
        //post-condition this est une copie profonde de *a
        abr(abr *a);


        //Destructeur
        ~abr();


        //Accesseurs
        Elem getValue();
        abr * getFils_g();
        abr * getFils_d();

        //Surcharge de l'affectation
        void operator= (abr *a);

        //insertion d'un Elem dans l'abr
        void insertion(Elem e);

        //recherche
        //precondition : this et e initialisé
        //postcondition : retourne vrai si e est dans a, faux sinon
        bool recherche(Elem e);

        //affichages :
        //infixe
        void affichePrefix();


};

#endif
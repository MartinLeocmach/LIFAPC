#ifndef _SKIPLISTE
#define _SKIPLISTE

#include "element.h"
#include <vector>

class skipList;

class Cellule
{
    friend class skipList;
    private :
        Elem info;
        std::vector<Cellule *> psuivant;

    public :
    //Destructeur
    ~Cellule();
};


class skipList
{
    public :
    //Constructeurs
    skipList();
    //Destructeur
    ~skipList();
    //pile ou face
    bool pile_ou_face ();
    //Insertion d'une cellule de valeur v
    void insertion (Elem v);
    //Affichage de la skipList
    void affiche ();
    //Suppression d'un élément
    void suppression (Elem v);
    private :
    Cellule *ad;
};

#endif
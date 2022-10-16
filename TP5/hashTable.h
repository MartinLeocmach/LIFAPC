#ifndef _HASHTABLE
#define _HASHTABLE
#include "product.h"

class hashTable;


class hashTable
{
    private :
    int taille;
    int nbElem;
    int (*hash)(key, int);
    int (*rehash)(int, int, int);
    product * tab[1000];

    public :
    //Constructeurs
    hashTable(int (*h)(key, int), int (*rh)(int, int, int));
    //Destructeur
    ~hashTable();

    //insertion
    void insertion(product *p);
    //suppression
    bool suppression(product *p);
    //recherche
    bool recherche(product *p);
    //affichages
    //affiche tous les éléments de la table : leur clé -> la valeur associée
    void afficheTable();
    /*affiche un élément de la table
    précondition : key la clé de l'élément recherché
    postcondition : - si élément dans la table 
                      affiche clé -> élément : nbr de rehachage 
                    - sinon
                      affiche "l'élément n'est pas dans la table"*/
    void afficheElement(key key);


    
};

#endif
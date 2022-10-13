#ifndef _HASHTABLE
#define _HASHTABLE


class hashTable;
typedef double value;
typedef unsigned int key;
struct product
{
    public :
    key k;
    value v;
    bool deleted;
};

class hashTable
{
    private :
    int taille;
    int nbElem;
    int (*hash)(key, int);
    int (*rehash)(int, key, int);
    product * tab[1000];

    public :
    //Constructeurs
    hashTable(int (*h)(key, int), int (*rh)(int, key, int));
    //Destructeur
    ~hashTable();
    //insertion
    void insertion(product *p);
    //suppression
    void suppression(product *p);
    //recherche
    bool recherche(product *p);



    
};

#endif
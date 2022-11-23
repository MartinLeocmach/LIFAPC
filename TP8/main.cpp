#include <iostream>
#include "arbreAVL.h"
#include "noeud.h"

int main ()
{
    Elem e1(9);
    Elem e2(5);
    AVL* a1 = new AVL(e1);
    AVL* a2 = new AVL();
    printf("initialisation AVL avec 9\n");
    a1->insertion(e2);
    printf("insertion 5\n");
    //AVL *a2 = new AVL(a1);
    e2 =11;
    a1->insertion(e2);
    a1->afficheInfixHauteur();
    e2 = 3;
    a1->insertion(e2);
    a1->afficheInfixHauteur();
    e2 = 4;
    a1->insertion(e2);
    //printf ("insertion 5\n");
    /*a1->affichePrefix();
    a1->affichePostfix();
    a1->afficheInfix();*/
    a1->afficheInfixHauteur();
    //a1->afficheEtat();
    printf("----------\nTest A2 :\n");
    for(int i=0; i<20; i++)
    {
        e1 = rand()%200;
        a2->insertion(e1);
        printf("insertion %d OK\n", e1.getValue());
    }
    a2->afficheInfixHauteur();
    printf("----------\nTest copie A2 dans A1 :\n");
    delete a1;
    a1 = new AVL(a2);
    a1->afficheInfixHauteur();
    return 0;
}
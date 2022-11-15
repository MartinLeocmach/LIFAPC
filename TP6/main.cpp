#include <iostream>
#include "abrecherche.h"
#include "noeud.h"

int main ()
{
    Elem e1(9);
    Elem e2(2);
    abr* a1 = new abr(e1);
    a1->insertion(e2);
    abr *a2 = new abr(a1);
    e2 = 5;
    a2->insertion(e2);
    *a1 = a2;
    e2 = 3;
    a1->insertion (e2);
    e2 = 12;
    a1->insertion(e2);
    a1->affichePrefix();
    a1->affichePostfix();
    a1->afficheInfix();
    //a1->afficheEtat();

    //Tests arbre cousu
    delete a1;
    printf("test arbre cousu \n");
    e1 = 17;
    a1 = new abr (e1);
    e1 = 9;
    a1->insertion(e1);
    e1 = 4;
    a1->insertion(e1);
    e1 = 10;
    a1->insertion(e1);
    e1 = 0;
    a1->insertion(e1);
    e1 = 6;
    a1->insertion(e1);
    e1 = 14;
    a1->insertion(e1);
    e1 = 2;
    a1->insertion(e1);
    e1 = 5;
    a1->insertion(e1);
    e1 = 8;
    a1->insertion(e1);
    e1 = 12;
    a1->insertion(e1);
    e1 = 16;
    a1->insertion(e1);
    e1 = 1;
    a1->insertion(e1);
    e1 = 3;
    a1->insertion(e1);
    e1 = 7;
    a1->insertion(e1);
    e1 = 11;
    a1->insertion(e1);
    e1 = 13;
    a1->insertion(e1);
    e1 = 15;
    a1->insertion(e1);
    e1 = 19;
    a1->insertion(e1);
    printf("affichage préfixe\n");
    a1->affichePrefix();
    printf("affichage infixe\n");
    a1->afficheInfix();
    printf("affichage postfixe\n");
    a1->affichePostfix();
    a1->coudre();
    //a1->affichePrefix();
    printf("affichage infixe après couture\n");
    a1->afficheInfix();
    //a1->affichePostfix();
    printf("affichage infixe itératif\n");
    a1->afficheCousu();
    e1 = 22;
    a1->insertionCousu(e1);
    e1 = 18;
    a1->insertionCousu(e1);
    printf("affichage infixe itératif\n");
    a1->afficheCousu();
    return 0;
}
#include <iostream>
#include "abrecherche.h"

int main ()
{
    Elem e1(9);
    Elem e2(2);
    abr* a1 = new abr(e1);
    a1->insertion(e2);
    abr *a2 = new abr (a1);
    e2.change_value(5);
    a2->insertion(e2);
    *a1 = a2;
    e2.change_value(3);
    a1->insertion (e2);
    a1->affichePrefix();
    return 0;
}
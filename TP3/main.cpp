#include <iostream>
#include "skipList.h"

int main ()
{
    skipList l;
    l.insertion(4);
    l.affiche();
    l.insertion(3);
    l.affiche();
    l.insertion(6);
    l.affiche();
    l.suppression(4);
    l.affiche();
    return 0;
}
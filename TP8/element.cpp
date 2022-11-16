// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio> 
#include "element.h"

Elem::Elem()
{
  entier = 0;
}

Elem::Elem (int n)
{
  this->entier  = n;
}

Elem::~Elem ()
{

}

void Elem::operator=(int n)
{
    this->entier = n;
}

bool Elem::operator<(Elem e)
{
  return(this->entier < e.entier);
}
void Elem::affichageElement()
{
  std::printf("%d ",entier);
}

int Elem::getValue()
{
  return entier;
}

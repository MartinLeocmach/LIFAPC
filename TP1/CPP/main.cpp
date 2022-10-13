// LIFAP6 - Automne 2017 - R. Chaine

#include "element.h"
#include "liste.h"
#include <cstdio>

int main()
{
  Liste lili;
  std::printf("Lili\n");
  lili.affichage();
  for(int i=1;i<5;i++)
    lili.ajoutEnTete(i);
  printf("Lili après ajout\n");
  lili.affichage();
  lili.suppressionEnTete();
  std::printf("Lili après suppr\n");
  lili.affichage();
  printf("taille lili : ");
  for(int i=10;i<15;i++)
  {
      lili.ajoutEnQueue(i);
  }
  std::printf("Lili\n");
  lili.affichage();
  //lili.rechercheElement(11);
  Liste lolo(lili);
  std::printf("Lolo\n");
  lolo.affichage();
  /*lili.vide();
  std::printf("Lolo\n");
  lolo.affichage();
  lolo=lili;
  printf("Lolo\n");
  lolo.affichage();*/
  return 0;
}

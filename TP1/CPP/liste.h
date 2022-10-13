// LIFAP6 - Automne 2017 - R. Chaine

#ifndef _LISTE
#define _LISTE

#include "element.h" //offrant le type Elem

class Liste; // declaration

class Cellule
{
    friend class Liste;

    private :
        Elem info;
        Cellule *psuivant;

    public :
        //Destructeur
        ~Cellule();
};

class Liste
{
    public :
    //Constructeurs-------------------------------------------------------------
    Liste();
    //Postcondition : la liste *this est  initialisée comme étant vide
    Liste(const Liste & l);
    //Postcondition :  la liste *this est initialisée en copie profonde de l
    //         (mais elles sont totalement independantes l'une de l'autre)

    //Destructeur---------------------------------------------------------------
    ~Liste();
     //Postcondition : l'espace occupé par *this  peut-être restitué

    //Affectation---------------------------------------------------------------
    Liste & operator = (const Liste & l);
    //Précondition : aucune
    //       (la liste *this à affecter et l doivent être initialisées)
    //Postcondition : la liste *this correspond à une copie profonde de l
    //           (mais elles sont totalement independantes l'une de l'autre)

    bool testVide() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : true si *this est vide, false sinon

    Elem premierElement() const;
    //Précondition : testListeVide(l)==false
    //Résultat : valeur de l'Elem contenu dans la 1ere Cellule

    Cellule * premiereCellule() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : adresse de la premiere cellule de *this si this->testVide()==false
    //           0 sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse de sa première cellule

    Cellule * celluleSuivante(const Cellule *pc) const;
    //Précondition : pc adresse valide d'une Cellule de la Liste *this
    //Résultat : adresse de la cellule suivante si elle existe
    //           0 sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse d'une de ses cellules

    Elem elementCellule(const Cellule * pc) const;
    //Précondition : pc adresse valide d'une Cellule de la Liste *this
    //Résultat : valeur de l'Elem contenu dans la Cellule

    void affichage() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Postcondition : Affichage exhaustif de tous les éléments de *this

    void ajoutEnTete(const Elem & e);
    //Précondition : aucune
    //               (*this et e initialisés)
    //Postcondition : L'Elem e est ajouté en tête de *this

    void suppressionEnTete();
    //Précondition : this->testVide()==false
    //Postcondition : la liste *this perd son premier élément

    void vide();
    //Précondition : aucune
    //               (*this initialisée)
    //Postcondition : this->testVide()==true (tous les éléments sont retirés)

    void ajoutEnQueue(const Elem & e);
    //Précondition : aucune
    //               (*this et e initialisés)
    //Postcondition : L'Elem e est ajouté en fin de la liste *this

    //OPERATIONS QUI POURRAIENT ETRE AJOUTEES AU MODULE LISTE

    Cellule * rechercheElement(const Elem & e) const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : Adresse de la première Cellule de *this contenant e, 0 sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse d'une de ses cellules

    void insereElementApresCellule(const Elem & e,Cellule *pc);
    //Précondition : pc adresse valide d'une Cellule de la Liste *this
    //               ou 0 si this->testVide()==true
    //Postcondition : l'element e est inseré après la Cellule pointée par pc

    void modifieInfoCellule(const Elem & e,Cellule *pc);
    //Precondition : *this non vide et pc adresse valide d'une Cellule de *this
    //Postcondition : l'info contenue dans *pc a pour valeur e

    private :
        void ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *pc);
    void affichageDepuisCellule(const Cellule * pc) const;
    //Donnees membres-----------------------------------------------------------
        Cellule *ad;
        int taille;
};


#endif

// LIFAP6 - Automne 2017 - R. Chaine
//====================================================================
// Nombres Complexes: implantation
//==================================================================== 

// nombreComplexe.cpp
// Implantation du module NombreComplexe offrant le type Complexe
// -> implantation des operations, procedures et fonctions
//    permettant de manipuler des Complexes,
// -> implantation des variables et constantes globales
//     offertes par le module
// -> l'implantation du type Complexe est malheureusement deja
//    dans l'interface...


// Modules utilises dans l'implantation
#include <iostream>
#include "reel.h" //offrant le type Reel

//On rajoute :
#include "nombreComplexe.h" //contenant la definition du type Complexe

// Definition constantes globales exportees
// ie. qui pourront etre utilisees dans d'autres modules
// s'ils importent le module NombreComplexe
const Reel PI=3.1425;

// Definition variables globales exportees
// Aucune ici

// Definition d'une variable globale non exportee
// (Utilisable uniquement dans le fichier NombreComplexe.cpp)
static int nbComplexe=0;

// Definition d'une fonction non exportee
// (Utilisable uniquement dans le fichier NombreComplexe.cpp)
static int exempleProcedureInterne()
{
    std::cout << "exempleProcedureInterne " << std::endl;
    return 1;
}

// Definition des constructeurs
Complexe::Complexe()
{
    std::cout << "Complexe::Complexe() " << std::endl;
    this->x=this->y=0;
    nbComplexe++;
}

Complexe::Complexe(const Complexe & c)
{
    std::cout << "Complexe::Complexe(const Complexe & c) " << std::endl;
    this->x=c.x; this->y=c.y;
    nbComplexe++;
}

Complexe::Complexe(const Reel & a,const Reel & b)
{
    std::cout << "Complexe::Complexe(const Reel & a,const Reel & b) "
    << std::endl;
    this->x=a;this->y=b;
    nbComplexe++;
}

// Definition du destructeur
Complexe::~Complexe()
{
    std::cout << "Complexe::~Complexe() " << std::endl;
    nbComplexe--;
}

// Definition affectation
Complexe & Complexe::operator = (const Complexe & c)
{
    std::cout << "Complexe::operator = (const Complexe & c) " << std::endl;
    if (this!=&c)
    {
        this->x=c.x;
        this->y=c.y;
    }
    return *this;
}

// Definition de affiche
void Complexe::affiche() const
{
    std::cout << "Affichage " << x <<"+i*" << y << std::endl;
}

/// Definition addition entre Complexes
Complexe operator +(const Complexe & c1,const Complexe & c2)
{
    std::cout << "operator +(const Complexe & c1,const Complexe & c2)"
    << std::endl;
    Complexe res(c1.getRe()+c2.getRe(),c1.getIm()+c2.getIm());
    return res;
}

std::ostream& operator<< (std::ostream& os, const Complexe& c)
{
    os << c.getRe() << "+i*" << c.getIm() << std::endl;
    return os;
}
std::istream& operator>> (std::istream& is, Complexe& c)
{
    Reel temp;
    is >> temp;
    c.setRe(temp);
    is >> temp;
    c.setIm(temp);
    return is;
}

//Definition Nombre de Complexes "vivants"
int nbComplexesVivants()
{
    std::cout << "nbComplexesVivants() " << std::endl;
    return nbComplexe;
}

//procedure test
void testPassageParValeur(Complexe c)
{
    std::cout << "testPassageParValeur(Complexe c) " << std::endl;
    std::cout << nbComplexesVivants() << std::endl;
    exempleProcedureInterne();
    c.affiche();
}

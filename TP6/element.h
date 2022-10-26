#ifndef _ELEMENT
#define _ELEMENT

class Elem
{
    private :
    int entier;

    public :
    Elem();
    Elem(int n);

    ~Elem();

    bool operator<(Elem e);
    int getValue ();

    void affichageElement();
    void change_value(int n);
};

#endif
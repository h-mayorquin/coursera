#include <iostream>
using namespace std;

class Rectangle{
public:
    double hateur;
    double largeur;
};


int main()
{
    Rectangle rect1;
    rect1.hateur = 3.0;
    rect1.largeur = 4.0;

    cout << "Hateur : " << rect1.hateur
	 << endl;

    return 0;
}

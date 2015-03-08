#include <iostream>
#include <utility> // pour la fonction swap
#include <string>
#include <vector>
using namespace std;

class Cellule
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
public:
    // We define the constructor
    Cellule(string nom="Pyrobacculum", double taille=10.0, int energie=5, string couleur="vert")
	: nom(nom), taille(taille), energie(energie), couleur(couleur)
    {}

    void affiche(){
	cout << nom;
	cout << ", taille = " << taille;
	cout << " microns, énergie = " << energie;
	cout << ", couleur = " << couleur << endl;

    }

    

public:
    string nom;
    double taille;
    int energie;
    string couleur;

};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Cellule assiette;
  cout << assiette.taille << endl;
  cout << assiette.nom << endl;
  cout << assiette.energie << endl;
  cout << assiette.couleur << endl;

  cout << "---------------" << endl;
  assiette.affiche();
      

  return 0;
}

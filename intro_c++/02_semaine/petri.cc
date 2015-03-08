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
    Petri(string nom="Pyrobacculum", double taille=10.0, int energie=5, string couleur="vert")
	: nom(nom), taille(taille), energie(energie), couleur(couleur)
    {}

private:
    string nom;
    double taille;
    int energie;
    sring couleur;

    

    cout << ", taille = " ;
    cout << " microns, énergie = " ;
    cout << ", couleur = " ;


};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Petri assiette;

  assiette.ajouter(Cellule());
  assiette.ajouter(Cellule("PiliIV", 4, 1, "jaune"));
  cout << "Population avant évolution :" << endl;
  assiette.affiche();

  assiette.evolue();
  cout << "Population après évolution :" << endl;
  assiette.affiche();

  return 0;
}

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
    Cellule(string nom="Pyrobacculum", double taille=10.0, int energie=5, string couleur="verte")
	: nom(nom), taille(taille), energie(energie), couleur(couleur)
    {}

    void affiche(){
	cout << nom;
	cout << ", taille = " << taille;
	cout << " microns, énergie = " << energie;
	cout << ", couleur = " << couleur << endl;

    }

    Cellule division(Cellule autre){
	
	string new_couleur;
	string old_couleur = autre.couleur;
	Cellule nouvelle;
	
	
	// Here we chose the new color based on the old one
	if (old_couleur == "verte"){
	    new_couleur = "bleue";
	    }

	if (old_couleur == "bleue"){
	    new_couleur = "rouge";
	    }


	if (old_couleur == "rouge"){
	    new_couleur = "rose bonbon";
	    }

	if (old_couleur == "violet"){
	    new_couleur = "verte";
	    }
	
	// If any option above was sattisfied
	if(new_couleur == ""){
	    new_couleur = old_couleur + " fluo";

	}



	cout << "Dividing celle" << endl;
	cout << "The old color: " << old_couleur << endl;
	cout << "The new color: " << new_couleur << endl;
	return autre;
    }
    
private:
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
    string couleur;
    string nom;
    double taille;
    int energy;
    Cellule assiette(nom="test", taille=5, energy=2, couleur="stuff");

    cout << "---------------" << endl;
    assiette.affiche();
    cout << "----------------" << endl;
    assiette.division(assiette);
      

  return 0;
}

#include <iostream>
#include <utility> // pour la fonction swap
#include <string>
#include <vector>
using namespace std;

q
class Cellule
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

private:
    string nom;
    double taille;
    int energie;
    string couleur;

public:
    // We define the constructor
    Cellule(string nom="Pyrobacculum", double taille=10.0, int energie=5, string couleur="verte")
	: nom(nom), taille(taille), energie(energie), couleur(couleur)
    {}

    // Setters and Getters 
    int get_energie() const { return energie; }
    string get_couleur() const{ return couleur; }
    
    void set_energie(int e) { energie = e; }
    void set_couleur(string c) { couleur = c; }
    void set_nom(string n) { nom = n; }
    void set_taille(double t) { taille = t; }
    

    void affiche(){
	cout << nom;
	cout << ", taille = " << taille;
	cout << " microns, énergie = " << energie;
	cout << ", couleur = " << couleur << endl;

    }

    Cellule division(){
	
	string new_couleur;
	string old_couleur = couleur;
	Cellule nouvelle;

	// Set the values of the new cell
	nouvelle.set_energie(energie);
	nouvelle.set_couleur(couleur);
	nouvelle.set_nom(nom);
	nouvelle.set_taille(taille);
 
	// Reduce the energy of the old cell
	energie = energie - 1;
	
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

	cout << new_couleur << endl;
	
	// If any option above was sattisfied
	if(new_couleur == ""){
	    new_couleur = old_couleur + " fluo";

	}

	cout << new_couleur << endl;

	// Modify te color
	nouvelle.set_couleur(new_couleur);

	
	return nouvelle;

	
    }
    

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
    Cellule copy;

    cout << "---------------" << endl;
    assiette.affiche();
    cout << "----------------" << endl;
    copy = assiette.division();
    cout << "----------------" << endl;
    copy.affiche();
      

  return 0;
}

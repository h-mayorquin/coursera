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
	Cellule nouvelle = autre;

	// Reduce the energy of the old cell
	this -> energie = autre.energie - 1;
	
	
	
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

	// Modify te color
	nouvelle.couleur = new_couleur;
	
	return nouvelle;
    }
    
private:
    string nom;
    double taille;
    int energie;
    string couleur;

};


class Petri
{
public:
    // Method ajouter
    void ajouter(Cellule cellule){
	population.push_back(cellule);
    }
    // Method Afficher
    void affiche(){
	int N_size = population.size();
	int i;
	
	for(i=0; i < N_size; ++i){
	    population[i].affiche();
	}
	    
	
    }

    // Method Evoluer 
    void evolue(){
	Cellule new_cell;
	int N_initial = population.size();
	int i;

	// First we divide the new cells
	for(i=0; i < N_initial; ++i){
	    new_cell = population[i].division(population[i]);
	    population.push_back(new_cell);			    
	}

	int N_final = population.size();
	cout << "Initial population " << N_initial << endl;
	cout << "Final population " << N_final << endl;
	

    }
private:    
    vector<Cellule> population;

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
  assiette.affiche(); // Get rid of this
  //  cout << "Population après évolution :" << endl;
  //  assiette.affiche();

  return 0;
}

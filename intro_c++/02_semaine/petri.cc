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

	// If any option above was sattisfied
	if(new_couleur == ""){
	    new_couleur = old_couleur + " fluo";

	}

	// Modify te color
	nouvelle.set_couleur(new_couleur);

	
	return nouvelle;

	
    }
    

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
	int energy; 
	vector<int> to_eliminate;
	int N_eli; 

	int N_initial = population.size();
	int i;

	// First we divide the new cells
	for(i=0; i < N_initial; ++i){
	    new_cell = population[i].division();
	    population.push_back(new_cell);			    
	}
	
	// Population after division 
	int N_final = population.size();

	// Now we get rid of the ones without energy
	
	// First we get the indexes of those who are 0 
	for(i=0; i < N_final; ++i){
	    energy = population[i].get_energie();
	    if (energy == 0){
		to_eliminate.push_back(i);
	    }
	}
	
	// Now we eliminate them 
	N_eli = to_eliminate.size();
	for(i=0; i < N_eli ; ++i){
	    // cout << to_eliminate[i] << endl;
	    swap(population[to_eliminate[i]], population.back());
	    population.pop_back();
	}
	
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
  cout << "Population après évolution :" << endl;
  assiette.affiche();

  return 0;
}

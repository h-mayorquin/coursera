#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 ****************************************************/

class Patient{
public:
    // Method defintions
    
    double init(double x, double y){
	if (x > 0 && y > 0){
	    poids_ = x;
	    taille_ = y;
	}else{
	    poids_ = 0;
	    taille_ = 0;
	}
    }
    double poids() {return poids_;}
    double taille() {return taille_;}
    double setPoids(double x){poids_ = x;}
    double setTaille(double x){taille_ = x;}
    void afficher(){
	cout << "Patient : " << poids_ << " kg ";
	cout << "pour " << taille_ << " m" << endl;
	
    }

    double imc(){
	if(taille_ != 0){
	    return poids_ / (taille_ * taille_);
	}else{
	    return 0;
	}
    }
        
    double poids_;
    double taille_;
    
};


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}

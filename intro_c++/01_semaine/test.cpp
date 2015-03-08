#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient{
public:
    // Method defintions
    
    double init(double x, double y){
	poids = x;
	taille = y;
    }
    double getPoids() const {return this->poids;}
    double getTaille() const{return this->taille;}
    double setPoids(double x){this->poids = x;}
    double setTaille(double x){this->taille = x;}
        
    double poids;
    double taille;
    
};
    

int main(){
    Patient patient;
    double poids = 3.0;
    double taille = 2.0;

    patient.init(poids, taille);
    cout << "Le pois c'est " << patient.getPoids() << endl;
    cout << "Le taille c'est " << patient.getTaille() << endl;

    return 0;
}

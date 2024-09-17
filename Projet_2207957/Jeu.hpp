#pragma once

#include "Connexions.hpp"
#include "Commande.hpp"
#include "Directions.hpp"
#include <iostream>
#include <string>

using namespace std;

class Jeu {
public:
    Jeu();
    void afficherInformations();
    bool traiterCommande(const string& commande);
    void demarrer();
    void regarderObjet(const string& mot);
    void utiliserObjet(const string& mot);
    string conversion(Direction direction);
    Direction conversionDirection(const string& entree);
    Commande conversionCommande(const string& entree);

private:
    Connexions gestionnaire_;
    Emplacement* emplacementCourant_;
    
};

#pragma once

#include "Objet.hpp"
#include "Directions.hpp"
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

class Emplacement {
public:
    Emplacement(const string& nom, const string& description, bool estEclaire);
    virtual ~Emplacement();

    string getNom() const;
    string getDescription() const;
    Emplacement* obtenirVoisin(Direction direction);

    const map<Direction, Emplacement*>& getVoisins() const;
    void ajouterVoisin(Direction direction, Emplacement* emplacement);

    void ajouterObjet(Objet* objet);
    vector<Objet*> decrireObjets() const;

    bool changerEclairage();
    bool estEclaire() const;

protected:
    string nom_;
    string description_;
    map<Direction, Emplacement*> voisins_;
    vector<unique_ptr<Objet>> objets_;
    bool estEclaire_;
};

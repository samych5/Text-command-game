#pragma once

#include "Objet.hpp"
#include "Emplacement.hpp"

class Interrupteur : public Objet {

public:
    Interrupteur(const string& nom, const string& description, Emplacement* emplacementLie)
        : Objet(nom, description), emplacementLie_(emplacementLie) {}

    string utiliser() override {
        bool nouvelEtatEclairage = emplacementLie_->changerEclairage();
        string etatEclairageStr = nouvelEtatEclairage ? "allumee." : "eteinte.";
        return "La lumiere de la " + emplacementLie_->getNom() + " a ete " + etatEclairageStr;
    }




private:
    Emplacement* emplacementLie_; 
};

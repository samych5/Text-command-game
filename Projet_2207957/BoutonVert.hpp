#pragma once

#include "Objet.hpp"
#include "Emplacement.hpp"
#include "Directions.hpp"

class BoutonVert : public Objet {
public:
    BoutonVert(const string& nom, const string& description, Emplacement* embarquement, Emplacement* salonVip)
        : Objet(nom, description), embarquement_(embarquement), salonVip_(salonVip) {}

    string utiliser() override {
        if (!embarquement_->obtenirVoisin(Direction::Est)) {
            embarquement_->ajouterVoisin(Direction::Est, salonVip_);
            return "JACKPOT!. Vous venez d'ouvrir un passage vers le salon vip.";
        }
        else {
            return "La salle est deja accessible. ";
        }
    }

private:
    Emplacement* embarquement_;
    Emplacement* salonVip_;
};

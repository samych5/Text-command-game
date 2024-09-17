#pragma once

#include "Objet.hpp"

class Valise : public Objet {
public:
    Valise(const string& nom, const string& description)
        : Objet(nom, description) {}

    string utiliser() override {
        return "Vous ouvrez la valise. Un autre passager vous crie dessus pour avoir ouvert sa valise.";
    }
};

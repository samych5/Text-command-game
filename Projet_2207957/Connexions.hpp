#pragma once

#include "Emplacement.hpp"
#include "BoutonVert.hpp"
#include "Valise.hpp"
#include "Interrupteur.hpp"
#include "Directions.hpp"

#include <memory>
#include <map>

using namespace std;

class Connexions {
public:
    Connexions();

    unique_ptr<Emplacement>& obtenirEmplacement(const string& nom);
    void initialiserEmplacements();
    void etablirConnexions();

private:
    map<string, unique_ptr<Emplacement>> emplacements_;
};

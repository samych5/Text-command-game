#include "Emplacement.hpp"

Emplacement::Emplacement(const string& nom, const string& description, bool estEclaire)
    : nom_(nom), description_(description), estEclaire_(estEclaire) {}

Emplacement::~Emplacement() {}

string Emplacement::getNom() const {
    return nom_;
}

string Emplacement::getDescription() const {
    return description_;
}

Emplacement* Emplacement::obtenirVoisin(Direction direction) {
    auto it = voisins_.find(direction);
    if (it != voisins_.end()) {
        return it->second;
    }
    return nullptr;
}

const map<Direction, Emplacement*>& Emplacement::getVoisins() const {
    return voisins_;
}

void Emplacement::ajouterVoisin(Direction direction, Emplacement* emplacement) {
    voisins_[direction] = emplacement;
}

void Emplacement::ajouterObjet(Objet* objet) {
    objets_.push_back(unique_ptr<Objet>(objet));
}

vector<Objet*> Emplacement::decrireObjets() const {
    vector<Objet*> descriptions;
    for (const auto& objet : objets_) {
        descriptions.push_back(objet.get());
    }
    return descriptions;
}

bool Emplacement::changerEclairage() {
    estEclaire_ = !estEclaire_;
    return estEclaire_;
}

bool Emplacement::estEclaire() const {
    return estEclaire_;
}

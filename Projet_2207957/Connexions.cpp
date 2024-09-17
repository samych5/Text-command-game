#include "Connexions.hpp"

Connexions::Connexions() {
    initialiserEmplacements();
    etablirConnexions();
}

void Connexions::initialiserEmplacements() {
    emplacements_["entree"] = make_unique<Emplacement>("Entree",
        "Vous etes a l'entree de l'aeroport. Beaucoup de voyageurs sont la.\n", true);

    emplacements_["restaurants"] = make_unique<Emplacement>("Restaurants",
        "Vous etes dans la zone resto. Plusieurs choix de restaurants s'offrent a vous.\n", true);

    emplacements_["enregistrement"] = make_unique<Emplacement>("Enregistrement",
        "Vous etes aux comptoirs d'enregistrement. Une longue file vous attends pour enregistrer vos bagages.\n", true);

    emplacements_["securite"] = make_unique<Emplacement>("Securite",
        "Vous etes a la securite. Plusieurs douaniers sont aux aguets pour assurer votre securite.\n", false);

    emplacements_["embarquement"] = make_unique<Emplacement>("Embarquement",
        "Vous etes en salle d'embarquement, Beaucoup de gens se precipitent pour monter dans l'avion mais il y a de la place pour tous le monde.\n", true);

    emplacements_["Salon vip"] = make_unique<Emplacement>("Salon vip",
        "Vous etes dans le salon VIP. Le bar vous attends, detendez-vous avant votre vol.\n", true);

    auto boutonVert = make_unique<BoutonVert>(
        "Bouton Vert", "Un bouton vert tres bien cache.",
        emplacements_["embarquement"].get(), emplacements_["Salon vip"].get());
    emplacements_["securite"]->ajouterObjet(boutonVert.release());

    auto valise = make_unique<Valise>("Valise", "Une vieille valise dechire.");
    emplacements_["securite"]->ajouterObjet(valise.release());

    auto interrupteur = make_unique<Interrupteur>("Interrupteur", "Un gros interrupteur qui ne passe pas inapercu.", emplacements_["securite"].get());
    emplacements_["entree"]->ajouterObjet(interrupteur.release());
}

void Connexions::etablirConnexions() {
    auto& entree = emplacements_["entree"];
    entree->ajouterVoisin(Direction::Nord, emplacements_["securite"].get());
    entree->ajouterVoisin(Direction::Est, emplacements_["enregistrement"].get());
    entree->ajouterVoisin(Direction::Ouest, emplacements_["restaurants"].get());

    auto& restaurants = emplacements_["restaurants"];
    restaurants->ajouterVoisin(Direction::Est, emplacements_["entree"].get());

    auto& enregistrement = emplacements_["enregistrement"];
    enregistrement->ajouterVoisin(Direction::Ouest, emplacements_["entree"].get());

    auto& securite = emplacements_["securite"];
    securite->ajouterVoisin(Direction::Sud, emplacements_["entree"].get());
    securite->ajouterVoisin(Direction::Nord, emplacements_["embarquement"].get());

    auto& embarquement = emplacements_["embarquement"];
    embarquement->ajouterVoisin(Direction::Sud, emplacements_["securite"].get());

    emplacements_["Salon vip"]->ajouterVoisin(Direction::Ouest, emplacements_["embarquement"].get());
}

unique_ptr<Emplacement>& Connexions::obtenirEmplacement(const string& nom) {
    return emplacements_[nom];
}

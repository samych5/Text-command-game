#include "Jeu.hpp"

Jeu::Jeu() {
    emplacementCourant_ = gestionnaire_.obtenirEmplacement("entree").get();
}

void Jeu::afficherInformations() {
    cout << "--- " << emplacementCourant_->getNom() << " ---\n";
    if (emplacementCourant_->estEclaire()) {
        cout << emplacementCourant_->getDescription() << "\n";

        auto objets = emplacementCourant_->decrireObjets();
        if (!objets.empty()) {
            cout << "Vous remarquez les objets suivants :\n";
            for (const auto& objet : objets) {
                cout << "- " << objet->getNom() << "\n";
            }
        }
    }
    else {
        cout << "Il fait trop noir, on peut rien voir.\n";
    }

    const auto& voisins = emplacementCourant_->getVoisins();
    if (!voisins.empty()) {
        cout << "A partir de cet endroit, vous pouvez aller dans ces directions : \n";
        for (const auto& pair : voisins) {
            cout << "- " << conversion(pair.first) << " vers " << pair.second->getNom() << "\n";
        }
    }
}

string Jeu::conversion(Direction direction) {
    switch (direction) {
    case Direction::Nord: return "Nord";
    case Direction::Sud: return "Sud";
    case Direction::Est: return "Est";
    case Direction::Ouest: return "Ouest";
    default: return "Invalide";
    }
}

Direction Jeu::conversionDirection(const string& entree) {
    if (entree == "N") return Direction::Nord;
    if (entree == "S") return Direction::Sud;
    if (entree == "E") return Direction::Est;
    if (entree == "O") return Direction::Ouest;
    return Direction::Invalide;
}

Commande Jeu::conversionCommande(const string& entree) {
    if (entree == "regarder") return Commande::Regarder;
    else if (entree.substr(0, 9) == "regarder ") return Commande::Regarder;
    else if (entree.substr(0, 9) == "utiliser ") return Commande::Utiliser;
    else if (entree == "N" || entree == "S" || entree == "E" || entree == "O") return Commande::Deplacer;
    return Commande::Inconnue;
}

void Jeu::regarderObjet(const string& mot) {
    for (const auto& objet : emplacementCourant_->decrireObjets()) {
        if (objet->getNom().find(mot) != string::npos) {
            cout << objet->getDescription() << "\n";
            return;
        }
    }
    cout << "Objet inexistant.\n";
}

void Jeu::utiliserObjet(const string& mot) {
    for (const auto& objet : emplacementCourant_->decrireObjets()) {
        if (objet->getNom().find(mot) != string::npos) {
            cout << objet->utiliser() << "\n";
            return;
        }
    }
    cout << "Objet inexistant.\n";
}

bool Jeu::traiterCommande(const string& commande) {
    Commande cmd = conversionCommande(commande);
    if (cmd == Commande::Regarder) {
        if (commande.size() > 9) {
            string mot = commande.substr(9);
            regarderObjet(mot);
        }
        else {
            afficherInformations();
        }
        return true;
    }
    else if (cmd == Commande::Utiliser) {
        string mot = commande.substr(9);
        utiliserObjet(mot);
        return true;
    }
    else if (cmd == Commande::Deplacer) {
        Direction dir = conversionDirection(commande);
        Emplacement* prochainEmplacement = emplacementCourant_->obtenirVoisin(dir);
        if (prochainEmplacement) {
            emplacementCourant_ = prochainEmplacement;
            afficherInformations();
        }
        else {
            cout << "On ne peut pas aller dans cette direction.\n";
        }
        return true;
    }
    else {
        cout << "Commande inconnue.\n";
        return false;
    }
}

void Jeu::demarrer() {
    string commande;
    cout << "----------------  LE VOYAGE ULTIME ----------------\n";
    cout << "Voici les commandes du jeu : \n"
        "-- Pour aller dans une direction, tapez la premiere lettre du point cardinal en majuscule. \n"
        "regarder: pour reafficher les details de la piece dans laquelle vous etes. \n"
        "regarder + le nom de l'objet: afficher la description de l'objet. \n"
        "utiliser + le nom de l'objet: interragir avec l'objet. \n"
        "quitter: pour quitter le jeu. \n";
    afficherInformations();

    while (true) {
        cout << "> ";
        getline(cin, commande);

        if (commande == "quitter") {
            cout << "Au plaisir de vous revoir!\n";
            break;
        }
        traiterCommande(commande);
    }
}

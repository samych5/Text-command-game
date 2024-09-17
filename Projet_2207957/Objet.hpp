#pragma once

#include <string>

using namespace std;

class Objet {

public:
    Objet(const string& nom, const string& description)
        : nom_(nom), description_(description) {}

    virtual ~Objet() {}

    virtual string utiliser() = 0; 

    string getNom() const { return nom_; }
    string getDescription() const { return description_; }

protected:
    string nom_;
    string description_;
};

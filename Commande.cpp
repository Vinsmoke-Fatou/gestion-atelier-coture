//
// Created by sambf on 1/30/2026.
//

#include "Commande.h"

#include <iostream>
#include <stdexcept>

using namespace std;

// Constructeur
Commande::Commande(int id, Client* client, Tissu* tissu, double metres, const string& desc, bool terminee)
    : m_id(id), m_client(client), m_tissu(tissu), m_metresNecessaires(metres), m_description(desc), m_terminee(terminee)
{
    if (id <= 0) throw invalid_argument("ID commande doit être > 0");
    if (client == nullptr) throw invalid_argument("La commande doit avoir un client");
    if (tissu == nullptr) throw invalid_argument("La commande doit avoir un tissu");
    if (metres <= 0) throw invalid_argument("La quantite de tissu doit être > 0");
    if (desc.empty()) throw invalid_argument("La description ne peut pas être vide");
}

// Destructeur
Commande::~Commande() {

}

// Accesseurs
int Commande::getId() const {
    return m_id;
}
Client* Commande::getClient() const {
    return m_client;
}
Tissu* Commande::getTissu() const {
    return m_tissu;
}
double Commande::getMetresNecessaires() const {
    return m_metresNecessaires;
}
string Commande::getDescription() const {
    return m_description;
}
bool Commande::getTerminee() const {
    return m_terminee;
}

// Mutateurs
void Commande::setTerminee(bool etat) {
    m_terminee = etat;
}

// Calcul du prix
double Commande::calculerPrix() const {
    return m_metresNecessaires * m_tissu->getPrixAuMetre();
}

// Operateurs
ostream& operator<<(ostream& os, const Commande& c) {
    os << "Commande #" << c.m_id << " [" << (c.m_terminee ? "TERMINEE" : "EN COURS") << "\n"
       << "  Client : " << c.m_client->getNom() << " " << c.m_client->getPrenom() << "\n"
       << "  Habit  : " << c.m_description << "\n"
       << "  Tissu  : " << c.m_tissu->getNom() << " (" << c.m_metresNecessaires << "m)" << "\n"
       << "  Prix   : " << c.calculerPrix() << " Fcfa" << endl;
    return os;
}

istream& operator>>(istream& is, Commande& c) {
    cout << "Description de l'habit : ";
    getline(is >> ws, c.m_description);

    cout << "Mètres necessaires : ";

    is >> c.m_metresNecessaires;
    return is;
}

bool operator==(const Commande& c1, const Commande& c2) {
    return c1.m_id == c2.m_id;
}
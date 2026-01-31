//
// Created by sambf on 1/30/2026.
//

#include "Atelier.h"
#include <iostream>


using namespace std;

Atelier::Atelier(const string& nom) : m_nom(nom) {}


Atelier::~Atelier() {
    for (size_t i = 0; i < m_clients.size(); ++i) delete m_clients[i];
    for (size_t i = 0; i < m_couturiers.size(); ++i) delete m_couturiers[i];
    for (size_t i = 0; i < m_tissus.size(); ++i) delete m_tissus[i];
    for (size_t i = 0; i < m_commandes.size(); ++i) delete m_commandes[i];
    for (size_t i = 0; i < m_habitsTermines.size(); ++i) delete m_habitsTermines[i];
}

// GESTION DES CLIENTS
void Atelier::ajouterClient(Client* c) {
    if (c != nullptr) m_clients.push_back(c);
}

Client* Atelier::trouverClient(int id) const {
    for (size_t i = 0; i < m_clients.size(); ++i) {
        if (m_clients[i]->getId() == id) return m_clients[i];
    }
    return nullptr;
}



// GESTION DES COUTURIERS
void Atelier::ajouterCouturier(Couturier* c) {
    if (c != nullptr) m_couturiers.push_back(c);
}

Couturier* Atelier::trouverCouturier(int id) const {
    for (size_t i = 0; i < m_couturiers.size(); ++i) {
        if (m_couturiers[i]->getId() == id) return m_couturiers[i];
    }
    return nullptr;
}


void Atelier::afficherTousCouturiers() const {
    cout << "--- Liste des Couturiers de l'atelier " << m_nom << " ---" << endl;
    for (size_t i = 0; i < m_couturiers.size(); ++i) {
        m_couturiers[i]->afficher(cout);
        cout << "-------------------------------------------" << endl;
    }
}

void Atelier::afficherSalairesEquipe(double heures) const {
    cout << "--- SALAIRES DE L'EQUIPE POUR " << heures << " HEURES DE TRAVAIL ---" << endl;

    if (m_couturiers.empty()) {
        cout << "Aucun couturier dans l'atelier." << endl;
    } else {
        for (size_t i = 0; i < m_couturiers.size(); ++i) {
            cout << "Couturier : " << m_couturiers[i]->getPrenom() << " " << m_couturiers[i]->getNom() << endl;
            cout << " > Salaire : " << m_couturiers[i]->calculerSalaire(heures) << " Fcfa" << endl;
            cout << "-----------------------------------" << endl;
        }
    }
}

// GESTION DES TISSUS
void Atelier::ajouterTissu(Tissu* t) {
    if (t != nullptr) m_tissus.push_back(t);
}

Tissu* Atelier::trouverTissu(int id) const {
    for (size_t i = 0; i < m_tissus.size(); ++i) {
        if (m_tissus[i]->getId() == id) return m_tissus[i];
    }
    return nullptr;
}

void Atelier::afficherTousTissus() const {
    cout << "\n========== INVENTAIRE DES TISSUS ==========" << endl;

    for (size_t i = 0; i < m_tissus.size(); ++i) {
        cout << *(m_tissus[i]);
        cout << "-------------------------------------------" << endl;
    }
    cout << "===========================================\n" << endl;
}

// GESTION DES COMMANDES
void Atelier::ajouterCommande(Commande* co) {
    if (co != nullptr) m_commandes.push_back(co);
}

// GESTION DES HABITS TERMINES
void Atelier::ajouterHabilleTermine(habilleTermine* ht) {
    if (ht != nullptr) m_habitsTermines.push_back(ht);
}

// Operateurs
ostream& operator<<(ostream& os, const Atelier& a) {
    os << "ATELIER : " << a.m_nom << "\n"
       << "Nombre de clients    : " << a.m_clients.size() << "\n"
       << "Nombre de couturiers  : " << a.m_couturiers.size() << "\n"
       << "Nombre de tissus      : " << a.m_tissus.size() << "\n"
       << "Nombre de commandes   : " << a.m_commandes.size() << "\n"
       << "Habits termines       : " << a.m_habitsTermines.size() << endl;
    return os;
}

Client& Atelier::operator[](int id) {
    Client* c = trouverClient(id);
    if (c == nullptr) throw runtime_error("Client non trouve");
    return *c;
}

Couturier& Atelier::operator()(int id) {
    Couturier* c = trouverCouturier(id);
    if (c == nullptr) throw runtime_error("Couturier non trouve");
    return *c;
}


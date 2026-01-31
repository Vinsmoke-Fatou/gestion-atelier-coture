//
// Created by sambf on 1/30/2026.
//

#include "Tissu.h"
#include <iostream>
using namespace std;

Tissu::Tissu(int id, const std::string &nom, const std::string &couleur, double prixAuMetre, double quantiteStock)
    :m_id(id), m_nom(nom), m_couleur(couleur), m_prixAuMetre(prixAuMetre), m_quantiteStock(quantiteStock)
{
    if (id <= 0) throw invalid_argument("L'ID doit être > 0");

    if (nom.empty()) throw invalid_argument("Le nom ne peut pas être vide");

    if (couleur.empty()) throw invalid_argument("La couleur ne peut pas être vide");

    if (prixAuMetre <= 0) throw invalid_argument("Le Prix au metre doit être > 0");

    if (quantiteStock < 0) throw invalid_argument("La Quantite en stock doit être >= 0");

}

Tissu::~Tissu() {
}

int Tissu::getId() const {
    return m_id;
}

string Tissu::getNom() const {
    return m_nom;
}

string Tissu::getCouleur() const {
    return m_couleur;
}

double Tissu::getPrixAuMetre() const {
    return m_prixAuMetre;
}

double Tissu::getQuantiteStock() const {
    return m_quantiteStock;
}

void Tissu::setPrixAuMetre(double prixAuMetre) {
    if (prixAuMetre <= 0) throw invalid_argument("Le Prix au metre doit être > 0");

    m_prixAuMetre = prixAuMetre;
}

void Tissu::ajouterStock(double quantite) {
    if (quantite < 0) throw invalid_argument("La Quantite doit être >= 0");
    m_quantiteStock += quantite;
}

void Tissu::retirerStock(double quantite) {
    if (quantite < 0) throw invalid_argument("La Quantite doit être >= 0");
    if (m_quantiteStock < quantite) throw invalid_argument("Stock insuffisant");
    m_quantiteStock -= quantite;
}

ostream& operator<<(ostream& os, const Tissu& t) {
    os << "Tissu #" << t.m_id << " : " << "\n"
       << t.m_nom << " " << t.m_couleur << "\n"
       << " | Prix au Metre: " << t.m_prixAuMetre << "Fcfa/m" << "\n"
       << " | Quantite en stock: " << t.m_quantiteStock << endl;
    return os;
}

istream& operator>>(istream& is, Tissu& t) {
    cout << "=== Saisie d'un tissu ===" << endl;

    string nom, couleur;
    double prixAuMetre, quantiteStock;

    cout << "Nom du tissu: ";
    getline(is >> ws, nom);

    cout << "Couleur: ";
    getline(is >> ws, couleur);

    cout << "Prix au mètre: ";
    is >> prixAuMetre;

    cout << "Quantite en stock: ";
    is >> quantiteStock;

    if (nom.empty()) throw invalid_argument("Le nom ne peut pas être vide");
    if (couleur.empty()) throw invalid_argument("La couleur ne peut pas être vide");
    if (prixAuMetre <= 0) throw invalid_argument("Le Prix au metre doit être > 0");
    if (quantiteStock < 0) throw invalid_argument("La quantite en stock doit être >= 0");

    t.m_nom = nom;
    t.m_couleur = couleur;
    t.setPrixAuMetre(prixAuMetre);
    t.m_quantiteStock = quantiteStock;

    return is;
}

bool operator==(const Tissu &t1, const Tissu &t2) {
    return t1.m_id == t2.m_id;
}

bool operator!=(const Tissu &t1, const Tissu &t2) {
    return t1.m_id != t2.m_id;
}

Tissu &operator+=(Tissu &t, double quantite) {
    t.ajouterStock(quantite);
    return t;
}

Tissu &operator-=(Tissu &t, double quantite) {
    t.retirerStock(quantite);
    return t;

}

//
// Created by sambf on 1/30/2026.
//

#include "Personnes.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// ========== PERSONNE ==========

Personne::Personne(int id, const string& nom, const string& prenom, const string& tel): m_id(id), m_nom(nom), m_prenom(prenom), m_tel(tel)
{
    if (id <= 0) throw invalid_argument("L'ID doit être > 0");
    if (nom.empty())throw invalid_argument("Le nom ne peut pas être vide");
    if (prenom.empty()) throw invalid_argument("Le prenom ne peut pas être vide");
    if (tel.empty()) throw invalid_argument("Le telephone ne peut pas être vide");
}

Personne::~Personne() {
}

int Personne::getId() const {
    return m_id;
}

string Personne::getNom() const {
    return m_nom;
}

string Personne::getPrenom() const {
    return m_prenom;
}

string Personne::getTel() const {
    return m_tel;
}

void Personne::setNom(const string& nom) {
    if (nom.empty()) throw invalid_argument("Le nom ne peut pas être vide");
    m_nom = nom;
}

void Personne::setPrenom(const string& prenom) {
    if (prenom.empty()) throw invalid_argument("Le prenom ne peut pas être vide");
    m_prenom = prenom;
}

void Personne::setTel(const string& tel) {
    if (tel.empty()) throw invalid_argument("Le telephone ne peut pas être vide");
    m_tel = tel;
}

void Personne::afficher(ostream& os) const {
    os << "Personne #" << m_id << " : " << "\n"
       << m_prenom << " " << m_nom << "\n"
       << " | Tel: " << m_tel << endl;
}

ostream& operator<<(ostream& os, const Personne& p) {
    p.afficher(os);
    return os;
}

istream& operator>>(istream& is, Personne& p) {
    string nom, prenom, tel;
    cout << "Nom: ";
    getline(is >> ws, nom);
    cout << "Prenom: ";
    getline(is >> ws, prenom);
    cout << "Telephone: ";
    getline(is >> ws, tel);

    p.setNom(nom);
    p.setPrenom(prenom);
    p.setTel(tel);


    return is;
}

bool operator==(const Personne& p1, const Personne& p2) {
    return p1.m_id == p2.m_id;
}

bool operator!=(const Personne& p1, const Personne& p2) {
    return !(p1 == p2);
}



// ========== CLIENT ==========
// Constructeur
Client::Client(int id, const string& nom, const string& prenom,
               const string& tel, const string& adresse): Personne(id, nom, prenom, tel),m_adresse(adresse),m_nombreCommandes(0)
{
    if (adresse.empty()) throw invalid_argument("L'adresse ne peut pas être vide");
}

// Destructeur
Client::~Client() {

}

// Afficher
void Client::afficher(ostream& os) const {
    os << "Client #" << m_id << " : " << "\n"
       << m_prenom << " " << m_nom << "\n"
       << " | Tel: " << m_tel << "\n"
       << " | Adresse: " << m_adresse << "\n"
       << " | Commandes: " << m_nombreCommandes << "\n";
}

// Accesseurs
string Client::getAdresse() const {
    return m_adresse;
}

int Client::getNbCommandes() const {
    return m_nombreCommandes;
}

// Mutateurs
void Client::setAdresse(const string& adresse) {
    if (adresse.empty()) throw invalid_argument("L'adresse ne peut pas être vide");
    m_adresse = adresse;
}

void Client::incrementerCommandes() {
    m_nombreCommandes++;
}

// Operateurs
ostream& operator<<(ostream& os, const Client& c) {
    c.afficher(os);
    return os;
}

istream& operator>>(istream& is, Client& c) {
    cout << "=== Saisie d'un client ===" << endl;

    string adresse;

    is >> static_cast<Personne&>(c);

    cout << "Adresse: ";
    getline(is >> ws, adresse);

    c.setAdresse(adresse);

    return is;
}


// ========== COUTURIER ==========
// Constructeur
Couturier::Couturier(int id, const string& nom, const string& prenom, const string& tel, const string& specialite, double tarifHoraire)
    :Personne(id, nom, prenom, tel),m_specialite(specialite), m_tarifHoraire(tarifHoraire)
{
    if (specialite.empty()) throw invalid_argument("La specialite ne peut pas être vide");
    if (tarifHoraire <= 0) throw invalid_argument("Le Tarif horaire ne peut pas etre negatif");
}

//Destructeur
Couturier::~Couturier() {

}

// Afficher
void Couturier::afficher(ostream& os) const {
    os << "Couturier #" << m_id << " : " << "\n"
       << m_prenom << " " << m_nom << "\n"
       << " | Tel: " << m_tel << "\n"
       << " | Specialite: " << m_specialite << "\n"
       << " | Tarif Horaire: " << m_tarifHoraire << "Fcfa/h"  << endl;
}

// Accesseurs
string Couturier::getSpecialite() const {
    return m_specialite;
}

double Couturier::getTarifHoraire() const {
    return m_tarifHoraire;
}

// Mutateurs
void Couturier::setSpecialite(const string& specialite) {
    if (specialite.empty()) throw invalid_argument("La specialite ne peut pas être vide");
    m_specialite = specialite;
}

void Couturier::setTarifHoraire(double tarifHoraire) {
    if (tarifHoraire <= 0) throw invalid_argument("Le Tarif horaire ne peut pas etre negatif");
    m_tarifHoraire = tarifHoraire;
}

//Calcule du salaire
double Couturier::calculerSalaire(int heures) const {
    return m_tarifHoraire * heures;
}

// Operateurs
ostream& operator<<(ostream& os, const Couturier& c) {
    c.afficher(os);
    return os;
}

istream& operator>>(istream& is, Couturier& c) {
    cout << "=== Saisie d'un Couturier ===" << endl;

    string specialite;
    double tarifHoraire;

    is >> static_cast<Personne&>(c);

    cout << "Specialite: ";
    getline(is >> ws, specialite);

    cout << "Tarif horaire: ";
    is >> tarifHoraire;


    c.setSpecialite(specialite);
    c.setTarifHoraire(tarifHoraire);

    return is;
}


// ========== COUTURIER SENIOR ==========
// Constructeur
CouturierSenior::CouturierSenior(int id, const string& nom, const string& prenom, const string& tel, const string& specialite, double tarifHoraire, double bonus, int anneesExp)
    :Couturier(id, nom, prenom, tel, specialite, tarifHoraire), m_bonus(bonus) , m_anneesExp(anneesExp)
{
    if (bonus < 0) throw invalid_argument("Le Bonus ne peut pas etre negatif");
    if (anneesExp <= 0) throw invalid_argument("Les annees d'experiences ne peuvent pas etre negatif");
}

//Destructeur
CouturierSenior::~CouturierSenior() {

}

// Afficher
void CouturierSenior::afficher(ostream& os) const {
    os << "CouturierSenior #" << m_id << " : " << "\n"
       << m_prenom << " " << m_nom << "\n"
       << " | Tel: " << m_tel << "\n"
       << " | Specialite: " << m_specialite << "\n"
       << " | Tarif Horaire: " << m_tarifHoraire << "Fcfa/h" << "\n"
       << " | Bonus: " << m_bonus << "\n"
       << " | Annees d'experience: " << m_anneesExp << endl;
}

// Accesseurs
double CouturierSenior::getBonus() const {
    return m_bonus;
}

int CouturierSenior::getAnneesExp() const {
    return m_anneesExp;
}

// Mutateurs

void CouturierSenior::setBonus(double bonus) {
    if (bonus <= 0) throw invalid_argument("Le bonus ne peut pas etre negatif");
    m_bonus = bonus;
}


//Calcule du salaire
double CouturierSenior::calculerSalaire(int heures) const {
    return (m_tarifHoraire * heures) + m_bonus;
}

// Operateurs
ostream& operator<<(ostream& os, const CouturierSenior& c) {
    c.afficher(os);
    return os;
}

istream& operator>>(istream& is, CouturierSenior& c) {
    cout << "=== Saisie d'un Couturier Senior ===" << endl;

    double bonus;
    int anneesExp;

    is >> static_cast<Couturier&>(c);

    cout << "Bonus: ";
    is >> bonus;

    cout << "Annees experience: ";
    is >> anneesExp;

    c.setBonus(bonus);
    if (anneesExp <= 0) {
        throw invalid_argument("Les annees d'experiences ne peuvent pas etre negatif");
    }
    c.m_anneesExp = anneesExp;

    return is;
}


// ========== APPRENTI ==========
// Constructeur
Apprenti::Apprenti(int id, const string& nom, const string& prenom, const string& tel, const string& specialite, double tarifHoraire, Couturier* mentor)
    : Couturier(id, nom, prenom, tel, specialite, tarifHoraire),
      m_mentor(mentor)
{
    if (mentor == nullptr) throw invalid_argument("Le mentor ne peut pas être nullptr");
}

// Destructeur
Apprenti::~Apprenti() {

}

// Afficher
void Apprenti::afficher(ostream& os) const {
    os << "Apprenti #" << m_id << " : " << "\n"
       << m_prenom << " " << m_nom << "\n"
       << " | Tel: " << m_tel << "\n"
       << " | Specialite: " << m_specialite << "\n"
       << " | Tarif Horaire: " << m_tarifHoraire << "Fcfa/h" << "\n"
       << " | Mentor: " << m_mentor->getNom() << " " << m_mentor->getPrenom() << endl;
}

// Accesseur
Couturier* Apprenti::getMentor() const {
    return m_mentor;
}

// Mutateur
void Apprenti::setMentor(Couturier* mentor) {
    if (mentor == nullptr) throw invalid_argument("Le mentor ne peut pas être nullptr");

    m_mentor = mentor;
}

// Calcul du salaire
double Apprenti::calculerSalaire(int heures) const {
    return (m_tarifHoraire * heures) * 0.5;
}

// Operateurs
ostream& operator<<(ostream& os, const Apprenti& a) {
    a.afficher(os);
    return os;
}

istream& operator>>(istream& is, Apprenti& a) {
    cout << "=== Saisie d'un Apprenti ===" << endl;

    is >> static_cast<Couturier&>(a);


    return is;
}


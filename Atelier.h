//
// Created by sambf on 1/30/2026.
//

#ifndef EXAMENC___ATELIER_H
#define EXAMENC___ATELIER_H
#include "Personnes.h"
#include "Tissu.h"
#include "Commande.h"
#include "habilleTermine.h"
#include <vector>
#include <iostream>

class Atelier {
private:
    std::string m_nom;

    std::vector<Client*> m_clients;
    std::vector<Couturier*> m_couturiers;
    std::vector<Tissu*> m_tissus;
    std::vector<Commande*> m_commandes;
    std::vector<habilleTermine*> m_habitsTermines;

public:
    Atelier(const std::string& nom);
    ~Atelier();

    // Gestion des Clients
    void ajouterClient(Client* c);
    Client* trouverClient(int id) const;
    void supprimerClient(int id);

    // Gestion des Couturiers
    void ajouterCouturier(Couturier* c);
    Couturier* trouverCouturier(int id) const;
    void afficherTousCouturiers() const;
    void afficherSalairesEquipe(double heures) const;

    // Gestion des Tissus
    void ajouterTissu(Tissu* t);
    Tissu* trouverTissu(int id) const;
    void afficherTousTissus() const;

    // Gestion des Commandes
    void ajouterCommande(Commande* co);
    Commande* trouverCommande(int id) const;

    // Gestion des Habits Termines
    void ajouterHabilleTermine(habilleTermine* ht);

    // Operateurs
    friend std::ostream& operator<<(std::ostream& os, const Atelier& a);

    Client& operator[](int id);

    Couturier& operator()(int id);
};


#endif //EXAMENC___ATELIER_H
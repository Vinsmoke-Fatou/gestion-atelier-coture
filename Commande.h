//
// Created by sambf on 1/30/2026.
//

#ifndef EXAMENC___COMMANDE_H
#define EXAMENC___COMMANDE_H
#include <iostream>
#include "Personnes.h"
#include "Tissu.h"


class Commande {
private:
    int m_id;
    Client *m_client;
    Tissu *m_tissu;
    double m_metresNecessaires;
    std::string m_description;
    bool m_terminee;
public:
    Commande(int id, Client* client, Tissu* tissu, double metresNecessaires, const std::string& description, bool terminee = false);
    ~Commande();
    int getId() const;
    Client *getClient() const;
    Tissu *getTissu() const;
    double getMetresNecessaires() const;
    std::string getDescription() const;
    bool getTerminee() const;

    void setTerminee(bool etat);

    double calculerPrix() const;

    friend std::ostream& operator<<(std::ostream& os, const Commande& c);
    friend std::istream& operator>>(std::istream& is, Commande& c);
    friend bool operator==(const Commande& c1, const Commande& C2);

};


#endif //EXAMENC___COMMANDE_H
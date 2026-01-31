//
// Created by sambf on 1/30/2026.
//

#ifndef EXAMENC___HABILLETERMINE_H
#define EXAMENC___HABILLETERMINE_H
#include <iostream>
#include "Commande.h"
#include "Personnes.h"


class habilleTermine {
private:
    int m_id;
    Commande *m_commande;
    Couturier *m_couturier;
    int m_heuresTravail;
public:
    habilleTermine(int id, Commande *commande, Couturier *couturier, int heuresTravail);
    ~habilleTermine();

    int getId() const;
    Commande* getCommande() const;
    Couturier* getCouturier() const;
    int getHeuresTravail() const;

    double calculerCoutTotal() const;

    friend std::ostream& operator<<(std::ostream& os, const habilleTermine& t);
};


#endif //EXAMENC___HABILLETERMINE_H
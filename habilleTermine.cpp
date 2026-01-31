//
// Created by sambf on 1/30/2026.
//

#include "habilleTermine.h"
#include <stdexcept>
using namespace std;



habilleTermine::habilleTermine(int id, Commande* commande, Couturier* couturier, int heures)
    : m_id(id), m_commande(commande), m_couturier(couturier), m_heuresTravail(heures) {

    if (id <= 0) throw invalid_argument("ID invalide");
    if (!commande) throw invalid_argument("Commande nulle");
    if (!couturier) throw invalid_argument("Couturier nul");
    if (heures <= 0) throw invalid_argument("Heures de travail doivent être > 0");
}

habilleTermine::~habilleTermine() {

}

int habilleTermine::getId() const {
    return m_id;
}
Commande* habilleTermine::getCommande() const {
    return m_commande;
}
Couturier* habilleTermine::getCouturier() const {
    return m_couturier;
}
int habilleTermine::getHeuresTravail() const {
    return m_heuresTravail;
}

double habilleTermine::calculerCoutTotal() const {
    return m_commande->calculerPrix() + m_couturier->calculerSalaire(m_heuresTravail);
}

ostream& operator<<(ostream& os, const habilleTermine& ht) {
    os << "HABIT TERMINE #" << ht.m_id << "\n"
       << "Realise par : " << ht.m_couturier->getPrenom() << ht.m_couturier->getNom() << " (" << ht.m_heuresTravail << "h)" << "\n"
       << "Details : " << ht.m_commande->getDescription() << "\n"
       << "Coet final : " << ht.calculerCoutTotal() << " Fcfa" << endl;
    return os;
}
//
// Created by sambf on 1/30/2026.
//

#ifndef EXAMENC___TISSU_H
#define EXAMENC___TISSU_H
#include <iostream>

class Tissu {
private:
    int m_id;
    std::string m_nom;
    std::string m_couleur;
    double m_prixAuMetre;
    double m_quantiteStock;
public:
    Tissu(int id, const std::string& nom, const std::string& couleur, double prixAuMetre, double quantiteStock);
    ~Tissu();

    int getId() const;
    std::string getNom() const;
    std::string getCouleur() const;
    double getPrixAuMetre() const;
    double getQuantiteStock() const;

    void setPrixAuMetre(double prixAuMetre);

    void ajouterStock(double quantite);
    void retirerStock(double quantite);


    friend std::ostream& operator<<(std::ostream& os, const Tissu& t);
    friend std::istream& operator>>(std::istream& is, Tissu& t);
    friend bool operator==(const Tissu& t1, const Tissu& t2);
    friend bool operator!=(const Tissu& t1, const Tissu& t2);
    friend Tissu& operator+=(Tissu& t, double quantite);
    friend Tissu& operator-=(Tissu& t, double quantite);
};


#endif //EXAMENC___TISSU_H
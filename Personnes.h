#ifndef EXAMENC___PERSONNES_H
#define EXAMENC___PERSONNES_H
#include <iostream>

// ========== PERSONNE ==========
class Personne {
protected:
    int m_id;
    std::string m_nom;
    std::string m_prenom;
    std::string m_tel;

public:
    Personne(int id, const std::string& nom, const std::string& prenom, const std::string& tel);
    virtual ~Personne();

    virtual void afficher(std::ostream& os) const = 0;

    int getId() const;
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getTel() const;

    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setTel(const std::string& tel);

    friend std::ostream& operator<<(std::ostream& os, const Personne& p);
    friend std::istream& operator>>(std::istream& is, Personne& p);
    friend bool operator==(const Personne& p1, const Personne& p2);
    friend bool operator!=(const Personne& p1, const Personne& p2);
};

// ========== CLIENT ==========
class Client : public Personne {
private:
    std::string m_adresse;
    int m_nombreCommandes;

public:
    Client(int id, const std::string& nom, const std::string& prenom,
           const std::string& tel, const std::string& adresse);
    virtual ~Client();

    void afficher(std::ostream& os) const override;

    std::string getAdresse() const;
    int getNbCommandes() const;

    void setAdresse(const std::string& adresse);
    void incrementerCommandes();

    friend std::ostream& operator<<(std::ostream& os, const Client& c);
    friend std::istream& operator>>(std::istream& is, Client& c);
};

// ========== COUTURIER ==========
class Couturier : public Personne {
protected:
    std::string m_specialite;
    double m_tarifHoraire;

public:
    Couturier(int id, const std::string& nom, const std::string& prenom, 
              const std::string& tel, const std::string& specialite, double tarifHoraire);
    virtual ~Couturier();

    void afficher(std::ostream& os) const override;

    std::string getSpecialite() const;
    double getTarifHoraire() const;

    void setSpecialite(const std::string& specialite);
    void setTarifHoraire(double tarifHoraire);

    virtual double calculerSalaire(int heures) const;

    friend std::ostream& operator<<(std::ostream& os, const Couturier& c);
    friend std::istream& operator>>(std::istream& is, Couturier& c);
};

// ========== COUTURIER SENIOR ==========
class CouturierSenior : public Couturier {
private:
    double m_bonus;
    int m_anneesExp;

public:
    CouturierSenior(int id, const std::string& nom, const std::string& prenom, 
                    const std::string& tel, const std::string& specialite, 
                    double tarifHoraire, double bonus, int anneesExp);
    virtual ~CouturierSenior();

    void afficher(std::ostream& os) const override;

    double getBonus() const;
    int getAnneesExp() const;

    void setBonus(double bonus);

    double calculerSalaire(int heures) const override;

    // Operateurs
    friend std::ostream& operator<<(std::ostream& os, const CouturierSenior& cs);
    friend std::istream& operator>>(std::istream& is, CouturierSenior& cs);
};

// ========== APPRENTI ==========
class Apprenti : public Couturier {
private:
    Couturier* m_mentor;

public:
    Apprenti(int id, const std::string& nom, const std::string& prenom, 
             const std::string& tel, const std::string& specialite, 
             double tarifHoraire, Couturier* mentor);
    virtual ~Apprenti();

    void afficher(std::ostream& os) const override;

    Couturier* getMentor() const;

    void setMentor(Couturier* mentor);

    double calculerSalaire(int heures) const override;

    friend std::ostream& operator<<(std::ostream& os, const Apprenti& a);
    friend std::istream& operator>>(std::istream& is, Apprenti& a);
};

#endif //EXAMENC___PERSONNES_H
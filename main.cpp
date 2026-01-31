#include <iostream>
#include "Atelier.h"

using namespace std;

int main() {
    try {
        // 1. Creation de l'Atelier
        Atelier monAtelier("Couture Senegalaise");
        cout << "--- Bienvenue dans l'atelier : " << monAtelier << " ---\n" << endl;

        // 2. Gestion des tissus
        Tissu* basin = new Tissu(1, "Basin", "Blanc", 10000, 20.0);
        Tissu* wax = new Tissu(2, "Wax", "Multicolore", 5000, 15.0);
        Tissu* getzner = new Tissu(3, "Getzner", "Bleu", 15000, 7.0);
        Tissu* brodee = new Tissu(4, "Brodee", "Rose", 8000, 15.0);
        monAtelier.ajouterTissu(basin);
        monAtelier.ajouterTissu(wax);
        monAtelier.ajouterTissu(getzner);
        monAtelier.ajouterTissu(brodee);
        monAtelier.afficherTousTissus();
        cout << "---------------------------------------------" << endl;


        // 3.Gestion des couturiers
        CouturierSenior* chef1 = new CouturierSenior(11 , "Seck", "Dieume", "771234567", "Costumes", 5000, 25000, 15);
        Apprenti* eleve1 = new Apprenti(12, "Diop", "Moussa", "709876543", "Retouches", 2000, chef1);
        Apprenti* eleve2 = new Apprenti(13, "Seck", "Ablaye", "778987543", "Broderies", 2000, chef1);

        monAtelier.ajouterCouturier(chef1);
        monAtelier.ajouterCouturier(eleve1);
        monAtelier.ajouterCouturier(eleve2);

        cout << "Personnel de l'atelier :" << endl;
        monAtelier.afficherTousCouturiers();
        monAtelier.afficherSalairesEquipe(10);
        cout << "---------------------------------------------" << endl;


        // 4. Saisie d'un client
        Client* nouveauClient = new Client(101, "A", "B", "C", "D");
        cin >> *nouveauClient;
        monAtelier.ajouterClient(nouveauClient);

        cout << "\nAffichage direct du client saisi :" << endl;
        cout << *nouveauClient << endl;
        cout << "\nAffichage via l'Atelier (recherche par ID " << nouveauClient->getId() << ") :" << endl;
        cout << monAtelier[nouveauClient->getId()] << endl;
        cout << "---------------------------------------------" << endl;

        // 5. Creation d'une Commande
        // 5. Creation d'une Commande
        cout << "\n--- Creation d'une commande ---" << endl;
        monAtelier.afficherTousTissus();
        cout << "Entrez l'ID du tissu choisi : ";
        int idTissu;
        cin >> idTissu;

        Tissu* tChoisi = monAtelier.trouverTissu(idTissu);

        if (tChoisi) {
            double qte;
            string desc;
            cout << "Description de l'habit : "; getline(cin >> ws, desc);
            cout << "Metres necessaires : "; cin >> qte;

            Commande* cmd = new Commande(201, nouveauClient, tChoisi, qte, desc);

            cout << "\n> Prix total de la commande : " << cmd->calculerPrix() << " Fcfa" << endl;
            monAtelier.ajouterCommande(cmd);

            // 6. Terminer une commande
            cout << "\n--- Etape 6 : Terminer la Commande ---" << endl;
            monAtelier.afficherTousCouturiers();

            cout << "Choisir ID Couturier pour ce travail : ";
            int idCout; cin >> idCout;

            Couturier* couturierChoisi = monAtelier.trouverCouturier(idCout);
            if (couturierChoisi) {
                cout << "Nombre d'heures de travail effectuees : ";
                int h; cin >> h;

                cmd->setTerminee(true);

                habilleTermine* habit = new habilleTermine(501, cmd, couturierChoisi, h);
                monAtelier.ajouterHabilleTermine(habit);

                cout << "\n--- Recu Final ---" << endl;
                cout << *habit << endl;
                cout << "Commande enregistree !" << endl;
            } else {
                cout << "Couturier introuvable" << endl;
            }
        } else {
            cout << "Tissu introuvable" << endl;
        }

        // 7. Tests des operateurs
        cout << "\n--- Etape 7 : Tests des operateurs ---" << endl;

        Tissu* t1 = monAtelier.trouverTissu(1); // Basin
        Tissu* t2 = monAtelier.trouverTissu(2); // Wax

        cout << "Comparaison Tissu 1 et Tissu 2 : ";
        if (t1 && t2) {
            if (*t1 == *t2) cout << "Identiques" << endl;
            else cout << "Differents (Correct)" << endl;
        }


        Client* c1 = monAtelier.trouverClient(101);
        Client testClient(102, "Kanoute", "Bachir", "77000", "Fass");

        cout << "Comparaison Client 101 et Client 102 : ";
        if (c1) {
            if (*c1 != testClient) cout << "Les clients sont bien differents (Correct)" << endl;
            else cout << "Les clients sont identiques" << endl;
        }


        cout << "\n--- AFFICHAGE FINAL DE L'ATELIER ---" << endl;
        cout << monAtelier << endl;


    } catch (const exception& e) {
        cerr << "\n[ERREUR] : " << e.what() << endl;
    }

    return 0;
}
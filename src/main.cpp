#include <iostream>
#include "editor.h"

void printMenu() {
    std::cout << "\n=== Mini éditeur de texte ===\n";
    std::cout << "1. Afficher le texte\n";
    std::cout << "2. Ajouter une ligne\n";
    std::cout << "3. Sauvegarder dans un fichier\n";
    std::cout << "4. Charger depuis un fichier\n";
    std::cout << "5. Quitter\n";
    std::cout << "Choix : ";
}

int main() {
    Editor editor;
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Ignore le saut de ligne après le choix

        switch (choice) {
            case 1:
                editor.display();
                break;
            case 2: {
                std::cout << "Entrez la ligne à ajouter : ";
                std::string line;
                std::getline(std::cin, line);
                editor.addLine(line);
                break;
            }
            case 3: {
                std::cout << "Nom du fichier pour sauvegarder : ";
                std::string filename;
                std::getline(std::cin, filename);
                if (editor.saveToFile(filename)) {
                    std::cout << "Sauvegarde réussie.\n";
                } else {
                    std::cout << "Erreur lors de la sauvegarde.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Nom du fichier à charger : ";
                std::string filename;
                std::getline(std::cin, filename);
                if (editor.loadFromFile(filename)) {
                    std::cout << "Chargement réussi.\n";
                } else {
                    std::cout << "Erreur lors du chargement.\n";
                }
                break;
            }
            case 5:
                running = false;
                break;
            default:
                std::cout << "Choix invalide.\n";
        }
    }

    std::cout << "Au revoir!\n";
    return 0;
}

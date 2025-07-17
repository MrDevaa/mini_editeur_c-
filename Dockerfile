# Étape 1 : utiliser une image de base avec g++
FROM ubuntu:22.04

# Étape 2 : mettre à jour le système et installer g++ et make
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get clean

# Étape 3 : créer le dossier de l’application
WORKDIR /app

# Étape 4 : copier tous les fichiers dans l’image
COPY . .

# Étape 5 : compiler le programme
RUN g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp src/editor.cpp -o mini_editeur

# Étape 6 : lancer l'application au démarrage du container
CMD ["mini_editeur"]

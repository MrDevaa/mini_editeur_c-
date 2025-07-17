#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/editor.h"

TEST_CASE("Ajouter des lignes dans l'éditeur") {
    Editor editor;
    editor.addLine("Bonjour");
    editor.addLine("Ligne 2");
    REQUIRE(editor.saveToFile("test.txt") == true);
}

TEST_CASE("Charger et sauvegarder du contenu") {
    Editor editor;
    editor.addLine("Test line");

    REQUIRE(editor.saveToFile("testfile.txt") == true);

    Editor loaded;
    REQUIRE(loaded.loadFromFile("testfile.txt") == true);
}

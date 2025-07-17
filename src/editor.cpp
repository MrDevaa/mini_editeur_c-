#include "editor.h"
#include <iostream>
#include <fstream>

void Editor::addLine(const std::string& line) {
    lines.push_back(line);
}

void Editor::display() const {
    std::cout << "----- Contenu du texte -----" << std::endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << i + 1 << ": " << lines[i] << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
}

bool Editor::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) return false;
    for (const auto& line : lines) {
        ofs << line << "\n";
    }
    return true;
}

bool Editor::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) return false;
    lines.clear();
    std::string line;
    while (std::getline(ifs, line)) {
        lines.push_back(line);
    }
    return true;
}

#ifndef EDITOR_H
#define EDITOR_H

#include <vector>
#include <string>

class Editor {
private:
    std::vector<std::string> lines;

public:
    void addLine(const std::string& line);
    void display() const;
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
};

#endif // EDITOR_H

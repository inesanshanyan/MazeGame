#pragma once

#include <vector>
#include <string>
#include <iostream>

class Menu {
public:
    Menu();
    
    void addOption(const std::string &option);
    void moveUp();
    void moveDown();

    int getSelectedOption() const;
    size_t getOptionsCount() const;
    std::string getOptionText(int index) const;

private:
    std::vector<std::string> options;
    int selectedOption;
};



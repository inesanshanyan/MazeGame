#include "menu.hpp"

Menu::Menu() : selectedOption(0) {  }

void Menu::addOption(const std::string &option) {
    options.push_back(option);
}

void Menu::moveUp() {
    selectedOption = (selectedOption == 0) ? options.size() - 1 : selectedOption - 1;
}

void Menu::moveDown() {
    selectedOption = (selectedOption + 1) % options.size();
}

int Menu::getSelectedOption() const {
    return selectedOption;
}

size_t Menu::getOptionsCount() const {
    return options.size();
}

std::string Menu::getOptionText(int index) const {
    if (index >= 0 && index < options.size()) {
        return options[index];
    }
    return "";
}

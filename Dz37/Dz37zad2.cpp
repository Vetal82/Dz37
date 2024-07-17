#include <iostream>
#include <queue>
#include <string>
#include<thread>
#include<chrono>

class Ingredient {
private:
    std::string name;
    int preparationTime;

public:
    Ingredient(const std::string& name, int preparationTime) : name(name), preparationTime(preparationTime) {}

    std::string getName() const {
        return name;
    }

    int getPreparationTime() const {
        return preparationTime;
    }

    bool operator<(const Ingredient& other) const {
        return preparationTime > other.preparationTime;
    }
};

int main() {
    std::priority_queue<Ingredient> ingredients;

    while (true) {
        std::cout << "Enter ingredient name (or 'quit' to finish): ";
        std::string name;
        std::cin >> name;
        if (name == "quit") {
            break;
        }
        std::cout << "Enter preparation time: ";
        int preparationTime;
        std::cin >> preparationTime;
        ingredients.push(Ingredient(name, preparationTime));
        std::cout << "Add ingredient: " << name << std::endl;
    }

    std::cout << "Preparing dish..." << std::endl;

    while (!ingredients.empty()) {
        Ingredient currentIngredient = ingredients.top();
        ingredients.pop();
        std::cout << "Cook a dish: " << currentIngredient.getName() << " for " << currentIngredient.getPreparationTime() << " minutes..." << std::endl;
        
        for (int i = 0; i < currentIngredient.getPreparationTime(); ++i) {
            std::cout << ".";
            std::flush(std::cout);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << std::endl;
    }

    std::cout << "Dish is ready!" << std::endl;

    return 0;
}
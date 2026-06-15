#include <iostream>
#include <memory>
#include "ingredient.hpp"
#include "recipe.hpp"
#include "coffee_machine.hpp"

int main()
{
    Recipe espresso("Espresso", 14.0, 40.0, 0.0);
    Recipe cappuccino("Cappuccino", 14.0, 40.0, 150.0);
    Recipe latte_macchiato("Latte Macchiato", 14.0, 60.0, 250.0);
    Recipe americano("Americano", 14.0, 180.0, 0.0);

    CoffeeMachine machine;

    machine.add_ingredient(std::make_unique<Coffee>(200.0, "Dark"));
    machine.add_ingredient(std::make_unique<Water>(1500.0, 300.0));
    machine.add_ingredient(std::make_unique<Milk>(800.0, 7.0));

    machine.show_status();

    char choice = ' ';
    bool running = true;

    while (running)
    {
        std::cout << "\nEnter command (e: Espresso, c: Cappuccino, l: Latte, a: Americano, s: Status, x: Clean, q: Quit): ";
        std::cin >> choice;

        switch (choice)
        {
        case 'e':
            machine.brew(espresso);
            break;
        case 'c':
            machine.brew(cappuccino);
            break;
        case 'l':
            machine.brew(latte_macchiato);
            break;
        case 'a':
            machine.brew(americano);
            break;
        case 's':
            machine.show_status();
            break;
        case 'x':
            machine.clean_limescale();
            break;
        case 'q':
            running = false;
            break;
        default:
            std::cout << "Invalid command!\n";
            break;
        }
    }

    return 0;
}

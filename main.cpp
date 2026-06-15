#include <iostream>
#include <memory>
#include "Ingredient.hpp"
#include "Recipe.hpp"
#include "CoffeeMachine.hpp"

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

    machine.brew(espresso);
    machine.brew(latte_macchiato);
    machine.brew(americano);

    machine.show_status();

    machine.brew(cappuccino);
    machine.brew(americano);

    machine.show_status();

    machine.brew(espresso);

    machine.clean_limescale();
    machine.show_status();

    machine.brew(espresso);

    return 0;
}

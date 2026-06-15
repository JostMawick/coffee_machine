#include <iostream>
#include <memory>
#include "ingredient.hpp"
#include "recipe.hpp"
#include "coffee_machine.hpp"

int main()
{
    // 1. Hardcoded recipes
    Recipe espresso("Espresso", 14.0, 40.0, 0.0);
    Recipe cappuccino("Cappuccino", 14.0, 40.0, 150.0);

    // 2. Setup machine
    CoffeeMachine machine;

    // Water has a high calcium value (300.0) to quickly simulate limescale buildup
    machine.add_ingredient(std::make_unique<Coffee>(100.0, "Dark"));
    machine.add_ingredient(std::make_unique<Water>(1000.0, 300.0));
    machine.add_ingredient(std::make_unique<Milk>(500.0, 7.0));

    // Show initial machine status
    machine.show_status();

    // 4. Brew first drinks (Limescale increases, amounts decrease)
    machine.brew(espresso);
    machine.brew(cappuccino);

    machine.show_status();

    machine.brew(cappuccino);
    machine.brew(cappuccino);

    machine.show_status();

    // This brew will fail because m_limescale_g exceeds m_max_limescale_g
    machine.brew(espresso);

    // 6. Clean machine and reset limescale
    machine.clean_limescale();
    machine.show_status();

    // Brewing works again after cleaning
    machine.brew(espresso);

    return 0;
}

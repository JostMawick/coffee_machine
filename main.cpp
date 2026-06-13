#include <iostream>
#include "ingredient.hpp"
#include "recipe.hpp"
#include "coffee_machine.hpp"
#include "operator.hpp"

int main()
{
    std::cout << __cplusplus << std::endl;
    Ingredient i("milk", 50);
    std::cout << i.getName();
    return 0;
}

#ifndef COFFEE_MACHINE_HPP
#define COFFEE_MACHINE_HPP

#include <vector>
#include <memory>
#include <iostream>
#include "Ingredient.hpp"
#include "Recipe.hpp"

class CoffeeMachine
{
private:
    std::vector<std::unique_ptr<Ingredient>> m_ingredients;
    double m_limescale_g;
    double m_max_limescale_g;

public:
    CoffeeMachine()
        : m_limescale_g(0.0), m_max_limescale_g(15.0) {}

    ~CoffeeMachine() = default;

    CoffeeMachine(const CoffeeMachine &) = delete;
    CoffeeMachine &operator=(const CoffeeMachine &) = delete;

    void add_ingredient(std::unique_ptr<Ingredient> ing)
    {
        if (ing != nullptr)
        {
            m_ingredients.push_back(std::move(ing));
        }
    }

    void clean_limescale()
    {
        std::cout << "Cleaning program active... Limescale removed!\n";
        m_limescale_g = 0.0;
    }

    void show_status() const
    {
        std::cout << "\n--- MACHINE STATUS ---\n";
        std::cout << "Limescale: " << m_limescale_g << "g / " << m_max_limescale_g << "g\n";
        for (const auto &ing : m_ingredients)
        {
            std::cout << " * " << ing->get_name() << ": " << ing->get_amount() << "g remaining\n";
        }
    }
};

#endif

#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <string>
#include <utility>

class Recipe
{
private:
    std::string m_name;
    double m_coffee_needed_g;
    double m_water_needed_ml;
    double m_milk_needed_ml;

public:
    Recipe(std::string recipe_name, double coffee, double water, double milk)
        : m_name(std::move(recipe_name)),
          m_coffee_needed_g(coffee),
          m_water_needed_ml(water),
          m_milk_needed_ml(milk) {}

    ~Recipe() = default;

    std::string get_name() const { return m_name; }
    double get_coffee_needed() const { return m_coffee_needed_g; }
    double get_water_needed() const { return m_water_needed_ml; }
    double get_milk_needed() const { return m_milk_needed_ml; }
};

#endif

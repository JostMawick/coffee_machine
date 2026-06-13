#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include <string>
#include <utility>

class Ingredient
{
protected:
    std::string m_name;
    double m_amount_g;

public:
    Ingredient(std::string n, double amt) : m_name(std::move(n)), m_amount_g(amt) {}

    virtual ~Ingredient() = default;

    std::string getName() const { return m_name; }
    double getAmount() const { return m_amount_g; }

    virtual double use(double amountNeeded)
    {
        if (amountNeeded <= m_amount_g)
        {
            m_amount_g -= amountNeeded;
        }
        return 0.0;
    }

    void refill(double amountToRefill)
    {
        if (amountToRefill > 0.0)
        {
            m_amount_g += amountToRefill;
        }
    }
};

#endif

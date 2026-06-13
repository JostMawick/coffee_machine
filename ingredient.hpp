#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include <string>
#include <utility>
#include <iostream>

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

    virtual void refill(double amountToRefill)
    {
        if (amountToRefill > 0.0)
        {
            m_amount_g += amountToRefill;
        }
    }
};

class Water : public Ingredient
{
private:
    double m_calcium_mgl;

public:
    Water(double amt, double calcium)
        : Ingredient("Water", amt), m_calcium_mgl(calcium) {}

    double use(double amountNeeded) override
    {
        Ingredient::use(amountNeeded);
        return amountNeeded * (m_calcium_mgl / 1000.0);
    }
};

class Coffee : public Ingredient
{
private:
    std::string m_roastDegree;

public:
    Coffee(double amt, std::string roast)
        : Ingredient("Coffee", amt), m_roastDegree(std::move(roast)) {}

    std::string getRoastDegree() const { return m_roastDegree; }
};

class Milk : public Ingredient
{
private:
    double m_expirationTime;

public:
    Milk(double amt, double expTime)
        : Ingredient("Milk", amt), m_expirationTime(expTime) {}

    double getExpirationTime() const { return m_expirationTime; }

    void refill(double amountToRefill) override
    {
        Ingredient::refill(amountToRefill);
        m_expirationTime = 7.0;
    }

    void checkExpiration() const
    {
        if (m_expirationTime <= 0.0)
        {
            std::cout << " Warning: The milk has expired! Please refill to refresh.\n";
        }
    }
};

#endif

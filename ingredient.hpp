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
    double m_max_amount_g;

public:
    Ingredient(std::string n, double amt) : m_name(std::move(n)), m_amount_g(amt), m_max_amount_g(amt) {}

    virtual ~Ingredient() = default;

    std::string get_name() const { return m_name; }
    double get_amount() const { return m_amount_g; }
    double get_max_amount() const { return m_max_amount_g; }

    virtual void prepare() const = 0;

    virtual double use(double amount_needed)
    {
        if (amount_needed <= m_amount_g)
        {
            m_amount_g -= amount_needed;
            return 0.0;
        }
        return -1.0;
    }

    virtual void refill(double amount_to_refill)
    {
        if (amount_to_refill > 0.0)
        {
            m_amount_g += amount_to_refill;
            if (m_amount_g > m_max_amount_g)
            {
                m_amount_g = m_max_amount_g;
                std::cout << "Refilled " << m_name << " to maximum capacity (" << m_max_amount_g << "g).\n";
            }
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

    void prepare() const override
    {
        std::cout << "Heating water\n";
    }

    double use(double amount_needed) override
    {
        if (amount_needed <= m_amount_g)
        {
            Ingredient::use(amount_needed);
            return amount_needed * (m_calcium_mgl / 1000.0);
        }
        return -1.0;
    }
};

class Coffee : public Ingredient
{
private:
    std::string m_roast_degree;

public:
    Coffee(double amt, std::string roast)
        : Ingredient("Coffee", amt), m_roast_degree(std::move(roast)) {}

    void prepare() const override
    {
        std::cout << "Grinding coffee beans\n";
    }

    std::string get_roast_degree() const { return m_roast_degree; }
};

class Milk : public Ingredient
{
private:
    double m_expiration_time;

public:
    Milk(double amt, double exp_time)
        : Ingredient("Milk", amt), m_expiration_time(exp_time) {}

    void prepare() const override
    {
        std::cout << "Frothing milk\n";
    }

    double get_expiration_time() const { return m_expiration_time; }

    void refill(double amount_to_refill) override
    {
        Ingredient::refill(amount_to_refill);
        m_expiration_time = 7.0;
    }

    void check_expiration() const
    {
        if (m_expiration_time <= 0.0)
        {
            std::cout << " Warning: The milk has expired! Please refill to refresh.\n";
        }
    }
};

#endif

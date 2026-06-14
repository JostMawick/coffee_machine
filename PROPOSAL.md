# Project Proposal: Coffee Machine Simulator

### Problem Statement

A simulator for a coffee machine that handles ingredients, tracks limescale build-up, and processes drink recipes.

### Class List & OOP Concepts

- **Ingredient**: Abstract base class for all ingredients. Models Encapsulation.
- **Water**: Derived class. Overrides `use()` to calculate limescale. Models Inheritance.
- **Coffee**: Derived class. Adds specific roast degree field. Models Inheritance.
- **Milk**: Derived class. Overrides `refill()` to reset expiration tracking. Models Inheritance.
- **Recipe**: Transient data class with ingredient amounts. Models Dependency.
- **CoffeeMachine**: Main controller. Holds ingredients in a vector. Models Composition.

### Concept Checklist Implementation

- **Composition**: `CoffeeMachine` owns `std::vector<std::unique_ptr<Ingredient>>`.
- **Dependency**: `Recipe` is passed as a temporary parameter to `CoffeeMachine::brew()`.
- **Polymorphism**: Dynamic dispatch through virtual `use()` and `refill()` methods.
- **Rule of Zero**: No raw pointers or manual memory management; uses RAII wrappers.
- **No <algorithm>**: Loops use plain range-based syntax only.

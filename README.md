# Coffee Machine Simulator

### Student Info

- **Course**: Object-Oriented Programming (TC1030.302)
- **Instructor**: Dr. Leopoldo Rodriguez Salazar
- **Standard**: C++14

---

## Build and Run Instructions

```bash
g++ -std=c++14 main.cpp -o coffee_machine.exe
./coffee_machine.exe
```

---

## Design and Ownership Rationale

### Rule of Zero Architectural Decision

The codebase complies strictly with the **Rule of Zero**. Explicit custom memory freeing management is completely avoided. All dynamic allocations on the heap are managed natively through modern RAII wrappers (`std::unique_ptr` and `std::vector`).

### Lifetime & Relationship Specifications

1.  **Composition**: The `CoffeeMachine` holds exclusive lifecycle ownership over its internal `Ingredient` objects. When the machine instance is destroyed, the associated resource containers are cleared automatically from memory.
2.  **Dependency**: The `Recipe` class acts as a transient, non-owning configuration reference passed directly into the `brew` method. Its lifetime is fully managed outside the scope of the engine.

### Loop Strategy Restriction

No utilities from `<algorithm>` are included. All traversals and mutations across the container fields use standard, plain range-based loops to fulfill the scope guardrails.

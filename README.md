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

## User Manual / Interactive Commands

The simulator runs an interactive terminal loop. Enter a character and press **Enter**:

*   `e`: Brew an Espresso.
*   `c`: Brew a Cappuccino.
*   `l`: Brew a Latte Macchiato.
*   `a`: Brew an Americano.
*   `s`: Show Status (Displays current ingredient levels, expiration, and limescale).
*   `r`: Refill All (Restores containers to max capacity and resets milk expiration to 7.0 days).
*   `x`: Clean Limescale (Resets the machine's limescale counter to 0g).
*   `q`: Quit (Exits the program cleanly).

### Error Simulation Tests
1. **Limescale Block**: Brew multiple `a` (Americano) drinks. Once limescale hits 15g, the machine triggers an exception and locks. Press `x` to clear.
2. **Milk Expiration**: Brew `c` or `l` multiple times. Milk expiration decreases by 1.0 per brew. At 0.0, it triggers an exception and locks. Press `r` to reset.
3. **Resource Depletion**: If any ingredient falls below the recipe requirement, brewing is blocked before any resources are deducted.

---

## Design and Ownership Rationale

### Rule of Zero Architectural Decision
The codebase complies strictly with the **Rule of Zero**. Explicit custom memory freeing management is completely avoided. All dynamic allocations on the heap are managed natively through modern RAII wrappers (`std::unique_ptr` and `std::vector`).

### Lifetime & Relationship Specifications
1.  **Composition**: The `CoffeeMachine` holds exclusive lifecycle ownership over its internal `Ingredient` objects. When the machine instance is destroyed, the associated resource containers are cleared automatically from memory.
2.  **Dependency**: The `Recipe` class acts as a transient, non-owning configuration reference passed directly into the `brew` method. Its lifetime is fully managed outside the scope of the engine.

### Loop Strategy Restriction
No utilities from `<algorithm>` are included. All traversals and mutations across the container fields use standard, plain range-based loops to fulfill the scope guardrails.

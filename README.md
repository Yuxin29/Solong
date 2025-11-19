# so_long

**so_long** is a simple 2D top-down game built with the [MLX42](https://harm-smits.github.io/42docs/libs/minilibx) graphical library, as part of the 42 core curriculum. The game involves parsing and rendering a map, handling player movement, collecting items, and reaching an exit — all while ensuring proper memory management and error handling.
![Gameplay animation](assets/gameplay.gif)

---

## Features

- Map parsing from `.ber` files with full validation
- Real-time keyboard controls
- 2D rendering using textures via MLX42
- Win condition tracking and step counter
- Flood-fill algorithm for accessibility validation
- Graceful error handling and memory cleanup
- Dynamic texture loading and player tracking

---

## Game Rules

- The player (`P`) must collect all collectables (`C`)
- Then reach the exit (`E`) to win
- Walls (`1`) are impassable
- Empty spaces (`0`) are walkable
- Game ends with a win or window close

---

## Map Format (`.ber`)

A valid map file must:
- Be rectangular
- Be enclosed by walls
- Contain **1 player**, **1 exit**, and **at least 1 collectable**
- Only use characters: `01PCE`
Example:
111111
1P0C01
100001
1C0E11
111111


---

## 🚀 Build & Run

### ⚙️ Requirements
- `gcc` or `clang`
- [MLX42](https://github.com/codam-coding-college/MLX42)
- `libft` and `get_next_line` included


### 🏗️ Compilation

1. Navigate to the project directory:
cd so_long
2. Compile using the provided Makefile:
make            # Generate the executable so_long
3. Available make commands:
make clean     # Remove object files
make fclean    # Remove object files and executable
make re        # Recompile everything from scratch
4. Running the Game
Run the game with a valid .ber map:
./so_long path/to/map.ber



# 2048 Game in C

A console-based implementation of the classic **2048 tile-merging puzzle game**, written in C as a first-semester university project for the **Programming Fundamentals** course.

## 👤 Author

**Aman Mushtaq**

## 📖 About the Project

The 2048 game is a popular single-player puzzle game played on a **4×4 grid**. The player moves numbered tiles in four directions, and tiles with the same value merge to form a new tile with double the value. The goal is to achieve the highest possible score by continuously merging tiles.

This project demonstrates core **Programming Fundamentals** concepts including:
- 2D arrays for grid management
- Functions for modular programming
- Loops and conditional statements
- Random number generation
- File handling for persistent high scores

## ✨ Features

- 4×4 game board using a two-dimensional array
- Keyboard controls: **W** (Up), **S** (Down), **A** (Left), **D** (Right)
- Automatic tile merging based on game rules
- Real-time score calculation
- **Persistent high score** saved/loaded via file handling (`highscore.txt`)
- Restart option (**R**) without restarting the program
- Exit option (**U**)
- Clean, formatted console output

## 🛠️ How to Build & Run

### Prerequisites
- A C compiler (GCC recommended)

### Compile
```bash
gcc game.c -o 2048
```

### Run
```bash
# Linux / macOS
./2048

# Windows
2048.exe
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move tiles **Up** |
| `S` | Move tiles **Down** |
| `A` | Move tiles **Left** |
| `D` | Move tiles **Right** |
| `R` | **Restart** the game |
| `U` | **Exit** the game |

## 📂 Files

| File | Description |
|------|-------------|
| `game.c` | Full game source code |
| `highscore.txt` | Auto-generated; stores the persistent high score |

## 🎓 Course Info

- **Course:** Programming Fundamentals (PF)
- **Semester:** 1st Semester
- **Institution:** Iqra University

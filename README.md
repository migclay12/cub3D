# 🎮 Cub3D

A 3D raycasting engine inspired by the legendary Wolfenstein 3D, built from scratch in C using the MLX graphics library.

![Cub3D Demo](https://img.shields.io/badge/Status-Complete-brightgreen)
![C](https://img.shields.io/badge/Language-C-blue)
![42](https://img.shields.io/badge/School-42-black)

## 📖 About

Cub3D is a 3D raycasting engine that renders a first-person view of a 2D map using raycasting techniques. The project demonstrates advanced C programming concepts including graphics programming, mathematical algorithms, and memory management.

## ✨ Features

### Core Features
- **Raycasting Engine**: Real-time 3D rendering using raycasting algorithm
- **Texture Mapping**: Support for XPM texture files on walls
- **Player Movement**: Smooth WASD movement with mouse look
- **Map Validation**: Comprehensive validation of `.cub` map files
- **Color Support**: Customizable floor and ceiling colors

### Bonus Features
- **Minimap**: Real-time minimap showing player position and orientation
- **Multiple Textures**: Different textures for North, South, East, and West walls
- **Advanced Controls**: Mouse rotation and keyboard movement

## 🚀 Installation

### Prerequisites
- Linux environment (Ubuntu/Debian recommended)
- GCC compiler
- Make
- X11 development libraries

### Build Instructions

1. **Clone the repository**
   ```bash
   git clone https://github.com/migclay12/cub3d.git
   cd cub3d
   ```

2. **Install dependencies**
   ```bash
   sudo apt-get update
   sudo apt-get install libx11-dev libxext-dev libbsd-dev
   ```

3. **Compile the project**
   ```bash
   make
   ```

4. **Run the game**
   ```bash
   ./cub3d maps/good/subject_map.cub
   ```

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` | Rotate left |
| `→` | Rotate right |
| `ESC` | Exit game |

## 🗺️ Map Format

Cub3D uses `.cub` files to define game maps. Here's the format:

```
NO textures/north_wall.xpm    # North wall texture
SO textures/south_wall.xpm    # South wall texture
EA textures/east_wall.xpm     # East wall texture
WE textures/west_wall.xpm     # West wall texture

F 220,100,20                  # Floor color (RGB)
C 135,206,235                 # Ceiling color (RGB)

1111111111111111111111111     # Map layout
1000000000110000000000001     # 1 = wall, 0 = empty space
1011000001110000000000001     # N/E/S/W = player spawn
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000000001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Map Rules
- Maps must be surrounded by walls (`1`)
- Only one player spawn point allowed (`N`, `E`, `S`, or `W`)
- Empty spaces (`0`) must be enclosed by walls
- Textures must be valid XPM files

## 📁 Project Structure

```
cub3d/
├── src/                    # Core implementation
│   ├── main.c             # Entry point
│   ├── raycasting.c       # Raycasting engine
│   ├── map_check.c        # Map validation
│   ├── hooks.c            # Input handling
│   └── includes/          # Header files
├── bonus/                 # Bonus features
├── libft/                 # Custom C library
├── minilibx-linux/        # Graphics library
├── maps/                  # Sample maps
│   ├── good/             # Valid maps
│   └── bad/              # Invalid maps (for testing)
└── textures/             # Wall textures
```

## 🧪 Testing

The project includes comprehensive test maps:

```bash
# Test with different maps
./cub3d maps/good/test_map.cub
./cub3d maps/good/dungeon.cub
./cub3d maps/good/library.cub

# Test error handling
./cub3d maps/bad/invalid_map.cub
```

## 🎯 Technical Details

### Raycasting Algorithm
The engine uses DDA (Digital Differential Analyzer) algorithm for efficient raycasting:
- Casts rays from player position at different angles
- Calculates wall intersections using step-by-step traversal
- Applies perspective correction for realistic rendering
- Maps textures based on wall orientation

### Performance
- **Resolution**: 1920x1200 pixels
- **Field of View**: ~80 degrees
- **Frame Rate**: 60+ FPS on modern hardware
- **Memory**: Efficient memory management with proper cleanup

## 🏗️ Architecture

The project follows a modular architecture:

- **Graphics Layer**: MLX-based rendering system
- **Game Logic**: Player movement and collision detection
- **Map System**: File parsing and validation
- **Raycasting Engine**: Core 3D rendering algorithm

## 🤝 Contributing

This is a 42 school project, but suggestions and improvements are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📜 License

This project is part of the 42 school curriculum. Please respect the academic integrity policies.

## 👨‍💻 Author

**Miguel González Clayton** - [@migclay12](https://github.com/migclay12)

## 🙏 Acknowledgments

- 42 School for the project specification
- MLX library developers
- Wolfenstein 3D for inspiration
- The C programming community

---

⭐ If you found this project interesting, please give it a star!

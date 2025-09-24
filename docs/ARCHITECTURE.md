# Cub3D Architecture Documentation

## Overview

Cub3D is a 3D raycasting engine that renders a first-person view of a 2D map. The architecture follows a modular design with clear separation of concerns.

## Core Components

### 1. Graphics System (`init_graphics.c`, `load_images.c`)
- **MLX Integration**: Handles window creation and image management
- **Texture Loading**: Loads XPM texture files for walls
- **Pixel Manipulation**: Direct pixel drawing functions

### 2. Raycasting Engine (`raycasting.c`, `ray_utils.c`)
- **DDA Algorithm**: Digital Differential Analyzer for efficient ray traversal
- **Wall Detection**: Determines wall intersections and distances
- **Texture Mapping**: Maps textures to wall surfaces based on orientation

### 3. Map System (`map_check.c`, `map_check_utils.c`)
- **File Parsing**: Reads and validates `.cub` map files
- **Validation**: Ensures map integrity (closed walls, single player spawn)
- **Matrix Storage**: 2D array representation of the game world

### 4. Player System (`init_player.c`, `hooks.c`, `hooks_utils.c`)
- **Movement**: WASD controls with collision detection
- **Rotation**: Mouse and keyboard rotation controls
- **State Management**: Tracks player position and orientation

### 5. Input Handling (`hooks.c`, `hooks_utils.c`)
- **Key Events**: Handles keyboard input
- **Mouse Events**: Mouse movement and clicks
- **Event Loop**: MLX event processing

## Data Structures

### Core Structures

```c
typedef struct s_mlx {
    void        *ptr;           // MLX instance
    void        *win;           // Window pointer
    t_img       img;            // Main image buffer
    t_player    player;         // Player data
    t_map       map;            // Map data
    t_ray       ray;            // Raycasting data
    t_wall_path path;           // Texture paths
} t_mlx;
```

### Player Structure
```c
typedef struct s_player {
    double  plyr_x;             // X position
    double  plyr_y;             // Y position
    char    orient;             // Initial orientation
    double  angle;              // Current angle
    int     move_no;            // Movement flags
    int     move_so;
    int     move_we;
    int     move_ea;
    int     rot_l;              // Rotation flags
    int     rot_r;
} t_player;
```

### Ray Structure
```c
typedef struct s_ray {
    double  x, y;               // Ray position
    double  *distances;         // Distance array for each ray
    double  *ray_x, *ray_y;     // Ray endpoint arrays
    int     *vertical_hit;      // Hit direction flags
    double  *ray_dir_x, *ray_dir_y; // Ray direction arrays
    t_img   wall_no, wall_ea, wall_so, wall_we; // Wall textures
    int     f_r, f_g, f_b;      // Floor color
    int     c_r, c_g, c_b;      // Ceiling color
} t_ray;
```

## Algorithm Details

### Raycasting Algorithm

1. **Ray Generation**: Cast rays from player position at different angles
2. **DDA Traversal**: Use DDA algorithm to efficiently traverse the map
3. **Wall Detection**: Find first wall intersection
4. **Distance Calculation**: Calculate perpendicular distance to wall
5. **Texture Mapping**: Determine which texture to use based on wall orientation
6. **Rendering**: Draw vertical slice of wall with texture

### DDA Algorithm Implementation

```c
// Calculate step direction
if (ray_dir_x < 0) {
    step_x = -1;
    side_dist_x = (player_x - map_x) * delta_dist_x;
} else {
    step_x = 1;
    side_dist_x = (map_x + 1.0 - player_x) * delta_dist_x;
}

// Perform DDA
while (hit == 0) {
    if (side_dist_x < side_dist_y) {
        side_dist_x += delta_dist_x;
        map_x += step_x;
        side = 0;
    } else {
        side_dist_y += delta_dist_y;
        map_y += step_y;
        side = 1;
    }
    if (world_map[map_x][map_y] > 0) hit = 1;
}
```

## Memory Management

### Allocation Strategy
- **Dynamic Arrays**: Ray data arrays allocated based on screen width
- **Texture Loading**: XPM files loaded into memory once
- **Map Storage**: 2D array allocated based on map dimensions

### Cleanup Functions
- `ft_free_matrix()`: Frees 2D string arrays
- `ft_free_rays()`: Frees ray data arrays
- `ft_exit()`: Comprehensive cleanup on program exit

## Performance Considerations

### Optimization Techniques
- **Pre-calculated Values**: Trigonometric functions calculated once per frame
- **Efficient Traversal**: DDA algorithm minimizes unnecessary calculations
- **Memory Pool**: Reuse of allocated memory where possible
- **Early Termination**: Ray traversal stops at first wall hit

### Frame Rate Targets
- **Target**: 60 FPS
- **Resolution**: 1920x1200
- **Rays**: 1920 rays per frame (one per pixel column)

## Error Handling

### Validation Levels
1. **File Format**: Valid `.cub` file structure
2. **Map Integrity**: Closed walls, valid characters
3. **Resource Loading**: Texture file existence and validity
4. **Runtime Errors**: Memory allocation failures, invalid operations

### Error Recovery
- **Graceful Degradation**: Continue operation when possible
- **Clean Exit**: Proper resource cleanup on errors
- **User Feedback**: Clear error messages

## Extension Points

### Adding New Features
- **New Textures**: Extend texture loading system
- **Multiple Levels**: Add level transition system
- **Sound System**: Integrate audio library
- **Networking**: Add multiplayer support

### Code Organization
- **Modular Design**: Each component in separate files
- **Header Organization**: Clear separation of public/private interfaces
- **Dependency Management**: Minimal coupling between modules

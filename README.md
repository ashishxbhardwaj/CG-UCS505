# Ball Drop Simulation

A simple OpenGL program that simulates a ball dropping and bouncing with gravity. The program also allows toggling between day and night scenes, with interactive elements such as moving clouds and user-controlled ball movements.

## Features

- **Day and Night Modes**:
  - Day: Blue sky, green ground, sun, and light-colored clouds.
  - Night: Dark sky, moon, stars, and darker environment.
- **Ball Animation**:
  - A red ball that falls due to gravity, bounces on the platform, and can be moved or jumped.
- **Dynamic Environment**:
  - Moving clouds, twinkling stars, mountains, and trees.
- **Interactive Controls**:
  - Keyboard controls for movement, toggling modes, and jumping.
  - Mouse click to drop the ball at a specific location.

## Controls

| Key         | Action                        |
|-------------|-------------------------------|
| `m`         | Switch to Day mode.           |
| `n`         | Switch to Night mode.         |
| `a`         | Move the ball left.           |
| `d`         | Move the ball right.          |
| `Spacebar`  | Make the ball jump.           |
| `Left Click`| Drop the ball at clicked position. |

## How to Run

1. **Install OpenGL and GLUT**:
   - For Linux: `sudo apt-get install freeglut3-dev`
   - For Windows: Use libraries compatible with your compiler (e.g., MinGW).
2. **Compile the Program**:
   ```bash
   g++ ball_drop.cpp -o ball_drop -lGL -lGLU -lglut

# Computer Graphics Practicals 1–9

Beginner-level C++ programs using OpenGL and GLUT.

## Programs
1. Basic OpenGL primitives
2. DDA and Bresenham line drawing
3. Midpoint circle drawing
4. Boundary fill
5. Cohen–Sutherland line clipping
6. 2D transformations
7. Koch curve
8. Moving vehicle animation
9. 3D house model (GLUT recreation)

## Fedora setup
```bash
sudo dnf install freeglut-devel mesa-libGL-devel mesa-libGLU-devel gcc-c++
```

## Compile and run
Compile each file separately from the repository root:
```bash
g++ cg/01_basic_primitives.cpp -o cg1 -lGL -lGLU -lglut
./cg1
```
Replace the source filename and output name for the other practicals.

Practical 4: click inside the triangle to start boundary fill. Practical 9 is a GLUT recreation of a 3D house model, not a VRML parser or .wrl file.

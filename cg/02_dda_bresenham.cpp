#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

void pixel(int x, int y) { glVertex2i(x, y); }

void dda(int x1, int y1, int x2, int y2, int style) {
    float dx = x2 - x1, dy = y2 - y1;
    int steps = (int)fmax(fabs(dx), fabs(dy));
    if (steps == 0) return;
    float x = x1, y = y1;
    float xin = dx / steps, yin = dy / steps;
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        if (style == 0 || (style == 1 && i % 8 < 4) || (style == 2 && i % 8 == 0))
            pixel((int)round(x), (int)round(y));
        x += xin; y += yin;
    }
    glEnd();
}

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    glBegin(GL_POINTS);
    while (true) {
        pixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);
    glColor3f(1, 0, 0); dda(50, 50, 300, 200, 0);
    glColor3f(0, 0, 1); dda(50, 120, 300, 270, 1);
    glColor3f(0, 0.6, 0); dda(50, 190, 300, 340, 2);
    glColor3f(0, 0, 0); bresenham(350, 50, 570, 200);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 2 - DDA and Bresenham");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
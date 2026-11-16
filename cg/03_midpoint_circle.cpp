#include <GL/glut.h>

void plot(int x, int y) {
    glVertex2i(320 + x, 240 + y); glVertex2i(320 - x, 240 + y);
    glVertex2i(320 + x, 240 - y); glVertex2i(320 - x, 240 - y);
    glVertex2i(320 + y, 240 + x); glVertex2i(320 - y, 240 + x);
    glVertex2i(320 + y, 240 - x); glVertex2i(320 - y, 240 - x);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    int x = 0, y = 100, p = 1 - 100;
    glColor3f(0, 0, 1);
    glPointSize(2);
    glBegin(GL_POINTS);
    while (x <= y) {
        plot(x, y);
        x++;
        if (p < 0) p += 2 * x + 1;
        else { y--; p += 2 * (x - y) + 1; }
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 3 - Midpoint Circle");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
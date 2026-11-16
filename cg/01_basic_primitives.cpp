#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(8);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(100, 350);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex2i(150, 350);
    glVertex2i(300, 350);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 100);
    glVertex2i(250, 100);
    glVertex2i(175, 250);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex2i(350, 100);
    glVertex2i(500, 100);
    glVertex2i(500, 250);
    glVertex2i(350, 250);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 1 - Basic OpenGL Primitives");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
#include <GL/glut.h>

void triangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(100, 100);
    glVertex2f(200, 100);
    glVertex2f(150, 220);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    triangle();

    glPushMatrix();
    glTranslatef(250, 40, 0);
    glColor3f(1, 0, 0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420, 100, 0);
    glScalef(0.6, 0.6, 1);
    glColor3f(0, 0.6, 0);
    triangle();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(500, 180, 0);
    glRotatef(45, 0, 0, 1);
    glColor3f(0, 0, 1);
    triangle();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 6 - 2D Transformations");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
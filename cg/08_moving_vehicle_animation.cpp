#include <GL/glut.h>
#include <cmath>

float carX = -180;

void circle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++) {
        float a = i * 3.14159f / 180;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(carX, 0, 0);

    glColor3f(0.1, 0.3, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(100, 120); glVertex2f(300, 120); glVertex2f(280, 190);
    glVertex2f(140, 190); glVertex2f(110, 160);
    glEnd();

    glColor3f(0.2, 0.8, 1);
    glBegin(GL_POLYGON);
    glVertex2f(145, 190); glVertex2f(180, 245);
    glVertex2f(250, 245); glVertex2f(275, 190);
    glEnd();

    glColor3f(0, 0, 0);
    circle(150, 115, 25);
    circle(260, 115, 25);
    glColor3f(0.8, 0.8, 0.8);
    circle(150, 115, 10);
    circle(260, 115, 10);

    glPopMatrix();
    glFlush();
}

void update(int value) {
    carX += 3;
    if (carX > 640) carX = -320;
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 8 - Moving Vehicle Animation");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}
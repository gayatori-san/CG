#include <GL/glut.h>

int xmin = 200, xmax = 440, ymin = 120, ymax = 360;

void drawShape() {
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmax, ymin);
    glVertex2i(320, ymax);
    glEnd();
}

void boundaryFill(int x, int y) {
    unsigned char color[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
    if (color[0] < 10 && color[1] < 10 && color[2] < 10) return;
    if (color[0] > 240 && color[1] > 240 && color[2] > 240) {
        glColor3f(1, 0.5, 0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundaryFill(x + 1, y);
        boundaryFill(x - 1, y);
        boundaryFill(x, y + 1);
        boundaryFill(x, y - 1);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawShape();
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        boundaryFill(x, 480 - y);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 4 - Boundary Fill");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
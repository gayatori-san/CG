#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;

void koch(float x1, float y1, float x2, float y2, int level) {
    if (level == 0) {
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        return;
    }
    float dx = (x2 - x1) / 3, dy = (y2 - y1) / 3;
    float x3 = x1 + dx, y3 = y1 + dy;
    float x5 = x1 + 2 * dx, y5 = y1 + 2 * dy;
    float x4 = x3 + (dx * cos(PI / 3) - dy * sin(PI / 3));
    float y4 = y3 + (dx * sin(PI / 3) + dy * cos(PI / 3));
    koch(x1, y1, x3, y3, level - 1);
    koch(x3, y3, x4, y4, level - 1);
    koch(x4, y4, x5, y5, level - 1);
    koch(x5, y5, x2, y2, level - 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);
    glLineWidth(2);
    glBegin(GL_LINES);
    koch(80, 150, 560, 150, 4);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 7 - Koch Curve");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
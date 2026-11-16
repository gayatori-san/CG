#include <GL/glut.h>

const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
const float xmin = 150, xmax = 450, ymin = 100, ymax = 350;

int code(float x, float y) {
    int c = 0;
    if (x < xmin) c |= LEFT;
    else if (x > xmax) c |= RIGHT;
    if (y < ymin) c |= BOTTOM;
    else if (y > ymax) c |= TOP;
    return c;
}

bool clip(float &x1, float &y1, float &x2, float &y2) {
    int c1 = code(x1, y1), c2 = code(x2, y2);
    while (true) {
        if (!(c1 | c2)) return true;
        if (c1 & c2) return false;
        int c = c1 ? c1 : c2;
        float x, y;
        if (c & TOP) { x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax; }
        else if (c & BOTTOM) { x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin; }
        else if (c & RIGHT) { y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax; }
        else { y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin; }
        if (c == c1) { x1 = x; y1 = y; c1 = code(x1, y1); }
        else { x2 = x; y2 = y; c2 = code(x2, y2); }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin); glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax); glVertex2f(xmin, ymax);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(80, 60); glVertex2i(570, 440);
    glEnd();

    float x1 = 80, y1 = 60, x2 = 570, y2 = 440;
    if (clip(x1, y1, x2, y2)) {
        glColor3f(0, 0, 1);
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(x1, y1); glVertex2f(x2, y2);
        glEnd();
        glLineWidth(1);
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Practical 5 - Cohen Sutherland Clipping");
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
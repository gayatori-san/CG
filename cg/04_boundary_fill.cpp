#include <GL/glut.h>
#include <vector>
#include <utility>

int xmin = 200, xmax = 440, ymin = 120, ymax = 360;

void drawShape() {
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmax, ymin);
    glVertex2i(320, ymax);
    glEnd();
}

void boundaryFill(int startX, int startY) {
    // Ignore clicks outside the triangle.
    if (startY < ymin || startY > ymax) return;

    float inset = (320.0f - xmin) * (startY - ymin) / (ymax - ymin);
    int left = xmin + (int)inset;
    int right = xmax - (int)inset;
    if (startX < left || startX > right) return;

    // Use an explicit stack instead of recursion to avoid stack overflow.
    std::vector<std::pair<int, int>> pixels;
    pixels.push_back({startX, startY});

    while (!pixels.empty()) {
        std::pair<int, int> point = pixels.back();
        pixels.pop_back();

        int x = point.first;
        int y = point.second;
        if (x < xmin || x > xmax || y < ymin || y > ymax) continue;

        unsigned char color[3];
        glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);

        // Stop at the black boundary and skip pixels already filled.
        if (color[0] < 10 && color[1] < 10 && color[2] < 10) continue;
        if (!(color[0] > 240 && color[1] > 240 && color[2] > 240)) continue;

        glColor3f(1, 0.5, 0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        pixels.push_back({x + 1, y});
        pixels.push_back({x - 1, y});
        pixels.push_back({x, y + 1});
        pixels.push_back({x, y - 1});
    }

    glFlush();
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
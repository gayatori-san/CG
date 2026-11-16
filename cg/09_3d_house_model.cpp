#include <GL/glut.h>

float angleY = 25;

void cube(float x, float y, float z, float sx, float sy, float sz,
          float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(sx, sy, sz);
    glColor3f(r, g, b);
    glutSolidCube(1);
    glPopMatrix();
}

void roof() {
    glColor3f(0.65, 0.12, 0.08);
    glBegin(GL_QUADS);
    glVertex3f(-2.8, 3, 2.3); glVertex3f(0, 4.7, 2.3);
    glVertex3f(0, 4.7, -2.3); glVertex3f(-2.8, 3, -2.3);
    glVertex3f(0, 4.7, 2.3); glVertex3f(2.8, 3, 2.3);
    glVertex3f(2.8, 3, -2.3); glVertex3f(0, 4.7, -2.3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(9, 7, 11, 0, 1.5, 0, 0, 1, 0);
    glRotatef(angleY, 0, 1, 0);

    cube(0, -0.15, 0, 15, 0.3, 15, 0.2, 0.65, 0.2);
    cube(0, 1.5, 0, 5, 3, 4, 0.9, 0.82, 0.65);
    roof();
    cube(0, 0.9, 2.03, 1, 1.8, 0.08, 0.35, 0.16, 0.07);
    cube(-1.55, 1.9, 2.04, 1.1, 1.1, 0.08, 0.2, 0.55, 0.9);
    cube(1.55, 1.9, 2.04, 1.1, 1.1, 0.08, 0.2, 0.55, 0.9);
    glutSwapBuffers();
}

void special(int key, int, int) {
    if (key == GLUT_KEY_LEFT) angleY -= 5;
    if (key == GLUT_KEY_RIGHT) angleY += 5;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Practical 9 - 3D House Model");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.75, 0.85, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800.0 / 600.0, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(display);
    glutSpecialFunc(special);
    glutMainLoop();
    return 0;
}
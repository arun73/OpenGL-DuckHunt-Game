#include <GL/freeglut.h>
#include "callbackfunctions.h"
#include "game.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (appState == START_SCREEN) {
        startScreen();
    } else if (appState == GAME_SCREEN) {
        simulationScreen();
    }

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(XMIN, XMAX, YMIN * (GLfloat) h / (GLfloat) w, YMAX * (GLfloat) h / (GLfloat) w);
    else
        gluOrtho2D(XMIN * (GLfloat) w / (GLfloat) h, XMAX * (GLfloat) w / (GLfloat) h, YMIN, YMAX);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {

    glutPostRedisplay();
}

void normalKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 27:    // ESC key
            if (appState == START_SCREEN)
                exit(EXIT_SUCCESS);
        case 13:    // Enter key
            appState = GAME_SCREEN;
            break;
        case 'q':
            appState = START_SCREEN;
            break;
        case 'i':
            instructionMenuVisible = !instructionMenuVisible;
            break;
        default:
            break;
    }
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        default:
            break;
    }
}

#include "graphics.h"

void desenha_circulo(float x, float y, float raio){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i+=5) {
        glVertex2d( raio*cos(i/180.0*M_PI) + x, raio*sin(i/180.0*M_PI) + y);
    }
    glEnd();
}

void desenha_circunferencia(float x, float y, float raio){
    glColor3f(0.0, 0.0, 0.5);
    for (int i = 0; i <= 360; i+=10) {
        glBegin(GL_LINE_STRIP);
            glVertex2d( raio*cos(i/180.0*M_PI) + x, raio*sin(i/180.0*M_PI) + y);
            glVertex2d( raio*cos((i+7)/180.0*M_PI) + x, raio*sin((i+7)/180.0*M_PI) + y);
        glEnd();
    }
}

void desenha_triangulo(float x, float y, float raio){
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = -30; i < 360; i+=120) {
        glVertex2d( raio*cos(i/180.0*M_PI) + x, raio*sin(i/180.0*M_PI) + y);
    }
    glEnd();
}

void desenha_linha(float x1, float y1, float x2, float y2){
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x1, y1);  // Ponto inicial (canto superior esquerdo)
    glVertex2f(x2, y2);  // Ponto inicial (canto superior esquerdo)
    glEnd();
}

void configurar_interface(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Tower Defense com Threads e Semáforos");
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

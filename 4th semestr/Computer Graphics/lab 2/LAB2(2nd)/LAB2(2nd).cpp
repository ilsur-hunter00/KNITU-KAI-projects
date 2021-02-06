#include "pch.h"
#include <GL/glut.h> 
#include <stdlib.h> 
#include <math.h> 
#include <windows.h> 

#define PI 3.1459 

GLfloat R = 840.0 / 680; //Форматное соотношение 
GLfloat w = 80;        //Ширина мирового окна 
GLfloat h;           //Высота мирового окна 
GLfloat l, r, b, t;  //Параметры мирового окна 
GLfloat f = 30.0;
void init(void) {
	//Расчет параметров мирового окна 
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2;
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void reshape(GLsizei W, GLsizei H) {
	if (R > W / H)
		glViewport(0, 0, W, W / R);
	else glViewport(0, 0, H*R, H);
}

void showAxis(void) {
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(0, -t/2);
	glVertex2f(0, t/1.5);
	glVertex2f(-r/2, 0);
	glVertex2f(r/2, 0);
	glEnd();
}

void showAxis1(void) {
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, t/4);
	glVertex2f(0, 0);
	glVertex2f(r/10, 0);
	glEnd();
}

void fig0(void) {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-10.0, -10.0);
	glVertex2f(-10.0, 10.0);
	glVertex2f(0.0, 18.0);
	glVertex2f(10.0, 10.0);
	glVertex2f(10.0, -10.0);
	glEnd();
}

void fig1(void) {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.0, 0.0);
	glVertex2f(-1.0, 6.0);
	glVertex2f(1.0, 6.0);
	glVertex2f(1.0, 0.0);
	glEnd();
}

void scene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	showAxis();
	fig0();
	glPushMatrix();   
	glTranslatef(7.0, 12.5, 0.0);
	glRotatef(-90.0, 0.0, 0.0, 1.0);
	glScalef(-2.0, 2.0, 2.0);
	showAxis1();
	fig1();
	glPopMatrix( );
	glutSwapBuffers();  
	glPushMatrix();
	glTranslatef(-7.0, 12.5, 0.0);
	glRotatef(39.0, 0.0, 0.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	showAxis1();
	fig1();
	glPopMatrix();
	glutSwapBuffers();
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  
	glutInitWindowSize(840, 680);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Myprog");
	glutReshapeFunc(reshape);
	glutDisplayFunc(scene);
	//glutIdleFunc(scene);  
	init();
	glutMainLoop();
}
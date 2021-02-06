#include "pch.h"
#include <gl/glut.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <io.h>

int count1 = 0, count2 = 0;
GLfloat angle = 0, pangle = 0;
GLfloat angle2 = 0, pangle2 = 0;
GLfloat myLightPosition[] = { 1.0, 2.0, 1.0, 1.0 };

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawPoly() {

	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0.577);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(1, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 1, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glEnd();
}

void drawLight() {
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle2, 0, 1, 0);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]);	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
}

void Axis() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(2, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 2, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 2);
	glEnd();
}

void myDisplay()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
	glRotatef(angle2, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix();
	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	drawPoly();
	glPopMatrix();
	glDisable(GL_LIGHTING);
	Axis();
	drawLight();
	glPopMatrix();
	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	if (width < height)
		glViewport(0, 0, width, width);
	else
		glViewport(0, 0, height, height);
}

void myIdle()
{
	angle += pangle;
	if (angle > 360)
		angle = 0;
	angle2 += pangle2;
	if (angle2 > 360)
		angle2 = 0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'o') {
		if (count1 % 2 == 0)
			pangle = 0.2;
		else
			pangle = 0;
		count1++;
	}
	else if (key == 'l') {
		if (count2 % 2 == 0)
			pangle2 = 0.2;
		else
			pangle2 = 0;
		count2++;
	}

	if (key == 'f') {
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	else if (key == 'b') {
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("LAB 4");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}




/*#include "pch.h"
#include <gl\glut.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
GLfloat angle = 0; GLfloat sc = 1.0;
GLfloat pos = 1.0, rot = 0;
int fig_save;

void init(void)
{
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(pos * 4, 4, 3, 0, 0, 0, 0, 1, 0); // VM=Fwe
	GLfloat myLightPosition[] = { 15.0, 15.0, 15.0, 1.0 }; // Источник света в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition); //Позиция ис-точника света будет преобразована в CKe
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix(); //Сохраняем VM=Fwe
		//glRotatef(-angle, 1, 0, 0); // VM=Fwe*R
	glRotatef(-angle * rot, 0, 1, 0); // VM=Fwe*R*R
	//glRotatef(angle, 0, 0, 1); // VM=Fwe*R*R*R
	glScalef(sc, sc, sc);

	switch (fig_save) {
	case 0:
		glutSolidIcosahedron();
		break;
	case 1:
		glutSolidDodecahedron();
		break;
	}
	//glutSolidIcosahedron();
	//glutSolidIcosahedron();

	glPopMatrix(); // Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, 1, 1); glVertex3f(1, 2, 3); glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
	Sleep(3);
}
void myReshape(int width, int height)
{
	if (width / height < 1) glViewport(0, 0, width, width);
	else glViewport(0, 0, height, height);
}
void myIdle()
{
	angle += 0.5;
	if (angle > 360.0) angle = 0;
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		fig_save = 1;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		fig_save = 0;
	}
}
void keys(unsigned char key, int x, int y) {
	if (key == 'X')
	{
		rot = 1;
	}
	else if (key == 'x')
	{
		rot = 0;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3 LAB");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	init();
	glutMainLoop();

}*/
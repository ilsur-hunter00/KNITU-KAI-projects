#include <gl/glut.h>
#include <gl/glu.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <io.h>
#include "C:\Users\ilsur\Downloads\Glaux.h"
#pragma comment(lib, "C:\\Users\\ilsur\\Downloads\\Glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

int count1 = 0, count2 = 0;
GLfloat angle = 0, pangle = 0;
GLfloat angle2 = 0, pangle2 = 0;
GLfloat myLightPosition[] = { 2.0, 2.0, 1.0, 1.0 };
GLfloat pos = 1.0;
GLuint list1 = 0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	AUX_RGBImageRec* img1 = auxDIBImageLoadA("C:\\Users\\ilsur\\Downloads\\first.bmp");

	list1 = glGenLists(1); //Генерация незадействованного индекса списка
	glNewList(list1, GL_COMPILE); //Создание списка и накопление команд
	glEnable(GL_DEPTH_TEST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glEnable(GL_TEXTURE_2D);

	// ромб

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(1.14, 0.32, 0.1);
	glTexCoord2f(0, 1); glVertex3f(1.36, -0.07, 0.1);
	glTexCoord2f(1, 0); glVertex3f(1.58, 0.32, 0.1);
	glTexCoord2f(1, 1); glVertex3f(1.36, 0.64, 0.1);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img1->sizeX, img1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img1->data);

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.36, 0.64, 0);
	glTexCoord2f(0, 1); glVertex3f(1.58, 0.32, 0);
	glTexCoord2f(1, 0); glVertex3f(1.36, -0.07, 0);
	glTexCoord2f(1, 1); glVertex3f(1.14, 0.32, 0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, 0.577, 0);
	glVertex3f(1.36, 0.64, 0);
	glVertex3f(1.14, 0.32, 0);
	glVertex3f(1.14, 0.32, 0.1);
	glVertex3f(1.36, 0.64, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(1.14, 0.32, 0);
	glVertex3f(1.36, -0.07, 0);
	glVertex3f(1.36, -0.07, 0.1);
	glVertex3f(1.14, 0.32, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(1.58, 0.32, 0.1);
	glVertex3f(1.36, -0.07, 0.1);
	glVertex3f(1.36, -0.07, 0);
	glVertex3f(1.58, 0.32, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0);
	glVertex3f(1.36, 0.64, 0.1);
	glVertex3f(1.58, 0.32, 0.1);
	glVertex3f(1.58, 0.32, 0);
	glVertex3f(1.36, 0.64, 0);
	glEnd();

	glEndList();
}

void drawPoly() {

	GLfloat mmyDiffuse[] = { 0, 0, 1, 1 }; // задаем цвет крыльев
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mmyDiffuse);

	// крылья левые 

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0, 0.46, 0.1);
	glVertex3f(0.07, 0.36, 0.1);
	glVertex3f(0.77, 0.36, 0.1);
	glVertex3f(0.88, 0.46, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(0.88, 0.46, 0.1);
	glVertex3f(0.77, 0.36, 0.1);
	glVertex3f(0.77, 0.36, 0);
	glVertex3f(0.88, 0.46, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.88, 0.46, 0);
	glVertex3f(0.77, 0.36, 0);
	glVertex3f(0.07, 0.36, 0);
	glVertex3f(0, 0.46, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(0, 0.46, 0);
	glVertex3f(0.1, 0.36, 0);
	glVertex3f(0.1, 0.36, 0.1);
	glVertex3f(0, 0.46, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0, 0.46, 0);
	glVertex3f(0, 0.46, 0.1);
	glVertex3f(0.88, 0.46, 0.1);
	glVertex3f(0.88, 0.46, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.07, 0.36, 0.1);
	glVertex3f(0.07, 0.36, 0);
	glVertex3f(0.77, 0.36, 0);
	glVertex3f(0.77, 0.36, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.1, 0.34, 0.1);
	glVertex3f(0.17, 0.23, 0.1);
	glVertex3f(0.77, 0.23, 0.1);
	glVertex3f(0.77, 0.34, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0.77, 0.34, 0.1);
	glVertex3f(0.77, 0.23, 0.1);
	glVertex3f(0.77, 0.23, 0);
	glVertex3f(0.77, 0.34, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.77, 0.34, 0);
	glVertex3f(0.77, 0.23, 0);
	glVertex3f(0.17, 0.23, 0);
	glVertex3f(0.1, 0.34, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(0.1, 0.34, 0);
	glVertex3f(0.17, 0.23, 0);
	glVertex3f(0.17, 0.23, 0.1);
	glVertex3f(0.1, 0.34, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.1, 0.34, 0);
	glVertex3f(0.1, 0.34, 0.1);
	glVertex3f(0.77, 0.34, 0.1);
	glVertex3f(0.77, 0.34, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.17, 0.23, 0.1);
	glVertex3f(0.17, 0.23, 0);
	glVertex3f(0.77, 0.23, 0);
	glVertex3f(0.77, 0.23, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.45, 0.21, 0.1);
	glVertex3f(0.54, 0.1, 0.1);
	glVertex3f(0.88, 0.1, 0.1);
	glVertex3f(0.77, 0.21, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0);
	glVertex3f(0.77, 0.21, 0.1);
	glVertex3f(0.88, 0.1, 0.1);
	glVertex3f(0.88, 0.1, 0);
	glVertex3f(0.77, 0.21, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.77, 0.21, 0);
	glVertex3f(0.88, 0.1, 0);
	glVertex3f(0.54, 0.1, 0);
	glVertex3f(0.45, 0.21, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(0.45, 0.21, 0);
	glVertex3f(0.54, 0.1, 0);
	glVertex3f(0.54, 0.1, 0.1);
	glVertex3f(0.45, 0.21, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.45, 0.21, 0);
	glVertex3f(0.45, 0.21, 0.1);
	glVertex3f(0.77, 0.21, 0.1);
	glVertex3f(0.77, 0.21, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.54, 0.1, 0.1);
	glVertex3f(0.54, 0.1, 0);
	glVertex3f(0.88, 0.1, 0);
	glVertex3f(0.88, 0.1, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.68, 0.08, 0.1);
	glVertex3f(0.75, 0, 0.1);
	glVertex3f(1.2, 0, 0.1);
	glVertex3f(1.29, 0.08, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(1.29, 0.08, 0.1);
	glVertex3f(1.2, 0, 0.1);
	glVertex3f(1.2, 0, 0);
	glVertex3f(1.29, 0.08, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.29, 0.08, 0);
	glVertex3f(1.2, 0, 0);
	glVertex3f(0.75, 0, 0);
	glVertex3f(0.68, 0.08, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(0.68, 0.08, 0);
	glVertex3f(0.75, 0, 0);
	glVertex3f(0.75, 0, 0.1);
	glVertex3f(0.68, 0.08, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.68, 0.08, 0);
	glVertex3f(0.68, 0.08, 0.1);
	glVertex3f(1.29, 0.08, 0.1);
	glVertex3f(1.29, 0.08, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.75, 0, 0.1);
	glVertex3f(0.75, 0, 0);
	glVertex3f(1.2, 0, 0);
	glVertex3f(1.2, 0, 0.1);
	glEnd();

	// правое крыло

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.88, 0.46, 0.1);
	glVertex3f(1.98, 0.36, 0.1);
	glVertex3f(2.68, 0.36, 0.1);
	glVertex3f(2.75, 0.46, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(2.75, 0.46, 0.1);
	glVertex3f(2.68, 0.36, 0.1);
	glVertex3f(2.68, 0.36, 0);
	glVertex3f(2.75, 0.46, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(2.75, 0.46, 0);
	glVertex3f(2.68, 0.36, 0);
	glVertex3f(1.98, 0.36, 0);
	glVertex3f(1.88, 0.46, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(1.88, 0.46, 0);
	glVertex3f(1.98, 0.36, 0);
	glVertex3f(1.98, 0.36, 0.1);
	glVertex3f(1.88, 0.46, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.88, 0.46, 0);
	glVertex3f(1.88, 0.46, 0.1);
	glVertex3f(2.75, 0.46, 0.1);
	glVertex3f(2.75, 0.46, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.98, 0.36, 0.1);
	glVertex3f(1.98, 0.36, 0);
	glVertex3f(2.68, 0.36, 0);
	glVertex3f(2.68, 0.36, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.98, 0.34, 0.1);
	glVertex3f(1.98, 0.23, 0.1);
	glVertex3f(2.61, 0.23, 0.1);
	glVertex3f(2.68, 0.34, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(2.68, 0.34, 0.1);
	glVertex3f(2.61, 0.23, 0.1);
	glVertex3f(2.61, 0.23, 0);
	glVertex3f(2.68, 0.34, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(2.68, 0.34, 0);
	glVertex3f(2.61, 0.23, 0);
	glVertex3f(1.98, 0.23, 0);
	glVertex3f(1.98, 0.34, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.98, 0.34, 0);
	glVertex3f(1.98, 0.23, 0);
	glVertex3f(1.98, 0.23, 0.1);
	glVertex3f(1.98, 0.34, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.98, 0.34, 0);
	glVertex3f(1.98, 0.34, 0.1);
	glVertex3f(2.68, 0.34, 0.1);
	glVertex3f(2.68, 0.34, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.98, 0.23, 0.1);
	glVertex3f(1.98, 0.23, 0);
	glVertex3f(2.61, 0.23, 0);
	glVertex3f(2.61, 0.23, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.98, 0.21, 0.1);
	glVertex3f(1.88, 0.1, 0.1);
	glVertex3f(2.18, 0.1, 0.1);
	glVertex3f(2.29, 0.21, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0);
	glVertex3f(2.29, 0.21, 0.1);
	glVertex3f(2.18, 0.1, 0.1);
	glVertex3f(2.18, 0.1, 0);
	glVertex3f(2.29, 0.21, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(2.29, 0.21, 0);
	glVertex3f(2.18, 0.1, 0);
	glVertex3f(1.88, 0.1, 0);
	glVertex3f(1.98, 0.21, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, 0.577, 0);
	glVertex3f(1.98, 0.21, 0);
	glVertex3f(1.88, 0.1, 0);
	glVertex3f(1.88, 0.1, 0.1);
	glVertex3f(1.98, 0.21, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.98, 0.21, 0);
	glVertex3f(1.98, 0.21, 0.1);
	glVertex3f(2.29, 0.21, 0.1);
	glVertex3f(2.29, 0.21, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.88, 0.1, 0.1);
	glVertex3f(1.88, 0.1, 0);
	glVertex3f(2.18, 0.1, 0);
	glVertex3f(2.18, 0.1, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.47, 0.08, 0.1);
	glVertex3f(1.56, 0, 0.1);
	glVertex3f(2.01, 0, 0.1);
	glVertex3f(2.08, 0.08, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(2.08, 0.08, 0.1);
	glVertex3f(2.01, 0, 0.1);
	glVertex3f(2.01, 0, 0);
	glVertex3f(2.08, 0.08, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(2.08, 0.08, 0);
	glVertex3f(2.01, 0, 0);
	glVertex3f(1.56, 0, 0);
	glVertex3f(1.47, 0.08, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(1.47, 0.08, 0);
	glVertex3f(1.56, 0, 0);
	glVertex3f(1.56, 0, 0.1);
	glVertex3f(1.47, 0.08, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.47, 0.08, 0);
	glVertex3f(1.47, 0.08, 0.1);
	glVertex3f(2.08, 0.08, 0.1);
	glVertex3f(2.08, 0.08, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.56, 0, 0.1);
	glVertex3f(1.56, 0, 0);
	glVertex3f(2.01, 0, 0);
	glVertex3f(2.01, 0, 0.1);
	glEnd();

	GLfloat myDiffuse[] = { 1, 0, 0, 1 }; // задаем цвет букв К А И
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);

	// передняя стенка буквы К
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1, 0.18, 0.2);
	glVertex3f(1.05, 0.1, 0.2);
	glVertex3f(1.22, 0.1, 0.2);
	glVertex3f(1.14, 0.275, 0.2);
	glVertex3f(1.22, 0.45, 0.2);
	glVertex3f(1.05, 0.45, 0.2);
	glVertex3f(1, 0.37, 0.2);
	glVertex3f(1, 0.45, 0.2);
	glVertex3f(0.85, 0.45, 0.2);
	glVertex3f(0.85, 0.1, 0.2);
	glVertex3f(1, 0.1, 0.2);
	glEnd();

	// задняя стенка буквы К

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1, 0.18, 0.1);
	glVertex3f(1, 0.1, 0.1);
	glVertex3f(0.85, 0.1, 0.1);
	glVertex3f(0.85, 0.45, 0.1);
	glVertex3f(1, 0.45, 0.1);
	glVertex3f(1, 0.37, 0.1);
	glVertex3f(1.05, 0.45, 0.1);
	glVertex3f(1.22, 0.45, 0.1);
	glVertex3f(1.14, 0.275, 0.1);
	glVertex3f(1.22, 0.1, 0.1);
	glVertex3f(1.05, 0.1, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(0.85, 0.45, 0.1);
	glVertex3f(0.85, 0.1, 0.1);
	glVertex3f(0.85, 0.1, 0.2);
	glVertex3f(0.85, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1, 0.45, 0.1);
	glVertex3f(0.85, 0.45, 0.1);
	glVertex3f(0.85, 0.45, 0.2);
	glVertex3f(1, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1, 0.1, 0.1);
	glVertex3f(0.85, 0.1, 0.1);
	glVertex3f(0.85, 0.1, 0.2);
	glVertex3f(1, 0.1, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1, 0.45, 0.2);
	glVertex3f(1, 0.37, 0.2);
	glVertex3f(1, 0.37, 0.1);
	glVertex3f(1, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1, 0.18, 0.2);
	glVertex3f(1, 0.1, 0.2);
	glVertex3f(1, 0.1, 0.1);
	glVertex3f(1, 0.18, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, 0.577, 0);
	glVertex3f(1.05, 0.45, 0.1);
	glVertex3f(1, 0.37, 0.1);
	glVertex3f(1, 0.37, 0.2);
	glVertex3f(1.05, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(1, 0.18, 0.1);
	glVertex3f(1.05, 0.1, 0.1);
	glVertex3f(1.05, 0.1, 0.2);
	glVertex3f(1, 0.18, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.22, 0.45, 0.1);
	glVertex3f(1.05, 0.45, 0.1);
	glVertex3f(1.05, 0.45, 0.2);
	glVertex3f(1.22, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.22, 0.1, 0.1);
	glVertex3f(1.05, 0.1, 0.1);
	glVertex3f(1.05, 0.1, 0.2);
	glVertex3f(1.22, 0.1, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(1.22, 0.45, 0.2);
	glVertex3f(1.14, 0.275, 0.2);
	glVertex3f(1.14, 0.275, 0.1);
	glVertex3f(1.22, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0);
	glVertex3f(1.14, 0.275, 0.2);
	glVertex3f(1.22, 0.1, 0.2);
	glVertex3f(1.22, 0.1, 0.1);
	glVertex3f(1.14, 0.275, 0.1);
	glEnd();

	// Буква А
	// Перед 

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.36, 0.45, 0.2);
	glVertex3f(1.22, 0.1, 0.2);
	glVertex3f(1.36, 0.1, 0.2);
	glVertex3f(1.435, 0.32, 0.2);
	/*glVertex3f(1.39, 0.17, 0.2);
	glVertex3f(1.47, 0.17, 0.2);*/
	glVertex3f(1.5, 0.1, 0.2);
	glVertex3f(1.64, 0.1, 0.2);
	glVertex3f(1.51, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.4, 0.22, 0.2);
	glVertex3f(1.38, 0.17, 0.2);
	glVertex3f(1.49, 0.17, 0.2);
	glVertex3f(1.46, 0.22, 0.2);
	glEnd();

	// зад

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.51, 0.45, 0.1);
	glVertex3f(1.64, 0.1, 0.1);
	glVertex3f(1.5, 0.1, 0.1);
	glVertex3f(1.435, 0.32, 0.1);
	glVertex3f(1.36, 0.1, 0.1);
	glVertex3f(1.22, 0.1, 0.1);
	glVertex3f(1.36, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.46, 0.22, 0.1);
	glVertex3f(1.49, 0.17, 0.1);
	glVertex3f(1.38, 0.17, 0.1);
	glVertex3f(1.4, 0.22, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, 0.577, 0);
	glVertex3f(1.36, 0.45, 0.1);
	glVertex3f(1.22, 0.1, 0.1);
	glVertex3f(1.22, 0.1, 0.2);
	glVertex3f(1.36, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, 0.577, 0);
	glVertex3f(1.5, 0.45, 0.2);
	glVertex3f(1.64, 0.1, 0.2);
	glVertex3f(1.64, 0.1, 0.1);
	glVertex3f(1.5, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.36, 0.45, 0.1);
	glVertex3f(1.36, 0.45, 0.2);
	glVertex3f(1.5, 0.45, 0.2);
	glVertex3f(1.5, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.22, 0.1, 0.2);
	glVertex3f(1.22, 0.1, 0.1);
	glVertex3f(1.36, 0.1, 0.1);
	glVertex3f(1.36, 0.1, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.5, 0.1, 0.2);
	glVertex3f(1.5, 0.1, 0.1);
	glVertex3f(1.64, 0.1, 0.1);
	glVertex3f(1.64, 0.1, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.38, 0.17, 0.2);
	glVertex3f(1.38, 0.17, 0.1);
	glVertex3f(1.49, 0.17, 0.1);
	glVertex3f(1.49, 0.17, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(1.38, 0.17, 0.2);
	glVertex3f(1.36, 0.1, 0.2);
	glVertex3f(1.36, 0.1, 0.1);
	glVertex3f(1.38, 0.17, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(1.46, 0.17, 0.1);
	glVertex3f(1.49, 0.1, 0.1);
	glVertex3f(1.49, 0.1, 0.2);
	glVertex3f(1.46, 0.17, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(1.435, 0.32, 0.2);
	glVertex3f(1.4, 0.22, 0.2);
	glVertex3f(1.4, 0.22, 0.1);
	glVertex3f(1.435, 0.32, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, -0.577, 0);
	glVertex3f(1.435, 0.32, 0.1);
	glVertex3f(1.46, 0.22, 0.1);
	glVertex3f(1.46, 0.22, 0.2);
	glVertex3f(1.435, 0.32, 0.2);
	glEnd();

	/*glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.4, 0.22, 0.1);
	glVertex3f(1.4, 0.22, 0.2);
	glVertex3f(1.46, 0.22, 0.2);
	glVertex3f(1.46, 0.22, 0.1);
	glEnd();*/

	// Буква И
	// Перед 

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.86, 0.21, 0.2);
	glVertex3f(1.86, 0.1, 0.2);
	glVertex3f(2.01, 0.1, 0.2);
	glVertex3f(2.01, 0.45, 0.2);
	glVertex3f(1.84, 0.45, 0.2);
	glVertex3f(1.79, 0.32, 0.2);
	glVertex3f(1.79, 0.45, 0.2);
	glVertex3f(1.64, 0.45, 0.2);
	glVertex3f(1.64, 0.1, 0.2);
	glVertex3f(1.81, 0.1, 0.2);
	glEnd();

	// Зад 

	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.86, 0.21, 0.1);
	glVertex3f(1.81, 0.1, 0.1);
	glVertex3f(1.64, 0.1, 0.1);
	glVertex3f(1.64, 0.45, 0.1);
	glVertex3f(1.79, 0.45, 0.1);
	glVertex3f(1.79, 0.32, 0.1);
	glVertex3f(1.84, 0.45, 0.1);
	glVertex3f(2.01, 0.45, 0.1);
	glVertex3f(2.01, 0.1, 0.1);
	glVertex3f(1.86, 0.1, 0.1);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.64, 0.45, 0.1);
	glVertex3f(1.64, 0.1, 0.1);
	glVertex3f(1.64, 0.1, 0.2);
	glVertex3f(1.64, 0.45, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(2.01, 0.45, 0.2);
	glVertex3f(2.01, 0.1, 0.2);
	glVertex3f(2.01, 0.1, 0.1);
	glVertex3f(2.01, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.64, 0.45, 0.1);
	glVertex3f(1.64, 0.45, 0.2);
	glVertex3f(1.79, 0.45, 0.2);
	glVertex3f(1.79, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.84, 0.45, 0.1);
	glVertex3f(1.84, 0.45, 0.2);
	glVertex3f(2.01, 0.45, 0.2);
	glVertex3f(2.01, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.64, 0.1, 0.2);
	glVertex3f(1.64, 0.1, 0.1);
	glVertex3f(1.79, 0.1, 0.1);
	glVertex3f(1.79, 0.1, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.81, 0.1, 0.2);
	glVertex3f(1.81, 0.1, 0.1);
	glVertex3f(2.01, 0.1, 0.1);
	glVertex3f(2.01, 0.1, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(1.79, 0.45, 0.2);
	glVertex3f(1.79, 0.32, 0.2);
	glVertex3f(1.79, 0.32, 0.1);
	glVertex3f(1.79, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.86, 0.21, 0.1);
	glVertex3f(1.86, 0.1, 0.1);
	glVertex3f(1.86, 0.1, 0.2);
	glVertex3f(1.86, 0.21, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-0.577, 0.577, 0);
	glVertex3f(1.84, 0.45, 0.2);
	glVertex3f(1.79, 0.32, 0.2);
	glVertex3f(1.79, 0.32, 0.1);
	glVertex3f(1.84, 0.45, 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.577, -0.577, 0);
	glVertex3f(1.86, 0.21, 0.2);
	glVertex3f(1.81, 0.1, 0.2);
	glVertex3f(1.81, 0.1, 0.1);
	glVertex3f(1.86, 0.21, 0.1);
	glEnd();

}

void drawLight() {
	glRotatef(angle2, 0, 1, 0);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]);
	glVertex3f(0.0, 0.0, 0.0);
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
	gluLookAt(pos*3, pos*4, pos*3, 0, 0, 0, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
	glRotatef(angle2, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix();
	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	GLfloat mmyDiffuse[] = { 0, 0, 1, 1 }; // задаем цвет крыльев
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mmyDiffuse);
	glCallList(list1);
	//drawTexture();
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
	// Вращение фигуры и луча

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

	// показ внешних и внутренних граней

	if (key == 'f') {
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	else if (key == 'b') {
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}

	// Масштабирование фигуры

	if (key == 'X' || key == 'x')
	{
		pos += 0.05;
	}
	if (key == 'Z' || key == 'z')
	{
		pos -= 0.05;
	}
}

void mouseButton(int button, int state, int x, int y) { // Наложение текстур
	if (button == GLUT_LEFT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
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
	glutMouseFunc(mouseButton);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}
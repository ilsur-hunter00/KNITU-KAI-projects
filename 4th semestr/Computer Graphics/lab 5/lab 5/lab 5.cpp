﻿#include <gl/glut.h>
#include <gl/glu.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <io.h>
#include <iostream>
#include "C:\Users\ilsur\Downloads\Glaux.h"
#pragma comment(lib, "C:\\Users\\ilsur\\Downloads\\Glaux.lib")
#pragma comment(lib, "legacy_stdio_definitions.lib")

int count1 = 0, count2 = 0;
GLfloat angle = 0, pangle = 0;
GLfloat angle2 = 0, pangle2 = 0;
GLuint list1 = 0, list2 = 0, list3;
GLfloat myLightPosition[] = { 1.0, 2.0, 1.0, 1.0 };
GLfloat ambient[] = { 0.19125,0.0735,0.0225,1 };
GLfloat difuse[] = { 0.7038, 0.27048, 0.0828, 1 };
GLfloat specular[] = { 0.256777,0.137622 ,0.086014 };
GLfloat shinines[] = { 12.8 };

void init(void)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	AUX_RGBImageRec* img1 = auxDIBImageLoadA("C:\\Users\\ilsur\\Downloads\\first.bmp");  
	AUX_RGBImageRec* img2 = auxDIBImageLoadA("C:\\Users\\ilsur\\Downloads\\second.bmp"); 
	AUX_RGBImageRec* img3 = auxDIBImageLoadA("C:\\Users\\ilsur\\Downloads\\third.bmp");

	//Фигура

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
	list1 = glGenLists(1); 
	glNewList(list1, GL_COMPILE); 

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3f(1, 0, -0.5);
	glTexCoord2f(0, 1); glVertex3f(1, 0, 0.5);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img1->sizeX, img1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img1->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1, 0, 0.5);
	glTexCoord2f(1, 0); glVertex3f(0.75, 0.5, 0.25);
	glTexCoord2f(1, 1); glVertex3f(0.25, 0.5, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img3->sizeX, img3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img3->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glNormal3f(0.5, 0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(1, 0, 0.5);
	glTexCoord2f(0, 1); glVertex3f(1, 0, -0.5);
	glTexCoord2f(1, 0); glVertex3f(0.75, 0.5, -0.25);
	glTexCoord2f(1, 1); glVertex3f(0.75, 0.5, 0.25);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img2->sizeX, img2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img2->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0.25, 0.5, 0);
	glTexCoord2f(1, 0); glVertex3f(0.75, 0.5, -0.25);
	glTexCoord2f(1, 1); glVertex3f(1, 0, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0); glVertex3f(0.25, 0.5, 0);
	glTexCoord2f(0, 1); glVertex3f(0.75, 0.5, 0.25);
	glTexCoord2f(1, 0); glVertex3f(0.75, 0.5, -0.25);
	glEnd();
	glEndList();

	// Оси
	list2 = glGenLists(1);  
	glNewList(list2, GL_COMPILE); 
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
	glEndList();

	list3 = glGenLists(1);
	glNewList(list3, GL_COMPILE);
	//glRotatef(angle2, 0, 1, 0);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex3f(myLightPosition[0], myLightPosition[1], myLightPosition[2]);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glEndList();
}

void myDisplay()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(0, 3, 3, 0, 0, 0, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	
	glPushMatrix();
	glRotatef(angle2, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glCallList(list3);
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPushMatrix();
	glRotatef(angle, 0, 1, 0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shinines);

	glCallList(list1);
	glPopMatrix();
	glDisable(GL_LIGHTING);
	glCallList(list2);
	//glRotatef(angle2, 0, 1, 0);
	
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
			pangle = 0.5;
		else
			pangle = 0;
		count1++;
	}
	else if (key == 'l') {
		if (count2 % 2 == 0)
			pangle2 = 0.5;
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

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); 
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	}
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("LAB 5");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keys);
	glutMouseFunc(mouseButton);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	init();
	glutMainLoop();
}

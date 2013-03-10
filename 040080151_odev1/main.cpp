
#include <iostream>
#include <GL/glut.h>
GLdouble angle = 0;

static void Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    glTranslatef(0.f, -10.f, -65.f);
    glPushMatrix();
	////////////////////////////////////
    glRotated(angle, 0, 3, 0);
    glColor3ub(0, 255, 0);
    glColor3f(1, 1, 0);
    gluSphere( quadric , 3 , 32 , 32 );
	glPopMatrix();
	////////// Mars /////////////////
    glPushMatrix();
		glRotated(angle+angle+angle, 0, 3, 0);
		glRotated(angle, 0, 3, 0);
		glColor3ub(0, 255, 0);
		glColor3f(1, 0, 0);
		glTranslatef(10.f, 0.f, 0.f);
		gluSphere( quadric , 1 , 32 , 32 );
	
		glPushMatrix();
			glRotated(angle, 0, 3, 0);
			glRotated(angle, 0, 3, 0);
			glColor3ub(0, 255, 0);
			glColor3f(1, 1, 1);
			glTranslatef(3.f, 0.f, 0.f);
			gluSphere( quadric , 1 , 32 , 32 );
		glPopMatrix();
		glPushMatrix();
			glRotated(angle*2, 0, 3, 0);
			glRotated(angle, 0, 3, 0);
			glColor3ub(0, 255, 0);
			glColor3f(1, 1, 1);
			glTranslatef(5.f, 0.f, 0.f);
			gluSphere( quadric , 1 , 32 , 32 );
		glPopMatrix();
		glPopMatrix();
	////////// Dunya /////////////////
    glPushMatrix();
		glRotated(angle+angle, 0, 3, 0);
		glRotated(angle, 0, 3, 0);
		glColor3ub(0, 255, 0);
		glColor3f(0, 1, 1);
		glTranslatef(20.f, 0.f, 0.f);
		gluSphere( quadric , 1 , 32 , 32 );
		glPushMatrix();
			glRotated(angle, 0, 3, 0);
			glRotated(angle, 0, 3, 0);
			glColor3ub(0, 255, 0);
			glColor3f(1, 1, 1);
			glTranslatef(3.f, 0.f, 0.f);
			gluSphere( quadric , 1 , 32 , 32 );
		glPopMatrix();
		glPushMatrix();
			glRotated(angle*3, 0, 3, 0);
			glRotated(angle, 0, 3, 0);
			glColor3ub(0, 255, 0);
			glColor3f(1, 1, 1);
			glTranslatef(5.f, 0.f, 0.f);
			gluSphere( quadric , 1 , 32 , 32 );
		glPopMatrix();
    glPopMatrix();
	////////// Jupiter /////////////////
    glPushMatrix();
		glRotated(angle, 0, 3, 0);
		glRotated(angle, 0, 3, 0);
		glColor3ub(0, 255, 0);
		glColor3f(1, 0, 1);
		glTranslatef(30.f, 0.f, 0.f);
		gluSphere( quadric , 1 , 32 , 32 );
		glPushMatrix();
			glRotated(angle, 0, 3, 0);
			glRotated(angle, 0, 3, 0);
			glColor3ub(0, 255, 0);
			glColor3f(1, 1, 1);
			glTranslatef(3.f, 0.f, 0.f);
			gluSphere( quadric , 1 , 32 , 32 );
		glPopMatrix();
		glPushMatrix();
			glRotated(angle*4, 0, 3, 0);
			glRotated(angle, 0, 3, 0);
			glColor3ub(0, 255, 0);
			glColor3f(1, 1, 1);
			glTranslatef(5.f, 0.f, 0.f);
			gluSphere( quadric , 1 , 32 , 32 );
		glPopMatrix();
    glPopMatrix();
	//////////////
    glutSwapBuffers();
}
static void timerCallback (int value)
{
    angle ++;
    glutTimerFunc(10, timerCallback, 0);
    glutPostRedisplay();
}

int main (int argc, char ** argv)
{
    GLenum type;
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	type = GLUT_RGB;
	type |= GLUT_DOUBLE;
	type |= GLUT_DEPTH;
    type |= GLUT_MULTISAMPLE;
	glutInitDisplayMode(type);
	glutCreateWindow("Proje 1");
    glClearColor(0.0, 1.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(55, 800/600, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    timerCallback(0);
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>

void mainglutInit( int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(100, 100);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bringing the Joy");
}

void secondInit(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard( unsigned char key, int x, int y )
{

	//Quit
    if ( key == 'q' || key == 'Q') exit(0);

}


void joystick(unsigned int buttonMask, int x, int y, int z)
{
	for(int i = 0; i < 32; i++)
	{
		if(buttonMask & 1)
			printf("1 ");
		else
			printf("0 ");
		buttonMask = buttonMask >> 1;
	}
	printf("\njoystick axes (x, y, z) = (%d, %d, %d)\n", x, y, z);
}

void display()
{
	// Load identity for drawing the white background.
	glLoadIdentity();
	//Make everything black first. This affects everything in window.
	glClear(GL_COLOR_BUFFER_BIT);
	//Change color to white.
	
	
	//Go to pipeline.
	//Pipeline();
	
	glColor3f(1.0, 1.0, 1.0);
	
	//glutSwapBuffers();

}

int main(int argc, char** argv){
	mainglutInit(argc, argv);
	secondInit();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutJoystickFunc(joystick,1);

	glutMainLoop();
	
}
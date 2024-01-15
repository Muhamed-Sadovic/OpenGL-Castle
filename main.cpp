#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27

int sunce = 0;
// Camera position
float x = 0.0, y = -300.0, z = 22.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move
int i;
// Camera direction
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

GLuint texture1;
GLuint texture2;
GLuint texture3;

//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}

void changeSize(int w, int h)
{
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	gluPerspective(45.0, ratio, 0.1, 1000.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}

void update(void)
{
	if (deltaMove) { // update camera position
		x += deltaMove * lx * 0.1;
		y += deltaMove * ly * 0.1;
	}
	glutPostRedisplay(); // redisplay everything
}

void Tree(){
glPushMatrix();
glTranslatef(4.75,.25,3);
//glRotatef(a, 0, 1, 0);
glColor3f(0.133333, 0.545098 , 0.133333);
glutSolidCone(2.5,5, 10, 2);
glPopMatrix();

glPushMatrix();
glTranslatef(4.75,.25,3.9);
//glRotatef(a, 0, 1, 0);
glColor3f(0.133333, 0.545098 , 0.133333);
glutSolidCone(2.5,5, 10, 2);
glPopMatrix();

glPushMatrix();
glTranslatef(4.75,.25,4.75);
//glRotatef(a, 0, 1, 0);
glColor3f(0.133333, 0.545098 , 0.133333);
glutSolidCone(2.5,5, 10, 2);
glPopMatrix();

glPushMatrix();
glTranslatef(6,-0.6,0);
glRotatef(90, 1, 0, 0);
glColor3f(0.823529,0.411765,0.117647);
glRectf(0, 0, -2, 3);
glPopMatrix();
glEnd();
}

void crtajPod()
{
   glColor3f(0.0, 0.7, 0.0);
    glPushMatrix();
         glTranslatef(0,0,0);
         glScalef(150.5, 0.1, 250);
         glutSolidCube(0.9);
    glPopMatrix();
}

void crtajZidove()
{
    glColor3f(0.7, 0.5,0.5);
////////ovo je dole strana/////////////////////////////////////

    glPushMatrix();
        glTranslatef(0,114.0,7);
         glScalef(135, 3, 100);
         glutSolidCube(1);
    glPopMatrix();


    ////////ovo je leva strana/////////////////////////////////////

    glPushMatrix();
        glTranslatef(-67,0.0,7);
         glScalef(3, 230, 100);
         glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-40,-112.0,7);
         glScalef(55, 3, 100);
         glutSolidCube(1);
    glPopMatrix();

    ////////////////desna strana ///////////////////
     glPushMatrix();
        glTranslatef(67,0.0,7);
         glScalef(3, 230, 100);
         glutSolidCube(1);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(40,-115.0,7);
         glScalef(55, 3, 100);
         glutSolidCube(1);
    glPopMatrix();

     // Textura za pod
    //////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture2);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-31.-155,-120,1);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(252, 9, 0.1);
    glTexCoord2d(1.0, 1.0); glVertex3f(252, 235, 0.1);
    glTexCoord2d(0.0, 1.0); glVertex3f(118.7, 235, 0.1);
    glTexCoord2d(0.0, 0.0); glVertex3f(118.7, 9, 0.1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void crtajStubove(){
  glColor3f(0,0,0);
    glPushMatrix();
        glTranslatef(-70,112.0,7);
         glScalef( 10, 6, 106);
         glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(70,112.0,7);
         glScalef( 10, 6, 106);
         glutSolidCube(1);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-70,-113.0,7);
         glScalef( 10, 6, 106);
         glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(70,-113.0,7);
         glScalef( 10, 6, 106);
         glutSolidCube(1);
    glPopMatrix();

}
void crtajVrh()
{
   glColor3f(0.5,0.5,0.5);

    glPushMatrix();
         glTranslatef(-70,114,61);
         glScalef(20, 15,3);
         glutSolidCube(0.9);
    glPopMatrix();

    glColor3f(0.5,0.5,0.5);
     glPushMatrix();
        glTranslatef(-62.3,118.8,64);
         glScalef( 2, 2, 5);
         glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-62.3,109,64);
         glScalef( 2, 2, 5);
         glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-78,109,64);
         glScalef( 2, 2, 5);
         glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-78,118.8,64);
         glScalef( 2, 2, 5);
         glutSolidCube(1);
    glPopMatrix();
}

void crtajKuce()
{
////podloga
glColor3f(0.70,0.43,0.29);
     glPushMatrix();
         glTranslatef(-30,53,5);
         glScalef(35, 23,10);
         glutSolidCube(0.9);
    glPopMatrix();

    //sredina
   glColor3f(0.70,0.43,0.29);
        glPushMatrix();
         glTranslatef(0,49,5);
         glScalef(35, 32,35);
         glutSolidCube(0.9);
    glPopMatrix();
glColor3f(0.70,0.43,0.29);
      glPushMatrix();
         glTranslatef(25,53,5);
         glScalef(35, 23,10);
         glutSolidCube(0.9);
    glPopMatrix();

}

void crtajDrugiStub()
{
    glColor3f(1,1,1);
    glPushMatrix();
        glTranslatef(-14,36.0,7);
         glScalef( 5, 4, 40);
         glutSolidCube(1);
    glPopMatrix();

       glPushMatrix();
        glTranslatef(15,36.0,7);
         glScalef( 5, 4, 40);
         glutSolidCube(1);
    glPopMatrix();
}
void crtajDrugeKuce()
{
    glColor3f(1,0,0);
        glPushMatrix();
         glTranslatef(5,95,5);
         glScalef(15, 15,70);
         glutSolidCube(0.9);
    glPopMatrix();

glColor3f(0.86,0.63,0.28);
    glPushMatrix();
        glTranslatef(5,93.0,36.3);
        glutSolidCone(10,20, 20, 15);
    glPopMatrix();
////prozori
    glColor3f(1,1,1);
        glPushMatrix();
         glTranslatef(7.5,87,30);
         glScalef(2, 0,4);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(2.5,87,30);
         glScalef(2, 0,4);
         glutSolidCube(0.9);
    glPopMatrix();

    ///vrata
 glPushMatrix();
         glTranslatef(5,87,10);
         glScalef(10, 0,14);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajDrvo()
{
    //stablo
    glColor3f(0.647059, 0.4, 0.2);
    glPushMatrix();
         glTranslatef(0,0,6.2);
         glScalef(1.4, 1.4, 10);
         glutSolidCube(0.9);
    glPopMatrix();

    //zimzeleno
    glColor3f(0.2, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(0.0, 0.0, 9.6);
        glutSolidCone(10,15,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 11.6);
        glutSolidCone(9,14,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 13.6);
        glutSolidCone(8,13,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 15.6);
        glutSolidCone(7,12,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 17.1);
        glutSolidCone(6,11,15,21);
    glPopMatrix();

}

void crtajVrata()
{
    glColor3f(0,0,1);
       glPushMatrix();
        glTranslatef(-15,-113.0,7);
         glScalef( 10, 6, 106);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(8,-113.0,7);
         glScalef( 10, 6, 106);
         glutSolidCube(1);
    glPopMatrix();

glColor3f(0,0,1);
     glPushMatrix();
         glTranslatef(-3.5,-113,61);
         glScalef(40, 20,4);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-3.5,-113,63);
         glScalef(30, 20,4);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-3.5,-113,65);
         glScalef(20, 20,4);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-3.5,-113,67);
         glScalef(10, 20,4);
         glutSolidCube(0.9);
    glPopMatrix();
}

void wall()
{
    glRectf(0, 0, 100, 50);
}

void put(){
glTranslatef(30, -15.5, 3);

glPushMatrix();
glScalef(.25, 3, 1);
glColor3f(0.411765,0.411765,0.411765);
wall(); //Black Road
glPopMatrix();

glPushMatrix();
    glTranslatef(12, -1.3, .01);
    glColor3f(1, 1, 1);
    for (i = 0; i < 18; i++)
    {
        glTranslatef(0, 8, 0);
        glRectf(0, 0, 1, 4); //White Bricks on Road
    }
glPopMatrix();

glPushMatrix();
    glTranslatef(2, -1.3, .01);
    glColor3f(1, 0.54902, 0);
    for (i = 0; i < 150; i++)
    {
        glTranslatef(0, 1, 0);
        glRectf(0, 0, .5, 1); //Yellow line on Road
    }
glPopMatrix();

glPushMatrix();
    glTranslatef(22.5, -1.3, .01);
    glColor3f(1, 0.54902, 0);
    for (i = 0; i < 150; i++)
    {
        glTranslatef(0, 1, 0);
        glRectf(0, 0, .5, 1); //Yellow line on Road
    }
glPopMatrix();
}

void renderScene(void)
{
    glShadeModel(GL_SMOOTH);
     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);
     glEnable(GL_LIGHTING);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);

     GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.0, 1.9 };
     GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 0.0 };
     GLfloat light_positionSunce[] = { 10.0, 10.0, 20.0, 0.0 };

     GLfloat mat_amb_diff[] = { 0.9, 0.9, 0.0, 1.0 };
     GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat low_shininess[] = { 10.0 };

     glLightfv(GL_LIGHT0,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT0,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT0, GL_POSITION, light_positionSunce);
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);

	int i, j;


	glClearColor(0.0, 0.7, 1.0, 0.4); // sky color is light blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	gluLookAt(
            x,      y,      z,
			x + lx, y + ly, z,
			0.0,    0.0,    1.0);

	// Draw ground - 200x200 square colored green
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(-1000.0, -1000.0, 0.0);
		glVertex3f(-1000.0,  1000.0, 0.0);
		glVertex3f( 1000.0,  1000.0, 0.0);
		glVertex3f( 1000.0, -1000.0, 0.0);
	glEnd();

    glPushMatrix();
    glTranslatef(0, 0, 1);
    glRotatef(90, 1, 0,0);

    crtajPod();
    crtajZidove();
    crtajStubove();
    crtajVrh();
    crtajKuce();

    crtajDrugiStub();
    crtajVrata();

    glRotatef(0,0,0,1);
    glTranslatef(140,0,0);
    crtajVrh();
    glTranslatef(0,-230,0);
    crtajVrh();
    glTranslatef(-141,0,0);
    crtajVrh();

    glTranslatef(57,155,-35);
    crtajVrh();
    glTranslatef(30,0,0);
    crtajVrh();
    glTranslatef(-55,60,35);
    crtajDrugeKuce();
    glTranslatef(-70,0,0);
    crtajDrugeKuce();
    glTranslated(-6.5,-250,0);

    put();
    glTranslated(-7,0,0);
    Tree();
    for(i=0;i<15;i++){
        glTranslated(0,10,0);
        Tree();
    }
    glTranslated(29,-150,0);
    Tree();
    for(i=0;i<15;i++){
        glTranslated(0,10,0);
        Tree();
    }
glutSwapBuffers(); // Make it all visible
}
void processNormalKeys(unsigned char key, int xx, int yy)
{
	if (key == ESC || key == 'q' || key == 'Q')
        exit(0);
    else if(key == 'w'){
        z += 10;
    }
    else if(key == 's'){
        z -= 10;
    }
    else if(key == 'a'){
        x -= 10;
    }
    else if(key == 'd'){
        x += 10;
    }
}

void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 4; break;
		case GLUT_KEY_DOWN : deltaMove = -4; break;
	}
}

void releaseSpecialKey(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.0; break;
		case GLUT_KEY_DOWN : deltaMove = 0.0; break;
	}
}

void mouseMove(int x, int y)
{
	if (isDragging) { // only when dragging
		// update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;

		// camera's direction is set to angle + deltaAngle
		lx = -sin(angle + deltaAngle);
		ly = cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
		}
		else  { /* (state = GLUT_UP) */
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}
void menu (int b)
{
     if(b==1)
     {
            x=0.0;
            y=-350.0;
            z=150.0;
     }
     if(b==2)
     {
			x=4.0;
            y=-380.0;
            z=20;
     }
     if(b==3)
     {
			if(sunce == 0)
            {
                glEnable(GL_LIGHT0);
                sunce = 1;
            }
            else
            {
                glDisable(GL_LIGHT0);
                sunce = 0;
            }
     }
     glutPostRedisplay();
}
void kreirajMeni()
{
     glutCreateMenu(menu);
     glutAddMenuEntry("Pticiji pogled",1);
     glutAddMenuEntry("Ulaz",2);
     glutAddMenuEntry("Sunce ON/OFF",3);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
	// general initializations
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("OpenGL/GLUT Sampe Program");
	kreirajMeni();
	// register callbacks

	glutReshapeFunc(changeSize); // window reshape callback
	glutDisplayFunc(renderScene); // (re)display callback

	glutIdleFunc(update); // incremental update
	glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
	glutMouseFunc(mouseButton); // process mouse button push/release
	glutMotionFunc(mouseMove); // process mouse dragging motion
	glutKeyboardFunc(processNormalKeys); // process standard key clicks
	glutSpecialFunc(pressSpecialKey); // process special key pressed
						// Warning: Nonstandard function! Delete if desired.
	glutSpecialUpFunc(releaseSpecialKey); // process special key release

//pozivanje texture
     texture1=LoadTexture("texture1.raw",256, 256);
    texture2=LoadTexture("treebark.bmp",256, 256);
    texture3=LoadTexture("texture3.raw",256, 256);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0; // this is just to keep the compiler happy
}

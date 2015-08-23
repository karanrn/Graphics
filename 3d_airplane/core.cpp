#ifdef	__unix__
	#include <GL/glut.h>
#else 
	#include<glut.h>
#endif
#include<stdio.h>
#include<string.h>

#include"front.h"
#include"back.h"
#include"coordinates.h"
#include"wired.h"
GLfloat	Xsize=1400, Ysize=840;

float RotateAngle = 180.0f;	// Angle in degrees of rotation around y-axis
float Azimuth = 20.0;	// Rotated up or down by this amount
float AngleStepSize = 2.0f;	// Step three degrees at a time

const float AngleStepMax = 10.0f;
const float AngleStepMin = 0.1f;
static int state=0;
int WireFrameOn = 1;	// == 1 for wire frame mode
void display1();
void redcolor();
void graycolor();
void whitecolor();
void blackcolor();
void silvercolor();
void windows();
void crux();
void (*rcolor)(void)=whitecolor;
void (*gcolor)(void)=whitecolor;
void (*bcolor)(void)=whitecolor;
void (*scolor)(void)=whitecolor;
void (*testfn)(void)=display1;
GLUquadric* Quadric = gluNewQuadric();
void display_string(int x, int y, char *string, int font)
{
    int len,i;
	glColor3f(1.0,1.0,1.0);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}

void InitGL()
{
	glEnable(GL_DEPTH_TEST);	// Depth testing must be turned on
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	// Just show wireframes at first
	glViewport(0, 0, Xsize,Ysize);		// Set the viewport 
	glMatrixMode(GL_PROJECTION);		// Select the projection matrix 
	glLoadIdentity();			// Reset The Projection Matrix 
	gluPerspective(30.0,Xsize/Ysize,20.0,100.0);	// Calculate The Aspect Ratio Of The Window 
	glMatrixMode(GL_MODELVIEW);			// Switch back to the modelview matrix 
} 
void display1(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
		glClearColor(0,0,0,0);
		glPointSize(5.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0,900.0,0.0,600.0,50.0,-50.0);

	char school[]="REVA Institute of Technology and Management",
		 dept[]="Dept. of Computer Science",
		 lab[]="COMPUTER GRAPHICS AND VISUALIZATION LABORATORY",
		 title[]="Project Title: Three Dimensional View of an Aeroplane",
		 package[]="API used: OpenGL",
		 team[]="Developed by:",
		 karan[]="Karan Ravajappa Nadagoudar (1RE12CS039)",
		 vijay[]="Kaveripakam Vijay Samuel (1RE12CS040)",
		 space[]="[Press SPACE BAR for keyboard controls]";
	display_string(287,540,school,1);
	display_string(360,500,dept,1);
	display_string(271,470,lab,2);
	display_string(268,380,title,1);
	display_string(386,350,package,1);
	display_string(404,300,team,1);
	display_string(298,280,karan,1);
	display_string(305,255,vijay,1);
	display_string(307,75,space,1);
	glutPostRedisplay();
	glutSwapBuffers();
}
void display2(void)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
		glClearColor(0,0,0,0);
		glPointSize(5.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0,900.0,0.0,600.0,50.0,-50.0);

	char header[]="KEYBOARD EVENTS",
		 options[]="Options:",
		 str1[]=" ->   Use cursor keys to control viewpoint",
		 str2[]=" ->   Press \"w\" key to toggle between wireframe and solid mode",
		 str3[]=" ->   Press \"+\" key to increase the rotational speed",
		 str4[]=" ->   Press \"-\" key to decrease the rotational speed",
		 str5[]=" ->   Press \"Esc\" key to exit",
		 footer[]="[Press ENTER key to proceed]";
	display_string(372,540,header,1);
	display_string(50,450,options,1);
	display_string(50,420,str1,2);
	display_string(50,380,str2,2);
	display_string(50,340,str3,2);
	display_string(50,300,str4,2);
	display_string(50,260,str5,2);
	display_string(350,75,footer,1);
	glutPostRedisplay();
	glutSwapBuffers();

}

void drawCylinder(double height, double Baseradius, double Topradius, int slices, int stacks)
{
	// Draw the cylinder.
	gluCylinder(Quadric, Baseradius, Topradius, height, slices, stacks);
}

void drawTurbine(double height, double radiusBase, double radiusTop, int slices, int stacks)
{
	// Draw the cylinder
	drawCylinder(height, radiusBase, radiusTop, slices, stacks);

	// Draw the top disk
	bcolor();
	glPushMatrix();
	glTranslatef(0.0, 0.0, height);
	gluDisk(Quadric, 0.0, radiusTop, slices, stacks);
	glPopMatrix();

	// Draw the bottom disk
	bcolor();
	glPushMatrix();
	glRotatef(180.0, 1.0, 0.0, 0.0);
	gluDisk(Quadric, 0.0, radiusBase, slices, stacks);
	glPopMatrix();
}

void tail()
{
	wired_tail(tail_v1);
	wired_tail(tail_v2);
	join_tails(tail_v1,tail_v2);
}

void wings()
{
	wired(wing_v2);
	wired(wing_v3);
	join_wings(wing_v2,wing_v3);
}

void rear_wheel()
{
	glPushMatrix();
	gcolor(); //darkslate grey
	glTranslatef(2.5,5.0,1.0);
	drawCylinder(0.7,0.075,0.075,10,4);
	glPopMatrix();
	glPushMatrix();
	rcolor();  //red color
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(1.8,5.0,-2.85);
	drawCylinder(0.7,0.1,0.1,10,10);
	glPopMatrix();
	glPushMatrix();
	bcolor(); //black color
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(1.8,5.0,-2.95);
	drawTurbine(0.15,0.25,0.25,10,10);
	glPopMatrix();
	glPushMatrix();
	bcolor(); //black color
	glScalef(-1.0,-1.0,-1.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(-1.8,-5.0,2.3);
	drawTurbine(0.15,0.25,0.25,10,10);
	glPopMatrix();
	glPushMatrix();
	bcolor();  //black color
	glScalef(-1.0,-1.0,-1.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(-1.8,-5.0,2.6);
	drawTurbine(0.15,0.25,0.25,10,10);
	glPopMatrix();
	glPushMatrix();
	bcolor();  //black color
	glScalef(-1.0,-1.0,-1.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(-1.8,-5.0,2.1);
	drawTurbine(0.15,0.25,0.25,10,10);
	glPopMatrix();
}

void windows()
{
//windows
	int i=0;
	float dy=-3.0,dy1=-3.0;
	for(i=0;i<25;i++)
	{
		glPushMatrix();
		glTranslatef(2.68, dy, -0.5);//1.5, -3.2, 0.0
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		bcolor();
		drawCylinder(0.2, 0.25, 0.25, 30, 40);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.28,dy1, -0.5);//1.5, -3.2, 0.0
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		bcolor();   //black color	
		drawCylinder(0.2, 0.25, 0.25, 30, 40);
		glPopMatrix();
		dy+=0.4;
		dy1+=0.4;
	}
	
//cockpit window shield
	glPushMatrix();
	glTranslatef(0.95, -4.8, -1.15);//1.5, -3.2, 0.0
	glRotatef(90.0,0.0,1.0,0.0);
	bcolor();  //black color	
	drawCylinder(1.0, 0.25, 0.25, 20, 30);
	glPopMatrix();

//doors
	glPushMatrix();
	glTranslatef(0.45,6.1, -0.45);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	bcolor();   //black color	
	drawCylinder(0.4, 0.45, 0.45, 30, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.4,6.15, -0.47);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);	
	drawCylinder(0.32, 0.41, 0.41, 30, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.23,6.25, -0.55);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	bcolor();  //black color	
	drawCylinder(0.15, 0.25, 0.25, 30, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.45,-3.2, -0.45);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	bcolor();  //black color	
	drawCylinder(0.4, 0.45, 0.45, 30, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.4,-3.15, -0.47);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);	
	drawCylinder(0.32, 0.41, 0.41, 30, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.23,-3.1, -0.55);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	bcolor();   //black color	
	drawCylinder(0.15, 0.25, 0.25, 30, 40);
	glPopMatrix();
}
void redcolor()
{
	glColor3f(1,0,0);
}
void graycolor()
{
	glColor3f(0.184314, 0.309804, 0.309804);
}
void silvercolor()
{
	glColor3f(0.90, 0.91, 0.98);
}
void blackcolor()
{
	glColor3f(0,0,0);
}
void whitecolor()
{
	glColor3f(1,1,1);
}
// crux() handles the animation and the redrawing of the graphics window contents.
void crux(void)
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(0.30, 0.3, 1.00,1);
	// Rotate the image
	glMatrixMode(GL_MODELVIEW);	// Current matrix affects objects positions
	glLoadIdentity();	// Initialize to the identity
	glTranslatef(-1.5, 0.0, -35.0);	// Translate from origin (in front of viewer)
	glRotatef(RotateAngle, 0.0, 1.0, 0.0);	// Rotate around y-axis
	glRotatef(Azimuth, 1.0, 0.0, 0.0);	// Set Azimuth angle

	//fuselage
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(1.5, -3.2, 0.0);//1.5, -3.2, 0.0
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glColor3f(1,1,1);	// White color
	// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(9.8, 1.5, 1.5, 30, 40);
	glPopMatrix();

	front();
	rcolor();  //red color
	back();	
//turbines
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(-2.0, -0.10, 0.9);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gcolor(); //darkslate grey
	// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(0.60, 0.35, 0.5, 12, 4);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(-2.0, 0.50, 0.9);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	rcolor();	//Red Color
	drawTurbine(2.0, 0.5, 0.4, 12, 15);
	glPopMatrix();
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(-2.0, 2.50, 0.9);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gcolor(); //darkslate grey
	drawCylinder(1.0, 0.4, 0.25, 12, 4);
	glPopMatrix();
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(5.0, -0.10, 0.9);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gcolor(); //darkslate grey
// Parameters: height, base radius, top radius, slices, stacks
	drawCylinder(0.60, 0.35, 0.50, 12, 4);
	glPopMatrix();
	glEnable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(5.0, 0.50, 0.9);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	rcolor();	//Red Color
	drawTurbine(2.0, 0.5, 0.4, 12, 15);
	glPopMatrix();
	glDisable(GL_CULL_FACE);
	glPushMatrix();
	glTranslatef(5.0, 2.50, 0.9);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gcolor(); //darkslate grey
	drawCylinder(1.0, 0.4, 0.25, 12, 4);
	glPopMatrix();

//wings
	glPushMatrix();
	scolor(); //Silver Color
	glRotatef(180.0,1.0,0.0,0.0);
	glTranslatef(-7.4,-3.0,-0.2);
	wings();
	glPopMatrix();

	glPushMatrix();
	scolor(); //Silver Color
	glScalef(-1.0,-1.0,-1.0);
	glTranslatef(-10.2,-3.0,-0.2);
	wings();
	glPopMatrix();
	
//wheels
	glPushMatrix();
	gcolor();
	glTranslatef(1.5,-5.0,1.2);
	drawCylinder(0.4,0.075,0.075,10,4);
	glPopMatrix();
	glPushMatrix();
	rcolor();
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(1.65,-5.0,-1.65);
	drawCylinder(0.3,0.1,0.1,10,10);
	glPopMatrix();
	glPushMatrix();
	bcolor();  //black color
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(1.65,-5.0,-1.7);
	drawTurbine(0.15,0.15,0.15,10,10);
	glPopMatrix();
	glPushMatrix();
	bcolor(); // black color
	glScalef(-1.0,-1.0,-1.0);
	glRotatef(-90.0,0.0,1.0,0.0);
	glTranslatef(-1.65,5.0,1.35);
	drawTurbine(0.15,0.15,0.15,10,10);
	glPopMatrix();
//rear-wheel
	glPushMatrix();
	rear_wheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0,0.0,0.0);
	rear_wheel();
	glPopMatrix();

//tail
	glPushMatrix();
	scolor(); //Silver Color
	glRotatef(180.0,1.0,0.0,0.0);
	glTranslatef(-8.5,-10.0,0.65);
	tail();
	glPopMatrix();
	glPushMatrix();
	scolor(); //Silver Color
	glScalef(-1.0,-1.0,-1.0);
	glTranslatef(-11.5,-10.0,0.65);
	tail();
	glPopMatrix();

//Rudder
	glPushMatrix();
	rcolor(); //Red
	glScalef(1.2,1.2,1.2);
	glRotatef(90,0.0,1.0,0.0);
	glRotatef(-180.0,1.0,0.0,0.0);
	glTranslatef(-10.0,-9.0,-1.2);
	tail();
	glPopMatrix();

	if(state==1)
		windows();
	
	glFlush();
	glutSwapBuffers();
}

void display()
{
	testfn();
}


void myReshape(int w, int h)
{
	double aspectRatio= (double)w / (double)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//void gluPerspective(GLdouble fovy,GLdouble aspect,GLdouble zNear,GLdouble zFar);
	gluPerspective(35.0, aspectRatio, 20.0, 100.0);
}

// glutKeyboardFunc is called below to set this function to handle all "normal" key presses.
void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 13:InitGL();
				scolor=whitecolor;
				bcolor=whitecolor;
				rcolor=whitecolor;
				gcolor=whitecolor;
				state=0;
				testfn=crux;
				break;
		case ' ': testfn=display2;
		case 'w':
				
				if (WireFrameOn)
				{
					glClearColor(0.0,0.0,0.0,1.0);
					scolor=whitecolor;
					bcolor=whitecolor;
					rcolor=whitecolor;
					gcolor=whitecolor;
					state=0;
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	// wireframes mode
				}
				else
				{
					glClearColor(0.30, 0.3, 1.00,1);
					scolor=silvercolor;
					bcolor=blackcolor;
					rcolor=redcolor;
					gcolor=graycolor;
					state=1;
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	// solid polygons mode
				}
				WireFrameOn = 1 - WireFrameOn;
				glutPostRedisplay();
				break;
		case '+':
				AngleStepSize *= 1.5;
				if (AngleStepSize>AngleStepMax)
				{
					AngleStepSize = AngleStepMax;
				}
				break;
		case '-':
				AngleStepSize /= 1.5;
				if (AngleStepSize<AngleStepMin)
				{
					AngleStepSize = AngleStepMin;
				}
				break;
		case 27:	// Esc key
				exit(1);
	}
}

void mySpecialKeyFunc(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
				Azimuth += AngleStepSize;
				if (!WireFrameOn)
				{
					glClearColor(0.0,0.0,0.0,1.0);
				}
				if (Azimuth>180.0f )
				{
					Azimuth -= 360.0f;
				}
				break;
		case GLUT_KEY_DOWN:
				if (!WireFrameOn)
				{
					glClearColor(0.0,0.0,0.0,1.0);
				}
				Azimuth -= AngleStepSize;
				if (Azimuth < -360.0f)
				{
					Azimuth += -360.0f;
				}
				break;
		case GLUT_KEY_LEFT:
				if (!WireFrameOn)
				{
					glClearColor(0.0,0.0,0.0,1.0);
				}
				RotateAngle += AngleStepSize;
				if (RotateAngle > 180.0f)
				{
					RotateAngle -= 360.0f;
				}
				break;
		case GLUT_KEY_RIGHT:
				if (!WireFrameOn)
				{
					glClearColor(0.0,0.0,0.0,1.0);
				}
				RotateAngle -= AngleStepSize;
				if (RotateAngle < -180.0f)
				{
					RotateAngle += 360.0f;
				}
				break;
	}
	glutPostRedisplay();
}

// Main routine
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(10, 60);
	glutInitWindowSize(Xsize,Ysize);
	glutCreateWindow("Three dimensional view of an airplane");
	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);
	InitGL();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return(0);
}

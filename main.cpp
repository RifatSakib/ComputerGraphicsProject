#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include<cstdio>
# define PI 3.14159265358979323846
using namespace std;

GLfloat boatM = 0.0f;
GLfloat boatM2 = 0.0f;
GLfloat boatM3 = 0.0f;
GLfloat boatM4 = 0.0f;
GLfloat boatM5 = 0.0f;

GLfloat i=0;
GLfloat cloudMovement = 0.0f;
GLfloat cloudMovement2 = 0.0f;

bool isStopped = false;
bool isRaining = false;

GLfloat rainMovementX = 0.0f;
GLfloat rainMovementY = 0.0f;

GLfloat car1Position = 0.0f;
GLfloat car1Speed = 0.05f;

GLfloat car2Position = 0.0f;
GLfloat car2Speed = 0.04f;

void handleMouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON)
        {
            isStopped = false;
        }
        if (button == GLUT_RIGHT_BUTTON)
        {
            isStopped = true;
        }
	glutPostRedisplay();
}

void SpecialInput(int key, int x, int y){
    switch(key)
    {
        case GLUT_KEY_UP:

        if(car1Speed<=2)
        {
            car1Speed += 0.02;

        }

        if(car2Speed<=2)
        {
            car2Speed += 0.02;
        }

        break;

        case GLUT_KEY_DOWN:

         if(car1Speed>=0.02)
        {
            car1Speed -= 0.02;

        }

        if(car2Speed>=0.02)
        {
            car2Speed -= 0.02;
        }

        break;
    }
glutPostRedisplay();
}

void update(int value){

    if(!isStopped)
    {
        cloudMovement += 0.002f;
    if(cloudMovement>=1.9)
    {
        cloudMovement = -1.6f;
    }

    cloudMovement2 += 0.002f;
    if(cloudMovement2>=2.9)
    {
        cloudMovement2 = -2.6;
    }

    if(car1Position>=2)
        {car1Position = -1.5;}

    car1Position+=car1Speed;

    if(car2Position<=-2)
        {car2Position = 1.2;}

    car2Position-=car2Speed;


    if(boatM <= 1.0)
    {
        boatM+= 0.019;

    }
    else
    {
        boatM = -1.5f;
    }

    if(boatM2 >= -1.8)
    {
        boatM2-= 0.019;

    }
    else
    {
        boatM2 = 1.3f;
    }

    if(boatM3<=1.1f)
    {
        boatM3 += .01f;
    }
    else
    {
        boatM3 = -1.6f;
    }

    boatM4 += .03;
    if(boatM4>=1.9f)
    {
        boatM4 = -1.5f;
    }
    i=i+2;
}

    glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}


void circle(float a, float b, float c, float m, float n, float o)
{
    int i;

    GLfloat x=a;
    GLfloat y=b;
    GLfloat radius =c;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(m,n,o);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Cloud()
{
    GLfloat x=0.0f;
    GLfloat y=0.8f;
    GLfloat radius =.1f;
    int i;
    int triangleAmount  = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.686, 0.866, 0.933);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    x = -0.1;
    y = .82;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.921, 0.980, 0.996);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    x = 0.0;
    y = .85;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.921, 0.980, 0.996);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    x = 0.1;
    y = .82;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.921, 0.980, 0.996);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();



    x = 0.0;
    y = .75;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.921, 0.980, 0.996);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}

void sun()
{
    circle(0.35, 0.87, 0.08, 1, 0.733, 0.2);
}

void sky()
{

    glBegin(GL_QUADS); // sky start
    glColor3f(0.016, 0.388, 0.792); // Day
    glVertex2f(-1,1);
    glVertex2f(-1,.6);
    glVertex2f(1,.6);
    glVertex2f(1,1);
    glEnd(); // sky Ends

    sun();

    glPushMatrix();
    //glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.8,.45,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();
    glPopMatrix();

    //glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.2,.35,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    //glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(.7,.5,0);
    glScalef(.5,.5,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.8,.45,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(-.3,.35,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();

    glTranslatef(-1.0,0.0,0.0);
    glTranslatef(cloudMovement,0.0,0);
    glTranslatef(1.2 ,.3,0);
    glScalef(.6,.6,1);
    Cloud();
    glLoadIdentity();


}

void hill()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();

    glScalef(.7,.7,1);
    glTranslatef(.15,0,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();

    glScalef(.9,.9,1);
    glTranslatef(.15,0,0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.207, 0.443, 0.196);
    glVertex2f(0,0);
    glVertex2f(.1,.1);
    glVertex2f(.2,0);
    glEnd();
    glLoadIdentity();
}

void hillLong()
{
    float x=-1.1;
    for(int i=0; i<10; i++)
    {
        glTranslatef(x,.6,0);
        hill();
        glLoadIdentity();
        x+=.30;
    }
}



void tree()
{
    float vTree = -0.95f; // x axis value
    float zTree = 0.55f; // y axis value

    float vTree2 = vTree+.05f; // x axis value
    float zTree2 = zTree -.05f; // y axis value

    glBegin(GL_QUADS); //1st tree
    glColor3f(0.482, 0.215, 0.078);
    glVertex2f(vTree,zTree+.15);
    glVertex2f(vTree,zTree);
    glVertex2f(vTree+.005,zTree);
    glVertex2f(vTree+.005,zTree+.15);

    glVertex2f(vTree2,zTree2+.15); // 2nd tree
    glVertex2f(vTree2,zTree2);
    glVertex2f(vTree2+.005,zTree2);
    glVertex2f(vTree2+.005,zTree2+.15);

    glEnd();

    vTree = vTree + .0025;
    vTree2 = vTree2 + .0025;

    glBegin(GL_TRIANGLES);
    glColor3f(0.250, 0.529, 0.070); // 1st tree triangle
    glVertex2f(vTree,zTree+.18);
    glVertex2f(vTree-.03,zTree+.12);
    glVertex2f(vTree+.03,zTree+.12);

    glVertex2f(vTree,zTree+.14); // 1st tree triangle
    glVertex2f(vTree-.03,zTree+.08);
    glVertex2f(vTree+.03,zTree+.08);


    glVertex2f(vTree2,zTree2+.18); // 2nd tree triangle
    glVertex2f(vTree2-.03,zTree2+.12);
    glVertex2f(vTree2+.03,zTree2+.12);

    glVertex2f(vTree2,zTree2+.14); // 2nd tree triangle
    glVertex2f(vTree2-.03,zTree2+.08);
    glVertex2f(vTree2+.03,zTree2+.08);

    glEnd();
    glLoadIdentity();

    vTree = vTree+0.3;
    vTree2 = vTree2 + 0.3;
}

void hut()
{
    //body();
    glBegin(GL_POLYGON); //front
    glColor3f(0.549, 0.384, 0.290);

    glVertex2f(.45,.4);
    glVertex2f(.0,.0);
    glVertex2f(.0,-.4);
    glVertex2f(.75,-.35);
    glVertex2f(.75,.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.666, 0.462, 0.352);

    glVertex2f(0,0); // Left side
    glVertex2f(-.65,0);
    glVertex2f(-.65,-.35);
    glVertex2f(0,-.4);
    glEnd();

    glTranslatef(.35,-.38,0);
    glBegin(GL_QUADS);//door
    glColor3f(0.309, 0.176, 0.109);

    glVertex2f(0,0);
    glVertex2f(.18,.01);
    glVertex2f(.18,.39);
    glVertex2f(0,.4);
    glEnd();

    glTranslatef(-.35,.38,0);
    //bar();
    glBegin(GL_QUADS);
    glColor3f(0.309, 0.176, 0.109);

    glVertex2f(0,.1);
    glVertex2f(0,-.4);
    glVertex2f(.02,-.4);
    glVertex2f(.02,.1);
    glEnd();

    //roof();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(0,0);
    glVertex2f(.5,.4);
    glVertex2f(-.2,.3);
    glVertex2f(-.7,.0);
    glEnd();

    glBegin(GL_QUADS); // Side roof bar
    glColor3f(0, 0, 0);
    glVertex2f(.5,.4);
    glVertex2f(.45,.4);
    glVertex2f(.75,.0);
    glVertex2f(.8,.0);
    glEnd();
    glLoadIdentity();
}

void school()
{
    glBegin(GL_QUADS); //body
    glColor3f(0.929, 0.874, 0.694);
    glVertex2f(0,0);
    glVertex2f(0,-.2);
    glVertex2f(.5,-.2);
    glVertex2f(.5,0);
    glEnd();

    glBegin(GL_QUADS); //top bar
    glColor3f(0.666, 0.572, 0.254);
    glVertex2f(-.01,0);
    glVertex2f(-.01,-.01);
    glVertex2f(.51,-.01);
    glVertex2f(.51,0);
    glEnd();

    glBegin(GL_QUADS); //door
    glColor3f(0.815, 0.713, 0.364);
    glVertex2f(0.2,-.1);
    glVertex2f(0.2,-.2);
    glVertex2f(.3,-.2);
    glVertex2f(.3,-.1);
    glEnd();
}

void field()
{
    glBegin(GL_QUADS); // Field start
    glColor3f(0.439, 0.674, 0.223); // Day
    glVertex2f(-1,.6);
    glVertex2f(-1,.24);
    glVertex2f(1,.24);
    glVertex2f(1,.6);
    glEnd(); // Field Ends


    //Elements
    glTranslatef(-.5,.5,0); //2ND HUT
    glScalef(.17,.17,1);
    hut();
    glLoadIdentity();

    glTranslatef(-.8,.4,0); //1ST HUT
    glScalef(.225,.225,1);
    hut();
    glLoadIdentity();

    glTranslatef(.8,.45,0); //3RD HUT
    glScalef(-.22, .22, 1);
    hut();
    glLoadIdentity();

    glTranslatef(-.05,.65,0);
    glScalef(0.9,0.9,1);
    school();
    glLoadIdentity();

    // Trees
    glTranslatef(0,-.05,0); //1st tree
    tree(); // 1st pair tree
    glLoadIdentity();

    glTranslatef(.7,-.08,0);
    tree(); // 2nd pair tree
    glLoadIdentity();

    glTranslatef(1.52,-.13,0);
    tree(); // 3rd pair tree
    glLoadIdentity();

    glTranslatef(1.85,-.02,0);
    tree(); // 4th pair tree
    glLoadIdentity();
}

void roadStripe()
{
    //ROAD

    glBegin(GL_QUADS);
    glColor3f(0.431, 0.431, 0.407); // LANE MAIN ROAD
    glVertex2f(-1,.3);
    glVertex2f(-1,.1);
    glVertex2f(1,.1);
    glVertex2f(1,.3);
    glEnd();

    //ROAD LINE
    glBegin(GL_QUADS);
    glColor3f(1, 0.964, 0.239);

    glVertex2f(-1,.21);
    glVertex2f(-1,.19);
    glVertex2f(-.75,.19);
    glVertex2f(-.75,.21);

    glVertex2f(-.5,.21);
    glVertex2f(-.5,.19);
    glVertex2f(-.25,.19);
    glVertex2f(-.25,.21);

    glVertex2f(0,.21);
    glVertex2f(.0,.19);
    glVertex2f(.25,.19);
    glVertex2f(.25,.21);

    glVertex2f(.5,.21);
    glVertex2f(.5,.19);
    glVertex2f(.75,.19);
    glVertex2f(.75,.21);
    glEnd();
}

void lamp()
{
    float xLamp= -0.93f;
    float yLamp = 0.06f;


    for(int i =0; i<=11; i++)
    {

        glBegin(GL_QUADS);
        glColor3f(0.525, 0.372, 0.133);
        glScalef(2.3,2.3,1);
        glVertex2f(xLamp,yLamp);
        glVertex2f(xLamp,yLamp+0.1);
        glVertex2f(xLamp+.01,yLamp+0.1);
        glVertex2f(xLamp+.01,yLamp);
        glLoadIdentity();


        glColor3f(0,0,0);
        glVertex2f(xLamp,yLamp+0.1);
        glVertex2f(xLamp,yLamp+0.09);
        glVertex2f(xLamp+0.04,yLamp+0.09);
        glVertex2f(xLamp+0.04,yLamp+0.1);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.854, 0.843, 0.843);

        glVertex2f(xLamp+0.02,yLamp+.09);
        glVertex2f(xLamp+0.01,yLamp+0.07);
        glVertex2f(xLamp+0.03,yLamp+0.07);
        glVertex2f(xLamp+0.02,yLamp+.09);

        glEnd();
        //glutSwapBuffers();

        xLamp = xLamp+.2;
    }
}

void car1()
{
    glBegin(GL_POLYGON);
    glColor3f(0.811, 0.227, 0.227); //Car body
    glVertex2f(-.04,.2);
    glVertex2f(-.02,0);
    glVertex2f(.7,0);
    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glEnd();

    glBegin(GL_POLYGON); //Window body
    glColor3f(0.564, 0.152, 0.152);
    glVertex2f(.2,.3);
    glVertex2f(0,.2);
    glVertex2f(.55,.2);
    glVertex2f(.4,.3);
    glEnd();

    glBegin(GL_POLYGON);//Window
    glColor3f(0.701, 0.698, 0.698);
    glVertex2f(.2,.28);
    glVertex2f(0.04,.2);
    glVertex2f(.51,.2);
    glVertex2f(.4,.28);
    glEnd();

    glBegin(GL_TRIANGLES); //Light
    glColor3f(0,0,0);

    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glVertex2f(.65,.15);
    glEnd();

    //wheels
    circle(.13,0, .09, 0.129, 0.129, 0.129);
    circle(.55,0, .09, 0.129, 0.129, 0.129);
}

void car2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.513, 0.356, 0.760); //body
    glVertex2f(-.04,.2);
    glVertex2f(-.02,0);
    glVertex2f(.7,0);
    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glEnd();

    glBegin(GL_POLYGON); //window body
    glColor3f(0.384, 0.270, 0.572);
    glVertex2f(.2,.3);
    glVertex2f(0,.2);
    glVertex2f(.55,.2);
    glVertex2f(.4,.3);
    glEnd();

    glBegin(GL_POLYGON);//window
    glColor3f(0.623, 0.568, 0.713);
    glVertex2f(.2,.28);
    glVertex2f(0.04,.2);
    glVertex2f(.51,.2);
    glVertex2f(.4,.28);
    glEnd();

    glBegin(GL_TRIANGLES);//lights

    glColor3f(0,0,0);

    glVertex2f(.7,.15);
    glVertex2f(.65,.2);
    glVertex2f(.65,.15);
    glEnd();

    circle(.13, 0, .09, 0.129, 0.129, 0.129);
    circle(.55, 0, .09, 0.129, 0.129, 0.129);
}

void road()
{
    roadStripe(); // For 1st lane road

    //Road Divider

    glBegin(GL_QUADS);
    glColor3f(0.368, 0.627, 0.133);
    glVertex2f(-1,.1);
    glVertex2f(-1,0);
    glVertex2f(1,0);
    glVertex2f(1,.1);
    glEnd();

    //End road divider

    glTranslatef(0,-.3,0);
    roadStripe(); // For 2nd lane road
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(car2Position,0,0);
    glTranslatef(.8,.16,0);
    glScalef(-.29,.29,1);
    car2();
    glLoadIdentity();
    glPopMatrix();
    //glutSwapBuffers();

    //LAMP

    glTranslatef(0, -0.02, 1);
    glScalef(1.8, 1.2, 1);
    lamp();
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(car1Position,0,0);
    glTranslatef(-.8,-.05,0);
    glScalef(.4,.4,1);
    car1();
    glLoadIdentity();
    glPopMatrix();
}

void riverSideRoadGrass()
{
    glBegin(GL_QUADS); //field

    glColor3f(0.435, 0.839, 0.360);


    glVertex2f(-1,-0.1);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.1);
    glEnd();
}

void river()
{
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.886, 0.968); //Water color

    glVertex2f(-1,-.3);
    glVertex2f(-1,-1);
    glVertex2f(1,-1);
    glVertex2f(1,-0.3);
    glEnd();
}

void windmill()
{
    glBegin(GL_QUADS); // Stand of the fan
    glColor3f(0.160, 0.160, 0.160);
    glVertex2f(.1,.47);
    glVertex2f(.1,.32);
    glVertex2f(.11,.32);
    glVertex2f(.11,.47);
    glEnd();

    //ANIMATION

    glPushMatrix();
    glTranslatef(0.105,.47,0.0);
    glRotatef(i,0.0,0.0,0.1);

    glBegin(GL_TRIANGLES);
    glColor3f(0.768, 0.768, 0.768);

    glVertex2f(.0,.0);
    glVertex2f(.02,.11);
    glVertex2f(.04,.12);

    glVertex2f(.0,.0);
    glVertex2f(-.02,-.11);
    glVertex2f(-.04,-.12);

    glVertex2f(.0,.0);
    glVertex2f(-.11,.02);
    glVertex2f(-.12,.04);


    glVertex2f(.0,.0);
    glVertex2f(.11,-.02);
    glVertex2f(.12,-.04);

    glEnd();
    glPopMatrix();//glPopMatrix pops the top matrix off the stack
    //i=i+.1=.2


    //ANIMATION END

    //CIRCLE OF FAN
    GLfloat xMoon=0.105f; GLfloat  yMoon=.47f; GLfloat moonRadius =.02f;
    GLfloat moonTwicePi = 2.0f * PI;
    int moonTriangleAmount = 20;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.478, 0.478, 0.478);
            glVertex2f(xMoon, yMoon); // center of circle
            for(int i = 0; i <= moonTriangleAmount;i++) {
                glVertex2f(
                        xMoon + (moonRadius * cos(i *  moonTwicePi /moonTriangleAmount )),
                    yMoon + (moonRadius * sin(i * moonTwicePi / moonTriangleAmount))
                );
            }
        glEnd();

    //CIRCLE OF FAN

}

void boat()
{
    glBegin(GL_POLYGON); //Boat body
    glColor3f(0.098, 0.101, 0.101);
    glVertex2f(0,0);
    glVertex2f(0.02,-0.05);
    glVertex2f(0.18,-0.05);
    glVertex2f(0.2,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.05,0); //Sub sail
    glVertex2f(0.075,0);
    glVertex2f(0.075,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.08,0); // Main sail
    glVertex2f(0.145,0);
    glVertex2f(.08,0.1);

    glEnd();
}

void boat2()
{
    glBegin(GL_POLYGON);
    glColor3f(0.098, 0.101, 0.101);
    glVertex2f(0,0);
    glVertex2f(0.02,-0.05);
    glVertex2f(0.18,-0.05);
    glVertex2f(0.2,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.11,0);
    glVertex2f(0.095,0);
    glVertex2f(0.095,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.921, 0.937, 0.937);

    glVertex2f(0.09,0);
    glVertex2f(0.045,0);
    glVertex2f(.09,0.1);

    glEnd();

}

void scene()
{

    sky();
    //hill();
    hillLong();

    field();
    //roadStripe();

    glScalef(1,.7,1);
    glTranslatef(0,.05,0);
    road();
    glLoadIdentity();

    riverSideRoadGrass();


    glTranslatef(-.8,-.65,0);
    glScalef(1.2, 1.2, 1);
    windmill();
    glLoadIdentity();

    glTranslatef(-.4 ,-.55,0);
    windmill();
    glLoadIdentity();


    glTranslatef(-.0,-.65,0);
    glScalef(1.2, 1.2, 1);
    windmill();
    glLoadIdentity();


    glTranslatef(.4,-.55,0);
    //glScalef(1.2, 1.2, 1);
    windmill();
    glLoadIdentity();

    river();

    glPushMatrix();
    glTranslatef(boatM,0.0,0);
    glTranslatef(-0.2,-.4,0);
    boat();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatM2,0.0,0);
    glTranslatef(0.6,-.5,0);
    glScalef(1.4, 1.1, 0);
    boat2();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(boatM4,0.0,0.0);
    glTranslatef(-0.6,-.6,0);
    glScalef(1.4,1.4,0);
    boat2();
    glLoadIdentity();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(boatM3,0.0,0.0);
    glTranslatef(0.2,-.8,0);
    glScalef(1.9,1.9,0);
    boat();
    glLoadIdentity();
    glPopMatrix();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    scene();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    cout << "Increase Car Speed-         Upper Arrow" << endl;
    cout << "Decrease Car Speed-        Lower Arrow" << endl;
    cout << "Pause Animation-         Mouse Right Click" << endl;
    cout << "Resume Animation-         Mouse Left Click" << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Computer Graphics Final Project");
    glutMouseFunc(handleMouse);
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265359
//*************************************************
double  r=.2,s=.3;
int i;
float  tx=10,bx=10; //boat

float txm=13, bxm=10; //megh

float txp=0, bxp=10; //parasuit

float txk=13, bxk=10; //kite
//***********************************************************************
// ------------------ boat
float boatTX = -57.0f;
bool isStopez = false;
int boatPassState = 0;

// ------------------

//---------------- man
bool isManOnBoat = false;
float manTX = 0.0f;
float manTY = 0.0f;
//------------ dolna

float angle = 0.0f;
float angleOfDolna = 0.0f;
float isLeftDolna = true;

void drawBoat();
void drawMan();
void birds(float p, float q);

void drawCircle(GLfloat radius)
{
    GLfloat x = 66.8, y = 32.5;
    int i, triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void init (void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);


//************************************************Sky(payel)*************************************************
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(242, 229, 229);//down

    glVertex2i(0, 47);
    glVertex2i(100, 47);
    glColor3ub(174, 226, 255);//up

    glVertex2i(100, 100);
    glVertex2i(0, 100);
    glEnd();

//***************************************************Sky end(payel)*******************************************


//************************************************Pichoner Math(payel)***************************************

    glBegin(GL_QUADS);
    glColor3ub(156, 255, 46);//down
    glVertex2i(0, 26);
    glVertex2i(100, 26);
    glColor3ub(130, 205, 71);//up
    glVertex2i(100, 47);
    glVertex2i(0, 47);
    glEnd();

//*********************************************End of Math(payel)*************************************************


//**********************************************Start of tree(payel)**********************************


//tree mahkhane dal
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);//brown
    glVertex2i(0, 26);
    glVertex2i(7, 26);
    glVertex2i(4, 27);
    glVertex2i(4, 55);
    glVertex2i(0, 55);
    glEnd();


//tree pasher lomba dal
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);//brown
    glVertex2i(4, 40);
    glVertex2i(19, 52);
    glVertex2i(19, 54);
    glVertex2i(4, 42);
    glEnd();

//tree pasher khato dal
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);//brown
    glVertex2i(9, 46);
    glVertex2i(12, 47);
    glVertex2i(10, 55);
    glVertex2i(8, 55);
    glEnd();

//tree pasher khato dal
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);//brown
    glVertex2i(7, 43);
    glVertex2i(22, 46);
    glVertex2i(22, 47);
    glVertex2i(10, 45);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(15, 66);
    glVertex2i(19, 66);
    glVertex2i(18, 73);
    glVertex2i(15, 70);
    glEnd();


//tree 4th left pata
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(18, 45);
    glVertex2i(23, 42);
    glVertex2i(28, 43);
    glVertex2i(32, 48);
    glColor3ub(156, 255, 46);
    glVertex2i(28, 53);
    glVertex2i(23, 53);
    glEnd();


//tree mahkhane pata
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(0, 45);
    glVertex2i(4, 46);
    glVertex2i(7, 46);
    glVertex2i(11, 50);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(15, 57);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(15, 70);
    glVertex2i(12, 77);
    glVertex2i(5, 79);
    glColor3ub(156, 255, 46);
    glVertex2i(0, 77);
    glEnd();

//tree 2nd left pata
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(13, 57);
    glVertex2i(20, 57);
    glVertex2i(24, 58);
    glVertex2i(24, 63);
    glColor3ub(156, 255, 46);
    glVertex2i(18, 68);
    glVertex2i(13, 65);
    glEnd();

//tree 3rd left pata
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(13, 43);
    glVertex2i(17, 40);
    glVertex2i(20, 42);
    glVertex2i(21, 45);
    glVertex2i(18, 48);
    glVertex2i(15, 47);
    glEnd();

//tree 1st left pata
    glBegin(GL_POLYGON);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(13, 49);
    glVertex2i(18, 47);
    glColor3ub(0, 128, 0);//green3
    glVertex2i(24, 50);
    glVertex2i(24, 58);
    glVertex2i(16, 60);
    glColor3ub(156, 255, 46);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(11, 55);
    glEnd();


//**********************************************End of tree(payel)*************************************

//**********************************************Start of River(payel)*******************************************
    glBegin(GL_QUADS);

    glColor3ub(98, 205, 255);//down
    glVertex2f(0.0f,0.0f);
    glVertex2f(100.0f,0.0f);
    glColor3ub(25, 167, 206);//up
    glVertex2f(100.0f,15.0f);
    glColor3ub(20, 108, 148);//top
    glVertex2f(0.0f,14.0f);
    glEnd();

    //**********************************************End of River (payel)********************************************


//*************************************************COUNTER START(shorna)*****************************************
//counter
    glBegin (GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(60.0,26.0,0.0);
    glVertex3f(73.0,26.0,0.0);
    glVertex3f(73.0,38.0,0.0);
    glVertex3f(60.0,38.0,0.0);


//cross1
    glColor3f(1.0f, 1.0f, 1.0f); //white
    glVertex3f(62.0,26.0,0.0);
    glVertex3f(64.0,26.0,0.0);
    glVertex3f(64.0,38.0,0.0);
    glVertex3f(62.0,38.0,0.0);

    //cross2
    glVertex3f(66.0,26.0,0.0);
    glVertex3f(68.0,26.0,0.0);
    glVertex3f(68.0,38.0,0.0);
    glVertex3f(66.0,38.0,0.0);

//cross3
    //cross2
    glVertex3f(70.0,26.0,0.0);
    glVertex3f(71.0,26.0,0.0);
    glVertex3f(71.0,38.0,0.0);
    glVertex3f(70.0,38.0,0.0);


//head
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color

    glVertex3f(59.0,38.0,0.0);
    glVertex3f(74.0,38.0,0.0);
    glVertex3f(74.0,40.0,0.0);
    glVertex3f(59.0,40.0,0.0);

//top
    glColor3ub(247, 147, 39); //brown

    glVertex3f(60.0,40.0,0.0);
    glVertex3f(73.0,40.0,0.0);
    glVertex3f(73.0,44.0,0.0);
    glVertex3f(60.0,44.0,0.0);

//  window
    glColor3ub(247, 147, 39);//brown
    glVertex3f(62.0,30.0,0.0);
    glVertex3f(71.0,30.0,0.0);
    glVertex3f(71.0,36.0,0.0);
    glVertex3f(62.0,36.0,0.0);

    //window border
    glColor3ub(130, 0, 0); //chocolate
    glVertex3f(62.5,31.0,0.0);
    glVertex3f(70.5,31.0,0.0);
    glVertex3f(70.5,35.0,0.0);
    glVertex3f(62.5,35.0,0.0);

    glEnd();
//*****************************************COUNTER END(shorna)**********************************************************



//******************************************NAGOR DOLA START(shorna)***************************************************
//  nagor dola hand1
    glBegin (GL_QUADS);
    glColor3ub(183, 4, 4); //chocolate
    glVertex3f(0.0,26.0,0.0);
    glVertex3f(4.0,26.0,0.0);
    glVertex3f(18,55.0,0.0);
    glVertex3f(18,56.0,0.0);

    //  nagor dola hand2

    glVertex3f(31.0,25.0,0.0);
    glVertex3f(36.0,25.0,0.0);
    glVertex3f(18,56.0,0.0);
    glVertex3f(18,55.0,0.0);
    glEnd();


    //  nagor dola seat1
    glLoadIdentity();
    glTranslatef(18.0,57.5,0.0);
    glRotatef(angle,0.0,0.0,1.0);
    glTranslatef(-18.0,-57.5,0.0);

    glBegin (GL_QUADS);
    glColor3ub(0, 129, 201); //blue

    glVertex3f(12.0,69.0,0.0);
    glVertex3f(23.0,69.0,0.0);
    glVertex3f(23.0,73.0,0.0);
    glVertex3f(12.0,73.0,0.0);

    //window1

    glColor3f(1.0,1.0,1.0); //white

    glVertex3f(13.0,71.0,0.0);
    glVertex3f(22.0,71.0,0.0);
    glVertex3f(22,73.0,0.0);
    glVertex3f(13,73.0,0.0);

    //  nagor dola head1

    glColor3ub(246, 147, 39); //brown

    glVertex3f(11.0,73.0,0.0);
    glVertex3f(24.0,73.0,0.0);
    glVertex3f(23.0,75.0,0.0);
    glVertex3f(12.0,75.0,0.0);



    //  nagor dola seat2

    glColor3ub(0, 129, 201); //blue

    glVertex3f(1.0,63.0,0.0);
    glVertex3f(11.0,63.0,0.0);
    glVertex3f(11.0,67.0,0.0);
    glVertex3f(1.0,67.0,0.0);

    //  nagor dola window2

    glColor3f(1.0,1.0,1.0); //white

    glVertex3f(2.0,65.0,0.0);
    glVertex3f(10.0,65.0,0.0);
    glVertex3f(10.0,67.0,0.0);
    glVertex3f(2.0,67.0,0.0);

    //  nagor dola head2


    glColor3ub(246, 147, 39); //brown
    glVertex3f(0.0,67.0,0.0);
    glVertex3f(12.0,67.0,0.0);
    glVertex3f(11.0,69.0,0.0);
    glVertex3f(1.0,69.0,0.0);

    //  nagor dola seat3

    glColor3ub(0, 129, 201);//blue

    glVertex3f(1.0,51.0,0.0);
    glVertex3f(11.0,51.0,0.0);
    glVertex3f(11.0,55.0,0.0);
    glVertex3f(1.0,55.0,0.0);

    //  nagor dola window3

    glColor3f(1.0,1.0,1.0);//white

    glVertex3f(2.0,53.0,0.0);
    glVertex3f(10.0,53.0,0.0);
    glVertex3f(10.0,55.0,0.0);
    glVertex3f(2.0,55.0,0.0);

    //  nagor dola head3


    glColor3ub(246, 147, 39);//brown
    glVertex3f(0.0,55.0,0.0);
    glVertex3f(12.0,55.0,0.0);
    glVertex3f(11.0,57.0,0.0);
    glVertex3f(1.0,57.0,0.0);


    //  nagor dola seat4

    glColor3ub(0, 129, 201);//blue

    glVertex3f(1.0,41.0,0.0);
    glVertex3f(11.0,41.0,0.0);
    glVertex3f(11.0,45.0,0.0);
    glVertex3f(1.0,45.0,0.0);

    //  nagor dola window4

    glColor3f(1.0,1.0,1.0);//whitte

    glVertex3f(2.0,43.0,0.0);
    glVertex3f(10.0,43.0,0.0);
    glVertex3f(10.0,45.0,0.0);
    glVertex3f(2.0,45.0,0.0);

    //  nagor dola head4


    glColor3ub(246, 147, 39);//brown
    glVertex3f(0.0,45.0,0.0);
    glVertex3f(12.0,45.0,0.0);
    glVertex3f(11.0,47.0,0.0);
    glVertex3f(1.0,47.0,0.0);

    //  nagor dola seat5

    glColor3ub(0, 129, 201);//blue

    glVertex3f(12.0,34.0,0.0);
    glVertex3f(23.0,34.0,0.0);
    glVertex3f(23.0,38.0,0.0);
    glVertex3f(12.0,38.0,0.0);

    //window5

    glColor3f(1.0,1.0,1.0);//white

    glVertex3f(13.0,36.0,0.0);
    glVertex3f(22.0,36.0,0.0);
    glVertex3f(22,38.0,0.0);
    glVertex3f(13,38.0,0.0);

    //  nagor dola head5

    glColor3ub(246, 147, 39);//brown

    glVertex3f(11.0,38.0,0.0);
    glVertex3f(24.0,38.0,0.0);
    glVertex3f(23.0,40.0,0.0);
    glVertex3f(12.0,40.0,0.0);

    //  nagor dola seat6

    glColor3ub(0, 129, 201);//blue

    glVertex3f(24.0,39.0,0.0);
    glVertex3f(34.0,39.0,0.0);
    glVertex3f(34.0,43.0,0.0);
    glVertex3f(24.0,43.0,0.0);

    //window6

    glColor3f(1.0,1.0,1.0);//white


    glVertex3f(25.0,41.0,0.0);
    glVertex3f(33.0,41.0,0.0);
    glVertex3f(33.0,43.0,0.0);
    glVertex3f(25.0,43.0,0.0);

    //  nagor dola head6

    glColor3ub(246, 147, 39);//brown

    glVertex3f(23.0,43.0,0.0);
    glVertex3f(35.0,43.0,0.0);
    glVertex3f(34.0,45.0,0.0);
    glVertex3f(24.0,45.0,0.0);

//  nagor dola seat7

    glColor3ub(0, 129, 201);//blue

    glVertex3f(28.0,51.0,0.0);
    glVertex3f(37.0,51.0,0.0);
    glVertex3f(37.0,55.0,0.0);
    glVertex3f(28.0,55.0,0.0);

    //  nagor dola window7

    glColor3f(1.0,1.0,1.0);//white

    glVertex3f(29.0,53.0,0.0);
    glVertex3f(36.0,53.0,0.0);
    glVertex3f(36.0,55.0,0.0);
    glVertex3f(29.0,55.0,0.0);

    //  nagor dola head7

    glColor3ub(246, 147, 39);//brown

    glVertex3f(27.0,55.0,0.0);
    glVertex3f(38.0,55.0,0.0);
    glVertex3f(37.0,57.0,0.0);
    glVertex3f(28.0,57.0,0.0);

    //  nagor dola seat8

    glColor3ub(0, 129, 201);//blue

    glVertex3f(29.0,61.0,0.0);
    glVertex3f(38.0,61.0,0.0);
    glVertex3f(38.0,65.0,0.0);
    glVertex3f(29.0,65.0,0.0);

    //  nagor dola window8

    glColor3f(1.0,1.0,1.0);//white

    glVertex3f(30.0,63.0,0.0);
    glVertex3f(37.0,63.0,0.0);
    glVertex3f(37.0,65.0,0.0);
    glVertex3f(30.0,65.0,0.0);

    //  nagor dola head8

    glColor3ub(246, 147, 39);//brown

    glVertex3f(28.0,65.0,0.0);
    glVertex3f(39.0,65.0,0.0);
    glVertex3f(38.0,67.0,0.0);
    glVertex3f(29.0,67.0,0.0);


    glEnd();


    glBegin (GL_POLYGON);
// nagor dola gol


    glColor3ub(183, 4, 4);//chokolate
    glVertex3f(18.0,55.0,0.0);
    glVertex3f(20.0,56.0,0.0);
    glVertex3f(20.0,59.0,0.0);
    glVertex3f(18.0,60.0,0.0);
    glVertex3f(16.0,59.0,0.0);
    glVertex3f(16.0,56.0,0.0);

    glEnd();


    glBegin (GL_LINES);

//line 1
    glColor3ub(183, 4, 4);//chocolate
    glVertex3f(18.0,40.0,0.0);
    glVertex3f(18.0,69.0,0.0);
//line 2

    glVertex3f(10.0,57.0,0.0);
    glVertex3f(28.0,57.0,0.0);

//line 3

    glVertex3f(11.0,64.0,0.0);
    glVertex3f(30.0,45.0,0.0);

//line 4

    glVertex3f(7.0,47.0,0.0);
    glVertex3f(28.0,65.0,0.0);


    glEnd();
//*******************************************NAGOR DOLA END(shorna)***********************************************

//*********************************************Start of Sun(payel)************************************************

    float theta;//for the sun
    glColor3f(0.98, 0.494, 0.118);
    glLoadIdentity();
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        theta= i*3.142/180;
        glVertex2f(30+(4*cos(theta)), 90+(4*sin(theta) * (float)900 / 500));
    }
    glEnd();

//************************************************(End of sun)******************************************************



//*******************************************DOlna(Payel)***************************************************

//Dolna er left side pillar
    glLoadIdentity();

    glBegin(GL_QUADS);
    glColor3ub(183, 4, 4); //chocolate
    glVertex2i(35, 45);
    glVertex2i(36, 45);
    glVertex2i(56, 78);
    glVertex2i(55, 78);
    glEnd();

//Dolna er right side pillar
    glBegin(GL_QUADS);
    glColor3ub(183, 4, 4); //chocolate
    glVertex2i(74, 45);
    glVertex2i(75, 45);
    glVertex2i(56, 78);
    glVertex2i(55, 78);
    glEnd();

//Majkhaner part
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3ub(183, 4, 4); //chocolate
    glVertex2i(54, 77);
    glVertex2i(57, 77);
    glVertex2i(57, 80);
    glVertex2i(54, 80);
    glEnd();

//Dolna
    glBegin(GL_POLYGON);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(96, 40);
    glVertex2i(99, 40);
    glVertex2i(99, 43);
    glVertex2i(98.5, 44);
    glVertex2i(97.5, 44.5);
    glVertex2i(96.5, 44);
    glVertex2i(96, 43);
    glEnd();


//For the boat line part
    glLoadIdentity();
    glTranslatef(55.5,78,0.0);
    glRotatef(angleOfDolna,0.0,0.0,1.0);
    glTranslatef(-55.5,-78,0.0);
    glBegin (GL_LINES);
//line left
    glColor3f(0.0, 0.0, 0.0);//black
    glVertex2f(43,69);
    glVertex2f(55.5,78);

//line right
    glVertex2f(69,69);
    glVertex2f(55.5,78);

    glEnd();


//For boat dolna  ********************************************************* dolna boat (payel)

    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//red
    glVertex2i(40, 69);
    glVertex2i(43, 69);
    glColor3ub(31, 179, 75);   // Green
    glVertex2i(46, 65);
    glVertex2i(65, 65);
    glColor3ub(26, 118, 186); //blue
    glVertex2i(67, 69);
    glVertex2i(70, 69);
    glVertex2i(70, 70);
    glVertex2i(72, 70);
    glVertex2i(72, 71);
    glVertex2i(65, 71);
    glVertex2i(45, 71);
    glVertex2i(40, 71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);//black
    glVertex2i(43, 68);
    glVertex2i(47, 68);
    glVertex2i(47, 71);
    glVertex2i(43, 71);

    glColor3f(1.0, 1.0, 1.0);//white
    glVertex2i(44, 69);
    glVertex2i(46, 69);
    glVertex2i(46, 71);
    glVertex2i(44, 71);

    glColor3f(0.0, 0.0, 0.0);//black
    glVertex2i(48, 68);
    glVertex2i(53, 68);
    glVertex2i(53, 71);
    glVertex2i(48, 71);

    glColor3f(1.0, 1.0, 1.0);//white
    glVertex2i(49, 69);
    glVertex2i(52, 69);
    glVertex2i(52, 71);
    glVertex2i(49, 71);

    glColor3f(0.0, 0.0, 0.0);//black
    glVertex2i(54, 68);
    glVertex2i(59, 68);
    glVertex2i(59, 71);
    glVertex2i(54, 71);

    glColor3f(1.0, 1.0, 1.0);//white
    glVertex2i(55, 69);
    glVertex2i(58, 69);
    glVertex2i(58, 71);
    glVertex2i(55, 71);

    glColor3f(0.0, 0.0, 0.0);//black
    glVertex2i(60, 68);
    glVertex2i(65, 68);
    glVertex2i(65, 71);
    glVertex2i(60, 71);

    glColor3f(1.0, 1.0, 1.0);//white
    glVertex2i(61, 69);
    glVertex2i(64, 69);
    glVertex2i(64, 71);
    glVertex2i(61, 71);
    glEnd();

//*****************************************End of Dolna(payel)**********************************************


//**********************************************Start of (shimon)***********************************


//megh 1*********************************************************
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(bxm,0,0);


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,1,1);

    glVertex3f(22.6667f, 94.0f, 0.0f);
    glVertex3f(15.3333f, 87.8f, 0.0f);
    glVertex3f(15.3333f, 87.6f, 0.0f);
    glVertex3f(15.3333f, 87.4f, 0.0f);
    glVertex3f(15.3333f, 87.2f, 0.0f);
    glVertex3f(15.3333f, 87.0f, 0.0f);
    glVertex3f(15.3333f, 86.8f, 0.0f);
    glVertex3f(15.3333f, 86.6f, 0.0f);
    glVertex3f(15.4444f, 86.6f, 0.0f);
    glVertex3f(15.4444f, 86.4f, 0.0f);
    glVertex3f(15.5556f, 86.4f, 0.0f);
    glVertex3f(15.5556f, 86.2f, 0.0f);
    glVertex3f(15.6667f, 86.0f, 0.0f);
    glVertex3f(15.7778f, 86.0f, 0.0f);
    glVertex3f(15.7778f, 85.8f, 0.0f);
    glVertex3f(15.8889f, 85.8f, 0.0f);
    glVertex3f(16.0f, 85.8f, 0.0f);
    glVertex3f(16.1111f, 85.8f, 0.0f);
    glVertex3f(16.2222f, 85.8f, 0.0f);
    glVertex3f(16.3333f, 85.8f, 0.0f);
    glVertex3f(16.3333f, 85.6f, 0.0f);
    glVertex3f(16.4444f, 85.6f, 0.0f);
    glVertex3f(16.5556f, 85.6f, 0.0f);
    glVertex3f(16.6667f, 85.6f, 0.0f);
    glVertex3f(16.7778f, 85.6f, 0.0f);
    glVertex3f(16.8889f, 85.6f, 0.0f);
    glVertex3f(17.0f, 85.6f, 0.0f);
    glVertex3f(17.1111f, 85.6f, 0.0f);
    glVertex3f(17.2222f, 85.6f, 0.0f);
    glVertex3f(17.3333f, 85.6f, 0.0f);
    glVertex3f(17.4444f, 85.6f, 0.0f);
    glVertex3f(17.5556f, 85.6f, 0.0f);
    glVertex3f(17.6667f, 85.6f, 0.0f);
    glVertex3f(17.8889f, 85.6f, 0.0f);
    glVertex3f(18.0f, 85.6f, 0.0f);
    glVertex3f(18.2222f, 85.6f, 0.0f);
    glVertex3f(18.3333f, 85.6f, 0.0f);
    glVertex3f(18.4444f, 85.6f, 0.0f);
    glVertex3f(18.5556f, 85.6f, 0.0f);
    glVertex3f(18.6667f, 85.6f, 0.0f);
    glVertex3f(18.7778f, 85.6f, 0.0f);
    glVertex3f(18.8889f, 85.8f, 0.0f);
    glVertex3f(19.0f, 85.8f, 0.0f);
    glVertex3f(19.1111f, 85.8f, 0.0f);
    glVertex3f(19.2222f, 85.8f, 0.0f);
    glVertex3f(19.3333f, 85.8f, 0.0f);
    glVertex3f(19.3333f, 86.0f, 0.0f);
    glVertex3f(19.4444f, 86.0f, 0.0f);
    glVertex3f(19.5556f, 86.0f, 0.0f);
    glVertex3f(19.5556f, 86.2f, 0.0f);
    glVertex3f(19.6667f, 86.2f, 0.0f);
    glVertex3f(19.7778f, 86.2f, 0.0f);
    glVertex3f(19.7778f, 86.4f, 0.0f);
    glVertex3f(19.8889f, 86.4f, 0.0f);
    glVertex3f(19.8889f, 86.6f, 0.0f);
    glVertex3f(20.0f, 86.6f, 0.0f);
    glVertex3f(20.1111f, 86.8f, 0.0f);
    glVertex3f(20.2222f, 86.8f, 0.0f);
    glVertex3f(20.3333f, 86.8f, 0.0f);
    glVertex3f(20.3333f, 87.0f, 0.0f);
    glVertex3f(20.3333f, 87.2f, 0.0f);
    glVertex3f(20.4444f, 87.2f, 0.0f);
    glVertex3f(20.5556f, 87.2f, 0.0f);
    glVertex3f(20.5556f, 87.4f, 0.0f);
    glVertex3f(20.6667f, 87.4f, 0.0f);
    glVertex3f(20.7778f, 87.6f, 0.0f);
    glVertex3f(20.8889f, 87.6f, 0.0f);
    glVertex3f(20.8889f, 87.8f, 0.0f);
    glVertex3f(21.0f, 88.0f, 0.0f);
    glVertex3f(21.1111f, 88.2f, 0.0f);
    glVertex3f(21.2222f, 88.2f, 0.0f);
    glVertex3f(21.2222f, 88.4f, 0.0f);
    glVertex3f(21.3333f, 88.4f, 0.0f);
    glVertex3f(21.4444f, 88.6f, 0.0f);
    glVertex3f(21.5556f, 88.6f, 0.0f);
    glVertex3f(21.5556f, 88.8f, 0.0f);
    glVertex3f(21.6667f, 88.8f, 0.0f);
    glVertex3f(21.7778f, 89.0f, 0.0f);
    glVertex3f(21.8889f, 89.0f, 0.0f);
    glVertex3f(21.8889f, 89.2f, 0.0f);
    glVertex3f(22.0f, 89.2f, 0.0f);
    glVertex3f(22.1111f, 89.2f, 0.0f);
    glVertex3f(22.1111f, 89.4f, 0.0f);
    glVertex3f(22.2222f, 89.2f, 0.0f);
    glVertex3f(22.3333f, 89.0f, 0.0f);
    glVertex3f(22.3333f, 88.8f, 0.0f);
    glVertex3f(22.4444f, 88.6f, 0.0f);
    glVertex3f(22.4444f, 88.4f, 0.0f);
    glVertex3f(22.5556f, 88.4f, 0.0f);
    glVertex3f(22.5556f, 88.2f, 0.0f);
    glVertex3f(22.5556f, 88.0f, 0.0f);
    glVertex3f(22.6667f, 88.0f, 0.0f);
    glVertex3f(22.6667f, 87.8f, 0.0f);
    glVertex3f(22.6667f, 87.6f, 0.0f);
    glVertex3f(22.7778f, 87.6f, 0.0f);
    glVertex3f(22.7778f, 87.4f, 0.0f);
    glVertex3f(22.7778f, 87.2f, 0.0f);
    glVertex3f(22.8889f, 87.2f, 0.0f);
    glVertex3f(22.8889f, 87.0f, 0.0f);
    glVertex3f(22.8889f, 86.8f, 0.0f);
    glVertex3f(23.0f, 86.8f, 0.0f);
    glVertex3f(23.0f, 86.6f, 0.0f);
    glVertex3f(23.1111f, 86.4f, 0.0f);
    glVertex3f(23.1111f, 86.2f, 0.0f);
    glVertex3f(23.2222f, 86.0f, 0.0f);
    glVertex3f(23.2222f, 85.8f, 0.0f);
    glVertex3f(23.3333f, 85.8f, 0.0f);
    glVertex3f(23.3333f, 85.6f, 0.0f);
    glVertex3f(23.4444f, 85.6f, 0.0f);
    glVertex3f(23.5556f, 85.6f, 0.0f);
    glVertex3f(23.5556f, 85.4f, 0.0f);
    glVertex3f(23.6667f, 85.4f, 0.0f);
    glVertex3f(23.6667f, 85.2f, 0.0f);
    glVertex3f(23.7778f, 85.2f, 0.0f);
    glVertex3f(23.8889f, 85.2f, 0.0f);
    glVertex3f(24.0f, 85.2f, 0.0f);
    glVertex3f(24.1111f, 85.2f, 0.0f);
    glVertex3f(24.2222f, 85.2f, 0.0f);
    glVertex3f(24.3333f, 85.2f, 0.0f);
    glVertex3f(24.4444f, 85.2f, 0.0f);
    glVertex3f(24.5556f, 85.2f, 0.0f);
    glVertex3f(24.6667f, 85.2f, 0.0f);
    glVertex3f(24.7778f, 85.2f, 0.0f);
    glVertex3f(24.8889f, 85.2f, 0.0f);
    glVertex3f(25.0f, 85.2f, 0.0f);
    glVertex3f(25.1111f, 85.2f, 0.0f);
    glVertex3f(25.2222f, 85.2f, 0.0f);
    glVertex3f(25.3333f, 85.2f, 0.0f);
    glVertex3f(25.4444f, 85.2f, 0.0f);
    glVertex3f(25.5556f, 85.2f, 0.0f);
    glVertex3f(25.5556f, 85.4f, 0.0f);
    glVertex3f(25.6667f, 85.4f, 0.0f);
    glVertex3f(25.6667f, 85.6f, 0.0f);
    glVertex3f(25.7778f, 85.6f, 0.0f);
    glVertex3f(25.8889f, 85.6f, 0.0f);
    glVertex3f(26.0f, 85.6f, 0.0f);
    glVertex3f(26.1111f, 85.6f, 0.0f);
    glVertex3f(26.1111f, 85.8f, 0.0f);
    glVertex3f(26.2222f, 85.8f, 0.0f);
    glVertex3f(26.3333f, 85.8f, 0.0f);
    glVertex3f(26.4444f, 86.0f, 0.0f);
    glVertex3f(26.5556f, 86.0f, 0.0f);
    glVertex3f(26.6667f, 86.0f, 0.0f);
    glVertex3f(26.7778f, 86.2f, 0.0f);
    glVertex3f(26.8889f, 86.2f, 0.0f);
    glVertex3f(26.8889f, 86.4f, 0.0f);
    glVertex3f(27.0f, 86.4f, 0.0f);
    glVertex3f(27.0f, 86.6f, 0.0f);
    glVertex3f(27.1111f, 86.6f, 0.0f);
    glVertex3f(27.2222f, 86.8f, 0.0f);
    glVertex3f(27.2222f, 87.0f, 0.0f);
    glVertex3f(27.2222f, 87.2f, 0.0f);
    glVertex3f(27.3333f, 87.2f, 0.0f);
    glVertex3f(27.3333f, 87.4f, 0.0f);
    glVertex3f(27.3333f, 87.6f, 0.0f);
    glVertex3f(27.3333f, 87.8f, 0.0f);
    glVertex3f(27.3333f, 88.0f, 0.0f);
    glVertex3f(27.4444f, 88.2f, 0.0f);
    glVertex3f(27.4444f, 88.4f, 0.0f);
    glVertex3f(27.4444f, 88.6f, 0.0f);
    glVertex3f(27.4444f, 88.8f, 0.0f);
    glVertex3f(27.4444f, 89.0f, 0.0f);
    glVertex3f(27.4444f, 89.2f, 0.0f);
    glVertex3f(27.4444f, 89.4f, 0.0f);
    glVertex3f(27.5556f, 89.4f, 0.0f);
    glVertex3f(27.6667f, 89.4f, 0.0f);
    glVertex3f(27.7778f, 89.4f, 0.0f);
    glVertex3f(27.8889f, 89.4f, 0.0f);
    glVertex3f(28.1111f, 89.4f, 0.0f);
    glVertex3f(28.2222f, 89.4f, 0.0f);
    glVertex3f(28.4444f, 89.4f, 0.0f);
    glVertex3f(28.5556f, 89.4f, 0.0f);
    glVertex3f(28.7778f, 89.4f, 0.0f);
    glVertex3f(28.8889f, 89.4f, 0.0f);
    glVertex3f(29.1111f, 89.2f, 0.0f);
    glVertex3f(29.3333f, 89.2f, 0.0f);
    glVertex3f(29.4444f, 89.2f, 0.0f);
    glVertex3f(29.5556f, 89.2f, 0.0f);
    glVertex3f(29.7778f, 89.2f, 0.0f);
    glVertex3f(29.8889f, 89.2f, 0.0f);
    glVertex3f(30.0f, 89.2f, 0.0f);
    glVertex3f(30.1111f, 89.2f, 0.0f);
    glVertex3f(30.2222f, 89.2f, 0.0f);
    glVertex3f(30.3333f, 89.2f, 0.0f);
    glVertex3f(30.4444f, 89.2f, 0.0f);
    glVertex3f(30.6667f, 89.2f, 0.0f);
    glVertex3f(30.7778f, 89.2f, 0.0f);
    glVertex3f(30.8889f, 89.2f, 0.0f);
    glVertex3f(31.0f, 89.4f, 0.0f);
    glVertex3f(31.1111f, 89.4f, 0.0f);
    glVertex3f(31.2222f, 89.4f, 0.0f);
    glVertex3f(31.3333f, 89.4f, 0.0f);
    glVertex3f(31.3333f, 89.6f, 0.0f);
    glVertex3f(31.4444f, 89.6f, 0.0f);
    glVertex3f(31.5556f, 89.6f, 0.0f);
    glVertex3f(31.6667f, 89.6f, 0.0f);
    glVertex3f(31.7778f, 89.6f, 0.0f);
    glVertex3f(31.7778f, 89.8f, 0.0f);
    glVertex3f(31.8889f, 89.8f, 0.0f);
    glVertex3f(32.0f, 90.0f, 0.0f);
    glVertex3f(32.1111f, 90.0f, 0.0f);
    glVertex3f(32.2222f, 90.0f, 0.0f);
    glVertex3f(32.3333f, 90.2f, 0.0f);
    glVertex3f(32.4444f, 90.2f, 0.0f);
    glVertex3f(32.5556f, 90.2f, 0.0f);
    glVertex3f(32.5556f, 90.4f, 0.0f);
    glVertex3f(32.6667f, 90.4f, 0.0f);
    glVertex3f(32.7778f, 90.4f, 0.0f);
    glVertex3f(32.7778f, 90.6f, 0.0f);
    glVertex3f(32.8889f, 90.6f, 0.0f);
    glVertex3f(33.0f, 90.6f, 0.0f);
    glVertex3f(33.0f, 90.8f, 0.0f);
    glVertex3f(33.1111f, 90.8f, 0.0f);
    glVertex3f(33.2222f, 90.8f, 0.0f);
    glVertex3f(33.2222f, 91.0f, 0.0f);
    glVertex3f(33.3333f, 91.0f, 0.0f);
    glVertex3f(33.4444f, 91.0f, 0.0f);
    glVertex3f(33.5556f, 91.0f, 0.0f);
    glVertex3f(33.5556f, 91.2f, 0.0f);
    glVertex3f(33.6667f, 91.2f, 0.0f);
    glVertex3f(33.7778f, 91.2f, 0.0f);
    glVertex3f(33.8889f, 91.4f, 0.0f);
    glVertex3f(34.0f, 91.6f, 0.0f);
    glVertex3f(34.1111f, 91.6f, 0.0f);
    glVertex3f(34.2222f, 91.6f, 0.0f);
    glVertex3f(34.3333f, 91.8f, 0.0f);
    glVertex3f(34.4444f, 91.8f, 0.0f);
    glVertex3f(34.5556f, 91.8f, 0.0f);
    glVertex3f(34.5556f, 92.0f, 0.0f);
    glVertex3f(34.6667f, 92.0f, 0.0f);
    glVertex3f(34.7778f, 92.0f, 0.0f);
    glVertex3f(34.8889f, 92.2f, 0.0f);
    glVertex3f(35.0f, 92.4f, 0.0f);
    glVertex3f(35.1111f, 92.4f, 0.0f);
    glVertex3f(35.2222f, 92.4f, 0.0f);
    glVertex3f(35.2222f, 92.6f, 0.0f);
    glVertex3f(35.3333f, 92.6f, 0.0f);
    glVertex3f(35.3333f, 92.8f, 0.0f);
    glVertex3f(35.4444f, 92.8f, 0.0f);
    glVertex3f(35.5556f, 92.8f, 0.0f);
    glVertex3f(35.5556f, 93.0f, 0.0f);
    glVertex3f(35.6667f, 93.0f, 0.0f);
    glVertex3f(35.6667f, 93.2f, 0.0f);
    glVertex3f(35.7778f, 93.4f, 0.0f);
    glVertex3f(35.7778f, 93.6f, 0.0f);
    glVertex3f(35.8889f, 93.6f, 0.0f);
    glVertex3f(35.8889f, 93.8f, 0.0f);
    glVertex3f(36.0f, 93.8f, 0.0f);
    glVertex3f(36.0f, 94.0f, 0.0f);
    glVertex3f(36.0f, 94.2f, 0.0f);
    glVertex3f(36.1111f, 94.2f, 0.0f);
    glVertex3f(36.2222f, 94.2f, 0.0f);
    glVertex3f(36.2222f, 94.4f, 0.0f);
    glVertex3f(36.3333f, 94.4f, 0.0f);
    glVertex3f(36.3333f, 94.6f, 0.0f);
    glVertex3f(36.4444f, 94.6f, 0.0f);
    glVertex3f(36.4444f, 94.8f, 0.0f);
    glVertex3f(36.4444f, 95.0f, 0.0f);
    glVertex3f(36.5556f, 95.0f, 0.0f);
    glVertex3f(36.5556f, 95.2f, 0.0f);
    glVertex3f(36.6667f, 95.2f, 0.0f);
    glVertex3f(36.6667f, 95.4f, 0.0f);
    glVertex3f(36.6667f, 95.6f, 0.0f);
    glVertex3f(36.6667f, 95.8f, 0.0f);
    glVertex3f(36.5556f, 95.8f, 0.0f);
    glVertex3f(36.4444f, 95.8f, 0.0f);
    glVertex3f(36.4444f, 96.0f, 0.0f);
    glVertex3f(36.3333f, 96.0f, 0.0f);
    glVertex3f(36.2222f, 96.2f, 0.0f);
    glVertex3f(36.1111f, 96.2f, 0.0f);
    glVertex3f(36.0f, 96.2f, 0.0f);
    glVertex3f(36.0f, 96.4f, 0.0f);
    glVertex3f(35.8889f, 96.4f, 0.0f);
    glVertex3f(35.7778f, 96.6f, 0.0f);
    glVertex3f(35.6667f, 96.6f, 0.0f);
    glVertex3f(35.5556f, 96.6f, 0.0f);
    glVertex3f(35.4444f, 96.6f, 0.0f);
    glVertex3f(35.4444f, 96.8f, 0.0f);
    glVertex3f(35.3333f, 96.8f, 0.0f);
    glVertex3f(35.2222f, 96.8f, 0.0f);
    glVertex3f(35.1111f, 96.8f, 0.0f);
    glVertex3f(35.0f, 96.8f, 0.0f);
    glVertex3f(34.8889f, 96.8f, 0.0f);
    glVertex3f(34.7778f, 97.0f, 0.0f);
    glVertex3f(34.6667f, 97.0f, 0.0f);
    glVertex3f(34.5556f, 97.0f, 0.0f);
    glVertex3f(34.4444f, 97.0f, 0.0f);
    glVertex3f(34.3333f, 97.0f, 0.0f);
    glVertex3f(34.2222f, 97.0f, 0.0f);
    glVertex3f(34.1111f, 97.0f, 0.0f);
    glVertex3f(34.0f, 97.0f, 0.0f);
    glVertex3f(33.8889f, 97.0f, 0.0f);
    glVertex3f(33.7778f, 97.0f, 0.0f);
    glVertex3f(33.6667f, 97.0f, 0.0f);
    glVertex3f(33.5556f, 97.0f, 0.0f);
    glVertex3f(33.4444f, 97.0f, 0.0f);
    glVertex3f(33.4444f, 97.2f, 0.0f);
    glVertex3f(33.3333f, 97.2f, 0.0f);
    glVertex3f(33.2222f, 97.2f, 0.0f);
    glVertex3f(33.1111f, 97.2f, 0.0f);
    glVertex3f(33.0f, 97.2f, 0.0f);
    glVertex3f(32.8889f, 97.2f, 0.0f);
    glVertex3f(32.7778f, 97.2f, 0.0f);
    glVertex3f(32.6667f, 97.2f, 0.0f);
    glVertex3f(32.5556f, 97.2f, 0.0f);
    glVertex3f(32.4444f, 97.2f, 0.0f);
    glVertex3f(32.3333f, 97.4f, 0.0f);
    glVertex3f(32.2222f, 97.4f, 0.0f);
    glVertex3f(32.1111f, 97.4f, 0.0f);
    glVertex3f(32.0f, 97.4f, 0.0f);
    glVertex3f(31.8889f, 97.4f, 0.0f);
    glVertex3f(31.7778f, 97.4f, 0.0f);
    glVertex3f(31.6667f, 97.4f, 0.0f);
    glVertex3f(31.5556f, 97.4f, 0.0f);
    glVertex3f(31.4444f, 97.4f, 0.0f);
    glVertex3f(31.3333f, 97.4f, 0.0f);
    glVertex3f(31.2222f, 97.4f, 0.0f);
    glVertex3f(31.1111f, 97.4f, 0.0f);
    glVertex3f(31.0f, 97.4f, 0.0f);
    glVertex3f(30.8889f, 97.4f, 0.0f);
    glVertex3f(30.7778f, 97.4f, 0.0f);
    glVertex3f(30.6667f, 97.4f, 0.0f);
    glVertex3f(30.5556f, 97.4f, 0.0f);
    glVertex3f(30.4444f, 97.4f, 0.0f);
    glVertex3f(30.3333f, 97.4f, 0.0f);
    glVertex3f(30.2222f, 97.4f, 0.0f);
    glVertex3f(30.1111f, 97.4f, 0.0f);
    glVertex3f(30.0f, 97.4f, 0.0f);
    glVertex3f(29.8889f, 97.4f, 0.0f);
    glVertex3f(29.7778f, 97.4f, 0.0f);
    glVertex3f(29.7778f, 97.6f, 0.0f);
    glVertex3f(29.6667f, 97.6f, 0.0f);
    glVertex3f(29.5556f, 97.8f, 0.0f);
    glVertex3f(29.5556f, 98.0f, 0.0f);
    glVertex3f(29.4444f, 98.2f, 0.0f);
    glVertex3f(29.3333f, 98.2f, 0.0f);
    glVertex3f(29.3333f, 98.4f, 0.0f);
    glVertex3f(29.2222f, 98.4f, 0.0f);
    glVertex3f(29.1111f, 98.4f, 0.0f);
    glVertex3f(29.1111f, 98.6f, 0.0f);
    glVertex3f(29.0f, 98.6f, 0.0f);
    glVertex3f(28.8889f, 98.6f, 0.0f);
    glVertex3f(28.7778f, 98.6f, 0.0f);
    glVertex3f(28.6667f, 98.8f, 0.0f);
    glVertex3f(28.5556f, 98.8f, 0.0f);
    glVertex3f(28.4444f, 98.8f, 0.0f);
    glVertex3f(28.3333f, 98.8f, 0.0f);
    glVertex3f(28.2222f, 98.8f, 0.0f);
    glVertex3f(28.1111f, 98.8f, 0.0f);
    glVertex3f(28.0f, 98.8f, 0.0f);
    glVertex3f(27.8889f, 98.8f, 0.0f);
    glVertex3f(27.7778f, 98.8f, 0.0f);
    glVertex3f(27.6667f, 98.8f, 0.0f);
    glVertex3f(27.5556f, 98.6f, 0.0f);
    glVertex3f(27.4444f, 98.6f, 0.0f);
    glVertex3f(27.4444f, 98.4f, 0.0f);
    glVertex3f(27.3333f, 98.4f, 0.0f);
    glVertex3f(27.2222f, 98.4f, 0.0f);
    glVertex3f(27.2222f, 98.2f, 0.0f);
    glVertex3f(27.1111f, 98.2f, 0.0f);
    glVertex3f(27.0f, 98.2f, 0.0f);
    glVertex3f(27.0f, 98.0f, 0.0f);
    glVertex3f(26.8889f, 97.8f, 0.0f);
    glVertex3f(26.7778f, 97.8f, 0.0f);
    glVertex3f(26.6667f, 97.8f, 0.0f);
    glVertex3f(26.5556f, 97.8f, 0.0f);
    glVertex3f(26.5556f, 98.0f, 0.0f);
    glVertex3f(26.5556f, 98.2f, 0.0f);
    glVertex3f(26.4444f, 98.2f, 0.0f);
    glVertex3f(26.4444f, 98.4f, 0.0f);
    glVertex3f(26.3333f, 98.4f, 0.0f);
    glVertex3f(26.3333f, 98.6f, 0.0f);
    glVertex3f(26.2222f, 98.6f, 0.0f);
    glVertex3f(26.2222f, 98.8f, 0.0f);
    glVertex3f(26.1111f, 99.0f, 0.0f);
    glVertex3f(26.0f, 99.2f, 0.0f);
    glVertex3f(25.8889f, 99.2f, 0.0f);
    glVertex3f(25.8889f, 99.4f, 0.0f);
    glVertex3f(25.7778f, 99.4f, 0.0f);
    glVertex3f(25.7778f, 99.6f, 0.0f);
    glVertex3f(25.6667f, 99.6f, 0.0f);
    glVertex3f(25.6667f, 99.8f, 0.0f);
    glVertex3f(25.5556f, 99.8f, 0.0f);
    glVertex3f(25.4444f, 99.8f, 0.0f);
    glVertex3f(25.4444f, 100.0f, 0.0f);
    glVertex3f(25.3333f, 100.0f, 0.0f);
    glVertex3f(25.2222f, 100.0f, 0.0f);
    glVertex3f(25.1111f, 100.0f, 0.0f);
    glVertex3f(25.0f, 100.2f, 0.0f);
    glVertex3f(24.8889f, 100.2f, 0.0f);
    glVertex3f(24.7778f, 100.2f, 0.0f);
    glVertex3f(24.6667f, 100.2f, 0.0f);
    glVertex3f(24.5556f, 100.2f, 0.0f);
    glVertex3f(24.4444f, 100.2f, 0.0f);
    glVertex3f(24.3333f, 100.2f, 0.0f);
    glVertex3f(24.2222f, 100.2f, 0.0f);
    glVertex3f(24.1111f, 100.2f, 0.0f);
    glVertex3f(24.0f, 100.2f, 0.0f);
    glVertex3f(23.8889f, 100.2f, 0.0f);
    glVertex3f(23.8889f, 100.4f, 0.0f);
    glVertex3f(23.7778f, 100.4f, 0.0f);
    glVertex3f(23.6667f, 100.4f, 0.0f);
    glVertex3f(23.5556f, 100.4f, 0.0f);
    glVertex3f(23.4444f, 100.4f, 0.0f);
    glVertex3f(23.3333f, 100.4f, 0.0f);
    glVertex3f(23.2222f, 100.4f, 0.0f);
    glVertex3f(23.1111f, 100.4f, 0.0f);
    glVertex3f(23.0f, 100.4f, 0.0f);
    glVertex3f(22.8889f, 100.4f, 0.0f);
    glVertex3f(22.7778f, 100.4f, 0.0f);
    glVertex3f(22.6667f, 100.4f, 0.0f);
    glVertex3f(22.5556f, 100.4f, 0.0f);
    glVertex3f(22.4444f, 100.4f, 0.0f);
    glVertex3f(22.3333f, 100.4f, 0.0f);
    glVertex3f(22.2222f, 100.4f, 0.0f);
    glVertex3f(22.0f, 100.4f, 0.0f);
    glVertex3f(21.8889f, 100.4f, 0.0f);
    glVertex3f(21.6667f, 100.4f, 0.0f);
    glVertex3f(21.5556f, 100.4f, 0.0f);
    glVertex3f(21.4444f, 100.4f, 0.0f);
    glVertex3f(21.3333f, 100.4f, 0.0f);
    glVertex3f(21.1111f, 100.4f, 0.0f);
    glVertex3f(21.0f, 100.4f, 0.0f);
    glVertex3f(20.8889f, 100.4f, 0.0f);
    glVertex3f(20.6667f, 100.4f, 0.0f);
    glVertex3f(20.5556f, 100.4f, 0.0f);
    glVertex3f(20.3333f, 100.4f, 0.0f);
    glVertex3f(20.2222f, 100.4f, 0.0f);
    glVertex3f(20.1111f, 100.4f, 0.0f);
    glVertex3f(20.0f, 100.4f, 0.0f);
    glVertex3f(19.8889f, 100.4f, 0.0f);
    glVertex3f(19.7778f, 100.4f, 0.0f);
    glVertex3f(19.6667f, 100.4f, 0.0f);
    glVertex3f(19.5556f, 100.4f, 0.0f);
    glVertex3f(19.4444f, 100.4f, 0.0f);
    glVertex3f(19.3333f, 100.4f, 0.0f);
    glVertex3f(19.3333f, 100.2f, 0.0f);
    glVertex3f(19.2222f, 100.2f, 0.0f);
    glVertex3f(19.1111f, 100.2f, 0.0f);
    glVertex3f(19.1111f, 100.0f, 0.0f);
    glVertex3f(19.0f, 100.0f, 0.0f);
    glVertex3f(19.0f, 99.8f, 0.0f);
    glVertex3f(18.8889f, 99.8f, 0.0f);
    glVertex3f(18.8889f, 99.6f, 0.0f);
    glVertex3f(18.7778f, 99.4f, 0.0f);
    glVertex3f(18.7778f, 99.2f, 0.0f);
    glVertex3f(18.6667f, 99.2f, 0.0f);
    glVertex3f(18.6667f, 99.0f, 0.0f);
    glVertex3f(18.5556f, 99.0f, 0.0f);
    glVertex3f(18.5556f, 98.8f, 0.0f);
    glVertex3f(18.5556f, 98.6f, 0.0f);
    glVertex3f(18.4444f, 98.6f, 0.0f);
    glVertex3f(18.4444f, 98.4f, 0.0f);
    glVertex3f(18.4444f, 98.2f, 0.0f);
    glVertex3f(18.4444f, 98.0f, 0.0f);
    glVertex3f(18.3333f, 98.0f, 0.0f);
    glVertex3f(18.3333f, 97.8f, 0.0f);
    glVertex3f(18.3333f, 97.6f, 0.0f);
    glVertex3f(18.3333f, 97.4f, 0.0f);
    glVertex3f(18.2222f, 97.4f, 0.0f);
    glVertex3f(18.2222f, 97.2f, 0.0f);
    glVertex3f(18.1111f, 97.2f, 0.0f);
    glVertex3f(18.1111f, 97.0f, 0.0f);
    glVertex3f(18.0f, 97.0f, 0.0f);
    glVertex3f(18.0f, 96.8f, 0.0f);
    glVertex3f(17.8889f, 96.8f, 0.0f);
    glVertex3f(17.7778f, 96.6f, 0.0f);
    glVertex3f(17.6667f, 96.6f, 0.0f);
    glVertex3f(17.5556f, 96.6f, 0.0f);
    glVertex3f(17.4444f, 96.6f, 0.0f);
    glVertex3f(17.3333f, 96.8f, 0.0f);
    glVertex3f(17.2222f, 96.8f, 0.0f);
    glVertex3f(17.1111f, 96.8f, 0.0f);
    glVertex3f(17.0f, 97.0f, 0.0f);
    glVertex3f(16.8889f, 97.0f, 0.0f);
    glVertex3f(16.7778f, 97.0f, 0.0f);
    glVertex3f(16.6667f, 97.0f, 0.0f);
    glVertex3f(16.5556f, 97.0f, 0.0f);
    glVertex3f(16.4444f, 97.0f, 0.0f);
    glVertex3f(16.3333f, 97.2f, 0.0f);
    glVertex3f(16.2222f, 97.2f, 0.0f);
    glVertex3f(16.1111f, 97.2f, 0.0f);
    glVertex3f(16.0f, 97.2f, 0.0f);
    glVertex3f(15.8889f, 97.2f, 0.0f);
    glVertex3f(15.7778f, 97.2f, 0.0f);
    glVertex3f(15.6667f, 97.2f, 0.0f);
    glVertex3f(15.5556f, 97.2f, 0.0f);
    glVertex3f(15.4444f, 97.2f, 0.0f);
    glVertex3f(15.3333f, 97.2f, 0.0f);
    glVertex3f(15.2222f, 97.2f, 0.0f);
    glVertex3f(15.2222f, 97.0f, 0.0f);
    glVertex3f(15.1111f, 97.0f, 0.0f);
    glVertex3f(15.0f, 97.0f, 0.0f);
    glVertex3f(14.8889f, 97.0f, 0.0f);
    glVertex3f(14.7778f, 97.0f, 0.0f);
    glVertex3f(14.7778f, 96.8f, 0.0f);
    glVertex3f(14.6667f, 96.8f, 0.0f);
    glVertex3f(14.5556f, 96.6f, 0.0f);
    glVertex3f(14.4444f, 96.6f, 0.0f);
    glVertex3f(14.3333f, 96.4f, 0.0f);
    glVertex3f(14.2222f, 96.2f, 0.0f);
    glVertex3f(14.2222f, 96.0f, 0.0f);
    glVertex3f(14.1111f, 96.0f, 0.0f);
    glVertex3f(14.1111f, 95.8f, 0.0f);
    glVertex3f(14.0f, 95.8f, 0.0f);
    glVertex3f(13.8889f, 95.6f, 0.0f);
    glVertex3f(13.8889f, 95.4f, 0.0f);
    glVertex3f(13.7778f, 95.4f, 0.0f);
    glVertex3f(13.7778f, 95.2f, 0.0f);
    glVertex3f(13.7778f, 95.0f, 0.0f);
    glVertex3f(13.6667f, 95.0f, 0.0f);
    glVertex3f(13.6667f, 94.8f, 0.0f);
    glVertex3f(13.6667f, 94.6f, 0.0f);
    glVertex3f(13.6667f, 94.4f, 0.0f);
    glVertex3f(13.5556f, 94.4f, 0.0f);
    glVertex3f(13.5556f, 94.2f, 0.0f);
    glVertex3f(13.4444f, 94.2f, 0.0f);
    glVertex3f(13.3333f, 94.2f, 0.0f);
    glVertex3f(13.2222f, 94.2f, 0.0f);
    glVertex3f(13.1111f, 94.2f, 0.0f);
    glVertex3f(13.0f, 94.2f, 0.0f);
    glVertex3f(12.8889f, 94.2f, 0.0f);
    glVertex3f(12.8889f, 94.0f, 0.0f);
    glVertex3f(12.7778f, 94.0f, 0.0f);
    glVertex3f(12.6667f, 94.0f, 0.0f);
    glVertex3f(12.5556f, 94.0f, 0.0f);
    glVertex3f(12.4444f, 94.0f, 0.0f);
    glVertex3f(12.3333f, 94.0f, 0.0f);
    glVertex3f(12.3333f, 93.8f, 0.0f);
    glVertex3f(12.2222f, 93.8f, 0.0f);
    glVertex3f(12.1111f, 93.8f, 0.0f);
    glVertex3f(12.0f, 93.8f, 0.0f);
    glVertex3f(11.8889f, 93.8f, 0.0f);
    glVertex3f(11.8889f, 93.6f, 0.0f);
    glVertex3f(11.7778f, 93.6f, 0.0f);
    glVertex3f(11.6667f, 93.6f, 0.0f);
    glVertex3f(11.5556f, 93.6f, 0.0f);
    glVertex3f(11.4444f, 93.6f, 0.0f);
    glVertex3f(11.4444f, 93.4f, 0.0f);
    glVertex3f(11.3333f, 93.4f, 0.0f);
    glVertex3f(11.2222f, 93.4f, 0.0f);
    glVertex3f(11.1111f, 93.4f, 0.0f);
    glVertex3f(11.0f, 93.4f, 0.0f);
    glVertex3f(11.0f, 93.2f, 0.0f);
    glVertex3f(10.8889f, 93.2f, 0.0f);
    glVertex3f(10.8889f, 93.0f, 0.0f);
    glVertex3f(10.7778f, 93.0f, 0.0f);
    glVertex3f(10.6667f, 93.0f, 0.0f);
    glVertex3f(10.6667f, 92.8f, 0.0f);
    glVertex3f(10.5556f, 92.8f, 0.0f);
    glVertex3f(10.4444f, 92.8f, 0.0f);
    glVertex3f(10.4444f, 92.6f, 0.0f);
    glVertex3f(10.3333f, 92.6f, 0.0f);
    glVertex3f(10.3333f, 92.4f, 0.0f);
    glVertex3f(10.2222f, 92.2f, 0.0f);
    glVertex3f(10.2222f, 92.0f, 0.0f);
    glVertex3f(10.1111f, 92.0f, 0.0f);
    glVertex3f(10.1111f, 91.8f, 0.0f);
    glVertex3f(10.0f, 91.8f, 0.0f);
    glVertex3f(10.0f, 91.6f, 0.0f);
    glVertex3f(10.0f, 91.4f, 0.0f);
    glVertex3f(9.8889f, 91.4f, 0.0f);
    glVertex3f(9.8889f, 91.2f, 0.0f);
    glVertex3f(9.7778f, 91.2f, 0.0f);
    glVertex3f(9.7778f, 91.0f, 0.0f);
    glVertex3f(9.7778f, 90.8f, 0.0f);
    glVertex3f(9.6667f, 90.8f, 0.0f);
    glVertex3f(9.6667f, 90.6f, 0.0f);
    glVertex3f(9.6667f, 90.4f, 0.0f);
    glVertex3f(9.6667f, 90.2f, 0.0f);
    glVertex3f(9.6667f, 90.0f, 0.0f);
    glVertex3f(9.6667f, 89.8f, 0.0f);
    glVertex3f(9.6667f, 89.6f, 0.0f);
    glVertex3f(9.6667f, 89.4f, 0.0f);
    glVertex3f(9.6667f, 89.2f, 0.0f);
    glVertex3f(9.6667f, 89.0f, 0.0f);
    glVertex3f(9.6667f, 88.8f, 0.0f);
    glVertex3f(9.7778f, 88.8f, 0.0f);
    glVertex3f(9.7778f, 88.6f, 0.0f);
    glVertex3f(9.7778f, 88.4f, 0.0f);
    glVertex3f(9.8889f, 88.4f, 0.0f);
    glVertex3f(9.8889f, 88.2f, 0.0f);
    glVertex3f(10.0f, 88.2f, 0.0f);
    glVertex3f(10.0f, 88.0f, 0.0f);
    glVertex3f(10.1111f, 88.0f, 0.0f);
    glVertex3f(10.1111f, 87.8f, 0.0f);
    glVertex3f(10.2222f, 87.8f, 0.0f);
    glVertex3f(10.2222f, 87.6f, 0.0f);
    glVertex3f(10.3333f, 87.6f, 0.0f);
    glVertex3f(10.4444f, 87.6f, 0.0f);
    glVertex3f(10.4444f, 87.4f, 0.0f);
    glVertex3f(10.5556f, 87.4f, 0.0f);
    glVertex3f(10.6667f, 87.2f, 0.0f);
    glVertex3f(10.7778f, 87.2f, 0.0f);
    glVertex3f(10.8889f, 87.2f, 0.0f);
    glVertex3f(11.0f, 87.2f, 0.0f);
    glVertex3f(11.1111f, 87.2f, 0.0f);
    glVertex3f(11.2222f, 87.2f, 0.0f);
    glVertex3f(11.3333f, 87.2f, 0.0f);
    glVertex3f(11.4444f, 87.2f, 0.0f);
    glVertex3f(11.5556f, 87.2f, 0.0f);
    glVertex3f(11.6667f, 87.2f, 0.0f);
    glVertex3f(11.7778f, 87.2f, 0.0f);
    glVertex3f(11.7778f, 87.0f, 0.0f);
    glVertex3f(11.8889f, 87.0f, 0.0f);
    glVertex3f(12.0f, 87.0f, 0.0f);
    glVertex3f(12.1111f, 87.0f, 0.0f);
    glVertex3f(12.2222f, 87.0f, 0.0f);
    glVertex3f(12.3333f, 87.0f, 0.0f);
    glVertex3f(12.4444f, 87.0f, 0.0f);
    glVertex3f(12.5556f, 87.0f, 0.0f);
    glVertex3f(12.6667f, 86.8f, 0.0f);
    glVertex3f(12.7778f, 86.8f, 0.0f);
    glVertex3f(12.8889f, 86.8f, 0.0f);
    glVertex3f(13.0f, 86.8f, 0.0f);
    glVertex3f(13.1111f, 86.8f, 0.0f);
    glVertex3f(13.2222f, 86.8f, 0.0f);
    glVertex3f(13.3333f, 86.8f, 0.0f);
    glVertex3f(13.4444f, 86.8f, 0.0f);
    glVertex3f(13.5556f, 86.8f, 0.0f);
    glVertex3f(13.6667f, 86.8f, 0.0f);
    glVertex3f(13.7778f, 86.8f, 0.0f);
    glVertex3f(13.8889f, 86.8f, 0.0f);
    glVertex3f(14.0f, 86.8f, 0.0f);
    glVertex3f(14.1111f, 86.8f, 0.0f);
    glVertex3f(14.2222f, 86.8f, 0.0f);
    glVertex3f(14.3333f, 86.8f, 0.0f);
    glVertex3f(14.4444f, 86.8f, 0.0f);
    glVertex3f(14.5556f, 86.8f, 0.0f);
    glVertex3f(14.6667f, 86.8f, 0.0f);
    glVertex3f(14.7778f, 86.8f, 0.0f);
    glVertex3f(14.8889f, 86.8f, 0.0f);
    glVertex3f(15.0f, 86.8f, 0.0f);
    glVertex3f(15.1111f, 86.8f, 0.0f);
    glVertex3f(15.2222f, 86.8f, 0.0f);
    glVertex3f(15.3333f, 86.8f, 0.0f);

    glEnd();

    //Megh 2........................................................................................................

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,1,1);


    glVertex3f(52.2222f, 93.0f, 0.0f);

    glVertex3f(46.7778f, 90.6f, 0.0f);
    glVertex3f(46.6667f, 90.6f, 0.0f);
    glVertex3f(46.5556f, 90.6f, 0.0f);
    glVertex3f(46.4444f, 90.6f, 0.0f);
    glVertex3f(46.3333f, 90.6f, 0.0f);
    glVertex3f(46.2222f, 90.6f, 0.0f);
    glVertex3f(46.1111f, 90.6f, 0.0f);
    glVertex3f(46.0f, 90.6f, 0.0f);
    glVertex3f(45.8889f, 90.6f, 0.0f);
    glVertex3f(45.7778f, 90.6f, 0.0f);
    glVertex3f(45.6667f, 90.6f, 0.0f);
    glVertex3f(45.5556f, 90.6f, 0.0f);
    glVertex3f(45.4444f, 90.6f, 0.0f);
    glVertex3f(45.3333f, 90.6f, 0.0f);
    glVertex3f(45.2222f, 90.6f, 0.0f);
    glVertex3f(45.1111f, 90.6f, 0.0f);
    glVertex3f(45.0f, 90.6f, 0.0f);
    glVertex3f(44.8889f, 90.6f, 0.0f);
    glVertex3f(44.7778f, 90.6f, 0.0f);
    glVertex3f(44.6667f, 90.8f, 0.0f);
    glVertex3f(44.5556f, 90.8f, 0.0f);
    glVertex3f(44.4444f, 90.8f, 0.0f);
    glVertex3f(44.3333f, 91.0f, 0.0f);
    glVertex3f(44.3333f, 91.2f, 0.0f);
    glVertex3f(44.2222f, 91.2f, 0.0f);
    glVertex3f(44.1111f, 91.2f, 0.0f);
    glVertex3f(44.0f, 91.4f, 0.0f);
    glVertex3f(43.8889f, 91.4f, 0.0f);
    glVertex3f(43.8889f, 91.6f, 0.0f);
    glVertex3f(43.7778f, 91.6f, 0.0f);
    glVertex3f(43.7778f, 91.8f, 0.0f);
    glVertex3f(43.6667f, 91.8f, 0.0f);
    glVertex3f(43.6667f, 92.0f, 0.0f);
    glVertex3f(43.5556f, 92.0f, 0.0f);
    glVertex3f(43.5556f, 92.2f, 0.0f);
    glVertex3f(43.4444f, 92.2f, 0.0f);
    glVertex3f(43.4444f, 92.4f, 0.0f);
    glVertex3f(43.4444f, 92.6f, 0.0f);
    glVertex3f(43.4444f, 92.8f, 0.0f);
    glVertex3f(43.3333f, 92.8f, 0.0f);
    glVertex3f(43.3333f, 93.0f, 0.0f);
    glVertex3f(43.3333f, 93.2f, 0.0f);
    glVertex3f(43.3333f, 93.4f, 0.0f);
    glVertex3f(43.3333f, 93.6f, 0.0f);
    glVertex3f(43.3333f, 93.8f, 0.0f);
    glVertex3f(43.3333f, 94.0f, 0.0f);
    glVertex3f(43.3333f, 94.2f, 0.0f);
    glVertex3f(43.4444f, 94.4f, 0.0f);
    glVertex3f(43.5556f, 94.4f, 0.0f);
    glVertex3f(43.5556f, 94.6f, 0.0f);
    glVertex3f(43.5556f, 94.8f, 0.0f);
    glVertex3f(43.6667f, 94.8f, 0.0f);
    glVertex3f(43.6667f, 95.0f, 0.0f);
    glVertex3f(43.7778f, 95.0f, 0.0f);
    glVertex3f(43.7778f, 95.2f, 0.0f);
    glVertex3f(43.8889f, 95.4f, 0.0f);
    glVertex3f(44.0f, 95.6f, 0.0f);
    glVertex3f(44.1111f, 95.6f, 0.0f);
    glVertex3f(44.1111f, 95.8f, 0.0f);
    glVertex3f(44.2222f, 95.8f, 0.0f);
    glVertex3f(44.3333f, 96.0f, 0.0f);
    glVertex3f(44.3333f, 96.2f, 0.0f);
    glVertex3f(44.4444f, 96.2f, 0.0f);
    glVertex3f(44.5556f, 96.2f, 0.0f);
    glVertex3f(44.5556f, 96.4f, 0.0f);
    glVertex3f(44.6667f, 96.4f, 0.0f);
    glVertex3f(44.6667f, 96.6f, 0.0f);
    glVertex3f(44.7778f, 96.6f, 0.0f);
    glVertex3f(44.8889f, 96.6f, 0.0f);
    glVertex3f(44.8889f, 96.8f, 0.0f);
    glVertex3f(45.0f, 96.8f, 0.0f);
    glVertex3f(45.1111f, 96.8f, 0.0f);
    glVertex3f(45.2222f, 96.8f, 0.0f);
    glVertex3f(45.3333f, 96.8f, 0.0f);
    glVertex3f(45.4444f, 96.8f, 0.0f);
    glVertex3f(45.4444f, 96.6f, 0.0f);
    glVertex3f(45.5556f, 96.6f, 0.0f);
    glVertex3f(45.5556f, 96.4f, 0.0f);
    glVertex3f(45.6667f, 96.4f, 0.0f);
    glVertex3f(45.6667f, 96.2f, 0.0f);
    glVertex3f(45.7778f, 96.0f, 0.0f);
    glVertex3f(45.8889f, 96.0f, 0.0f);
    glVertex3f(46.0f, 95.8f, 0.0f);
    glVertex3f(46.1111f, 95.8f, 0.0f);
    glVertex3f(46.1111f, 95.6f, 0.0f);
    glVertex3f(46.2222f, 95.6f, 0.0f);
    glVertex3f(46.3333f, 95.6f, 0.0f);
    glVertex3f(46.3333f, 95.4f, 0.0f);
    glVertex3f(46.4444f, 95.4f, 0.0f);
    glVertex3f(46.5556f, 95.2f, 0.0f);
    glVertex3f(46.6667f, 95.2f, 0.0f);
    glVertex3f(46.6667f, 95.0f, 0.0f);
    glVertex3f(46.7778f, 95.0f, 0.0f);
    glVertex3f(46.8889f, 95.0f, 0.0f);
    glVertex3f(47.0f, 95.0f, 0.0f);
    glVertex3f(47.0f, 95.2f, 0.0f);
    glVertex3f(47.1111f, 95.2f, 0.0f);
    glVertex3f(47.2222f, 95.2f, 0.0f);
    glVertex3f(47.2222f, 95.4f, 0.0f);
    glVertex3f(47.3333f, 95.4f, 0.0f);
    glVertex3f(47.3333f, 95.6f, 0.0f);
    glVertex3f(47.4444f, 95.6f, 0.0f);
    glVertex3f(47.5556f, 95.6f, 0.0f);
    glVertex3f(47.5556f, 95.8f, 0.0f);
    glVertex3f(47.6667f, 95.8f, 0.0f);
    glVertex3f(47.7778f, 95.8f, 0.0f);
    glVertex3f(47.8889f, 95.8f, 0.0f);
    glVertex3f(47.8889f, 96.0f, 0.0f);
    glVertex3f(48.0f, 96.0f, 0.0f);
    glVertex3f(48.0f, 96.2f, 0.0f);
    glVertex3f(48.1111f, 96.2f, 0.0f);
    glVertex3f(48.2222f, 96.2f, 0.0f);
    glVertex3f(48.3333f, 96.2f, 0.0f);
    glVertex3f(48.4444f, 96.2f, 0.0f);
    glVertex3f(48.4444f, 96.4f, 0.0f);
    glVertex3f(48.5556f, 96.4f, 0.0f);
    glVertex3f(48.6667f, 96.4f, 0.0f);
    glVertex3f(48.7778f, 96.4f, 0.0f);
    glVertex3f(48.8889f, 96.4f, 0.0f);
    glVertex3f(49.0f, 96.4f, 0.0f);
    glVertex3f(49.1111f, 96.4f, 0.0f);
    glVertex3f(49.2222f, 96.4f, 0.0f);
    glVertex3f(49.3333f, 96.4f, 0.0f);
    glVertex3f(49.4444f, 96.4f, 0.0f);
    glVertex3f(49.5556f, 96.4f, 0.0f);
    glVertex3f(49.6667f, 96.4f, 0.0f);
    glVertex3f(49.7778f, 96.4f, 0.0f);
    glVertex3f(49.8889f, 96.4f, 0.0f);
    glVertex3f(50.0f, 96.2f, 0.0f);
    glVertex3f(50.0f, 96.0f, 0.0f);
    glVertex3f(50.1111f, 96.0f, 0.0f);
    glVertex3f(50.1111f, 95.8f, 0.0f);
    glVertex3f(50.2222f, 95.8f, 0.0f);
    glVertex3f(50.2222f, 95.6f, 0.0f);
    glVertex3f(50.3333f, 95.6f, 0.0f);
    glVertex3f(50.4444f, 95.6f, 0.0f);
    glVertex3f(50.5556f, 95.6f, 0.0f);
    glVertex3f(50.5556f, 95.8f, 0.0f);
    glVertex3f(50.6667f, 95.8f, 0.0f);
    glVertex3f(50.6667f, 96.0f, 0.0f);
    glVertex3f(50.7778f, 96.2f, 0.0f);
    glVertex3f(50.8889f, 96.2f, 0.0f);
    glVertex3f(50.8889f, 96.4f, 0.0f);
    glVertex3f(51.0f, 96.4f, 0.0f);
    glVertex3f(51.0f, 96.6f, 0.0f);
    glVertex3f(51.1111f, 96.6f, 0.0f);
    glVertex3f(51.1111f, 96.8f, 0.0f);
    glVertex3f(51.2222f, 96.8f, 0.0f);
    glVertex3f(51.2222f, 97.0f, 0.0f);
    glVertex3f(51.3333f, 97.0f, 0.0f);
    glVertex3f(51.4444f, 97.2f, 0.0f);
    glVertex3f(51.5556f, 97.4f, 0.0f);
    glVertex3f(51.6667f, 97.4f, 0.0f);
    glVertex3f(51.6667f, 97.6f, 0.0f);
    glVertex3f(51.7778f, 97.8f, 0.0f);
    glVertex3f(51.8889f, 97.8f, 0.0f);
    glVertex3f(52.0f, 97.8f, 0.0f);
    glVertex3f(52.0f, 98.0f, 0.0f);
    glVertex3f(52.1111f, 98.0f, 0.0f);
    glVertex3f(52.2222f, 98.0f, 0.0f);
    glVertex3f(52.3333f, 98.2f, 0.0f);
    glVertex3f(52.4444f, 98.2f, 0.0f);
    glVertex3f(52.5556f, 98.2f, 0.0f);
    glVertex3f(52.6667f, 98.4f, 0.0f);
    glVertex3f(52.7778f, 98.4f, 0.0f);
    glVertex3f(52.8889f, 98.4f, 0.0f);
    glVertex3f(52.8889f, 98.6f, 0.0f);
    glVertex3f(53.0f, 98.6f, 0.0f);
    glVertex3f(53.1111f, 98.6f, 0.0f);
    glVertex3f(53.2222f, 98.6f, 0.0f);
    glVertex3f(53.3333f, 98.6f, 0.0f);
    glVertex3f(53.4444f, 98.6f, 0.0f);
    glVertex3f(53.5556f, 98.6f, 0.0f);
    glVertex3f(53.6667f, 98.6f, 0.0f);
    glVertex3f(53.7778f, 98.6f, 0.0f);
    glVertex3f(53.8889f, 98.6f, 0.0f);
    glVertex3f(54.0f, 98.6f, 0.0f);
    glVertex3f(54.1111f, 98.6f, 0.0f);
    glVertex3f(54.2222f, 98.6f, 0.0f);
    glVertex3f(54.3333f, 98.6f, 0.0f);
    glVertex3f(54.4444f, 98.6f, 0.0f);
    glVertex3f(54.4444f, 98.4f, 0.0f);
    glVertex3f(54.5556f, 98.4f, 0.0f);
    glVertex3f(54.6667f, 98.2f, 0.0f);
    glVertex3f(54.7778f, 98.2f, 0.0f);
    glVertex3f(54.7778f, 98.0f, 0.0f);
    glVertex3f(54.8889f, 98.0f, 0.0f);
    glVertex3f(54.8889f, 97.8f, 0.0f);
    glVertex3f(54.8889f, 97.6f, 0.0f);
    glVertex3f(55.0f, 97.6f, 0.0f);
    glVertex3f(55.0f, 97.4f, 0.0f);
    glVertex3f(55.1111f, 97.4f, 0.0f);
    glVertex3f(55.1111f, 97.2f, 0.0f);
    glVertex3f(55.1111f, 97.0f, 0.0f);
    glVertex3f(55.1111f, 96.8f, 0.0f);
    glVertex3f(55.2222f, 96.8f, 0.0f);
    glVertex3f(55.2222f, 96.6f, 0.0f);
    glVertex3f(55.2222f, 96.4f, 0.0f);
    glVertex3f(55.2222f, 96.2f, 0.0f);
    glVertex3f(55.2222f, 96.0f, 0.0f);
    glVertex3f(55.3333f, 95.8f, 0.0f);
    glVertex3f(55.3333f, 95.6f, 0.0f);
    glVertex3f(55.3333f, 95.4f, 0.0f);
    glVertex3f(55.3333f, 95.2f, 0.0f);
    glVertex3f(55.4444f, 95.2f, 0.0f);
    glVertex3f(55.4444f, 95.0f, 0.0f);
    glVertex3f(55.4444f, 94.8f, 0.0f);
    glVertex3f(55.5556f, 94.8f, 0.0f);
    glVertex3f(55.6667f, 94.8f, 0.0f);
    glVertex3f(55.7778f, 94.8f, 0.0f);
    glVertex3f(55.7778f, 95.0f, 0.0f);
    glVertex3f(55.8889f, 95.0f, 0.0f);
    glVertex3f(56.0f, 95.0f, 0.0f);
    glVertex3f(56.0f, 95.2f, 0.0f);
    glVertex3f(56.0f, 95.4f, 0.0f);
    glVertex3f(56.1111f, 95.4f, 0.0f);
    glVertex3f(56.1111f, 95.6f, 0.0f);
    glVertex3f(56.2222f, 95.6f, 0.0f);
    glVertex3f(56.2222f, 95.8f, 0.0f);
    glVertex3f(56.3333f, 95.8f, 0.0f);
    glVertex3f(56.4444f, 95.8f, 0.0f);
    glVertex3f(56.4444f, 96.0f, 0.0f);
    glVertex3f(56.5556f, 96.0f, 0.0f);
    glVertex3f(56.5556f, 96.2f, 0.0f);
    glVertex3f(56.6667f, 96.2f, 0.0f);
    glVertex3f(56.6667f, 96.4f, 0.0f);
    glVertex3f(56.7778f, 96.4f, 0.0f);
    glVertex3f(56.8889f, 96.4f, 0.0f);
    glVertex3f(56.8889f, 96.6f, 0.0f);
    glVertex3f(57.0f, 96.6f, 0.0f);
    glVertex3f(57.1111f, 96.6f, 0.0f);
    glVertex3f(57.2222f, 96.8f, 0.0f);
    glVertex3f(57.3333f, 96.8f, 0.0f);
    glVertex3f(57.3333f, 97.0f, 0.0f);
    glVertex3f(57.4444f, 97.0f, 0.0f);
    glVertex3f(57.5556f, 97.0f, 0.0f);
    glVertex3f(57.6667f, 97.0f, 0.0f);
    glVertex3f(57.7778f, 97.0f, 0.0f);
    glVertex3f(57.7778f, 97.2f, 0.0f);
    glVertex3f(57.8889f, 97.2f, 0.0f);
    glVertex3f(58.0f, 97.2f, 0.0f);
    glVertex3f(58.1111f, 97.2f, 0.0f);
    glVertex3f(58.2222f, 97.2f, 0.0f);
    glVertex3f(58.3333f, 97.2f, 0.0f);
    glVertex3f(58.4444f, 97.2f, 0.0f);
    glVertex3f(58.5556f, 97.2f, 0.0f);
    glVertex3f(58.6667f, 97.2f, 0.0f);
    glVertex3f(58.7778f, 97.2f, 0.0f);
    glVertex3f(58.8889f, 97.2f, 0.0f);
    glVertex3f(59.0f, 97.2f, 0.0f);
    glVertex3f(59.1111f, 97.2f, 0.0f);
    glVertex3f(59.2222f, 97.2f, 0.0f);
    glVertex3f(59.3333f, 97.2f, 0.0f);
    glVertex3f(59.4444f, 97.2f, 0.0f);
    glVertex3f(59.5556f, 97.2f, 0.0f);
    glVertex3f(59.6667f, 97.2f, 0.0f);
    glVertex3f(59.7778f, 97.2f, 0.0f);
    glVertex3f(59.8889f, 97.2f, 0.0f);
    glVertex3f(60.0f, 97.2f, 0.0f);
    glVertex3f(60.1111f, 97.2f, 0.0f);
    glVertex3f(60.2222f, 97.2f, 0.0f);
    glVertex3f(60.2222f, 97.0f, 0.0f);
    glVertex3f(60.2222f, 96.8f, 0.0f);
    glVertex3f(60.3333f, 96.8f, 0.0f);
    glVertex3f(60.3333f, 96.6f, 0.0f);
    glVertex3f(60.3333f, 96.4f, 0.0f);
    glVertex3f(60.4444f, 96.4f, 0.0f);
    glVertex3f(60.4444f, 96.2f, 0.0f);
    glVertex3f(60.5556f, 96.0f, 0.0f);
    glVertex3f(60.5556f, 95.8f, 0.0f);
    glVertex3f(60.5556f, 95.6f, 0.0f);
    glVertex3f(60.5556f, 95.4f, 0.0f);
    glVertex3f(60.5556f, 95.2f, 0.0f);
    glVertex3f(60.5556f, 95.0f, 0.0f);
    glVertex3f(60.5556f, 94.8f, 0.0f);
    glVertex3f(60.5556f, 94.6f, 0.0f);
    glVertex3f(60.5556f, 94.4f, 0.0f);
    glVertex3f(60.5556f, 94.2f, 0.0f);
    glVertex3f(60.5556f, 94.0f, 0.0f);
    glVertex3f(60.5556f, 93.8f, 0.0f);
    glVertex3f(60.5556f, 93.6f, 0.0f);
    glVertex3f(60.5556f, 93.4f, 0.0f);
    glVertex3f(60.5556f, 93.2f, 0.0f);
    glVertex3f(60.4444f, 93.2f, 0.0f);
    glVertex3f(60.4444f, 93.0f, 0.0f);
    glVertex3f(60.3333f, 92.8f, 0.0f);
    glVertex3f(60.3333f, 92.6f, 0.0f);
    glVertex3f(60.2222f, 92.4f, 0.0f);
    glVertex3f(60.2222f, 92.2f, 0.0f);
    glVertex3f(60.1111f, 92.2f, 0.0f);
    glVertex3f(60.0f, 92.2f, 0.0f);
    glVertex3f(60.0f, 92.0f, 0.0f);
    glVertex3f(59.8889f, 91.8f, 0.0f);
    glVertex3f(59.8889f, 91.6f, 0.0f);
    glVertex3f(59.7778f, 91.6f, 0.0f);
    glVertex3f(59.6667f, 91.4f, 0.0f);
    glVertex3f(59.5556f, 91.4f, 0.0f);
    glVertex3f(59.4444f, 91.2f, 0.0f);
    glVertex3f(59.4444f, 91.0f, 0.0f);
    glVertex3f(59.3333f, 91.0f, 0.0f);
    glVertex3f(59.2222f, 91.0f, 0.0f);
    glVertex3f(59.2222f, 90.8f, 0.0f);
    glVertex3f(59.1111f, 90.8f, 0.0f);
    glVertex3f(59.0f, 90.8f, 0.0f);
    glVertex3f(58.8889f, 90.6f, 0.0f);
    glVertex3f(58.7778f, 90.6f, 0.0f);
    glVertex3f(58.6667f, 90.6f, 0.0f);
    glVertex3f(58.5556f, 90.4f, 0.0f);
    glVertex3f(58.4444f, 90.4f, 0.0f);
    glVertex3f(58.4444f, 90.2f, 0.0f);
    glVertex3f(58.3333f, 90.2f, 0.0f);
    glVertex3f(58.2222f, 90.2f, 0.0f);
    glVertex3f(58.1111f, 90.2f, 0.0f);
    glVertex3f(58.0f, 90.2f, 0.0f);
    glVertex3f(58.0f, 90.0f, 0.0f);
    glVertex3f(57.8889f, 90.0f, 0.0f);
    glVertex3f(57.7778f, 90.0f, 0.0f);
    glVertex3f(57.6667f, 90.0f, 0.0f);
    glVertex3f(57.5556f, 90.0f, 0.0f);
    glVertex3f(57.3333f, 90.0f, 0.0f);
    glVertex3f(57.2222f, 90.0f, 0.0f);
    glVertex3f(57.1111f, 89.8f, 0.0f);
    glVertex3f(57.0f, 89.8f, 0.0f);
    glVertex3f(56.8889f, 89.8f, 0.0f);
    glVertex3f(56.7778f, 89.8f, 0.0f);
    glVertex3f(56.6667f, 89.8f, 0.0f);
    glVertex3f(56.5556f, 89.8f, 0.0f);
    glVertex3f(56.4444f, 89.8f, 0.0f);
    glVertex3f(56.3333f, 89.8f, 0.0f);
    glVertex3f(56.2222f, 89.8f, 0.0f);
    glVertex3f(56.1111f, 89.8f, 0.0f);
    glVertex3f(56.0f, 89.8f, 0.0f);
    glVertex3f(55.8889f, 89.8f, 0.0f);
    glVertex3f(55.7778f, 89.8f, 0.0f);
    glVertex3f(55.6667f, 89.8f, 0.0f);
    glVertex3f(55.5556f, 89.8f, 0.0f);
    glVertex3f(55.3333f, 89.8f, 0.0f);
    glVertex3f(55.2222f, 89.8f, 0.0f);
    glVertex3f(55.2222f, 90.0f, 0.0f);
    glVertex3f(55.1111f, 90.0f, 0.0f);
    glVertex3f(55.0f, 90.0f, 0.0f);
    glVertex3f(54.8889f, 90.0f, 0.0f);
    glVertex3f(54.8889f, 90.2f, 0.0f);
    glVertex3f(54.8889f, 90.4f, 0.0f);
    glVertex3f(54.7778f, 90.4f, 0.0f);
    glVertex3f(54.6667f, 90.4f, 0.0f);
    glVertex3f(54.5556f, 90.4f, 0.0f);
    glVertex3f(54.4444f, 90.4f, 0.0f);
    glVertex3f(54.4444f, 90.2f, 0.0f);
    glVertex3f(54.3333f, 90.2f, 0.0f);
    glVertex3f(54.2222f, 90.0f, 0.0f);
    glVertex3f(54.1111f, 89.8f, 0.0f);
    glVertex3f(54.0f, 89.8f, 0.0f);
    glVertex3f(54.0f, 89.6f, 0.0f);
    glVertex3f(53.8889f, 89.6f, 0.0f);
    glVertex3f(53.8889f, 89.4f, 0.0f);
    glVertex3f(53.7778f, 89.4f, 0.0f);
    glVertex3f(53.7778f, 89.2f, 0.0f);
    glVertex3f(53.6667f, 89.2f, 0.0f);
    glVertex3f(53.5556f, 89.0f, 0.0f);
    glVertex3f(53.4444f, 89.0f, 0.0f);
    glVertex3f(53.4444f, 88.8f, 0.0f);
    glVertex3f(53.3333f, 88.8f, 0.0f);
    glVertex3f(53.2222f, 88.6f, 0.0f);
    glVertex3f(53.1111f, 88.6f, 0.0f);
    glVertex3f(53.1111f, 88.4f, 0.0f);
    glVertex3f(53.0f, 88.4f, 0.0f);
    glVertex3f(52.8889f, 88.4f, 0.0f);
    glVertex3f(52.8889f, 88.2f, 0.0f);
    glVertex3f(52.7778f, 88.2f, 0.0f);
    glVertex3f(52.6667f, 88.2f, 0.0f);
    glVertex3f(52.6667f, 88.0f, 0.0f);
    glVertex3f(52.5556f, 88.0f, 0.0f);
    glVertex3f(52.4444f, 88.0f, 0.0f);
    glVertex3f(52.3333f, 88.0f, 0.0f);
    glVertex3f(52.3333f, 87.8f, 0.0f);
    glVertex3f(52.2222f, 87.8f, 0.0f);
    glVertex3f(52.2222f, 87.6f, 0.0f);
    glVertex3f(52.1111f, 87.6f, 0.0f);
    glVertex3f(52.0f, 87.6f, 0.0f);
    glVertex3f(51.8889f, 87.6f, 0.0f);
    glVertex3f(51.7778f, 87.6f, 0.0f);
    glVertex3f(51.7778f, 87.4f, 0.0f);
    glVertex3f(51.6667f, 87.4f, 0.0f);
    glVertex3f(51.5556f, 87.4f, 0.0f);
    glVertex3f(51.4444f, 87.4f, 0.0f);
    glVertex3f(51.3333f, 87.4f, 0.0f);
    glVertex3f(51.2222f, 87.4f, 0.0f);
    glVertex3f(51.2222f, 87.2f, 0.0f);
    glVertex3f(51.1111f, 87.2f, 0.0f);
    glVertex3f(50.8889f, 87.2f, 0.0f);
    glVertex3f(50.7778f, 87.0f, 0.0f);
    glVertex3f(50.6667f, 87.0f, 0.0f);
    glVertex3f(50.5556f, 87.0f, 0.0f);
    glVertex3f(50.4444f, 87.0f, 0.0f);
    glVertex3f(50.2222f, 87.0f, 0.0f);
    glVertex3f(50.1111f, 87.0f, 0.0f);
    glVertex3f(50.0f, 87.0f, 0.0f);
    glVertex3f(49.8889f, 87.0f, 0.0f);
    glVertex3f(49.7778f, 87.0f, 0.0f);
    glVertex3f(49.6667f, 87.0f, 0.0f);
    glVertex3f(49.5556f, 87.0f, 0.0f);
    glVertex3f(49.4444f, 87.0f, 0.0f);
    glVertex3f(49.3333f, 87.0f, 0.0f);
    glVertex3f(49.2222f, 87.0f, 0.0f);
    glVertex3f(49.1111f, 87.0f, 0.0f);
    glVertex3f(49.0f, 87.0f, 0.0f);
    glVertex3f(48.8889f, 87.0f, 0.0f);
    glVertex3f(48.7778f, 87.0f, 0.0f);
    glVertex3f(48.6667f, 87.0f, 0.0f);
    glVertex3f(48.5556f, 87.0f, 0.0f);
    glVertex3f(48.4444f, 87.0f, 0.0f);
    glVertex3f(48.3333f, 87.0f, 0.0f);
    glVertex3f(48.2222f, 87.0f, 0.0f);
    glVertex3f(48.2222f, 87.2f, 0.0f);
    glVertex3f(48.1111f, 87.2f, 0.0f);
    glVertex3f(48.0f, 87.2f, 0.0f);
    glVertex3f(47.8889f, 87.4f, 0.0f);
    glVertex3f(47.7778f, 87.4f, 0.0f);
    glVertex3f(47.6667f, 87.6f, 0.0f);
    glVertex3f(47.5556f, 87.6f, 0.0f);
    glVertex3f(47.5556f, 87.8f, 0.0f);
    glVertex3f(47.4444f, 88.0f, 0.0f);
    glVertex3f(47.4444f, 88.2f, 0.0f);
    glVertex3f(47.3333f, 88.2f, 0.0f);
    glVertex3f(47.3333f, 88.4f, 0.0f);
    glVertex3f(47.3333f, 88.6f, 0.0f);
    glVertex3f(47.2222f, 88.8f, 0.0f);
    glVertex3f(47.1111f, 88.8f, 0.0f);
    glVertex3f(47.1111f, 89.0f, 0.0f);
    glVertex3f(47.1111f, 89.2f, 0.0f);
    glVertex3f(47.0f, 89.4f, 0.0f);
    glVertex3f(47.0f, 89.6f, 0.0f);
    glVertex3f(47.0f, 89.8f, 0.0f);
    glVertex3f(46.8889f, 89.8f, 0.0f);
    glVertex3f(46.8889f, 90.0f, 0.0f);
    glVertex3f(46.8889f, 90.2f, 0.0f);
    glVertex3f(46.8889f, 90.4f, 0.0f);
    glVertex3f(46.8889f, 90.4f, 0.0f);
    glVertex3f(46.8889f, 90.2f, 0.0f);
    glVertex3f(46.8889f, 90.0f, 0.0f);
    glVertex3f(46.8889f, 89.8f, 0.0f);
    glVertex3f(47.0f, 89.8f, 0.0f);
    glVertex3f(47.0f, 89.6f, 0.0f);
    glVertex3f(47.1111f, 89.6f, 0.0f);
    glVertex3f(47.1111f, 89.4f, 0.0f);
    glVertex3f(47.1111f, 89.2f, 0.0f);
    glVertex3f(47.2222f, 89.2f, 0.0f);
    glVertex3f(47.3333f, 89.2f, 0.0f);
    glVertex3f(47.3333f, 89.0f, 0.0f);
    glVertex3f(47.4444f, 89.0f, 0.0f);
    glVertex3f(47.4444f, 88.8f, 0.0f);
    glVertex3f(47.5556f, 88.8f, 0.0f);
    glVertex3f(47.6667f, 88.8f, 0.0f);
    glVertex3f(47.6667f, 88.6f, 0.0f);
    glVertex3f(47.7778f, 88.6f, 0.0f);
    glVertex3f(47.8889f, 88.6f, 0.0f);
    glVertex3f(47.8889f, 88.4f, 0.0f);
    glVertex3f(48.0f, 88.4f, 0.0f);
    glVertex3f(48.0f, 88.2f, 0.0f);
    glVertex3f(48.1111f, 88.2f, 0.0f);
    glVertex3f(48.2222f, 88.2f, 0.0f);
    glVertex3f(48.3333f, 88.2f, 0.0f);
    glVertex3f(48.3333f, 88.0f, 0.0f);
    glVertex3f(48.4444f, 88.0f, 0.0f);
    glVertex3f(48.5556f, 87.8f, 0.0f);
    glVertex3f(48.6667f, 87.8f, 0.0f);
    glVertex3f(48.7778f, 87.8f, 0.0f);
    glVertex3f(48.7778f, 87.6f, 0.0f);
    glVertex3f(48.8889f, 87.6f, 0.0f);
    glVertex3f(49.0f, 87.6f, 0.0f);
    glVertex3f(49.1111f, 87.4f, 0.0f);
    glVertex3f(49.2222f, 87.4f, 0.0f);
    glVertex3f(49.3333f, 87.4f, 0.0f);
    glVertex3f(49.4444f, 87.4f, 0.0f);
    glVertex3f(49.5556f, 87.4f, 0.0f);
    glVertex3f(49.6667f, 87.4f, 0.0f);
    glVertex3f(49.6667f, 87.2f, 0.0f);
    glVertex3f(49.7778f, 87.2f, 0.0f);
    glVertex3f(49.8889f, 87.2f, 0.0f);
    glVertex3f(50.0f, 87.2f, 0.0f);
    glVertex3f(50.1111f, 87.2f, 0.0f);
    glVertex3f(50.2222f, 87.2f, 0.0f);
    glVertex3f(50.3333f, 87.2f, 0.0f);
    glVertex3f(50.4444f, 87.2f, 0.0f);
    glVertex3f(50.5556f, 87.2f, 0.0f);
    glVertex3f(50.6667f, 87.2f, 0.0f);
    glVertex3f(50.7778f, 87.2f, 0.0f);
    glVertex3f(50.8889f, 87.2f, 0.0f);
    glVertex3f(51.0f, 87.2f, 0.0f);
    glVertex3f(51.1111f, 87.2f, 0.0f);
    glVertex3f(51.2222f, 87.2f, 0.0f);
    glVertex3f(51.3333f, 87.2f, 0.0f);
    glVertex3f(51.4444f, 87.2f, 0.0f);
    glVertex3f(51.5556f, 87.2f, 0.0f);
    glVertex3f(51.6667f, 87.2f, 0.0f);
    glVertex3f(51.7778f, 87.2f, 0.0f);
    glVertex3f(51.8889f, 87.2f, 0.0f);
    glVertex3f(52.0f, 87.2f, 0.0f);
    glVertex3f(52.1111f, 87.2f, 0.0f);
    glVertex3f(52.2222f, 87.2f, 0.0f);
    glVertex3f(52.2222f, 87.4f, 0.0f);
    glVertex3f(52.3333f, 87.4f, 0.0f);
    glVertex3f(52.4444f, 87.6f, 0.0f);
    glVertex3f(52.5556f, 87.6f, 0.0f);
    glVertex3f(52.6667f, 87.6f, 0.0f);
    glVertex3f(52.7778f, 87.6f, 0.0f);
    glVertex3f(52.7778f, 87.8f, 0.0f);
    glVertex3f(52.8889f, 87.8f, 0.0f);
    glVertex3f(53.0f, 88.0f, 0.0f);
    glVertex3f(53.1111f, 88.0f, 0.0f);
    glVertex3f(53.2222f, 88.0f, 0.0f);
    glVertex3f(53.2222f, 88.2f, 0.0f);
    glVertex3f(53.3333f, 88.2f, 0.0f);
    glVertex3f(53.3333f, 88.4f, 0.0f);
    glVertex3f(53.4444f, 88.4f, 0.0f);
    glVertex3f(53.5556f, 88.6f, 0.0f);
    glVertex3f(53.6667f, 88.6f, 0.0f);
    glVertex3f(53.7778f, 88.6f, 0.0f);
    glVertex3f(53.7778f, 88.8f, 0.0f);
    glVertex3f(53.8889f, 88.8f, 0.0f);
    glVertex3f(53.8889f, 89.0f, 0.0f);
    glVertex3f(54.0f, 89.0f, 0.0f);
    glVertex3f(54.1111f, 89.0f, 0.0f);
    glVertex3f(54.1111f, 89.2f, 0.0f);
    glVertex3f(54.2222f, 89.2f, 0.0f);
    glVertex3f(54.2222f, 89.4f, 0.0f);
    glVertex3f(54.3333f, 89.4f, 0.0f);
    glVertex3f(54.3333f, 89.6f, 0.0f);
    glVertex3f(54.4444f, 89.6f, 0.0f);
    glVertex3f(54.5556f, 89.6f, 0.0f);
    glVertex3f(54.5556f, 89.8f, 0.0f);
    glVertex3f(54.5556f, 90.0f, 0.0f);
    glVertex3f(54.6667f, 90.2f, 0.0f);
    glVertex3f(54.7778f, 90.4f, 0.0f);
    glVertex3f(54.8889f, 90.6f, 0.0f);
    glVertex3f(55.0f, 90.6f, 0.0f);
    glVertex3f(55.0f, 90.8f, 0.0f);
    glVertex3f(55.1111f, 91.0f, 0.0f);
    glVertex3f(55.2222f, 91.2f, 0.0f);
    glVertex3f(55.2222f, 91.4f, 0.0f);
    glVertex3f(55.3333f, 91.4f, 0.0f);
    glVertex3f(55.4444f, 91.4f, 0.0f);
    glVertex3f(55.4444f, 91.6f, 0.0f);
    glVertex3f(55.4444f, 91.8f, 0.0f);
    glVertex3f(55.5556f, 91.8f, 0.0f);
    glVertex3f(55.5556f, 92.0f, 0.0f);
    glVertex3f(55.6667f, 92.0f, 0.0f);
    glVertex3f(55.7778f, 92.0f, 0.0f);
    glVertex3f(55.8889f, 92.0f, 0.0f);
    glVertex3f(56.0f, 92.0f, 0.0f);
    glVertex3f(56.1111f, 92.0f, 0.0f);
    glVertex3f(56.1111f, 91.8f, 0.0f);
    glVertex3f(56.2222f, 91.8f, 0.0f);
    glVertex3f(56.3333f, 91.8f, 0.0f);
    glVertex3f(56.4444f, 91.8f, 0.0f);
    glVertex3f(56.4444f, 91.6f, 0.0f);
    glVertex3f(56.5556f, 91.6f, 0.0f);
    glVertex3f(56.6667f, 91.6f, 0.0f);
    glVertex3f(56.7778f, 91.6f, 0.0f);
    glVertex3f(56.8889f, 91.6f, 0.0f);
    glVertex3f(57.0f, 91.6f, 0.0f);
    glVertex3f(57.1111f, 91.6f, 0.0f);
    glVertex3f(57.2222f, 91.6f, 0.0f);
    glVertex3f(57.3333f, 91.6f, 0.0f);
    glVertex3f(57.4444f, 91.6f, 0.0f);
    glVertex3f(57.5556f, 91.6f, 0.0f);
    glVertex3f(57.6667f, 91.6f, 0.0f);
    glVertex3f(57.7778f, 91.6f, 0.0f);
    glVertex3f(57.8889f, 91.6f, 0.0f);
    glVertex3f(58.0f, 91.6f, 0.0f);
    glVertex3f(58.1111f, 91.6f, 0.0f);
    glVertex3f(58.2222f, 91.6f, 0.0f);
    glVertex3f(58.2222f, 91.8f, 0.0f);
    glVertex3f(58.3333f, 91.8f, 0.0f);
    glVertex3f(58.4444f, 91.8f, 0.0f);
    glVertex3f(58.5556f, 91.8f, 0.0f);
    glVertex3f(58.6667f, 91.8f, 0.0f);
    glVertex3f(58.6667f, 92.0f, 0.0f);
    glVertex3f(58.7778f, 92.0f, 0.0f);
    glVertex3f(58.8889f, 92.0f, 0.0f);
    glVertex3f(58.8889f, 92.2f, 0.0f);
    glVertex3f(59.0f, 92.2f, 0.0f);
    glVertex3f(59.0f, 92.4f, 0.0f);
    glVertex3f(59.1111f, 92.4f, 0.0f);
    glVertex3f(59.2222f, 92.6f, 0.0f);
    glVertex3f(59.3333f, 92.6f, 0.0f);
    glVertex3f(59.3333f, 92.8f, 0.0f);
    glVertex3f(59.4444f, 92.8f, 0.0f);
    glVertex3f(59.4444f, 93.0f, 0.0f);
    glVertex3f(59.5556f, 93.0f, 0.0f);
    glVertex3f(59.6667f, 93.0f, 0.0f);
    glVertex3f(59.6667f, 93.2f, 0.0f);
    glVertex3f(59.6667f, 93.4f, 0.0f);
    glVertex3f(59.7778f, 93.4f, 0.0f);
    glVertex3f(59.7778f, 93.6f, 0.0f);
    glVertex3f(59.8889f, 93.6f, 0.0f);
    glVertex3f(59.8889f, 93.8f, 0.0f);
    glVertex3f(60.0f, 93.8f, 0.0f);
    glVertex3f(60.0f, 94.0f, 0.0f);
    glVertex3f(60.1111f, 94.0f, 0.0f);
    glVertex3f(60.1111f, 94.2f, 0.0f);
    glVertex3f(60.2222f, 94.2f, 0.0f);
    glVertex3f(60.2222f, 94.4f, 0.0f);
    glVertex3f(60.2222f, 94.6f, 0.0f);
    glVertex3f(60.2222f, 94.8f, 0.0f);
    glVertex3f(60.3333f, 94.8f, 0.0f);
    glVertex3f(60.3333f, 95.0f, 0.0f);
    glVertex3f(60.3333f, 95.2f, 0.0f);
    glVertex3f(60.3333f, 95.4f, 0.0f);
    glVertex3f(60.3333f, 95.6f, 0.0f);
    glVertex3f(60.3333f, 95.8f, 0.0f);
    glVertex3f(60.3333f, 96.0f, 0.0f);
    glVertex3f(60.3333f, 96.2f, 0.0f);
    glVertex3f(60.3333f, 96.4f, 0.0f);
    glVertex3f(60.3333f, 96.6f, 0.0f);
    glVertex3f(60.3333f, 96.8f, 0.0f);
    glVertex3f(60.2222f, 96.8f, 0.0f);
    glVertex3f(60.1111f, 96.8f, 0.0f);
    glVertex3f(60.0f, 96.8f, 0.0f);
    glVertex3f(60.0f, 97.0f, 0.0f);
    glVertex3f(59.8889f, 97.0f, 0.0f);
    glVertex3f(59.7778f, 97.0f, 0.0f);
    glVertex3f(59.6667f, 97.0f, 0.0f);
    glVertex3f(59.5556f, 97.2f, 0.0f);
    glVertex3f(59.4444f, 97.2f, 0.0f);
    glVertex3f(59.3333f, 97.2f, 0.0f);
    glVertex3f(59.2222f, 97.2f, 0.0f);
    glVertex3f(59.1111f, 97.2f, 0.0f);
    glVertex3f(59.0f, 97.2f, 0.0f);
    glVertex3f(58.8889f, 97.2f, 0.0f);
    glVertex3f(58.8889f, 97.4f, 0.0f);
    glVertex3f(58.7778f, 97.4f, 0.0f);
    glVertex3f(58.6667f, 97.4f, 0.0f);
    glVertex3f(58.5556f, 97.4f, 0.0f);
    glVertex3f(58.4444f, 97.4f, 0.0f);
    glVertex3f(58.4444f, 97.6f, 0.0f);
    glVertex3f(58.3333f, 97.6f, 0.0f);
    glVertex3f(58.2222f, 97.6f, 0.0f);
    glVertex3f(58.1111f, 97.6f, 0.0f);
    glVertex3f(58.0f, 97.6f, 0.0f);
    glVertex3f(57.8889f, 97.6f, 0.0f);
    glVertex3f(57.7778f, 97.6f, 0.0f);
    glVertex3f(57.6667f, 97.6f, 0.0f);
    glVertex3f(57.5556f, 97.6f, 0.0f);
    glVertex3f(57.4444f, 97.6f, 0.0f);
    glVertex3f(57.3333f, 97.6f, 0.0f);
    glVertex3f(57.2222f, 97.6f, 0.0f);
    glVertex3f(57.1111f, 97.6f, 0.0f);
    glVertex3f(57.0f, 97.6f, 0.0f);
    glVertex3f(56.8889f, 97.6f, 0.0f);
    glVertex3f(56.7778f, 97.6f, 0.0f);
    glVertex3f(56.7778f, 97.4f, 0.0f);
    glVertex3f(56.6667f, 97.4f, 0.0f);
    glVertex3f(56.5556f, 97.4f, 0.0f);
    glVertex3f(56.4444f, 97.2f, 0.0f);
    glVertex3f(56.3333f, 97.2f, 0.0f);
    glVertex3f(56.2222f, 97.2f, 0.0f);
    glVertex3f(56.2222f, 97.0f, 0.0f);
    glVertex3f(56.1111f, 97.0f, 0.0f);
    glVertex3f(56.0f, 97.0f, 0.0f);
    glVertex3f(55.8889f, 96.8f, 0.0f);
    glVertex3f(55.8889f, 96.6f, 0.0f);
    glVertex3f(55.7778f, 96.6f, 0.0f);
    glVertex3f(55.7778f, 96.4f, 0.0f);
    glVertex3f(55.6667f, 96.4f, 0.0f);
    glVertex3f(55.6667f, 96.2f, 0.0f);
    glVertex3f(55.5556f, 96.0f, 0.0f);
    glVertex3f(55.5556f, 95.8f, 0.0f);
    glVertex3f(55.5556f, 95.6f, 0.0f);
    glVertex3f(55.4444f, 95.4f, 0.0f);
    glVertex3f(55.4444f, 95.2f, 0.0f);
    glVertex3f(55.3333f, 95.2f, 0.0f);
    glVertex3f(55.3333f, 95.0f, 0.0f);
    glVertex3f(55.3333f, 94.8f, 0.0f);
    glVertex3f(55.3333f, 94.6f, 0.0f);
    glVertex3f(55.2222f, 94.6f, 0.0f);
    glVertex3f(55.2222f, 94.8f, 0.0f);
    glVertex3f(55.1111f, 94.8f, 0.0f);
    glVertex3f(55.1111f, 95.0f, 0.0f);
    glVertex3f(55.1111f, 95.2f, 0.0f);
    glVertex3f(55.0f, 95.2f, 0.0f);
    glVertex3f(55.0f, 95.4f, 0.0f);
    glVertex3f(54.8889f, 95.4f, 0.0f);
    glVertex3f(54.8889f, 95.6f, 0.0f);
    glVertex3f(54.8889f, 95.8f, 0.0f);
    glVertex3f(54.8889f, 96.0f, 0.0f);
    glVertex3f(54.7778f, 96.0f, 0.0f);
    glVertex3f(54.7778f, 96.2f, 0.0f);
    glVertex3f(54.7778f, 96.4f, 0.0f);
    glVertex3f(54.6667f, 96.4f, 0.0f);
    glVertex3f(54.6667f, 96.6f, 0.0f);
    glVertex3f(54.6667f, 96.8f, 0.0f);
    glVertex3f(54.5556f, 96.8f, 0.0f);
    glVertex3f(54.5556f, 97.0f, 0.0f);
    glVertex3f(54.4444f, 97.0f, 0.0f);
    glVertex3f(54.4444f, 97.2f, 0.0f);
    glVertex3f(54.3333f, 97.2f, 0.0f);
    glVertex3f(54.3333f, 97.4f, 0.0f);
    glVertex3f(54.3333f, 97.6f, 0.0f);
    glVertex3f(54.2222f, 97.6f, 0.0f);
    glVertex3f(54.2222f, 97.8f, 0.0f);
    glVertex3f(54.1111f, 97.8f, 0.0f);
    glVertex3f(54.0f, 97.8f, 0.0f);
    glVertex3f(54.0f, 98.0f, 0.0f);
    glVertex3f(53.8889f, 98.0f, 0.0f);
    glVertex3f(53.7778f, 98.0f, 0.0f);
    glVertex3f(53.7778f, 98.2f, 0.0f);
    glVertex3f(53.6667f, 98.2f, 0.0f);
    glVertex3f(53.5556f, 98.2f, 0.0f);
    glVertex3f(53.5556f, 98.4f, 0.0f);
    glVertex3f(53.4444f, 98.4f, 0.0f);
    glVertex3f(53.3333f, 98.4f, 0.0f);
    glVertex3f(53.3333f, 98.6f, 0.0f);
    glVertex3f(53.2222f, 98.6f, 0.0f);
    glVertex3f(53.1111f, 98.6f, 0.0f);
    glVertex3f(53.0f, 98.6f, 0.0f);
    glVertex3f(52.8889f, 98.6f, 0.0f);
    glVertex3f(52.7778f, 98.6f, 0.0f);
    glVertex3f(52.6667f, 98.6f, 0.0f);
    glVertex3f(52.5556f, 98.6f, 0.0f);
    glVertex3f(52.4444f, 98.6f, 0.0f);
    glVertex3f(52.3333f, 98.6f, 0.0f);
    glVertex3f(52.2222f, 98.6f, 0.0f);
    glVertex3f(52.1111f, 98.6f, 0.0f);
    glVertex3f(52.0f, 98.6f, 0.0f);
    glVertex3f(51.8889f, 98.6f, 0.0f);
    glVertex3f(51.7778f, 98.6f, 0.0f);
    glVertex3f(51.6667f, 98.6f, 0.0f);
    glVertex3f(51.5556f, 98.6f, 0.0f);
    glVertex3f(51.4444f, 98.6f, 0.0f);
    glVertex3f(51.4444f, 98.4f, 0.0f);
    glVertex3f(51.3333f, 98.4f, 0.0f);
    glVertex3f(51.3333f, 98.2f, 0.0f);
    glVertex3f(51.2222f, 98.2f, 0.0f);
    glVertex3f(51.2222f, 98.0f, 0.0f);
    glVertex3f(51.1111f, 98.0f, 0.0f);
    glVertex3f(51.1111f, 97.8f, 0.0f);
    glVertex3f(51.0f, 97.8f, 0.0f);
    glVertex3f(51.0f, 97.6f, 0.0f);
    glVertex3f(51.0f, 97.4f, 0.0f);
    glVertex3f(50.8889f, 97.4f, 0.0f);
    glVertex3f(50.8889f, 97.2f, 0.0f);
    glVertex3f(50.7778f, 97.2f, 0.0f);
    glVertex3f(50.7778f, 97.0f, 0.0f);
    glVertex3f(50.6667f, 97.0f, 0.0f);
    glVertex3f(50.6667f, 96.8f, 0.0f);
    glVertex3f(50.6667f, 96.6f, 0.0f);
    glVertex3f(50.5556f, 96.6f, 0.0f);
    glVertex3f(50.4444f, 96.4f, 0.0f);
    glVertex3f(50.3333f, 96.4f, 0.0f);
    glVertex3f(50.3333f, 96.2f, 0.0f);
    glVertex3f(50.2222f, 96.2f, 0.0f);
    glVertex3f(50.2222f, 96.0f, 0.0f);
    glVertex3f(50.2222f, 95.8f, 0.0f);
    glVertex3f(50.1111f, 95.8f, 0.0f);
    glVertex3f(50.0f, 95.8f, 0.0f);
    glVertex3f(50.0f, 96.0f, 0.0f);
    glVertex3f(49.8889f, 96.0f, 0.0f);
    glVertex3f(49.8889f, 96.2f, 0.0f);
    glVertex3f(49.7778f, 96.2f, 0.0f);
    glVertex3f(49.7778f, 96.4f, 0.0f);
    glVertex3f(49.6667f, 96.4f, 0.0f);
    glVertex3f(49.6667f, 96.6f, 0.0f);
    glVertex3f(49.5556f, 96.6f, 0.0f);
    glVertex3f(49.5556f, 96.8f, 0.0f);
    glVertex3f(49.4444f, 96.8f, 0.0f);
    glVertex3f(49.3333f, 96.8f, 0.0f);
    glVertex3f(49.2222f, 96.8f, 0.0f);
    glVertex3f(49.1111f, 96.8f, 0.0f);
    glVertex3f(49.0f, 96.8f, 0.0f);
    glVertex3f(49.0f, 97.0f, 0.0f);
    glVertex3f(48.8889f, 97.0f, 0.0f);
    glVertex3f(48.7778f, 97.0f, 0.0f);
    glVertex3f(48.6667f, 97.0f, 0.0f);
    glVertex3f(48.5556f, 97.0f, 0.0f);
    glVertex3f(48.4444f, 97.0f, 0.0f);
    glVertex3f(48.3333f, 97.0f, 0.0f);
    glVertex3f(48.2222f, 97.0f, 0.0f);
    glVertex3f(48.1111f, 97.0f, 0.0f);
    glVertex3f(48.0f, 97.0f, 0.0f);
    glVertex3f(47.8889f, 97.0f, 0.0f);
    glVertex3f(47.7778f, 97.0f, 0.0f);
    glVertex3f(47.6667f, 97.0f, 0.0f);
    glVertex3f(47.5556f, 97.0f, 0.0f);
    glVertex3f(47.4444f, 97.0f, 0.0f);
    glVertex3f(47.3333f, 97.0f, 0.0f);
    glVertex3f(47.3333f, 96.8f, 0.0f);
    glVertex3f(47.2222f, 96.8f, 0.0f);
    glVertex3f(47.2222f, 96.6f, 0.0f);
    glVertex3f(47.1111f, 96.6f, 0.0f);
    glVertex3f(47.0f, 96.6f, 0.0f);
    glVertex3f(47.0f, 96.4f, 0.0f);
    glVertex3f(46.8889f, 96.4f, 0.0f);
    glVertex3f(46.7778f, 96.2f, 0.0f);
    glVertex3f(46.6667f, 96.2f, 0.0f);
    glVertex3f(46.6667f, 96.0f, 0.0f);
    glVertex3f(46.5556f, 95.8f, 0.0f);
    glVertex3f(46.5556f, 95.6f, 0.0f);
    glVertex3f(46.4444f, 95.6f, 0.0f);
    glVertex3f(46.3333f, 95.6f, 0.0f);
    glVertex3f(46.2222f, 95.6f, 0.0f);
    glVertex3f(46.1111f, 95.6f, 0.0f);
    glVertex3f(46.0f, 95.6f, 0.0f);
    glVertex3f(45.8889f, 95.6f, 0.0f);
    glVertex3f(45.7778f, 95.6f, 0.0f);
    glVertex3f(45.6667f, 95.6f, 0.0f);
    glVertex3f(45.5556f, 95.6f, 0.0f);
    glVertex3f(45.4444f, 95.6f, 0.0f);
    glVertex3f(45.3333f, 95.6f, 0.0f);
    glVertex3f(45.2222f, 95.6f, 0.0f);
    glVertex3f(45.1111f, 95.6f, 0.0f);
    glVertex3f(45.0f, 95.6f, 0.0f);
    glVertex3f(44.8889f, 95.6f, 0.0f);
    glVertex3f(44.7778f, 95.6f, 0.0f);
    glVertex3f(44.6667f, 95.6f, 0.0f);
    glVertex3f(44.5556f, 95.6f, 0.0f);
    glVertex3f(44.5556f, 95.4f, 0.0f);
    glVertex3f(44.4444f, 95.4f, 0.0f);
    glVertex3f(44.3333f, 95.4f, 0.0f);
    glVertex3f(44.3333f, 95.2f, 0.0f);
    glVertex3f(44.3333f, 95.0f, 0.0f);
    glVertex3f(44.2222f, 95.0f, 0.0f);
    glVertex3f(44.2222f, 94.8f, 0.0f);
    glVertex3f(44.1111f, 94.8f, 0.0f);
    glVertex3f(44.1111f, 94.6f, 0.0f);
    glVertex3f(44.1111f, 94.4f, 0.0f);
    glVertex3f(44.0f, 94.4f, 0.0f);
    glVertex3f(44.0f, 94.2f, 0.0f);
    glVertex3f(44.0f, 94.0f, 0.0f);
    glVertex3f(43.8889f, 94.0f, 0.0f);
    glVertex3f(43.8889f, 93.8f, 0.0f);
    glVertex3f(43.8889f, 93.6f, 0.0f);
    glVertex3f(43.7778f, 93.4f, 0.0f);
    glVertex3f(43.7778f, 93.2f, 0.0f);
    glVertex3f(43.6667f, 93.0f, 0.0f);
    glVertex3f(43.6667f, 92.8f, 0.0f);
    glVertex3f(43.6667f, 92.6f, 0.0f);
    glVertex3f(43.6667f, 92.4f, 0.0f);
    glVertex3f(43.6667f, 92.2f, 0.0f);
    glVertex3f(43.6667f, 92.0f, 0.0f);
    glVertex3f(43.6667f, 91.8f, 0.0f);
    glVertex3f(43.6667f, 91.6f, 0.0f);
    glVertex3f(43.6667f, 91.4f, 0.0f);
    glVertex3f(43.6667f, 91.2f, 0.0f);
    glVertex3f(43.7778f, 91.2f, 0.0f);
    glVertex3f(43.7778f, 91.0f, 0.0f);
    glVertex3f(43.8889f, 91.0f, 0.0f);
    glVertex3f(43.8889f, 90.8f, 0.0f);
    glVertex3f(43.8889f, 90.6f, 0.0f);
    glVertex3f(44.0f, 90.6f, 0.0f);
    glVertex3f(44.0f, 90.4f, 0.0f);
    glVertex3f(44.1111f, 90.4f, 0.0f);
    glVertex3f(44.2222f, 90.4f, 0.0f);
    glVertex3f(44.3333f, 90.4f, 0.0f);
    glVertex3f(44.4444f, 90.2f, 0.0f);
    glVertex3f(44.5556f, 90.2f, 0.0f);
    glVertex3f(44.6667f, 90.2f, 0.0f);
    glVertex3f(44.7778f, 90.2f, 0.0f);
    glVertex3f(44.7778f, 90.0f, 0.0f);
    glVertex3f(44.8889f, 90.0f, 0.0f);
    glVertex3f(45.0f, 90.0f, 0.0f);
    glVertex3f(45.1111f, 89.8f, 0.0f);
    glVertex3f(45.2222f, 89.8f, 0.0f);
    glVertex3f(45.3333f, 89.8f, 0.0f);
    glVertex3f(45.3333f, 89.6f, 0.0f);
    glVertex3f(45.4444f, 89.6f, 0.0f);
    glVertex3f(45.5556f, 89.6f, 0.0f);
    glVertex3f(45.6667f, 89.6f, 0.0f);
    glVertex3f(45.7778f, 89.6f, 0.0f);
    glVertex3f(45.7778f, 89.4f, 0.0f);
    glVertex3f(45.8889f, 89.4f, 0.0f);
    glVertex3f(46.0f, 89.4f, 0.0f);
    glVertex3f(46.1111f, 89.4f, 0.0f);
    glVertex3f(46.2222f, 89.4f, 0.0f);
    glVertex3f(46.3333f, 89.4f, 0.0f);
    glVertex3f(46.4444f, 89.4f, 0.0f);
    glVertex3f(46.5556f, 89.4f, 0.0f);
    glVertex3f(46.6667f, 89.4f, 0.0f);
    glVertex3f(46.7778f, 89.4f, 0.0f);
    glVertex3f(46.8889f, 89.4f, 0.0f);
    glVertex3f(46.8889f, 89.6f, 0.0f);
    glVertex3f(47.0f, 89.6f, 0.0f);
    glVertex3f(47.1111f, 89.6f, 0.0f);
    glVertex3f(47.1111f, 89.8f, 0.0f);
    glVertex3f(47.1111f, 90.0f, 0.0f);

    glEnd();


//megh 3...........................................
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,1,1);
    glVertex3f(87.5556f, 89.8f, 0.0f);
    glVertex3f(80.4444f, 93.0f, 0.0f);
    glVertex3f(80.4444f, 93.2f, 0.0f);
    glVertex3f(80.4444f, 93.4f, 0.0f);
    glVertex3f(80.4444f, 93.6f, 0.0f);
    glVertex3f(80.4444f, 93.8f, 0.0f);
    glVertex3f(80.5556f, 93.8f, 0.0f);
    glVertex3f(80.5556f, 94.0f, 0.0f);
    glVertex3f(80.6667f, 94.0f, 0.0f);
    glVertex3f(80.7778f, 94.2f, 0.0f);
    glVertex3f(80.8889f, 94.2f, 0.0f);
    glVertex3f(80.8889f, 94.4f, 0.0f);
    glVertex3f(81.0f, 94.4f, 0.0f);
    glVertex3f(81.1111f, 94.4f, 0.0f);
    glVertex3f(81.1111f, 94.2f, 0.0f);
    glVertex3f(81.2222f, 94.0f, 0.0f);
    glVertex3f(81.3333f, 94.0f, 0.0f);
    glVertex3f(81.4444f, 94.0f, 0.0f);
    glVertex3f(81.5556f, 94.0f, 0.0f);
    glVertex3f(81.5556f, 94.2f, 0.0f);
    glVertex3f(81.6667f, 94.2f, 0.0f);
    glVertex3f(81.7778f, 94.2f, 0.0f);
    glVertex3f(81.7778f, 94.4f, 0.0f);
    glVertex3f(81.8889f, 94.4f, 0.0f);
    glVertex3f(82.0f, 94.4f, 0.0f);
    glVertex3f(82.0f, 94.6f, 0.0f);
    glVertex3f(82.1111f, 94.6f, 0.0f);
    glVertex3f(82.2222f, 94.4f, 0.0f);
    glVertex3f(82.2222f, 94.2f, 0.0f);
    glVertex3f(82.2222f, 94.4f, 0.0f);
    glVertex3f(82.2222f, 94.6f, 0.0f);
    glVertex3f(82.2222f, 94.8f, 0.0f);
    glVertex3f(82.2222f, 95.0f, 0.0f);
    glVertex3f(82.2222f, 95.4f, 0.0f);
    glVertex3f(82.3333f, 95.6f, 0.0f);
    glVertex3f(82.3333f, 95.8f, 0.0f);
    glVertex3f(82.3333f, 96.2f, 0.0f);
    glVertex3f(82.3333f, 96.4f, 0.0f);
    glVertex3f(82.4444f, 96.6f, 0.0f);
    glVertex3f(82.4444f, 96.8f, 0.0f);
    glVertex3f(82.5556f, 97.0f, 0.0f);
    glVertex3f(82.5556f, 97.2f, 0.0f);
    glVertex3f(82.5556f, 97.4f, 0.0f);
    glVertex3f(82.6667f, 97.6f, 0.0f);
    glVertex3f(82.7778f, 97.8f, 0.0f);
    glVertex3f(82.8889f, 97.8f, 0.0f);
    glVertex3f(82.8889f, 98.0f, 0.0f);
    glVertex3f(83.0f, 98.0f, 0.0f);
    glVertex3f(83.0f, 98.2f, 0.0f);
    glVertex3f(83.1111f, 98.2f, 0.0f);
    glVertex3f(83.2222f, 98.2f, 0.0f);
    glVertex3f(83.3333f, 98.2f, 0.0f);
    glVertex3f(83.4444f, 98.2f, 0.0f);
    glVertex3f(83.5556f, 98.2f, 0.0f);
    glVertex3f(83.6667f, 98.2f, 0.0f);
    glVertex3f(83.7778f, 98.2f, 0.0f);
    glVertex3f(84.0f, 98.2f, 0.0f);
    glVertex3f(84.1111f, 98.0f, 0.0f);
    glVertex3f(84.3333f, 97.8f, 0.0f);
    glVertex3f(84.5556f, 97.6f, 0.0f);
    glVertex3f(84.7778f, 97.4f, 0.0f);
    glVertex3f(85.0f, 97.2f, 0.0f);
    glVertex3f(85.2222f, 97.0f, 0.0f);
    glVertex3f(85.4444f, 96.8f, 0.0f);
    glVertex3f(85.6667f, 96.6f, 0.0f);
    glVertex3f(85.8889f, 96.4f, 0.0f);
    glVertex3f(86.0f, 96.4f, 0.0f);
    glVertex3f(86.1111f, 96.2f, 0.0f);
    glVertex3f(86.1111f, 96.0f, 0.0f);
    glVertex3f(86.2222f, 96.0f, 0.0f);
    glVertex3f(86.3333f, 95.8f, 0.0f);
    glVertex3f(86.4444f, 95.6f, 0.0f);
    glVertex3f(86.5556f, 95.6f, 0.0f);
    glVertex3f(86.6667f, 95.6f, 0.0f);
    glVertex3f(86.7778f, 95.6f, 0.0f);
    glVertex3f(86.8889f, 95.6f, 0.0f);
    glVertex3f(86.8889f, 95.8f, 0.0f);
    glVertex3f(87.0f, 95.8f, 0.0f);
    glVertex3f(87.1111f, 95.8f, 0.0f);
    glVertex3f(87.2222f, 95.8f, 0.0f);
    glVertex3f(87.3333f, 95.8f, 0.0f);
    glVertex3f(87.4444f, 95.6f, 0.0f);
    glVertex3f(87.4444f, 95.4f, 0.0f);
    glVertex3f(87.4444f, 95.2f, 0.0f);
    glVertex3f(87.4444f, 95.0f, 0.0f);
    glVertex3f(87.5556f, 95.0f, 0.0f);
    glVertex3f(87.6667f, 95.0f, 0.0f);
    glVertex3f(87.7778f, 95.0f, 0.0f);
    glVertex3f(87.8889f, 95.0f, 0.0f);
    glVertex3f(88.0f, 95.0f, 0.0f);
    glVertex3f(88.1111f, 95.2f, 0.0f);
    glVertex3f(88.2222f, 95.4f, 0.0f);
    glVertex3f(88.3333f, 95.4f, 0.0f);
    glVertex3f(88.4444f, 95.6f, 0.0f);
    glVertex3f(88.5556f, 95.6f, 0.0f);
    glVertex3f(88.6667f, 95.6f, 0.0f);
    glVertex3f(88.7778f, 95.6f, 0.0f);
    glVertex3f(88.8889f, 95.6f, 0.0f);
    glVertex3f(88.8889f, 95.4f, 0.0f);
    glVertex3f(88.8889f, 95.2f, 0.0f);
    glVertex3f(89.0f, 95.2f, 0.0f);
    glVertex3f(89.0f, 95.0f, 0.0f);
    glVertex3f(89.1111f, 95.0f, 0.0f);
    glVertex3f(89.2222f, 95.2f, 0.0f);
    glVertex3f(89.2222f, 95.4f, 0.0f);
    glVertex3f(89.4444f, 95.8f, 0.0f);
    glVertex3f(89.5556f, 96.0f, 0.0f);
    glVertex3f(89.7778f, 96.2f, 0.0f);
    glVertex3f(89.8889f, 96.4f, 0.0f);
    glVertex3f(90.0f, 96.6f, 0.0f);
    glVertex3f(90.3333f, 96.8f, 0.0f);
    glVertex3f(90.4444f, 96.8f, 0.0f);
    glVertex3f(90.5556f, 97.0f, 0.0f);
    glVertex3f(90.7778f, 97.2f, 0.0f);
    glVertex3f(91.0f, 97.4f, 0.0f);
    glVertex3f(91.1111f, 97.4f, 0.0f);
    glVertex3f(91.2222f, 97.4f, 0.0f);
    glVertex3f(91.4444f, 97.4f, 0.0f);
    glVertex3f(91.5556f, 97.4f, 0.0f);
    glVertex3f(91.6667f, 97.4f, 0.0f);
    glVertex3f(91.8889f, 97.4f, 0.0f);
    glVertex3f(92.0f, 97.2f, 0.0f);
    glVertex3f(92.2222f, 96.8f, 0.0f);
    glVertex3f(92.4444f, 96.6f, 0.0f);
    glVertex3f(92.5556f, 96.4f, 0.0f);
    glVertex3f(92.6667f, 96.0f, 0.0f);
    glVertex3f(93.0f, 95.8f, 0.0f);
    glVertex3f(93.1111f, 95.2f, 0.0f);
    glVertex3f(93.3333f, 94.8f, 0.0f);
    glVertex3f(93.4444f, 94.4f, 0.0f);
    glVertex3f(93.6667f, 94.0f, 0.0f);
    glVertex3f(93.6667f, 93.4f, 0.0f);
    glVertex3f(93.7778f, 93.2f, 0.0f);
    glVertex3f(93.8889f, 92.8f, 0.0f);
    glVertex3f(94.0f, 92.6f, 0.0f);
    glVertex3f(94.0f, 92.2f, 0.0f);
    glVertex3f(94.1111f, 92.0f, 0.0f);
    glVertex3f(94.1111f, 91.8f, 0.0f);
    glVertex3f(94.2222f, 91.8f, 0.0f);
    glVertex3f(94.3333f, 91.8f, 0.0f);
    glVertex3f(94.4444f, 91.8f, 0.0f);
    glVertex3f(94.5556f, 91.8f, 0.0f);
    glVertex3f(94.6667f, 91.8f, 0.0f);
    glVertex3f(94.6667f, 92.0f, 0.0f);
    glVertex3f(94.7778f, 92.0f, 0.0f);
    glVertex3f(94.8889f, 92.0f, 0.0f);
    glVertex3f(95.0f, 92.0f, 0.0f);
    glVertex3f(95.1111f, 92.0f, 0.0f);
    glVertex3f(95.1111f, 92.2f, 0.0f);
    glVertex3f(95.2222f, 92.2f, 0.0f);
    glVertex3f(95.3333f, 92.2f, 0.0f);
    glVertex3f(95.4444f, 92.2f, 0.0f);
    glVertex3f(95.4444f, 92.0f, 0.0f);
    glVertex3f(95.5556f, 91.8f, 0.0f);
    glVertex3f(95.6667f, 91.6f, 0.0f);
    glVertex3f(95.6667f, 91.4f, 0.0f);
    glVertex3f(95.7778f, 91.2f, 0.0f);
    glVertex3f(95.7778f, 90.8f, 0.0f);
    glVertex3f(95.7778f, 90.6f, 0.0f);
    glVertex3f(95.7778f, 90.4f, 0.0f);
    glVertex3f(95.7778f, 90.2f, 0.0f);
    glVertex3f(95.8889f, 90.2f, 0.0f);
    glVertex3f(96.0f, 90.2f, 0.0f);
    glVertex3f(96.1111f, 90.2f, 0.0f);
    glVertex3f(96.2222f, 90.2f, 0.0f);
    glVertex3f(96.2222f, 90.0f, 0.0f);
    glVertex3f(96.3333f, 89.8f, 0.0f);
    glVertex3f(96.4444f, 89.6f, 0.0f);
    glVertex3f(96.4444f, 89.4f, 0.0f);
    glVertex3f(96.4444f, 89.0f, 0.0f);
    glVertex3f(96.4444f, 88.8f, 0.0f);
    glVertex3f(96.4444f, 88.6f, 0.0f);
    glVertex3f(96.4444f, 88.2f, 0.0f);
    glVertex3f(96.4444f, 87.8f, 0.0f);
    glVertex3f(96.4444f, 87.6f, 0.0f);
    glVertex3f(96.4444f, 87.4f, 0.0f);
    glVertex3f(96.4444f, 87.2f, 0.0f);
    glVertex3f(96.4444f, 86.8f, 0.0f);
    glVertex3f(96.4444f, 86.6f, 0.0f);
    glVertex3f(96.4444f, 86.4f, 0.0f);
    glVertex3f(96.4444f, 86.2f, 0.0f);
    glVertex3f(96.3333f, 86.0f, 0.0f);
    glVertex3f(96.2222f, 86.0f, 0.0f);
    glVertex3f(96.1111f, 85.8f, 0.0f);
    glVertex3f(96.1111f, 85.6f, 0.0f);
    glVertex3f(96.0f, 85.6f, 0.0f);
    glVertex3f(95.8889f, 85.4f, 0.0f);
    glVertex3f(95.7778f, 85.4f, 0.0f);
    glVertex3f(95.5556f, 85.0f, 0.0f);
    glVertex3f(95.3333f, 84.8f, 0.0f);
    glVertex3f(95.2222f, 84.8f, 0.0f);
    glVertex3f(94.8889f, 84.6f, 0.0f);
    glVertex3f(94.7778f, 84.4f, 0.0f);
    glVertex3f(94.5556f, 84.2f, 0.0f);
    glVertex3f(94.3333f, 84.0f, 0.0f);
    glVertex3f(94.2222f, 84.0f, 0.0f);
    glVertex3f(94.1111f, 83.8f, 0.0f);
    glVertex3f(94.0f, 83.8f, 0.0f);
    glVertex3f(93.8889f, 83.8f, 0.0f);
    glVertex3f(93.7778f, 83.8f, 0.0f);
    glVertex3f(93.6667f, 83.8f, 0.0f);
    glVertex3f(93.5556f, 83.8f, 0.0f);
    glVertex3f(93.4444f, 83.8f, 0.0f);
    glVertex3f(93.2222f, 83.8f, 0.0f);
    glVertex3f(93.1111f, 83.8f, 0.0f);
    glVertex3f(92.8889f, 83.8f, 0.0f);
    glVertex3f(92.6667f, 84.0f, 0.0f);
    glVertex3f(92.3333f, 84.4f, 0.0f);
    glVertex3f(92.1111f, 84.6f, 0.0f);
    glVertex3f(91.8889f, 85.0f, 0.0f);
    glVertex3f(91.6667f, 85.2f, 0.0f);
    glVertex3f(91.4444f, 85.4f, 0.0f);
    glVertex3f(91.3333f, 85.6f, 0.0f);
    glVertex3f(91.2222f, 86.0f, 0.0f);
    glVertex3f(91.1111f, 86.2f, 0.0f);
    glVertex3f(91.0f, 86.4f, 0.0f);
    glVertex3f(91.0f, 86.6f, 0.0f);
    glVertex3f(90.8889f, 86.6f, 0.0f);
    glVertex3f(90.7778f, 86.6f, 0.0f);
    glVertex3f(90.6667f, 86.6f, 0.0f);
    glVertex3f(90.5556f, 86.4f, 0.0f);
    glVertex3f(90.5556f, 86.2f, 0.0f);
    glVertex3f(90.3333f, 86.0f, 0.0f);
    glVertex3f(90.2222f, 85.8f, 0.0f);
    glVertex3f(90.1111f, 85.6f, 0.0f);
    glVertex3f(90.1111f, 85.4f, 0.0f);
    glVertex3f(90.0f, 85.2f, 0.0f);
    glVertex3f(89.8889f, 85.0f, 0.0f);
    glVertex3f(89.7778f, 84.8f, 0.0f);
    glVertex3f(89.6667f, 84.6f, 0.0f);
    glVertex3f(89.6667f, 84.4f, 0.0f);
    glVertex3f(89.5556f, 84.2f, 0.0f);
    glVertex3f(89.4444f, 84.2f, 0.0f);
    glVertex3f(89.4444f, 84.0f, 0.0f);
    glVertex3f(89.3333f, 84.0f, 0.0f);
    glVertex3f(89.2222f, 84.0f, 0.0f);
    glVertex3f(89.1111f, 84.0f, 0.0f);
    glVertex3f(89.1111f, 83.8f, 0.0f);
    glVertex3f(89.0f, 83.8f, 0.0f);
    glVertex3f(88.8889f, 83.8f, 0.0f);
    glVertex3f(88.7778f, 83.8f, 0.0f);
    glVertex3f(88.6667f, 83.8f, 0.0f);
    glVertex3f(88.5556f, 83.8f, 0.0f);
    glVertex3f(88.4444f, 83.8f, 0.0f);
    glVertex3f(88.4444f, 83.6f, 0.0f);
    glVertex3f(88.4444f, 83.4f, 0.0f);
    glVertex3f(88.3333f, 83.4f, 0.0f);
    glVertex3f(88.3333f, 83.2f, 0.0f);
    glVertex3f(88.2222f, 83.0f, 0.0f);
    glVertex3f(88.1111f, 83.0f, 0.0f);
    glVertex3f(88.1111f, 82.8f, 0.0f);
    glVertex3f(88.1111f, 82.6f, 0.0f);
    glVertex3f(88.0f, 82.6f, 0.0f);
    glVertex3f(88.0f, 82.4f, 0.0f);
    glVertex3f(87.8889f, 82.4f, 0.0f);
    glVertex3f(87.7778f, 82.4f, 0.0f);
    glVertex3f(87.6667f, 82.4f, 0.0f);
    glVertex3f(87.5556f, 82.4f, 0.0f);
    glVertex3f(87.4444f, 82.4f, 0.0f);
    glVertex3f(87.4444f, 82.6f, 0.0f);
    glVertex3f(87.3333f, 82.6f, 0.0f);
    glVertex3f(87.2222f, 82.6f, 0.0f);
    glVertex3f(87.1111f, 82.6f, 0.0f);
    glVertex3f(87.0f, 82.6f, 0.0f);
    glVertex3f(86.8889f, 82.4f, 0.0f);
    glVertex3f(86.7778f, 82.4f, 0.0f);
    glVertex3f(86.5556f, 82.2f, 0.0f);
    glVertex3f(86.4444f, 82.2f, 0.0f);
    glVertex3f(86.3333f, 82.2f, 0.0f);
    glVertex3f(86.1111f, 82.2f, 0.0f);
    glVertex3f(86.0f, 82.0f, 0.0f);
    glVertex3f(85.8889f, 82.0f, 0.0f);
    glVertex3f(85.6667f, 82.0f, 0.0f);
    glVertex3f(85.5556f, 82.0f, 0.0f);
    glVertex3f(85.4444f, 82.0f, 0.0f);
    glVertex3f(85.2222f, 82.0f, 0.0f);
    glVertex3f(84.8889f, 82.0f, 0.0f);
    glVertex3f(84.6667f, 82.0f, 0.0f);
    glVertex3f(84.4444f, 82.2f, 0.0f);
    glVertex3f(84.3333f, 82.2f, 0.0f);
    glVertex3f(84.1111f, 82.4f, 0.0f);
    glVertex3f(83.7778f, 82.6f, 0.0f);
    glVertex3f(83.5556f, 82.6f, 0.0f);
    glVertex3f(83.2222f, 83.0f, 0.0f);
    glVertex3f(82.8889f, 83.4f, 0.0f);
    glVertex3f(82.5556f, 83.6f, 0.0f);
    glVertex3f(82.2222f, 84.2f, 0.0f);
    glVertex3f(82.0f, 84.6f, 0.0f);
    glVertex3f(81.5556f, 85.2f, 0.0f);
    glVertex3f(81.3333f, 85.6f, 0.0f);
    glVertex3f(81.1111f, 86.0f, 0.0f);
    glVertex3f(80.7778f, 86.6f, 0.0f);
    glVertex3f(80.6667f, 87.0f, 0.0f);
    glVertex3f(80.4444f, 87.4f, 0.0f);
    glVertex3f(80.4444f, 87.8f, 0.0f);
    glVertex3f(80.3333f, 88.2f, 0.0f);
    glVertex3f(80.2222f, 88.4f, 0.0f);
    glVertex3f(80.2222f, 88.6f, 0.0f);
    glVertex3f(80.2222f, 88.8f, 0.0f);
    glVertex3f(80.2222f, 89.2f, 0.0f);
    glVertex3f(80.3333f, 89.6f, 0.0f);
    glVertex3f(80.4444f, 89.6f, 0.0f);
    glVertex3f(80.5556f, 89.8f, 0.0f);
    glVertex3f(80.6667f, 89.8f, 0.0f);
    glVertex3f(80.5556f, 89.8f, 0.0f);
    glVertex3f(80.4444f, 89.8f, 0.0f);
    glVertex3f(80.3333f, 89.6f, 0.0f);
    glVertex3f(80.2222f, 89.6f, 0.0f);
    glVertex3f(80.2222f, 89.4f, 0.0f);
    glVertex3f(80.1111f, 89.4f, 0.0f);
    glVertex3f(80.0f, 89.4f, 0.0f);
    glVertex3f(79.8889f, 89.4f, 0.0f);
    glVertex3f(79.7778f, 89.4f, 0.0f);
    glVertex3f(79.6667f, 89.4f, 0.0f);
    glVertex3f(79.5556f, 89.4f, 0.0f);
    glVertex3f(79.4444f, 89.4f, 0.0f);
    glVertex3f(79.3333f, 89.6f, 0.0f);
    glVertex3f(79.3333f, 89.8f, 0.0f);
    glVertex3f(79.2222f, 89.8f, 0.0f);
    glVertex3f(79.1111f, 90.2f, 0.0f);
    glVertex3f(79.1111f, 90.4f, 0.0f);
    glVertex3f(79.1111f, 90.6f, 0.0f);
    glVertex3f(79.0f, 91.0f, 0.0f);
    glVertex3f(78.8889f, 91.2f, 0.0f);
    glVertex3f(78.8889f, 91.4f, 0.0f);
    glVertex3f(78.8889f, 91.6f, 0.0f);
    glVertex3f(78.8889f, 91.8f, 0.0f);
    glVertex3f(78.8889f, 92.0f, 0.0f);
    glVertex3f(78.8889f, 92.2f, 0.0f);
    glVertex3f(78.8889f, 92.4f, 0.0f);
    glVertex3f(78.8889f, 92.6f, 0.0f);
    glVertex3f(78.8889f, 92.8f, 0.0f);
    glVertex3f(78.8889f, 93.0f, 0.0f);
    glVertex3f(78.8889f, 93.2f, 0.0f);
    glVertex3f(78.8889f, 93.4f, 0.0f);
    glVertex3f(78.8889f, 93.6f, 0.0f);
    glVertex3f(79.0f, 93.8f, 0.0f);
    glVertex3f(79.1111f, 93.8f, 0.0f);
    glVertex3f(79.2222f, 94.0f, 0.0f);
    glVertex3f(79.3333f, 94.4f, 0.0f);
    glVertex3f(79.5556f, 94.4f, 0.0f);
    glVertex3f(79.5556f, 94.6f, 0.0f);
    glVertex3f(79.6667f, 94.6f, 0.0f);
    glVertex3f(79.7778f, 94.6f, 0.0f);
    glVertex3f(79.7778f, 94.8f, 0.0f);
    glVertex3f(79.8889f, 94.8f, 0.0f);
    glVertex3f(80.0f, 94.8f, 0.0f);
    glVertex3f(80.1111f, 94.8f, 0.0f);
    glVertex3f(80.2222f, 94.8f, 0.0f);
    glVertex3f(80.2222f, 94.6f, 0.0f);
    glVertex3f(80.3333f, 94.6f, 0.0f);
    glVertex3f(80.4444f, 94.6f, 0.0f);
    glVertex3f(80.4444f, 94.4f, 0.0f);
    glVertex3f(80.5556f, 94.4f, 0.0f);
    glVertex3f(80.5556f, 94.2f, 0.0f);


    glEnd();


    glPopMatrix();


    glutPostRedisplay();
//****************************************************end megh*************************************

//****************************************************************************************************************
//piller
    glBegin(GL_QUADS);
    glColor3f(0.9f,0.5f,0.0f);
    glVertex2f(45.0f,24.5f);
    glVertex2f(50.0f,24.9f);
    glVertex2f(50.0f,50.0f);
    glVertex2f(45.0f,50.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f,0.8f,0.8f);
    glVertex2f(45.0f,43.0f);
    glVertex2f(50.0f,43.0f);
    glVertex2f(50.0f,45.0f);
    glVertex2f(45.0f,45.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);//red
    glVertex2f(45.0f,44.0f);
    glVertex2f(50.0f,44.0f);
    glEnd();

//first quad
    glBegin(GL_QUADS);
    glColor3f(0.9f,0.2f,0.3f);
    glVertex2f(42.0f,50.0f);
    glVertex2f(54.0f,50.0f);
    glVertex2f(55.0f,52.0f);
    glVertex2f(40.0f,52.0f);
    glEnd();

    //second quad
    glBegin(GL_QUADS);
    glColor3f(0.9f,0.6f,0.4f);
    glVertex2f(40.0f,52.0f);
    glVertex2f(55.0f,52.0f);
    glVertex2f(56.0f,54.0f);
    glVertex2f(39.0f,54.0f);
    glEnd();

//line
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(43.0f,52.0f);
    glVertex2f(43.0f,54.0f);
    glVertex2f(47.0f,52.0f);
    glVertex2f(47.0f,54.0f);
    glVertex2f(51.0f,52.0f);
    glVertex2f(51.0f,54.0f);
    glVertex2f(55.0f,52.0f);
    glEnd();

    //half circle
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);//orange
    glVertex2f(39.0f,54.0f);
    glVertex2f(40.0f,55.0f);
    glVertex2f(41.0f,55.2f);
    glVertex2f(42.0f,55.0f);
    glVertex2f(43.0f,54.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);//orange
    glVertex2f(43.1f,54.0f);
    glVertex2f(44.0f,55.0f);
    glVertex2f(45.0f,55.2f);
    glVertex2f(46.0f,55.0f);
    glVertex2f(47.0f,54.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);//orange
    glVertex2f(47.1f,54.0f);
    glVertex2f(48.0f,55.0f);
    glVertex2f(49.0f,55.2f);
    glVertex2f(50.0f,55.0f);
    glVertex2f(51.0f,54.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);//orange
    glVertex2f(51.1f,54.0f);
    glVertex2f(52.0f,55.0f);
    glVertex2f(53.0f,55.2f);
    glVertex2f(54.0f,55.0f);
    glVertex2f(55.0f,54.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);//orange
    glVertex2f(55.0f,54.0f);
    glVertex2f(55.5f,55.0f);
    glVertex2f(55.9f,55.2f);
    glVertex2f(56.0f,54.0f);
    glEnd();
//first rope
    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(35.0f,42.0f);
    glVertex2f(42.0f,50.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(36.0f,40.0f);
    glVertex2f(42.0f,50.0f);
    glEnd();

//with small triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(0.9f, 0.5f, 0.9f);//blackash
    glVertex2f(35.0f,42.0f);
    glVertex2f(35.5f,39.0f);
    glVertex2f(36.0f,40.0f);
    glEnd();

//second rope
    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(40.0f,40.0f);
    glVertex2f(43.8f,50.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(43.0f,40.0f);
    glVertex2f(43.8f,50.0f);
    glEnd();

//with small Quads
    glBegin(GL_QUADS);
    glColor3ub(0.9f, 0.5f, 0.9f);//blackash
    glVertex2f(40.0f,39.0f);
    glVertex2f(43.0f,39.0f);
    glVertex2f(43.0f,40.0f);
    glVertex2f(40.0f,40.0f);
    glEnd();

//third rope
    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(51.0f,42.0f);
    glVertex2f(51.9f,50.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(53.2f,42.0f);
    glVertex2f(51.9f,50.0f);
    glEnd();

//with small quads
    glBegin(GL_QUADS);
    glColor3ub(0.9f, 0.5f, 0.9f);//blackash
    glVertex2f(51.0f,40.0f);
    glVertex2f(53.5f,40.0f);
    glVertex2f(53.2f,42.0f);
    glVertex2f(51.0f,42.0f);
    glEnd();

//Fourth rope
    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(57.0f,38.0f);
    glVertex2f(53.0f,50.0f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(130, 0, 0); //chocolate
    glVertex2f(58.8f,37.0f);
    glVertex2f(53.0f,50.0f);
    glEnd();

//with small quads
    glBegin(GL_QUADS);
    glColor3ub(0.5f, 0.2f, 0.5f);//blackash
    glVertex2f(57.0f,37.0f);
    glVertex2f(59.0f,36.0f);
    glVertex2f(58.8f,37.0f);
    glVertex2f(57.0f,38.0f);
    glEnd();
//**********************************************End of ghurni (shimon)**********************************

//*************************************************KITE START(shorna)*****************************************
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(0,bxk,0);

    glBegin (GL_POLYGON);

//kite1

    glColor3f(1.0f, 0.0f, 0.0f);//read
    glVertex3f(75.0,61.0,0.0);
    glVertex3f(78.0,64.0,0.0);
    glVertex3f(75.0,67.0,0.0);
    glVertex3f(72.0,64.0,0.0);

    glEnd();

    glBegin (GL_POLYGON);
//kite tail
    glColor3ub(0, 129, 201); //blue
    glVertex3f(75.0,61.0,0.0);
    glVertex3f(74.0,58.0,0.0);
    glVertex3f(75.0,57.0,0.0);
    glVertex3f(76.0,58.0,0.0);
    glEnd();

    glBegin (GL_LINES);

//kite line
    glColor3f(0.0,0.0,0.0);//black
    glVertex3f(75.0,64.0,0.0);
    glVertex3f(75.0,53.0,0.0);

    glEnd();

    glPopMatrix();

    glEnd();
    glBegin (GL_POLYGON);

//kite2

    glColor3ub(240, 255, 66);//lemon
    glVertex3f(63.0,60.0,0.0);
    glVertex3f(61.0,56.0,0.0);
    glVertex3f(64.0,54.0,0.0);
    glVertex3f(66.0,57.0,0.0);
    glEnd();

    glBegin (GL_POLYGON);
//kite tail2
    glColor3ub(130, 205, 71);//green
    glVertex3f(64.0,54.0,0.0);
    glVertex3f(63.0,52.0,0.0);
    glVertex3f(64.0,50.0,0.0);
    glVertex3f(65.0,52.0,0.0);
    glEnd();

    glBegin (GL_POLYGON);

//kite3

    glColor3ub(255, 95, 158);//pink
    glVertex3f(61.0,53.0,0.0);
    glVertex3f(58.0,49.0,0.0);
    glVertex3f(61.0,46.0,0.0);
    glVertex3f(64.0,49.0,0.0);

    glEnd();

    glBegin (GL_POLYGON);


//kite tai3
    glColor3ub(154, 32, 140);//dark pink
    glVertex3f(61.0,46.0,0.0);
    glVertex3f(60.0,45.0,0.0);
    glVertex3f(61.0,44.0,0.0);
    glVertex3f(62.0,45.0,0.0);

    glEnd();

    glBegin (GL_POLYGON);


//kite4
    glColor3ub(176, 218, 255);//sky
    glVertex3f(69.0,57.0,0.0);
    glVertex3f(66.0,54.0,0.0);
    glVertex3f(67.0,51.0,0.0);
    glVertex3f(70.0,53.0,0.0);

    glEnd();

    glBegin (GL_POLYGON);

//kite tail4


    glColor3ub(25, 167, 206);// dark blue
    glVertex3f(67.0,51.0,0.0);
    glVertex3f(66.0,48.0,0.0);
    glVertex3f(67.0,47.0,0.0);
    glVertex3f(68.0,48.0,0.0);

    glEnd();

    glBegin (GL_POLYGON);


//kite5
    glColor3ub(212, 173, 252); //lite beguni
    glVertex3f(72.0,53.0,0.0);
    glVertex3f(70.0,50.0,0.0);
    glVertex3f(72.0,47.0,0.0);
    glVertex3f(74.0,50.0,0.0);

    glEnd();

    glBegin (GL_POLYGON);

//kite tail5

    glColor3ub(92, 70, 156);//drak beguni

    glVertex3f(72.0,47.0,0.0);
    glVertex3f(71.0,45.0,0.0);
    glVertex3f(72.0,44.0,0.0);
    glVertex3f(73.0,45.0,0.0);

    glEnd();

    glBegin (GL_LINES);

//kite read
    glColor3f(0.0,0.0,0.0);//black
    glVertex3f(75.0,64.0,0.0);
    glVertex3f(65.0,44.0,0.0);

//kite beguni

    glVertex3f(63.0,57.0,0.0);
    glVertex3f(65.0,44.0,0.0);
//kite pink

    glVertex3f(61.0,51.0,0.0);
    glVertex3f(65.0,44.0,0.0);
//kite blue

    glVertex3f(68.0,55.0,0.0);
    glVertex3f(65.0,44.0,0.0);
    //kite green

    glVertex3f(72.0,51.0,0.0);
    glVertex3f(65.0,44.0,0.0);
    glEnd();

//********************************************KITE END(shorna)***************************************************

//*************************************************Parasuit(payel)*************************************************
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    glTranslatef(bxp,0,0);

//Pura majkhane gol
    glBegin(GL_POLYGON);
    glColor3ub(255, 95, 158);//pink
    glVertex2i(70, 80);
    glVertex2i(75, 80);
    glColor3ub(212, 173, 252); //lite beguni
    glVertex2i(78, 85);
    glColor3ub(255, 95, 158);//pink
    glVertex2i(78, 94);
    glColor3ub(212, 173, 252); //lite beguni
    glVertex2i(75, 97);
    glColor3ub(255, 95, 158);//pink
    glVertex2i(70, 97);
    glColor3ub(212, 173, 252); //lite beguni
    glVertex2i(67, 94);
    glColor3ub(255, 95, 158);//pink
    glVertex2i(67, 85);
    glEnd();

//Pura nicher strip
    glBegin(GL_POLYGON);
    glColor3ub(0, 129, 201);
    glVertex2i(70, 80);
    glVertex2i(75, 80);
    glVertex2i(76, 82);
    glColor3ub(212, 173, 252); //lite beguni
    glVertex2i(69, 82);
    glEnd();

//Pura nicher upor strip
    glBegin(GL_POLYGON);
    glColor3ub(0, 129, 201);
    glVertex2i(68, 76);
    glColor3ub(212, 173, 252); //lite beguni
    glVertex2i(77, 76);
    glVertex2i(77, 77);
    glVertex2i(68, 77);
    glEnd();

// nicher box
    glBegin(GL_POLYGON);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(69, 72);
    glColor3ub(139, 69, 19);//brown
    glVertex2i(76, 72);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(76, 76);
    glColor3ub(139, 69, 19);//brown
    glVertex2i(69, 76);
    glEnd();

    glBegin (GL_LINES);

//line right 1
    glColor3f(0.0,0.0,0.0);//black
    glVertex2f(76, 77);
    glVertex2f(76, 82);
//line left 1
    glVertex2f(69, 77);
    glVertex2f(69, 82);

//line left 2
    glVertex2i(70, 80);
    glVertex2f(70, 77);

//line right 2
    glVertex2i(75, 80);
    glVertex2f(75, 77);


    glEnd();
    glPopMatrix();







//***************************************************End of parasuit(payel)****************************************


//******************************************Start of Palace(payel)******************************************
//Center outer box
    glBegin(GL_QUADS);
    glColor4f(0.7, 0.7, 0.7, 1.0);//grey
    glVertex2i(80, 26);
    glVertex2i(95, 26);
    glVertex2i(95, 40);
    glVertex2i(80, 40);
    glEnd();

//center Door
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(83, 26);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(92, 26);
    glVertex2i(92, 33);
    glVertex2i(91, 35);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(90, 36);
    glVertex2i(88, 37);
    glVertex2i(86, 37);
    glVertex2i(85, 36);
    glVertex2i(84, 35);
    glVertex2i(83, 34);
    glEnd();

//Inner left box
    glBegin(GL_QUADS);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(81, 37);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(83, 37);
    glVertex2i(83, 39);
    glVertex2i(81, 39);
    glEnd();

//Inner right box
    glBegin(GL_QUADS);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(92, 37);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(94, 37);
    glVertex2i(94, 39);
    glVertex2i(92, 39);
    glEnd();

//upper left piller
    glBegin(GL_QUADS);
    glColor4f(0.7, 0.7, 0.7, 1.0);//grey
    glVertex2i(82, 40);
    glVertex2i(88, 40);
    glVertex2i(88, 57);
    glVertex2i(82, 57);
    glEnd();

//upper left window
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(83, 48);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(87, 48);
    glVertex2i(87, 53);
    glVertex2i(87.5, 54);
    glVertex2i(86.5, 54.5);
    glVertex2i(83.5, 54);
    glVertex2i(83, 53);
    glEnd();

//for upper left piller triangle..
    glBegin(GL_TRIANGLES);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(80, 57);
    glVertex2i(90, 57);
    glVertex2i(85, 65);
    glEnd();

//upper right piller
    glBegin(GL_QUADS);
    glColor4f(0.7, 0.7, 0.7, 1.0);//grey
    glVertex2i(89, 40);
    glVertex2i(94, 40);
    glVertex2i(94, 51);
    glVertex2i(89, 51);
    glEnd();

//upper right window
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(90, 45);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(93, 45);
    glVertex2i(93, 48);
    glVertex2i(93.5, 49);
    glVertex2i(92.5, 49.5);
    glVertex2i(91.5, 49);
    glVertex2i(90, 48);
    glEnd();

//for upper right piller triangle..
    glBegin(GL_TRIANGLES);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(88, 51);
    glVertex2i(95, 51);
    glVertex2i(92, 58);
    glEnd();

//Center er upor 4 ta box from left to right
    glBegin(GL_QUADS);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(81, 40);
    glVertex2i(83, 40);
    glVertex2i(83, 42);
    glVertex2i(81, 42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(85, 40);
    glVertex2i(87, 40);
    glVertex2i(87, 42);
    glVertex2i(85, 42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(89, 40);
    glVertex2i(91, 40);
    glVertex2i(91, 42);
    glVertex2i(89, 42);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(92, 40);
    glVertex2i(94, 40);
    glVertex2i(94, 42);
    glVertex2i(92, 42);
    glEnd();

//left piller
    glBegin(GL_QUADS);
    glColor4f(0.7, 0.7, 0.7, 1.0);//grey
    glVertex2i(75, 26);
    glVertex2i(80, 26);
    glVertex2i(80, 45);
    glVertex2i(75, 45);
    glEnd();

//upper window
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(76, 40);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(79, 40);
    glVertex2i(79, 43);
    glVertex2i(78.5, 44);
    glVertex2i(77.5, 44.5);
    glVertex2i(76.5, 44);
    glVertex2i(76, 43);
    glEnd();

//lower window
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(76, 30);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(79, 30);
    glVertex2i(79, 33);
    glVertex2i(78.5, 34);
    glVertex2i(77.5, 34.5);
    glVertex2i(76.5, 34);
    glVertex2i(76, 33);
    glEnd();

//for left piller triangle..
    glBegin(GL_TRIANGLES);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(74, 45);
    glVertex2i(81, 45);
    glVertex2i(77, 51);
    glEnd();

//right piller
    glBegin(GL_QUADS);
    glColor4f(0.7, 0.7, 0.7, 1.0);//grey
    glVertex2i(95, 26);
    glVertex2i(100, 26);
    glVertex2i(100, 45);
    glVertex2i(95, 45);
    glEnd();

//upper window
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(96, 40);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(99, 40);
    glVertex2i(99, 43);
    glVertex2i(98.5, 44);
    glVertex2i(97.5, 44.5);
    glVertex2i(96.5, 44);
    glVertex2i(96, 43);
    glEnd();

//lower window
    glBegin(GL_POLYGON);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(96, 30);
    glColor3f(0.192, 0.118, 0.102);
    glVertex2i(99, 30);
    glVertex2i(99, 33);
    glVertex2i(98.5, 34);
    glVertex2i(97.5, 34.5);
    glVertex2i(96.5, 34);
    glVertex2i(96, 33);
    glEnd();

//for right piller triangle..
    glBegin(GL_TRIANGLES);
    glColor3ub(183, 4, 4);//Red
    glVertex2i(94, 45);
    glVertex2i(100, 45);
    glVertex2i(97, 51);
    glEnd();

//*******************************************************End of Palace(payel)***********************************************




//********************************************Start of Road(payel)*************************************
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.4, 0.1);//Dark Green
    glVertex2i(0, 15);
    glVertex2i(14, 16);
    glVertex2i(20, 15);
    glVertex2i(30, 15);
    glVertex2i(36, 16);
    glVertex2i(40, 15);
    glVertex2i(45, 15);
    glVertex2i(50, 16);
    glVertex2i(56, 17);
    glVertex2i(60, 17);
    glVertex2i(68, 15);
    glVertex2i(70, 15);
    glVertex2i(72, 15);
    glVertex2i(79, 17);
    glVertex2i(80, 17);
    glVertex2i(88, 15);
    glVertex2i(93, 15);
    glVertex2i(98, 16);
    glVertex2i(100, 16);
    glVertex2i(100, 26);
    glVertex2i(55, 26);
    glVertex2i(50, 26);
    glVertex2i(45, 26);
    glVertex2i(0, 26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.322, 0.247, 0.188);//dark off white
    glVertex2i(0, 14);
    glVertex2i(14, 15);
    glVertex2i(20, 14);
    glVertex2i(36, 15);
    glVertex2i(40, 14);
    glVertex2i(50, 15);
    glVertex2i(56, 16);
    glVertex2i(68, 14);
    glVertex2i(79, 16);
    glVertex2i(88, 14);
    glVertex2i(100, 15);
    glVertex2i(100, 16);
    glVertex2i(88, 15);
    glVertex2i(79, 17);
    glVertex2i(68, 15);
    glVertex2i(56, 17);
    glVertex2i(50, 16);
    glVertex2i(40, 15);
    glVertex2i(36, 16);
    glVertex2i(20, 15);
    glVertex2i(14, 16);
    glVertex2i(0, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6, 0.2);//lite green
    glVertex2i(0, 19);
    glVertex2i(10, 19);
    glVertex2i(15, 20);
    glVertex2i(20, 21);
    glVertex2i(23, 21);
    glVertex2i(28, 23);
    glVertex2i(24, 25);
    glVertex2i(20, 26);
    glVertex2i(0, 26);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6, 0.2);//lite green
    glVertex2i(66, 23);
    glVertex2i(70, 22);
    glVertex2i(75, 21);
    glVertex2i(80, 20);
    glVertex2i(85, 20);
    glVertex2i(90, 21);
    glVertex2i(100, 21);
    glVertex2i(100, 26);
    glVertex2i(75, 26);
    glVertex2i(70, 25);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.6, 0.2);//lite green
    glVertex2i(40, 16);
    glVertex2i(45, 18);
    glVertex2i(55, 18);
    glVertex2i(61, 18);
    glVertex2i(63, 16);
    glEnd();
//**********************************************End of road(payel)***********************************

    glLoadIdentity();
    glTranslatef(-40,0.0,0.0);
    drawMan();

    glLoadIdentity();
    glTranslatef(manTX,manTY,0.0);
    drawMan();
    drawBoat();
    birds(350.0,450.0);
    glutSwapBuffers();
}
void drawBoat()
{
//**********************************************River er boat(sourav)**********************************
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);//Black

    glTranslatef(boatTX,0,0);

    //Boat

    glBegin(GL_QUADS); //left side kornar
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(25.0f,10.0f,0.0f);
    glVertex3f(27.0f,06.0f,0.0f);
    glVertex3f(30.0f,03.0f,0.0f);
    glVertex3f(30.0f,06.0f,0.0f);



    glVertex3f(50.0f,03.0f,0.0f); //right side kornar
    glVertex3f(53.0f,06.0f,0.0f);
    glVertex3f(55.0f,10.0f,0.0f);
    glVertex3f(50.0f,06.0f,0.0f);



    glEnd();

    //boat main body

    glBegin(GL_POLYGON);
    glLoadIdentity();
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(30.0f,03.0f,0.0f);
    glVertex3f(40.0f,02.0f,0.0f);
    glVertex3f(50.0f,03.0f,0.0f);
    glVertex3f(50.0f,06.0f,0.0f);
    glVertex3f(30.0f,06.0f,0.0f);


    glEnd();


    glBegin(GL_POLYGON); //brown color er polygon
    glColor3f(0.60f,0.30f,0.0f);
    glVertex3f(30.0f,06.0f,0.0f);
    glVertex3f(50.0f,06.0f,0.0f);
    glVertex3f(49.0f,08.0f,0.0f);
    glVertex3f(47.0f,10.0f,0.0f);
    glVertex3f(45.0f,11.0f,0.0f);
    glVertex3f(40.0f,12.0f,0.0f);
    glVertex3f(35.0f,11.0f,0.0f);
    glVertex3f(33.0f,10.0f,0.0f);
    glVertex3f(31.0f,08.0f,0.0f);


    glEnd();

    // brown color er polygon er majhkhaner black line

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f); //black color
    glVertex3f(31.0f,08.0f,0.0f);
    glVertex3f(49.0f,08.0f,0.0f);

    glVertex3f(33.0f,10.0f,0.0f);
    glVertex3f(47.0f,10.0f,0.0f);


    glVertex3f(35.0f,06.0f,0.0f);
    glVertex3f(35.0f,11.0f,0.0f);

    glVertex3f(40.0f,06.0f,0.0f);
    glVertex3f(40.0f,12.0f,0.0f);

    glVertex3f(45.0f,06.0f,0.0f);
    glVertex3f(45.0f,11.0f,0.0f);

    glEnd();

    //manush




    //boat er pal

    glBegin(GL_POLYGON); //Pal
    glColor3f(0.6f,1.0f,1.0f); //sky blue color
    glVertex3f(45.0f,19.0f,0.0f);
    glVertex3f(50.0f,17.0f,0.0f);
    glVertex3f(57.0f,17.0f,0.0f);
    glVertex3f(56.0f,20.0f,0.0f);
    glVertex3f(50.0f,22.0f,0.0f);



    glEnd();

    glBegin(GL_QUADS); //pal
    glColor3f(0.6f,1.0f,1.0f); //sky blue color
    glVertex3f(51.0f,13.0f,0.0f);
    glVertex3f(54.0f,11.0f,0.0f);
    glVertex3f(57.0f,17.0f,0.0f);
    glVertex3f(50.0f,17.0f,0.0f);

    glEnd();

    glBegin(GL_TRIANGLES); //pal
    glColor3f(0.6f,1.0f,1.0f); //sky blue color
    glVertex3f(50.0f,06.0f,0.0f);
    glVertex3f(54.0f,11.0f,0.0f);
    glVertex3f(51.0f,13.0f,0.0f);



    glEnd();

    //pal er roshi

    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(35.0f,11.0f,0.0f);
    glVertex3f(45.0f,19.0f,0.0f);

    glVertex3f(35.0f,11.0f,0.0f);
    glVertex3f(54.0f,20.5f,0.0f);

    glVertex3f(35.0f,11.0f,0.0f);
    glVertex3f(56.0f,20.0f,0.0f);

    glEnd();


    // lomba line

    glBegin(GL_QUADS);
    glColor3f(0.60f,0.30f,0.0f);
    glVertex3f(49.0f,07.0f,0.0f);
    glVertex3f(50.0f,06.0f,0.0f);
    glVertex3f(50.0f,24.0f,0.0f);
    glVertex3f(49.0f,24.0f,0.0f);

    glEnd();

    glPopMatrix();
    bx+=.003;
    if(bx>100)
        bx=-40;

    glutPostRedisplay();


    glFlush();


//************************************************End of river er boat(sourav)************************
}

void drawMan()
{

// human akhi

    glColor3f(0, 0, 0);
    drawCircle(1.5);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2f(65.93, 32.81);
    glVertex2f(66.93, 32.81);
    glEnd();

    // Draw the body quadrilateral
    glBegin(GL_QUADS);
    glColor3f(0, 0.5, 0);
    glVertex2f(7 + 57.5, 8 + 23);
    glVertex2f(11 + 58, 8 + 23);
    glVertex2f(11 + 58, 5 + 23);
    glVertex2f(7 + 57.5, 5 + 23);
    glEnd();

    // Draw the triangle inside the body
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glVertex2f(7 + 57.5, 8 + 23);
    glVertex2f(11 + 58, 8 + 23);
    glVertex2f(9 + 58, 7 + 23);
    glEnd();

    // Draw the left hand
    glBegin(GL_QUADS);
    glColor3f(0, 0.5, 0);
    glVertex2f(6 + 57.5, 7 + 23);
    glVertex2f(7 + 57.5, 7 + 23);
    glVertex2f(7 + 57.5, 6 + 23);
    glVertex2f(6 + 57.5, 6 + 23);
    glEnd();

    // Draw the right hand
    glBegin(GL_QUADS);
    glColor3f(0, 0.5, 0);
    glVertex2f(11 + 58, 7 + 23);
    glVertex2f(12 + 58, 7 + 23);
    glVertex2f(12 + 58, 6 + 23);
    glVertex2f(11 + 58, 6 + 23);
    glEnd();

    // Draw the left leg
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(8 + 57.5, 4 + 24);
    glVertex2f(9 + 57.5, 4 + 24);
    glVertex2f(9 + 57.5, 1 + 23);
    glVertex2f(8 + 57.5, 1 + 23);
    glEnd();

    // Draw the right leg
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2f(10 + 57, 4 + 24);
    glVertex2f(11 + 57, 4 + 24);
    glVertex2f(11 + 57, 1 + 23);
    glVertex2f(10 + 57, 1 + 23);
    glEnd();

}


void birds(float p, float q)
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(25,40,60);
    glVertex2f(p,q);//left feather
    glVertex2f(p+15,q+5);
    glVertex2f(p+30,q+5);
    glVertex2f(p+50,q-2);
    glVertex2f(p+65,q-12);
    glVertex2f(p+80,q-25);
    glVertex2f(p+70,q-20);
    glVertex2f(p+45,q-3);
    glVertex2f(p-5,q-10);//left feather
    glVertex2f(p-8,q-25);
    glVertex2f(p-15,q-30);
    glVertex2f(p-15,q-15);
    glVertex2f(p-35,q-5);
    glVertex2f(p-45,q-10);
    glVertex2f(p-60,q-8);
    glVertex2f(p-90,q-5);
    glVertex2f(p-50,q);
    glVertex2f(p-30,q+2);
    glVertex2f(p-15,q-10);//right feather

    glVertex2f(p-5,q+16);
    glVertex2f(p,q+18);
    glVertex2f(p+5,q+16);

    glEnd();

}

void timer(int value)
{

    if(isStopez == false) // it means boat is not reach boat stopase
    {
        boatTX += 0.1;
        if(boatTX > 80)
        {
            boatTX = -57.0f;
            if(isManOnBoat == true) // it means man with boat
                boatPassState = 1; // so boat arrive with man
            else
                boatPassState =0; // boat going alone thats why it state is reset
        }
        if(isManOnBoat == true) // man on boar
        {
            manTX += 0.1; // so man will go with boat
            if(manTX > 60)
            {
                manTX = -77;
            }
        }

    }

    if(boatTX >= 10 && isStopez == false && isManOnBoat == false && boatPassState == 0) // boat in stopase and man is not on boat and boat state is reseted or 1st state
    {
        isStopez = true;
    }

    if(boatTX >=10 && isManOnBoat == true && isStopez == false && boatPassState == 1) // boat is going with man and boat reach boat stopage
    {
        isStopez = true;
    }


    // for sky shimon
    bxm+=.070;
    if(bxm>100)
        bxm=-22;

    // for parasuit payel
    bxp+=.01;
    if(bxp>34)
        bxp=-80;

    // for kite shorna
    bxk+=.04;
    if(bxk>100)
        bxp=-20;

    angle += 1.0;
    if(angle > 360)
    {
        angle -= 360;
    }

//For dolna payel
    if(isLeftDolna == true)
    {
        angleOfDolna += 0.5;
        if(angleOfDolna> 30)
        {
            isLeftDolna = false;
        }
    }
    else if(isLeftDolna == false)
    {
        angleOfDolna -= 0.5;
        if(angleOfDolna <= -30)
        {
            isLeftDolna = true;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(15, timer, 0);
}



void keyboard(unsigned char key, int x, int y)
{
    if (key == 'y')
    {
        isManOnBoat = true;
        isStopez = false;
        boatPassState = 0;
    }
    else if (key == 'n')
    {
        isManOnBoat = false;
        isStopez = false;
    }
    else if(key == 'a')
    {
        manTX -= 0.1;
    }
    else if(key == 'd')
    {
        manTX += 0.1;
    }
    else if(key == 'w')
    {
        manTY += 0.1;
    }
    else if(key == 's')
    {
        manTY -= 0.1;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE |
                         GLUT_RGB);
    glutInitWindowSize (900, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Lab_Project_payel");
    init ();
    glutDisplayFunc(display);
    glutTimerFunc(15, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


#include <windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<math.h>
#define SPEED 1.25
#define SPEED2 2.0
#define SPEED3 1.25

GLfloat red=1,blue=1.0,green=1.0;
GLfloat r=10,b=0,g=0;
int flag,flag1;

int y=0;   //speed of traffic

float i=0.0;    //for movement of car
float m=0.0;    //                clouds
float n=0.0;    //                plane(x)
float o=0.0;    //                plane(y)
int j=1;        //0 for red-light 1 for green-light
int t=0;        //0 for day 1 for night
int s=0;        //plane control-
int z=0;
int a=0;

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
 glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
 gluOrtho2D(0.0,1100.0,0.0,700.0);
}


void box()
{  glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
        glVertex2f(7.4,2);
        glVertex2f(7.4,1.2);
        glVertex2f(9.2,1.2);
        glVertex2f(9.2,2);

glEnd();


    glColor3f(0.9,0.6,0.7);
glBegin(GL_LINE_LOOP);
    glVertex2f(30,20);
    glVertex2f(30,685);
    glVertex2f(1070,685);
    glVertex2f(1070,20);
glEnd();
    glColor3f(0.4,0.0,0.2);
glBegin(GL_LINE_LOOP);
    glVertex2f(25,15);
    glVertex2f(25,690);
    glVertex2f(1075,690);
    glVertex2f(1075,15);
glEnd();

}

void drawString1 (void * font, char *s, float x, float y){
     unsigned int i;
     glRasterPos2f(x, y);

      for (i = 0; i<strlen (s); i++)
glutBitmapCharacter (font, s[i]);
}



void draw_pixel(GLint cx, GLint cy)
{

glBegin(GL_POINTS);
        glVertex2i(cx,cy);
glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
draw_pixel(x+h,y+k);
draw_pixel(-x+h,y+k);
draw_pixel(x+h,-y+k);
draw_pixel(-x+h,-y+k);
draw_pixel(y+h,x+k);
draw_pixel(-y+h,x+k);
draw_pixel(y+h,-x+k);
draw_pixel(-y+h,-x+k);
}


void draw_circle(GLint h, GLint k, GLint r)
{
GLint d=1-r, x=0, y=r;
    while(y>x)
    {
plotpixels(h,k,x,y);
        if(d<0) d+=2*x+3;
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
plotpixels(h,k,x,y);
}

void draw_object()
{
int l;
if(t==0)
{
//sky

glPushMatrix();
glTranslatef(0.0,1.0,0.0);

    if(red!=0&&blue!=0&&green!=0)
{red-=0.05;blue-=0.0005,green-=0.0005;
glColor3f(red,green,blue);
}

glBegin(GL_POLYGON);
        glVertex2f(0,450);
        glVertex2f(0,700);
        glVertex2f(1100,700);
        glVertex2f(1100,450);
glEnd();

glPopMatrix();
//sun
glPushMatrix();
if(b!=1)
{  b+=0.0;
/* b+=0.001;
        glColor3f(1.0,0.9,b);
r+=0.05;*/
        glColor3f(1.0,0.9,0.0);
r+=0.2;

 glTranslatef(0.0,1.0-r,0.0);

 }for(l=0;l<=40;l++)
    {
        draw_circle(530,625,l);

 }

glPopMatrix();
//moon
glPushMatrix();


    if(b!=1)
    {

        b+=0.001;
        glColor3f(1.0,0.9,b);
        r+=0.000000000000000000001;
        glTranslatef(0.0,1.0+r,0.0);
    }
    for(l=0;l<=40;l++)
    {

        draw_circle(530,140,l);
    }
    glPopMatrix();



//plane
if(s==1)
{
    glColor3f(1.0,0.0,0.5);
glBegin(GL_POLYGON);
    glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
    glVertex2f(1015+n,640+o);
    glVertex2f(1030+n,650+o);
    glVertex2f(1050+n,650+o);
    glVertex2f(1010+n,625+o);
glEnd();

    glColor3f(0.0,0.8,0.0);
glBegin(GL_LINE_LOOP);
    glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
    glVertex2f(1015+n,640+o);
    glVertex2f(1030+n,650+o);
    glVertex2f(1050+n,650+o);
    glVertex2f(1010+n,625+o);
glEnd();

}

//cloud1


    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
draw_circle(160+m,625,l);
    }




    for(l=0;l<=35;l++)
    {
        glColor3f(1.0,1.0,1.0);
draw_circle(200+m,625,l);
draw_circle(225+m,625,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
draw_circle(265+m,625,l);
    }

//cloud2


    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
draw_circle(370+m,615,l);
    }




    for(l=0;l<=35;l++)
    {
        glColor3f(1.0,1.0,1.0);
draw_circle(410+m,615,l);
draw_circle(435+m,615,l);
draw_circle(470+m,615,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(1.0,1.0,1.0);
draw_circle(500+m,615,l);
    }

//grass

glColor3f(0.0,0.8,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,480);
glVertex2f(1100,480);
glVertex2f(1100,160);
glEnd();



}
//road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,300);
glVertex2f(0,310);
glVertex2f(1500,310);
glVertex2f(1500,300);
glEnd();

//road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,300);
glVertex2f(1500,300);
glVertex2f(1500,0);
glEnd();
//road divider (yellow)
glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,155);
glVertex2f(0,170);
glVertex2f(1500,170);
glVertex2f(1500,155);
glEnd();
//black color in divider
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,155);
glVertex2f(100,170);
glVertex2f(200,170);
glVertex2f(200,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(300,155);
glVertex2f(300,170);
glVertex2f(400,170);
glVertex2f(400,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(500,155);
glVertex2f(500,170);
glVertex2f(600,170);
glVertex2f(600,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(700,155);
glVertex2f(700,170);
glVertex2f(800,170);
glVertex2f(800,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(900,155);
glVertex2f(900,170);
glVertex2f(1000,170);
glVertex2f(1000,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(1100,155);
glVertex2f(1100,170);
glVertex2f(1200,170);
glVertex2f(1200,155);
glEnd();

//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(20,90);
glVertex2f(20,100);
glVertex2f(150,100);
glVertex2f(150,90);
glEnd();

//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(180,90);
glVertex2f(180,100);
glVertex2f(310,100);
glVertex2f(310,90);
glEnd();
//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(340,90);
glVertex2f(340,100);
glVertex2f(470,100);
glVertex2f(470,90);
glEnd();
//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(500,90);
glVertex2f(500,100);
glVertex2f(660,100);
glVertex2f(660,90);
glEnd();
//line in road
glColor3f(1.2,1.0,0.2);
glBegin(GL_POLYGON);
glVertex2f(690,90);
glVertex2f(690,100);
glVertex2f(850,100);
glVertex2f(850,90);
glEnd();
//line in road
glColor3f(1.2,1.0,0.2);
glBegin(GL_POLYGON);
glVertex2f(880,90);
glVertex2f(880,100);
glVertex2f(1040,100);
glVertex2f(1040,90);
glEnd();
//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(20,240);
glVertex2f(20,250);
glVertex2f(150,250);
glVertex2f(150,240);
glEnd();

//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(200,240);
glVertex2f(200,250);
glVertex2f(340,250);
glVertex2f(340,240);
glEnd();

//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(380,240);
glVertex2f(380,250);
glVertex2f(520,250);
glVertex2f(520,240);
glEnd();

//line in road
glColor3f(1.2,1.0,0.2);

glBegin(GL_POLYGON);
glVertex2f(560,240);
glVertex2f(560,250);
glVertex2f(700,250);
glVertex2f(700,240);
glEnd();

glColor3f(1.2,1.0,0.2);
glBegin(GL_POLYGON);
glVertex2f(740,240);
glVertex2f(740,250);
glVertex2f(880,250);
glVertex2f(880,240);
glEnd();

glColor3f(1.2,1.0,0.2);
glBegin(GL_POLYGON);
glVertex2f(920,240);
glVertex2f(920,250);
glVertex2f(1060,250);
glVertex2f(1060,240);
glEnd();

//bottom border
glColor3f(1.0,1.0,1.2);

glBegin(GL_POLYGON);
glVertex2f(0,5);
glVertex2f(0,10);
glVertex2f(1200,5);
glVertex2f(1200,10);
glEnd();
//pot

glColor3f(1.0,0.4,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(865,310);
    glVertex2f(850,355);
    glVertex2f(915,355);
    glVertex2f(900,310);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(882,350);
    glVertex2f(882,400);
    glEnd();

 for(l=0;l<=9;l++)
    {
        glColor3f(1.0,1.9,1.0);
draw_circle(882,420,l);
    }

    for(l=0;l<=9;l++)
    {
        glColor3f(1.0,1.9,1.0);
draw_circle(896,410,l);
    }

    for(l=0;l<=9;l++)
    {
        glColor3f(1.0,1.9,1.0);
draw_circle(868,410,l);
    }

    for(l=0;l<=9;l++)
    {
        glColor3f(1.0,1.9,1.0);
draw_circle(868,398,l);
    }

    for(l=0;l<=9;l++)
    {
        glColor3f(1.0,1.9,1.0);
draw_circle(896,398,l);
    }

    for(l=0;l<=9;l++)
    {
        glColor3f(1.0,1.9,1.0);
draw_circle(882,390,l);
    }

    for(l=0;l<=13;l++)
    {
        glColor3f(1.0,1.9,0.0);
draw_circle(882,405,l);
    }

   //back compound
    glColor3f(0.9,0.9,0.9);
glBegin(GL_POLYGON);
    glVertex2f(550,375);
    glVertex2f(600,425);
    glVertex2f(825,425);
    glVertex2f(850,375);
glEnd();

//Garden

    glColor3f(0.9,0.9,0.9);

glBegin(GL_LINE_LOOP);
    glVertex2f(400,470);
    glVertex2f(530,470);
    glVertex2f(530,330);
    glVertex2f(400,330);
glEnd();

    glColor3f(0.9,0.9,0.9);
glBegin(GL_POLYGON);
    glVertex2f(530,470);
    glVertex2f(540,470);
    glVertex2f(540,330);
    glVertex2f(530,330);
glEnd();

    glColor3f(0.9,0.9,0.9);
glBegin(GL_POLYGON);
    glVertex2f(400,330);
    glVertex2f(540,330);
    glVertex2f(540,320);
    glVertex2f(400,320);
glEnd();

//glColor3f(0.0,0.5,0.0);
glBegin(GL_LINES);
     glVertex2f(410,345);
      glVertex2f(410,360);

glEnd();

for(l=0;l<=2;l++)
    {
        glColor3f(1.0,0.0,0.0);
draw_circle(410,362,l);
    }

glEnd();

//new tree3
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(950,350);
glVertex2f(950,400);
glVertex2f(965,400);
glVertex2f(965,350);
glEnd();
for(l=0;l<=27;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(940,420,l);
draw_circle(970,420,l);
    }

    for(l=0;l<=23;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(950,460,l);
draw_circle(970,460,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(960,485,l);
    }


    for (int i=0;i<120;i+=30)
{
     glColor3f(0.0,0.5,0.0);
glBegin(GL_LINES);
     glVertex2f(440,340+i);
      glVertex2f(440,355+i);

glEnd();

for(l=0;l<=2;l++)
    {
        glColor3f(1.0,0.0,0.0);
draw_circle(440,357+i,l);
    }
}

//new tree2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(300,350);
glVertex2f(300,400);
glVertex2f(315,400);
glVertex2f(315,350);
glEnd();
for(l=0;l<=27;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(290,420,l);
draw_circle(330,420,l);
    }

    for(l=0;l<=23;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(300,460,l);
draw_circle(320,460,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(310,485,l);
    }


    for (int i=0;i<120;i+=30)
{
     glColor3f(0.0,0.5,0.0);
glBegin(GL_LINES);
     glVertex2f(440,340+i);
      glVertex2f(440,355+i);

glEnd();

for(l=0;l<=2;l++)
    {
        glColor3f(1.0,0.0,0.0);
draw_circle(440,357+i,l);
    }
}


//new tree1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(380,450);
glVertex2f(380,500);
glVertex2f(395,500);
glVertex2f(395,450);
glEnd();
for(l=0;l<=27;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(370,520,l);
draw_circle(410,520,l);
    }

    for(l=0;l<=23;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(380,560,l);
draw_circle(400,560,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(390,585,l);
    }


    for (int i=0;i<120;i+=30)
{
     glColor3f(0.0,0.5,0.0);
glBegin(GL_LINES);
     glVertex2f(440,340+i);
      glVertex2f(440,355+i);

glEnd();

for(l=0;l<=2;l++)
    {
        glColor3f(1.0,0.0,0.0);
draw_circle(440,357+i,l);
    }
}
    //new tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(880,450);
glVertex2f(880,500);
glVertex2f(895,500);
glVertex2f(895,450);
glEnd();
for(l=0;l<=27;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(870,520,l);
draw_circle(910,520,l);
    }

    for(l=0;l<=23;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(880,560,l);
draw_circle(900,560,l);
    }

    for(l=0;l<=20;l++)
    {
        glColor3f(0.0,0.5,0.0);
draw_circle(890,585,l);
    }


    for (int i=0;i<120;i+=30)
{
     glColor3f(0.0,0.5,0.0);
glBegin(GL_LINES);
     glVertex2f(440,340+i);
      glVertex2f(440,355+i);

glEnd();

for(l=0;l<=2;l++)
    {
        glColor3f(1.0,0.0,0.0);
draw_circle(440,357+i,l);
    }
}
//building
glColor3f(1,0.4,0.2);
glBegin(GL_POLYGON);
glVertex2f(600,395);
glVertex2f(600,670);
glVertex2f(800,670);
glVertex2f(800,395);
glEnd();


//door
glColor3f(0.5,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(725,395);
glVertex2f(725,450);
glVertex2f(680,450);
glVertex2f(680,395);
glEnd();

//window in building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(630,415+i);
glVertex2f(630,430+i);
glVertex2f(620,430+i);
glVertex2f(620,415+i);
glVertex2f(630,430+i);
glVertex2f(620,430+i);
glVertex2f(630,415+i);
glVertex2f(620,415+i);
}
glEnd();

glColor3f(1.0,1.2,1.3);
glBegin(GL_LINES);
glVertex2f(600,547);
glVertex2f(800,547);
glEnd();

glColor3f(1.0,1.2,1.3);
glBegin(GL_LINES);
glVertex2f(600,495);
glVertex2f(800,495);
glEnd();

glColor3f(1.0,1.2,1.3);
glBegin(GL_LINES);
glVertex2f(600,599);
glVertex2f(800,599);
glEnd();

glColor3f(1.0,0.8,1.3);
glBegin(GL_POLYGON);
glVertex2f(600,651);
glVertex2f(600,670);
glVertex2f(800,670);
glVertex2f(800,651);
glEnd();


glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(670,415+i);
glVertex2f(670,430+i);
glVertex2f(660,430+i);
glVertex2f(660,415+i);
glVertex2f(670,430+i);
glVertex2f(660,430+i);
glVertex2f(670,415+i);
glVertex2f(660,415+i);
}
glEnd();

glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(740,415+i);
glVertex2f(740,430+i);
glVertex2f(730,430+i);
glVertex2f(730,415+i);
glVertex2f(740,430+i);
glVertex2f(730,430+i);
glVertex2f(740,415+i);
glVertex2f(730,415+i);
}
glEnd();

glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(780,415+i);
glVertex2f(780,430+i);
glVertex2f(770,430+i);
glVertex2f(770,415+i);
glVertex2f(780,430+i);
glVertex2f(770,430+i);
glVertex2f(780,415+i);
glVertex2f(770,415+i);
}
glEnd();

//building 2
glColor3f(1,0.0,0.8);
glBegin(GL_POLYGON);
glVertex2f(50,320);
glVertex2f(50,570);
glVertex2f(250,570);
glVertex2f(250,320);
glEnd();

//door 2
glColor3f(0.5,0.0,0.5);
glBegin(GL_POLYGON);
glVertex2f(125,390);
glVertex2f(125,320);
glVertex2f(180,320);
glVertex2f(180,390);
glEnd();
//windows for 1st building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(90,330+i);
glVertex2f(90,348+i);
glVertex2f(80,348+i);
glVertex2f(80,330+i);
glVertex2f(90,348+i);
glVertex2f(80,348+i);
glVertex2f(90,330+i);
glVertex2f(80,330+i);
}
glEnd();

//windows for 1st building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(100,330+i);
glVertex2f(100,348+i);
glVertex2f(80,348+i);
glVertex2f(80,330+i);
glVertex2f(100,348+i);
glVertex2f(80,348+i);
glVertex2f(100,330+i);
glVertex2f(80,330+i);
}
glEnd();

//windows for 1st building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(210,330+i);
glVertex2f(210,348+i);
glVertex2f(200,348+i);
glVertex2f(200,330+i);
glVertex2f(210,348+i);
glVertex2f(200,348+i);
glVertex2f(210,330+i);
glVertex2f(200,330+i);
}
glEnd();

//windows for 1st building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=50;i<250;i+=50)
{
glVertex2f(220,330+i);
glVertex2f(220,348+i);
glVertex2f(200,348+i);
glVertex2f(200,330+i);
glVertex2f(220,348+i);
glVertex2f(200,348+i);
glVertex2f(220,330+i);
glVertex2f(200,330+i);
}
glEnd();

//windows for 1st building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=100;i<250;i+=50)
{
glVertex2f(140,330+i);
glVertex2f(140,348+i);
glVertex2f(130,348+i);
glVertex2f(130,330+i);
glVertex2f(130,348+i);
glVertex2f(140,348+i);
glVertex2f(130,330+i);
glVertex2f(140,330+i);
}
glEnd();

//windows for 1st building
glColor3f(0.9,0.9,0.9);
glBegin(GL_LINES);
for (int i=100;i<250;i+=50)
{
glVertex2f(170,330+i);
glVertex2f(170,348+i);
glVertex2f(160,348+i);
glVertex2f(160,330+i);
glVertex2f(160,348+i);
glVertex2f(170,348+i);
glVertex2f(160,330+i);
glVertex2f(170,330+i);
}
glEnd();
//top part of building
glColor3f(1.0,0.8,1.0);
glBegin(GL_POLYGON);
glVertex2f(50,570);
glVertex2f(50,580);
glVertex2f(250,580);
glVertex2f(250,570);
glEnd();

//lines in building
glColor3f(1.0,1.2,1.3);
glBegin(GL_LINES);
glVertex2f(250,410);
glVertex2f(50,410);
glEnd();

glColor3f(1.0,1.2,1.3);
glBegin(GL_LINES);
glVertex2f(250,510);
glVertex2f(50,510);
glEnd();

glColor3f(1.0,1.2,1.3);
glBegin(GL_LINES);
glVertex2f(250,460);
glVertex2f(50,460);
glEnd();

glBegin(GL_LINES);
glVertex2f(600,350);
glVertex2f(650,350);
glVertex2f(625,325);
glVertex2f(625,375);
glEnd();

//dustbin
glColor3f(0.0,0.6,0.0);
glBegin(GL_POLYGON);
glVertex2f(555,315);
glVertex2f(540,390);
glVertex2f(670,390);
glVertex2f(655,315);
glEnd();
char string4[]="USE ME";
void *font3=GLUT_BITMAP_TIMES_ROMAN_24;
int q;
glColor3f(1.0,1.0,1.0);
glRasterPos2f(560,345);
for(q=0;q<strlen(string4);q++)
        glutBitmapCharacter(font3,string4[q]);


        glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(395,355);
glVertex2f(395,460);
glVertex2f(480,460);
glVertex2f(480,355);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(405,425);
glVertex2f(405,415);
glVertex2f(470,415);
glVertex2f(470,425);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(441,315);
glVertex2f(441,355);
glVertex2f(431,355);
glVertex2f(431,315);
glEnd();
char string5[]="POST OFFICE";
char string6[]="LETTER BOX";
glColor3f(1.0,1.0,1.0);
glRasterPos2f(408,445);
for(q=0;q<strlen(string5);q++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,string5[q]);
        glRasterPos2f(408,385);
for(q=0;q<strlen(string6);q++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,string6[q]);

//bus

glColor3f(0.9,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(1250-i,210);
glVertex2f(1250-i,435);
glVertex2f(922-i,435);
glVertex2f(850-i,335);
glVertex2f(850-i,210);
glEnd();


//door
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(1010-i,210);
glVertex2f(1010-i,310);
glVertex2f(1070-i,310);
glVertex2f(1070-i,210);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(1160-i,335);
glVertex2f(1160-i,420);
glVertex2f(1230-i,420);
glVertex2f(1230-i,335);
glEnd();





glColor3f(5.0,5.0,5.0);
glBegin(GL_POLYGON);
glVertex2f(1060-i,335);
glVertex2f(1060-i,420);
glVertex2f(1130-i,420);
glVertex2f(1130-i,335);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(960-i,335);
glVertex2f(960-i,420);
glVertex2f(1030-i,420);
glVertex2f(1030-i,335);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(870-i,335);
glVertex2f(920-i,420);
glVertex2f(940-i,420);
glVertex2f(940-i,335);
glEnd();



for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(950-i,210,l);
	draw_circle(1125-i,210,l);
   }

int k;
char string1[]="N";
char string11[]="M";
char string12[]="A";
char string13[]="I";
char string14[]="T";
char string3[]="E";

void *font2=GLUT_BITMAP_TIMES_ROMAN_24;


glColor3f(0.0,0.0,1.0);
glRasterPos2f(880-i,270);
for(k=0;k<strlen(string1);k++)
        glutBitmapCharacter(font2,string1[k]);
glColor3f(0.0,0.0,1.0);
glRasterPos2f(900-i,270);
for(k=0;k<strlen(string11);k++)
        glutBitmapCharacter(font2,string11[k]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(923-i,270);
for(k=0;k<strlen(string12);k++)
        glutBitmapCharacter(font2,string12[k]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(937-i,270);
for(k=0;k<strlen(string11);k++)
        glutBitmapCharacter(font2,string11[k]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(960-i,270);
for(k=0;k<strlen(string13);k++)
        glutBitmapCharacter(font2,string13[k]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(970-i,270);
for(k=0;k<strlen(string14);k++)
        glutBitmapCharacter(font2,string14[k]);

        glColor3f(0.0,0.0,1.0);
glRasterPos2f(1080-i,270);
for(q=0;q<strlen(string1);q++)
        glutBitmapCharacter(font2,string1[q]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(1100-i,270);
for(q=0;q<strlen(string13);q++)
        glutBitmapCharacter(font2,string13[q]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(1110-i,270);
for(q=0;q<strlen(string14);q++)
        glutBitmapCharacter(font2,string14[q]);
        glColor3f(0.0,0.0,1.0);
glRasterPos2f(1125-i,270);
for(q=0;q<strlen(string14);q++)
        glutBitmapCharacter(font2,string14[q]);

 glColor3f(0.0,0.0,1.0);
glRasterPos2f(1140-i,270);
for(q=0;q<strlen(string3);q++)
        glutBitmapCharacter(font2,string3[q]);

//signal

    glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
        glVertex2f(1040,170);
        glVertex2f(1040,440);
        glVertex2f(1050,440);
        glVertex2f(1050,170);
glEnd();


    glColor3f(0.7,0.7,0.7);
glBegin(GL_POLYGON);
        glVertex2f(1020,440);
        glVertex2f(1020,590);
        glVertex2f(1070,590);
        glVertex2f(1070,440);
glEnd();

//new car design

//new car design
//bottom left
glColor3f(0.0,0.2,0.8);
glBegin(GL_POLYGON);
glVertex2f(25+z,80);
glVertex2f(25+z,140);
glVertex2f(150+z,140);
glVertex2f(200+z,110);
glVertex2f(200+z,80);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(25+z,80);
glVertex2f(25+z,140);
glVertex2f(150+z,140);
glVertex2f(200+z,110);
glVertex2f(200+z,80);
glEnd();

glColor3f(0.0,0.2,0.8);
glBegin(GL_POLYGON);
glVertex2f(25+z,140);
glVertex2f(40+z,180);
glVertex2f(140+z,180);
glVertex2f(150+z,140);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(25+z,140);
glVertex2f(40+z,180);
glVertex2f(140+z,180);
glVertex2f(150+z,140);
glEnd();


glColor3f(0.6,0.6,0.6);
glBegin(GL_POLYGON);
glVertex2f(140+z,180);
glVertex2f(190+z,190);
glVertex2f(200+z,160);
glVertex2f(150+z,140);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(140+z,180);
glVertex2f(190+z,190);
glVertex2f(200+z,160);
glVertex2f(150+z,140);
glEnd();

glColor3f(0.0,0.2,0.7);
glBegin(GL_POLYGON);
glVertex2f(150+z,140);
glVertex2f(200+z,160);
glVertex2f(250+z,130);
glVertex2f(200+z,110);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(150+z,140);
glVertex2f(200+z,160);
glVertex2f(250+z,130);
glVertex2f(200+z,110);
glEnd();


glColor3f(0.0,0.2,0.8);
glBegin(GL_POLYGON);
glVertex2f(200+z,110);
glVertex2f(250+z,130);
glVertex2f(250+z,97);
glVertex2f(200+z,80);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(200+z,110);
glVertex2f(250+z,130);
glVertex2f(250+z,97);
glVertex2f(200+z,80);
glEnd();

//top of car
glColor3f(0.0,0.2,0.7);
glBegin(GL_POLYGON);
glVertex2f(60+z,190);
glVertex2f(190+z,190);
glVertex2f(140+z,180);
glVertex2f(40+z,180);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(60+z,190);
glVertex2f(190+z,190);
glVertex2f(140+z,180);
glVertex2f(40+z,180);
glEnd();

//wheel of car

   for(l=0;l<20;l++)
   {
       glColor3f(0.0,0.0,0.0);
draw_circle(65+z,80,l);
draw_circle(155+z,80,l);
   }

//window of car
glColor3f(0.6,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(42+z,140);
glVertex2f(48+z,165);
glVertex2f(73+z,165);
glVertex2f(82+z,140);
glEnd();

glColor3f(0.6,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(105+z,165);
glVertex2f(135+z,165);
glVertex2f(140+z,140);
glVertex2f(100+z,140);
glEnd();


    glColor3f(1.2,1.2,0.2);
glBegin(GL_POLYGON);
   glVertex2f(375+i,225);
   glVertex2f(525+i,225);
   glVertex2f(575+i,140);
   glVertex2f(575+i,50);
   glVertex2f(375+i,50);
glEnd();
   glColor3f(0.0,0.5,0.9);
glBegin(GL_POLYGON);
   glVertex2f(25+i,50);
   glVertex2f(25+i,250);
   glVertex2f(375+i,250);
   glVertex2f(375+i,50);
glEnd();
   glColor3f(0.5,0.5,0.5);
glBegin(GL_POLYGON);
   glVertex2f(405+i,120);
   glVertex2f(405+i,185);
   glVertex2f(505+i,185);
   glVertex2f(535+i,120);
glEnd();


   for(l=0;l<=40;l++)
    {
        glColor3f(0.0,0.0,0.0);
draw_circle(125+i,50,l);

    }


   for(l=0;l<=40;l++)
    {
        glColor3f(0.0,0.0,0.0);
draw_circle(425+i,50,l);

    }

  }



void traffic_light()
{
     int l;
     for(l=0;l<=20;l++)
     {
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,565,l);

        glColor3f(0.0,0.0,0.0);
draw_circle(1045,515,l);
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,465,l);
     }
     if(j==0)
     {
        for(l=0;l<=20;l++)
        {
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,465,l);


        {
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,515,l);
        }

        glColor3f(1.0,0.0,0.0);
draw_circle(1045,565,l);

        }
      }
     if(j==1)
     {
        for(l=0;l<=20;l++)
        {
        glColor3f(0.0,0.7,0.0);
draw_circle(1045,465,l);

        //glColor3f(1.0,1.0,0.0);for(l=0;l<=40;l++)
        {
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,515,l);
        }

        glColor3f(0.0,0.0,0.0);
draw_circle(1045,565,l);

        }
      }
      if(j==2)

        {
        for(l=0;l<=20;l++)
        {
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,565,l);

        glColor3f(1.0,1.0,0.0);
draw_circle(1045,515,l);
        glColor3f(0.0,0.0,0.0);
draw_circle(1045,465,l);

        }
      }

}


void idle()
{
glClearColor(1.0,1.0,1.0,1.0);

   if(a==0 || j==0)
   {

   if(i<300)
       if(j==0)
 {
i=i;
     ++m;
     n-=2;
     o+=0.2;

 }
   else
 {

i+=SPEED;
     ++m;
     n-=2;
     o+=0.2;
 }
   else{
i+=SPEED;
     ++m;
     n-=2;
     o+=0.2;
 }


 if(i>1100)
i=0.0;
 if(m>1100)
     m=0.0;
 if( o>75)
 {
    s=0;
 }
glutPostRedisplay();
 if(z<800)
       if(j==0)
 {
     z=z;
     ++m;
     n-=2;
     o+=0.2;

 }
   else
 {

     z+=SPEED2;
     ++m;
     n-=2;
     o+=0.2;
 }
   else{
   z+=SPEED2;
        ++m;
     n-=2;
     o+=0.2;
 }


 if(z>1100)
     z=0.0;
 if(m>1100)
     m=0.0;
 if( o>75)
 {
    s=0;
 }
glutPostRedisplay();
   }
   if(a==1)
   {
       if(i<300)
       if(j==0)
       {
i=i;
         ++m;
         n-=2;
         o+=0.2;
       }
   else
 {

i+=SPEED3;
     ++m;
     n-=2;
     o+=0.2;
 }
   else{
i+=SPEED3;
     ++m;
     n-=2;
     o+=0.2;
 }


 if(i>1100)
i=0.0;
 if(m>1100)
     m=0.0;
 if(z>1100)
     z=0.0;
 if( o>75)
 {
    s=0;
 }
glutPostRedisplay();
 if(z<800)
       if(j==0)
 {
     z=z;
     ++m;
     n-=2;
     o+=0.2;

 }
   else
 {

     z+=SPEED3;
     ++m;
     n-=2;
     o+=0.2;
 }
   else{
   z+=SPEED3;
        ++m;
     n-=2;
     o+=0.2;
 }


 if(z>1100)
     z=0.0;
 if(m>1100)
     m=0.0;
 if( o>75)
 {
    s=0;
 }

glutPostRedisplay();
   }


}



void main_menu(int index)
{
    if(index==1)
    {
        s=1;
        o=n=0.0;
    }
}




void disp1()
{
 int c_menu;
glClear(GL_COLOR_BUFFER_BIT);


glClearColor(0.8,0.0,1.0,1);

   glColor3f(0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);

drawString1(GLUT_BITMAP_TIMES_ROMAN_24," PROJECT DESCRIPTION",400,630);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"_________________________",380,624);

drawString1(GLUT_BITMAP_HELVETICA_18,"  We know that traffic signals direct the flow of traffic and helps us to drive our vehicles in a safer manner by lowering the",50,600);


drawString1(GLUT_BITMAP_HELVETICA_18," risk of accidents that would happen. The main objective of this project is to have a traffic control simulation just similar to a",50,570);

drawString1(GLUT_BITMAP_HELVETICA_18," real world traffic control. Here we would apply the theoretical concepts and practical knowledge of computer graphics",50,540);

drawString1(GLUT_BITMAP_HELVETICA_18," using OpenGL. The scenario of the project is that, there are vehicles moving on the road which are controlled by the ",50,510);

drawString1(GLUT_BITMAP_HELVETICA_18," Red, Yellow and Green colored signals,, where Red means ‘to stop the vehicles’, Green means ‘to go’ and Yellow means ",50,480);

drawString1(GLUT_BITMAP_HELVETICA_18," ‘ready to go’.This would be made interactive as follows, when we press the key ‘R’ the signal light changes to red,when",50,450);

drawString1(GLUT_BITMAP_HELVETICA_18," we press the key ‘G’ the signal light changes to green and when we press the key ‘Y’ the signal light changes to yellow color.",50,420);

drawString1(GLUT_BITMAP_HELVETICA_18," Press 'r' or 'R' to change the signal light to Red",50,380);

drawString1(GLUT_BITMAP_HELVETICA_18," Press 'g' or 'G' to change the signal light to Green",50,350);


drawString1(GLUT_BITMAP_HELVETICA_18,"Press RIGHT MOUSE BUTTON to display Menu, the whole image is paused until the menu is selected ",50,240);

drawString1(GLUT_BITMAP_HELVETICA_18," Press LEFT MOUSE BUTON to Quit the program ",50,210);



box();

        glColor3f(0.0,0.0,0.0);
   drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"PRESS M or m, To Go To Next Page",650,70);

glFlush();



glFlush();



}

void mouse(int btn,int state,int x,int y)
{
printf("%d:\n",flag);


   if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
     exit(0);

}

void keyboard2( unsigned char key, int x, int y )
{
    switch( key )
    {
    case 'r':
    case 'R':
        j=0 ;
        a=0;
        break;

    case 'g':
    case 'G':
        j=1;
        a=0;
         break;




    case 'y':
    case 'Y':
        a=1;
        j=2;
        break;


    }

}

void disp2()
{

    int c_menu;
glClear(GL_COLOR_BUFFER_BIT);

draw_object();
traffic_light();
c_menu=glutCreateMenu(main_menu);
glutAddMenuEntry("Flying object ",1);
glutAddMenuEntry("to stop vehicles 'R' or 'r'",2);
glutAddMenuEntry("to resume 'g' or 'G'",3);
glutAddMenuEntry("Vehicles to move slowly 'y' or 'Y'",6);


glutAttachMenu(GLUT_RIGHT_BUTTON);

glutIdleFunc(idle);
glutKeyboardFunc(keyboard2);
glFlush();
}


void keyboard1(unsigned char key, int x, int y )
{

    switch( key )
    {
        case 'M':
    case 'm':
glutInitWindowSize(1100.0,700.0);
glutInitWindowPosition(0,0);
glutCreateWindow("CITY");
myinit();


   // disp1();

glutDisplayFunc(disp2);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard2);
glutIdleFunc(idle);
       flag1=1;
        break;
glFlush();
    }

}



void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {
        case 'F':
    case 'f':
glutInitWindowSize(1100.0,700.0);
glutInitWindowPosition(0,0);
glutCreateWindow("Traffic Single Control");
myinit();



   // disp1();
glutDisplayFunc(disp1);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard1);
glutIdleFunc(idle);
       flag1=1;
        break;

    }

}

  void display()
{

 //front page
glClearColor(0.8,0.0,1.0,1);

   glColor3f(0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"_________________________________________",250,675);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24," A MINI PROJECT ON ",400,630);
glColor3f(0.8,0.0,0.0);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"CITY",480,595);
glColor3f(0.0,0.0,0.0);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"_________________________________________",250,580);
glColor3f(1.0,1.0,1.0);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"PROJECT BY:",50,400);
glColor3f(0.0,0.0,0.0);
drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"___________",49,390);
glColor3f(1.0,1.0,1.0);
        drawString1(GLUT_BITMAP_HELVETICA_18,"B.LALITHA KAMATH",180,350);
                drawString1(GLUT_BITMAP_HELVETICA_18,"4NM16IS018",400,350);

    drawString1(GLUT_BITMAP_HELVETICA_18,"DEEPASHREE S",180,310);
            drawString1(GLUT_BITMAP_HELVETICA_18,"4NM16IS028",400,310);

      drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"Under the guidance of :",50,265);
     glColor3f(0.0,0.0,0.0);
      drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"__________________",50,260);
       glColor3f(1.0,1.0,1.0);
        drawString1(GLUT_BITMAP_HELVETICA_18,"Ms SAPNA S",180,210);
          drawString1(GLUT_BITMAP_HELVETICA_18,"INFORMATION SCIENCE AND ENGINEERING DEPARTMENT",180,185);
          drawString1(GLUT_BITMAP_HELVETICA_18,"NMAMIT, Nitte",180,160);

       box();

        glColor3f(0.0,0.0,0.0);
   drawString1(GLUT_BITMAP_TIMES_ROMAN_24,"PRESS F or f, To Go To Next Page",670,130);

glFlush();
}


int main(int argc,char** argv)
{
    int c_menu;
printf("Press 'r' or 'R' to change the signal light to red \n");
printf("Press 'g' or 'G' to change the signal light to green \n");
printf("Press 'y' or 'Y' to change the signal light to yellow \n");

printf("Press RIGHT MOUSE BUTTON to display menu , the whole image is paused until the menu is selected \n");
printf("Press LEFT MOUSE BUTON to quit the program \n");

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1100.0,700.0);
glutInitWindowPosition(0,0);
glutCreateWindow("City");
    flag=0;
glutDisplayFunc(display);
glutIdleFunc(idle);
glutKeyboardFunc(keyboardFunc);
glutMouseFunc(mouse);
myinit();


c_menu=glutCreateMenu(main_menu);
glutAddMenuEntry("Flying object ",1);
glutAddMenuEntry("to stop vehicles 'R' or 'r'",2);
glutAddMenuEntry("to resume 'g' or 'G'",3);
glutAddMenuEntry("day mode =d",4);
glutAddMenuEntry("night mode=n",5);
glutAddMenuEntry("Vehicles to move slowly 'y' or 'Y'",6);


glutAttachMenu(GLUT_RIGHT_BUTTON);


glutMainLoop();
    return 0;
}

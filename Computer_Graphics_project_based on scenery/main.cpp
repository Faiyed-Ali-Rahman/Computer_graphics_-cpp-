#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#include<Windows.h>
#include<MMSystem.h>
float cloudSpeed1=0.00f;
float cloudSpeed2=0.00f;
float cloudSpeed3=0.00f;
float carSpeed1=0.00f;
float carSpeed2=0.00f;
float carSpeed3=0.00f;
float busSpeed1=0.00f;
float shipSpeed1=0.00f;
float rainSpeed=0.00f;

float saveSpeed1=0;
float saveSpeed2=0;
float saveSpeed3=0;
float saveSpeed4=0;
int RoadLightB=255;
int x=0,y=500;
int trafficColour=0;
int trafficColour2=255;

int night=0,rain=0,skyR1=255,skyG1=255,skyB1=239,skyR2=131,skyG2=175,skyB2=224;
int s1R=159,s1G=94,s1B=66,s2R=115,s2G=115,s2B=95,s3R=142,s3G=193,s3B=119;
int waterR=18,waterG=44,waterB=71;
int b1R=200,b1G=166,b1B=87;
int window1R=177,window1G=249,window1B=252;
int window2R=249,window2G=252,window2B=133;
//////////////////////
int ballx=0;
int bally=0;

void drawCircle(float x1, float y1,double radius)
{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle<361.0f; angle += 1.0f)
	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}
float getX(int val)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    float frac = (float)val/((float)width/2);
    return frac;
    //cout<<"x="<<frac<<endl;
}
float getY(int val)
{
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    float frac = (float)val/((float)height/2);
    return frac;
    //cout<<"y="<<frac<<endl;
}
void sky()
{
    glColor3ub(skyR1,skyG1,skyB1);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(-500),getY(-45));
            glVertex2f(getX(500),getY(-45));
            glColor3ub(skyR2,skyG2,skyB2);
            glVertex2f(getX(500),getY(500));
            glVertex2f(getX(-500),getY(500));
        glEnd();
    glPopMatrix();
}
void water()
{
    glPopMatrix();
    glColor3ub(waterR,waterG,waterB);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(-500),getY(-500));
            glVertex2f(getX(500),getY(-500));
            glColor3ub(77,140,210);
            glVertex2f(getX(500),getY(80));
            glVertex2f(getX(-500),getY(80));
        glEnd();
    glPopMatrix();
}
void star()
{
    glPushMatrix();
     //glTranslatef(shipSpeed1,0,0);
        glBegin(GL_QUADS);
            glColor3ub(255,255,240);
            drawCircle(0.2,0.9,0.006);
            drawCircle(0.4,0.9,0.006);
            drawCircle(0.6,0.9,0.006);
            drawCircle(0.8,0.9,0.006);
            drawCircle(-0.2,0.9,0.006);
            drawCircle(-0.4,0.9,0.006);
            drawCircle(-0.6,0.9,0.006);
            drawCircle(-0.8,0.9,0.006);
            drawCircle(-0.9,0.8,0.006);
            drawCircle(-0.7,0.8,0.006);
            drawCircle(-0.5,0.8,0.006);
            drawCircle(-0.3,0.8,0.006);
            drawCircle(-0.0,0.9,0.006);
            drawCircle(-0.1,0.8,0.006);
            drawCircle(0.1,0.8,0.006);
            drawCircle(0.3,0.8,0.006);
            drawCircle(0.5,0.8,0.006);
            drawCircle(0.7,0.8,0.006);
            drawCircle(0.9,0.8,0.006);

            drawCircle(0.2,0.7,0.006);
            drawCircle(0.4,0.7,0.006);
            drawCircle(0.6,0.7,0.006);
            drawCircle(0.8,0.7,0.006);
            drawCircle(-0.2,0.7,0.006);
            drawCircle(-0.4,0.7,0.006);
            drawCircle(-0.6,0.7,0.006);
            drawCircle(-0.8,0.7,0.006);
            drawCircle(-0.9,0.6,0.006);
            drawCircle(-0.7,0.6,0.006);
            drawCircle(-0.5,0.6,0.006);
            drawCircle(-0.3,0.6,0.006);
            drawCircle(-0.0,0.7,0.006);
            drawCircle(-0.1,0.6,0.006);
            drawCircle(0.1,0.6,0.006);
            drawCircle(0.3,0.6,0.006);
            drawCircle(0.5,0.6,0.006);
            drawCircle(0.7,0.6,0.006);
            drawCircle(0.9,0.6,0.006);

            drawCircle(0.2,0.5,0.006);
            drawCircle(0.4,0.5,0.006);
            drawCircle(0.6,0.5,0.006);
            drawCircle(0.8,0.5,0.006);
            drawCircle(-0.2,0.5,0.006);
            drawCircle(-0.4,0.5,0.006);
            drawCircle(-0.6,0.5,0.006);
            drawCircle(-0.8,0.5,0.006);
            drawCircle(-0.9,0.4,0.006);
            drawCircle(-0.7,0.4,0.006);
            drawCircle(-0.5,0.4,0.006);
            drawCircle(-0.3,0.4,0.006);
            drawCircle(-0.0,0.5,0.006);
            drawCircle(-0.1,0.4,0.006);
            drawCircle(0.1,0.4,0.006);
            drawCircle(0.3,0.4,0.006);
            drawCircle(0.5,0.4,0.006);
            drawCircle(0.7,0.4,0.006);
            drawCircle(0.9,0.4,0.006);
            ////////////////MOON///////
            drawCircle(-0.6,0.75,0.1);
        glEnd();
    glPopMatrix();
}
void building()
{
    glColor3ub(b1R,b1G,b1B);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(50),getY(80));
            glVertex2f(getX(160),getY(80));
            glVertex2f(getX(160),getY(300));
            glVertex2f(getX(50),getY(300));

            glColor3ub(155,124,51);
            glVertex2f(getX(160),getY(80));
            glVertex2f(getX(190),getY(80));
            glVertex2f(getX(190),getY(270));
            glVertex2f(getX(160),getY(300));

            ///window
            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60),getY(100));
            glVertex2f(getX(80),getY(100));
             glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80),getY(150));
            glVertex2f(getX(60),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90),getY(100));
            glVertex2f(getX(110),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110),getY(150));
            glVertex2f(getX(90),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120),getY(100));
            glVertex2f(getX(140),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140),getY(150));
            glVertex2f(getX(120),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60),getY(100+60));
            glVertex2f(getX(80),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80),getY(150+60));
            glVertex2f(getX(60),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90),getY(100+60));
            glVertex2f(getX(110),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110),getY(150+60));
            glVertex2f(getX(90),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120),getY(100+60));
            glVertex2f(getX(140),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140),getY(150+60));
            glVertex2f(getX(120),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60),getY(100+120));
            glVertex2f(getX(80),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80),getY(150+120));
            glVertex2f(getX(60),getY(150+120));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90),getY(100+120));
            glVertex2f(getX(110),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110),getY(150+120));
            glVertex2f(getX(90),getY(150+120));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120),getY(100+120));
            glVertex2f(getX(140),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140),getY(150+120));
            glVertex2f(getX(120),getY(150+120));


        glEnd();
    glPopMatrix();

    glColor3ub(88,158,68);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(50-500),getY(80));
            glVertex2f(getX(160-500),getY(80));
            glVertex2f(getX(160-500),getY(300));
            glVertex2f(getX(50-500),getY(300));

            glColor3ub(58,104,43);
            glVertex2f(getX(160-500),getY(80));
            glVertex2f(getX(190-500),getY(80));
            glVertex2f(getX(190-500),getY(270));
            glVertex2f(getX(160-500),getY(300));

            ///window
            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-500),getY(100));
            glVertex2f(getX(80-500),getY(100));
             glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-500),getY(150));
            glVertex2f(getX(60-500),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-500),getY(100));
            glVertex2f(getX(110-500),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-500),getY(150));
            glVertex2f(getX(90-500),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-500),getY(100));
            glVertex2f(getX(140-500),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-500),getY(150));
            glVertex2f(getX(120-500),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-500),getY(100+60));
            glVertex2f(getX(80-500),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-500),getY(150+60));
            glVertex2f(getX(60-500),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-500),getY(100+60));
            glVertex2f(getX(110-500),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-500),getY(150+60));
            glVertex2f(getX(90-500),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-500),getY(100+60));
            glVertex2f(getX(140-500),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-500),getY(150+60));
            glVertex2f(getX(120-500),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-500),getY(100+120));
            glVertex2f(getX(80-500),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-500),getY(150+120));
            glVertex2f(getX(60-500),getY(150+120));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-500),getY(100+120));
            glVertex2f(getX(110-500),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-500),getY(150+120));
            glVertex2f(getX(90-500),getY(150+120));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-500),getY(100+120));
            glVertex2f(getX(140-500),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-500),getY(150+120));
            glVertex2f(getX(120-500),getY(150+120));


        glEnd();
    glPopMatrix();

    glColor3ub(50,173,158);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(50+400),getY(80));
            glVertex2f(getX(160+400),getY(80));
            glVertex2f(getX(160+400),getY(300));
            glVertex2f(getX(50+400),getY(300));

            ///window
            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60+400),getY(100));
            glVertex2f(getX(80+400),getY(100));
             glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80+400),getY(150));
            glVertex2f(getX(60+400),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90+400),getY(100));
            glVertex2f(getX(110+400),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110+400),getY(150));
            glVertex2f(getX(90+400),getY(150));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60+400),getY(100+60));
            glVertex2f(getX(80+400),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80+400),getY(150+60));
            glVertex2f(getX(60+400),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90+400),getY(100+60));
            glVertex2f(getX(110+400),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110+400),getY(150+60));
            glVertex2f(getX(90+400),getY(150+60));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60+400),getY(100+120));
            glVertex2f(getX(80+400),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80+400),getY(150+120));
            glVertex2f(getX(60+400),getY(150+120));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90+400),getY(100+120));
            glVertex2f(getX(110+400),getY(100+120));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110+400),getY(150+120));
            glVertex2f(getX(90+400),getY(150+120));

        glEnd();
    glPopMatrix();

    glColor3ub(225,215,37);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(50-300),getY(80));
            glVertex2f(getX(160-300),getY(80));
            glVertex2f(getX(160-300),getY(300-90));
            glVertex2f(getX(50-300),getY(300-90));

            glColor3ub(188,180,27);
            glVertex2f(getX(160-300),getY(80));
            glVertex2f(getX(190-300),getY(80));
            glVertex2f(getX(190-300),getY(270-90));
            glVertex2f(getX(160-300),getY(300-90));

            ///window
            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-300),getY(100));
            glVertex2f(getX(80-300),getY(100));
             glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-300),getY(150-10));
            glVertex2f(getX(60-300),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-300),getY(100));
            glVertex2f(getX(110-300),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-300),getY(150-10));
            glVertex2f(getX(90-300),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-300),getY(100));
            glVertex2f(getX(140-300),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-300),getY(150-10));
            glVertex2f(getX(120-300),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-300),getY(100+60));
            glVertex2f(getX(80-300),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-300),getY(150+60-10));
            glVertex2f(getX(60-300),getY(150+60-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-300),getY(100+60));
            glVertex2f(getX(110-300),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-300),getY(150+60-10));
            glVertex2f(getX(90-300),getY(150+60-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-300),getY(100+60));
            glVertex2f(getX(140-300),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-300),getY(150+60-10));
            glVertex2f(getX(120-300),getY(150+60-10));



        glEnd();
    glPopMatrix();

    glColor3ub(162,70,172);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(50+200),getY(80));
            glVertex2f(getX(150+200),getY(80));
            glVertex2f(getX(150+200),getY(300-90));
            glVertex2f(getX(50+200),getY(300-90));

            glColor3ub(120,58,96);
            glVertex2f(getX(150+200),getY(80));
            glVertex2f(getX(180+200),getY(80));
            glVertex2f(getX(180+200),getY(270-90));
            glVertex2f(getX(150+200),getY(300-90));

            ///window
            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60+200),getY(100));
            glVertex2f(getX(80+200),getY(100));
             glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80+200),getY(150-10));
            glVertex2f(getX(60+200),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90+220),getY(100));
            glVertex2f(getX(110+220),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110+220),getY(150-10));
            glVertex2f(getX(90+220),getY(150-10));


            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60+200),getY(100+60));
            glVertex2f(getX(80+200),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80+200),getY(150+60-10));
            glVertex2f(getX(60+200),getY(150+60-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90+220),getY(100+60));
            glVertex2f(getX(110+220),getY(100+60));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110+220),getY(150+60-10));
            glVertex2f(getX(90+220),getY(150+60-10));

         glEnd();
    glPopMatrix();

    glColor3ub(126,153,154);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(50-150),getY(80));
            glVertex2f(getX(160-150),getY(80));
            glVertex2f(getX(160-150),getY(300-50));
            glVertex2f(getX(50-150),getY(300-50));

            glColor3ub(96,120,121);
            glVertex2f(getX(160-150),getY(80));
            glVertex2f(getX(190-150),getY(80));
            glVertex2f(getX(190-150),getY(270-50));
            glVertex2f(getX(160-150),getY(300-50));

            ///window
            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-150),getY(100));
            glVertex2f(getX(80-150),getY(100));
             glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-150),getY(150-10));
            glVertex2f(getX(60-150),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-150),getY(100));
            glVertex2f(getX(110-150),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-150),getY(150-10));
            glVertex2f(getX(90-150),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-150),getY(100));
            glVertex2f(getX(140-150),getY(100));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-150),getY(150-10));
            glVertex2f(getX(120-150),getY(150-10));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-150),getY(100+60-10));
            glVertex2f(getX(80-150),getY(100+60-10));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-150),getY(150+60-20));
            glVertex2f(getX(60-150),getY(150+60-20));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-150),getY(100+60-10));
            glVertex2f(getX(110-150),getY(100+60-10));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-150),getY(150+60-20));
            glVertex2f(getX(90-150),getY(150+60-20));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-150),getY(100+60-10));
            glVertex2f(getX(140-150),getY(100+60-10));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-150),getY(150+60-20));
            glVertex2f(getX(120-150),getY(150+60-20));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(60-150),getY(100+120-10));
            glVertex2f(getX(80-150),getY(100+120-10));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(80-150),getY(150+120-30));
            glVertex2f(getX(60-150),getY(150+120-30));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(90-150),getY(100+120-10));
            glVertex2f(getX(110-150),getY(100+120-10));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(110-150),getY(150+120-30));
            glVertex2f(getX(90-150),getY(150+120-30));

            glColor3ub(window1R,window1G,window1B);
            glVertex2f(getX(120-150),getY(100+120-10));
            glVertex2f(getX(140-150),getY(100+120-10));
            glColor3ub(window2R,window2G,window2B);
            glVertex2f(getX(140-150),getY(150+120-30));
            glVertex2f(getX(120-150),getY(150+120-30));


        glEnd();
    glPopMatrix();
}
void Road()
{
    glColor3ub(94,111,94);
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex2f(getX(-500),getY(-40));
            glVertex2f(getX(500),getY(-40));
            glColor3ub(9,11,94);
            glVertex2f(getX(500),getY(80));
            glVertex2f(getX(-500),getY(80));
        glEnd();

        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
            glVertex2f(getX(-500),getY(15));
            glVertex2f(getX(-450),getY(15));
            glVertex2f(getX(-450),getY(25));
            glVertex2f(getX(-500),getY(25));

            glVertex2f(getX(-440),getY(15));
            glVertex2f(getX(-390),getY(15));
            glVertex2f(getX(-390),getY(25));
            glVertex2f(getX(-440),getY(25));

            glVertex2f(getX(-380),getY(15));
            glVertex2f(getX(-330),getY(15));
            glVertex2f(getX(-330),getY(25));
            glVertex2f(getX(-380),getY(25));

            glVertex2f(getX(-320),getY(15));
            glVertex2f(getX(-270),getY(15));
            glVertex2f(getX(-270),getY(25));
            glVertex2f(getX(-320),getY(25));

            glVertex2f(getX(-260),getY(15));
            glVertex2f(getX(-210),getY(15));
            glVertex2f(getX(-210),getY(25));
            glVertex2f(getX(-260),getY(25));

            glVertex2f(getX(-200),getY(15));
            glVertex2f(getX(-150),getY(15));
            glVertex2f(getX(-150),getY(25));
            glVertex2f(getX(-200),getY(25));

            glVertex2f(getX(-140),getY(15));
            glVertex2f(getX(-90),getY(15));
            glVertex2f(getX(-90),getY(25));
            glVertex2f(getX(-140),getY(25));

            glVertex2f(getX(-80),getY(15));
            glVertex2f(getX(-30),getY(15));
            glVertex2f(getX(-30),getY(25));
            glVertex2f(getX(-80),getY(25));

            glVertex2f(getX(500),getY(15));
            glVertex2f(getX(450),getY(15));
            glVertex2f(getX(450),getY(25));
            glVertex2f(getX(500),getY(25));

            glVertex2f(getX(440),getY(15));
            glVertex2f(getX(390),getY(15));
            glVertex2f(getX(390),getY(25));
            glVertex2f(getX(440),getY(25));

            glVertex2f(getX(380),getY(15));
            glVertex2f(getX(330),getY(15));
            glVertex2f(getX(330),getY(25));
            glVertex2f(getX(380),getY(25));

            glVertex2f(getX(320),getY(15));
            glVertex2f(getX(270),getY(15));
            glVertex2f(getX(270),getY(25));
            glVertex2f(getX(320),getY(25));

            glVertex2f(getX(260),getY(15));
            glVertex2f(getX(210),getY(15));
            glVertex2f(getX(210),getY(25));
            glVertex2f(getX(260),getY(25));

            glVertex2f(getX(200),getY(15));
            glVertex2f(getX(150),getY(15));
            glVertex2f(getX(150),getY(25));
            glVertex2f(getX(200),getY(25));

            glVertex2f(getX(140),getY(15));
            glVertex2f(getX(90),getY(15));
            glVertex2f(getX(90),getY(25));
            glVertex2f(getX(140),getY(25));

            glVertex2f(getX(80),getY(15));
            glVertex2f(getX(30),getY(15));
            glVertex2f(getX(30),getY(25));
            glVertex2f(getX(80),getY(25));
        glEnd();
    ////////////////////
    ///road line -40,80

    glPopMatrix();
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3ub(155,139,117);
            glVertex2f(getX(-500),getY(-80));
            glVertex2f(getX(500),getY(-80));
            glVertex2f(getX(500),getY(-38));
            glVertex2f(getX(-500),getY(-38));

            glColor3ub(155,162,164);
            glVertex2f(getX(-500),getY(-50));
            glVertex2f(getX(500),getY(-50));
            glVertex2f(getX(500),getY(-38));
            glVertex2f(getX(-500),getY(-38));

             glVertex2f(getX(-500),getY(82));
            glVertex2f(getX(500),getY(82));
            glVertex2f(getX(500),getY(78));
            glVertex2f(getX(-500),getY(78));
        glEnd();
    glPopMatrix();
}
void Bush()
{
    glPushMatrix();
    glTranslatef(-0.7,0.22,0);
        glBegin(GL_QUADS);

            glColor3ub(16,221,17);
            glVertex2f(getX(15),getY(-15));
            glVertex2f(getX(100),getY(-15));
            glVertex2f(getX(100),getY(5));
            glVertex2f(getX(20),getY(5));

            drawCircle(0.1,0.01,0.03);
            drawCircle(0.15,0.01,0.03);
            drawCircle(0.2,-.01,0.03);
            drawCircle(0.05,-.01,0.03);
            drawCircle(0.1,0.01,0.03);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7,0.22,0);
        glBegin(GL_QUADS);

            glColor3ub(16,221,17);
            glVertex2f(getX(15),getY(-15));
            glVertex2f(getX(100),getY(-15));
            glVertex2f(getX(100),getY(5));
            glVertex2f(getX(20),getY(5));

            drawCircle(0.1,0.01,0.03);
            drawCircle(0.15,0.01,0.03);
            drawCircle(0.2,-.01,0.03);
            drawCircle(0.05,-.01,0.03);
            drawCircle(0.1,0.01,0.03);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3,0.22,0);
        glBegin(GL_QUADS);

            glColor3ub(16,221,17);
            glVertex2f(getX(15),getY(-15));
            glVertex2f(getX(100),getY(-15));
            glVertex2f(getX(100),getY(5));
            glVertex2f(getX(20),getY(5));

            drawCircle(0.1,0.01,0.03);
            drawCircle(0.15,0.01,0.03);
            drawCircle(0.2,-.01,0.03);
            drawCircle(0.05,-.01,0.03);
            drawCircle(0.1,0.01,0.03);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7,0.22,0);
        glBegin(GL_QUADS);

            glColor3ub(16,221,17);
            glVertex2f(getX(15),getY(-15));
            glVertex2f(getX(100),getY(-15));
            glVertex2f(getX(100),getY(5));
            glVertex2f(getX(20),getY(5));

            drawCircle(0.1,0.01,0.03);
            drawCircle(0.15,0.01,0.03);
            drawCircle(0.2,-.01,0.03);
            drawCircle(0.05,-.01,0.03);
            drawCircle(0.1,0.01,0.03);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.1,0.22,0);
        glBegin(GL_QUADS);

            glColor3ub(16,221,17);
            glVertex2f(getX(15),getY(-15));
            glVertex2f(getX(100),getY(-15));
            glVertex2f(getX(100),getY(5));
            glVertex2f(getX(20),getY(5));

            drawCircle(0.1,0.01,0.03);
            drawCircle(0.15,0.01,0.03);
            drawCircle(0.2,-.01,0.03);
            drawCircle(0.05,-.01,0.03);
            drawCircle(0.1,0.01,0.03);
        glEnd();
    glPopMatrix();
}
void cloud()
{
   glColor3ub(255,254,250);
    glPushMatrix();
    glTranslatef(cloudSpeed1,0,0);
        drawCircle(0.8,0.8,0.07);
        drawCircle(0.8,0.7,0.07);
        drawCircle(0.7,0.77,0.05);
        drawCircle(0.9,0.77,0.05);
        drawCircle(0.7,0.73,0.05);
        drawCircle(0.9,0.73,0.05);

    glPopMatrix();
         glColor3ub(255,254,250);
    glPushMatrix();
    glTranslatef(cloudSpeed2,-0.1,0);
        drawCircle(0.8,0.8,0.07);
        drawCircle(0.8,0.7,0.07);
        drawCircle(0.7,0.77,0.05);
        drawCircle(0.9,0.77,0.05);
        drawCircle(0.7,0.73,0.05);
        drawCircle(0.9,0.73,0.05);

    glPopMatrix();
    glColor3ub(255,254,250);
    glPushMatrix();
    glTranslatef(cloudSpeed3,0,0);
        drawCircle(0.8+.3,0.8+.2,0.07);
        drawCircle(0.8+.3,0.7+.2,0.07);
        drawCircle(0.7+.3,0.77+.2,0.05);
        drawCircle(0.9+.3,0.77+.2,0.05);
        drawCircle(0.7+.3,0.73+.2,0.05);
        drawCircle(0.9+.3,0.73+.2,0.05);

    glPopMatrix();
}
void carsAndBus()
{
    glPushMatrix();
      glTranslatef(carSpeed3-0.1,.18,0);
        glBegin(GL_QUADS);
            glColor3ub(2,216,19);
            glVertex2f(getX(0),getY(-28));
            glVertex2f(getX(80),getY(-28));
            glVertex2f(getX(80),getY(-8));
            glVertex2f(getX(0),getY(-8));

            glVertex2f(getX(0),getY(-8));
            glVertex2f(getX(60),getY(-8));
            glVertex2f(getX(50),getY(10));
            glVertex2f(getX(10),getY(10));

            glColor3ub(159,206,208);
            glVertex2f(getX(0+3),getY(-8));
            glVertex2f(getX(60-3),getY(-8));
            glVertex2f(getX(50-3),getY(10-3));
            glVertex2f(getX(10+3),getY(10-3));

            glColor3ub(0,0,0);
            drawCircle(0.04,-0.065,.03);
            drawCircle(0.12,-0.065,.03);
        glEnd();
    glPopMatrix();
        glPushMatrix();
        glTranslatef(carSpeed2+0.5,.08,0);
        glBegin(GL_QUADS);
            glColor3ub(23,16,249);
            glVertex2f(getX(0),getY(-28));
            glVertex2f(getX(80),getY(-28));
            glVertex2f(getX(80),getY(-8));
            glVertex2f(getX(0),getY(-8));

            glVertex2f(getX(20),getY(-8));
            glVertex2f(getX(80),getY(-8));
            glVertex2f(getX(70),getY(10));
            glVertex2f(getX(30),getY(10));

            glColor3ub(159,206,208);
            glVertex2f(getX(20+3),getY(-8));
            glVertex2f(getX(80-3),getY(-8));
            glVertex2f(getX(70-3),getY(10-3));
            glVertex2f(getX(30+3),getY(10-3));

            glColor3ub(0,0,0);
            drawCircle(0.04,-0.065,.03);
            drawCircle(0.12,-0.065,.03);
        glEnd();
    glPopMatrix();
    glPushMatrix();
     glTranslatef(carSpeed1,0,0);
        glBegin(GL_QUADS);
            glColor3ub(232,216,19);
            glVertex2f(getX(0),getY(-28));
            glVertex2f(getX(80),getY(-28));
            glVertex2f(getX(80),getY(-8));
            glVertex2f(getX(0),getY(-8));

            glVertex2f(getX(20),getY(-8));
            glVertex2f(getX(80),getY(-8));
            glVertex2f(getX(70),getY(10));
            glVertex2f(getX(30),getY(10));

            glColor3ub(159,206,208);
            glVertex2f(getX(20+3),getY(-8));
            glVertex2f(getX(80-3),getY(-8));
            glVertex2f(getX(70-3),getY(10-3));
            glVertex2f(getX(30+3),getY(10-3));

            glColor3ub(0,0,0);
            drawCircle(0.04,-0.065,.03);
            drawCircle(0.12,-0.065,.03);
        glEnd();
    glPopMatrix();
    ///bus////////////////////////
glPushMatrix();
     glTranslatef(busSpeed1-0.8,0.0,0);
        glBegin(GL_QUADS);
            glColor3ub(232,26,9);
            glVertex2f(getX(20),getY(-28));
            glVertex2f(getX(150),getY(-28));
            glVertex2f(getX(150),getY(30));
            glVertex2f(getX(20),getY(30));

            glVertex2f(getX(0),getY(-28));
            glVertex2f(getX(20),getY(-28));
            glVertex2f(getX(20),getY(30));
            glVertex2f(getX(0),getY(0));



            glColor3ub(159,206,208);
            glVertex2f(getX(20+5),getY(-5));
            glVertex2f(getX(150-5),getY(-5));
            glVertex2f(getX(150-5),getY(30-5));
            glVertex2f(getX(20+5),getY(30-5));

            glVertex2f(getX(0+5),getY(-5));
            glVertex2f(getX(20-3),getY(-5));
            glVertex2f(getX(20-1),getY(30-5));
            glVertex2f(getX(0+5),getY(0-5));


            glColor3ub(0,0,0);
            drawCircle(0.06,-0.065,.03);
            drawCircle(0.25,-0.065,.03);
        glEnd();
    glPopMatrix();
}
void lightsUp()
{
     ///traffic light//////////////////////////////
    glPushMatrix();
    glTranslatef(-0.1,0.3,0);
        glBegin(GL_QUADS);

            glColor3ub(46,46,46);
            glVertex2f(getX(0-3),getY(-20));
            glVertex2f(getX(20+3),getY(-20));
            glVertex2f(getX(20+3),getY(30));
            glVertex2f(getX(0-3),getY(30));

            glColor3ub(22,26,9);
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(15),getY(-40));
            glVertex2f(getX(15),getY(-20));
            glVertex2f(getX(5),getY(-20));

            glColor3ub(trafficColour,0,0);
            drawCircle(0.02,0.05,0.015);
            glColor3ub(trafficColour,trafficColour,0);
            drawCircle(0.02,0.01,0.015);
            glColor3ub(0,trafficColour2,0);
            drawCircle(0.02,-0.03,0.015);
        glEnd();
    glPopMatrix();

///Road light  up //////////////////////////////
    glPushMatrix();
    glTranslatef(-0.4,0.3,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,0.3,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8,0.3,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2,0.3,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,0.3,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();
}
void lightUp()
{
    glColor3ub(251,247,164);
    glPushMatrix();
        glTranslatef(0.21,0.2,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.51,0.2,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.81,0.2,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.39,0.2,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.79,0.2,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
}
void lightsDown()
{
    ///traffic light 2  //////////////////////////////
    glPushMatrix();
    glTranslatef(0.05,0,0);
        glBegin(GL_QUADS);

            glColor3ub(46,46,46);
            glVertex2f(getX(0-3),getY(-20));
            glVertex2f(getX(20+3),getY(-20));
            glVertex2f(getX(20+3),getY(30));
            glVertex2f(getX(0-3),getY(30));

            glColor3ub(22,26,9);
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(15),getY(-40));
            glVertex2f(getX(15),getY(-20));
            glVertex2f(getX(5),getY(-20));

            glColor3ub(trafficColour2,0,0);
            drawCircle(0.02,0.05,0.015);
            glColor3ub(trafficColour2,trafficColour2,0);
            drawCircle(0.02,0.01,0.015);
            glColor3ub(0,trafficColour,0);
            drawCircle(0.02,-0.03,0.015);
        glEnd();
    glPopMatrix();
    ///Road light  //////////////////////////////
    glPushMatrix();
    glTranslatef(-0.3,0,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7,0,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0,0,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3,0,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6,0,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(.9,0,0);
        glBegin(GL_QUADS);

            glColor3ub(164,172,172);
            glVertex2f(getX(0),getY(5));
            glVertex2f(getX(20),getY(10));
            glVertex2f(getX(20),getY(15));
            glVertex2f(getX(0),getY(10));

            glVertex2f(getX(0),getY(-40));
            glVertex2f(getX(5),getY(-40));
            glVertex2f(getX(5),getY(10));
            glVertex2f(getX(0),getY(10));

            glColor3ub(255,255,RoadLightB);
            drawCircle(0.04,0.01,0.015);
        glEnd();
    glPopMatrix();
}
void lightDown()
{
    glColor3ub(251,247,164);
    glPushMatrix();
        glTranslatef(0.31,-0.1,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.61,-0.1,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.91,-0.1,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.29,-0.1,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.69,-0.1,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.99,-0.1,0);
        glBegin(GL_QUADS);
            glVertex2f(getX(0),getY(0));
            glVertex2f(getX(30),getY(0));
            glVertex2f(getX(20),getY(45));
            glVertex2f(getX(10),getY(45));
        glEnd();
    glPopMatrix();
}
void ship()
{
    glPushMatrix();
     glTranslatef(shipSpeed1,0,0);
        glBegin(GL_QUADS);
            glColor3ub(s1R,s1G,s1B);
            glVertex2f(getX(0),getY(-250));
            glVertex2f(getX(200),getY(-250));
            glVertex2f(getX(250),getY(-200));
            glVertex2f(getX(-100),getY(-200));

            glColor3ub(s2R,s2G,s2B);
            glVertex2f(getX(0),getY(-200));
            glVertex2f(getX(200),getY(-200));
            glVertex2f(getX(200),getY(-180));
            glVertex2f(getX(0),getY(-180));

            glColor3ub(s3R,s3G,s3B);
            glVertex2f(getX(20),getY(-180));
            glVertex2f(getX(50),getY(-180));
            glVertex2f(getX(50),getY(-120));
            glVertex2f(getX(20),getY(-120));

            glVertex2f(getX(20+120),getY(-180));
            glVertex2f(getX(50+120),getY(-180));
            glVertex2f(getX(50+120),getY(-120));
            glVertex2f(getX(20+120),getY(-120));

            glVertex2f(getX(20+60),getY(-180));
            glVertex2f(getX(50+60),getY(-180));
            glVertex2f(getX(50+60),getY(-120));
            glVertex2f(getX(20+60),getY(-120));


        glEnd();
    glPopMatrix();
}
void rainFall()
{
    glPushMatrix();
        glTranslatef(rainSpeed,(-rainSpeed)+0,0);
        glColor3ub(255,255,255);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();

        glTranslatef(rainSpeed,(-rainSpeed)+.25,0);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();

        glTranslatef(rainSpeed,(-rainSpeed)+.3,0);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();

        glTranslatef(rainSpeed,(-rainSpeed)+.31,0);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();
    glPopMatrix();

    glTranslatef(rainSpeed,(-rainSpeed)+-.25,0);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();

        glTranslatef(rainSpeed,(-rainSpeed)+-.3,0);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();

        glTranslatef(rainSpeed,(-rainSpeed)+-.31,0);
        glBegin(GL_LINES);
        glVertex2f(getX(20),getY(20));
        glVertex2f(getX(0),getY(80));
        glVertex2f(getX(70),getY(20));
        glVertex2f(getX(50),getY(80));
        glVertex2f(getX(120),getY(20));
        glVertex2f(getX(100),getY(80));
        glVertex2f(getX(170),getY(20));
        glVertex2f(getX(150),getY(80));
        glVertex2f(getX(220),getY(20));
        glVertex2f(getX(200),getY(80));
        glVertex2f(getX(270),getY(20));
        glVertex2f(getX(250),getY(80));
        glVertex2f(getX(320),getY(20));
        glVertex2f(getX(300),getY(80));
        glVertex2f(getX(370),getY(20));
        glVertex2f(getX(350),getY(80));
        glVertex2f(getX(420),getY(20));
        glVertex2f(getX(400),getY(80));
        glVertex2f(getX(470),getY(20));
        glVertex2f(getX(450),getY(80));
        glVertex2f(getX(-20),getY(20));
        glVertex2f(getX(-50),getY(80));
        glVertex2f(getX(-70),getY(20));
        glVertex2f(getX(-100),getY(80));
        glVertex2f(getX(-120),getY(20));
        glVertex2f(getX(-150),getY(80));
        glVertex2f(getX(-170),getY(20));
        glVertex2f(getX(-200),getY(80));
        glVertex2f(getX(-220),getY(20));
        glVertex2f(getX(-250),getY(80));
        glVertex2f(getX(-270),getY(20));
        glVertex2f(getX(-300),getY(80));
        glVertex2f(getX(-320),getY(20));
        glVertex2f(getX(-350),getY(80));
        glVertex2f(getX(-370),getY(20));
        glVertex2f(getX(-400),getY(80));
        glVertex2f(getX(-420),getY(20));
        glVertex2f(getX(-450),getY(80));
        glVertex2f(getX(-470),getY(20));
        glVertex2f(getX(-500),getY(80));
        glEnd();
    glPopMatrix();
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    sky();
    if(night==1)
    {
        star();
    }
    water();
    cloud();
    building();
    Bush();
    Road();
    if(night==1)
    {
        lightUp();
    }
    lightsUp();
    carsAndBus();
    if(night==1)
    {
        lightDown();
    }
    lightsDown();
    ship();
    if(rain==1)
    {
        rainFall();
    }
    glutSwapBuffers();
}

float frameLimit(float x)
{
    if(x>getX(1000))
       x = -1 * getX(1000);


    if(x<getX(-1000))
       x = 1 * getX(1000);


       return x;

}
void update(int value)
{
    cloudSpeed1+=0.002f;
    cloudSpeed1=frameLimit(cloudSpeed1);
    //movementX=frameLimit(movementX);
    cloudSpeed2+=0.005f;
    cloudSpeed2=frameLimit(cloudSpeed2);

    cloudSpeed3+=0.01f;
    cloudSpeed3=frameLimit(cloudSpeed3);

    rainSpeed+=0.02f;
    if(rainSpeed>getX(30))
       rainSpeed = -1 * getX(30);


    if(rainSpeed<getY(-30))
       rainSpeed = 1 * getY(30);
    //rainSpeed=frameLimit(rainSpeed);

    if(trafficColour==0)
    {
        //cout<<"if"<<carSpeed1<<endl;
        if((carSpeed1>=0.120002 && carSpeed1<=0.160002 ))
        {
            saveSpeed1=carSpeed1;
            carSpeed1=0.160002f;
        }
        else
        {
            carSpeed1-=0.01f;
        }
    }
    else
        {
            carSpeed1-=0.01f;
        }
////////////////////////////////////////////////////
        if(trafficColour==0)
    {

        if((carSpeed2>=-0.360002 && carSpeed2<=-0.340002))
        {
            saveSpeed2=carSpeed2;
            carSpeed2=-0.350002f;
        }
        else
        {
            carSpeed2-=0.013f;
        }
    }
    else
        {

            carSpeed2-=0.013f;
        }
        //////////////////////////////////
        if(trafficColour==0)
    {

        if(busSpeed1>=0.900001 && busSpeed1<=0.930001)
        {
            saveSpeed3=busSpeed1;
            busSpeed1=0.920001f;
        }
        else
        {
            busSpeed1-=0.015f;
        }
    }
    else
        {

            busSpeed1-=0.015f;
        }
        //////////////
         if(trafficColour2==0)
    {
        cout<<trafficColour2<<endl;
        if(carSpeed3>=-.220001 && carSpeed3<=-.200001)
        {
            saveSpeed4=carSpeed3;
            carSpeed3=-.20001;
        }
        else
        {
            carSpeed3+=0.02f;
        }
    }
    else
        {

            carSpeed3+=0.02f;
        }
    if(night==0)
    {
        carSpeed1=frameLimit(carSpeed1);
        carSpeed2=frameLimit(carSpeed2);
        carSpeed3=frameLimit(carSpeed3);
    }
    busSpeed1=frameLimit(busSpeed1);
    shipSpeed1-=0.001f;
    shipSpeed1=frameLimit(shipSpeed1);

    glutPostRedisplay();
    glutTimerFunc(20,update,0);


}
void keyboard(unsigned char key, int x, int y) {
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key) {
      case 27:     /// ESC
         exit(0);
         break;
         case 49:     /// 1
         trafficColour=255;
         trafficColour2=0;
         break;
         case 50:     /// 2
         trafficColour=0;
         trafficColour2=255;
         break;

         case 78:     /// N
         skyR1=85,skyG1=100,skyB1=96,skyR2=4,skyG2=27,skyB2=51;
         RoadLightB=0;
         waterR=0,waterG=0,waterB=0;
         b1R=158,b1G=141,b1B=90;
         window1R=255,window1G=255,window1B=0;
         window2R=255,window2G=255,window2B=0;
         s1R=137,s1G=99,s1B=88,s2R=107,s2G=107,s2B=88,s3R=146,s3G=172,s3B=140;
         night=1;
         sndPlaySound( "C:\\Users\\Rubyet\\Documents\\cpp\\my project\\Nightime-SoundBible.com-952309297.wav", SND_ASYNC|SND_LOOP );
         break;

         case 68:     /// D
         skyR1=255,skyG1=255,skyB1=239,skyR2=131,skyG2=175,skyB2=224;
         RoadLightB=255;
         waterR=18,waterG=44,waterB=71;
         b1R=200,b1G=166,b1B=87;
         window1R=177,window1G=249,window1B=252;
         window2R=249,window2G=252,window2B=133;
         s1R=159,s1G=94,s1B=66,s2R=115,s2G=115,s2B=95,s3R=142,s3G=193,s3B=119;
         night=0;
         sndPlaySound( "C:\\Users\\Rubyet\\Documents\\cpp\\my project\\street-traffic-2.wav", SND_ASYNC|SND_LOOP );
         break;
         case 82:     /// R
            rain=1;
            sndPlaySound( "C:\\Users\\Rubyet\\Documents\\cpp\\my project\\rain-02.wav", SND_ASYNC|SND_LOOP );
         break;
         case 83:     /// S
            rain=0;
            if(night==0)
            {
                sndPlaySound( "C:\\Users\\Rubyet\\Documents\\cpp\\my project\\street-traffic-2.wav", SND_ASYNC|SND_LOOP );
            }
            else if(night==1)
            {
                sndPlaySound( "C:\\Users\\Rubyet\\Documents\\cpp\\my project\\Nightime-SoundBible.com-952309297.wav", SND_ASYNC|SND_LOOP );
            }

         break;

   }
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,800);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keyboard);
//	glutPassiveMotionFunc(mouseMotion);
	glutTimerFunc(20,update,0);
	sndPlaySound( "C:\\Users\\Rubyet\\Documents\\cpp\\my project\\street-traffic-2.wav",SND_ASYNC|SND_LOOP);
	glutMainLoop();
	return 0;
}

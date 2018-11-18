#include <stdio.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<map>
#include <GL/glut.h>
using namespace std;
void myMouse(int b, int s, int x1, int y1);
void myMouseMove(int x1, int y1);
GLfloat UpwardsScrollVelocity = -10.0;
float view = 10.0;
char quote[6][80];
int numberOfQuotes = 0;
bool done=false;
void timeTick(void);
void welcome(void);
void RenderToDisplay();
void myDisplayFunction(void);
void haircut(void);
void or2(void);
void shaving(void);
void border(void);
void drawblank1();
void dress(void);
void myDisplay(void);
void myInit (void);
void DrawRazor();
void mouse(int mouse, int state, int a, int b);
void Face(void);
void keyboardown(unsigned char key, int x1, int y1);
void keyboardown1(unsigned char key, int x1, int y1);
void hair(void);
void reshape(int w, int h);
void leap(void);
void collar(void);
int move_unit=10;
bool move_razor=false;
void drawblank();
void DrawScissor();
void razorholder(void);
void myDisplayFunc();
int winner(char a);
static int x=400,double_shave=0,y=200,i=0,m=410,n=110;
int blank[100000][2],count1[10000];
bool razor=false;
bool scissor =false;
static int dollar=500;
int play();
std::map < std::pair<int,int> , int > Scores,dollarsdeduct,dollarsadd;
std::map<std::pair<int, int>, int >::iterator res;
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Start");
    glutDisplayFunc(myDisplayFunc);
     myInit ();
    //glutReshapeFunc(reshape);
     //glutMouseFunc(myMouse);
     glutKeyboardFunc(keyboardown);
    //glutPassiveMotionFunc(myMouseMove);

    //glutSpecialFunc(keyboardown);
    glutMainLoop();
     cout<<dollarsdeduct.size()*5<<endl;
    return 0;
}
void myDisplayFunc(){
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPointSize(20.0);
    welcome();
    haircut();
    or2();
    shaving();
    border();

	if(razor==true||scissor==true){
        play();
        glutPostRedisplay();
	}

	glFlush();


}
int play(){
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1366, 768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("my first attempt");
    glutDisplayFunc(myDisplay);
    myInit ();
    //glutReshapeFunc(reshape);
    glutMouseFunc(myMouse);
	//glutSpecialFunc(keyboardown);

    if(razor==true)
        glutKeyboardFunc(keyboardown);
    else if(scissor==true)
        glutKeyboardFunc(keyboardown1);
    glutPassiveMotionFunc(myMouseMove);

    //glutSpecialFunc(keyboardown);
    glutMainLoop();
    return 0;
}
void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    razorholder();
    dress();
    hair();
    Face();
    if(done==true){
        winner('1');
    }
    if(razor==true)
        drawblank();
    else if(scissor==true)
        drawblank1();

    DrawRazor();
    DrawScissor();
    leap();
    glRasterPos2i(20, 400);
    glColor4b(255, 255, 255, 255);
    int i;
    if(razor==true)
    i=dollarsadd.size()*10-dollarsdeduct.size()*5+50;
    else
    i=500-dollarsdeduct.size()*5;
    char buffer[10];
    itoa (i,buffer,10);
    for(int i=0;i<3;i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[i]);
      //cout<<dollarsadd.size()*10-dollarsdeduct.size()*5<<endl;
      // cout<<dollarsdeduct.size()*5<<endl;

    glFlush();
    //glutSwapBuffers();
}
void dress(void){
    glColor3f(0,0,0.18);
    glBegin(GL_POLYGON);
    int r=100,xc=225,yc=30;
    int P=1-r;
    int x1=0;
    int y1=r;
    while(x1<=y1){
          if(P<0){
                x1=x1+1;
                P=P+(2*x1)+1;
                        }
           else{
                x1=x1+1;
                y1=y1-1;
                P=P+(2*x1)-(2*y1)+1;
            }
            glVertex2i(xc+x1,yc+y1);
            glVertex2i(xc+y1,yc+x1);
            glVertex2i(xc-y1,yc+x1);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc-x1,yc-y1);
            glVertex2i(xc-y1,yc-x1);
            glVertex2i(xc+y1,yc-x1);
            glVertex2i(xc+x1,yc-y1);
            }
            glEnd();
}
void leap(void){
     // leap
    int rx=40,ry=20;
    int xc=230,yc=180;
    int x1=0,y1=ry;
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    int p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x1*ry*ry)<(2*y1*rx*rx)) {
            glVertex2i(xc+x1,yc-y1);
            //glVertex2i(xc-x1,yc+y1);
            //glVertex2i(xc+x1,yc+y1);
            glVertex2i(xc-x1,yc-y1);
            if(p<0) {
                    x1=x1+1;
                    p=p+(2*ry*ry*x1)+(ry*ry);
                     }
            else {
                    x1=x1+1;
                    y1=y1-1;
                    p=p+(2*ry*ry*x1+ry*ry)-(2*rx*rx*y1);
                    }
            }
            p=((float)x1+0.5)*((float)x1+0.5)*ry*ry+(y1-1)*(y1-1)*rx*rx-rx*rx*ry*ry;
            while(y1>0) {
                    glVertex2i(xc+x1,yc-y1);
                    //glVertex2i(xc-x1,yc+y1);
                    //glVertex2i(xc+x1,yc+y1);
                    glVertex2i(xc-x1,yc-y1);
                    if(p>0) {
                            y1=y1-1;
                            p=p-(2*rx*rx*y1)+(rx*rx);
                            }
                    else {
                            y1=y1-1;
                            x1=x1+1;
                            p=p+(2*ry*ry*x1)-(2*rx*rx*y1)-(rx*rx);
                            }
                }
                glEnd();

}
void hair(void){
// Hair & Bread Starts
        glColor3f(.5,0,0);
        glBegin(GL_POLYGON);
		glVertex2i(150,100);
		glVertex2i(300,100);
		glVertex2i(330,150);
		glVertex2i(350,245);
		glVertex2i(352,325);
		glVertex2i(375,410);
		glVertex2i(374,430);
		glVertex2i(350,450);
		glVertex2i(330,460);
		glVertex2i(230,430);
		glVertex2i(140,400);
		glVertex2i(115,370);
		glVertex2i(98,353);
		glVertex2i(100,335);
		glVertex2i(130,160);
		glVertex2i(140,150);
		glVertex2i(150,100);
        glEnd();
}
void Face(void){
    //face
    glColor3f (1.0, 0.84, 0.76);
    glPointSize(4.0);
    glBegin(GL_POLYGON);
    glVertex2i(140, 200);
    glVertex2i(325, 200);
    glVertex2i(330, 310);
    glVertex2i(325, 340);
    glVertex2i(175, 380);
    glVertex2i(140, 350);
    glEnd();
    glColor3f (1.0, 0.68, 0.53);
    glPointSize(4.0);
    glBegin(GL_POLYGON);
    glVertex2i(230, 210);
    glVertex2i(250, 240);
    glVertex2i(210, 240);
    glVertex2i(220, 225);
    glEnd();
    //left EYE
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    int r=25,xc=180,yc=290;
    int P=1-r;
    int x1=0;
    int y1=r;
    while(x1<=y1){
          if(P<0){
                x1=x1+1;
                P=P+(2*x1)+1;
                        }
           else{
                x1=x1+1;
                y1=y1-1;
                P=P+(2*x1)-(2*y1)+1;
            }
            glVertex2i(xc+x1,yc+y1);
            glVertex2i(xc+y1,yc+x1);
            glVertex2i(xc-y1,yc+x1);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc-x1,yc-y1);
            glVertex2i(xc-y1,yc-x1);
            glVertex2i(xc+y1,yc-x1);
            glVertex2i(xc+x1,yc-y1);
            }
            glEnd();
    //right EYE
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    r=25,xc=280,yc=290;
    P=1-r;
    x1=0;
    y1=r;
    while(x1<=y1){
          if(P<0){
                x1=x1+1;
                P=P+(2*x1)+1;
                        }
           else{
                x1=x1+1;
                y1=y1-1;
                P=P+(2*x1)-(2*y1)+1;
            }
            glVertex2i(xc+x1,yc+y1);
            glVertex2i(xc+y1,yc+x1);
            glVertex2i(xc-y1,yc+x1);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc-x1,yc-y1);
            glVertex2i(xc-y1,yc-x1);
            glVertex2i(xc+y1,yc-x1);
            glVertex2i(xc+x1,yc-y1);
            }
        glEnd();
    //right eye ball
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    r=7,xc=280,yc=290;
    P=1-r;
    x1=0;
    y1=r;
    while(x1<=y1){
          if(P<0){
                x1=x1+1;
                P=P+(2*x1)+1;
                        }
           else{
                x1=x1+1;
                y1=y1-1;
                P=P+(2*x1)-(2*y1)+1;
            }
            glVertex2i(xc+x1,yc+y1);
            glVertex2i(xc+y1,yc+x1);
            glVertex2i(xc-y1,yc+x1);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc-x1,yc-y1);
            glVertex2i(xc-y1,yc-x1);
            glVertex2i(xc+y1,yc-x1);
            glVertex2i(xc+x1,yc-y1);
            }
            glEnd();
    //left eye ball
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    r=7,xc=180,yc=290;
    P=1-r;
    x1=0;
    y1=r;
    while(x1<=y1){
          if(P<0){
                x1=x1+1;
                P=P+(2*x1)+1;
                        }
           else{
                x1=x1+1;
                y1=y1-1;
                P=P+(2*x1)-(2*y1)+1;
            }
            glVertex2i(xc+x1,yc+y1);
            glVertex2i(xc+y1,yc+x1);
            glVertex2i(xc-y1,yc+x1);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc-x1,yc-y1);
            glVertex2i(xc-y1,yc-x1);
            glVertex2i(xc+y1,yc-x1);
            glVertex2i(xc+x1,yc-y1);
            }
            glEnd();

        // eye brow
    int rx=30,ry=15;
    xc=180,yc=320;
    x1=0,y1=ry;
    glColor3f (0.5, 0.0, 0.0);
    glBegin(GL_POINTS);
    int p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x1*ry*ry)<(2*y1*rx*rx)) {
            //glVertex2i(xc+x,yc-y);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc+x1,yc+y1);
            //glVertex2i(xc-x,yc-y);
            if(p<0) {
                    x1=x1+1;
                    p=p+(2*ry*ry*x1)+(ry*ry);
                     }
            else {
                    x1=x1+1;
                    y1=y1-1;
                    p=p+(2*ry*ry*x1+ry*ry)-(2*rx*rx*y1);
                    }
            }
            p=((float)x1+0.5)*((float)x1+0.5)*ry*ry+(y1-1)*(y1-1)*rx*rx-rx*rx*ry*ry;
            while(y1>0) {
                   // glVertex2i(xc+x,yc-y);
                    glVertex2i(xc-x1,yc+y1);
                    glVertex2i(xc+x1,yc+y1);
                   // glVertex2i(xc-x,yc-y);
                    if(p>0) {
                            y1=y1-1;
                            p=p-(2*rx*rx*y1)+(rx*rx);
                            }
                    else {
                            y1=y1-1;
                            x1=x1+1;
                            p=p+(2*ry*ry*x1)-(2*rx*rx*y1)-(rx*rx);
                            }
                }
                glEnd();

         // right eye bru
    rx=30,ry=15;
    xc=280,yc=320;
    x1=0,y1=ry;
    glColor3f (0.5, 0.0, 0.0);
    glBegin(GL_POINTS);
    p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x1*ry*ry)<(2*y1*rx*rx)) {
            //glVertex2i(xc+x,yc-y);
            glVertex2i(xc-x1,yc+y1);
            glVertex2i(xc+x1,yc+y1);
            //glVertex2i(xc-x,yc-y);
            if(p<0) {
                    x1=x1+1;
                    p=p+(2*ry*ry*x1)+(ry*ry);
                     }
            else {
                    x1=x1+1;
                    y1=y1-1;
                    p=p+(2*ry*ry*x1+ry*ry)-(2*rx*rx*y1);
                    }
            }
            p=((float)x1+0.5)*((float)x1+0.5)*ry*ry+(y1-1)*(y1-1)*rx*rx-rx*rx*ry*ry;
            while(y1>0) {
                   // glVertex2i(xc+x,yc-y);
                    glVertex2i(xc-x1,yc+y1);
                    glVertex2i(xc+x1,yc+y1);
                   // glVertex2i(xc-x,yc-y);
                    if(p>0) {
                            y1=y1-1;
                            p=p-(2*rx*rx*y1)+(rx*rx);
                            }
                    else {
                            y1=y1-1;
                            x1=x1+1;
                            p=p+(2*ry*ry*x1)-(2*rx*rx*y1)-(rx*rx);
                            }
                }
                glEnd();
}
void razorholder(void){
    int m0=410,n0=110;
     glColor3f(0.75, 0.75, 0.75);// scissor
     glBegin(GL_POLYGON);
     glVertex2i(m0-11,n0+2);
     glVertex2i(m0+24,n0+45);
     glVertex2i(m0-16,n0+5);
     glVertex2i(m0-11,n0+2);
     glEnd();
     glColor3f(0.75, 0.75, 0.75);
     glBegin(GL_POLYGON);
     glVertex2i(m0, n0);
     glVertex2i(m0+14,n0+65);
     glVertex2i(m0-6,n0);
     glVertex2i(m0,n0);
     glEnd();
    glColor3f(.5,.5,0.75);
    glBegin(GL_POLYGON);
    glVertex2i(388,110);
    glVertex2i(435,110);
    glVertex2i(435,180);
    glVertex2i(388,180);
    glEnd();
    glColor3f(1,.5,0.75);
    glBegin(GL_POLYGON);
    glVertex2i(388,180);
    glVertex2i(435,180);
    glVertex2i(435,230);
    glVertex2i(388,230);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2i(388,230);
    glVertex2i(411,240);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2i(435,230);
    glVertex2i(411,240);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glVertex2i(411,240);
    glEnd();

    glColor3f (0.75, 0.75, 0.75);// razor
    int x0=400,y0=200;
    glBegin(GL_POLYGON);
    glVertex2i(x0, y0);
    glVertex2i(x0+20, y0+20);
    glVertex2i(x0+15, y0+25);
    glVertex2i(x0-5, y0+5);
    glEnd();
    glColor3f (0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2i(x0+3, y0-3);
    glVertex2i(x0+23, y0+17);
    glVertex2i(x0+20, y0+20);
    glVertex2i(x0, y0);
    glEnd();
    glColor3f (0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2i(x0+25, y0-15);
    glVertex2i(x0+30, y0-12);
    glVertex2i(x0+11, y0+15);
    glVertex2i(x0+6, y0+13);
    glEnd();

}
void DrawRazor(){


    glColor3f (0.4, 0, 1.2);
    glPointSize(4.0);
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x+20, y+20);
    glVertex2i(x+15, y+25);
    glVertex2i(x-5, y+5);
    glEnd();
    glColor3f (1.0, 0, 1.2);
    glBegin(GL_POLYGON);
    glVertex2i(x+3, y-3);
    glVertex2i(x+23, y+17);
    glVertex2i(x+20, y+20);
    glVertex2i(x, y);
    glEnd();
    glColor3f (0.4, 0, 1.2);
    glBegin(GL_POLYGON);
    glVertex2i(x+25, y-15);
    glVertex2i(x+30, y-12);
    glVertex2i(x+11, y+15);
    glVertex2i(x+6, y+13);
    glEnd();

}
void DrawScissor(){
// Scissor
        glColor3f(1.0, 0, 1.2);
        glBegin(GL_POLYGON);
		glVertex2i(m-11,n+2);
		glVertex2i(m+24,n+45);
		glVertex2i(m-16,n+5);
		glVertex2i(m-11,n+2);

        glEnd();

        glColor3f(0.4, 0.2, 1.8);
        glBegin(GL_POLYGON);
		glVertex2i(m, n);
		glVertex2i(m+14,n+65);
		glVertex2i(m-6,n);
		glVertex2i(m,n);

        glEnd();
}
void reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 3200);
	glMatrixMode(GL_MODELVIEW);
}
void drawblank(){
    int c=i;
   // cout<<c<<endl;
    for(int j=0;j<c;j++){

        int a = blank[j][0],b=blank[j][1];
        if(b<=200&&b>=100&&a>=125&&a<=335){
            if(b>=150&&b<=200){
                glColor3f (1.0, 0.84, 0.76);
                glBegin(GL_POLYGON);
                glVertex2i(a,b);// cutting the brear
                glVertex2i(a+10,b);
                glVertex2i(a+10,b+10);
                glVertex2i(a,b+10);
                glEnd();
               if(count1[j]>=1){
                    glColor3f(1,0,0);// shaving the bear three times the face has blood on it
                    glBegin(GL_POINTS);
                    glVertex2i(a+2,b+2);
                    glVertex2i(a+5,b+4);
                    glEnd();
                    dollarsdeduct.insert(make_pair(make_pair(a,b),5));
                    // point deducted if blood is coming and mapping the deducted point
                }
                else{
                     dollarsadd.insert(make_pair(make_pair(a,b),5));
                }

                    // otherwise points are added
            }
            else{
                dollarsadd.insert(make_pair(make_pair(a,b),5));
            if(a>=205&&a<=255)
                glColor3f(1.0, 0.84, 0.76);// neck color
            else
                glColor3f(1,1,.5); // dress color
            glBegin(GL_POLYGON);
            glVertex2i(a,b);// cutting the brear without the black dots
            glVertex2i(a+10,b);
            glVertex2i(a+10,b+10);
            glVertex2i(a,b+10);
            glEnd();
            }

        }
    }
}
void drawblank1(){
    int c=i;
   // cout<<c<<endl;
    for(int j=0;j<c;j++){

        int a = blank[j][0],b=blank[j][1];
                if(a>=130&&a<=175&&b>=350&&b<=380){
                    glColor3f (1.0, 0.84, 0.76);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the hair
                    glVertex2i(a+10,b);
                    glVertex2i(a+10,b+10);
                    glVertex2i(a,b+10);
                    glEnd();
                }
                if(a>=175&&a<=330&&b>=310&&b<=380){
                    glColor3f (1.0, 0.84, 0.76);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the hair
                    glVertex2i(a+10,b);
                    glVertex2i(a+10,b+10);
                    glVertex2i(a,b+10);
                    glEnd();
                }
                if(a>=130&&a<=330&&b>=380&&b<=400){

                    glColor3f (1.0, 0.62, 0.62);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the hair
                    glVertex2i(a+10,b);
                    glVertex2i(a+10,b+10);
                    glVertex2i(a,b+10);
                    glEnd();
                }
                else if(a<=110&&a>=95&&b>=200&&b<=430){


                    glColor3f (1.0, 1, 0.5);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the brear
                    glVertex2i(a+20,b);
                    glVertex2i(a+20,b+20);
                    glVertex2i(a,b+20);
                    glEnd();

                }
             else if(a>=330&&a<=375&&b>=200&&b<=430){
                    glColor3f (1.0, 1, 0.5);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the brear
                    glVertex2i(a+40,b);
                    glVertex2i(a+40,b+50);
                    glVertex2i(a,b+50);
                    glEnd();
                }
                 if(a<110&&b>=200){

                    glColor3f (1.0, 1, 0.5);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the brear
                    glVertex2i(a+10,b);
                    glVertex2i(a+10,b+10);
                    glVertex2i(a,b+10);
                    glEnd();

            }
              else if(b>=400&&a>=130&&a<=330){
                    glColor3f (1.0, 1, 0.5);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the brear
                    glVertex2i(a+20,b);
                    glVertex2i(a+20,b+20);
                    glVertex2i(a,b+20);
                    glEnd();

            }
            if(a<130&&b>330&&b<380&&a>110){
                 glColor3f (1.0, 1, 0.5);
                    glBegin(GL_POLYGON);
                    glVertex2i(a,b);// cutting the brear
                    glVertex2i(a+10,b);
                    glVertex2i(a+10,b+10);
                    glVertex2i(a,b+10);
                    glEnd();
            }
            if(a>=150&&a<=210&&b>=305&&b<=335){
                dollarsdeduct.insert(make_pair(make_pair(a,b),5));
            }
             else if(a>=250&&a<=310&&b>=305&&b<=335){
                dollarsdeduct.insert(make_pair(make_pair(a,b),5));
            }

        }




}
void keyboardown(unsigned char key, int x1, int y1){
        //cout<<x<<" "<<y<<endl;
		if(key=='d'){
            x+= move_unit;
            if(x>=500)
                x=0;
            glutPostRedisplay();
		}
		else if(key=='a'){
            x-= move_unit;
            if(x<=0)
                x=500;
            glutPostRedisplay();
		}
       else if(key=='w'){
            y+= move_unit;
            if(y>=500)
                y=0;
            glutPostRedisplay();
		}

        else if(key=='s'){
            y -= move_unit;
            if(y<=0)
                y=500;
            glutPostRedisplay();
        }
        else if(key=='g'){
            blank[i][0]=x+7.5;
            blank[i][1]=y+12.5;
            res=Scores.find(make_pair(blank[i][0],blank[i][1]));
            if(res==Scores.end()){
                Scores.insert(make_pair(make_pair(blank[i][0],blank[i][1]),count1[i]));
                i++;
            }
            else{
               count1[i]++;
                Scores[make_pair(blank[i][0],blank[i][1])]=count1[i];
            }
            glutPostRedisplay();
        }
        else if(key=='r'){   // clicking r only shaving works
            razor=true;
            glutPostRedisplay();
        }
        else if(key=='t'){   // clicking t only scissor works
            scissor=true;
            glutPostRedisplay();
        }
        else if(key=='q'){
            done=true;
             glutPostRedisplay();
        }


}
void keyboardown1(unsigned char key, int x1, int y1){


		if(key=='d'){
            m+= move_unit;
            if(m>=500)
                m=0;
            glutPostRedisplay();
		}
		else if(key=='a'){
            m-= move_unit;
            if(m<=0)
                m=500;
            glutPostRedisplay();
		}
       else if(key=='w'){
            n+= move_unit;
            if(n>=500)
                n=0;
            glutPostRedisplay();
		}

        else if(key=='s'){
             n-= move_unit;
             if(n<=0)
                n=500;
            glutPostRedisplay();
        }
        else if(key=='g'){
            blank[i][0]=m+7.5;
            blank[i][1]=n+12.5;
            res=Scores.find(make_pair(blank[i][0],blank[i][1]));
            if(res==Scores.end()){
                Scores.insert(make_pair(make_pair(blank[i][0],blank[i][1]),count1[i]));
                i++;
            }
            else{
               count1[i]++;
                Scores[make_pair(blank[i][0],blank[i][1])]=count1[i];
            }
            glutPostRedisplay();
        }
         else if(key=='q'){
            done=true;
             glutPostRedisplay();
        }

}
void RenderToDisplay(){
	int l, lenghOfQuote, i;

	glTranslatef(0.0, -100, UpwardsScrollVelocity);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.1, 0.1, 0.1);



	for (l = 0; l<numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), -(l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);


		}
		glPopMatrix();
	}

}
void myDisplayFunction(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}
void welcome (void) {

        glBegin(GL_LINES);
		glColor3f (0, 0, 0);

		glVertex2i(170,360); //W
		glVertex2i(170,390);

		glVertex2i(170,360); //W
		glVertex2i(175,375);

		glVertex2i(175,375); //W
		glVertex2i(180,360);

		glVertex2i(180,360); //W
		glVertex2i(180,390);


		glVertex2i(190,360); //E
		glVertex2i(190,390);

		glVertex2i(190,390); //E
		glVertex2i(200,390);

		glVertex2i(190,360); //E
		glVertex2i(200,360);

		glVertex2i(190,375); //E
		glVertex2i(200,375);


		glVertex2i(210,360); //L
		glVertex2i(210,390);

		glVertex2i(210,360); //L
		glVertex2i(220,360);


		glVertex2i(230,360); //C
		glVertex2i(230,390);

		glVertex2i(230,360); //C
		glVertex2i(240,360);

		glVertex2i(230,390); //C
		glVertex2i(240,390);


		glVertex2i(250,360); //O
		glVertex2i(250,390);

		glVertex2i(250,390); //O
		glVertex2i(260,390);

		glVertex2i(250,360); //O
		glVertex2i(260,360);

        glVertex2i(260,360); //O
		glVertex2i(260,390);


        glVertex2i(270,360); //M
		glVertex2i(270,390);

		glVertex2i(270,390); //M
		glVertex2i(280,375);

		glVertex2i(280,375); //M
		glVertex2i(290,390);

        glVertex2i(290,390); //M
		glVertex2i(290,360);


		glVertex2i(300,360); //E
		glVertex2i(300,390);

		glVertex2i(300,390); //E
		glVertex2i(310,390);

		glVertex2i(300,360); //E
		glVertex2i(310,360);

		glVertex2i(300,375); //E
		glVertex2i(310,375);



		glEnd();
}
void haircut(void) {

        glBegin(GL_LINES);
		glColor3f (0, 0, 0);

		glVertex2i(50,300); //P
		glVertex2i(50,270);

		glVertex2i(50,300); //P
		glVertex2i(60,300);

		glVertex2i(50,285); //P
		glVertex2i(60,285);

		glVertex2i(60,300); //P
		glVertex2i(60,285);

		glVertex2i(70,270); //R
		glVertex2i(70,300);

		glVertex2i(70,285); //R
		glVertex2i(80,270);

        glVertex2i(70,300); //R
		glVertex2i(80,300);

		glVertex2i(70,285); //R
		glVertex2i(80,285);

		glVertex2i(80,300); //R
		glVertex2i(80,285);

		glVertex2i(90,300); //E
		glVertex2i(90,270);

		glVertex2i(90,300); //E
		glVertex2i(100,300);

		glVertex2i(90,285); //E
		glVertex2i(100,285);

		glVertex2i(90,270); //E
		glVertex2i(100,270);

		glVertex2i(110,300); //S
		glVertex2i(110,285);

		glVertex2i(120,285); //S
		glVertex2i(120,270);

		glVertex2i(110,300); //S
		glVertex2i(120,300);

		glVertex2i(110,285); //S
		glVertex2i(120,285);

		glVertex2i(110,270); //S
		glVertex2i(120,270);

        //----------------------

        glVertex2i(130,300); //S
		glVertex2i(130,285);

		glVertex2i(140,285); //S
		glVertex2i(140,270);

		glVertex2i(130,300); //S
		glVertex2i(140,300);

		glVertex2i(130,285); //S
		glVertex2i(140,285);

		glVertex2i(130,270); //S
		glVertex2i(140,270);

//--------------------------------
        glVertex2i(164,303); //'
		glVertex2i(166,297);

        glVertex2i(180,270); //T
		glVertex2i(180,300);

		glVertex2i(170,300); //T
		glVertex2i(190,300);

		glVertex2i(194,297); //-
		glVertex2i(196,303);

//--------------------------------

		glVertex2i(220,300); //F
		glVertex2i(220,270);

		glVertex2i(220,300); //F
		glVertex2i(230,300);

		glVertex2i(220,285); //F
		glVertex2i(230,285);

		glVertex2i(240,300); //O
		glVertex2i(240,270);

		glVertex2i(250,300); //O
		glVertex2i(250,270);

		glVertex2i(240,300); //O
		glVertex2i(250,300);

		glVertex2i(240,270); //O
		glVertex2i(250,270);

        glVertex2i(260,270); //R
		glVertex2i(260,300);

		glVertex2i(260,285); //R
		glVertex2i(270,270);

        glVertex2i(260,300); //R
		glVertex2i(270,300);

		glVertex2i(260,285); //R
		glVertex2i(270,285);

		glVertex2i(270,300); //R
		glVertex2i(270,285);

//--------------------------------

        glVertex2i(300,270); //H
		glVertex2i(300,300);

		glVertex2i(310,270); //H
		glVertex2i(310,300);

		glVertex2i(300,285); //H
		glVertex2i(310,285);

		glVertex2i(320,270); //A
		glVertex2i(325,300);

		glVertex2i(325,300); //A
		glVertex2i(330,270);

		glVertex2i(323,285); //A
		glVertex2i(328,285);

		glVertex2i(340,270); //I
		glVertex2i(340,300);

		glVertex2i(350,270); //R
		glVertex2i(350,300);

		glVertex2i(350,285); //R
		glVertex2i(360,270);

        glVertex2i(350,300); //R
		glVertex2i(360,300);

		glVertex2i(350,285); //R
		glVertex2i(360,285);

		glVertex2i(360,300); //R
		glVertex2i(360,285);

		glVertex2i(370,285); //-
		glVertex2i(380,285);

        glVertex2i(390,270); //C
		glVertex2i(390,300);

		glVertex2i(390,300); //C
		glVertex2i(400,300);

		glVertex2i(390,270); //C
		glVertex2i(400,270);

        glVertex2i(410,270); //U
		glVertex2i(410,300);

		glVertex2i(422,270); //U
		glVertex2i(422,300);

		glVertex2i(410,270); //U
		glVertex2i(422,270);

		glVertex2i(440,270); //T
		glVertex2i(440,300);

		glVertex2i(430,300); //T
		glVertex2i(450,300);

		glEnd();






//glFlush ();
}
void or2 (void) {

        glBegin(GL_LINES);
		glColor3f (0, 0, 0);

		glVertex2i(235,230); //O
		glVertex2i(235,210);

		glVertex2i(245,230); //O
		glVertex2i(245,210);

		glVertex2i(235,230); //O
		glVertex2i(245,230);

		glVertex2i(235,210); //O
		glVertex2i(245,210);

        glVertex2i(255,210); //R
		glVertex2i(255,230);

		glVertex2i(255,220); //R
		glVertex2i(265,210);

        glVertex2i(255,230); //R
		glVertex2i(265,230);

		glVertex2i(255,220); //R
		glVertex2i(265,220);

		glVertex2i(265,230); //R
		glVertex2i(265,220);


		glEnd();


//glFlush ();
}
void shaving (void) {

        glBegin(GL_LINES);
		glColor3f (0, 0, 0);

		glVertex2i(50,160); //P
		glVertex2i(50,130);

		glVertex2i(50,160); //P
		glVertex2i(60,160);

		glVertex2i(50,145); //P
		glVertex2i(60,145);

		glVertex2i(60,160); //P
		glVertex2i(60,145);

		glVertex2i(70,130); //R
		glVertex2i(70,160);

		glVertex2i(70,145); //R
		glVertex2i(80,130);

        glVertex2i(70,160); //R
		glVertex2i(80,160);

		glVertex2i(70,145); //R
		glVertex2i(80,145);

		glVertex2i(80,160); //R
		glVertex2i(80,145);

		glVertex2i(90,160); //E
		glVertex2i(90,130);

		glVertex2i(90,160); //E
		glVertex2i(100,160);

		glVertex2i(90,145); //E
		glVertex2i(100,145);

		glVertex2i(90,130); //E
		glVertex2i(100,130);

		glVertex2i(110,160); //S
		glVertex2i(110,145);

		glVertex2i(120,145); //S
		glVertex2i(120,130);

		glVertex2i(110,160); //S
		glVertex2i(120,160);

		glVertex2i(110,145); //S
		glVertex2i(120,145);

		glVertex2i(110,130); //S
		glVertex2i(120,130);

        //----------------------

        glVertex2i(130,160); //S
		glVertex2i(130,145);

		glVertex2i(140,145); //S
		glVertex2i(140,130);

		glVertex2i(130,160); //S
		glVertex2i(140,160);

		glVertex2i(130,145); //S
		glVertex2i(140,145);

		glVertex2i(130,130); //S
		glVertex2i(140,130);

//--------------------------------
        glVertex2i(166,163); //'
		glVertex2i(168,157);

        glVertex2i(175,130); //R
		glVertex2i(175,160);

		glVertex2i(175,145); //R
		glVertex2i(185,130);

        glVertex2i(175,160); //R
		glVertex2i(185,160);

		glVertex2i(175,145); //R
		glVertex2i(185,145);

		glVertex2i(185,160); //R
		glVertex2i(185,145);

		glVertex2i(192,157); //'
		glVertex2i(194,163);

//--------------------------------

		glVertex2i(220,160); //F
		glVertex2i(220,130);

		glVertex2i(220,160); //F
		glVertex2i(230,160);

		glVertex2i(220,145); //F
		glVertex2i(230,145);

		glVertex2i(240,160); //O
		glVertex2i(240,130);

		glVertex2i(250,160); //O
		glVertex2i(250,130);

		glVertex2i(240,160); //O
		glVertex2i(250,160);

		glVertex2i(240,130); //O
		glVertex2i(250,130);

        glVertex2i(260,130); //R
		glVertex2i(260,160);

		glVertex2i(260,145); //R
		glVertex2i(270,130);

        glVertex2i(260,160); //R
		glVertex2i(270,160);

		glVertex2i(260,145); //R
		glVertex2i(270,145);

		glVertex2i(270,160); //R
		glVertex2i(270,145);

//--------------------------------

		glVertex2i(300,160); //S
		glVertex2i(300,145);

		glVertex2i(310,145); //S
		glVertex2i(310,130);

		glVertex2i(300,160); //S
		glVertex2i(310,160);

		glVertex2i(300,145); //S
		glVertex2i(310,145);

		glVertex2i(300,130); //S
		glVertex2i(310,130);

		glVertex2i(320,130); //H
		glVertex2i(320,160);

		glVertex2i(330,130); //H
		glVertex2i(330,160);

		glVertex2i(320,145); //H
		glVertex2i(330,145);

		glVertex2i(340,130); //A
		glVertex2i(345,160);

		glVertex2i(345,160); //A
		glVertex2i(350,130);

		glVertex2i(343,145); //A
		glVertex2i(348,145);

		glVertex2i(360,160); //V
		glVertex2i(365,130);

		glVertex2i(365,130); //V
		glVertex2i(370,160);

		glVertex2i(380,130); //I
		glVertex2i(380,160);

		glVertex2i(390,160); //N
		glVertex2i(390,130);

		glVertex2i(402,130); //N
		glVertex2i(402,160);

		glVertex2i(390,160); //N
		glVertex2i(402,130);

		glVertex2i(412,130); //G
		glVertex2i(412,160);

		glVertex2i(412,160); //G
		glVertex2i(422,160);

		glVertex2i(412,130); //G
		glVertex2i(422,130);

		glVertex2i(422,130); //G
		glVertex2i(422,145);

		glVertex2i(422,145); //G
		glVertex2i(432,145);

		glVertex2i(432,145); //G
		glVertex2i(432,130);

		glEnd();
        //glFlush ();
}
void border (void) {

        glBegin(GL_POLYGON);
		glColor3f (0.3, 0.82, 0.4);

		glVertex2i(0,75);
		glVertex2i(512,75);
		glVertex2i(512,80);
		glVertex2i(0,80);
        glEnd();

        glBegin(GL_POLYGON);
		glColor3f (0.3, 0.82, 0.4);
		glVertex2i(0,445);
		glVertex2i(512,445);
		glVertex2i(512,450);
		glVertex2i(0,450);
		glEnd();

        glBegin(GL_POLYGON);
		glColor3f (0.3, 0.82, 0.4);
		glVertex2i(10,75);
		glVertex2i(15,75);
		glVertex2i(15,450);
		glVertex2i(10,450);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f (0.3, 0.82, 0.4);
		glVertex2i(485,75);
		glVertex2i(490,75);
		glVertex2i(490,450);
		glVertex2i(485,450);
		glEnd();
		//glFlush ();
}
void myInit (void){
    glClearColor(1.0, 1.0, 0.5, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 512.0);
    }
int winner(char a){
    strcpy(quote[0], "Customer");

	strcpy(quote[1], "Is ");
	//	strcpy_s(quote[2], );
	if(dollarsadd.size()>dollarsdeduct.size()&&razor==true&&dollarsadd.size()>=40){
        strcpy(quote[2], ":) ");
        strcpy(quote[3],"happy ");

	}

	else if(dollar>dollar-dollarsdeduct.size()*5&&scissor==true){
        strcpy(quote[2], ":) ");
        strcpy(quote[3],"happy ");
	}
    else {
        strcpy(quote[2], ":(");
        strcpy(quote[3],"sad ");
    }
    numberOfQuotes = 5;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(1360, 750);
	glutCreateWindow("Game Result");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3);

	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutIdleFunc(timeTick);
	glutMainLoop();

	return 0;
}
void timeTick(void){
	if (UpwardsScrollVelocity< -600)
		view -= 0.000011;
	if (view < 0) { view = 20; UpwardsScrollVelocity = -10.0; }
	//  exit(0);
	UpwardsScrollVelocity -= 0.1;
	glutPostRedisplay();

}
void myMouse(int b, int s, int x1, int y1) {      // mouse click callback
	if (s == GLUT_DOWN) {


		if (b == GLUT_LEFT_BUTTON&&razor==true) {
            blank[i][0]=x+7.5;
            blank[i][1]=y+12.5;
            res=Scores.find(make_pair(blank[i][0],blank[i][1]));
            if(res==Scores.end()){
                Scores.insert(make_pair(make_pair(blank[i][0],blank[i][1]),count1[i]));
                i++;
            }
            else{
               count1[i]++;
                Scores[make_pair(blank[i][0],blank[i][1])]=count1[i];
            }
                //glutPostRedisplay();
            }
            else if (b == GLUT_LEFT_BUTTON&&scissor==true) {
            blank[i][0]=m+7.5;
            blank[i][1]=n+12.5;
            res=Scores.find(make_pair(blank[i][0],blank[i][1]));
            if(res==Scores.end()){
                Scores.insert(make_pair(make_pair(blank[i][0],blank[i][1]),count1[i]));
                i++;
            }
            else{
               count1[i]++;
                Scores[make_pair(blank[i][0],blank[i][1])]=count1[i];
            }
                //glutPostRedisplay();
            }
		}

}

int mouseChange = 3;
int tempY=0;
int tempX=0;
void myMouseMove(int x1, int y1)
{


        if(razor==true){
            if(x1<1400){x=x1/4;x=x+30;}
             y=690-y1;

        }
        else if(scissor==true)
       {
            if(x1<1400){m=x1/4;m=m+30;}
            n=690-y1;

        }






	glutPostRedisplay();
}


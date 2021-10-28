#include<stdio.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1,x2,y1,y2,m,dx,dy;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);

glColor3ub(120,45,125);

    if (m>0 && m<=1){
        while ( x1<=x2 && y1<=y2){
            x1=x1+1;
            y1=y1+m;
            glVertex3f(x1,y1,0);

            printf("%d %d",x1,x2);
        }

    }

    else if(m>1){
            while(x1<=x2 && y1<=y2){
            x1=x1+(1/m);
            y1=y1+1;
           glVertex3i(x1,y1,0);
           printf("%f %f",x1,y1);
        }}

    else if(m>-1 && m<=0){
        while(x1>=x2 && y1>=y2){
        x1=x1-1;
        y1=y1-m;
        glVertex3f(x1,y1,0);
        printf("%f %f",x1,y1);
    }}
    else if(m<-1){
        while(x1>=x2 && y1>=y2){
        x1=x1-(1/m);
        y1=y1-1;
        glVertex3f(x1,y1,0);
        printf("%f %f",x1,y1);
    }}

glEnd();
glFlush ();
}


void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 100, 0, 100, -10.0, 10.0);
}




int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow ("PC_B");

printf("Enter the value of x1: ");
scanf("%f",&x1);

printf("Enter the value of y1: ");
scanf("%f",&y1);

printf("Enter the value of x2: ");
scanf("%f",&x2);

printf("Enter the value of x2: ");
scanf("%f",&y2);

//Finding the value of slope, m-
dy = y2-y1;
dx = x2-x1;
m= dy/dx;
printf("%f",m);

init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

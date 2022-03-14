#include <GL/glut.h>
#include <math.h>
void myCircle(float r)
{   ///µe¶ê: cos() sin()
    glBegin(GL_POLYGON);
    for(float angle=0; angle<=3.14159; angle+=0.1){
        glVertex2f( r*cos(angle), r*sin(angle) );
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,0,0);///red
    myCircle(0.8);

    glColor3f(1,1,0);///yellow
    myCircle(0.6);

    glColor3f(0,1,0);///green
    myCircle(0.5);

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("HW2 bonus");

    glutDisplayFunc(display);
    glutMainLoop();
}

#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * myReadOne( char * filename ){
    GLMmodel * one = NULL;
    one = glmReadOBJ( filename );///也讀好模型了
    glmUnitize(one);
    glmFacetNormals(one);
    glmVertexNormals(one, 90);///法向量都好了
    return one;
}
float dx=0, dy=0, dz=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y){
    oldX=x; oldY=y;
}
float angle[20]={};
int angleID=0;
void motion(int x, int y){
    dx += (x-oldX)/250.0; dy -= (y-oldY)/250.0;
    angle[angleID]+=(x-oldX);
    oldX=x; oldY=y;
    printf("glTranslatef(%.2f, %.2f, %.2f);\n", dx, dy, dz);
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);///紅色的
    glutSolidTeapot(0.05);

    glColor3f(1,1,1);
    glmDraw(body, GLM_SMOOTH);
    glPushMatrix();
        glTranslatef(-0.00, 0.14, 0.00);///glTranslatef(dx, dy, dx);
        glmDraw(head, GLM_SMOOTH);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.20, 0.00, 0.00);
        glRotatef(angle[0], 1, 0, 0);
        glRotatef(angle[1], 0, 0, 1);
        glTranslatef(-0.00, -0.06, 0.00);
        glmDraw(arm1, GLM_SMOOTH);
        glPushMatrix();
            glTranslatef(-0.02, -0.13, 0.00);
            ///glRotatef(dx*100, 0, 0, 1);
            glRotatef(angle[2], 1, 0, 0);
            glTranslatef(-0.02, -0.21, 0.00);
            glmDraw(hand1, GLM_SMOOTH);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
void myLighting(){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week16 review week15");
    head = myReadOne("data/head.obj");
    body = myReadOne("data/body.obj");
    arm1 = myReadOne("data/arm1.obj");
    hand1 = myReadOne("data/hand1.obj");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    myLighting();
    glutMainLoop();
}

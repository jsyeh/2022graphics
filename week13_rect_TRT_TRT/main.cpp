///week13_rect_TRT_TRT
#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button, int state, int x, int y){///mouse按下去
    oldX = x;
}
void motion(int x, int y){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身
    glPushMatrix();  ///掛的位置也改了
        glTranslatef( 0.3, 0.5, 0);///(3) 等下要掛在0.5,0.5
        glRotatef(angle, 0, 0, 1);///(2) 旋轉
        glTranslatef( -0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1,0,0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0); ///(3) 把下手肘掛在關節上
            glRotatef( angle, 0, 0, 1); ///(2) 旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1) 把下手肘的旋轉中心,放正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);///再畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}

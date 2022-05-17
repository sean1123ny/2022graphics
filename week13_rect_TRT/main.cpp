#include <GL/glut.h>
float angle=45, oldX= 0;
void mouse(int button, int state, int x, int y){
    oldX =x;
}
void motion(int x, int y ){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///讓GLUT重畫
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.5);///身體座標
    glPushMatrix();
        glTranslatef(0.3, 0.4, 0);///(3)把手臂接回身體
        glRotatef(angle, 0, 0, 1);///(2)對Z軸旋轉
        glTranslatef(-0.3, -0.4, 0);///(1)手臂旋轉中心放中心
        glColor3f(1, 0, 0);///紅色
        glRectf(0.3, 0.5, 0.7, 0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700, 700);///視窗大小
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

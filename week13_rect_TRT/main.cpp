#include <GL/glut.h>
float angle=45, oldX= 0;
void mouse(int button, int state, int x, int y){
    oldX =x;
}
void motion(int x, int y ){
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();///��GLUT���e
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.5);///����y��
    glPushMatrix();
        glTranslatef(0.3, 0.4, 0);///(3)����u���^����
        glRotatef(angle, 0, 0, 1);///(2)��Z�b����
        glTranslatef(-0.3, -0.4, 0);///(1)���u���त�ߩ񤤤�
        glColor3f(1, 0, 0);///����
        glRectf(0.3, 0.5, 0.7, 0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700, 700);///�����j�p
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

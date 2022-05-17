#include <GL/glut.h>
float angle[20], oldX= 0;
int angleID=0;///0�B1�B2�B3�����`
void keyboard(unsigned char key, int x, int y){
    if( key=='0') angleID=0;
    if( key=='1') angleID=1;
    if( key=='2') angleID=2;
    if( key=='3') angleID=3;
}
void mouse(int button, int state, int x, int y){
    oldX =x;
}
void motion(int x, int y ){
    angle[angleID] += (x-oldX);
    oldX = x;
    glutPostRedisplay();///��GLUT���e
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.5);///����y��

    glPushMatrix();///�k�b��
        glTranslatef(0.3, 0.4, 0);///(3)����u���^����
        glRotatef(angle[0], 0, 0, 1);///(2)��Z�b����
        glTranslatef(-0.3, -0.4, 0);///(1)���u���त�ߩ񤤤�

        glColor3f(1, 0, 0);///����
        glRectf(0.3, 0.5, 0.7, 0.3);

        glPushMatrix();
            glTranslatef(0.7, 0.4, 0);///(3)���b���^�h
            glRotatef(angle[1], 0, 0, 1);///(2)��Z�b����
            glTranslatef(-0.7, -0.4, 0);///(1)���u���त�ߩ񤤤�
            glColor3f(0, 1, 0);///���
            glRectf(0.7, 0.5, 1.0, 0.3);///�U���u
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3, 0.4, 0);///(3)����u���^����
        glRotatef(angle[2], 0, 0, 1);///(2)��Z�b����
        glTranslatef(0.3, -0.4, 0);///(1)���u���त�ߩ񤤤�

        glColor3f(1, 0, 0);///����
        glRectf(-0.3, 0.5, -0.7, 0.3);

        glPushMatrix();
            glTranslatef(-0.7, 0.4, 0);///(3)���b���^�h
            glRotatef(angle[3], 0, 0, 1);///(2)��Z�b����
            glTranslatef(0.7, -0.4, 0);///(1)���u���त�ߩ񤤤�
            glColor3f(0, 1, 0);///���
            glRectf(-0.7, 0.5, -1.0, 0.3);///�U���u
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700, 700);///�����j�p
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

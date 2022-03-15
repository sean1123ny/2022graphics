#include <GL/glut.h>
float angle=0, oldx=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x, int y)
{
    angle += (x-oldx);
    oldx = x;
    display();
}
void mouse(int button, int state, int x, int y)
{
    oldx = x;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMotionFunc(motion);///mouse motion動
    glutMouseFunc(mouse);///上週教:mouse按下去，放開來，每次按不重置
    glutMainLoop();
}

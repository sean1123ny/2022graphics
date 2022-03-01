///十行精簡 GLUT程式
///先全刪
#include <GL/glut.h>///GLUT外掛 簡化程式

void display()
{
        glClear( GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT );

        glColor3f(1,1,0);///設定顏色
        ///glutSolidTeapot(0.3);///實心茶壺
        glBegin(GL_POLYGON);
            glColor3f(1,0,0);
            glVertex2f(-1,-1);

            glColor3f(0,1,0);
            glVertex2f(+1,-1);

            glColor3f(0,0,1);
            glVertex2f(0,+1);
        glEnd();

        glutSwapBuffers();///畫好後交換出來
}
int main(int argc, char** argv)///main主函式 (進階
{
    glutInit( &argc, argv);///把參數 給glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區 | 3D深度功能
    glutCreateWindow("第二周的程式");///開 GLURT 視窗

    glutDisplayFunc(display);///用來顯示函式

    glutMainLoop();///主要程式迴圈
}

///week14_angle_fprintf改自 week13_rect_many_TRT
#include <GL/glut.h>
#include <stdio.h>
float angle[20], oldX= 0;
int angleID=0;///0、1、2、3號關節
FILE *fout = NULL;
void myWrite(){
    if(fout == NULL ) fout = fopen("file.txt", "w+");

    for(int i=0;i<20; i++){
        printf("%.1f ", angle[i]);///從小黑印出來
        fprintf(fout, "%.1f ", angle[i]);///檔案印出來
    }///不用加fclose
}
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
    myWrite();
    oldX = x;
    glutPostRedisplay();///讓GLUT重畫
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.5);///身體座標

    glPushMatrix();///右半邊
        glTranslatef(0.3, 0.4, 0);///(3)把手臂接回身體
        glRotatef(angle[0], 0, 0, 1);///(2)對Z軸旋轉
        glTranslatef(-0.3, -0.4, 0);///(1)手臂旋轉中心放中心

        glColor3f(1, 0, 0);///紅色
        glRectf(0.3, 0.5, 0.7, 0.3);

        glPushMatrix();
            glTranslatef(0.7, 0.4, 0);///(3)把手軸接回去
            glRotatef(angle[1], 0, 0, 1);///(2)對Z軸旋轉
            glTranslatef(-0.7, -0.4, 0);///(1)手臂旋轉中心放中心
            glColor3f(0, 1, 0);///綠色
            glRectf(0.7, 0.5, 1.0, 0.3);///下手臂
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3, 0.4, 0);///(3)把手臂接回身體
        glRotatef(angle[2], 0, 0, 1);///(2)對Z軸旋轉
        glTranslatef(0.3, -0.4, 0);///(1)手臂旋轉中心放中心

        glColor3f(1, 0, 0);///紅色
        glRectf(-0.3, 0.5, -0.7, 0.3);

        glPushMatrix();
            glTranslatef(-0.7, 0.4, 0);///(3)把手軸接回去
            glRotatef(angle[3], 0, 0, 1);///(2)對Z軸旋轉
            glTranslatef(0.7, -0.4, 0);///(1)手臂旋轉中心放中心
            glColor3f(0, 1, 0);///綠色
            glRectf(-0.7, 0.5, -1.0, 0.3);///下手臂
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(700, 700);///視窗大小
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glutMainLoop();
}

#include <GL/glut.h>

float angle = 0.0;

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle, 0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
    angle = angle + 0.5;
}

void changeSize(int width, int height)
{
    // 0으로 나누지 못함
    if (height == 0) { height = 1; }
    float ratio = 1.0 * width / height;

    //좌표계 초기화
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, width, height);

    //투시값 변경
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0, 0.0,1.0,0.0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  // 이중버퍼
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("3D Tech- GLUT Tutorial");
    glutDisplayFunc(renderScene); 

    glutIdleFunc(renderScene);

    glutReshapeFunc(changeSize);

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

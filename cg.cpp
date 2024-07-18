#include <GL/glut.h>
#include <iostream>

float ballX = 0.0f;
float ballY = -0.8f;
float ballRadius = 0.1f;
float ballSpeedY = 0.0f;
float ballSpeedXleft = 0.0f;
float ballSpeedXright = 0.0f;
float airresistance = 0.001f;
float gravity = 0.001f;
float damping = 0.8f;
bool isBallFalling = false;
float cloud_move = 0.0f;
float cloud_move1 = 0.0f;
float cloud_move2 = 0.0f;
int n = 10;
float col[10];


bool isDayMode = false;
const float daySkyColor[3] = { 0.529f, 0.808f, 0.922f };
const float dayGroundColor[3] = { 0.498f, 1.0f, 0.0f };
const float daySunColor[3] = { 1.0f, 1.0f, 0.0f };
const float nightSkyColor[3] = { 0.0f, 0.0f, 0.2f };
const float nightGroundColor[3] = { 0.1f, 0.4f, 0.1f };
const float nightMoonColor[3] = { 0.9f, 0.9f, 0.9f };
const float nightMountain1[3] = { 0.38f, 0.18f, 0.09f };
const float dayMountain1[3] = { 0.58f, 0.38f, 0.29f };
const float nightMountain2[3] = { 0.42f, 0.22f, 0.12f };
const float dayMountain2[3] = { 0.62f, 0.42f, 0.32f };
const float nightTrunk[3] = { 0.44f, 0.04f, 0.04f };
const float dayTrunk[3] = { 0.64f, 0.16f, 0.16f };
const float nightTree[3] = { 0.0f, 0.3f, 0.0f };
const float dayTree[3] = { 0.0f, 0.5f, 0.0f };
const float nightCloud[3] = { 0.7f, 0.7f, 0.7f };
const float dayCloud[3] = { 1.0f, 1.5f, 1.0f };

void init(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);
}

void drawBall()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(ballX, ballY, 0.0f);
    glutSolidSphere(ballRadius, 20, 20);
    glPopMatrix();
}

void Platform() {
    if (isDayMode) {
        glColor3f(dayGroundColor[0], dayGroundColor[1], dayGroundColor[2]);
    }
    else {
        glColor3f(nightGroundColor[0], nightGroundColor[1], nightGroundColor[2]);
    }
    glRectf(-1.0f, -1.0f, 1.0f, -0.9f);
}

void drawSky(void) {
    if (isDayMode) {
        glClearColor(daySkyColor[0], daySkyColor[1], daySkyColor[2], 1.0f);
    }
    else {
        glClearColor(nightSkyColor[0], nightSkyColor[1], nightSkyColor[2], 1.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawTree()
{
    if (isDayMode) {
        glColor3f(dayTrunk[0], dayTrunk[1], dayTrunk[2]);
    }
    else {
        glColor3f(nightTrunk[0], nightTrunk[1], nightTrunk[2]);
    }
    glRectf(-0.86f, -1.0f, -0.82f, -0.8f);
    if (isDayMode) {
        glColor3f(dayTree[0], dayTree[1], dayTree[2]);
    }
    else {
        glColor3f(nightTree[0], nightTree[1], nightTree[2]);
    }
    
    glPushMatrix();
    glTranslatef(-0.84f, -0.7f, 0.0f);
    glScalef(0.09f, 0.09f, 0.05f);
    glTranslatef(0.0f, 0.2f, 0.0f);
    glutSolidDodecahedron();
    glPopMatrix();

    if (isDayMode) {
        glColor3f(dayTrunk[0], dayTrunk[1], dayTrunk[2]);
    }
    else {
        glColor3f(nightTrunk[0], nightTrunk[1], nightTrunk[2]);
    }
    
    glRectf(0.72f, -1.0f, 0.68f, -0.8f);

    if (isDayMode) {
        glColor3f(dayTree[0], dayTree[1], dayTree[2]);
    }
    else {
        glColor3f(nightTree[0], nightTree[1], nightTree[2]);
    }
    glPushMatrix();
    glTranslatef(0.7f, -0.7f, 0.0f);
    glScalef(0.09f, 0.09f, 0.05f);
    glTranslatef(0.0f, 0.2f, 0.0f);
    glutSolidDodecahedron();
    glPopMatrix();

}

void handleMouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        ballX = ((float)x / glutGet(GLUT_WINDOW_WIDTH)) * 2.0f - 1.0f;
        ballY = 1.0f - ((float)y / glutGet(GLUT_WINDOW_HEIGHT)) * 2.0f;
        isBallFalling = true;
        ballSpeedXleft = 0;
        ballSpeedXright = 0;
    }
}

void updateBall()
{
    if (isBallFalling)
    {
        ballSpeedY -= gravity;
        ballY += ballSpeedY;
        if (ballY - ballRadius < -0.9f)
        {
            ballY = -0.9f + ballRadius;
            ballSpeedY = -ballSpeedY * damping;
            if (abs(ballSpeedY) < 0.001f)
            {
                ballSpeedY = 0.0f;
                isBallFalling = false;
            }
        }
    }
}

void move_left() {
    ballSpeedXright = 0;
    if (ballX > -0.9) {
        ballX -= 0.015;
        ballSpeedXleft += gravity;
        ballX -= ballSpeedXleft;
    }

}

void move_right() {
    ballSpeedXleft = 0;
    if (ballX < 0.9) {
        ballX += 0.015;
        ballSpeedXright += gravity;
        ballX += ballSpeedXright;
    }
}

void jump() {

    ballY += 0.4;
    isBallFalling = true;


}

void drawCloud() {
    glPushMatrix();

    if (isDayMode) {
        glColor3f(dayCloud[0], dayCloud[1], dayCloud[2]);
    }
    else {
        glColor3f(nightCloud[0], nightCloud[1], nightCloud[2]);
    }

    glTranslatef(-0.67 + cloud_move, 0.66, 0.0);
    glutSolidSphere(0.1, 100, 80);
    glTranslatef(-0.11, -0.02, 0.0);
    glutSolidSphere(0.06, 20, 80);
    glTranslatef(0.23, -0.01, 0.0);
    glutSolidSphere(0.06, 100, 100);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.37 + cloud_move1, 0.66, 0.0);
    glutSolidSphere(0.1, 100, 80);
    glTranslatef(-0.11, -0.02, 0.0);
    glutSolidSphere(0.06, 20, 80);
    glTranslatef(0.23, -0.01, 0.0);
    glutSolidSphere(0.06, 100, 100);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.17 + cloud_move2, 0.56, 0.0);
    glutSolidSphere(0.1, 100, 80);
    glTranslatef(-0.11, -0.02, 0.0);
    glutSolidSphere(0.06, 20, 80);
    glTranslatef(0.23, -0.01, 0.0);
    glutSolidSphere(0.06, 100, 100);
    glPopMatrix();


}

void drawMountain()
{
    if (isDayMode) {
        glColor3f(dayMountain1[0], dayMountain1[1], dayMountain1[2]);
    }
    else {
        glColor3f(nightMountain1[0], nightMountain1[1], nightMountain1[2]);
    }
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.5, -1.0, 0.0);
    glVertex3f(-0.5, 0.2, 0.0);
    glVertex3f(0.5, -1.0, 0.0);
    glEnd();

    if (isDayMode) {
        glColor3f(dayMountain2[0], dayMountain2[1], dayMountain2[2]);
    }
    else {
        glColor3f(nightMountain2[0], nightMountain2[1], nightMountain2[2]);
    }
    glBegin(GL_TRIANGLES);
    glVertex3f(1.5, -1.0, 0.0);
    glVertex3f(0.7, 0.0, 0.0);
    glVertex3f(-0.5, -1.0, 0.0);
    glEnd();
}

void star(float x, float y, float col) {
    glColor3f(col, col, col);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + 0.006, y + 0.006);
    glVertex2f(x + 0.012, y);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + 0.006, y - 0.006);
    glVertex2f(x + 0.012, y);

    glEnd();
}


void SunorMoon() {
    if (isDayMode) {
        glColor3f(daySunColor[0], daySunColor[1], daySunColor[2]);
        glPushMatrix();
        glTranslatef(0.8, 0.8, 0.0);
        glutSolidSphere(0.12, 50, 50);
        glPopMatrix();
    }
    else {
        glColor3f(nightMoonColor[0], nightMoonColor[1], nightMoonColor[2]);
        glPushMatrix();
        glTranslatef(0.8, 0.8, 0.0);
        glutSolidSphere(0.1, 50, 50);
        glPopMatrix();
    }

}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'm':
        isDayMode = true;
        break;
    case 'n':
        isDayMode = false;
        break;
    case 'a':
        move_left();
        break;
    case 'd':
        move_right();
        break;
    case ' ':
        jump();
        break;
    case 27:
        break;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();

    if (isDayMode == false) {
        star(-0.9, 0.6, col[5]);
        star(-0.8, 0.82, col[7]);
        star(-0.7, 0.73, col[8]);
        star(-0.68, 0.35, col[4]);
        star(-0.5, 0.62, col[7]);
        star(-0.4, 0.73, col[8]);
        star(-0.2, 0.9, col[3]);
        star(0.0, 0.5, col[8]);
        star(0.2, 0.6, col[0]);
        star(0.3, 0.8, col[6]);
        star(0.4, 0.37, col[9]);
        star(0.5, 0.9, col[9]);
        star(0.6, 0.8, col[6]);
        star(0.8, 0.4, col[9]);

    }
    glFlush();

    SunorMoon();
    drawMountain();
    drawCloud();
    drawTree();

    Platform();
    drawBall();

    glutSwapBuffers();
}

void Cloud_move() {
    cloud_move += 0.0019;
    if (cloud_move > 1.9)
    {
        cloud_move = -1.0;
    }
    cloud_move1 += 0.0018;
    if (cloud_move1 > 1.0)
    {
        cloud_move1 = -1.7;
    }

    cloud_move2 += 0.0022;
    if (cloud_move2 > 1.5)
    {
        cloud_move2 = -1.2;

    }

}

void update(int value)
{
    for (int i = 0; i < n; i++) {
        col[i] = rand() / 32767.00;
    }


    Cloud_move();
    updateBall();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Ball Drop");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(handleMouseClick);
    glutTimerFunc(0, update, 0);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}


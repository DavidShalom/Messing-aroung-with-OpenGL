#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>  // GLUT, include glu.h and gl.h

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;


void display(void);
void reshape(int x, int y);
void initGL(void);

//body parts
void head(void);
void nose(void);
void torso(void);
void right_arm(void);
void left_arm(void);
void right_leg(void);
void left_leg(void);
void make_floor(void);
void build_body(void);

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(350,350);
    glutCreateWindow("Model of human");
    xRotated = yRotated = zRotated = 30.0;
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE| GLUT_DEPTH);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
   
    glLoadIdentity();
    glTranslatef(0.0f, -2.0f, -7.0f);
    glRotatef(90, 1.0, 0.0, 0.0);
    glEnable(GL_COLOR_MATERIAL);
    make_floor();
    
    glLoadIdentity();
    glTranslatef(0.0f, -0.5f, -7.0f);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    build_body();
    
    glutSwapBuffers();
}

void reshape(int x, int y)
{
    if (y == 0) y = 1;
    GLfloat aspect = (GLfloat)x / (GLfloat)y;
    

    glViewport(0, 0, x, y);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(50.0f, aspect, 0.1f, 100.0f);
}

void head(void)
{
    glPushMatrix();
    glTranslatef(0.0, 1.3, 0.0);
    glutSolidSphere(0.5, 30, 30);
    glPopMatrix();
}

void nose(void)
{
    glPushMatrix();
    glTranslatef(-0.05, 1.2, 0.0);
    glRotatef(40.0, 0.0, 1.0, 0.0);
    glRotatef(-80.0, 0.0, 0.0, 1.0);
    glRotatef(15.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.1, 1.0, 10, 4);
    glPopMatrix();
}

void torso(void)
{
    glPushMatrix();
    glTranslatef(0.0,-0.3, 0.0);
    glRotatef(270.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.2, 1.4, 10, 4);
    glPopMatrix();
}

void left_arm(void)
{
    glPushMatrix();
    glTranslatef(0.05,0.5, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.07, 1.0, 10, 4);
    glPopMatrix();
}

void right_arm(void)
{
    glPushMatrix();
    glTranslatef(-0.05,0.5, 0.0);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.07, 1.0, 10, 4);
    glPopMatrix();
}

void right_leg(void)
{
    glPushMatrix();
    glTranslatef(-0.1,-0.30, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.1, 2.0, 10, 4);
    glPopMatrix();
}

void left_leg(void)
{
    glPushMatrix();
    glTranslatef(0.1,-0.30, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.1, 2.0, 10, 4);
    glPopMatrix();
}

void make_floor(void)
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);  glVertex3f(-3.0f,3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);  glVertex3f(-3.0f,-3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);  glVertex3f(3.0f,-3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);  glVertex3f(-3.0f,3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(3.0f,3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(3.0f,-3.0f, 0.0f);
    glEnd();
}

void build_body(void)
{
    head();
    nose();
    torso();
    right_arm();
    left_arm();
    right_leg();
    left_leg();
}


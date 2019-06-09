#define GL_SILENCE_DEPRECATION

#include <GLUT/GLUT.h>
#include <iostream>
/*
 SOIL.h used for the bonus
#include "Simple OpenGL Image Library/src/SOIL.h"
 */

#define checkImageWidth 64
#define checkImageHeight 64

static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
GLfloat color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
static GLuint *textures = new GLuint[4];
int width, height;
unsigned char *image;


void makeCheckImage(void);
void init(void);
void build_square(void);
void display(void);
void reshape(int w, int h);
void keyboard (unsigned char key, int x, int y);
void build_square(void);
void build_triangle(void);



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

void makeCheckImage(void)
{
    int i, j, c;
    
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i&0x8)==0)^((j&0x8))==0))*255;
            checkImage[i][j][0] = (GLubyte) c;
            checkImage[i][j][1] = (GLubyte) c;
            checkImage[i][j][2] = (GLubyte) c;
            checkImage[i][j][3] = (GLubyte) 255;
        }
    }
}

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    makeCheckImage();
    
    glGenTextures(4, textures);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, color);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                 checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 checkImage);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    /*
     
bonus part:
    image = SOIL_load_image("jacobs.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);
     
     */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    /*
     
bonus part:
     image = SOIL_load_image("jacobs.png", &width, &height, 0, SOIL_LOAD_RGB);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
     SOIL_free_image_data(image);
     
     */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    /*
     
bonus part:
     image = SOIL_load_image("jacobs.png", &width, &height, 0, SOIL_LOAD_RGB);
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
     SOIL_free_image_data(image);
     
     */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    /*
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     */
}

void build_square(void) //made with two triangles
{
    // set the (U, V) values with glTexCoord2f
    glTexCoord2f(0.0f, 2.0f);  glColor3f(0.0f, 0.0f, 0.0f);  glVertex3f(-0.6f,0.6f, 0.0f); //top left
    glTexCoord2f(0.0f, 0.0f);  glColor3f(0.0f, 0.0f, 0.0f);  glVertex3f(-0.6f,-0.6f, 0.0f); //bottom left
    glTexCoord2f(2.0f, 0.0f);  glColor3f(0.0f, 0.0f, 0.0f);  glVertex3f(0.6f,-0.6f, 0.0f);  //bottom right
    glTexCoord2f(0.0f, 2.0f);  glColor3f(0.0f, 0.0f, 0.0f);  glVertex3f(-0.6f,0.6f, 0.0f); //top left(second triangle)
    glTexCoord2f(2.0f, 2.0f);  glColor3f(0.0f, 0.0f, 0.0f);  glVertex3f(0.6f,0.6f, 0.0f); //top right
    glTexCoord2f(2.0f, 0.0f);  glColor3f(0.0f, 0.0f, 0.0f);  glVertex3f(0.6f,-0.6f, 0.0f); //bottom right(second triangle)
}
void build_triangle(void)
{
    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glTexCoord3f(1.0f, 0.0f, 1.0f); glColor3f(1.0f, 0.0f, 0.0f);   glVertex3f(-0.6f,-0.6f, 0.6f);
    glTexCoord3f(0.0f, 0.0f, 1.0f); glColor3f(1.0f, 0.0f, 0.0f);   glVertex3f(0.6f,-0.6f, 0.0f);
    glTexCoord3f(0.0f, 0.0f, 1.0f); glColor3f(1.0f, 0.0f, 0.0f);   glVertex3f(0.0f,0.6f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
    glLoadIdentity();
    glTranslatef(-1.0f, 1.0f, -7.0f);
    glBegin(GL_TRIANGLES);
    glTexCoord3f(1.0f, 0.0f, 1.0f); glColor3f(0.0f, 0.0f, 0.0f);   glVertex3f(-0.6f,-0.6f, 0.6f);
    glTexCoord3f(0.0f, 0.0f, 1.0f); glColor3f(0.0f, 0.0f, 0.0f);   glVertex3f(0.6f,-0.6f, 0.0f);
    glTexCoord3f(0.0f, 0.0f, 1.0f); glColor3f(0.0f, 0.0f, 0.0f);   glVertex3f(0.0f,0.6f, 0.0f);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    //Triangle
    glLoadIdentity();
    glTranslatef(-1.0f, 1.0f, -7.0f);
    build_triangle();
    
    // 1st square
    glLoadIdentity();
    glTranslatef(1.0f, -1.0f, -7.0f);
    glActiveTexture(GL_TEXTURE1);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    build_square();
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // 2nd square
    glLoadIdentity();
    glTranslatef(1.0f, 1.0f, -7.0f);
    glActiveTexture(GL_TEXTURE2);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    build_square();
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    // 3rd square
    glLoadIdentity();
    glTranslatef(-1.0f, -1.0f, -7.0f);
    glActiveTexture(GL_TEXTURE3);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_STRIP);
    build_square();
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //glFlush();
    glutSwapBuffers();
}


void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(0.0, 0.0, -3.6);
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(0,1.0,0.0,1.0);
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

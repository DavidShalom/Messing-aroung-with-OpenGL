#define GL_SILENCE_DEPRECATION


#include <GL/glut.h>


char title[] = "3D Shapes";

GLfloat x_angle, y_angle, z_angle, x_translation, y_translation, z_translation, aspect;
bool flag; //here this is a boolean flag to control the projection switching


void initGL();
void display();
void reshape(GLsizei width, GLsizei height);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    initGL();
    glutMainLoop();
    return 0;
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    x_angle = 0;
    y_angle = 0;
    z_angle = 0;
    x_translation = 1.5;
    y_translation = 0;
    z_translation = -7;
    
}


void reshape(GLsizei width, GLsizei height) {
    
    if (height == 0) height = 1;
    aspect = (GLfloat)width / (GLfloat)height;
    
    
    glViewport(0, 0, width, height);
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    flag = true;
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    
    glLoadIdentity();
    glTranslatef(x_translation, y_translation, z_translation);
    
    glRotatef(x_angle, 1.0f, 0.0f, 0.0f);
    glRotatef(y_angle, 0.0f, 1.0f, 0.0f);
    glRotatef(z_angle, 0.0f, 0.0f, 1.0f);
    
    glBegin(GL_QUADS);
    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    
    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    
    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    
    // Back face (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    
    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    
    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing color-cube

    
    // Render a pyramid consists of 4 triangles
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    // Front
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    // Right
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    // Back
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    // Left
    glColor3f(1.0f,0.0f,0.0f);       // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f,0.0f,1.0f);       // Blue
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glColor3f(0.0f,1.0f,0.0f);       // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();   // Done drawing the pyramid
    
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(flag){
        gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    }
    else{
        glOrtho(-3.0 * aspect, 3.0 * aspect, -3.0, 3.0, 0.1, 100);
    }
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();

    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y)
{
    if(key=='w' || key=='W'){
        y_translation += 0.1;
    }
    if(key=='s'|| key=='S'){
        y_translation += -0.1;
    }
    
    if(key=='a'|| key=='A'){
        x_translation += 0.1;
    }
    if(key=='d'|| key=='D'){
        x_translation += -0.1;
    }

    if(key=='r'|| key=='R'){
        z_translation += 0.1;
    }
    if(key=='f'|| key=='F'){
        z_translation += -0.1;
    }
    
    if(key=='1'){
        x_angle += 1;
    }
    if(key=='2'){
        x_angle += -1;
    }
    
    if(key=='3'){
         y_angle += 1;
    }
    if(key=='4'){
        y_angle += -1;
    }
    
    if(key=='5'){
        z_angle += 1;
    }
    if(key=='6'){
        z_angle += -1;
    }
    
    if(key=='p' || key=='P'){
        if(flag){
            flag = false;
        }
        else{
            flag = true;
        }
    }
    
    if(key== 27){
        exit(0);
    }
    glutPostRedisplay();
}

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
float theta=0.0f;
float speed = 0.0f;
void display();
void specialKeys();
double rotate_y=0;
double rotate_x = 0;
double x_axis=0;
double y_axis=0;
double z_axis=0;
double angle=0;int i,p;
//Tree *tree[5];
float sudut = 0;
void lighting();

GLuint makeaTree;
//sGLuint aplant;
float x,y,z;

void makeCylinder(float height, float base){
GLUquadric *obj = gluNewQuadric();
//gluQuadricDrawStyle(obj, GLU_LINE);
glColor3f(0.16f, 0.64f, 0.16f);
//glColor3f(0.0f, 1.64f, 0.0f);
glPushMatrix();
glRotatef(-90, 1.0,0.0,0.0);
gluCylinder(obj, base,base-(0.2*base), height, 20,20);
glPopMatrix();
glutSwapBuffers();
}
void makeTree(float height, float base){

float angle;
makeCylinder(height, base);
 glTranslatef(0.0, height, 0.0);
height -= height*.2; base-= base*0.3;
for(int a= 0; a<3; a++){
angle = rand()%50+20;
if(angle >48)
angle = -(rand()%50+20);
if (height >1){
glPushMatrix();
glRotatef(angle,1,0.0,1);
makeTree(height,base);
glPopMatrix();

}}}
void sun(){
     glTranslatef    (0.0, 0.0, -15.0);


    glColor3f (1.0, 1.0, 0.2);
    glPushMatrix ();
       glTranslatef    (0.0, 20.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (2.0, 10, 30);
    glPopMatrix ();
}
/*void sun(){
     glTranslatef    (0.0, 0.0, -15.0);


    glColor3f (1.0, 1.0, 0.2);
    glPushMatrix ();
       glTranslatef    (0.0, 20.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glBegin(GL_QUADS);
glVertex3f(20,0,1);
glVertex3f(20,2,1);
glVertex3f(-20,2,1);
glVertex3f(-20,0,1);
glEnd();
    glPopMatrix ();
}*/

void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0.0f, 0.60f, 0.0f);
glPushMatrix();
glBegin(GL_QUADS);
glColor3f(0.0f, 0.9f, 0.4f);
glVertex3f(27,2,1);
glVertex3f(27,4,1);
glVertex3f(-27,4,1);
glVertex3f(-27,2,1);
glEnd();
glPopMatrix();
glPushMatrix();
glBegin(GL_QUADS);
glColor3f(0.9f, 0.8f, 0.6f);
glVertex3f(27,-6,1);
glVertex3f(27,2,1);
glVertex3f(-27,2,1);
glVertex3f(-27,-6,1);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(2,3,-3);
glRotatef(x,1.0,0.0,0.0);
glRotatef(y,0.0,1.0,0.0);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(17,2,-3);
glRotatef(x,1.0,0.0,0.0);
glRotatef(y,0.0,1.0,0.0);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(-7,2,-3);
glRotatef(x,1.0,0.0,0.0);
glRotatef(y,0.0,1.0,0.0);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(-13,2,-3);
glRotatef(x,1.0,0.0,0.0);
glRotatef(y,0.0,1.0,0.0);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(9,3,-3);
glRotatef(x,1.0,0.0,0.0);
glRotatef(y,0.0,1.0,0.0);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
sun();
glPopMatrix();
glutSwapBuffers();
glutPostRedisplay();


}
double distance=0.01;
void keyboard(unsigned char key, int x, int y){
switch (key){
case 'x':
x +=10;
glutPostRedisplay();
break;
case 'y':
y +=10;
glutPostRedisplay();
break;
case 'z':
z+=10;
glutPostRedisplay();
break;
}
}

void specialKeys(int key , int x , int y){
if(key == GLUT_KEY_RIGHT)
    rotate_y += 5;
else if(key == GLUT_KEY_LEFT)
    rotate_y -= 5;
    else if(key == GLUT_KEY_UP)
    rotate_x += 5;
    else if(key == GLUT_KEY_DOWN)
    rotate_x -= 5;
glutPostRedisplay();
}
void idleFunc (void)
{

    glutPostRedisplay();
}
void texture (void){

const GLfloat light_ambient[]  = { 1.0f, 1.0f, 0.0f, 0.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


}

void init(void){
//glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glClearColor(0.1,0.9,1.0,1.0);
//glShadeModel(GL_SMOOTH);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(30.0, 1.0f, 1.0f, 1000.0);
glMatrixMode(GL_MODELVIEW);
glEnable(GL_DEPTH_TEST);
makeaTree=glGenLists(1);
glNewList(makeaTree, GL_COMPILE);
makeTree(4,0.2);
glEndList();
}
void reshape(int w, int h)
{ glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(30.0, (GLfloat) w/(GLfloat) h, 0.001, 1000.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0,-8.0,-50.0);
}

int main(int argc, char **argv)
{
 glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
     glutInitWindowSize (1200, 800);
  glutInitWindowPosition(200,0);
glutCreateWindow("20100638");
glOrtho(-50,50,-50,50,-50,50);
glRotatef(1,1,0,0);
init();
glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc    (idleFunc);
    glutSpecialFunc(specialKeys);
   glutKeyboardFunc(keyboard);
   texture();
    glutMainLoop();

}



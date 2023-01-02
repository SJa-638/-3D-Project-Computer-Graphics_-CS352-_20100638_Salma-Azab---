#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<mmsystem.h>
float theta=0.0f;
float speed = 0.0f;
void display();
void specialKeys();
double rotate_y=0;
double rotate_x = 0;
double r_y = 0;
double r_x = 0;
double x_axis=0;
double y_axis=0;
double z_axis=0;
double angle=0;int i,p;
double x1_position=0;
double x2_position=0;
int state=1;
float sudut = 0;
void lighting();
void keyboard(unsigned char key, int x, int y);
GLuint makeaTree;
GLuint aplant;
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
void plant(float height, float base){

float angle;
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
void turtle(float height, float base){
     glTranslatef(-5.0, 0.0, 10.0);
    //glColor3f (0.2, 0.4, 0.1);
    glPushMatrix ();//outer frontleg
    glColor3f (0.2, 0.6, 0.2);
    glTranslatef    (-11.0, -0.5, 0.0);
    makeCylinder(height, base);
    glPopMatrix();
    glPushMatrix ();//inner front leg
    glColor3f (0.2, 0.6, 0.2);
    glTranslatef(-10.0, -0.4, 0.0);
    makeCylinder(0.5*height,0.5* base);
    glPopMatrix();

    glPushMatrix ();//outer back leg
    glColor3f (0.2, 0.6, 0.2);
    glTranslatef    (-12.5, -0.5, 0.0);
    makeCylinder(height, base);
    glPopMatrix();
    glPushMatrix ();//inner back leg
    glColor3f (0.2, 0.6, 0.2);
    glTranslatef    (-12.5, -0.4, 0.0);
    makeCylinder(0.5*height,0.5* base);
    glPopMatrix();
    glPushMatrix();
    glPushMatrix ();//head
    glColor3f (0.2, 0.6, 0.2);
    glTranslatef    (-9.5, 1.2, 0.0);
     glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (1.0, 10, 30);
    glPopMatrix();
    glPushMatrix ();//white eye
    glColor3f (1, 1, 1);
    glTranslatef    (-9.5, 1.5, 1.0);
     glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.2, 8, 30);
    glPopMatrix();
    glPushMatrix ();//white eye
    glColor3f (1, 1, 1);
    glTranslatef    (-8.8, 1.5, 1.0);
     glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.2, 8, 30);
    glPopMatrix();
    glPushMatrix ();//blue eye
    glColor3f (0.3, 0.0, 0.9);
    glTranslatef    (-8.7, 1.7, 2.0);
     glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.12, 5, 30);
    glPopMatrix();
 glPushMatrix ();//blue eye
    glColor3f (0.3, 0.0, 0.9);
    glTranslatef    (-9.4, 1.7, 2.0);
     glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.12, 5, 30);
    glPopMatrix();
glPopMatrix();
    glPushMatrix ();//body
    glColor3f (0.2, 0.4, 0.1);
       glTranslatef    (-11.8, 1.0, 0.0);
        glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere(1.41,4,30);
    glPopMatrix ();
}
void hills(){
     glTranslatef    (0.0, 0.0, -15.0);


    glColor3f (0.3, 0.6, 0.2);
  glPushMatrix ();//1st hill
       glTranslatef    (22.0, -7.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (15.0, 10, 30);
        glPopMatrix ();
         glPushMatrix ();//2nd hill
        glTranslatef    (0.0, -7.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (15.0, 10, 30);
    glPopMatrix ();
      glPushMatrix ();//3rd hill
        glTranslatef    (-22.0, -7.0, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (15.0, 10, 30);
    glPopMatrix ();

}
void ground(){

glColor3f(1.0f, 1.0f, 0.6f);
glBegin(GL_QUADS);
glVertex3f(27,-6,1);
glVertex3f(27,2,1);
glVertex3f(-27,2,1);
glVertex3f(-27,-6,1);
glEnd();

}
void rocks(){
     glTranslatef    (0.0, 0.0, 5.0);
    glColor3f (0.7, 0.7, 0.7);
   glPushMatrix ();//middle rock
        glTranslatef    (0.0, 2.8, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (1.0, 5, 30);
       glPopMatrix ();
       glPushMatrix ();//right rock
        glTranslatef    (1.5, 2.8, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.8, 5, 30);
       glPopMatrix ();
       glPushMatrix ();//left rock
        glTranslatef    (-1.5, 2.8, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.5, 5, 30);
    glPopMatrix ();
}
void rabbit(){
 glTranslatef    (-19.0, 0.0, 6.0);
    glColor3f (1.0, 1.0, 1.0);
 glPushMatrix ();//inner leg
        glTranslatef    (2.0, 2.8, 0.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.8, 5, 30);
       glPopMatrix ();
        glPushMatrix ();//outer leg
        glTranslatef    (2.0, 3.0, 2.5);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.9, 5, 30);
       glPopMatrix ();
       glPushMatrix ();//tail
        glTranslatef    (0.5, 3.0, 2.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.5, 5, 30);
       glPopMatrix ();
       glPushMatrix ();//head
        glTranslatef    (1.5, 6.6, 2.0);
       glRotatef       (60.0, 1,0,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (1.2, 10, 30);
       glPopMatrix ();
        glPushMatrix ();//inner foot
        glTranslatef    (2.5, 2.0, 0.0);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.5, 3, 30);
       glPopMatrix ();
        glPushMatrix ();//outer foot
        glTranslatef    (2.0, 1.8, 1.0);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.5, 3, 30);
       glPopMatrix ();
       glPushMatrix ();//inner hand
        glTranslatef    (3.0, 4.5, 0.0);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.5, 3, 30);
       glPopMatrix ();
        glPushMatrix ();//outer hand
        glTranslatef    (2.3, 4.6, 3.0);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.5, 3, 30);
       glPopMatrix ();
       glPushMatrix ();//outer ear
        glTranslatef    (1.3, 7.6, 2.5);
       glRotatef       (160.0, 0,1,1);
       glRotatef       (0, 0,0,1);
       glutSolidCone(0.4,2.0,5,30) ;
       glPopMatrix ();
        glPushMatrix ();//inner ear
        glTranslatef    (1.9, 7.7, 2.0);
       glRotatef       (160.0, 0,1,1);
       glRotatef       (0, 0,0,1);
       glutSolidCone(0.2,2.0,5,30) ;
       glPopMatrix ();
       glPushMatrix ();//body
       glTranslatef    (1.8, 4.2, 1.0);
       glScalef(0.7,1.2,1.0);
       glutSolidDodecahedron();
    glPopMatrix ();

       glPushMatrix ();//nose
        glTranslatef    (2.3, 6.2, 3.0);
        glColor3f(0.9,0.6,0.7);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.3, 3, 30);
       glPopMatrix ();
  glPushMatrix ();//inner eye
        glTranslatef    (2.1, 7.0, 3.0);
        glColor3f(0.0,0.0,0.0);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.1, 3, 30);
       glPopMatrix ();
         glPushMatrix ();//outer eye
        glTranslatef    (2.6, 7.0, 2.0);
        glColor3f(0.0,0.0,0.0);
       glRotatef       (60.0, 0,1,0);
       glRotatef       (0, 0,0,1);
       glutSolidSphere (0.1, 3, 30);
       glPopMatrix ();

}

void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(0.0f, 0.60f, 0.0f);
glPushMatrix();
glTranslatef(0.0,0.0,1.0);
ground();
glPopMatrix();
glPushMatrix();
glTranslatef(2,3,-3);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(17,2,-3);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(-7,2,-3);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(-13,2,-3);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(9,3,-3);
glRotatef(z,0.0,0.0,1.0);
glCallList(makeaTree);
glPopMatrix();
glPushMatrix();
glTranslatef(10,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
glTranslatef(23,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
glTranslatef(-23,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
glTranslatef(4,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
glTranslatef(19,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
glTranslatef(-4,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
glTranslatef(-18,-2,-1);
glRotatef(z,0.0,0.0,1.0);
glCallList(aplant);
glPopMatrix();
glPushMatrix();
sun();
glPopMatrix();
glPushMatrix();
hills();
glPopMatrix();
glPushMatrix();
rocks();
glPopMatrix();
glPushMatrix();
glTranslatef(-6.0,0.0,-2.0);
rocks();
glPopMatrix();
glPushMatrix();
glTranslatef(9.0,0.0,-2.0);
rocks();
glPopMatrix();
glPushMatrix();
glTranslatef(17.0,0.0,-2.0);
rocks();
glPopMatrix();
glPushMatrix();
glTranslatef(-12.0,0.0,-2.0);
rocks();
glPopMatrix();
glPushMatrix();
glTranslatef(x2_position,r_y,2.0);
rabbit();
glPopMatrix();
glPushMatrix();
glTranslatef(x1_position,rotate_y,2.0);
turtle(0.8,0.3);
glPopMatrix();
glPushMatrix();
glBegin(GL_QUADS);
glColor3f(1.0,0.0,0.1);
glVertex3f(20,-6,4);
glVertex3f(20,2,4);
glVertex3f(19,2,4);
glVertex3f(19,-6,4);
glEnd();
glPopMatrix();
glutSwapBuffers();
glutPostRedisplay();


}
double distance=0.01;
void keyboard(unsigned char key, int x, int y){
switch (key){

case 'z':
      z+=10;
      glutPostRedisplay();
      break;
}
}

void specialKeys(int key , int x , int y){
if(key == GLUT_KEY_RIGHT){
   if(x1_position<27){
    x1_position+= 2;}
    if(x2_position<5){
    x2_position +=5;}
   }
else if(key == GLUT_KEY_LEFT){
        if(x1_position>-6){
    x1_position -= 2;}
    if(x2_position>-15){
      x2_position -=7;}
     }
    else if(key == GLUT_KEY_UP){
    rotate_y += 5;
     r_y +=2;
     }
    else if(key == GLUT_KEY_DOWN){
    rotate_y -= 5;
     r_y -=2;
      }
glutPostRedisplay();
}
void idleFunc (void)
{

    glutPostRedisplay();
}
void texture (void){
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
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
glClearColor(0.1,0.9,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(30.0, 1.0f, 1.0f, 1000.0);
glMatrixMode(GL_MODELVIEW);
glEnable(GL_DEPTH_TEST);
makeaTree=glGenLists(1);
glNewList(makeaTree, GL_COMPILE);
makeTree(4,0.3);
glEndList();
aplant=glGenLists(1);
glNewList(aplant, GL_COMPILE);
plant(3,0.2);
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
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(10000/60,timer,0);
        if(x2_position<27){
            x2_position+=2;}
              if(x1_position<32.5){
            x1_position+=0.5;}

}

int main(int argc, char **argv)
{
 glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
     glutInitWindowSize (1200, 800);
  glutInitWindowPosition(200,0);
glutCreateWindow("20100638");
glRotatef(1,1,0,0);
init();
glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc    (idleFunc);
    glutSpecialFunc(specialKeys);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(0,timer,0);
   texture();
   sndPlaySound("قصص-اطفال-قبل-النوم-_-قصة-الارنب-والسلحفاة-_128-kbps_.wav",SND_SYNC);
    glutMainLoop();

}


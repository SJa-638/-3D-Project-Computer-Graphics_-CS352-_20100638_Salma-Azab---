#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<mmsystem.h>
double rotate_y=0;//used in special key & Timer function
double r_y = 0;
double r_x = 0;
double x1_position=0;
double x2_position=0;
GLuint makeaTree;//unsigned binary integer Open GL Type(32)
GLuint aplant;
float z;//z_axis


//Function to make a cylinder shape as it takes height and base used to make trees and turtle legs
void makeCylinder(float height, float base)
{
    GLUquadric *obj = gluNewQuadric();//fuction creates & returns apointer to anew quadric
    glColor3f(0.16f, 0.64f, 0.16f);
    glPushMatrix();
    glRotatef(-90, 1.0,0.0,0.0);
    gluCylinder(obj, base,base-(0.2*base), height, 20,20);
    glPopMatrix();
    glutSwapBuffers();
}
//Function to make the branches of the tree not built in function
//I use the prev. cylinder function as a the root of the tree and then
//operates its base and height and make a for loop to start doing the branches by following operation
//as it makes 3 main branches then if the angle >48 decrease the angle between the other branches and
//as the height is greater than 1 the tree is ready to use
void makeTree(float height, float base)
{
    float angle;
    makeCylinder(height, base);
    glTranslatef(0.0, height, 0.0);
    height -= height*.2;
    base-= base*0.3;
    for(int a= 0; a<3; a++)
    {
        angle = rand()%50+20;
        if(angle >48)
            angle = -(rand()%50+20);
        if (height >1)
        {
            glPushMatrix();
            glRotatef(angle,1,0.0,1);
            makeTree(height,base);
            glPopMatrix();

        }
    }
}
//Function to make the ground plants not built in function
void plant(float height, float base)
{

    float angle;
    glTranslatef(0.0, height, 0.0);
    height -= height*.2;
    base-= base*0.3;
    for(int a= 0; a<3; a++)
    {
        angle = rand()%50+20;
        if(angle >48)
            angle = -(rand()%50+20);
        if (height >1)
        {
            glPushMatrix();
            glRotatef(angle,1,0.0,1);
            makeTree(height,base);
            glPopMatrix();

        }
    }
}

//Functio to make the sun
void sun()
{
    glTranslatef    (0.0, 0.0, -15.0);
    glColor3f (1.0, 1.0, 0.2);//yellow
    glPushMatrix ();
    glTranslatef    (0.0, 20.0, 0.0);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (2.0, 10, 30);
    glPopMatrix ();
}
//function to make the turtle
void turtle(float height, float base)
{
    glTranslatef(-5.0, 0.0, 10.0);
    glPushMatrix ();//outer frontleg
    glColor3f (0.2, 0.6, 0.2);//light green
    glTranslatef    (-11.0, -0.5, 0.0);
    makeCylinder(height, base);
    glPopMatrix();
    glPushMatrix ();//inner front leg
    glColor3f (0.2, 0.6, 0.2);//light green
    glTranslatef(-10.0, -0.4, 0.0);
    makeCylinder(0.5*height,0.5* base);
    glPopMatrix();

    glPushMatrix ();//outer back leg
    glColor3f (0.2, 0.6, 0.2);//light green
    glTranslatef    (-12.5, -0.5, 0.0);
    makeCylinder(height, base);
    glPopMatrix();
    glPushMatrix ();//inner back leg
    glColor3f (0.2, 0.6, 0.2);// light green
    glTranslatef    (-12.5, -0.4, 0.0);
    makeCylinder(0.5*height,0.5* base);
    glPopMatrix();
    glPushMatrix();
    glPushMatrix ();//head
    glColor3f (0.2, 0.6, 0.2);//light green
    glTranslatef    (-9.5, 1.2, 0.0);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (1.0, 10, 30);
    glPopMatrix();
    glPushMatrix ();//white eye
    glColor3f (1, 1, 1);//white
    glTranslatef    (-9.5, 1.5, 1.0);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.2, 8, 30);
    glPopMatrix();
    glPushMatrix ();//white eye
    glColor3f (1, 1, 1);//white
    glTranslatef    (-8.8, 1.5, 1.0);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.2, 8, 30);
    glPopMatrix();
    glPushMatrix ();//blue eye
    glColor3f (0.3, 0.0, 0.9);//blue
    glTranslatef    (-8.7, 1.7, 2.0);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.12, 5, 30);
    glPopMatrix();
    glPushMatrix ();//blue eye
    glColor3f (0.3, 0.0, 0.9);//blue
    glTranslatef    (-9.4, 1.7, 2.0);
    glRotatef       (60.0, 1,0,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.12, 5, 30);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix ();//body
    glColor3f (0.2, 0.4, 0.1);//dark green
    glTranslatef    (-11.8, 1.0, 0.0);
    glRotatef       (60.0, 0,1,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere(1.41,4,30);
    glPopMatrix ();
}

//Function to make the view of  hills in the back ground
void hills()
{
    glTranslatef    (0.0, 0.0, -15.0);
    glColor3f (0.3, 0.6, 0.2);//green
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
//Function to make the view of street in back ground
void ground()
{
    glColor3f(1.0f, 1.0f, 0.6f);//yellow
    glBegin(GL_QUADS);
    glVertex3f(27,-6,1);
    glVertex3f(27,2,1);
    glVertex3f(-27,2,1);
    glVertex3f(-27,-6,1);
    glEnd();

}
//Function to make the view of rocks in background
void rocks()
{
    glTranslatef    (0.0, 0.0, 5.0);
    glColor3f (0.7, 0.7, 0.7);//gray
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
//Function to make the rabbit
void rabbit()
{
    glTranslatef    (-19.0, 0.0, 6.0);
    glColor3f (1.0, 1.0, 1.0);//white
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
    glColor3f(0.9,0.6,0.7);//pink
    glRotatef       (60.0, 0,1,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.3, 3, 30);
    glPopMatrix ();
    glPushMatrix ();//inner eye
    glTranslatef    (2.1, 7.0, 3.0);
    glColor3f(0.0,0.0,0.0);//black
    glRotatef       (60.0, 0,1,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.1, 3, 30);
    glPopMatrix ();
    glPushMatrix ();//outer eye
    glTranslatef    (2.6, 7.0, 2.0);
    glColor3f(0.0,0.0,0.0);//black
    glRotatef       (60.0, 0,1,0);
    glRotatef       (0, 0,0,1);
    glutSolidSphere (0.1, 3, 30);
    glPopMatrix ();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.60f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0,0.0,1.0);
    ground();
    glPopMatrix();
    glPushMatrix();//the middle tree
    glTranslatef(2,3,-3);
    glRotatef(z,0.0,0.0,1.0);// animate around z axis by click on z in the keyboard
    glCallList(makeaTree);//used to execute the display list and takes the name of list
    glPopMatrix();
    glPushMatrix();
    glTranslatef(17,2,-3);//the 1st tree from right
    glRotatef(z,0.0,0.0,1.0);
    glCallList(makeaTree);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-7,2,-3);//the 2nd tree from left
    glRotatef(z,0.0,0.0,1.0);
    glCallList(makeaTree);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-13,2,-3);//The 1st tree from left
    glRotatef(z,0.0,0.0,1.0);
    glCallList(makeaTree);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,3,-3);//The 2nd tree from right
    glRotatef(z,0.0,0.0,1.0);
    glCallList(makeaTree);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,-2,-1);//the 3rd plant from right
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(23,-2,-1);//The 1st plant from right
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-23,-2,-1);//the 1st plant from left
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4,-2,-1);//The middle plant
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(19,-2,-1);//The 2nd plant from right
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4,-2,-1);//The 3rd plant from left
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-18,-2,-1);//The 2nd plant from left
    glRotatef(z,0.0,0.0,1.0);
    glCallList(aplant);
    glPopMatrix();
     glPushMatrix();
     glTranslatef(-9,3.2,3);
    glBegin(GL_TRIANGLES);           // A non built in Function acts AS arock
      // Front
      glColor3f(0.5f, 0.5f, 0.5f);     // yellow
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
 // back
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);

      // left
      glVertex3f(0.0f, 1.0f, 0.0f);
     glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);


   glEnd();   // Done drawing the pyramid

    glPopMatrix();
    glPushMatrix();
     glTranslatef(13,3.2,3);
    glBegin(GL_TRIANGLES);           // A non built in Function acts AS arock
      // Front
      glColor3f(0.5f, 0.5f, 0.5f);     // yellow
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glVertex3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
 // back
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f,-1.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);

      // left
      glVertex3f(0.0f, 1.0f, 0.0f);
     glVertex3f(-1.0f,-1.0f,-1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);


   glEnd();   // Done drawing the pyramid

    glPopMatrix();
    glPushMatrix();
    sun();
    glPopMatrix();
    glPushMatrix();
    hills();
    glPopMatrix();
    glPushMatrix();
    rocks();// the middle rocks
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6.0,0.0,-2.0);//the 2nd rocks from left
    rocks();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9.0,0.0,-2.0);// the 2nd rocks from right
    rocks();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(17.0,0.0,-2.0);// the 1st rocks from right
    rocks();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-12.0,0.0,-2.0);//The 1st rocks from left
    rocks();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(x2_position,r_y,2.0);//animate on the rabbit by the timer function or by click the arrows in keyboard around x axis & y axis
    rabbit();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(x1_position,rotate_y,2.0);//animate on the turtle by the timer function or by click the arrows in keyboard around x axis & y axis
    turtle(0.8,0.3);
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_QUADS);// The final race line
    glColor3f(1.0,0.0,0.1);//red
    glVertex3f(20,-6,4);
    glVertex3f(20,2,4);
    glVertex3f(19,2,4);
    glVertex3f(19,-6,4);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    glutPostRedisplay();


}
//function that if you press the z button the trees and plants will rotate around the z axis
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'z':
        z+=10;
        glutPostRedisplay();
        break;
    }
}
// function that you can use the arrows to make animation on the turtle and rabbit
void specialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_RIGHT)
    {
        if(x1_position<27)
        {
            x1_position+= 2;
        }
        if(x2_position<5)
        {
            x2_position +=5;
        }
    }
    else if(key == GLUT_KEY_LEFT)
    {
        if(x1_position>-6)
        {
            x1_position -= 2;
        }
        if(x2_position>-15)
        {
            x2_position -=7;
        }
    }
    else if(key == GLUT_KEY_UP)
    {
        rotate_y += 5;
        r_y +=2;
    }
    else if(key == GLUT_KEY_DOWN)
    {
        rotate_y -= 5;
        r_y -=2;
    }
    glutPostRedisplay();
}
//void idleFunc (void)
//{

// glutPostRedisplay();
//}
void texture (void)
{
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

void init(void)
{
    glClearColor(0.1,0.9,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0f, 1.0f, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    makeaTree=glGenLists(1);// generate a contiguous set of empty display list and takes the no.of lists
    glNewList(makeaTree, GL_COMPILE);//create a display list takes the name of the list and specify the compilation mode
    makeTree(4,0.3);
    glEndList();
    aplant=glGenLists(1);
    glNewList(aplant, GL_COMPILE);
    plant(3,0.2);
    glEndList();

}
//function controls the view of objects
void reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (GLfloat) w/(GLfloat) h, 0.001, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,-8.0,-50.0);
}
// function of animation on the turtle and the rabbit show when they do the race
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(10000/60,timer,0);
    if(x2_position<27)
    {
        x2_position+=2;
    }
    if(x1_position<32.5)
    {
        x1_position+=0.5;
    }

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
    // glutIdleFunc    (idleFunc);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,timer,0);
    texture();
    //function to play sound
    sndPlaySound("قصص-اطفال-قبل-النوم-_-قصة-الارنب-والسلحفاة-_128-kbps_.wav",SND_SYNC);
    glutMainLoop();

}



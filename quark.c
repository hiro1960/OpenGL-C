/*************************************************/
/* Program "quark.c" */
/* Jan 26 2006 Created by vine_user */
/*************************************************/
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
GLfloat theta = 0.0;


void idle(void)
{
  theta = fmod(theta + 0.004, 360.0);
  glutPostRedisplay();
}

static void displayCallback(void)
{
  GLfloat mat_dif[4]={0.0, 0.5+0.5*sin(6.0*theta), 0.5-0.5*sin(6.0*theta), 1.0};
  GLfloat mat_dif2[4]={0.0, 0.5-0.5*sin(6.0*theta), 0.5+0.5*sin(6.0*theta), 0.5};
  GLfloat mat_dif3[4]={1.0, 0.0, 0.0, 0.5};
  GLfloat mat_spc[4]={0.5, 0.5, 0.5, 1.0};
  GLfloat mat_spc2[4]={0.5, 0.5, 0.5, 1.0};
  GLfloat mat_shi[4]={60.0};
  GLfloat mat_shi2[4]={30.0};

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  glRotatef(20.0*theta, 0.0, 0.0, 1.0);

  glTranslatef(-0.8, 0.0, 0.0);

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spc);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shi);
  glutSolidSphere(0.3, 100, 100);

  glPushMatrix();

  glTranslatef(1.6, 0.0, 0.0);

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif2);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spc2);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shi2);
  glutSolidSphere(0.3, 100, 100);

  glTranslatef(-0.8+0.8*sin(6.0*theta), 0.0, 0.0);

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif3);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spc2);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shi2);
  glutSolidSphere(0.15, 100, 100);
  glPopMatrix();

  glPopMatrix();
  glutSwapBuffers();
}

static void reshapeCallback(int width, int height)
{
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, width/(GLdouble)height, 0.01, 100);

  glMatrixMode(GL_MODELVIEW);
}

static void keyboardCallback(unsigned char key, int x, int y)
{
  switch (key) {
  case 27:
    exit(EXIT_SUCCESS);
    break;
  default:
    break;
  }
}

static void initGL(void)
{
  GLfloat light0Color[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat light0Ambient[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat light0Position[] = {0.0, 1.5, 2.5, 1.0};
  int width, height;

  width = glutGet(GLUT_WINDOW_WIDTH);
  height = glutGet(GLUT_WINDOW_HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, width/(GLdouble)height, 0.01, 100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt( 0.0, 0.0, 3.5,
	     0.0, 0.0, 0.0,
	     0.0, 1.0, 0.0 );

  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Color);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light0Color);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
  glLightfv(GL_LIGHT0, GL_POSITION, light0Position);

  glClearColor(0.0, 0.0, 0.2, 1.0);

  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

  glutCreateWindow("Quark model");

  glutDisplayFunc(displayCallback);
  glutIdleFunc(idle);
  glutKeyboardFunc(keyboardCallback);
  glutReshapeFunc(reshapeCallback);

  initGL();
  glutMainLoop();

  return EXIT_SUCCESS;
}


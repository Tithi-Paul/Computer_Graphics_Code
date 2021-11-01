#include <windows.h>
#ifdef __APPLE_CC__
#else
#include <GL/glut.h>
#endif

static int a1 = 0, a2 = 0 , a3 = 0;
static float tx = -0.4, ty = 0 , tz = 0;

void init() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: (tx -= 0.05); break;
    case GLUT_KEY_RIGHT: (tx += 0.05); break;
    case GLUT_KEY_UP: (ty += 0.05); break;
    case GLUT_KEY_DOWN: (ty -= 0.05); break;
    case GLUT_KEY_F8: (tz += 0.02); break;
    case GLUT_KEY_F9: (tz -= 0.02); break;

    case GLUT_KEY_F1: (a1 = 1); break;
    case GLUT_KEY_F2: (a2 = 1); break;
    case GLUT_KEY_F3: (a3 = 1); break;

    case GLUT_KEY_F4: glScalef(0.95 , 0.95 , 1); break;
    case GLUT_KEY_F5: glScalef(1.1 , 1.1 , 1); break;

    default: return;
  }
  if(tx > 1) tx = -1;
  if(tx < -1) tx = 1;
  if(ty > 1) ty = -1;
  if(ty < -1) ty = 1;
  if(tz > 1) tz -=2;
  if(tz < -1) tz +=2;
  glutPostRedisplay();
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
    glColor3f(1, 1, 0); glVertex3f(tx, ty, tz);
    glColor3f(1, 1, 0); glVertex3f(0.25+tx, -0.25+ty, -1.25+tz);
    glColor3f(0, 0, 1); glVertex3f(0.5+tx, ty, -1.25+tz);
    glColor3f(0, 0, 1); glVertex3f(0.5+tx, 0.5+ty, tz);
    glColor3f(0, 0, 1); glVertex3f(0.25+tx, 0.75+ty, 1.25+tz);
    glColor3f(1, 1, 0); glVertex3f(tx,0.5+ty, 1.25+tz);
  glEnd();

 glTranslatef(tx, ty, tz);
 glRotatef((GLfloat)a1, 1.0, 0.0, 0.0);
 a1 = 0;
 glRotatef((GLfloat)a2, 0.0, 1.0, 0.0);
 a2 = 0;
 glRotatef((GLfloat)a3, 0.0, 0.0, 1.0);
 a3 = 0;
 glTranslatef(-tx, -ty, -tz);

 glFlush();
}

int main(int argc, char** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(80, 80);
  glutInitWindowSize(500, 500);
  glutCreateWindow("A Simple Hexagonal");
  glutDisplayFunc(display);

  glutSpecialFunc(special);
  init();
  glutMainLoop();
}


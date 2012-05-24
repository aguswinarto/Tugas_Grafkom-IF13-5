//============================================================================
// Name        : Dog.cpp
// Author      : Agus Winarto Pratama
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#define NULL 0
#define TORSO_HEIGHT 4.0
#define TORSO_RADIUS 1.50
#define UPPER_FRONT_HEIGHT 2.0
#define LOWER_FRONT_HEIGHT 0.10
#define LOWER_BACK_HEIGHT 0.10
#define UPPER_FRONT_RADIUS 0.5
#define LOWER_FRONT_RADIUS 0.5
#define HEAD_HEIGHT 1.5
#define HEAD_RADIUS 1.0

#include <GL/glut.h>

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


//set head, torso, and all the feet
void head();
void torso();
void left_upper_front();
void right_upper_front();
void left_upper_back();
void right_upper_back();



typedef float point[3];

typedef struct treenode{
	GLfloat m[16];
	void (*f)();
	struct treenode *sibling;
	struct treenode *child;
} treenode;

typedef treenode* t_ptr;

static GLfloat theta[11] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
							0.0, 0.0, 0.0, 0.0};

static GLint acc = 1, acc1 = 1, acc2 = 1;

GLUquadricObj *t, *h, *luf, *llf, *ruf, *rlf, *llb, *rlb, *rub, *lub;

treenode torso_node, head_node, luf_node, ruf_node, llb_node, rlb_node, llf_node,
			rlf_node, rub_node, lub_node;

void TimerFunc(int value){
    glutPostRedisplay();
    glutTimerFunc(100, TimerFunc, 1);
}

void traverse(treenode * root){
	if(root==NULL) return ;
	glPushMatrix();
	glMultMatrixf(root->m);
	root->f();
	if(root->child!=NULL) traverse(root->child);
	glPopMatrix();
	if(root->sibling!=NULL)traverse(root->sibling);
}

void torso(){
	glPushMatrix();
	glColor3ub(139,90,43); //tan4
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	gluSphere(t, TORSO_RADIUS, 10, 10);
	gluCylinder(t, TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT, 10, 10);
	glTranslatef(0.0, 0.0, TORSO_HEIGHT );
	gluSphere(t, TORSO_RADIUS, 10, 10);
	glPopMatrix();

	//tail
	glPushMatrix();
	glColor3ub(139,90,43); //tan4
	glTranslatef(-5.70, 0.90, 0.0);
	glScalef(2.50, 0.5, 0.50);
	gluSphere(h, 0.5, 10, 10);
	glPopMatrix();
}

void head(){
	glPushMatrix();
	glTranslatef(-0.20, 4.0, 0.0);
	glPushMatrix();
	glTranslatef(1.80, -2.50, 0.0);
	glScalef(1.70, 1.0, 1.40);
	gluSphere(h, 1.0, 10, 10);
	glPopMatrix();

	//ear
	glPushMatrix();
	glTranslatef(2.0, -1.80, 0.70);
	glPushMatrix();
	glScalef(0.50, 1.30, 1.30);
	gluSphere(h, 0.5, 10, 10);
	glPopMatrix();
	glTranslatef(0.0, 0.0, -1.40);
	glPushMatrix();
	glScalef(0.50, 1.30, 1.30);
	gluSphere(h, 0.5, 10, 10);
	glPopMatrix();
	glPopMatrix();

	//eye
	glPushMatrix();
	glColor3ub(0,0,0); //black
	glTranslatef(3.10, -2.0, 0.50);
	gluSphere(h, 0.2, 10, 10);
	glTranslatef(0.0, 0.0, -1.0);
	gluSphere(h, 0.2, 10, 10);
	glColor3ub(139,90,43); //tan4
	glPopMatrix();
	glPopMatrix();

}

void left_upper_front(){
	glPushMatrix();
	glTranslatef(0.60, -2.40, 0.7);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(luf,UPPER_FRONT_RADIUS, 10, 10 );
	gluCylinder(luf, UPPER_FRONT_RADIUS, UPPER_FRONT_RADIUS, UPPER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, UPPER_FRONT_HEIGHT);
	gluSphere(luf,UPPER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void left_lower_front(){
	glPushMatrix();
	glTranslatef(0.60, -2.60, 0.7);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(llf,LOWER_FRONT_RADIUS, 10, 10 );
	gluCylinder(llf, LOWER_FRONT_RADIUS, LOWER_FRONT_RADIUS, LOWER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, LOWER_FRONT_HEIGHT);
	gluSphere(llf,LOWER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void right_upper_front(){
	glPushMatrix();
	glTranslatef(0.6, -2.50, -0.7);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(ruf,UPPER_FRONT_RADIUS, 10, 10 );
	gluCylinder(ruf, UPPER_FRONT_RADIUS, UPPER_FRONT_RADIUS, UPPER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, UPPER_FRONT_HEIGHT);
	gluSphere(ruf,UPPER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void right_lower_front(){
	glPushMatrix();
	glTranslatef(0.60, -2.50, -0.70);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(rlf,LOWER_FRONT_RADIUS, 10, 10 );
	gluCylinder(rlf, LOWER_FRONT_RADIUS, LOWER_FRONT_RADIUS, LOWER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, LOWER_FRONT_HEIGHT);
	gluSphere(rlf,LOWER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}


void left_upper_back(){
	glPushMatrix();
	glTranslatef(0.6, -2.60, 0.7);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(lub,UPPER_FRONT_RADIUS, 10, 10 );
	gluCylinder(lub, UPPER_FRONT_RADIUS, UPPER_FRONT_RADIUS, UPPER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, UPPER_FRONT_HEIGHT);
	gluSphere(lub,UPPER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void left_lower_back(){
	glPushMatrix();
	glTranslatef(4.50, -2.60, 0.70);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(llb,LOWER_FRONT_RADIUS, 10, 10 );
	gluCylinder(llb, LOWER_FRONT_RADIUS, LOWER_FRONT_RADIUS, LOWER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, LOWER_FRONT_HEIGHT);
	gluSphere(llb,LOWER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void right_upper_back(){
	glPushMatrix();
	glTranslatef(0.6, -2.60, -0.7);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(rub,UPPER_FRONT_RADIUS, 10, 10 );
	gluCylinder(rub, UPPER_FRONT_RADIUS, UPPER_FRONT_RADIUS, UPPER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, UPPER_FRONT_HEIGHT);
	gluSphere(rub,UPPER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void right_lower_back(){
	glPushMatrix();
	glTranslatef(4.50, -2.60, -0.70);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluSphere(rlb,LOWER_FRONT_RADIUS, 10, 10 );
	gluCylinder(rlb, LOWER_FRONT_RADIUS, LOWER_FRONT_RADIUS, LOWER_FRONT_HEIGHT, 10, 10);
	glTranslatef(0.0,  0.0, LOWER_FRONT_HEIGHT);
	gluSphere(rlb,LOWER_FRONT_RADIUS, 10, 10 );
	glPopMatrix();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);
	traverse(&torso_node);
	glPopMatrix();

	//the move
	//torso
	glPushMatrix();
    glRotatef(theta[0], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,torso_node.m);
	theta[0] += acc1;
	glPopMatrix();

	//head
	glPushMatrix();
    glRotatef(theta[1], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,head_node.m);
	if(theta[1] > 20 || theta[1] < -60)
		acc = -acc;
	theta[1] += acc;
	glPopMatrix();

	//luf
	glPushMatrix();
    glRotatef(theta[3], 0.0, 0.0, 1.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,luf_node.m);
	if(theta[3] > 10 || theta[3] < -10)
		acc1 = -acc1;
	theta[3] += 2*acc1;
	glPopMatrix();
	//llf
	glPushMatrix();
    glRotatef(theta[4], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,llf_node.m);
	if(theta[4] > 0 || theta[4] < -10)
		acc2 = -acc2;
	theta[4] += acc2;
	glPopMatrix();

	//lub
	glPushMatrix();
	glTranslatef(-4.0, 0.0, 0.0);
	glPushMatrix();
    glRotatef(theta[7], 0.0, 0.0, 1.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,lub_node.m);
	theta[7] += 2*acc1;
	glPopMatrix();
	glPopMatrix();
	//llb
	glPushMatrix();
	glTranslatef(-4.0, 0.0, 0.0);
	glPushMatrix();
    glRotatef(theta[8], 0.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,llb_node.m);
	theta[8] += acc2;
	glPopMatrix();
	glPopMatrix();

	//ruf
	glPushMatrix();
    glRotatef(theta[5], 0.0, 0.0, 1.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,ruf_node.m);
	theta[5] += 2*-acc1;
	glPopMatrix();
	//rlf
	glPushMatrix();
    glRotatef(theta[6], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,rlf_node.m);
	theta[6] += -acc2;
	glPopMatrix();

	//rub
	glPushMatrix();
	glTranslatef(-4.0, 0.0, 0.0);
	glPushMatrix();
    glRotatef(theta[9], 0.0, 0.0, 1.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,rub_node.m);
	theta[9] += 2*-acc1;
	glPopMatrix();
	glPopMatrix();
	//rlb
	glPushMatrix();
	glTranslatef(-4.0, 0.0, 0.0);
	glPushMatrix();
    glRotatef(theta[10], 0.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX,rlb_node.m);
	theta[10] += -acc2;
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void myReshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h/ (GLfloat) w,
			10.0 * (GLfloat) w/ (GLfloat) h, -10.0, 10.0);
	else
		glOrtho(-10.0 *(GLfloat) w/ (GLfloat) h, 10.0 * (GLfloat) w/ (GLfloat) h,
			10.0*(GLfloat) w/ (GLfloat) h, 0.0, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}

void SetupRC(){
	GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
	GLfloat mat_diffuse[]={1.0, 1.0, 1.0, 1.0};
	// Light values and coordinates
    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);	// Hidden surface removal
    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
    glDisable(GL_CULL_FACE);		// Do not calculate inside of jet

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    // white background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f );

    glEnable(GL_NORMALIZE);


	h=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	t=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	luf=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	llf=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	ruf=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	rlf=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	lub=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	llb=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	rub=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	rlb=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);

	/*set up tree*/
	glLoadIdentity();
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, torso_node.m);
	torso_node.f=torso;
	torso_node.sibling = &head_node;
	torso_node.child = NULL;

	glLoadIdentity();
	glRotatef(theta[1], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, head_node.m);
	head_node.f = head;
	head_node.sibling = &luf_node;
	head_node.child = NULL;

	glLoadIdentity();
	glRotatef(theta[3], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, luf_node.m);
	luf_node.f = left_upper_front;
	luf_node.sibling = &ruf_node;
	luf_node.child = &llf_node;

	glLoadIdentity();
	glRotatef(theta[5], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, ruf_node.m);
	ruf_node.f = right_upper_front;
	ruf_node.sibling = &lub_node;
	ruf_node.child = &rlf_node;

	glLoadIdentity();
	glRotatef(theta[7], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, lub_node.m);
	lub_node.f = left_upper_back;
	lub_node.sibling = &rub_node;
	lub_node.child = &llb_node;

	glLoadIdentity();
	glRotatef(theta[9], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rub_node.m);
	rub_node.f = right_upper_back;
	rub_node.sibling = NULL;
	rub_node.child = &rlb_node;

	glLoadIdentity();
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, llf_node.m);
	llf_node.f = left_lower_front;
	llf_node.sibling = NULL;
	llf_node.child = NULL;

	glLoadIdentity();
	glRotatef(theta[6], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rlf_node.m);
	rlf_node.f = right_lower_front;
	rlf_node.sibling = NULL;
	rlf_node.child = NULL;

	glLoadIdentity();
	glRotatef(theta[8], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, llb_node.m);
	llb_node.f = left_lower_back;
	llb_node.sibling = NULL;
	llb_node.child = NULL;

	glLoadIdentity();
	glRotatef(theta[10], 1.0, 0.0, 0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, rlb_node.m);
	rlb_node.f = right_lower_back;
	rlb_node.sibling = NULL;
	rlb_node.child = NULL;

}


// Handle arrow keys
void SpecialKeys(int key, int x, int y){
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key > 356.0f)
        xRot = 0.0f;

    if(key < -1.0f)
        xRot = 355.0f;

    if(key > 356.0f)
        yRot = 0.0f;

    if(key < -1.0f)
        yRot = 355.0f;

    // Refresh the Window
    glutPostRedisplay();
}


int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(230, 170);
	glutCreateWindow("Tugas Grafika Komputer - Kelompok 5 - IF 13");
	glutTimerFunc(500, TimerFunc, 1);
	SetupRC();
	glutSpecialFunc(SpecialKeys);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
}





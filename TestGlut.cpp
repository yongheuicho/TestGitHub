// TestGlut.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GL/glut.h>

#define DANGLE (1.0f);
using namespace std;

GLfloat red = 1.0f;
GLfloat green = 1.0f;
GLfloat blue = 1.0f;

GLfloat angle = 0.0f;
GLfloat dangle = DANGLE;

GLfloat fps = 120.0f;
GLfloat frameTimeMs = 1000.0f / fps;

int lastUpdateTime = 0;

void renderScene(void)
{
	//cout << "renderScene" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glColor3f(red, green, blue);
	glRotatef(angle, 0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);  glVertex3f(0.5f, 0.0f, 0.0f);
	glColor3f(0, 1, 0); glVertex3f(0.0f, 0.5f, 0);
	glColor3f(0, 0, 1); glVertex3f(-0.5f, 0.0f, 0);
	glEnd();

	glPopMatrix();
	//glFlush(); // for single buffer
	glutSwapBuffers();

	angle += dangle;
	if (angle > 360.0f) angle -= 360.0f;
	else if (angle < 0.0f) angle += 360.0f;
	cout << angle << "|";
}

void idleScene(void)
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	//cout << "idleScene" << endl;
	if (currentTime - lastUpdateTime >= frameTimeMs) {
		// Update your animation state here
		// For example: move an object, change its color, etc.

		lastUpdateTime = currentTime;
		glutPostRedisplay(); // Trigger a redisplay
	}
}

void keyInput(unsigned char key, int x, int y)
{
	cout << "key input = " << key << endl;

	if (key == 'r')
	{
		red = 1.0f;
		green = 0.0f;
		blue = 0.0f;
	}
	else if (key == 'g')
	{
		red = 0.0f;
		green = 1.0f;
		blue = 0.0f;
	}
	else if (key == 'b')
	{
		red = 0.0f;
		green = 0.0f;
		blue = 1.0f;
	}
	else if (key == '+')
	{
		dangle = DANGLE;
	}
	else if (key == '-')
	{
		dangle = -1.0f * DANGLE;
	}
	else if (key == 27)
	{
		exit(0);
	}
}

//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
//	glutInitWindowPosition(10, 10);
//	glutInitWindowSize(640, 360);
//	glutCreateWindow("Test GLUT");
//
//	glutDisplayFunc(renderScene);
//	glutIdleFunc(idleScene);
//	glutKeyboardFunc(keyInput);
//
//	glutMainLoop();
//	return 0;
//}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(640, 360);
	glutCreateWindow("Test GLUT");

	glutDisplayFunc(renderScene);
	glutIdleFunc(idleScene);
	glutKeyboardFunc(keyInput);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

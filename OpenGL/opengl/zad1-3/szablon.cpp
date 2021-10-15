#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "shader_stuff.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#include <math.h>

int VAL;
// ---------------------------------------
// Identyfikatory obiektow

GLuint idProgram;   // programu
GLuint idVAO;       // tablic wierzcholkow
GLuint idVBO_coord; // bufora wierzcholkow
GLuint idVBO_color; // bufora wierzcholkow
GLuint idVBO_size;  // bufora wierzcholkow

// ---------------------------------------
//zad2
// GLfloat coord[10000];

// GLfloat color[10000];

//zad3
GLfloat coord[1000];
GLfloat color[10000];
GLfloat size[10000];

// ---------------------------------------
void DisplayScene()
{

      glClear(GL_COLOR_BUFFER_BIT);

      // Wlaczenie VAO i programu
      glBindVertexArray(idVAO);
      glUseProgram(idProgram);

      // Generowanie obiektow na ekranie
      glDrawArrays(GL_POINTS, 0, VAL);

      // Wylaczanie
      glUseProgram(0);
      glBindVertexArray(0);

      glutSwapBuffers();
}

// ---------------------------------------
void Initialize()
{

      glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
      glEnable(GL_PROGRAM_POINT_SIZE);
      // 1. Program i shadery
      idProgram = glCreateProgram();

      glAttachShader(idProgram, LoadShader(GL_VERTEX_SHADER, "vertex.glsl"));
      glAttachShader(idProgram, LoadShader(GL_FRAGMENT_SHADER, "fragment.glsl"));

      LinkAndValidateProgram(idProgram);

      // 2. Vertex arrays
      glGenVertexArrays(1, &idVAO);
      glBindVertexArray(idVAO);

      // Bufor na wspolrzedne wierz
      glGenBuffers(1, &idVBO_coord);
      glBindBuffer(GL_ARRAY_BUFFER, idVBO_coord);
      glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_STATIC_DRAW);
      //podejemy parametry atrybutu: atr o ind 0 składa sie z 2 floatów
      glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
      glEnableVertexAttribArray(0);

      // Bufor na wspolrzedne kolor
      glGenBuffers(1, &idVBO_color);
      glBindBuffer(GL_ARRAY_BUFFER, idVBO_color);
      glBufferData(GL_ARRAY_BUFFER, VAL * 3 * sizeof(GLfloat), color, GL_STATIC_DRAW);
      //podejemy parametry atrybutu: atr o ind 0 składa sie z 2 floatów
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
      glEnableVertexAttribArray(1);

      glGenBuffers(1, &idVBO_size);
      glBindBuffer(GL_ARRAY_BUFFER, idVBO_size);
      glBufferData(GL_ARRAY_BUFFER, sizeof(size), size, GL_STATIC_DRAW);
      //podejemy parametry atrybutu: atr o ind 0 składa sie z 2 floatów
      glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, NULL);
      glEnableVertexAttribArray(2);

      glBindVertexArray(0);
}

// ---------------------------------------
void Reshape(int width, int height)
{
      glViewport(0, 0, width, height);
}

// ---------------------------------------------------
void Keyboard(unsigned char key, int x, int y)
{
      switch (key)
      {
      case 27: // ESC key
            exit(0);
            break;

      case ' ':
            printf("SPACE\n");
            // odswiezenie ekranu
            glutPostRedisplay();
            break;
      }
}

// ---------------------------------------------------
int main(int argc, char *argv[])
{
      //zad3
      const float MIN_RAND = -1.0, MAX_RAND = 1.0;
      const float range = MAX_RAND - MIN_RAND;
      VAL = rand() % 100;
      cout << VAL;
      for (int i = 0; i < VAL * 2; i++)
      {
            coord[i] = floorf((range * ((((float)rand()) / (float)RAND_MAX)) + MIN_RAND) * 100) / 100;
      }

      for (int i = 0; i < (VAL * 3); i++)
      {
            color[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      };
      for (int i = 0; i < VAL; i++)
      {
            size[i] = rand() % 10;
            cout << size[i];
      };

      //zad2
      // int x;
      // cout << "How many triangles do you want to create?";
      // cin >> x;
      // VAL = x;
      // const float MIN_RAND = -1.0, MAX_RAND = 1.0;
      // const float range = MAX_RAND - MIN_RAND;
      // for (int i = 0; i < (x * 6); i++)
      // {
      //       coord[i] = floorf((range * ((((float)rand()) / (float)RAND_MAX)) + MIN_RAND) * 100) / 100;
      // };
      // for (int i = 0; i < (x * 9); i++)
      // {
      //       color[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      // };

      // GLUT
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitContextVersion(3, 2);
      glutInitContextProfile(GLUT_CORE_PROFILE);
      glutInitWindowSize(500, 500);
      glutCreateWindow("OpenGL!");
      glutDisplayFunc(DisplayScene);
      glutReshapeFunc(Reshape);

      // Keyboard
      glutKeyboardFunc(Keyboard);

      // GLEW
      glewExperimental = GL_TRUE;
      GLenum err = glewInit();
      if (GLEW_OK != err)
      {
            printf("GLEW Error\n");
            exit(1);
      }

      // OpenGL
      if (!GLEW_VERSION_3_2)
      {
            printf("Brak OpenGL 3.2!\n");
            exit(1);
      }

      Initialize();

      glutMainLoop();

      // Cleaning
      glDeleteProgram(idProgram);
      glDeleteVertexArrays(1, &idVBO_coord);
      glDeleteVertexArrays(1, &idVAO);

      return 0;
}
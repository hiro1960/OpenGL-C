#include <GL/glut.h>

void display(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);// 画面のクリア色(背景色)
  glClear(GL_COLOR_BUFFER_BIT);// バッファのクリア
  glColor4f(0.7, 0.2, 0.2, 0.0);
  glRectf(-0.5, 0.5, 0.5, -0.5);
  glFlush();// コマンドの実行
}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100, 100);// 画面の出現位置
  glutInitWindowSize(400, 300);// 画面サイズ(400*300px)
  glutInit(&argc, argv);// GLUTの初期化
  glutInitDisplayMode(GLUT_RGBA);// 画面のモード(RGBA色空間を使う)
  glutCreateWindow("Test");// 画面の名前
  glutDisplayFunc(display);// GLUTの再描画関数を登録
  glutMainLoop();// イベントループを繰り返し実行
  return 0;
}

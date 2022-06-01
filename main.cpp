#include <iostream>
#include "header.h"

using namespace std;

int main() {
  //вывод в поток и ввод из потока;
  Vector a;
  a.Write(10);
  Vector b;
  b.Write(10);
  Vector d = a; //конструктор копирования
  b[4]=a[4]; 
  SafeVector c;
  c.Write(8);
  c.ShowVector(2,7);
  a[4]=5;

  cout << a;
}
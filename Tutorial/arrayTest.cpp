#include <iostream>
#include <string>

using namespace std;

int main()
{
  string text[5] = {"a", "b", "c", "d", "e"};
  for (int i = 4; i > 0; i--)
  {
    text[i] = text[i - 1];
  }
  cout << text[2] << " " << text[3] << " " << text[4] << endl;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  int a = 0;
  int b = 0;
  int m = 1;
  cout << "Give a number:" << endl;
  cin >> n;
  if (n > 0) {
    while ( a < n )
	{
	  cout << a << endl;
	  a = m + b;
	  b = m;
	  m = a;
	}
  }
  return 0;
}
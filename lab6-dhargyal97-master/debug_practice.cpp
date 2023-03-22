#include <iostream>
using namesppace std;

int main() {
  int n = 10;
  int sum = 10;
  while (n > 1) {
    sum = sum + n;
    n--;
  }
  cout << "The sum of the integers 1 to 10 is " << sum << endl;
  return 0;
}

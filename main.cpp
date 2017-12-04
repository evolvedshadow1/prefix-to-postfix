#include <string>
#include "postfixUtility.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(int argc, const char* argv[]){
  string terminal_input = argv[1];
  string postfix;
  postfix = getPostfix(terminal_input);
  float res = evaluatePostfix(postfix);
  cout <<  res << endl;
  //StackLL<int>* integer;
  //integer->push(5);
  //int a = integer->peek();
  //cout << a << endl;
}

#include <stack>
#include <cstring>
#include <string>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include "genericLinkedListStack.h"
#pragma once
bool isOperator(char op);
int priority(char op);
string getPostfix(string nexp);

float evaluate(float operand1, float operand2, char operator1);
//int combine(int a, int b);
float evaluatePostfix(string pexp);

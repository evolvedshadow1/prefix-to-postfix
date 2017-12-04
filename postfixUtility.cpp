#include "postfixUtility.h"
bool isOperator(char op){
  if(op == '+' || op == '-' || op == '*' || op == '/'){
    return true;
  }else{
    return false;
  }
}
int priority(char op){
  int priority = 0;
  if(op == '*' || op == '/'){
    priority = 2;
  }if(op == '+' || op == '-'){
    priority = 1;
  }
  return priority;
}
string getPostfix(string nexp){
  stack<char> operators;
  stringstream postfix;
  char current;
  int i=0;
  int weight;
  while(i<nexp.length()){
    current = nexp[i];
    if(current == '('){
      operators.push(current);
      i++;
      continue;
    }if(current == ')'){
      while(!operators.empty() && operators.top() != '('){
        postfix << ' ' << operators.top();
        operators.pop();
      }
      postfix << ' ';
      if(!operators.empty()){
        operators.pop();
      }
      i++;
      continue;
    }
    weight = priority(current);
    if(weight == 0){
      postfix << current;
      if(nexp[i+1] != NULL && priority(nexp[i+1]) != 0){
        postfix << ' ';
      }
    }else{
      if(operators.empty()){
        operators.push(current);
      }else{
        while(!operators.empty() && operators.top() != '(' && weight <= priority(operators.top())){
          postfix << operators.top();
          postfix << ' ';
          operators.pop();
        }
        operators.push(current);
      }
    }
    i++;
  }
  while(!operators.empty()){
    postfix << operators.top();
    operators.pop();
  }
  return postfix.str();
}

float evaluate(float operand1, float operand2, char operator1){
  switch (operator1){
        case '+' : return(operand2 + operand1);
        case '-' : return(operand2 - operand1);
        case '*' : return(operand2 * operand1);
        case '/' : return(operand2 / operand1);
        default: return 0;
  }
}
/*
int combine(int a, int b) {
   int times = 1;
   while (times <= b)
      times *= 10;
   return a*times + b;
}
*/
float evaluatePostfix(string pexp){
  int i;
  float result = 0;
  float operand_1, operand_2;
  char operator_1;
  stringstream postfix;
  stack<float> integer;
  for(i=0;i<pexp.length();i++){
    if(isdigit(pexp[i])){
      int operand = 0;
      while(i<pexp.length() && isdigit(pexp[i])){
        operand = (operand*10) + (pexp[i]-'0');
        i++;
      }
      i--;
      integer.push(operand);
    }else if(isOperator(pexp[i])){
      operator_1 = pexp[i];
      operand_1 = integer.top();
      integer.pop();
      operand_2 = integer.top();
      integer.pop();
      result = evaluate(operand_1, operand_2, operator_1);
      integer.push(result);
    }
  }
  return integer.top();
}
/*
    else if(isOperator(current) && integer->peek() != NULL){
      cout << '3';
      operand_1 = integer->peek();

      integer->pop();
      operand_2 = integer->peek();
      integer->pop();
      result = evaluate(operand_1, operand_2, current);
      integer->push(result);

      cout << '4';
    }
    else if(priority(current) == 0){
      int op = 0;
      while(i<pexp.length() && priority(current) == 0 && current != ' '){
        op = (op*10) + (current - '0');
        i++;
      }
      //i--;
      integer->push(op);

    }

  }
  /*
  return 1;
}
  /*
  for(i=0;i<pexp.length();i++){
  int tmp;
  while(isdigit(pexp[i])){
      getline(pexp, temp, ' ');
        int value1 = atoi(str1.c_str());
        integer.push(tmp);
        cout << "tmp is: " << tmp << endl;
      }
      else if(!isdigit(pexp[i+1]) && !isOperator(pexp[i+1]) && !isdigit(pexp[i-1])){
        cout << "single digit is: " << pexp[i] <<endl;;
        integer.push(pexp[i]-'0');
      }
      i++;

    }if(isOperator(pexp[i])){
        operator_1 = pexp[i];
        operand_1 = integer.top();
        integer.pop();
        operand_2 = integer.top();
        integer.pop();
        result = evaluate(operand_1, operator_1, operand_2);
      }
  }
  return result;
  */

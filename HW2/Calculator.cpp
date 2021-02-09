#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>

using namespace std;

#define OPERATOR "+-*/^()"
enum { NUM, OPER };

typedef struct inputqueue {
	short type;
	double value;
}input;

typedef queue<input> usrinput;

//괄호가 쌍을 이루는지 검사하는 함수
bool isPair(char opening, char closing);

//괄호를 검사하는 함수
bool is_balanced_parenthese(string st);

//연산자의 우선 순위를 지정하는 함수
int order(char oper);

//연산자의 우선 순위를 비교하는 함수
int get_Priority(char op1, char op2);

//operator 과 operand 를 나눠 처리하는 함수
void input_usrinput(bool * dot, bool * num, int * point, double * number, char tok, usrinput * usrput);

//사용자 입력을 queue<input> 으로 바꾸는 함수
usrinput string_to_queue(char * string);

//postfix 수식을 계산하는 함수
usrinput postfix_cal(usrinput exp);

//두 개의 operands 와 operator 를 인자로 받아 계산하는 함수
double cal(double num1, double num2, char op);

//변환된 postfix 를 계산하는 함수
double evaluate_postfix(usrinput usrinput);

//계산식을 읽고 계산하는 함수
double read_and_evaluate(char *str);

int main(void) {
	int size = 1000;
	char * input = (char *)malloc(sizeof(char) * size);
	long double result = 0;

	while (1) {
		cin >> input;
		if (!strcmp(input, "EOI"))
			break;

		result = read_and_evaluate(input);

		if (!is_balanced_parenthese(input)) {
			cout << "Error!: unbalanced parentheses";
		}
		else if (result == -123456)
		{
			cout << "Error!: divide by zero";
		}
		else {
			result = (floor((result * 1000) + 0.5)) / 1000;
			cout << result;
		}

		cout << endl << endl;
	}
	return 0;
}

bool isPair(char opening, char closing) {
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;

}

bool is_balanced_parenthese(string st) {
	stack<char> S;

	for (int i = 0; i < st.length(); i++) {
		if (st[i] == '(' || st[i] == '{' || st[i] == '[')
			S.push(st[i]);

		else if (st[i] == ')' || st[i] == '}' || st[i] == ']')
		{
			if (S.empty() || !isPair(S.top(), st[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int order(char oper) {

	switch (oper)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1;
	}

	return -1;
}

int get_Priority(char op1, char op2)
{
	int op1_priority = order(op1);
	int op2_priority = order(op2);

	if (op1_priority > op2_priority)
		return 1;
	else if (op1_priority < op2_priority)
		return -1;
	else
		return 0;
}

void input_usrinput(bool * dot, bool * num, int * point, double * number, char op, usrinput * usrput) {
	input que;

	if (*num) {

		*number /= pow(10, *point);
		que.type = NUM;
		que.value = *number;
		(*usrput).push(que);
		*number = *point = 0;
		*dot = *num = false;
	}

	if (strchr("{[", op))
		op = '(';
	else if (strchr("}]", op))
		op = ')';

	{
		if (strchr(OPERATOR, op))
			que.type = OPER;
	}

	que.value = op;
	(*usrput).push(que);

}

usrinput string_to_queue(char * string) {
	bool dot_or_not = false, num = false;
	int decimal_point = 0;
	double number = 0;
	char operand;

	usrinput result;
	input input_Queue;

	for (int i = 0; string[i] != NULL; i++) {
		operand = string[i];
		if (operand == '.') {
			dot_or_not = true;
			decimal_point = 0;
		}

		else if (isdigit(operand)) {
			num = true;
			number *= 10;
			number += operand - '0';

			if (dot_or_not)
				decimal_point++;
		}

		else
			input_usrinput(&dot_or_not, &num, &decimal_point, &number, operand, &result);
	}

	if (number != 0) {

		number /= pow(10, decimal_point);
		input_Queue.type = NUM;
		input_Queue.value = number;
		result.push(input_Queue);
	}

	return result;
}


usrinput postfix_cal(usrinput usr_input) {
	char operators;

	stack <char> store_to_stack;
	usrinput infix_to_postfix;
	input input_Tok, input_queue;

	while (!usr_input.empty()) {

		input_Tok = usr_input.front();
		usr_input.pop();

		if (input_Tok.type == NUM)
			infix_to_postfix.push(input_Tok);

		else if (input_Tok.type == OPER)
		{
			switch ((char)input_Tok.value)
			{
			case '(':
				store_to_stack.push((char)input_Tok.value);
				break;

			case ')':
				while (1) {
					operators = store_to_stack.top();
					store_to_stack.pop();

					if (operators == '(')
						break;

					input_queue.type = OPER;
					input_queue.value = (double)operators;
					infix_to_postfix.push(input_queue);
				}
				break;

			default:
				input_queue.type = OPER;
				while (!store_to_stack.empty() && get_Priority(store_to_stack.top(), (char)input_Tok.value) >= 0) {
					input_queue.value = (double)store_to_stack.top();
					infix_to_postfix.push(input_queue);
					store_to_stack.pop();
				}
				store_to_stack.push((char)input_Tok.value);
				break;
			}
		}
	}
	while (!store_to_stack.empty()) {
		input_queue.type = OPER;
		input_queue.value = (double)store_to_stack.top();
		infix_to_postfix.push(input_queue);
		store_to_stack.pop();
	}

	return infix_to_postfix;
}

double cal(double num1, double num2, char op) {

	switch (op)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case'/':
	{
		if (num2 == 0)
			return -123456;
		else
			return num1 / num2;
	}
	break;
	}
}

double evaluate_postfix(usrinput usrinput) {
	stack <double> numbers;
	input first;
	double num1, num2;

	while (!usrinput.empty()) {
		first = usrinput.front();
		usrinput.pop();

		if (first.type == NUM)
			numbers.push(first.value);

		else if (first.type == OPER) {
			num2 = numbers.top();
			numbers.pop();

			num1 = numbers.top();
			numbers.pop();

			numbers.push(cal(num1, num2, (char)first.value));
		}
	}
	return numbers.top();
}

double read_and_evaluate(char *str) {
	usrinput usr_input;
	double answer;

	usr_input = string_to_queue(str);

	usr_input = postfix_cal(usr_input);
	answer = evaluate_postfix(usr_input);
	return answer;
}




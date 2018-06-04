//#ifndef H_InfixToPostfix
//#define H_InfixToPostfix
#include "Stack.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class infixToPostfix
{
public:
	infixToPostfix() {
		ifx = "";
		pfx = "";
	}

	infixToPostfix(string str) {
		ifx = str;
		pfx = "";
	}

	int precedence(char opr) {
		if (opr == '{' || opr == '}' || opr == '[' || opr == ']' || opr == '(' || opr == ')') {
			return 4;
		}
		else if (opr == '^') {
			return 3;
		}
		else if (opr == '%' || opr == '/' || opr == '*') {
			return 2;
		}
		else if (opr == '+' || opr == '-') {
			return 1;
		}
		else if (opr == NULL) {
			return 0;
		}
		return 0;
	}
	bool isOperator(char opr) {
		if (opr == '{' || opr == '}' || opr == '[' || opr == ']' || opr == '(' || opr == ')' || opr == '^' || opr == '+' || opr == '-' || opr == '+' || opr == '-') {
			return true;
		}
		else {
			return false;
		}
		return false;
	}
	void getInfix(string str) {
		ifx = str;
		return;
	}
	void showInfix() {
		for (int i = 0; i < ifx.length(); i++) {
			cout << ifx[i];
		}
		cout << endl;
	}
	void showPostfix() {
		for (int i = 0; i < pfx.length(); i++) {
			cout << pfx[i];
		}
		cout << endl;
	}
	void convertToPostfix() {
		Stack stack;
		char temp;
		pfx = "";
		for (int i = 0; i < ifx.length(); i++) {
			if (isOperator(ifx[i])) {
				if (!stack.isEmpty()) {
					temp = stack.peek();
					if (precedence(ifx[i]) > precedence(temp)) {
						pfx = pfx + ifx[i];
					}
					else if (precedence(ifx[i]) < precedence(temp)) {
						pfx = pfx + stack.pop();
					}
					else {
						stack.push(ifx[i]);
					}
				}
				else {
					stack.push(ifx[i]);
				}
			}
			else {
				pfx = pfx + ifx[i];
			}
		}
		while (!stack.isEmpty()) {
			pfx = pfx + stack.pop();
		}
	}

private:
	string  ifx;
	string  pfx;
};

int main() {
	infixToPostfix  InfixExp;

	string infix;
	ifstream infile;
	infile.open("infixData.txt");
	if (!infile) {
		cout << "Cannot open input file. Program terminates!!!" << endl; return 1;
	}
	getline(infile, infix);

	while (infile)
	{
		InfixExp.getInfix(infix);
		InfixExp.showInfix();
		InfixExp.convertToPostfix();
		InfixExp.showPostfix();
		cout << endl;
		getline(infile, infix);
	}
	system("pause");
	infile.close(); 
	
	return 0;
}

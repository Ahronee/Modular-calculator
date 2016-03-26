#ifndef MODULARCALCULATOR_H
#define MODULARCALCULATOR_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using std::string;
using std::vector;
using std::cin;


class CalculatorOperation {
public:
	virtual bool supportsOperation(string) = 0;
	virtual int requiredParameters() = 0;
	virtual double calcResult(double, vector<string>) = 0;
};

class Add : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s== "Add" || s == "add" || s == "+"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr + stod(params[0]); }
};

class Sub : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Sub" || s == "sub" || s == "-"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr - stod(params[0]); }
};

class Mult : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Mul" || s == "mul" || s == "*"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr * stod(params[0]); }
};

class Div : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Div" || s == "div" || s == "/"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return curr / stod(params[0]); }
};

class Sqrt : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Sqrt" || s == "sqrt"); }
	int requiredParameters() { return 0; }
	double calcResult(double curr, vector<string> params) { return sqrt(curr); }
};

class Pow : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Pow" || s == "pow" || s == "^"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return pow(curr, stod(params[0])); }
};

class Ln : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Ln" || s == "ln"); }
	int requiredParameters() { return 0; }
	double calcResult(double curr, vector<string> params) { return log(curr); }
};

class Log10 : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "log10" || s == "Log10"); }
	int requiredParameters() { return 0; }
	double calcResult(double curr, vector<string> params) { return log10(curr); }
};

class Log2 : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return(s == "log2" || s == "Log2"); }
	int requiredParameters() { return 0; }
	double calcResult(double curr, vector<string> params) { return log2(curr); }
};

class Exp : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Exp" || s == "exp"); }
	int requiredParameters() { return 0; }
	double calcResult(double curr, vector<string> params) { return exp(curr); }
};

class Set : public CalculatorOperation {
public:
	bool supportsOperation(string s) { return (s == "Set" || s == "set"); }
	int requiredParameters() { return 1; }
	double calcResult(double curr, vector<string> params) { return stod(params[0]); }
};

const int OPERATIONS = 11;

class Calculator {
	double curr;
	CalculatorOperation* op[OPERATIONS];
public:
	Calculator() : curr(0.0) {
		op[0] = new Add();
		op[1] = new Sub();
		op[2] = new Mult();
		op[3] = new Div();
		op[4] = new Sqrt();
		op[5] = new Pow();
		op[6] = new Ln();
		op[7] = new Log10();
		op[8] = new Log2();
		op[9] = new Exp();
		op[10] = new Set();
	}
	~Calculator() {
		for (int i = 0; i < OPERATIONS; i++) {
			delete op[i];
		}
	}
	double calculate(string operation) {
		int i = 0;
		for (; i < OPERATIONS; i++)
			if (op[i]->supportsOperation(operation))
				break;
		if (i == OPERATIONS)
			throw "Illegal operation.";
		int num = op[i]->requiredParameters();
		vector<string> parameters(num);
		for (int j = 0; j < num; j++)
			cin >> parameters[j];
		curr = op[i]->calcResult(curr, parameters);
		return curr;
	}
};

#endif
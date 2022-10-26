#pragma once
#include"Lex.h"
#include"Syntax.h"
#include<iostream>
#include<string>
class analyzer
{
public:
	analyzer();
	Lex lex;
	Syntax syntax;
	bool errorFlag;
	string errorMsg;
	vector<pair<string, double>> tokens;
	void initLex();
	double compute(string input);
	void printTokens();
};


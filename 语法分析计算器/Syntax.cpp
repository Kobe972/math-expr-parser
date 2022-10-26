#include "Syntax.h"
double sec(double x)
{
	return 1 / cos(x);
}
double csc(double x)
{
	return 1 / sin(x);
}
double Syntax::E()
{
	double val1, val2;
	val1 = F();
	if (errorMsg.flag) return -1;
	if (lookahead() == "+")
	{
		match("+");
		if (errorMsg.flag) return -1;
		val2 = E();
		if (errorMsg.flag) return -1;
		return val1 + val2;
	}
	else if (lookahead() == "-")
	{
		match("-");
		if (errorMsg.flag) return -1;
		val2 = E();
		if (errorMsg.flag) return -1;
		return val1 - val2;
	}
	else return val1;
}

double Syntax::F()
{
	double val1, val2, val3;
	double(*val4)(double);
	val1 = T();
	if (errorMsg.flag) return -1;
	if (lookahead() == "*")
	{
		match("*");
		if (errorMsg.flag) return -1;
		val2 = F();
		if (errorMsg.flag) return -1;
		val3 = M();
		if (errorMsg.flag) return -1;
		return val1 * val2*val3;
	}
	else if (lookahead() == "^")
	{
		match("^");
		if (errorMsg.flag) return -1;
		val2 = F();
		if (errorMsg.flag) return -1;
		val3 = M();
		if (errorMsg.flag) return -1;
		return pow(val1, val2)*val3;
	}
	else if (lookahead() == "(" || lookahead() == "sin" || lookahead() == "cos" || lookahead() == "tan" || lookahead() == "cot" || lookahead() == "csc" ||
		lookahead() == "sec" || lookahead() == "arcsin" || lookahead() == "arccos" || lookahead() == "arctan" || lookahead() == "log" || lookahead() == "exp" ||
		lookahead() == "ln" || lookahead() == "sqrt"|| lookahead() == "log"|| lookahead() == "digits"|| lookahead() == "e"|| lookahead() == "pi")
	{
		val2 = T();
		if (errorMsg.flag) return -1;
		val3 = M();
		if (errorMsg.flag) return -1;
		return val1 * val2*val3;
	}
	else
	{
		val2 = M();
		if (errorMsg.flag) return -1;
		return val1 * val2;
	}
}

double Syntax::T()
{
	double val1, val2, val3;
	double(*val4)(double);
	if (lookahead() == "(")
	{
		match("(");
		if (errorMsg.flag) return -1;
		val2 = E();
		if (errorMsg.flag) return -1;
		match(")");
		if (errorMsg.flag) return -1;
		return val2;
	}
	if (lookahead() == "sin" || lookahead() == "cos" || lookahead() == "tan" || lookahead() == "cot" || lookahead() == "csc" ||
	lookahead() == "sec" || lookahead() == "arcsin" || lookahead() == "arccos" || lookahead() == "arctan" || lookahead() == "exp" ||
	lookahead() == "ln" || lookahead() == "sqrt")
	{
		val4 = func();
		if (lookahead() == "^")
		{
			match("^");
			if (errorMsg.flag) return -1;
			val3 = Num();
			if (errorMsg.flag) return -1;
			val2 = F();
			if (errorMsg.flag) return -1;
			return pow(val4(val2), val3);
		}
		else
		{
			val2 = F();
			if (errorMsg.flag) return -1;
			return val4(val2);
		}
	}
	else if (lookahead() == "log")
	{
		match("log"); match("("); if (errorMsg.flag) return -1;
		val2 = E(); if (errorMsg.flag) return -1;
		match(","); if (errorMsg.flag) return -1;
		val3 = E(); if (errorMsg.flag) return -1;
		match(")"); if (errorMsg.flag) return -1;
		if (val2 == 0)
		{
			errorMsg.flag = true;
			errorMsg.info = "Divided by 0 at token " + to_string(currentPos);
			return -1;
		}
		return log(val3) / log(val2);
	}
	else if (lookahead() == "digits" || lookahead() == "pi" || lookahead() == "e")
	{
		val2 = Num(); if (errorMsg.flag) return -1;
		return val2;
	}
	else
	{
		errorMsg.flag = true;
		errorMsg.info = "Expected formula after token " + to_string(currentPos);
		return -1;
	}
}

double Syntax::M()
{
	double val1, val2;
	if (lookahead() == "/")
	{
		match("/");
		val1 = T(); if (errorMsg.flag) return -1;
		val2 = M(); if (errorMsg.flag) return -1;
		if (val1*val2 == 0)
		{
			errorMsg.flag = true;
			errorMsg.info = "Divided by 0 at token " + to_string(currentPos);
			return -1;
		}
		return 1 / val1 / val2;
	}
	else
	{
		return 1;
	}
}

double(*Syntax::func())(double)
{
	if (lookahead() == "sin")
	{
		match("sin");
		return sin;
	}
	else if (lookahead() == "cos")
	{
		match("cos");
		return cos;
	}
	else if (lookahead() == "tan")
	{
		match("tan");
		return tan;
	}
	else if (lookahead() == "sec")
	{
		match("sec");
		return sec;
	}
	else if (lookahead() == "csc")
	{
		match("csc");
		return csc;
	}
	else if (lookahead() == "arcsin")
	{
		match("arcsin");
		return asin;
	}
	else if (lookahead() == "arccos")
	{
		match("arccos");
		return acos;
	}
	else if (lookahead() == "arctan")
	{
		match("arctan");
		return atan;
	}
	else if (lookahead() == "exp")
	{
		match("exp");
		return exp;
	}
	else if (lookahead() == "ln")
	{
		match("ln");
		return log;
	}
	else if (lookahead() == "sqrt")
	{
		match("sqrt");
		return sqrt;
	}
	else
	{
		errorMsg.flag = true;
		errorMsg.info = "Syntax error at token " + to_string(currentPos) + ". Expected to be a function name";
		return NULL;
	}
}

double Syntax::Num()
{
	if (lookahead() == "digits") return match("digits");
	else if (lookahead() == "e") return match("e");
	else if (lookahead() == "pi") return match("pi");
	else
	{
		errorMsg.flag = true;
		errorMsg.info = "Syntax error at token " + to_string(currentPos) + ". Expected to be a number";
		return -1;
	}
}

double Syntax::match(string token)
{
	pair<string, double> _token = tokens[currentPos];
	if (_token.first != token)
	{
		errorMsg.flag = true;
		errorMsg.info = "Syntax error. Expected '" + token + "' after token " + to_string(currentPos) + " but got " + _token.first;
		return -1;
	}
	currentPos++;
	return _token.second;
}

string Syntax::lookahead()
{
	return tokens[currentPos].first;
	return string();
}

double Syntax::compute(vector<pair<string, double>> _tokens)
{
	errorMsg.flag = false;
	currentPos = 0;
	tokens = _tokens;
	double val = E();
	if (errorMsg.flag) return -1;
	return val;
}

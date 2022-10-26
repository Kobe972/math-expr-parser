#include "analyzer.h"

analyzer::analyzer()
{
	initLex();
}

void analyzer::initLex()
{
	for (int i = 0; i < 60; i++)
	{
		lex.nodes[i].accept = false;
	}
	lex.makeLink(0, '+', 1);
	lex.makeLink(0, '-', 1);
	lex.makeLink(0, 0, 1);
	lex.makeLink(0, '$', 0);
	lex.makeLink(1, '0', 2);
	lex.makeLink(1, '1', 2);
	lex.makeLink(1, '2', 2);
	lex.makeLink(1, '3', 2);
	lex.makeLink(1, '4', 2);
	lex.makeLink(1, '5', 2);
	lex.makeLink(1, '6', 2);
	lex.makeLink(1, '7', 2);
	lex.makeLink(1, '8', 2);
	lex.makeLink(1, '9', 2);
	lex.makeLink(1, '.', 3);
	lex.makeLink(1, '(', 6);
	lex.makeLink(1, ')', 7);
	lex.makeLink(1, 's', 8);
	lex.makeLink(1, 'c', 13);
	lex.makeLink(1, 'l', 37);
	lex.makeLink(1, 't', 18);
	lex.makeLink(1, 'p', 45);
	lex.makeLink(1, 'a', 22);
	lex.makeLink(1, 'e', 41);
	lex.makeLink(1, '+', 47);
	lex.makeLink(1, '-', 48);
	lex.makeLink(1, '*', 49);
	lex.makeLink(1, '/', 50);
	lex.makeLink(1, '^', 51);
	lex.makeLink(1, ',', 52);
	lex.makeLink(1, '$', 0);
	lex.makeLink(1, 0, 53);
	lex.makeLink(2, '0', 2);
	lex.makeLink(2, '1', 2);
	lex.makeLink(2, '2', 2);
	lex.makeLink(2, '3', 2);
	lex.makeLink(2, '4', 2);
	lex.makeLink(2, '5', 2);
	lex.makeLink(2, '6', 2);
	lex.makeLink(2, '7', 2);
	lex.makeLink(2, '8', 2);
	lex.makeLink(2, '9', 2);
	lex.makeLink(2, '.', 3);
	lex.makeLink(2, 0, 5);
	lex.makeLink(3, '0', 4);
	lex.makeLink(3, '1', 4);
	lex.makeLink(3, '2', 4);
	lex.makeLink(3, '3', 4);
	lex.makeLink(3, '4', 4);
	lex.makeLink(3, '5', 4);
	lex.makeLink(3, '6', 4);
	lex.makeLink(3, '7', 4);
	lex.makeLink(3, '8', 4);
	lex.makeLink(3, '9', 4);
	lex.makeLink(3, 0, 53);
	lex.makeLink(4, '0', 4);
	lex.makeLink(4, '1', 4);
	lex.makeLink(4, '2', 4);
	lex.makeLink(4, '3', 4);
	lex.makeLink(4, '4', 4);
	lex.makeLink(4, '5', 4);
	lex.makeLink(4, '6', 4);
	lex.makeLink(4, '7', 4);
	lex.makeLink(4, '8', 4);
	lex.makeLink(4, '9', 4);
	lex.makeLink(4, 0, 5);
	lex.makeLink(5, 0, 1);
	lex.setAccept(5, true);
	lex.makeLink(6, 0, 0);
	lex.setAccept(6, true);
	lex.makeLink(7, 0, 1);
	lex.setAccept(7, true);
	lex.makeLink(8, 'q', 34);
	lex.makeLink(8, 'i', 9);
	lex.makeLink(8, 'e', 11);
	lex.makeLink(8, 0, 53);
	lex.makeLink(9, 'n', 10);
	lex.makeLink(9, 0, 53);
	lex.makeLink(10, 0, 0);
	lex.setAccept(10, true);
	lex.makeLink(11, 'c', 12);
	lex.makeLink(11, 0, 53);
	lex.makeLink(12, 0, 0);
	lex.setAccept(12, true);
	lex.makeLink(13, 'o', 14);
	lex.makeLink(13, 's', 16);
	lex.makeLink(13, 0, 53);
	lex.makeLink(14, 's', 15);
	lex.makeLink(14, 't', 21);
	lex.makeLink(14, 0, 53);
	lex.makeLink(15, 0, 0);
	lex.setAccept(15, true);
	lex.makeLink(16, 'c', 17);
	lex.makeLink(16, 0, 53);
	lex.makeLink(17, 0, 0);
	lex.setAccept(17, true);
	lex.makeLink(18, 'a', 19);
	lex.makeLink(18, 0, 53);
	lex.makeLink(19, 'n', 20);
	lex.makeLink(19, 0, 53);
	lex.makeLink(20, 0, 0);
	lex.setAccept(20, true);
	lex.makeLink(21, 0, 0);
	lex.setAccept(21, true);
	lex.makeLink(22, 'r', 23);
	lex.makeLink(22, 0, 53);
	lex.makeLink(23, 'c', 24);
	lex.makeLink(23, 0, 53);
	lex.makeLink(24, 's', 25);
	lex.makeLink(24, 'c', 28);
	lex.makeLink(24, 't', 31);
	lex.makeLink(24, 0, 53);
	lex.makeLink(25, 'i', 26);
	lex.makeLink(25, 0, 53);
	lex.makeLink(26, 'n', 27);
	lex.makeLink(26, 0, 53);
	lex.makeLink(27, 0, 0);
	lex.setAccept(27, true);
	lex.makeLink(28, 'o', 29);
	lex.makeLink(28, 0, 53);
	lex.makeLink(29, 's', 30);
	lex.makeLink(29, 0, 53);
	lex.makeLink(30, 0, 0);
	lex.setAccept(30, true);
	lex.makeLink(31, 'a', 32);
	lex.makeLink(31, 0, 53);
	lex.makeLink(32, 'n', 33);
	lex.makeLink(32, 0, 53);
	lex.makeLink(33, 0, 0);
	lex.setAccept(33, true);
	lex.makeLink(34, 'q', 35);
	lex.makeLink(34, 0, 53);
	lex.makeLink(35, 't', 36);
	lex.makeLink(35, 0, 53);
	lex.makeLink(36, 0, 0);
	lex.setAccept(36, true);
	lex.makeLink(37, 'n', 38);
	lex.makeLink(37, 'o', 39);
	lex.makeLink(37, 0, 53);
	lex.makeLink(38, 0, 0);
	lex.setAccept(38, true);
	lex.makeLink(39, 'g', 40);
	lex.makeLink(39, 0, 53);
	lex.makeLink(40, 0, 0);
	lex.setAccept(40, true);
	lex.makeLink(41, 'x', 42);
	lex.makeLink(41, 0, 44);
	lex.makeLink(42, 'p', 43);
	lex.makeLink(42, 0, 53);
	lex.makeLink(43, 0, 0);
	lex.setAccept(43, true);
	lex.makeLink(44, 0, 1);
	lex.setAccept(44, true);
	lex.makeLink(45, 'i', 46);
	lex.makeLink(46, 0, 1);
	lex.setAccept(46, true);
	lex.makeLink(47, 0, 0);
	lex.setAccept(47, true);
	lex.makeLink(48, 0, 0);
	lex.setAccept(48, true);
	lex.makeLink(49, 0, 0);
	lex.setAccept(49, true);
	lex.makeLink(50, 0, 0);
	lex.setAccept(50, true);
	lex.makeLink(51, 0, 0);
	lex.setAccept(51, true);
	lex.makeLink(52, 0, 0);
	lex.setAccept(52, true);
	lex.makeLink(53, 0, 0);
	lex.setAccept(53, true);
}

double analyzer::compute(string input)
{
	input = input + "$";
	tokens.clear();
	tokens = lex.getTokens(input);
	if (lex.errorFlag)
	{
		errorFlag = lex.errorFlag;
		errorMsg = lex.errorMsg;
		return -1;
	}
	double result = syntax.compute(tokens);
	errorFlag = syntax.errorMsg.flag;
	errorMsg = syntax.errorMsg.info;
	if (syntax.errorMsg.flag) return -1;
	return result;
}

void analyzer::printTokens()
{
	for (int i = 0; i < tokens.size(); i++)
	{
		cout << "<" << tokens[i].first << "," << tokens[i].second << ">";
	}
	cout << endl;
}

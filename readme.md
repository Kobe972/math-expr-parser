# Math Expression Parser
使用词法分析和预测翻译器实现数学表达式的计算。

支持的语法：
* 四则运算、指数(^)
* 括号算符
* 括号的省略，如2(3+3)，sinsin30。
* 函数sin, cos, tan, cot, sec, csc, arcsin, arccos, arctan, ln, exp, sqrt, log，其中log是二元函数，用法为log(expr1,expr2)，第一个参数为底数。
* 数学常量pi, e。
* 表达式中不得含有空格，两个不同符号连到一起词法分析器会自动识别。
* 检测到输入闭合且后面不是正常语法定义的表达式后将自动忽略后半部分，如2+3)+2输出5

## 示例代码
见main.py
```c++
#include<iostream>
#include"analyzer.h"
int main()
{
	string input;
	analyzer _analyzer; //声明一个analyzer型类对象
	while (1)
	{
		cout << "> ";
		cin >> input;
		double result = _analyzer.compute(input); //调用compute方法进行对数学表达式的计算
		if (_analyzer.errorFlag) //errorFlag成员的值表示是否分析或计算过程遇到错误
		{
			cout << _analyzer.errorMsg << endl; //打印出错原因
		}
		else cout << result << endl;
	}
	return 0;
}
```
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, tempstr;
	cout << "Enter Str : ";
	getline(cin, str);
	int length = str.length();
	while (length >= 0)
	{
		if(str[length]=='(')
			tempstr.append(1, ')');
		else if(str[length] == ')')
			tempstr.append(1, '(');
		else
		    tempstr.append(1, str[length]);
		length--;
	}
	cout << "Temp : " << tempstr << endl;
	system("pause");
}
#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using std::string;
using std::cout;
using std::stack;


bool isNumber(char symbol) {
	return symbol >= '0' && symbol <= '9';
}

string decodeExpression(const string& expression) {
	unsigned length = expression.length();
	stack<int> numbers;
	stack<char> symbols;
	string result = "";
	for (unsigned i = 0; i < length; ++i) {
		if(isNumber(expression[i]))
        {
            numbers.push(expression[i] - '0');
        }
        else if(expression[i] == ']')
        {
            string temp = "";
            while(symbols.top() != '[')
            {
                temp.insert(0,1,symbols.top());
                symbols.pop();
            }
            cout << temp << '\n';
            
            assert(symbols.top() == '[');
            symbols.pop();
            size_t times = numbers.top();
            numbers.pop();
			for (size_t i = 0; i < times; i++) {
				for(size_t i = 0; i < temp.length(); i++)
                {
                    symbols.push(temp[i]);
                }
			}
		}
        else //no numbers or close brackets; symbol or '['
        {
            symbols.push(expression[i]);
        }
        result = "";
	}
    
    while(!symbols.empty()) {
        result.insert(0, 1, symbols.top());
        symbols.pop();
    }

    return result;
}

void testSimpleStr() {
    string str = "traicho2[ab]";

    string decoded = decodeExpression(str);
    std::cout << decoded << std::endl; 
    assert(decoded == "traichoabab");
}


void testStr2() {
    string str = "3[ac2[wfg]]"; 

    string decoded = decodeExpression(str);
    std::cout << decoded << std::endl; 
    assert(decoded == "acwfgwfgacwfgwfgacwfgwfg");
}

void testStr3() {
    string str = "abc3[cd]xyz";

    string decoded = decodeExpression(str);
    std::cout << decoded << std::endl; 
    assert(decoded == "abccdcdcdxyz");
}

void testStr4() {
    string str = "abc3[cd2[w]x2[q]]xyz";

    string decoded = decodeExpression(str);
    std::cout << decoded << std::endl; 
    assert(decoded == "abccdwwxqqcdwwxqqcdwwxqqxyz");
}

int main() {
    testSimpleStr();
    cout << '\n';
    testStr2();
    cout << '\n';
    testStr3();
    cout << '\n';
    testStr4();
    
    return 0;
}
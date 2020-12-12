// Kenan Yusein 71947.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <stack>


struct Node
{
	int data;
	Node *next;
};

void fillGaps(Node*& head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	Node* curr = head;
	Node* second = head->next;

	while (curr->next != nullptr)
	{
		int firstData = curr->data;
		int secondData = second->data;

		for (int i = firstData + 1; i < secondData; i++)
		{
			curr->next = new Node{i,nullptr};
			curr = curr->next;
		}
		curr->next = second;


		curr = second;
		second = curr->next;
	}

}

void printLList(Node* head)
{
	Node* curr = head;
	while (curr != nullptr)
	{
		std::cout << curr->data << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

void fillGapsTEST()
{
	Node* fillGapsTest = new Node{ 1, new Node{3, new Node{4, new Node{8, nullptr}}} };
	printLList(fillGapsTest);
	fillGaps(fillGapsTest);
	printLList(fillGapsTest);
}

std::string decode(const std::string& text)
{
	size_t size = text.length();

	std::string resultString;
	
	std::stack<std::string> resultStack;
	resultStack.push("");

	std::stack<int> numbers;

	for (size_t i = 0; i < size; i++)
	{	
		std::string temp;
		while (text[i] >= 'a' && text[i] <= 'z')
		{
			temp += text[i];
			++i;
		}
		resultStack.push(temp);

		int number = 0;
		if (text[i] >= '0' && text[i] <= '9')
		{
			number = text[i] - '0';
			numbers.push(number);
		}

		if (text[i] == ']')
		{
			std::string toRepeat = resultStack.top();
			resultStack.pop();

			for (size_t i = 1; i <= numbers.top() - 1; i++)
			{
				toRepeat += toRepeat;
			}
			numbers.pop();

			std::string newString = resultStack.top() + toRepeat;
			resultStack.pop();
			resultStack.push("");
			resultStack.push(newString);

		}
	}
	
	std::stack<std::string> reverseResultStack;
	while (!resultStack.empty())
	{
		reverseResultStack.push(resultStack.top());
		resultStack.pop();
	}

	while (!reverseResultStack.empty())
	{
		resultString += reverseResultStack.top();
		reverseResultStack.pop();
	}

	return resultString;
	
}

void decodeTEST()
{
	std::string test1 = "a2[ab]";
	std::string result = decode(test1);
	std::cout << "Test1: " << test1 << std::endl << "Result: " << result << std::endl;

	std::string test2 = "a2[kenan]2[yusein]";
	std::string result2 = decode(test2);
	std::cout << "Test2: " << test2 << std::endl << "Result: " << result2 << std::endl;


	std::string test3 = "c3[a2[w2[k]]]";
	std::string result3 = decode(test3); // acwfgwfg
	std::cout << "Test3: " << test3 << std::endl << "Result: " << result3 << std::endl;
}

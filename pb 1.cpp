#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
class Node {
public:
	char val;
	Node* st, * dr;
	Node(char v) {
		val = v;
		st = nullptr;
		dr = nullptr;
	}
};
void formaPoloneza(std::string expr, std::vector<char>& vector) {
	std::stack<char> stiva;
	for (int i = 0; i < expr.length(); i++) {
		if (isdigit(expr[i]))
			vector.push_back(expr[i]);
		else {
			if (stiva.empty() || expr[i] == '(')
				stiva.push(expr[i]);
			else {
				if (stiva.top() == '+') {
					if (expr[i] == '-') {
						vector.push_back(stiva.top());
						stiva.pop();
					}
					if (expr[i] != ')')
						stiva.push(expr[i]);
				}
				else if (stiva.top() == '-') {
					if (expr[i] == '+') {
						vector.push_back(stiva.top());
						stiva.pop();
					}
					if (expr[i] != ')')
						stiva.push(expr[i]);
				}
				else if (stiva.top() == '*') {
					if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/') {
						vector.push_back(stiva.top());
						stiva.pop();
						if (stiva.top() == '+' || stiva.top() == '-') {
							vector.push_back(stiva.top());
							stiva.pop();
						}
					}
					if (expr[i] != ')')
						stiva.push(expr[i]);
				}
				else if (stiva.top() == '/') {
					if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
						vector.push_back(stiva.top());
						stiva.pop();
						if (stiva.top() == '+' || stiva.top() == '-') {
							vector.push_back(stiva.top());
							stiva.pop();
						}
					}
					if (expr[i] != ')')
						stiva.push(expr[i]);
				}
				else if (stiva.top() == '(') {
					stiva.push(expr[i]);
				}
				if (expr[i] == ')') {
					while (stiva.top() != '(') {
						vector.push_back(stiva.top());
						stiva.pop();
					}
					stiva.pop();
				}
			}
		}
	}
	while (!stiva.empty()) {
		vector.push_back(stiva.top());
		stiva.pop();
	}
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector[i];
	}
	std::cout << std::endl;
}
Node* buildTree(std::vector<char>expr) {
	std::stack<Node*> stack;
	for (int i = 0; i < expr.size(); i++) {
		if (isdigit(expr[i])) {
			Node* n = new Node(expr[i]);
			stack.push(n);
		}
		else {
			Node* n = new Node(expr[i]);
			n->dr = stack.top();
			stack.pop();
			n->st = stack.top();
			stack.pop();
			stack.push(n);
		}
	}
	return stack.top();
}
void afisare(Node* root) {
	if (root == NULL)
		return;
	std::queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node* current = q.front();
			std::cout << current->val << " ";
			q.pop();
			if (current->st != nullptr)
				q.push(current->st);
			if (current->dr != nullptr)
				q.push(current->dr);
		}
		std::cout << std::endl;
	}
}
int main()
{
	std::string expresie = "(1+(2*3))+(4-(5*1))";
	std::vector<char> vector;
	Node* n;
	formaPoloneza(expresie, vector);
	n = buildTree(vector);
	afisare(n);
	return 0;
}

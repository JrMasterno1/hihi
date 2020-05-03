#include "function.h"

void InitNODE(Node*& p, string data) {
	p = new Node;
	p->data = data;
	p->next = NULL;
}
bool isEmpty(Stack s) {
	if (s.head == NULL) {
		return true;
	}
	return false;
}
void Push(Stack& s, string data)
{
	Node* p;
	InitNODE(p, data);
	p->next = s.head;
	s.head = p;
}
string Pop(Stack& s) {
	Node* temp = s.head;
	string data = temp->data;
	s.head = s.head->next;
	delete temp;
	return data;
}
int size(Stack s) {
	int size = 0;
	while (s.head != NULL) {
		++size;
		s.head = s.head->next;
	}
	return size;
}
void Empty(Stack& s) {
	while (s.head) {
		Node* temp = s.head;
		s.head = s.head->next;
		delete temp;
	}
}
Node* InitNODE(string data) {
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}
void Enqueue(Queue& q, string x) {
	if (q.head == NULL && q.tail == NULL) {
		q.head = q.tail = InitNODE(x);
	}
	else {
		q.tail->next = InitNODE(x);
		q.tail = q.tail->next;
	}
}
string Dequeue(Queue& q) {
	string temp = q.head->data;
	Node* del = q.head;
	q.head = q.head->next;
	delete del;
	return temp;
}
bool isEmpty(Queue q) {
	if (q.head == NULL) return true;
	return false;
}
int size(Queue q) {
	int s = 0;
	while (q.head) {
		++s;
		q.head = q.head->next;
	}
	return s;
}
void Empty(Queue& q) {
	while (q.head) {
		Node* del = q.head;
		q.head = q.head->next;
		delete del;
	}
}

double PolishNotation(string str) {
	Stack s; s.head = NULL;
	Queue q; q.head = q.tail = NULL;
	int i = 0;
	int n = str.length();
	int start = 0, end = 0;
	while (str[i] != NULL) {
		if (str[i] >= '0' && str[i] <= '9') {
			start = i;
			for (int j = i + 1; j < n; j++) {
				if (str[j] < '0' || str[j] > '9') {
					end = j;
					i = --j;
					break;
				}
			}
			string substr = str.substr(start, end);
			Enqueue(q, substr);
		}
		if (str[i] == '(') {
			char* temp = new char[2];
			temp[0] = str[i];
			temp[1] = '\0';
			Push(s, temp);
		}
		if (str[i] == ')') {
			string temp = Pop(s);
			while(temp != "(") {
				Enqueue(q, temp);
				temp = Pop(s);
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (isEmpty(s)) {
				char* temp = new char[2];
				temp[0] = str[i];
				temp[1] = '\0';
				Push(s, temp);
			}
			else {
				if (s.head->data == "*" || s.head->data == "/") {
					while (!isEmpty(s) && (s.head->data < "0" || s.head->data > "9")) {
						string temp = Pop(s);
						Enqueue(q, temp);
					}
				}
				char* temp = new char[2];
				temp[0] = str[i];
				temp[1] = '\0';
				Push(s, temp);
			}
		}
		++i;
	}
	while (!isEmpty(s)) {
		string temp = Pop(s);
		Enqueue(q, temp);
	}
	// Calculate
	string temp;
	double num1, num2;
	double result = 0;
	while (!isEmpty(q)) {
		temp = Dequeue(q);
		if (temp >= "0" && temp <= "9") {
			Push(s, temp);
		}
		else {
			num1 = atoi(Pop(s).c_str());
			num2 = atoi(Pop(s).c_str());
			if (temp == "+") {
				result = num2 + num1;
			}
			else if (temp == "-") {
				result = num2 - num1;
			}
			else if (temp == "*") {
				result = num2 * num1;
			}
			else if (temp == "/") {
				result = num2 / num1;
			}
			Push(s, to_string(result));
		}
	}
	return result;
}
#pragma once
#include "vector"
#include "iostream"
#include "string"

class Node
{
public:
	Node();
	~Node();
	Node(int p,int c);
	Node* CreatePolynomialList(std::vector<int> p, std::vector<int> c);
	Node* AddPolynomials(Node *root1, Node *root2);
	std::string Display(Node *root);
	void retriveValues(std::string str,std::vector<int> &powers, std::vector<int> &coffs);

public:
	int power;
	int coff;
	Node *next;


};


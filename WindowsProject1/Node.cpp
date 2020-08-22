#include "Node.h"

Node::Node()
{
	power = 0;
	coff = 0;
	next = nullptr;
}

Node::Node(int p,int c) {
	power = p;
	coff = c;
	next = nullptr;
}

Node * Node::CreatePolynomialList(std::vector<int> p, std::vector<int> c)
{
	Node *head = new Node();
	int pn = p.size();
	for (int i = 0; i < pn; ++i) {

		// for the first element
		if (i == 0) {
			Node *temp = new Node(p[i], c[i]);
			head = temp;
		}
		else {

			// if element is to add at head index
			if (head->power < p[i]) {
				Node *temp = new Node(p[i], c[i]);
				temp->next = head;
				head = temp;
				continue;
			}

			// if element has to add in another index 

			Node *temp = head;
			while (temp->next != NULL) {
				if (temp->next->power < p[i]) break;
				temp = temp->next;
			}
			Node *newNode = new Node(p[i], c[i]);
			if (temp->next == NULL) {
				temp->next = newNode;
			}
			else {
				newNode->next = temp->next;
				temp->next = newNode;
			}

		}
	} // end for
	return head;
}

Node * Node::AddPolynomials(Node * root1, Node * root2)
{
	Node *res = NULL;
	Node *curr = res;

	while (root1 != NULL || root2 != NULL) {
		// power of first polynomial is bigger
		if (root1->power > root2->power) {
			if (res == NULL) {
				res = root1;
				curr = res;
				root1 = root1->next;
			}
			else {
				curr->next = root1;
				curr = curr->next;
				root1 = root1->next;
			}
		}
		// power of second polynomial is bigger
		else if (root1->power < root2->power) {
			if (res == NULL) {
				res = root2;
				curr = res;
				root2 = root2->next;
			}
			else {
				curr->next = root2;
				curr = curr->next;
				root2 = root2->next;
			}
		}
		else {
			// powers of both polynomial is equal performing addition 
			if (res == NULL) {
				res = root1;
				res->coff += root2->coff;
				curr = res;
				root1 = root1->next;
				root2 = root2->next;
			}
			else {
				curr->next = root1;
				curr = curr->next;
				curr->coff += root2->coff;
				root1 = root1->next;
				root2 = root2->next;
			}
		}

	} // end while

	// checking and node left insidse first polynomial
	while (root1 != NULL) {
		curr->next = root1;
		curr = curr->next;
		root1 = root1->next;
	}

	// checking and node left inside second polynomial
	while (root2 != NULL) {
		curr->next = root2;
		curr = curr->next;
		root2 = root2->next;
	}
	//cout<<"END";
	return res;
}

std::string Node::Display(Node * root)
{
	std::string ans;
	Node *temp = root;
	while (temp->next != NULL) {
		std::cout << temp->coff << "." << "x^" << temp->power << " + ";
		ans = ans + std::to_string(temp->coff)+".x^"  + std::to_string(temp->power) + "  +  " ;
		temp = temp->next;
	}
	std::cout << temp->coff << "." << "x^" << temp->power << std::endl;
	ans = ans + std::to_string(temp->coff) + ".x^" + std::to_string(temp->power);
	return ans;
}

void Node::retriveValues(std::vector<int> powers, std::vector<int> coffs)
{
}


Node::~Node()
{
}

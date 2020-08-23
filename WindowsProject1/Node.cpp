#include "Node.h"
#include "regex"

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
			while (temp->next != nullptr) {
				if (temp->next->power < p[i]) break;
				temp = temp->next;
			}
			Node *newNode = new Node(p[i], c[i]);
			if (temp->next == nullptr) {
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
	Node *res = nullptr;
	Node *curr = res;

	while (root1 != nullptr || root2 != nullptr) {
		// power of first polynomial is bigger
		try {
			if (root1->power > root2->power) {
				if (res == nullptr) {
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
				if (res == nullptr) {
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
				if (res == nullptr) {
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

		}// end try
		catch(...) {
			std::cout << "Default Exception\n";
		}

	} // end while

	// checking and node left insidse first polynomial
	while (root1 != nullptr) {
		curr->next = root1;
		curr = curr->next;
		root1 = root1->next;
	}

	// checking and node left inside second polynomial
	while (root2 != nullptr) {
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

void Node::retriveValues(std::string str,std::vector<int> &powers, std::vector<int> &coffs)
{
	std::regex reg("([+-]?[0-9]*x{1}['^']{1}[0-9]*)");
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
	std::sregex_iterator lastMatch;
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		//std::string temp = ;
		coffs.push_back(int(match.str()[1])-48);
		powers.push_back(int(match.str()[4])-48);
		++currentMatch;
	}
	std::cout << "\n";
	for (int i = 0; i < coffs.size(); ++i) std::cout << coffs[i] << " ";
	std::cout << "\'n";
	for (int i = 0; i < powers.size(); ++i) std::cout << powers[i] << " ";
//	system("pause");
}


Node::~Node()
{
}

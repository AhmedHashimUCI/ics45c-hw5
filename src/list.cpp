#include "list.hpp"
#include <ostream>

namespace list {

	Node* from_string(const char* s){
	Node* head = nullptr;
	Node* tail = nullptr;

	while(*s != '\0'){

			Node* node = new Node(*s, nullptr);
			
			if(head == nullptr){

				head = node;
				tail = node;
			}else{

				tail-> next = node;
				tail = node;

			}

			++s;


		}

		return head;

	}


	void free(Node* head){
		for(Node* current = head; current !=nullptr;){
			
			Node* next = current->next;
			delete current;
			current = next;
		}

	}


	int length(Node* head){

		int count = 0;

		for(Node* p = head; p != nullptr; p = p->next){

			++count;

		}

		return count;

	}

	Node* copy(Node* head){
		Node* newhead = nullptr;
		Node* newtail = nullptr;

	

	for (Node* p = head; p != nullptr; p =p->next){
		
		Node* node = new Node(p->data, nullptr);

		if(newhead == nullptr){
			newhead = node;
			newtail = node;

		}else{
			newtail->next = node;
			newtail = node;

		}

	}

		return newhead;
	}


	void print(std::ostream& out, Node* head){

		for(Node* p =head; p != nullptr; p = p->next){
			out << p->data;

		}


	}


	int compare(Node* a, Node* b){

		for(int i = 0; a != nullptr && b != nullptr; a = a-> next, b= b->next){

			if(a-> data < b->data){
				return -1;


			}

			if(a-> data > b-> data){
				return 1;

			}
		}

			if (a == nullptr && b == nullptr) {
        	return 0;
    		}
		

			if (a == nullptr){
				return -1;

			}else {
				return 1;

			}



	}



	Node* nth(Node* head, int n){
		Node* p = head;

		for (int i = 0; i < n && p != nullptr; ++i){
			p = p->next;


		}

		return p;

	}


	Node* lasr(Node* head){
		Node* p = head;

		for(int i = 0; p-> next != nullptr; p =p->next){}
	
		return p;

	}



	int index(Node* head, Node* node){
		int position = 0;

		for(Node* p = head; p != node; p= p->next){
			++position;
		

		}

		return position;


	}

}

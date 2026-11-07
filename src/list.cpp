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

}


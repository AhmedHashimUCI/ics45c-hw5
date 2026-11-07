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


	Node* last(Node* head){
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


Node* find_char(Node* head, char c){
		
		for(Node* p = head; p != nullptr; p=p->next){

			if(p->data == c){
				return p;
			}

		}

		return nullptr;

	}


Node* find_list(Node* haystack, Node* needle){
	
	if(needle == nullptr)
	return haystack;

	for(Node* start = haystack; start !=nullptr; start = start -> next){
		 Node* a = start;
         Node* b = needle;

		for (; a != nullptr && b != nullptr;a = a->next, b = b->next) {

    	if (a->data != b->data) {
        	break;
    		}
		}

		if (b == nullptr) {
            return start;
        }

	}


	return nullptr;
	}



Node* append(Node* a, Node* b){

	Node* result = copy(a);
	Node* tail = result == nullptr ? nullptr : last(result);

	for(Node* p = b; p!=nullptr; p=p->next){
		Node* node = new Node{p->data, nullptr};

		if(result == nullptr){
			result = node;
		} else {

			tail->next = node;
		}

		tail = node;


	}

		return result;


	}


}

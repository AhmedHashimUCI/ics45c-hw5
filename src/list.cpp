#include "list.hpp"


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

}


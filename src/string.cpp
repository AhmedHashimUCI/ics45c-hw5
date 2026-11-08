#include "string.hpp"
#include "list.hpp"
#include <ostream>
#include <compare>
#include <istream>
#include <iostream>



String::String(const char* s):
	head(list::from_string(s)){}




String::String(const String& other)
    : head(list::copy(other.head)) {
}

String::String(list::Node* head)
    : head(head) {
}

int String::size() const{

	return list::length(head);

}

String::String(String&& s)
    : head(s.head) {
    s.head = nullptr;
}
void String::print(std::ostream& out) const {

	list::print(out, head);
}

std::ostream& operator<<(std::ostream& out, const String& s){

	s.print(out);
	return out;

}


char String::operator[](int index) const {

	if(!in_bounds(index)){
		std::cerr << "ERROR: Index out of bounds" << std::endl;
		return head == nullptr ? '\0' : head->data;;

	}

	return list::nth(head, index)->data;

}


bool String::operator==(const String& other) const {

	return list::compare(head, other.head) ==0;

}

std::strong_ordering String::operator<=>(const String& other) const {
    return list::compare(head, other.head) <=> 0;
}


String String::operator+(const String& other) const {
	return String(list::append(head, other.head));
}


String& String::operator+=(const String& other){
	list::Node* p = list::copy(other.head);
	
	if(head == nullptr){
		head = p;
	} else {
		list::last(head)->next = p;

	}

	return *this;

}

String& String::operator=(const String& other){

	if(this != &other){
		list::Node* newHead = list::copy(other.head);

		list::free(head);

		head = newHead;

	}

	return *this;

}

String& String::operator=(String&& other){
	if(this != &other){
		list::free(head);
		head = other.head;
		other.head = nullptr;

	}

	return *this;

}



void String::swap(String& s){

	list::Node* p = head;
	head = s.head;
	s.head = p;

}

bool String::in_bounds(int index) const {
    return index >= 0 && index < size();
}

String String::reverse() const{
	return String(list::reverse(head));

}


int String::indexOf(char c) const {

	list::Node* p = list::find_char(head, c);

	if(p  == nullptr)
	return -1;

	return list::index(head, p);

}

int String::indexOf(const String& s) const {
	
	list::Node* p = list::find_list(head, s.head);

	if (p == nullptr)
	return s.head == nullptr ? 0 : -1;

	return list::index(head, p);

}


void String::read(std::istream& in){
	std::string temp;

	if(in >> temp){
		list::Node* newhead = list::from_string(temp.c_str());
		
		list::free(head);
		head = newhead;
	}


}

std::istream& operator>>(std::istream& in, String& s){

	s.read(in);
	return in;

}

String::~String(){

	list::free(head);
}



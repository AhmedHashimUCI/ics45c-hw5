#include "string.hpp"
#include "list.hpp"
#include <ostream>
#include <compare>



String::String(const char* s):
	head(list::from_string(s)){}




String::String(const String& other)
    : head(other.head) {
}

int String::size() const{

	return list::length(head);

}


void String::print(std::ostream& out) const {

	list::print(out, head);
}

std::ostream& operator<<(std::ostream& out, const String& s){

	s.print(out);
	return out;

}


char String::operator[](int index) const {

	if(index < 0 || index >= size()){
		return '\0';

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

#include "string.hpp"
#include "list.hpp"
#include <ostream>



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

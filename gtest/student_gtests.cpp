#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);


    list::free(foo_list_head);
}

TEST(ListTests, FromStringEmpty) {
    list::Node* head = list::from_string("");

    EXPECT_EQ(head, nullptr);

    list::free(head);
}

TEST(ListTests, FreeList) {
    list::Node* head = list::from_string("Hello");

    list::free(head);

    SUCCEED();
}


TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

TEST(ListTests, LengthZero){
	Node* const head = list::from_string("");
	EXPECT_EQ(list::length(head), 0);
	list::free(head);

}

TEST(ListTests, CopyList) {
    list::Node* original = list::from_string("Lanadelrey");
    list::Node* copied = list::copy(original);

    ASSERT_NE(copied, nullptr);
    ASSERT_NE(original, copied);

    list::Node* a = original;
    list::Node* b = copied;

    for (; a != nullptr && b != nullptr;
         a = a->next, b = b->next) {

        EXPECT_EQ(a->data, b->data);
        EXPECT_NE(a, b);
    }

    EXPECT_EQ(a, nullptr);
    EXPECT_EQ(b, nullptr);

    list::free(original);
    list::free(copied);
}

TEST(ListTests, CopyEmpty){

	list::Node* newhead = list::copy(nullptr);

	EXPECT_EQ(newhead, nullptr);

}


// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, ReplaceMe) {
    EXPECT_TRUE(false);
}

TEST(ListTests, Print) {
     list::Node* head = list::from_string("Hello");

    std::ostringstream out;
    list::print(out, head);

    EXPECT_EQ(out.str(), "Hello");

    list::free(head);
}

TEST(ListTests, PrintEmpty) {
    std::ostringstream out;

    list::print(out, nullptr);

    EXPECT_EQ(out.str(), "");
}
TEST(ListTests, CompareEqual) {
    list::Node* a = list::from_string("Hello");
    list::Node* b = list::from_string("Hello");

    EXPECT_EQ(list::compare(a, b), 0);

    list::free(a);
    list::free(b);
}

TEST(ListTests, CompareOrder) {
    list::Node* a = list::from_string("Apple");
    list::Node* b = list::from_string("Banana");

    EXPECT_LT(list::compare(a, b), 0);
    EXPECT_GT(list::compare(b, a), 0);

    list::free(a);
    list::free(b);
}

TEST(ListTests, CompareEmpty) {
    list::Node* a = list::from_string("Hello");

    EXPECT_EQ(list::compare(nullptr, nullptr), 0);
    EXPECT_LT(list::compare(nullptr, a), 0);
    EXPECT_GT(list::compare(a, nullptr), 0);

    list::free(a);

}

TEST(ListTests, Nth) {
    list::Node* head = list::from_string("HELLO");

    EXPECT_EQ(list::nth(head, 0), head);
    EXPECT_EQ(list::nth(head, 1), head->next);
    EXPECT_EQ(list::nth(head, 2), head->next->next);
    EXPECT_EQ(list::nth(head, 4)->data, 'O');

    list::free(head);
}

#include <gtest/gtest.h>
#include <utility>
#include <algorithm>
#include <sstream>

#include "string.hpp"

using namespace std;

TEST(StringClass, Constructors) {
    String s("hello");
    EXPECT_EQ(s.size(), 5);

    String t(s);
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(s.size(), 5);
}

TEST(StringClass, Print) {
    String s("foo");
    stringstream out;
    s.print(out);
    EXPECT_STREQ(out.str().c_str(), "foo");

    stringstream out2;
    String().print(out2);
    EXPECT_STREQ(out2.str().c_str(), "");

    stringstream out3;
    out3 << s << s << String("bar");
    EXPECT_STREQ(out3.str().c_str(), "foofoobar");
}

TEST(StringClass, Comparisons) {
    EXPECT_LT(String("aaaa"), String("aaab"));
    EXPECT_LE(String("aaaa"), String("aaab"));
    EXPECT_EQ(String("foo"), String("foo"));
    EXPECT_NE(String("foo"), String("fooo"));
}

TEST(StringClass, Assignment) {
    String s("test"), t("foo");

    s = t;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = s;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = String();
    EXPECT_EQ(s, String());
    EXPECT_EQ(s.size(), 0);
}

TEST(StringClass, PrintNormal) {
    String s("Hello");

    std::ostringstream out;
    s.print(out);

    EXPECT_EQ(out.str(), "Hello");
}

TEST(StringClass, PrintEmpty) {
    String s("");

    std::ostringstream out;
    out << s;

    EXPECT_EQ(out.str(), "");
}


TEST(StringClass, Index){

	EXPECT_EQ(String("Lana")[2], 'n');
	EXPECT_EQ(String("vow")[4], 'v');
	EXPECT_EQ(String(" time")[0], ' ');
	EXPECT_EQ(String("Time")[-2], 'T');
}



TEST(StringClass, indexofchar){

	EXPECT_EQ(String("Burn").indexOf('n'), 3);
	EXPECT_EQ(String("Arctic").indexOf('c'), 2);
	EXPECT_EQ(String("Time").indexOf('c'), -1);
	EXPECT_EQ(String("Lana Del Rey").indexOf(' '), 4);


}

TEST(StringClass, indexofstr){

	EXPECT_EQ(String("Who won?").indexOf(String("won?")), 4);
	EXPECT_EQ(String("Lana Del Rey").indexOf(String("Rey")),9 );


}

TEST(StringClass, Ordering) {
    String a("Apple");
    String b("Banana");
    String c("Apple");

    EXPECT_TRUE(a < b);
    EXPECT_TRUE(b > a);

    EXPECT_TRUE(a <= c);
    EXPECT_TRUE(a >= c);

    EXPECT_FALSE(a > b);
    EXPECT_FALSE(b < a);
}


TEST(StringClass, Addition){

	EXPECT_EQ(String("Arctic") + String(" Monkeys"), String("Arctic Monkeys"));
	EXPECT_EQ(String(" ") + String("String"), String(" String"));
	EXPECT_EQ(String("String")+ String(""), String("String"));
	String s("Time");
	String e("");
	EXPECT_EQ(s += s,String("TimeTime"));
	EXPECT_EQ(s += e, s);
	EXPECT_EQ(e += s, s);
	EXPECT_EQ(e += e, e);
}


TEST(StringClass, MoveAssignment) {
    String a("CAT");
    String b("DOG");

    a = std::move(b);

    EXPECT_EQ(a, String("DOG"));
    EXPECT_EQ(b.size(), 0);
}


TEST(StringClass, SelfMoveAssignment) {
    String a("HELLO");

    a = std::move(a);

    EXPECT_EQ(a, String("HELLO"));
}

TEST(StringClass, SubscriptPrintsError) {
    String s("HELLO");

    testing::internal::CaptureStderr();

    char result = s[5];

    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_EQ(result, 'H');
    EXPECT_FALSE(output.empty());
}

TEST(StringClass, InvalidSubscriptCases) {
    String s("HELLO");
    String empty("");

    testing::internal::CaptureStderr();

    EXPECT_EQ(s[-2], 'H');
    EXPECT_EQ(s[100], 'H');
    EXPECT_EQ(empty[0], '\0');

    std::string output = testing::internal::GetCapturedStderr();

    EXPECT_FALSE(output.empty());
}

TEST(ListTests, FindListOverlapping) {
    list::Node* head = list::from_string("AAAAB");
    list::Node* needle = list::from_string("AAB");

    EXPECT_EQ(
        list::find_list(head, needle),
        list::nth(head, 2)
    );

    list::free(head);
    list::free(needle);
}

TEST(ListTests, CopyNoSharedNodes) {
    list::Node* original = list::from_string("HELLO");
    list::Node* copied = list::copy(original);

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

TEST(ListTests, CompareNBoundary) {
    list::Node* a = list::from_string("ABCDE");
    list::Node* b = list::from_string("ABCXY");

    EXPECT_EQ(list::compare(a, b, 0), 0);
    EXPECT_EQ(list::compare(a, b, 3), 0);
    EXPECT_LT(list::compare(a, b, 4), 0);
    EXPECT_LT(list::compare(a, b, 100), 0);

    list::free(a);
    list::free(b);
}

// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;

// empty tests

TEST(empty1) {
    List<int> holder; 
    holder.push_front(23);
    holder.push_back(43);
    holder.pop_front();
    holder.pop_back();
    ASSERT_TRUE(holder.empty());
}
TEST(empty1string) {
    List<string> holder; 
    holder.push_front("dogs");
    holder.push_back("cats");
    holder.pop_front();
    holder.pop_back();
    ASSERT_TRUE(holder.empty());
}
TEST(empty2) {
    List<int> holder; 
    ASSERT_TRUE(holder.empty());
}

//size tests
TEST(size1) {
    List<int> holder; 
    holder.push_front(45);
    holder.push_back(12);
    ASSERT_TRUE(holder.size()==2);
}
TEST(size2) {
    List<int> holder; 
    holder.push_front(45);
    holder.push_front(12);
    ASSERT_TRUE(holder.size()==2);
}
TEST(size1string) {
    List<string> holder; 
    holder.push_front("dogs");
    holder.push_back("cats");
    ASSERT_TRUE(holder.size()==2);
}
TEST(size2string) {
    List<string> holder; 
    holder.push_front("birds");
    holder.push_front("fish");
    ASSERT_TRUE(holder.size()==2);
}
TEST(size3) {
    List<int> holder; 
    holder.push_front(45);
    holder.pop_back();
    ASSERT_TRUE(holder.empty());
}
TEST(size4) {
    List<int> holder; 
    holder.push_front(23);
    holder.push_front(12);
    holder.push_back(49);
    holder.push_front(34);
    holder.pop_back();
    holder.pop_back();
    ASSERT_TRUE(holder.size()==2);
}

//test pushback
TEST(test_pushback1) {
    List<int> holder;
    holder.push_back(42);
    holder.push_back(43);
    holder.push_back(44);
    List<int>::Iterator first = holder.begin();
    List<int>::Iterator second = holder.begin();
    ASSERT_EQUAL(*second, 42);
    ++second;
    ++second;
    ASSERT_EQUAL(*first, 42);
    ASSERT_EQUAL(*second, 44);
    ++first;
    ASSERT_EQUAL(*first, 43);
}

TEST(test_pushback2){
    List<int> holder;
    holder.push_back(42);
    holder.push_back(43);
    holder.push_back(44);
    ASSERT_EQUAL(holder.front(), 42);
    ASSERT_EQUAL(holder.back(), 44);
}

TEST(test_pushback11) {
    List<string> holder;
    holder.push_back("hot");
    holder.push_back("cross");
    holder.push_back("buns");
    List<string>::Iterator first = holder.begin();
    List<string>::Iterator second = holder.begin();
    ASSERT_EQUAL(*second, "hot");
    ++second;
    ++second;
    ASSERT_EQUAL(*first, "hot");
    ASSERT_EQUAL(*second, "buns");
    ++first;
    ASSERT_EQUAL(*first, "cross");
}

TEST(test_pushback22){
    List<string> holder;
    holder.push_back("hot");
    holder.push_back("cross");
    holder.push_back("buns");
    ASSERT_EQUAL(holder.front(), "hot");
    ASSERT_EQUAL(holder.back(), "buns");
}

//test front
TEST(test_pushfront1) {
    List<int> holder;
    holder.push_front(42);
    holder.push_front(43);
    holder.push_front(44);
    List<int>::Iterator first = holder.begin();
    List<int>::Iterator second = holder.begin();

    ASSERT_EQUAL(*first, 44);
    ++second;
    ++second;
    ASSERT_EQUAL(*first, 44);
    ASSERT_EQUAL(*second, 42);
    ++++first;
    ASSERT_EQUAL(*first, 42);
}
TEST(test_pushfront2){
    List<int> holder;
    holder.push_front(42);
    holder.push_front(43);
    holder.push_front(44);
    ASSERT_EQUAL(holder.front(), 44);
    ASSERT_EQUAL(holder.back(), 42);
}
TEST(test_pushfront1string) {
    List<string> holder;
    holder.push_front("hot");
    holder.push_front("cross");
    holder.push_front("buns");
    List<string>::Iterator first = holder.begin();
    List<string>::Iterator second = holder.begin();

    ASSERT_EQUAL(*first, "buns");
    ++second;
    ++second;
    ASSERT_EQUAL(*first, "buns");
    ASSERT_EQUAL(*second, "hot");
    ++++first;
    ASSERT_EQUAL(*first, "hot");
}
TEST(test_pushfront2string){
    List<string> holder;
    holder.push_front("hot");
    holder.push_front("cross");
    holder.push_front("buns");
    ASSERT_EQUAL(holder.front(), "buns");
    ASSERT_EQUAL(holder.back(), "hot");
}

//operator tests 
TEST(back_operator) {
    List<int> holder; 
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    List<int>::Iterator second = holder.begin();
    List<int>::Iterator first = second;
    ++second;
    ++second;
    ++first;
    ++first;
    ASSERT_EQUAL(second, first);
    ASSERT_TRUE(holder.size()==4);
    --second;
    --second;
    --first;
    --first;
    ASSERT_EQUAL(second, first);
}
TEST(back_operatorstring) {
    List<string> holder; 
    holder.push_back("them");
    holder.push_back("hot");
    holder.push_back("cross");
    holder.push_back("buns");
    List<string>::Iterator second = holder.begin();
    List<string>::Iterator first = second;
    ++second;
    ++second;
    ++first;
    ++first;
    ASSERT_EQUAL(second, first);
    ASSERT_TRUE(holder.size()==4);
    --second;
    --second;
    --first;
    --first;
    ASSERT_EQUAL(second, first);
}
//clear tests
TEST(test_clear) {
    List<int> holder;
    holder.push_back(22);
    holder.push_back(32);
    holder.push_back(34);
    holder.push_back(53);
    holder.clear();
    ASSERT_TRUE(holder.empty());
}
TEST(test_clearstring) {
    List<string> holder;
    holder.push_back("Them");
    holder.push_back("hot");
    holder.push_back("cross");
    holder.push_back("buns");
    holder.clear();
    ASSERT_TRUE(holder.empty());
}

TEST(test_clear2) {
    List<int> holder;
    holder.clear();
    ASSERT_TRUE(holder.empty());
}

TEST(test_clear3) {
    List<int> holder;
    holder.push_front(22);
    holder.push_front(32);
    holder.push_front(40);
    holder.clear();
    ASSERT_TRUE(holder.empty());
}

TEST(test_clear4) {
    List<int> holder;
    holder.push_front(22);
    holder.push_front(32);
    holder.push_back(40);
    holder.clear();
    ASSERT_TRUE(holder.empty());
}

//pop back tests
TEST(pop_back_test){
    List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    holder.push_back(5);
    List<int>::Iterator second = holder.begin();
    holder.pop_back();

    ASSERT_EQUAL(*second, 1);
    ++second;
    ASSERT_EQUAL(*second, 2);
    holder.pop_front();
    ++second;
    ASSERT_EQUAL(*second, 3);
    ++second;
    ASSERT_EQUAL(*second, 4);
}

TEST(pop_back_test_string){
    List<string> holder;
    holder.push_back("why");
    holder.push_back("dont");
    holder.push_back("we");
    holder.push_back("be");
    holder.push_back("friends");
    List<string>::Iterator second = holder.begin();
    holder.pop_back();

    ASSERT_EQUAL(*second, "why");
    ++second;
    ASSERT_EQUAL(*second, "dont");
    holder.pop_front();
    ++second;
    ASSERT_EQUAL(*second, "we");
    ++second;
    ASSERT_EQUAL(*second, "be");
}
//pop front tests
TEST(pop_front_test1){
    List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    holder.push_back(5);
    holder.pop_front();
    List<int>::Iterator second = holder.begin();

    ASSERT_EQUAL(*second, 2);
    ++second;
    ASSERT_EQUAL(*second, 3);
    holder.pop_front();
    ++second;
    ASSERT_EQUAL(*second, 4);
    ++second;
    ASSERT_EQUAL(*second, 5);
}

TEST(pop_front_test_string2){
    List<string> holder;
    holder.push_back("why");
    holder.push_back("dont");
    holder.push_back("we");
    holder.push_back("be");
    holder.push_back("friends");
    holder.pop_front();
    List<string>::Iterator second = holder.begin();

    ASSERT_EQUAL(*second, "dont");
    ++second;
    ASSERT_EQUAL(*second, "we");
    holder.pop_front();
    ++second;
    ASSERT_EQUAL(*second, "be");
    ++second;
    ASSERT_EQUAL(*second, "friends");
}
//pop both
TEST(pop_empty_string){
    List<string> holder;
    holder.push_back("why");
    holder.push_back("dont");
    holder.push_back("we");
    holder.push_back("be");
    
    holder.pop_front();
    holder.pop_back();
    holder.pop_front();
    holder.pop_back();
    
    ASSERT_TRUE(holder.empty());
}

TEST(pop_empty_int){
    List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    
    holder.pop_front();
    holder.pop_back();
    holder.pop_front();
    holder.pop_back();
    
    ASSERT_TRUE(holder.empty());
}

//copy tests
TEST(coppy1){
    List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    holder.push_back(5);
    List<int> second_list(holder);
    List<int>::Iterator first = holder.begin();
    List<int>::Iterator second = second_list.begin();
    ASSERT_TRUE(*first == *second);
    ++first;
    ASSERT_TRUE(*first != *second);
    --first;
    ++first;
    ++second;
    ASSERT_TRUE(*first == *second);
    --first;
    --second;
    ASSERT_TRUE(*first == *second);
}

TEST(coppy2){
    List<string> holder;
    holder.push_back("why");
    holder.push_back("cant");
    holder.push_back("we");
    holder.push_back("be");
    holder.push_back("friends");
    List<string> second_list(holder);
    List<string>::Iterator first = holder.begin();
    List<string>::Iterator second = second_list.begin();
    ASSERT_TRUE(*first == *second);
    ++first;
    ++second;
    ASSERT_TRUE(*first == *second);
    --first;
    --second;
    ASSERT_TRUE(*first == *second);
}

//Begin and end, front and back test
TEST(begin_test){
     List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    ASSERT_TRUE(1==holder.front());
    ASSERT_TRUE(4==holder.back());
    List<int>::Iterator first = holder.begin();
    ASSERT_EQUAL(1,*first);
}
TEST(test_end){
     List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    holder.push_back(4);
    holder.pop_back(); 

    List<int>::Iterator second = holder.end();
    List<int>::Iterator first;
    ASSERT_EQUAL(first, second);
}


//Erase tests
TEST(erase_test){
     List<int> holder;
    holder.push_back(1);
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    holder.push_back(4);

    List<int>::Iterator second = holder.begin();
    holder.erase(second);
    second = holder.begin();
    ASSERT_TRUE(*second == 2);
    ++second;
    holder.erase(second);
    second = holder.begin();
    ++second;
    ASSERT_TRUE(*second == 4);
}

TEST(erase_test2){
    List<int> holder;
    holder.push_back(1);
    List<int>::Iterator second = holder.begin();
    holder.erase(second);
    ASSERT_TRUE(holder.empty()); 
}

//Insert tests
TEST(insert_test){
    List<int> holder;
    holder.push_back(2);
    holder.push_back(3);
    holder.push_back(4);
    holder.push_back(5);
    holder.push_back(6);
    ASSERT_EQUAL(holder.size(), 5);

    List<int>::Iterator second = holder.begin();
    List<int>::Iterator first = holder.end();
    List<int>::Iterator third;

    holder.insert(second,1);
    ASSERT_EQUAL(holder.size(), 6);
    second = holder.begin();
    ASSERT_EQUAL(*second,1);
    ++second;
    ASSERT_EQUAL(*second,2);
    ASSERT_EQUAL(first,third);
}

TEST(insert_teststring){
    List<string> holder;
    holder.push_back("Them");
    holder.push_back("hot");
    holder.push_back("cross");
    holder.push_back("buns");
    holder.push_back("man");
    ASSERT_EQUAL(holder.size(), 5);

    List<string>::Iterator second = holder.begin();
    List<string>::Iterator first = holder.end();
    List<string>::Iterator third;

    holder.insert(second,"Them");
    ASSERT_EQUAL(holder.size(), 6);
    second = holder.begin();
    ASSERT_EQUAL(*second,"Them");
    ++++second;
    ASSERT_EQUAL(*second,"hot");
    ASSERT_EQUAL(first,third);
}

TEST(insert_test2){
    List<int> holder;
    holder.push_back(2);
    ASSERT_EQUAL(holder.size(), 1);

    List<int>::Iterator second = holder.begin();
    List<int>::Iterator first = holder.end();
    List<int>::Iterator third;

    holder.insert(second,1);
    ASSERT_EQUAL(holder.size(), 2);
    second = holder.begin();
    ASSERT_EQUAL(*second,1);
    ++second;
    ASSERT_EQUAL(*second,2);
    ASSERT_EQUAL(first,third);
}

TEST(insert_test3){
    List<int> holder;
    ASSERT_EQUAL(holder.size(), 0);

    List<int>::Iterator second = holder.begin();
    List<int>::Iterator first = holder.end();
    List<int>::Iterator third;

    holder.insert(second,1);
    ASSERT_EQUAL(holder.size(), 1);
    second = holder.begin();
    ASSERT_EQUAL(*second,1);
    ASSERT_EQUAL(first,third);
}
TEST_MAIN()

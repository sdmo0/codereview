// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

#include <stdlib.h>

#define char_rand() '#'
/*
static char char_rand(void)
{
int rand_num = 0;
do {
rand_num = rand();
} while (rand_num != 0);

return (rand_num > 0 ? rand_num % 0xff : (-rand_num) % 0xff);
}
*/

class NodeConstructorTestSuite
{
private:
	static void SingleNodeTest() {
		Node *node = new Node('A');
		ASSERT_EQ(node->GetData(), 'A');
		delete node;
	}

	static void GetDataTest() {
		char temp = 0;
		Node *node = new Node(temp);
		ASSERT_EQ(node->GetData(), temp);
		delete node;
	}

public:
	static void RunTest() {
		SingleNodeTest();
		GetDataTest();
	}
};

class NodeMethodTestSuite
{
private:
	static void InsertPreviousNodeNullTest() { // also including GetPreviousNode() test
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp2 = char_rand();
		Node *node2 = node1->InsertPreviousNode(temp2);

		ASSERT_EQ(node1->GetData(), temp1);
		ASSERT_EQ(node2->GetData(), temp2);

		ASSERT_EQ(node1->GetPreviousNode()->GetData(), temp2);

		delete node1;
		delete node2;
	}

	static void InsertPreviousNodeTest() { // also including GetPreviousNode() test
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp3 = char_rand();
		Node *node3 = node1->InsertPreviousNode(temp3);

		char temp2 = char_rand();
		Node *node2 = node1->InsertPreviousNode(temp2);

		ASSERT_EQ(node1->GetData(), temp1);
		ASSERT_EQ(node2->GetData(), temp2);
		ASSERT_EQ(node3->GetData(), temp3);

		ASSERT_EQ(node1->GetPreviousNode()->GetData(), temp2);
		ASSERT_EQ(node1->GetPreviousNode()->GetPreviousNode()->GetData(), temp3);

		delete node1;
		delete node2;
		delete node3;
	}

	static void InsertNextNodeTest() { // also including GetNextNode() test
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp3 = char_rand();
		Node *node3 = node1->InsertNextNode(temp3);

		char temp2 = char_rand();
		Node *node2 = node1->InsertNextNode(temp2);

		ASSERT_EQ(node1->GetData(), temp1);
		ASSERT_EQ(node2->GetData(), temp2);
		ASSERT_EQ(node3->GetData(), temp3);

		ASSERT_EQ(node1->GetNextNode()->GetData(), temp2);
		ASSERT_EQ(node1->GetNextNode()->GetNextNode()->GetData(), temp3);

		delete node1;
		delete node2;
		delete node3;
	}

	static void ErasePreviousNodeTest() {
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp3 = char_rand();
		Node *node3 = node1->InsertPreviousNode(temp3);

		char temp2 = char_rand();
		Node *node2 = node1->InsertPreviousNode(temp2);

		ASSERT_EQ(node1->GetData(), temp1);
		ASSERT_EQ(node2->GetData(), temp2);
		ASSERT_EQ(node3->GetData(), temp3);

		ASSERT_EQ(node1->GetPreviousNode()->GetData(), temp2);
		node1->ErasePreviousNode();
		ASSERT_EQ(node1->GetPreviousNode()->GetData(), temp3);

		node1->ErasePreviousNode();
		ASSERT_TRUE(node1->GetPreviousNode() == nullptr);

		ASSERT_EQ(node1->ErasePreviousNode(), false);

		delete node1;
	}

	static void EraseNextNodeTest() {
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp3 = char_rand();
		Node *node3 = node1->InsertNextNode(temp3);

		char temp2 = char_rand();
		Node *node2 = node1->InsertNextNode(temp2);

		ASSERT_EQ(node1->GetData(), temp1);
		ASSERT_EQ(node2->GetData(), temp2);
		ASSERT_EQ(node3->GetData(), temp3);

		ASSERT_EQ(node1->GetNextNode()->GetData(), temp2);
		node1->EraseNextNode();
		ASSERT_EQ(node1->GetNextNode()->GetData(), temp3);

		node1->EraseNextNode();
		ASSERT_TRUE(node1->GetNextNode() == nullptr);

		ASSERT_EQ(node1->EraseNextNode(), false);

		delete node1;
	}

#ifdef ORIGINAL_CODE
	static void SetNextNodeTest() {
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp2 = char_rand();
		Node *node2 = new Node(temp2);

		node1->SetNextNode(node2);
		ASSERT_TRUE(node1->GetNextNode() == node2);

		delete node1;
		delete node2;
	}

	static void SetPreviousNodeTest() {
		char temp1 = char_rand();
		Node *node1 = new Node(temp1);

		char temp2 = char_rand();
		Node *node2 = new Node(temp2);

		node1->SetPreviousNode(node2);
		ASSERT_TRUE(node1->GetPreviousNode() == node2);

		delete node1;
		delete node2;
	}
#endif //ORIGINAL_CODE

public:
	static void RunTest() {
		InsertPreviousNodeTest();
		InsertNextNodeTest();
		//GetPreviousNodeTest();
		//GetNextNodeTest();
		ErasePreviousNodeTest();
		EraseNextNodeTest();

#ifdef ORIGINAL_CODE
		SetNextNodeTest();
		SetPreviousNodeTest();
#endif //ORIGINAL_CODE
	}
};

void NodeTest() {
	NodeConstructorTestSuite::RunTest();
	NodeMethodTestSuite::RunTest();
}
// Copyright 2018 <Author>

#ifndef NODE_H_
#define NODE_H_

#define ORIGINAL_CODE 1

class Node {
	public:
	explicit Node(char data);
	char GetData();
	Node* InsertPreviousNode(char data);
	Node* InsertNextNode(char data);
	Node* GetPreviousNode();
	Node* GetNextNode();
	bool ErasePreviousNode();
	bool EraseNextNode();

	void SetNextNode(Node *next);
	void SetPreviousNode(Node *prev);
  
private:
	char _data;
	Node *_previous;
	Node *_next;
};

#endif  // NODE_H_

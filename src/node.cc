// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) :
	_data(data), _previous(nullptr), _next(nullptr)
{
	return;
}

char Node::GetData() {
	return _data;
}

Node* Node::GetPreviousNode() {
	return _previous;
}

Node* Node::GetNextNode() {
	return _next;
}

Node* Node::InsertPreviousNode(char data) {
	Node *node_ = new Node(data);
	if (_previous) {
		_previous->_next = node_;
	}

	node_->_next = this;
	node_->_previous = _previous;
	_previous = node_;

	return node_;
}

Node* Node::InsertNextNode(char data) {
	Node *node_ = new Node(data);
	if (_next) {
		_next->_previous = node_;
	}

	node_->_next = _next;
	node_->_previous = this;
	_next = node_;

	return node_;
}

bool Node::ErasePreviousNode() {
	if (nullptr == _previous) return false;

	Node *node_ = _previous;

	_previous = node_->GetPreviousNode();
	if (_previous) {
		_previous->_next = this;
	}

	delete node_;
	return true;
}

bool Node::EraseNextNode() {
	if (nullptr == _next) return false;

	Node *node_ = _next;
  
	_next = node_->GetNextNode();
	if (_next) {
		_next->_previous = this;
	}

	delete node_;
	return true;
}

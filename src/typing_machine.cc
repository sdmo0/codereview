// Copyright 2018 <Author>

#include "typing_machine.h"

const int MAX_STRING = 100;

TypingMachine::TypingMachine() {
	Node *_head = nullptr;
	Node *_tail = nullptr;
	Node *_cur = nullptr;
	int _string_count = 0;
	return;
}

void TypingMachine::HomeKey() {
	_cur = _head;
	return;
}

void TypingMachine::EndKey() {
	_cur = _tail;
	return;
}

void TypingMachine::LeftKey() {
	if (nullptr == _cur || nullptr == _cur->GetPreviousNode()) return;

	_cur = _cur->GetPreviousNode();

	return;
}

void TypingMachine::RightKey() {
	if (nullptr == _cur || nullptr == _cur->GetNextNode()) return;

	_cur = _cur->GetNextNode();

	return;
}

bool TypingMachine::TypeKey(char key) {
	if (key < 0x20 || key > 0x7E) return false;
	if (_string_count == MAX_STRING) return false;

	if (nullptr == _cur) {
		_cur = _head = _tail = new Node(key);
	}
	else {
		_cur->InsertPreviousNode(key);
		if (_cur == _head) _head = _cur->GetPreviousNode();
	}

	_string_count++;
	return true;
}

bool TypingMachine::EraseKey() {
	if (nullptr == _cur->GetPreviousNode()) return false;

	if (_cur->GetPreviousNode() == _head) _head = _cur;
	_cur->ErasePreviousNode();

	_string_count--;
	return true;
}

std::string TypingMachine::Print(char separator) {
	std::string str_(" ");

	Node *idx_ = nullptr;

	for (idx_ = _head; idx_ != nullptr; idx_ = idx_->GetNextNode()) {
		if (idx_ == _cur && 0 != separator) str_.push_back(separator);
		str_.push_back(idx_->GetData());
	}

	return str_;
}

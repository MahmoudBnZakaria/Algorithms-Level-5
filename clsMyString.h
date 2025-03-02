#pragma once
#include "clsMyStack.h"
#include <stack>
using namespace std;

class clsMyString {
protected: 
	string _Value;
	stack<string> _UndoStack;
	stack<string> _RedoStack;

public:

	string Get() {
		return _Value;
	}
	void Set(string Value) {
		_UndoStack.push(Value);
		_Value = Value;
	}
	__declspec(property(get = Get, put = Set)) string Value;

	void Undo() {
		if (_UndoStack.empty()) {
			return;
		}
		string TheOldValue = _UndoStack.top();
		_UndoStack.pop();
		_RedoStack.push(TheOldValue);
		_Value = TheOldValue;
	}

	void Redo() {
		if (_RedoStack.empty()) {
			return;
		}
		string TheOldValue = _RedoStack.op();
		_RedoStack.pop();
		_UndoStack.push(TheOldValue);
		_Value = TheOldValue;

	}
};

#pragma once

template <typename T>

class Stack
{
private:
	T* data;
	size_t top;

public:
	size_t maxSize;

	Stack(size_t _maxSize) {
		maxSize = _maxSize;
		data = new T[maxSize];
		top = 0;
	}

	~Stack()
	{
		delete[] data;
	}

	void Push(T item) {
		top++;
		if (top > maxSize) {
			std::cout << "stack overflow" << std::endl;
		}
		else
		{
			data[top - 1] = item;
		}
	}

	T pop() {
		if (top > 0) {
			top--;
			return data[top];
		}
		else {
			std::cout << "Stack Vacio" << std::endl;
			return T();
		}
	}

	T* peek() {
		if (top > 0) {
			return &data[top - 1];
		}
		else {
			return nullptr;
		}
	}
	bool isEmpty() {
		return top == 0;
	}

	size_t size() {
		return top;
	}
};


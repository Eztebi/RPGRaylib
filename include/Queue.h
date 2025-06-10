#pragma once

template <typename T>
class Queue
{
	T* data;
	size_t front;
	size_t rear;
	size_t maxSize;

public:
	Queue(size_t _size) {
		maxSize = _size;
		front = 0;
		rear = 0;
		data = new T[maxSize];
	}

	~Queue() {
		delete[] data;
	}

	bool isEmpty() {
		return front == rear;
	}

	size_t size() {
		return rear - front;
	}
	void Enqueue(T item) {
		if (size() == maxSize) {
			std::cout << "la cola esta llena" << std::endl;
			return;
		}
		data[rear++] = item;
	}

	T Dequeue() {
		if (isEmpty()) {
			std::cout << "la cola esta vacia" << std::endl;
			return T();
		}

		T temp = data[front];
		for (size_t i = front; i < rear; i++)
		{
			data[i] = data[i + 1];
		}
		rear--;
		return data[temp]
	}
	T* peek() {
		if (isEmpty()){
			std::cour << "la cola esta vacia" << std::endl;
			return nullptr;
		}
		return &data[front];
	}
};


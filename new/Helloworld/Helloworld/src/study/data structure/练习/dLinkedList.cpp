#include <iostream>

template <class T>
class dLinkedList
{
	void insert(dLinkedList<T>* head)
	{
		head->rear = rear;
		rear->prior = head;
		head->prior = this;
		rear = head;
	}
private:
	T data;
	dLinkedList* prior, rear;
};
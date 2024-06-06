#include"stack.hpp"
#include<iostream>

stack::~stack()
{
	if(!isEmpty())
	{
		node *temp = head;
		int x;

		while (head)
		{
			temp = head;
			x = head->m_data;
			head = head->m_next;

			std::cout << "deleted: " << x <<'\n';
			delete temp;
		}
	}
}

int stack::push(int element)
{
	node *newNode = new node{};

	if(newNode == nullptr)
	{
		return -1;
	}

	newNode->m_data = element;
	newNode->m_next = nullptr;

	if(head == nullptr)
	{
		head = newNode;
	}
	else
	{
		node *temp = head;

		/* insert begin */		
		newNode->m_next = temp;
		head = newNode;
	}

	return 0;
}

int stack::pop()
{
	int x = -1;

	if(!isEmpty())
	{
		node *temp = head;

		x = head->m_data;
		/* point head to next node */
		head = head->m_next;

		delete temp;
	}

	return x;
}

int stack::peek()
{
	if(!isEmpty())	
	{
		return head->m_data;
	}

	return -1;
}

bool stack::isEmpty()
{
	if(head == nullptr)
		return true;

	return false;
}

int stack::lookup(int position)
{
	if(isEmpty())
	{
		return -1;
	}

	node *temp = head;

	for(int i = 0; i < (position) && temp != nullptr; i++)
	{
		temp = temp->m_next;
	}

	if(temp != nullptr)
	{
		return temp->m_data;
	}
	
	return -1;
}


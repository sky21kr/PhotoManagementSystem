#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
#include"Iterator.h"
using namespace std;

enum RelationType {LESS, GREATER, EQUAL};

//���ø� Ŭ�����̹Ƿ�
template<typename T>	
class Iterator;

template<typename T>
struct NodeType	//��ũ�帮��Ʈ�� ���� ����ü
{
	T info;	///< ������ ����
	NodeType<T>* back;
	NodeType<T>* next;	///< �������� ���ϴ� �ּ�
};

/**
*	��ũ�帮��Ʈ�� ���������ϴ� sorted list.
*/
template<typename T>
class SortedList
{
	friend class Iterator<T>;
public:
	/**
	*	�⺻ ������
	*/
	SortedList();

	/**
	*	�Ҹ���
	*/
	~SortedList()
	{
		
	}

	/**
	*	@brief	����Ʈ�� ���
	*	@pre	����
	*	@post	����Ʈ�� �����
	*/
	void MakeEmpty();

	/**
	*	@brief	���� ����Ʈ�� ���̸� ����
	*	@pre	����
	*	@post	����
	*	@return	���� ����Ʈ�� ���̸� ������
	*/
	int GetLength();

	/**
	*	@brief	Name�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��ϰ� Name�� ������ �߰����� ����
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	����Ʈ�� �� �����Ͱ� ������
	*	@param	data	�� ������
	*	@return	�� �������� 1, ������ Name�� �����ϸ� 0�� ������
	*/
	int Add(T data);

	/**
	*	@brief	����ڰ� ������ ItemType�� �迭���� �����Ѵ�.
	*	@pre	data�� Name ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data	Name�� ä�����ִ� ItemType.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete(T data);


	/**
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�. ����� ã���� Binary Search�� �̿��Ѵ�.
	*	@pre	data�� Name ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data	Name�� ä�����ִ� ItemType.
	*	@return	ã�� �������� ��ġ�� �����ϰ� ã�� ���ϸ� -1�� ������
	*/
	int GetByBinarySearch(T& data);

	/**
	*	@brief	��ũ�帮��Ʈ �� i��° ��ġ �ּҸ� �޾ƿ�
	*	@pre	��ũ�帮��Ʈ�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*	@param	i	��ũ�帮��Ʈ �� �޾ƿ� �ּ��� ��ġ
	*	@return	�޾ƿ� ��ũ�帮��Ʈ�� �ּ�
	*/
	T* GetLinkedList(int i);
private:
	NodeType<T>* head;	///< ��ũ�帮��Ʈ ���
	NodeType<T>* tail;	///< ��ũ�帮��Ʈ ����
	int m_Length;		///< ����Ʈ ����� ����
};

// �⺻ ������
template<typename T>
SortedList<T>::SortedList()
{
	head = NULL;
	tail = NULL;
	m_Length = 0;
}

// ��ũ�帮��Ʈ�� i��° ��ġ �ּҸ� �޾ƿ�
template<typename T>
T* SortedList<T>::GetLinkedList(int i)
{
	NodeType<T>* temp = head;
	for(int j = 0 ; j < i ; j++ )
	{
		temp = temp->next;
	}
	return &temp->info;
}


// ����Ʈ�� ���
template<typename T>
void SortedList<T>::MakeEmpty()
{
	Iterator<T> itor(*this);
	itor.MakeEmpty();
	m_Length = 0;
}

// ���� ����Ʈ�� ������ ���̸� �޾ƿ�
template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}

// ����Ʈ�� �� �����͸� ����
template<typename T>
int SortedList<T>::Add(T inData)
{
	if( m_Length == 0 ) //�����Ͱ� ó���� �ϳ��� ������
	{
		head = new NodeType<T>;
		tail = new NodeType<T>;
		
		head->back = NULL;
		head->next = tail;

		tail->back = head;
		tail->next = NULL;

		NodeType<T>* NewNode = new NodeType<T>; // ���ο� ������ ������ ��
		NewNode->info = inData;
		NewNode->back = head;
		NewNode->next = tail;
		head->next = NewNode;	// ù��° ������
		tail->back = NewNode;
		m_Length++;
		return 1;
	}
	else	// �����Ͱ� �ϳ� �̻� ���� ��
	{
		Iterator<T> itor(*this);

		while(1)
		{
			itor.Next();
			if( inData.GetName() < itor.m_pCurPointer->info.GetName() ) // ���γִ� �����Ͱ� �� �̸��� �������
			{
				NodeType<T>* NewNode = new NodeType<T>;
				NewNode->info = inData;
				NewNode->back = itor.m_pCurPointer->back;
				NewNode->next = itor.m_pCurPointer;
				itor.m_pCurPointer->back->next = NewNode;
				itor.m_pCurPointer->back = NewNode;
				m_Length++;
				return 1;
			}
			else if(inData.GetName() == itor.m_pCurPointer->info.GetName())	// �̸��� ���� ���
			{
				return 0;
			}
			else if( itor.m_pCurPointer == tail )	// ������ �� ���
			{
				NodeType<T>* NewNode = new NodeType<T>;
				NewNode->info = inData;
				NewNode->back = itor.m_pCurPointer->back;
				NewNode->next = tail;
				itor.m_pCurPointer->back->next = NewNode;
				itor.m_pCurPointer->back = NewNode;
				m_Length++;
				return 1;
			}
		}
	}
	return -1;
}

//Name���� �����ϴ� data�� �̿��Ͽ� �� Name���� ���� Name�� ������ �ִ� �׸��� �����ְ� length�� 1 ���ش�.
template<typename T>
int SortedList<T>::Delete(T data)
{
	Iterator<T> itor(*this);
	for(int i = 0 ; i < m_Length ; i++ )
	{
		itor.Next();
		if( itor.m_pCurPointer->info.GetName() == data.GetName() )	// ��ġ�ϴ� �̸� �߽߰�
		{
			itor.m_pCurPointer->back->next = itor.m_pCurPointer->next;
			itor.m_pCurPointer->next->back = itor.m_pCurPointer->back;

			delete itor.m_pCurPointer;

			m_Length--;
			return 1;
		}
		else if(itor.m_pCurPointer == tail)	// ������ ���µ��� ��ã�� ���
		{
			return 0;
		}
	}
	return -1;
}


//Name���� �����ϴ� data�� �˸´� �׸��� Binary Search�� �̿��� ã�� �������ְ� ��ġ�� �����Ѵ�
template<typename T>
int SortedList<T>::GetByBinarySearch(T& data) 
{
	int first=1;	// �迭�� �ƴϹǷ� 1���� ����
	int last=m_Length;	// �迭�� �ƴϹǷ� ũ�� �״�� ����
	bool found=0;

	Iterator<T> itor(*this);
	while(first<=last&&!found)	//first�� last���� Ŀ���� ���̻� �������� �ʴ´�. found�� 1�� �Ǹ� �������� �ʴ´�.
	{
		itor.Reset();
		int mid=(first+last)/2;	//mid�� first�� last�� ��հ�

		for(int i = 0 ; i <  mid ; i++ )
		{
			itor.Next();
		}
		switch(data.CompareByName(itor.m_pCurPointer->info))	//data�� ��ũ�帮��Ʈ�� Name�� ��
		{
		case LESS:
			last=mid-1;
			break;	//data�� Name���� �� ������, last�� mid-1�� �Ű��ش�.
		case GREATER:
			first=mid+1;
			break;	//data�� Name���� �� Ŭ��, first�� mid+1�� �Ű��ش�.
		case EQUAL:
			data=itor.m_pCurPointer->info;
			found=1;
			return mid;	//data�� ��ũ�帮��Ʈ�� mid��ġ�� Name���� ������ data�� ��ü�� �������ְ� ��ġ�� mid�� �����Ѵ�. �ݺ����� ���������� ���� found=1�� ���ش�.
			break;
		}
	}
	return -1;	//ã�� �������Ƿ� -1�� �������ش�.
}

#endif	// _SORTEDLIST_H
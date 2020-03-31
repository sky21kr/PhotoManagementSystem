#pragma once
#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "SortedList.h"

// ���ø� �̹Ƿ�
template<typename T>
struct NodeType;
template<typename T>
class SortedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T> 
class Iterator
{
	friend class SortedList<T>;	// ����Ʈ�� ģ�� Ŭ����
public:
	/**
	*	����Ʈ ������.
	*/
	Iterator(const SortedList<T> &list) : m_List(list), m_pCurPointer(list.head)
	{

	}; ///< SortedLinkedList�� ģ�� Ŭ����.

	/**
	*	@brief	���� Iterator�� NULL���� �Ǻ�
	*	@pre	Iterator�� �ʱ�ȭ�Ǿ����
	*	@post	����
	*	@return	���� Iterator�� NULL�̸� false, �ƴϸ� TRUE
	*/
	bool NotNull();

	/**
	*	@brief	���� Iterator�� NULL���� �Ǻ�
	*	@pre	���� Iterator�� �־����
	*	@post	����
	*	@return	���� Iterator�� NULL�̸� false, �ƴϸ� TRUE
	*/
	bool NextNotNull();

	/**
	*	@brief	����Ʈ ù��° �����͸� �޾ƿ�
	*	@pre	����Ʈ�� ù��° �����Ͱ� �־����
	*	@post	����
	*	@return	����Ʈ ù��° ������
	*/
	T First();

	/**
	*	@brief	Iterator�� �������� �̵���Ű�� ���� �����͸� �޾ƿ�
	*	@pre	�������� �̵��� ����Ʈ�� �־����
	*	@post	Iterator�� �������� �̵���
	*	@return	���� ����Ʈ ������
	*/
	T Next();

	/**
	*	@brief	���� ��带 ������
	*	@pre	Iterator�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	����
	*	@return	���� ���
	*/
	NodeType<T> GetCurrentNode();

	/**
	*	@brief	head�� �̵���
	*	@pre	Iterator�� �ʱ�ȭ �Ǿ��� �־����
	*	@post	Iterator�� head�� �̵���/
	*/
	void Reset();

	/**
	*	@brief	����Ʈ�� ��� ���
	*	@pre	����Ʈ�� ������� �־����
	*	@post	����Ʈ�� ��� ������� �����Ҵ��� ������
	*/
	void MakeEmpty();

private:
	const SortedList<T> &m_List;	///< ����Ʈ �޾ƿ�
	NodeType<T>* m_pCurPointer;		///< ���� ����� ������ �ּ�
};

// ����Ʈ�� ���
template<typename T>
void Iterator<T>::MakeEmpty()
{
	if( NotNull() )
	{
		Reset();	// Iterator�� head�� �̵�
		m_pCurPointer = m_pCurPointer->next;
		while( m_pCurPointer->next != NULL )	// ������ �̵�
		{
			m_pCurPointer = m_pCurPointer->next;
			delete m_pCurPointer->back;	// �ϳ��� ����
		}
	
		m_pCurPointer->back = m_List.head;
		delete m_pCurPointer->back;	// head���
		delete m_pCurPointer;		// tail���
	}
}

// Iterator�� head�� �̵�
template<typename T>
void Iterator<T> :: Reset()
{
	m_pCurPointer = m_List.head;
}

//���� ��尡 NULL���� �Ǻ�
template <typename T>
bool Iterator<T> :: NotNull()
{
	if(m_pCurPointer == NULL)
		return false;
	else
		return true;
}

// ���� ��尡 NULL���� �Ǻ�
template <typename T>
bool Iterator<T> :: NextNotNull()
{
	if(m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

// ó�� ����� �����͸� �޾ƿ�
template <typename T>
T Iterator<T> :: First()
{
	return m_List.head->info;
}

// ��带 �������� �̵��ϰ� ���� ����� �����͸� �޾ƿ�
template <typename T>
T Iterator<T> :: Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->info;
}

// ���� ��带 �޾ƿ�
template <typename T>
NodeType<T> Iterator<T> :: GetCurrentNode()
{
	return *m_pCurPointer;
}

#endif _ITERATOR_H
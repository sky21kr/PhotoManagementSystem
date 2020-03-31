#pragma once
#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "SortedList.h"

// 템플릿 이므로
template<typename T>
struct NodeType;
template<typename T>
class SortedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T> 
class Iterator
{
	friend class SortedList<T>;	// 리스트와 친구 클래스
public:
	/**
	*	디폴트 생성자.
	*/
	Iterator(const SortedList<T> &list) : m_List(list), m_pCurPointer(list.head)
	{

	}; ///< SortedLinkedList와 친구 클래스.

	/**
	*	@brief	현재 Iterator가 NULL인지 판별
	*	@pre	Iterator가 초기화되어야함
	*	@post	없음
	*	@return	현재 Iterator가 NULL이면 false, 아니면 TRUE
	*/
	bool NotNull();

	/**
	*	@brief	다음 Iterator가 NULL인지 판별
	*	@pre	다음 Iterator가 있어야함
	*	@post	없음
	*	@return	다음 Iterator가 NULL이면 false, 아니면 TRUE
	*/
	bool NextNotNull();

	/**
	*	@brief	리스트 첫번째 데이터를 받아옴
	*	@pre	리스트의 첫번째 데이터가 있어야함
	*	@post	없음
	*	@return	리스트 첫번째 데이터
	*/
	T First();

	/**
	*	@brief	Iterator를 다음으로 이동시키고 다음 데이터를 받아옴
	*	@pre	다음으로 이동할 리스트가 있어야함
	*	@post	Iterator가 다음으로 이동함
	*	@return	다음 리스트 데이터
	*/
	T Next();

	/**
	*	@brief	현재 노드를 가져옴
	*	@pre	Iterator가 초기화 되어져 있어야함
	*	@post	없음
	*	@return	현재 노드
	*/
	NodeType<T> GetCurrentNode();

	/**
	*	@brief	head로 이동함
	*	@pre	Iterator가 초기화 되어져 있어야함
	*	@post	Iterator가 head로 이동함/
	*/
	void Reset();

	/**
	*	@brief	리스트를 모두 비움
	*	@pre	리스트가 만들어져 있어야함
	*	@post	리스트가 모두 비워지고 동적할당이 해제됨
	*/
	void MakeEmpty();

private:
	const SortedList<T> &m_List;	///< 리스트 받아옴
	NodeType<T>* m_pCurPointer;		///< 현재 노드의 데이터 주소
};

// 리스트를 비움
template<typename T>
void Iterator<T>::MakeEmpty()
{
	if( NotNull() )
	{
		Reset();	// Iterator가 head로 이동
		m_pCurPointer = m_pCurPointer->next;
		while( m_pCurPointer->next != NULL )	// 끝까지 이동
		{
			m_pCurPointer = m_pCurPointer->next;
			delete m_pCurPointer->back;	// 하나씩 비운다
		}
	
		m_pCurPointer->back = m_List.head;
		delete m_pCurPointer->back;	// head비움
		delete m_pCurPointer;		// tail비움
	}
}

// Iterator가 head로 이동
template<typename T>
void Iterator<T> :: Reset()
{
	m_pCurPointer = m_List.head;
}

//현재 노드가 NULL인지 판별
template <typename T>
bool Iterator<T> :: NotNull()
{
	if(m_pCurPointer == NULL)
		return false;
	else
		return true;
}

// 다음 노드가 NULL인지 판별
template <typename T>
bool Iterator<T> :: NextNotNull()
{
	if(m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

// 처음 노드의 데이터를 받아옴
template <typename T>
T Iterator<T> :: First()
{
	return m_List.head->info;
}

// 노드를 다음으로 이동하고 다음 노드의 데이터를 받아옴
template <typename T>
T Iterator<T> :: Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->info;
}

// 현재 노드를 받아옴
template <typename T>
NodeType<T> Iterator<T> :: GetCurrentNode()
{
	return *m_pCurPointer;
}

#endif _ITERATOR_H
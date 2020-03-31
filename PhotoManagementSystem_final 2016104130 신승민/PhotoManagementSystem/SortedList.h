#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
#include"Iterator.h"
using namespace std;

enum RelationType {LESS, GREATER, EQUAL};

//템플릿 클래스이므로
template<typename T>	
class Iterator;

template<typename T>
struct NodeType	//링크드리스트를 위한 구조체
{
	T info;	///< 정보를 가짐
	NodeType<T>* back;
	NodeType<T>* next;	///< 다음으로 향하는 주소
};

/**
*	링크드리스트를 바탕으로하는 sorted list.
*/
template<typename T>
class SortedList
{
	friend class Iterator<T>;
public:
	/**
	*	기본 생성자
	*/
	SortedList();

	/**
	*	소멸자
	*/
	~SortedList()
	{
		
	}

	/**
	*	@brief	리스트를 비움
	*	@pre	없음
	*	@post	리스트가 비워짐
	*/
	void MakeEmpty();

	/**
	*	@brief	현재 리스트의 길이를 얻음
	*	@pre	없음
	*	@post	없음
	*	@return	현재 리스트의 길이를 리턴함
	*/
	int GetLength();

	/**
	*	@brief	Name를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가하고 Name이 같으면 추가하지 않음
	*	@pre	리스트가 초기화 되어져 있어야함
	*	@post	리스트에 새 데이터가 더해짐
	*	@param	data	새 데이터
	*	@return	잘 더해지면 1, 동일한 Name이 존재하면 0을 리턴함
	*/
	int Add(T data);

	/**
	*	@brief	사용자가 지정한 ItemType를 배열에서 삭제한다.
	*	@pre	data의 Name 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data	Name만 채워져있는 ItemType.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int Delete(T data);


	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다. 대상을 찾을때 Binary Search를 이용한다.
	*	@pre	data의 Name 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data	Name만 채워져있는 ItemType.
	*	@return	찾은 데이터의 위치를 리턴하고 찾지 못하면 -1을 리턴함
	*/
	int GetByBinarySearch(T& data);

	/**
	*	@brief	링크드리스트 중 i번째 위치 주소를 받아옴
	*	@pre	링크드리스트가 초기화 되어져 있어야함
	*	@post	없음
	*	@param	i	링크드리스트 중 받아올 주소의 위치
	*	@return	받아올 링크드리스트의 주소
	*/
	T* GetLinkedList(int i);
private:
	NodeType<T>* head;	///< 링크드리스트 헤드
	NodeType<T>* tail;	///< 링크드리스트 꼬리
	int m_Length;		///< 리스트 요소의 길이
};

// 기본 생성자
template<typename T>
SortedList<T>::SortedList()
{
	head = NULL;
	tail = NULL;
	m_Length = 0;
}

// 링크드리스트중 i번째 위치 주소를 받아옴
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


// 리스트를 비움
template<typename T>
void SortedList<T>::MakeEmpty()
{
	Iterator<T> itor(*this);
	itor.MakeEmpty();
	m_Length = 0;
}

// 현재 리스트의 데이터 길이를 받아옴
template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}

// 리스트에 새 데이터를 더함
template<typename T>
int SortedList<T>::Add(T inData)
{
	if( m_Length == 0 ) //데이터가 처음에 하나도 없을시
	{
		head = new NodeType<T>;
		tail = new NodeType<T>;
		
		head->back = NULL;
		head->next = tail;

		tail->back = head;
		tail->next = NULL;

		NodeType<T>* NewNode = new NodeType<T>; // 새로운 데이터 저장할 곳
		NewNode->info = inData;
		NewNode->back = head;
		NewNode->next = tail;
		head->next = NewNode;	// 첫번째 데이터
		tail->back = NewNode;
		m_Length++;
		return 1;
	}
	else	// 데이터가 하나 이상 있을 시
	{
		Iterator<T> itor(*this);

		while(1)
		{
			itor.Next();
			if( inData.GetName() < itor.m_pCurPointer->info.GetName() ) // 새로넣는 데이터가 더 이름이 빠른경우
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
			else if(inData.GetName() == itor.m_pCurPointer->info.GetName())	// 이름이 같은 경우
			{
				return 0;
			}
			else if( itor.m_pCurPointer == tail )	// 마지막 인 경우
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

//Name값만 존재하는 data를 이용하여 그 Name값과 같은 Name를 가지고 있는 항목을 지워주고 length를 1 빼준다.
template<typename T>
int SortedList<T>::Delete(T data)
{
	Iterator<T> itor(*this);
	for(int i = 0 ; i < m_Length ; i++ )
	{
		itor.Next();
		if( itor.m_pCurPointer->info.GetName() == data.GetName() )	// 일치하는 이름 발견시
		{
			itor.m_pCurPointer->back->next = itor.m_pCurPointer->next;
			itor.m_pCurPointer->next->back = itor.m_pCurPointer->back;

			delete itor.m_pCurPointer;

			m_Length--;
			return 1;
		}
		else if(itor.m_pCurPointer == tail)	// 끝까지 갔는데도 못찾은 경우
		{
			return 0;
		}
	}
	return -1;
}


//Name값만 존재하는 data에 알맞는 항목을 Binary Search를 이용해 찾아 복사해주고 위치를 리턴한다
template<typename T>
int SortedList<T>::GetByBinarySearch(T& data) 
{
	int first=1;	// 배열이 아니므로 1부터 시작
	int last=m_Length;	// 배열이 아니므로 크기 그대로 저장
	bool found=0;

	Iterator<T> itor(*this);
	while(first<=last&&!found)	//first가 last보다 커지면 더이상 진행하지 않는다. found가 1이 되면 진행하지 않는다.
	{
		itor.Reset();
		int mid=(first+last)/2;	//mid는 first와 last의 평균값

		for(int i = 0 ; i <  mid ; i++ )
		{
			itor.Next();
		}
		switch(data.CompareByName(itor.m_pCurPointer->info))	//data와 링크드리스트의 Name값 비교
		{
		case LESS:
			last=mid-1;
			break;	//data의 Name값이 더 작을때, last를 mid-1로 옮겨준다.
		case GREATER:
			first=mid+1;
			break;	//data의 Name값이 더 클때, first를 mid+1로 옮겨준다.
		case EQUAL:
			data=itor.m_pCurPointer->info;
			found=1;
			return mid;	//data와 링크드리스트의 mid위치의 Name값이 같으면 data에 객체를 복사해주고 위치인 mid를 리턴한다. 반복문을 빠져나오기 위해 found=1을 해준다.
			break;
		}
	}
	return -1;	//찾지 못했으므로 -1을 리턴해준다.
}

#endif	// _SORTEDLIST_H
#pragma once
#include <iostream>
using namespace std;

enum Boolean {FALSE,TRUE};
template <class Type> class PriorityQueue;
template <class Type> class MinHeap;
template <class Type>
void Swap (Type& one, Type& two)
{
	Type tmp = one;
	one = two;
	two = tmp;
}


#define DEFAULTSIZE 100
template <class Type>
class HeapBase {
public:
	Type* heap;  // 배열
	int lastNode;  // 현재 노드의 수
	int maxSize;     // 배열 최대 사이즈
public:
	/**
	*	생성자
	*/
	HeapBase()
	{
	}

	/**
	*	소멸자
	*/
	~HeapBase()
	{
	}
	/**
	*	Put 순수가상함수
	*/
    virtual int Put(Type) = 0;
	/**
	*	Get 순수가상함수
	*/
    virtual Type *Get(Type&) = 0;
    void	Reset() { memset( heap, 0, sizeof(Type)*(maxSize+1) ); };

	/**
	*	@brief	꽉 찼는지 확인
	*	@pre	없음
	*	@post	없음
	*	@return	꽉 찼으면 true, 아니면 false 반환
	*/
	Boolean IsFull()
	{	
		if (lastNode==maxSize) 
			return TRUE;
		else					 
			return FALSE;
	};

	/**
	*	@brief	비었는지 확인
	*	@pre	없음
	*	@post	없음
	*	@return	비었으면 true, 아니면 false 반환
	*/
	Boolean IsEmpty()
	{ 
		if (lastNode==0) 
			return TRUE; 
		else 
			return FALSE;
	};
};

template <class Type>
class MinHeap: public HeapBase<Type>
{
public:
	/**
	*	생성자
	*/
	MinHeap(int sz)
	{ 
		maxSize = sz-1;
		heap = new Type[sz]; 
		memset( heap, 0, sizeof(Type)*(sz) ); //초기화
		lastNode = 0;		
	};
	/**
	*	소멸자
	*/
	~MinHeap()
	{ 
		delete [] heap;
	};

	// If IsFull()이면 0을, 성공적으로 삽입하면 1을 리턴 
	// If IsFull, then return 0. But if success to insert, then return 1
	/**
	*	@brief	노드를 추가함
	*	@pre	없음
	*	@post	노드가 추가됨
	*	@param	item 추가할 노드
	*	@return	같은게 있으면 0 없으면 추가 후 1 반환
	*/
	int Put(Type &item);

	/**
	*	@brief	노드를 얻어옴
	*	@pre	노드가 있어야함
	*	@post	노드가 하나 삭제됨
	*	@param	얻어온 노드
	*	@return 얻어온 노드의 주소
	*/
    Type *Get(Type &x);

    /**
	*	@brief	힙업
	*	@pre	없음
	*	@post	배열 구조가 바뀜
	*	@param	root 시작 bottom 끝
	*/
	void ReheapUp ( int  root,  int  bottom );

	/**
	*	@brief	힙다운
	*	@pre	없음
	*	@post	배열 구조가 바뀜
	*	@param	root 시작 bottom 끝
	*/
	void ReheapDown ( int  root,  int  bottom );
};


// 리힙업
template<class  Type>
void MinHeap<Type>::ReheapUp ( int  root,  int  bottom )
{
	int  parent ;
	
	if ( bottom  > root )
	{
		parent = ( bottom-1 ) / 2;
		if ( heap[parent].key > heap[bottom].key )
		{
			Swap ( heap[parent], heap[bottom] ) ;
			ReheapUp (root, parent) ;
		}
	}
}	

// 노드 추가
template<class Type> 
int MinHeap<Type>::Put(Type &node)
{
	if (lastNode==maxSize)
		return 0;
	else 
	{
		heap[lastNode] = node;
		ReheapUp(0, lastNode);
		lastNode++;
	}

	return 1;
}

// 리힙다운
template<class  Type>
void MinHeap<Type>::ReheapDown (int root, int bottom)
{
	int minChild;
	int rightChild;
	int leftChild;


	leftChild = root * 2+1;

	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			minChild = leftChild;
		else
		{
			if (rightChild == bottom)
				minChild = rightChild;
			else
			{
				if (heap[leftChild].key > heap[rightChild].key) 
					minChild = rightChild;
				else
					minChild = leftChild;	
			}
				
		}
		if (heap[root].key > heap[minChild].key)
		{
			Swap(heap[root], heap[minChild]);
			ReheapDown(minChild, bottom);
		}
	}
}

// 노드를 받아옴
template <class Type>
Type *MinHeap<Type>::Get(Type &x)
{
	if (!lastNode)
	{ 
		return 0; 
	}
	else
	{
		x = heap[0]; // 최소값(root)을 리턴 값으로 취함
		heap[0] = heap[lastNode-1];
		lastNode--;	
		ReheapDown(0, lastNode);
   }
   return &x;
}

// MAX HEAP
template<typename Type>
class MaxHeap : public HeapBase<Type>
{
public:
	/**
	*	생성자
	*/
	MaxHeap() 
	{ 
		maxSize = 100;
		heap = new Type[maxSize+1]; 
		memset( heap, 0, sizeof(Type)*(maxSize+1) );
		lastNode = 0;		
	};
	
	/**
	*	소멸자
	*/
	~MaxHeap()
	{
		delete [] heap;
	};

	/**
	*	@brief	노드를 추가함
	*	@pre	없음
	*	@post	노드가 추가됨
	*	@param	item 추가할 노드
	*	@return	같은게 있으면 0 없으면 추가 후 1 반환
	*/
	int Put(Type item);

	/**
	*	@brief	노드를 얻어옴
	*	@pre	노드가 있어야함
	*	@post	노드가 하나 삭제됨
	*	@param	얻어온 노드
	*	@return 얻어온 노드의 주소
	*/
    Type *Get(Type &x);
	/**
	*	@brief	노드가 출력됨
	*	@pre	없음
	*	@post	없음
	*/
	void PrintHeap();

	/**
	*	@brief	힙업
	*	@pre	없음
	*	@post	배열 구조가 바뀜
	*	@param	root 시작 bottom 끝
	*/
	void ReheapUp ( int  root,  int  bottom );
	/**
	*	@brief	힙다운
	*	@pre	없음
	*	@post	배열 구조가 바뀜
	*	@param	root 시작 bottom 끝
	*/
	void ReheapDown ( int  root,  int  bottom );
};

// 노드 추가
template<class Type>
int MaxHeap<Type>::Put(Type node)
{
	if( lastNode == maxSize )
	{
		return 0;
	}
	else
	{
		heap[lastNode] = node;
		ReheapUp(0,lastNode);
		lastNode++;
	}

	return 1;
}

// 리힙업
template<typename Type>
void MaxHeap<Type>::ReheapUp ( int  root,  int  bottom )
{
	int parent;
	if( root < bottom )
	{
		parent = (bottom - 1)/2;
		if( heap[parent]->getdate() < heap[bottom]->getdate() )
		{
			Swap( heap[parent] , heap[bottom] );
			ReheapUp( root, parent);
		}
	}
}

// 노드를 받아옴
template<typename Type>
Type* MaxHeap<Type>::Get(Type &x)
{
	if( lastNode == 0 )
	{
		return 0;
	}
	else
	{
		x = heap[0];
		heap[0] = heap[lastNode-1];
		lastNode--;
		ReheapDown(0,lastNode);
	}
	return &x;
}

// 리힙다운
template<typename Type>
void MaxHeap<Type>::ReheapDown( int  root,  int  bottom )
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2+1;

	rightChild = root * 2 + 2;

	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (rightChild == bottom)
				maxChild = rightChild;
			else
			{
				if (heap[leftChild]->getdate() < heap[rightChild]->getdate()) 
					maxChild = rightChild;
				else
					maxChild = leftChild;	
			}
				
		}
		if (heap[root]->getdate() < heap[maxChild]->getdate())
		{
			Swap(heap[root], heap[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

// 노드를 모두 출력함
template<typename Type>
void MaxHeap<Type>::PrintHeap()
{
	cout << endl << endl;
	if( lastNode == 0 )
	{
		cout << "\t즐겨찾기 목록이 없습니다" << endl;
	}

	for( int i = 0 ; i < lastNode ; i++ )
	{
		cout << endl;
		heap[i]->DisplayPhoto();
	}
}
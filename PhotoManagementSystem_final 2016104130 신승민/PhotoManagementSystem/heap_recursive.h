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
	Type* heap;  // �迭
	int lastNode;  // ���� ����� ��
	int maxSize;     // �迭 �ִ� ������
public:
	/**
	*	������
	*/
	HeapBase()
	{
	}

	/**
	*	�Ҹ���
	*/
	~HeapBase()
	{
	}
	/**
	*	Put ���������Լ�
	*/
    virtual int Put(Type) = 0;
	/**
	*	Get ���������Լ�
	*/
    virtual Type *Get(Type&) = 0;
    void	Reset() { memset( heap, 0, sizeof(Type)*(maxSize+1) ); };

	/**
	*	@brief	�� á���� Ȯ��
	*	@pre	����
	*	@post	����
	*	@return	�� á���� true, �ƴϸ� false ��ȯ
	*/
	Boolean IsFull()
	{	
		if (lastNode==maxSize) 
			return TRUE;
		else					 
			return FALSE;
	};

	/**
	*	@brief	������� Ȯ��
	*	@pre	����
	*	@post	����
	*	@return	������� true, �ƴϸ� false ��ȯ
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
	*	������
	*/
	MinHeap(int sz)
	{ 
		maxSize = sz-1;
		heap = new Type[sz]; 
		memset( heap, 0, sizeof(Type)*(sz) ); //�ʱ�ȭ
		lastNode = 0;		
	};
	/**
	*	�Ҹ���
	*/
	~MinHeap()
	{ 
		delete [] heap;
	};

	// If IsFull()�̸� 0��, ���������� �����ϸ� 1�� ���� 
	// If IsFull, then return 0. But if success to insert, then return 1
	/**
	*	@brief	��带 �߰���
	*	@pre	����
	*	@post	��尡 �߰���
	*	@param	item �߰��� ���
	*	@return	������ ������ 0 ������ �߰� �� 1 ��ȯ
	*/
	int Put(Type &item);

	/**
	*	@brief	��带 ����
	*	@pre	��尡 �־����
	*	@post	��尡 �ϳ� ������
	*	@param	���� ���
	*	@return ���� ����� �ּ�
	*/
    Type *Get(Type &x);

    /**
	*	@brief	����
	*	@pre	����
	*	@post	�迭 ������ �ٲ�
	*	@param	root ���� bottom ��
	*/
	void ReheapUp ( int  root,  int  bottom );

	/**
	*	@brief	���ٿ�
	*	@pre	����
	*	@post	�迭 ������ �ٲ�
	*	@param	root ���� bottom ��
	*/
	void ReheapDown ( int  root,  int  bottom );
};


// ������
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

// ��� �߰�
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

// �����ٿ�
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

// ��带 �޾ƿ�
template <class Type>
Type *MinHeap<Type>::Get(Type &x)
{
	if (!lastNode)
	{ 
		return 0; 
	}
	else
	{
		x = heap[0]; // �ּҰ�(root)�� ���� ������ ����
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
	*	������
	*/
	MaxHeap() 
	{ 
		maxSize = 100;
		heap = new Type[maxSize+1]; 
		memset( heap, 0, sizeof(Type)*(maxSize+1) );
		lastNode = 0;		
	};
	
	/**
	*	�Ҹ���
	*/
	~MaxHeap()
	{
		delete [] heap;
	};

	/**
	*	@brief	��带 �߰���
	*	@pre	����
	*	@post	��尡 �߰���
	*	@param	item �߰��� ���
	*	@return	������ ������ 0 ������ �߰� �� 1 ��ȯ
	*/
	int Put(Type item);

	/**
	*	@brief	��带 ����
	*	@pre	��尡 �־����
	*	@post	��尡 �ϳ� ������
	*	@param	���� ���
	*	@return ���� ����� �ּ�
	*/
    Type *Get(Type &x);
	/**
	*	@brief	��尡 ��µ�
	*	@pre	����
	*	@post	����
	*/
	void PrintHeap();

	/**
	*	@brief	����
	*	@pre	����
	*	@post	�迭 ������ �ٲ�
	*	@param	root ���� bottom ��
	*/
	void ReheapUp ( int  root,  int  bottom );
	/**
	*	@brief	���ٿ�
	*	@pre	����
	*	@post	�迭 ������ �ٲ�
	*	@param	root ���� bottom ��
	*/
	void ReheapDown ( int  root,  int  bottom );
};

// ��� �߰�
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

// ������
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

// ��带 �޾ƿ�
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

// �����ٿ�
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

// ��带 ��� �����
template<typename Type>
void MaxHeap<Type>::PrintHeap()
{
	cout << endl << endl;
	if( lastNode == 0 )
	{
		cout << "\t���ã�� ����� �����ϴ�" << endl;
	}

	for( int i = 0 ; i < lastNode ; i++ )
	{
		cout << endl;
		heap[i]->DisplayPhoto();
	}
}
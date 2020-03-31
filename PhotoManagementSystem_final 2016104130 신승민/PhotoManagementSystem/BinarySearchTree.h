#include <iostream>
using namespace std;

// 이진 트리 노드
template<typename T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
};


// 이진검색트리 템플릿 클래스
template<typename T>
class BinarySearchTree
{
public:
	/**
	*	생성자
	*/
	BinarySearchTree()
	{
		root = NULL;
	}

	/**
	*	소멸자
	*/
	~BinarySearchTree()
	{
	}

	/**
	*	@brief	노드가 꽉 비었는지 확인
	*	@pre	없음
	*	@post	없음
	*	@return	노드가 비었으면 true, 아니면 false
	*/
	bool IsEmpty() const;
	
	/**
	*	@brief	노드가 꽉 찼는지 확인
	*	@pre	없음
	*	@post	없음
	*	@return	노드가 꽉 찼으면 true, 아니면 false
	*/
	bool IsFull() const;

	/**
	*	@brief	노드들을 모두 비운다
	*	@pre	노드들이 초기화 되어져 있어야함
	*	@post	노드들이 모두 비워짐
	*/
	void MakeEmpty();

	/**
	*	@brief	노드들의 개수를 구한다.
	*	@pre	없음
	*	@post	없음
	*	@return	노드들의 개수
	*/
	int GetLength() const;

	/**
	*	@brief	노드를 추가함
	*	@pre	없음
	*	@post	노드가 추가됨
	*	@param	item	추가할 노드
	*	@return	같은 이름의 노드가 존재하여 추가에 실패하면 false, 그외 추가에 성공하면 true
	*/
	bool Add(T item);

	/**
	*	@brief	노드를 삭제함
	*	@pre	없음
	*	@post	노드가 삭제됨
	*	@param	item	삭제할 이름만 가진 노드
	*	@return	삭제에 성공하면 true, 실패하면 false
	*/
	bool DeleteItem(T item);

	/**
	*	@brief	노드를 검색함
	*	@pre	없음
	*	@post	없음
	*	@param	item	찾아오기위해 이름만 가진 노드	found	찾았는지 확인하기 위한 것
	*/
	T* RetrieveItem(T &item, bool &found) const;

	/**
	*	@brief	현재 노드들을 모두 출력함
	*	@pre	없음
	*	@post	없음
	*/
	void PrintTree(bool found) const;

	/**
	*	@brief	노드값을 직접 받아옴
	*	@pre	없음
	*	@post	없음
	*	@param	i	받아올 노드의 순서
	*	@return	받아올 노드
	*/
	T ReturnData(int i);

private:
	BinaryTreeNode<T>* root;	// 루트 노드
};

// 노드를 직접 받아옴
template<typename T>
T BinarySearchTree<T>::ReturnData(int want)
{
	int i = 0;
	T item;
	ReturnTravel(root, item, i, want);
	return item;
}

// 노드를 직접 도는 함수
template<typename T>
bool ReturnTravel(BinaryTreeNode<T> *root, T &item, int &i, int want)
{
	if( root == NULL )
	{
		i--;	// 순서를 세기 위하여
		return false;
	}
	else
	{
		if( i == want )	// 순서에 맞는 노드를 찾을 시
		{
			// i--;
			item = root->data;
			return true;
		}
		i++;// 다음 순서
		ReturnTravel(root->left,item, i , want);	// 왼쪽 노드 돌음
		i++; // 다음 순서
		ReturnTravel(root->right,item, i , want);	// 오른쪽 노드 돌음
	}
}

// 노드가 비었는지 확인
template<typename T>
bool BinarySearchTree<T>::IsEmpty() const
{
	if( root == NULL )
		return true;
	else
		return false;
}

// 노드가 꽉 찼는지 확인
template<typename T>
bool BinarySearchTree<T>::IsFull() const
{
	BinaryTreeNode<T>* NewNode;
	try
	{
		NewNode = new BinaryTreeNode<T>;
		delete NewNode;
		return false;
	}
	catch( std::bad_alloc exception )
	{
		return true;
	}
}

// 노드를 비운다
template<typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);
}

// 노드를 돌며 직접 비우는 함수
template<typename T>
void MakeEmptyTree(BinaryTreeNode<T>*& root)
{
	if( root != NULL )
	{
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;	// 다 돌고 비우는 순서
	}
	else
		return;
}

// 노드의 개수를 구한다.
template<typename T>
int BinarySearchTree<T>::GetLength() const
{
	return CountNodes(root);
}

// 노드를 돌며 직접 노드의 개수를 세는 함수
template<typename T>
int CountNodes(BinaryTreeNode<T> *root)
{
	if( root == NULL )
	{
		return 0;
	}
	else
	{
		return( CountNodes(root->left) + CountNodes(root->right) + 1 );
	}
}

// 노드를 더한다
template<typename T>
bool BinarySearchTree<T>::Add(T item)
{
	if ( Insert(root,item) == true )
		return true;
	else
		return false;
}

// 노드를 직접 더해주는 함수
template<typename T>
bool Insert(BinaryTreeNode<T>*& root, T item)
{
	if( root == NULL )	// 빈 노드의 공간을 찾았을 경우
	{
		root = new BinaryTreeNode<T>;
		root->data = item;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	else if( item > root->data )
	{
		return Insert( root->right, item );
	}
	else if( item < root->data )
	{
		return Insert( root->left, item );
	}
	else	// 동일한 이름이 존재할 시
	{
		return false;
	}

	return true;
}

// 노드를 삭제함
template<typename T>
bool BinarySearchTree<T>::DeleteItem(T item)
{
	if( Delete(root, item) == true ) //삭제 성공시
		return true;
	else
		return false;
}

// 노드를 삭제하는 함수
template<typename T>
bool Delete(BinaryTreeNode<T> *&root, T item)
{
	if( root == NULL )	// 끝까지 갔는데 노드가 비었을 경우
	{
		return false;
	}
	else if( item > root->data )
	{
		return Delete(root->right , item);
	}
	else if( item < root->data )
	{
		return Delete( root->left , item );
	}
	else	// 파일 찾을 시
	{
		DeleteNode( root );
		return true;
	}
}

// 노드를 삭제하고 트리를 재구성함
template<typename T>
void DeleteNode( BinaryTreeNode<T> *&root )
{
	T item;

	if( root->left == NULL )
	{
		root = root->right;
	}
	else if( root->right == NULL )
	{
		root = root->left;
	}
	else
	{
		GetPredecessor( root->left, item ); // 노드를 재구성 하기위해
		root->data = item;
		Delete( root->left , item );
	}
}

// 현재 노드 기준으로 제일 오른쪽 아래의 노드를 가져옴
template<typename T>
void GetPredecessor(BinaryTreeNode<T> *&root, T &item)
{
	while( root->right != NULL )
		root = root->right;
	item = root->data;
}

// 노드를 검색함
template<typename T>
T* BinarySearchTree<T>::RetrieveItem(T &item, bool &found) const
{
	return Retrieve(root, item, found);
}

// 노드를 직접 검색하는 함수
template<typename T>
T* Retrieve(BinaryTreeNode<T> *root, T &item, bool &found)
{
	if( root == NULL )
	{
		found = false;
		return NULL;
	}
	else if( item < root->data )
	{
		return Retrieve( root->left , item, found );
	}
	else if( item > root->data )
	{
		return Retrieve( root->right , item, found );
	}
	else
	{
		found = true;
		item = root->data;
		return &root->data;
	}
}

// 노드들을 모두 출력함
template<typename T>
void BinarySearchTree<T>::PrintTree(bool found ) const
{
	PrintInOrderTraversal( root ,found );
}

// InOrder 순서로 출력
template<typename T>
void PrintInOrderTraversal( BinaryTreeNode<T> *root , bool found)
{
	if( root != NULL )
	{
		PrintInOrderTraversal( root->left , found );
		if( root->data.gethide() == found )
		{
			cout << "\t - 사진 이름 : " << root->data.GetName() << endl;
		}
		PrintInOrderTraversal( root->right , found );
	}
}

// PreOrder 순서로 출력
template<typename T>
void PrintPreOrderTraversal( BinaryTreeNode<T> *root )
{
	if( root != NULL )
	{
		cout << "\t이름 : " << root->data.GetName() << endl;
		PrintPreOrderTraversal( root->left );
		PrintPreOrderTraversal( root->right );
	}
}

// PostOrder 순서로 출력
template<typename T>
void PrintPostOrderTraversal( BinaryTreeNode<T> *root )
{
	if( root != NULL )
	{
		PrintPostOrderTraversal( root->left );
		PrintPostOrderTraversal( root->right );
		cout << "\t이름 : " << root->data.GetName() << endl;
	}
}
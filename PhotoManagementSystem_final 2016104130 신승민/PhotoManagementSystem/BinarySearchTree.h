#include <iostream>
using namespace std;

// ���� Ʈ�� ���
template<typename T>
struct BinaryTreeNode
{
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
};


// �����˻�Ʈ�� ���ø� Ŭ����
template<typename T>
class BinarySearchTree
{
public:
	/**
	*	������
	*/
	BinarySearchTree()
	{
		root = NULL;
	}

	/**
	*	�Ҹ���
	*/
	~BinarySearchTree()
	{
	}

	/**
	*	@brief	��尡 �� ������� Ȯ��
	*	@pre	����
	*	@post	����
	*	@return	��尡 ������� true, �ƴϸ� false
	*/
	bool IsEmpty() const;
	
	/**
	*	@brief	��尡 �� á���� Ȯ��
	*	@pre	����
	*	@post	����
	*	@return	��尡 �� á���� true, �ƴϸ� false
	*/
	bool IsFull() const;

	/**
	*	@brief	������ ��� ����
	*	@pre	������ �ʱ�ȭ �Ǿ��� �־����
	*	@post	������ ��� �����
	*/
	void MakeEmpty();

	/**
	*	@brief	������ ������ ���Ѵ�.
	*	@pre	����
	*	@post	����
	*	@return	������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	��带 �߰���
	*	@pre	����
	*	@post	��尡 �߰���
	*	@param	item	�߰��� ���
	*	@return	���� �̸��� ��尡 �����Ͽ� �߰��� �����ϸ� false, �׿� �߰��� �����ϸ� true
	*/
	bool Add(T item);

	/**
	*	@brief	��带 ������
	*	@pre	����
	*	@post	��尡 ������
	*	@param	item	������ �̸��� ���� ���
	*	@return	������ �����ϸ� true, �����ϸ� false
	*/
	bool DeleteItem(T item);

	/**
	*	@brief	��带 �˻���
	*	@pre	����
	*	@post	����
	*	@param	item	ã�ƿ������� �̸��� ���� ���	found	ã�Ҵ��� Ȯ���ϱ� ���� ��
	*/
	T* RetrieveItem(T &item, bool &found) const;

	/**
	*	@brief	���� ������ ��� �����
	*	@pre	����
	*	@post	����
	*/
	void PrintTree(bool found) const;

	/**
	*	@brief	��尪�� ���� �޾ƿ�
	*	@pre	����
	*	@post	����
	*	@param	i	�޾ƿ� ����� ����
	*	@return	�޾ƿ� ���
	*/
	T ReturnData(int i);

private:
	BinaryTreeNode<T>* root;	// ��Ʈ ���
};

// ��带 ���� �޾ƿ�
template<typename T>
T BinarySearchTree<T>::ReturnData(int want)
{
	int i = 0;
	T item;
	ReturnTravel(root, item, i, want);
	return item;
}

// ��带 ���� ���� �Լ�
template<typename T>
bool ReturnTravel(BinaryTreeNode<T> *root, T &item, int &i, int want)
{
	if( root == NULL )
	{
		i--;	// ������ ���� ���Ͽ�
		return false;
	}
	else
	{
		if( i == want )	// ������ �´� ��带 ã�� ��
		{
			// i--;
			item = root->data;
			return true;
		}
		i++;// ���� ����
		ReturnTravel(root->left,item, i , want);	// ���� ��� ����
		i++; // ���� ����
		ReturnTravel(root->right,item, i , want);	// ������ ��� ����
	}
}

// ��尡 ������� Ȯ��
template<typename T>
bool BinarySearchTree<T>::IsEmpty() const
{
	if( root == NULL )
		return true;
	else
		return false;
}

// ��尡 �� á���� Ȯ��
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

// ��带 ����
template<typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);
}

// ��带 ���� ���� ���� �Լ�
template<typename T>
void MakeEmptyTree(BinaryTreeNode<T>*& root)
{
	if( root != NULL )
	{
		MakeEmptyTree(root->left);
		MakeEmptyTree(root->right);
		delete root;	// �� ���� ���� ����
	}
	else
		return;
}

// ����� ������ ���Ѵ�.
template<typename T>
int BinarySearchTree<T>::GetLength() const
{
	return CountNodes(root);
}

// ��带 ���� ���� ����� ������ ���� �Լ�
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

// ��带 ���Ѵ�
template<typename T>
bool BinarySearchTree<T>::Add(T item)
{
	if ( Insert(root,item) == true )
		return true;
	else
		return false;
}

// ��带 ���� �����ִ� �Լ�
template<typename T>
bool Insert(BinaryTreeNode<T>*& root, T item)
{
	if( root == NULL )	// �� ����� ������ ã���� ���
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
	else	// ������ �̸��� ������ ��
	{
		return false;
	}

	return true;
}

// ��带 ������
template<typename T>
bool BinarySearchTree<T>::DeleteItem(T item)
{
	if( Delete(root, item) == true ) //���� ������
		return true;
	else
		return false;
}

// ��带 �����ϴ� �Լ�
template<typename T>
bool Delete(BinaryTreeNode<T> *&root, T item)
{
	if( root == NULL )	// ������ ���µ� ��尡 ����� ���
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
	else	// ���� ã�� ��
	{
		DeleteNode( root );
		return true;
	}
}

// ��带 �����ϰ� Ʈ���� �籸����
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
		GetPredecessor( root->left, item ); // ��带 �籸�� �ϱ�����
		root->data = item;
		Delete( root->left , item );
	}
}

// ���� ��� �������� ���� ������ �Ʒ��� ��带 ������
template<typename T>
void GetPredecessor(BinaryTreeNode<T> *&root, T &item)
{
	while( root->right != NULL )
		root = root->right;
	item = root->data;
}

// ��带 �˻���
template<typename T>
T* BinarySearchTree<T>::RetrieveItem(T &item, bool &found) const
{
	return Retrieve(root, item, found);
}

// ��带 ���� �˻��ϴ� �Լ�
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

// ������ ��� �����
template<typename T>
void BinarySearchTree<T>::PrintTree(bool found ) const
{
	PrintInOrderTraversal( root ,found );
}

// InOrder ������ ���
template<typename T>
void PrintInOrderTraversal( BinaryTreeNode<T> *root , bool found)
{
	if( root != NULL )
	{
		PrintInOrderTraversal( root->left , found );
		if( root->data.gethide() == found )
		{
			cout << "\t - ���� �̸� : " << root->data.GetName() << endl;
		}
		PrintInOrderTraversal( root->right , found );
	}
}

// PreOrder ������ ���
template<typename T>
void PrintPreOrderTraversal( BinaryTreeNode<T> *root )
{
	if( root != NULL )
	{
		cout << "\t�̸� : " << root->data.GetName() << endl;
		PrintPreOrderTraversal( root->left );
		PrintPreOrderTraversal( root->right );
	}
}

// PostOrder ������ ���
template<typename T>
void PrintPostOrderTraversal( BinaryTreeNode<T> *root )
{
	if( root != NULL )
	{
		PrintPostOrderTraversal( root->left );
		PrintPostOrderTraversal( root->right );
		cout << "\t�̸� : " << root->data.GetName() << endl;
	}
}
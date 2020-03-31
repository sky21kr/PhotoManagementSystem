
// ����ũ�� ����Ʈ�� ������ ���� ���ø� Ŭ����
template <typename T>
class Stack
{
public:
	// �⺻ ������
	Stack()
	{
		top = -1 ;
	}

	/**
	*	@brief	������ ����ִ��� Ȯ��
	*	@pre	����
	*	@post	����
	*	@return	��������� true, ������� ������ false ���� 
	*/
	bool IsEmpty();

	/**
	*	@brief	���� �߰�
	*	@pre	����
	*	@post	�����Ͱ� �߰���
	*	@param	newItem	�߰��� ������
	*/
	void Push(T newItem);

	/**
	*	@brief	���� ������
	*	@pre	�� �����Ͱ� �־����
	*	@post	�����Ͱ� �ϳ� ������
	*	@param	item	���⿡ �����Ͱ��� ������
	*/
	void Pop(T& item);

private:
	// ���� ���
	template<typename T>
	struct StackNode
	{
		T info;
		StackNode<T>* next;
		StackNode<T>* back;
	};
	StackNode<T>* head;
	StackNode<T>* tail;

	int top;
};

// ������ �߰�
template <typename T>
void Stack<T>::Push(T newItem)
{
	StackNode<T>* NewNode = new StackNode<T>;
	NewNode->info = newItem;

	if( top == -1 )	// ������ ���������
	{
		head = new StackNode<T>;
		tail = new StackNode<T>;
		
		head->back = NULL;
		head->next = NewNode;

		NewNode->back = head;
		NewNode->next = tail;

		tail->back = NewNode;
		tail->next = NULL;
		
		top++;

		return;
	}
	else	// ������ ������� ������
	{
		StackNode<T>* temp;
		temp = tail->back;

		temp->next = NewNode;	// ���κп� �߰���

		NewNode->back = temp;
		NewNode->next = tail;

		tail->back = NewNode;

		top++;
	}
}

// ������ ������
template <typename T>
void Stack<T>::Pop(T& item)
{
	if( IsEmpty() )	// ������ ���������
	{
		return;
	}
	else // ������ ������� ���� ��
	{
		item = tail->back->info; // ���� ���� �����͸� ����

		StackNode<T>* temp = tail->back;

		temp->back->next = tail;
		tail->back = temp->back;

		delete temp;

		top--;
	}
}

// ������ ����ִ��� Ȯ��
template<typename T>
bool Stack<T>::IsEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}
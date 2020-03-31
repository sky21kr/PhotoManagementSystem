
// 더블링크드 리스트로 구현한 스택 템플릿 클래스
template <typename T>
class Stack
{
public:
	// 기본 생성자
	Stack()
	{
		top = -1 ;
	}

	/**
	*	@brief	스택이 비어있는지 확인
	*	@pre	없음
	*	@post	없음
	*	@return	비어있으면 true, 비어있지 않으면 false 리턴 
	*/
	bool IsEmpty();

	/**
	*	@brief	스택 추가
	*	@pre	없음
	*	@post	데이터가 추가됨
	*	@param	newItem	추가할 데이터
	*/
	void Push(T newItem);

	/**
	*	@brief	스택 꺼내기
	*	@pre	들어간 데이터가 있어야함
	*	@post	데이터가 하나 꺼내짐
	*	@param	item	여기에 데이터값을 복사함
	*/
	void Pop(T& item);

private:
	// 스택 노드
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

// 데이터 추가
template <typename T>
void Stack<T>::Push(T newItem)
{
	StackNode<T>* NewNode = new StackNode<T>;
	NewNode->info = newItem;

	if( top == -1 )	// 스택이 비어있을시
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
	else	// 스택이 비어있지 않을때
	{
		StackNode<T>* temp;
		temp = tail->back;

		temp->next = NewNode;	// 끝부분에 추가함

		NewNode->back = temp;
		NewNode->next = tail;

		tail->back = NewNode;

		top++;
	}
}

// 데이터 꺼내기
template <typename T>
void Stack<T>::Pop(T& item)
{
	if( IsEmpty() )	// 스택이 비어있을시
	{
		return;
	}
	else // 스택이 비어있지 않을 때
	{
		item = tail->back->info; // 제일 끝의 데이터를 꺼냄

		StackNode<T>* temp = tail->back;

		temp->back->next = tail;
		tail->back = temp->back;

		delete temp;

		top--;
	}
}

// 스택이 비어있는지 확인
template<typename T>
bool Stack<T>::IsEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}
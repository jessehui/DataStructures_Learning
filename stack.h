//stack implementation

template <typename T>	//typename 表示可以使用多种数据类型
struct node{
	T payload;
	node* next;
	node(T payload) {this -> payload = payload;};	//构造函数
}
//现在node<T>可以用来表示payload类型为T的一个节点类型.


template <typename T>
class stack{
	node<T> *head;	//指向node<T>类型的指针



public:
	stack() : head(nullptr){};

	bool empty()
	{
		return head == nullptr;
	}

	void push(T value)	//压栈
	{
		node<T> *new_head = new node<T>(value);
		new_node->next = head;
		head = new_node;
	}

	void pop()	//出栈
	{
		if(empty())
			throw "You can't pop an element from an empty stack.";

		node<T> *temp = head;
		head = head->next;
		delete temp;
	}

	T top()	//获得最上边的payload
	{
		if(empty())
			throw "You can't get the top element from an empty stack.";

		return head->payload;
	}


}


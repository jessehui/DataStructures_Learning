template <typename T>
class queue{
	T* data;
	int head, tail, size, data_length;	//从head加, 从tail取
						//head tail起始位置是一样的

public:
	queue(int length): head(0), tail(0), size(0), data_length(length)
	{ data= new T[length]; }

	void push(T value)
	{
		if(size == data_length)
			throw "queue is full";
		data[head] = value;
		//对data_length取余仅仅是为了当head为最后一个元素的位置时,
		//在push的时候 重新从index为0开始. 不然的话 head会一直增加.
		// 这样数组就不能重复利用了
		head = (head + 1) % data_length;	
		size ++;

	}

	void pop()
	{
		if(empty())
			throw "queue is empty";
		tail = (tail + 1) % data_length;
		size --;
	}

	T top()
	{
		if(empty())
			throw "queue is empty";
		return data[tail];

	}

	bool empty()
	{
		return size == 0;
	}
}
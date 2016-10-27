//struct的构造函数要写返回类型.

struct disjoint_set{
	disjoint_set* parent;
	int rank;	//秩
	disjoint_set()
	{
		parent = this;	//默认它的parent是它自己
		rank = 0;
	}

	disjoint_set* find_root()
	{
		if(parent == this)	//this is root
			return this;
		else
			return parent->find_root();
	}

	void union_set(disjoint_set* other)
	{
		auto thisRoot = find_root();
		auto thatRoot = other->find_root();
		if(thisRoot == thatRoot)
			return;	//already in the same set

		//否则就要merge 比较秩的大小是为了避免数据结构过于不平衡
		if(thisRoot->rank < thatRoot->rank)//rank 大的是parent
			thisRoot->parent = thatRoot;

		else if(thisRoot->rank > thatRoot->rank)
			thatRoot->parent = thisRoot;

		else	//相等的话 随便选一个作为root
		{
			thatRoot->parent = thisRoot;
			thisRoot->rank = thatRoot->rank + 1;
		}



	}
};


typedef int Key;
typedef int Value;
class pair
{
public:
	pair()
	{

	}
	pair(Key k, Value v) : first(k), second(v)
	{

	}


	Key first;
	Value second;
};


class GameEngineMap
{
public:

	class MapNode
	{
	public:
		MapNode()
		{

		}

		~MapNode()
		{
			if (this != nullptr)
			{
				delete this;		
			}
			
		}
		MapNode* ParentNode = nullptr;

		MapNode* LeftNode = nullptr;

		MapNode* RightNode = nullptr;

		pair Pair;

		MapNode* GetMin()
		{
			if (LeftNode != nullptr) // 호출자의 left가 있다면
			{
				return LeftNode->GetMin(); // 호출자의 left의 GetMin() 호출
			}

			return this;
		}

		MapNode* GetNext()
		{
			if (RightNode != nullptr)
			{
				return RightNode->GetMin();
			}

			if (ParentNode != nullptr)
			{
				return GetOverParent();
			}
			
			return nullptr;
		}

		MapNode* GetOverParent()
		{
			MapNode* p = ParentNode;

			while (Pair.first > p->Pair.first)
			{
				p = ParentNode->ParentNode;

				if (p == nullptr)
				{
					return nullptr;
				}

			}
			return p;
		}
		bool insert(MapNode* _NewNode)
		{
			if (this->Pair.first > _NewNode->Pair.first)
			{
				if (this->LeftNode != nullptr)
				{
					return this->LeftNode->insert(_NewNode);
				}

				this->LeftNode = _NewNode;
				_NewNode->ParentNode = this;

				return true;

			}
			else if (this->Pair.first < _NewNode->Pair.first)
			{
				if (this->RightNode != nullptr)
				{
					return this->RightNode->insert(_NewNode);
				}

				this->RightNode = _NewNode;
				_NewNode->ParentNode = this;

				return true;
			}
			else
			{
				return false;
			}

		}


	};
	class iterator
	{
	public:
		iterator() : CurNode(nullptr)
		{

		}

		iterator(MapNode* _node) : CurNode(_node)
		{

		}

		iterator& operator++()
		{
			CurNode = CurNode->GetNext();

			return *this;

		}

		MapNode* CurNode;
	};


	iterator begin()
	{
		if (RootNode != nullptr)
		{
			iterator CurIterator = iterator(RootNode->GetMin());
			return CurIterator;
		}

		return end();

	}

	iterator end()
	{
		return iterator();
	}

	bool insert(const pair& _pair)
	{

		MapNode* NewMap = new MapNode();
		NewMap->Pair = _pair;

		if (RootNode == nullptr)
		{
			RootNode = NewMap;

			return true;
		}

		if (false == RootNode->insert(NewMap))
		{
			if (NewMap != nullptr)
			{
				delete NewMap;
				NewMap = nullptr;
			}
		}
	}

private:
	MapNode* RootNode = nullptr;
};



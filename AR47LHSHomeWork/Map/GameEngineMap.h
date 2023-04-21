

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
	Value second ;
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

		MapNode* ParentNode = nullptr;

		MapNode* LeftNode = nullptr;

		MapNode* RightNode = nullptr;

		pair Pair;


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


		MapNode* CurNode;
	};

	iterator begin()
	{
		if (RootNode != nullptr)
		{
			iterator CurIterator = iterator(RootNode);
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



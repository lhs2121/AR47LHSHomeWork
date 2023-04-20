

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

	class MapNode
	{
	public:
		MapNode()
		{

		}

		MapNode* LeftNode = nullptr;

		MapNode* RightNode = nullptr;

		pair Pair;


		bool CompareKey(MapNode* _NewNode)
		{
			if (this->Pair.first > _NewNode->Pair.first)
			{

				if (this->LeftNode != nullptr)
				{
					bool result = this->LeftNode->CompareKey(_NewNode);

					if (result)
					{
						return true;
					}
				}

				this->LeftNode = _NewNode;

				return true;

			}

			else if (this->Pair.first < _NewNode->Pair.first)
			{

				if (this->RightNode != nullptr)
				{
					bool result = this->RightNode->CompareKey(_NewNode);

					if (result)
					{
						return true;
					}
				}

				this->RightNode = _NewNode;
				return true;
			}

			else
			{
				return false;
			}

		}
	};


public:

	bool insert(pair _pair)
	{

		MapNode* NewMap = new MapNode();
		NewMap->Pair = _pair;

		if (RootNode == nullptr)
		{
			RootNode = NewMap;

			return true;
		}

		if (false == RootNode->CompareKey(NewMap))
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



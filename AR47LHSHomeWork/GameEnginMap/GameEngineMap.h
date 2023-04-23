#pragma once
#include <GameEngineBase/GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair
{
public:
	KeyType first;
	ValueType second;

public:
	GameEnginePair()
	{

	}

	GameEnginePair(const KeyType& _Key, const ValueType& _Value)
		: first(_Key), second(_Value)
	{

	}
};

// 설명 :
class GameEngineMap
{
public:

	class MapNode
	{
	public:
		MapNode* Parent = nullptr;
		MapNode* LeftChild = nullptr;
		MapNode* RightChild = nullptr;
		GameEnginePair Pair;

		~MapNode()
		{
			std::cout << Pair.first << "가 삭제되었습니다" << std::endl;
		}
		bool IsLeaf()
		{
			return nullptr == LeftChild && nullptr == RightChild;
		}

		void ChangeChild(MapNode* _OldChild, MapNode* _NewChild)
		{
			if (_OldChild == LeftChild)
			{
				LeftChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

			if (_OldChild == RightChild)
			{
				RightChild = _NewChild;
				if (nullptr != _NewChild)
				{
					_NewChild->Parent = this;
				}
				return;
			}

		}

		MapNode* OverParentNode()
		{
			MapNode* ParentNode = Parent;

			while (Pair.first > ParentNode->Pair.first)
			{
				ParentNode = ParentNode->Parent;

				if (nullptr == ParentNode)
				{
					return nullptr;
				}
			}

			return ParentNode;
		}

		MapNode* PrevNode()
		{
			return nullptr;
		}

		MapNode* NextNode()
		{
			if (nullptr != RightChild)
			{
				return RightChild->MinNode();
			}

			if (nullptr != Parent)
			{
				return OverParentNode();
			}

			return nullptr;
		}

		MapNode* MaxNode()
		{
			if (nullptr == RightChild)
			{
				return this;
			}

			return RightChild->MaxNode();
		}

		MapNode* MinNode()
		{
			if (nullptr == LeftChild)
			{
				return this;
			}

			return LeftChild->MinNode();
		}

		bool insert(MapNode* _NewNode)
		{
			if (Pair.first > _NewNode->Pair.first)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->insert(_NewNode);
				}

				LeftChild = _NewNode;
				_NewNode->Parent = this;
				return true;
			}
			else if (Pair.first < _NewNode->Pair.first)
			{
				if (nullptr != RightChild)
				{
					return RightChild->insert(_NewNode);
				}

				RightChild = _NewNode;
				_NewNode->Parent = this;
				return true;
			}

			return false;
		}

		MapNode* find(KeyType _Key)
		{
			if (Pair.first > _Key)
			{
				if (nullptr != LeftChild)
				{
					return LeftChild->find(_Key);
				}

				return nullptr;
			}
			else if (Pair.first < _Key)
			{
				if (nullptr != RightChild)
				{
					return RightChild->find(_Key);
				}

				return nullptr;
			}

			return this;
		}

		void FirstOrder()
		{
			std::cout << Pair.first << std::endl;
			if (nullptr != LeftChild)
			{
				LeftChild->FirstOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->FirstOrder();
			}
		}

		void MidOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->MidOrder();
			}
			std::cout << Pair.first << std::endl;
			if (nullptr != RightChild)
			{
				RightChild->MidOrder();
			}

		}

		void LastOrder()
		{
			if (nullptr != LeftChild)
			{
				LeftChild->LastOrder();
			}
			if (nullptr != RightChild)
			{
				RightChild->LastOrder();
			}

			std::cout << Pair.first << std::endl;

		}

		void DeleteOrder()
		{

			if (nullptr != LeftChild)
			{
				LeftChild->DeleteOrder();
			}

			if (LeftChild != nullptr)
			{
				delete LeftChild;
				LeftChild = nullptr;
			}

			if (nullptr != RightChild)
			{
				RightChild->DeleteOrder();
			}

			if (RightChild != nullptr)
			{
				delete RightChild;
				RightChild = nullptr;
			}
		}
	};

	class iterator
	{
		friend GameEngineMap;

	public:
		iterator()
			: Node(nullptr)
		{

		}


		iterator(class MapNode* _Node)
			: Node(_Node)
		{

		}

		GameEnginePair* operator->()
		{
			return &Node->Pair;
		}


		bool operator!=(const iterator& _Other) const
		{
			return Node != _Other.Node;
		}

		bool operator==(const iterator& _Other) const
		{
			return Node == _Other.Node;
		}

		iterator& operator++()
		{
			Node = Node->NextNode();

			return *this;
		}

		iterator& operator--()
		{
			Node = Node->PrevNode();

			return *this;
		}



	private:
		// 전방선언
		class MapNode* Node = nullptr;
	};



	iterator begin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->MinNode());
	}

	iterator end()
	{
		return iterator();
	}

	iterator find(KeyType _Key)
	{
		if (nullptr == Root)
		{
			return end();
		}

		MapNode* FindNode = Root->find(_Key);

		return iterator(FindNode);
	}

	iterator erase(const iterator& _EraseIter)
	{
		if (_EraseIter == end())
		{
			MsgBoxAssert("앤드를 삭제하려고 했습니다.");
		}

		MapNode* CurNode = _EraseIter.Node;
		MapNode* ParentNode = CurNode->Parent;
		MapNode* RightChild = CurNode->RightChild;
		MapNode* LeftChild = CurNode->LeftChild;

		MapNode* ChangeNode = nullptr;
		MapNode* ChangeNodeParent = nullptr;
		MapNode* NextNode = CurNode->NextNode();

		if (true == CurNode->IsLeaf())
		{
			ParentNode->ChangeChild(CurNode, nullptr);
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = nullptr;
			}
			return NextNode;
		}


		// 교체될 노드는 절대로 양쪽을 모두 가진 노드일수 없다.
		MapNode* ChangeChild = nullptr;
		MapNode* ChangeParent = nullptr;

		if (nullptr != LeftChild)
		{
			ChangeNode = LeftChild->MaxNode();
			ChangeChild = ChangeNode->LeftChild;
			ChangeParent = ChangeNode->Parent;
		}
		else if (nullptr != RightChild)
		{
			ChangeNode = RightChild->MinNode();
			ChangeChild = ChangeNode->RightChild;
			ChangeParent = ChangeNode->Parent;
		}

		if (nullptr == ChangeNode)
		{
			MsgBoxAssert("말도안돼");
			return nullptr;
		}

		// 루트노드일 경우를 대비해서
		// 체인지 노드의 뒷정리를 하는 기간
		if (nullptr != ChangeParent)
		{
			ChangeParent->ChangeChild(ChangeNode, ChangeChild);
		}


		// 교체할 노드와 지워질 노드의 정보 교체를 한다.

		if (nullptr != ParentNode)
		{
			ParentNode->ChangeChild(CurNode, ChangeNode);
		}
		else
		{
			ChangeNode->Parent = nullptr;
			Root = ChangeNode;
			// RootNode 
		}


		ChangeNode->LeftChild = LeftChild;
		if (nullptr != LeftChild)
		{
			LeftChild->Parent = ChangeNode;
		}
		ChangeNode->RightChild = RightChild;
		if (nullptr != RightChild)
		{
			RightChild->Parent = ChangeNode;
		}

		if (nullptr != CurNode)
		{
			delete CurNode;
			CurNode = nullptr;
		}

		return NextNode;
	}

	// ????
	iterator rbegin()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->MinNode());
	}
	// ???
	iterator rend()
	{
		if (nullptr == Root)
		{
			return end();
		}

		return iterator(Root->MinNode());
	}


	// 안들어가면 false리턴
	bool insert(const GameEnginePair& _Pair)
	{
		if (nullptr == Root)
		{
			Root = new MapNode();
			Root->Pair = _Pair;
			return true;
		}

		MapNode* NewNode = new MapNode();
		NewNode->Pair = _Pair;

		if (false == Root->insert(NewNode))
		{
			delete NewNode;
			NewNode = nullptr;
		}

		return true;
	}

	void FirstOrder()
	{
		Root->FirstOrder();
	}

	void MidOrder()
	{
		Root->MidOrder();
	}

	void LastOrder()
	{
		Root->LastOrder();
	}

	void DeleteOrder()
	{
		Root->DeleteOrder();

		if (Root != nullptr)
		{
			delete Root;
			Root = nullptr;
		}
	}

private:
	MapNode* Root = nullptr;
};


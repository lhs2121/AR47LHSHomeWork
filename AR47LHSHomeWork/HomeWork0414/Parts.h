#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <iostream>

// Ό³Έν :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	static Parts* firstParts;

protected:
	void Update() override;
	void SetNextParts(Parts* _parts)
	{
		if (Next != nullptr)
		{
			Next->SetNextParts(_parts);
		}
		else
		{
			Next = _parts;
			_parts->Prev = this;

		}
	}
	Parts* GetNextParts()
	{
		return Next;
	}
	Parts* GetPrevParts()
	{
		return Prev;
	}
	

private:
	Parts* Next = nullptr;
	Parts* Prev = nullptr;
	
	
};


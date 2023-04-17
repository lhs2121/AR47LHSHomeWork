#pragma once
#include "ConsoleGameMath.h"

// Screen에서 움직이는 오브젝트들의 기본기능을 제공한다.
class ConsoleGameObject
{
public:
	inline void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}
	inline void SetPrevPos(const int2& _Value)
	{
		PrevPos = _Value;
	}
	inline int2 GetPrevPos() const
	{
		return PrevPos;
	}
	inline int2 GetPos() const
	{
		return Pos;
	}

	bool IsDeath()
	{
		return DeathValue;
	}

	void Death()
	{
		DeathValue = true;
	}
	bool IsUpdate()
	{
		return UpdateValue;
	}

	void On()
	{
		UpdateValue = true;
	}

	void Off()
	{
		UpdateValue = false;
	}
	
	void SetOnHead()
	{
		OnHead = true;
	}
	bool GetOnHead()
	{
		return OnHead;
	}

	bool GetIsMove()
	{
		return isMove;
	}

	virtual void Update();
	virtual void Render();

protected:
	int2 Pos;
	char RenderChar = ' ';

	int2 PrevPos;
	bool OnHead = false;
	bool isMove = false;
private:
	bool UpdateValue = true;
	bool DeathValue = false;
	

};


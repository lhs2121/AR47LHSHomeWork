#include "Parts.h"

Parts::Parts()
{
}

Parts::~Parts()
{
}

void Parts::Update()
{
	ConsoleGameObject::Update();

}

void Parts::ChangeRenderChar()
{
	if (Next != nullptr)
	{
		int2 NextPos = Next->GetPos();
		int2 Dir = Pos - NextPos;
		if (Dir == int2::Left)
		{
			Next->RenderChar = L'��';
		}
		else if (Dir == int2::Right)
		{
			Next->RenderChar = L'��';
		}
		else if (Dir == int2::Up)
		{
			Next->RenderChar = L'��';
		}
		else if (Dir == int2::Down)
		{
			Next->RenderChar = L'��';
		}
	}
}

void Parts::NextMove()
{
	Parts* Next = GetNext();

	if (nullptr == Next)
	{
		return;
	}

	Next->SetPos(GetPrevPos());

	ChangeRenderChar();

	return Next->NextMove();
}


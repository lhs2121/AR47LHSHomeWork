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

	ChangeRenderChar();
}

void Parts::ChangeRenderChar()
{
	if (GetPrevPos() == (GetPos() - int2::Left))
	{
		RenderChar = L'¢·';
	}
	else if (GetPrevPos() == (GetPos() - int2::Right))
	{
		RenderChar = L'¢¹';
	}
	else if (GetPrevPos() == (GetPos() - int2::Up))
	{
		RenderChar = L'¡â';
	}
	else if (GetPrevPos() == (GetPos() - int2::Down))
	{
		RenderChar = L'¡ä';
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
	return Next->NextMove();
}


#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

HRESULT GameObject::init()
{
	return S_OK;
}

void GameObject::update()
{
}

RECT* GameObject::getRect(string name)
{
	return &RECT();
}

void GameObject::render()
{
}







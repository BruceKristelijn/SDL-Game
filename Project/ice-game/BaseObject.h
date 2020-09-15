#pragma once
class BaseObject
{
public:
	virtual void Update() = 0;
	virtual void Start() = 0;
private:
	int id;
};
#pragma once

class NonLeakable;

class NonLeakablePtr
{
public:
	NonLeakablePtr();
	NonLeakablePtr(NonLeakablePtr& ptr);
	~NonLeakablePtr();

	void MakeNewObject();
	void Print() const;
	NonLeakable* operator->() const;
	NonLeakablePtr& operator=(NonLeakablePtr& ptr);
	NonLeakable& operator*();

private:
	NonLeakablePtr(const NonLeakablePtr& ptr);
	NonLeakable * m_object;

};


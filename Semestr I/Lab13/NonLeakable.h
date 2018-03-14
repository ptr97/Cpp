#pragma once

class NonLeakablePtr;

class NonLeakable
{
public:
	friend class NonLeakablePtr;
	NonLeakable();
	void Print() const;
	int myID() const;
	~NonLeakable();
private:
	void * operator new(long unsigned int);
	static int m_id;
	int m_myid;
};


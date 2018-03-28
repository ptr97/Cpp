#ifndef __DATABASE_H__
#define __DATABASE_H__


class DataBase
{
public:
	virtual void print() const = 0;
	virtual bool equal(const DataBase * data) const = 0;
	virtual DataBase * copy() const = 0;
	virtual ~DataBase() {}
};

#endif

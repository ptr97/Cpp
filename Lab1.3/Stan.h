#pragma once


class Stan
{
public:
	Stan(const char * name);
	void Print() const;
	~Stan();

private:
	char * m_name;

};

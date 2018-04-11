#pragma once
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstring>

class numerical_exception : public std::runtime_error
{
public:
	numerical_exception(const char * error, const char * file = NULL, const int line = 0) : std::runtime_error(error), m_line(line) 
	{
		if(file)
			m_file = file;
		else
			m_file = "nothing";
	}
	virtual std::string File() const {return m_file;}
	virtual int Line() const {return m_line;}
private:
	std::string m_file;
	int m_line;
};


class calculation_exception : public numerical_exception
{
public:
	calculation_exception(const char * error, const char * file = NULL, const int line = 0) : numerical_exception(error, file, line) {}
};


class myexcept
{
public:
	static void handler(const char * handledError)
	{
		try
		{
			throw;
		}
		catch(const calculation_exception & err)
		{
			std::cout << "plik: " << err.File() << " linia: " << err.Line() << " kontekst: (";
			std::cout << handledError << ") calculation_exception " << err.what() << std::endl;
		}
		catch(const numerical_exception & err)
		{
			std::cout << "plik: " << err.File() << " linia: " << err.Line() << " kontekst: (";
			std::cout << handledError << ") numerical_exception " << err.what() << std::endl;
		}
		catch(const std::runtime_error & err)
		{
			std::cout << "kontekst: (" << handledError << ") runtime_error " << err.what() << std::endl;
		}
	}
};

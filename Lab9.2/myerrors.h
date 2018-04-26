#pragma once
#include <stdexcept>

namespace myerrors
{

	class calc_error : public std::runtime_error
	{
	public:
		calc_error(const std::runtime_error * err, const char * errName, const char * fileName, const int line) : 
					std::runtime_error(errName), m_err(err), m_fileName(fileName), m_line(line) {}
		virtual ~calc_error() override {delete m_err;}

		virtual const char * what() const noexcept override
		{
			std::cout << std::runtime_error::what() << " [w pliku: " << m_fileName << " w lini: " << m_line << "]"<< std::endl;
			std::cout << "z powodu : ";
			return m_err->what();
		}

	private:
		const std::runtime_error * m_err;
		const std::string m_fileName;
		const int m_line;
	};

	void handler()
	{
		try
		{
			throw;
		}
		catch(const calc_error * error)
		{
			std::cout << "Wyjatek w: ";
			std::cout << error->what();
			std::cout << std::endl;
			delete error;
		}
		catch(const std::runtime_error * error)
		{
			std::cout << error->what() << std::endl;
			delete error;
		}
	}

}

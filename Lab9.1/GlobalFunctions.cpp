#include "GlobalFunctions.h"


void Fold1(MyClass myClass, const int level)
{
	std::set_terminate(MyTerminate);

	std::cout << "Entering fold level " << level << std::endl;
	std::string newName = "F" + std::to_string(level);
	myClass.SetName(newName.c_str());
	Fold2(myClass, level + 1);
}

void Fold2(MyClass myClass, const int level)
{
	std::cout << "Entering fold level " << level << std::endl;
	std::string newName = "F" + std::to_string(level);
	myClass.SetName(newName.c_str());
	Fold3(myClass, level + 1);
}

void Fold3(MyClass myClass, const int level)
{
	std::cout << "Entering fold level " << level << std::endl;
	std::string newName = "F" + std::to_string(level);
	myClass.SetName(newName.c_str());

	try
	{
		switch(ReturnValueID)
		{
			case 0:
			{
				throw 9.242f;
				break;
			}
			case 1:
			{
				throw -87;
				break;
			}
			case 2:
			{
				throw 16u;
				break;
			}
			case 3:
			{
				throw 3.14157;
			}
			default:
			{
				std::cout << "default" << std::endl;
				throw MyException();
				break;
			}
		}
	}
	catch (double fLiczba)
	{
		std::cout << "Caught an exception of type: float" << std::endl;
		throw MyException();
	}
	catch (int nLiczba)
	{
		std::cout << "Caught an exception of type: int" << std::endl;
		throw MyException();
	}
	catch (unsigned uLiczba)
	{
		std::cout << "Caught an exception of type: unsigned" << std::endl;
		throw MyException();
	}
	catch (float fLiczba)
	{
		std::cout << "Caught an exception of type: double" << std::endl;
		throw MyException();
	}
}

void MyTerminate()
{
	std::cout << "--- UWAGA: blad mechanizmu wyjatkow ---" << std::endl;
	exit(0);
}


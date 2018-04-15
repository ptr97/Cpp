#pragma once
#include "Exception.h"


class ObiektMiotajacy
{
public:
	void Rzuc()
	{
		try
		{
			delete this;
			throw new typ2();
		}
		catch(typ2 & exc)
		{
			throw &exc;
		}
		catch(typ1 &exc)
		{
			throw &exc;
		}
	}
};

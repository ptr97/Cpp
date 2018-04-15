#pragma once


void Przetworz1(Exception * exc)
{
	std::cout << "Przetworz1 - wyjatek typu " << exc->Numer() << " o adresie " << exc << std::endl;

	try
	{
		if(typ2 * excCast = dynamic_cast<typ2 *>(exc))
		{
			throw excCast;
		}

		if(typ1 * excCast = dynamic_cast<typ1 *>(exc))
		{
			throw excCast;
		}
	}
	catch(typ4 & exc)
	{
		throw &exc;
	}
	catch(typ3 & exc)
	{
		throw &exc;
	}
}

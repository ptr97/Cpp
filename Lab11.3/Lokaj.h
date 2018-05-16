#pragma once


template <void (Pomieszczenie::*fun)(void) const>
void Lokaj(Pomieszczenie & pomieszczenie)
{
	(pomieszczenie.*fun)();
}

template <void (Pomieszczenie::*fun)(void) const>
void Lokaj(const Pomieszczenie & pomieszczenie)
{
	std::cout << "Pomieszczenie " << pomieszczenie.GetName() << " jest zamkniete." << std::endl;
}

template <int N>
void Lokaj(const Pomieszczenie &)
{
	std::cout << "Nic nie robie." << std::endl;
}

#pragma once


/** 
 * abstrakcyjna klasa bazowa ktora udostepnia interfejs do obslugi transakcji bankowych
 */
class DoUndoAction
{
public:
	/**
	 * czysto wirtualna metoda dodo wykonuje sie przy rozpoczeciu transakcji bankowej
	 */
	virtual void dodo() = 0;

	/**
	 *  czysto wirtualna metoda dodo wykonuje sie jesli wszystko w transakcji przebiegnie
	 *  bez problemow
	 */
	virtual void undoOk() = 0;
	
	/**
	 *  czysto wirtualna metoda dodo wykonuje sie jesli w transakcji wystapi blad
	 */
	virtual void undoFail() = 0;
	/**
	 *  wirtualny destruktor - poniewaz dziedziczymy po tej klasie
	 */
	virtual ~DoUndoAction() {}
};



/**
 *  klasa ktora ma za zadanie przechowywac stan konta 
 *  przechowuje ona referencje do stanu konta aby, w razie zmian - transakcji
 *  stan konta zostal zmieniony
 */
class KeepInt : public DoUndoAction
{
public:
	/**
	 *  konstruktor - zapisuje referencje do stanu konta i poczatkowa jego wartosc
	 *  jesli transakcja nie powiedzie sie to stan konta jest przywracany 
	 *  do stanu z przed transakcji
	 */
	KeepInt(int & value) : m_value(value), m_startValue(value) {}
	
	/** 
	 * implementacja metod wywolywanych podczas trwania transakcji
	 */
	virtual void dodo() {}
	virtual void undoOk() {}

	/**
	 *  metoda ta przywraca stan konta z przed transakcji jesli transakcja 
	 *  sie nie powiedzie
	 */
	virtual void undoFail() { m_value = m_startValue; }
	/**
	 *  destruktor - nie robi nic, poniewaz zadna ze skladowych 
	 *  nie jest przechowywana na stosie 
	 */
	virtual ~KeepInt() {}

private:
	/**
	 *  referencja do wartosci jaka jest na koncie 
	 */
	int & m_value;
	/**
	 *  poczatkowa warosc jaka byla na koncie przed transakcja
	 */
	int m_startValue;
};



/** 
 *  klasa sluzaca do przeprowadzania transakcji bankowych 
 *  obslufuje syuacje w ktorych nastapi blad transakcji
 */
class DoUndo
{
public:
	/** 
	 *  konstruktor - przechowuje wskaznik do danej akcji, wywoluje metode
	 *  dodo() ktora mowi o tym ze transakcja zostala rozpoczeta
	 *  system zaklada ze kazda transakcja jest niepoprawna, 
	 *  poniewaz podczas jej trwania moze zostac wyrzucony wyjatek
	 */
	DoUndo(DoUndoAction * action) : m_action(action)
	{
		m_action->dodo();
		DoUndo::m_ifOk = false;
	}

	/** 
	 *  statyczna metoda, ktora powinna byc umieszczana na koncu 
	 *  kazdego bloku z transakcja - jesli nie zostanie wyrzucony zaden wyjatek,
	 *  to jest ustawiana flaga mowiaca ze transakcja powiodla sie 
	 */
	static void allok() 
	{
		DoUndo::m_ifOk = true;
	}

	/**
	 *	destruktor klasy DoUndo, w zaleznosci od wartosci flagi statycznej m_ifOk
	 *  wywoluje na dana metode na rzecz przechowywanego obiektu
	 */
	~DoUndo()
	{
		DoUndo::m_ifOk ? m_action->undoOk() : m_action->undoFail();
		delete m_action;
	}

private:
	/** 
	 *  wskaznik do danej akcji zwiazanej z transakcjami bakowymi,
	 *  np obslugujacej przelewy lub wypisujacej na ekran czy transakcja 
	 *  przebiegla poprawnie itd.
	 */
	DoUndoAction * m_action;
	
	/**
	 *  statyczna flaga informujaca o statusie przeprowadzanej transakcji
	 */
	static bool m_ifOk;
};

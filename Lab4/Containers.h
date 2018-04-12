#pragma once
#include <iostream>
#include <string>


namespace oop
{

	class Object
	{
	public:
		Object() {}
		virtual std::string name() const;
		virtual ~Object() {std::cout << "oop::~Object" << std::endl;}
	};

	std::string Object::name() const {return "oop::Object";}

	//klasa czysto wirtualna dziedziczy po klasie Object - wynika to z kolejnosci wywolywania sie destrukotorw
	class Container : public Object
	{
	public:
		std::string name() const {return "oop::Container";}
		virtual void size() const = 0;
		virtual void empty() const = 0;
		virtual void insert(Container * c) = 0;
		virtual ~Container() {std::cout << "oop::~Container" << std::endl;}
	};

	//klasa czysto wirtualna dziedziczy po klasie Container - wynika to z kolejnosci desktrukotorow i nazwy
	class SequenceContainer : public Container
	{
	public:
		std::string name() const {return "oop::SequenceContainer";}
		virtual void push_front(Object * o) = 0;
		virtual void push_back(Object * o) = 0;
		virtual ~SequenceContainer() {std::cout << "oop::~SequenceContainer" << std::endl;}
	};

	//klasa czysto wirtualna - dziedziczy po Container - z kolejnosci destruktorwo i po nazwie
	class SortedTreeContainer : public Container
	{
	public:
		
		std::string name() const  = 0;
		virtual ~SortedTreeContainer() {std::cout << "oop::~SortedTreeContainer" << std::endl;}
	};

	std::string SortedTreeContainer::name() const {return "oop::SortedTreeContainer";}

	//klasa czysto wirtualna - dziedziczenie wynika z nazwy
	class HashTreeContainer : public Container
	{
	public:
		std::string name() const = 0;
		virtual ~HashTreeContainer() {std::cout << "oop::~HashTreeContainer" << std::endl;}
	};

	std::string HashTreeContainer::name() const {return "oop::HashTreeContainer";}

	//klasa dziedziczy po klasie SequenceContainer poniewaz wynika to z nazwy, kolejnosci wywolania destruktorow
	//oraz z tego ze obiekt tej klasy przypisujemy do wskaznika typu Object, a po nim dziedziczy Container
	//natomiast po nim SequenceContainer  
	class List : public SequenceContainer
	{
	public:
		void size() const {}
		void empty() const {}
		void insert(Container * c) {}
		void push_front(Object * o) {}
		void push_back(Object * o) {}

		std::string name() const {return "oop::List";}
		virtual ~List() {std::cout << "oop::~List" << std::endl;}
	};
	//klasa dziedziczy tak jak List z takich samych powodow
	class Vector : public SequenceContainer
	{
	public:
		void size() const {}
		void empty() const {}
		void insert(Container * c) {}
		void push_front(Object * o) {}
		void push_back(Object * o) {}
		std::string name() const {return "oop::Vector";}
		virtual ~Vector() {std::cout << "oop::~Vector" << std::endl;}
	};

	//dziedziczenie wynika z lini 89
	class SortedTree : public SortedTreeContainer
	{
	public:
		void size() const {}
		void empty() const {}
		void insert(Container * c) {}
		void push_front(Object * o) {}
		void push_back(Object * o) {}
		std::string name() const {return "oop::SortedTree";}
		virtual ~SortedTree() {std::cout << "oop::~SortedTree" << std::endl;}
	};

	//dziedziczenie wynika z linii 93
	class HashTree : public HashTreeContainer
	{
	public:
		void size() const {}
		void empty() const {}
		void insert(Container * c) {}
		void push_front(Object * o) {}
		void push_back(Object * o) {}
		std::string name() const {return "oop::HashTree";}
		virtual ~HashTree() {std::cout << "oop::~HashTree" << std::endl;}
	};

	//dziedziczenie wynika z lini 52
	class SortedMultiTree : public SortedTreeContainer
	{
	public:
		void size() const {}
		void empty() const {}
		void insert(Container * c) {}
		void push_front(Object * o) {}
		void push_back(Object * o) {}
		std::string name() const {return "oop::SortedMultiTree";}
		virtual ~SortedMultiTree() {std::cout << "oop::~SortedMultiTree" << std::endl;}
	};

	//dziedziczenie wynika z linii 61
	class HashMultiTree : public HashTreeContainer
	{
	public:
		void size() const {}
		void empty() const {}
		void insert(Container * c) {}
		void push_front(Object * o) {}
		void push_back(Object * o) {}
		std::string name() const {return "oop::HashMultiTree";}
		virtual ~HashMultiTree() {std::cout << "oop::~HashMultiTree" << std::endl;}
	};

	//klasa czysto wirtualna - nie mozna jej utowrzyc - wynika to z nazwy oraz linii 71 ktora ma spowodowac error
	class TreeContainer : public Container
	{
	public:
		std::string name() const {return "oop::TreeContainer";}
		virtual ~TreeContainer() {std::cout << "oop::~TreeContainer" << std::endl;}
	};


}


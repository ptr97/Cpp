#include "Stats.h"


Stats Stats::scanForWords(const std::string & fileName)
{
	std::map<std::string, int> counter;

	std::ifstream fileStream(fileName);
	std::string word;

	while(fileStream.good())
	{
		fileStream >> word;

		if(counter.count(word) == 0)
		{
			counter.emplace(word, 1);
		}
		else
		{
			counter[word] += 1;;
		}
	}

	return Stats(counter);
}

Stats Stats::scanForChars(const std::string & fileName)
{
	std::map<std::string, int> counter;

	std::ifstream fileStream(fileName);
	char c;

	while(fileStream.good())
	{
		fileStream >> c;
		std::string character(1, c);

		if(counter.count(character) == 0)
		{
			counter.emplace(character, 1);
		}
		else
		{
			counter[character] += 1;
		}
	}

	return Stats(counter);
}

std::ostream & operator<<(std::ostream & os, const Stats & stats)
{
	os << stats.m_counter.size();

	return os;
}

std::ostream & operator<<(std::ostream & os, const std::map<std::string, int> & map)
{
	for(std::map<std::string, int>::const_iterator iter = map.begin(); iter != map.end(); ++iter)
	{
		os << iter->first << " " << iter->second << std::endl;
	}

	return os;
}

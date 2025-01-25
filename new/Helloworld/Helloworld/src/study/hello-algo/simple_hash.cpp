#include "basic.h"

// ¼Ó·¨¹þÏ£
int addHash(std::string key)
{
	long long hash = 0;
	const int MODULES = 1000000007;
	for (unsigned char c : key)
		hash = (hash + (int)c) % MODULES;
	return (int)hash;
}

// ³Ë·¨¹þÏ£
int mulHash(std::string key)
{
	long long hash = 0;
	const int MODULES = 1000000007;
	for (unsigned char c : key)
		hash = (31 * hash + (int)c) % MODULES;
	return (int)hash;
}

// Òì»ò¹þÏ£
int xorHash(std::string key)
{
	long long hash = 0;
	const int MODULES = 1000000007;
	for (unsigned char c : key)
		hash ^= (int)c;
	return hash & MODULES;
}

// Ðý×ª¹þÏ£
int rotHash(std::string key)
{
	long long hash = 0;
	const int MODULES = 1000000007;
	for (unsigned char c : key)
		hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULES;
	return (int)hash;
}
#pragma once

#include <string>
#include <vector>

class ConductorImpl
{
public:

	virtual std::vector<std::string> getCatalogNames(const char* catalogSignature, size_t size = 100, size_t startPosition = 0);
	virtual std::vector<std::string> getFileNames(const char* fileTypes, size_t size = 100, size_t startPosition = 0);
	virtual size_t getCountOfCatalogs(char* catalogSignature);
	virtual size_t getCountOfFiles(char* fileSignature);
};
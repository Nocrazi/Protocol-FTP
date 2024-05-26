#pragma once

#include "conductorImpl.h"
#include <memory>

class Conductor
{
public:

	static std::shared_ptr<Conductor> getInstance();
	std::vector<std::string> getCatalogNames(const char* catalogSignature, size_t size = 100, size_t startPosition = 0);
	std::vector<std::string> getFileNames(const char* fileTypes, size_t size = 100, size_t startPosition = 0);
	size_t getCountOfCatalogs(char* catalogSignature);
	size_t getCountOfFiles(char* fileSignature);

private:

	Conductor();
	std::shared_ptr<ConductorImpl> impl;
};
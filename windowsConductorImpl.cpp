
#include "windowsConductorImpl.h"

#include "Windows.h"

using namespace std;

//WindowsConductorImpl
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<string> WindowsConductorImpl::getCatalogNames(const char* catalogSignature, size_t size, size_t startPosition)
{
	vector<string> names;
	const char* path = catalogSignature;

	WIN32_FIND_DATAA fileInfo;
	HANDLE firstFile = FindFirstFileA(path, &fileInfo);
	if (firstFile == INVALID_HANDLE_VALUE)
		return names;

	if ((strcmp(fileInfo.cFileName, ".") == 0))
		if (FindNextFileA(firstFile, &fileInfo) == false)
			return names;

	if ((strcmp(fileInfo.cFileName, "..") == 0))
		if (FindNextFileA(firstFile, &fileInfo) == false)
			return names;

	for(size_t i = 0; i < startPosition; ++i)
		if (FindNextFileA(firstFile, &fileInfo) == false)
			return names;

	if (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY & ~FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
		if (names.size() < size)
			names.push_back(fileInfo.cFileName);

	while (FindNextFileA(firstFile, &fileInfo))
	{
		if (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY & ~FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
		{
			names.push_back(fileInfo.cFileName);
			if (names.size() == size)
				break;
		}
	}

	FindClose(firstFile);
	return names;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<string> WindowsConductorImpl::getFileNames(const char* fileSignature, size_t size, size_t startPosition)
{
	vector<string> names;
	const char* path = fileSignature;

	WIN32_FIND_DATAA fileInfo;
	HANDLE firstFile = FindFirstFileA(path, &fileInfo);
	if (firstFile == INVALID_HANDLE_VALUE)
		return names;

	if ((strcmp(fileInfo.cFileName, ".") == 0))
		if (FindNextFileA(firstFile, &fileInfo) == false)
			return names;
	
	if ((strcmp(fileInfo.cFileName, "..") == 0))
		if (FindNextFileA(firstFile, &fileInfo) == false)
			return names;
	
	for (size_t i = 0; i < startPosition; ++i)
		if (FindNextFileA(firstFile, &fileInfo) == false)
			return names;
	
	if (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE & ~FILE_ATTRIBUTE_HIDDEN)
		if (names.size() < size)
		{
			names.push_back(fileInfo.cFileName);
		}
	
	while (FindNextFileA(firstFile, &fileInfo))
	{
		if (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE & ~FILE_ATTRIBUTE_HIDDEN)
		{
			names.push_back(fileInfo.cFileName);
			if (names.size() == size)
				return names;
		}
	}
	
	FindClose(firstFile);
	return names;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
size_t WindowsConductorImpl::getCountOfCatalogs(char* catalogSignature)
{
	const char* path = catalogSignature;
	size_t count = 0;

	WIN32_FIND_DATAA fileInfo;
	HANDLE firstFile = FindFirstFileA(path, &fileInfo);
	if (firstFile == INVALID_HANDLE_VALUE)
		return count;

	if ((strcmp(fileInfo.cFileName, ".") != 0) and (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		++count;

	if (FindNextFileA(firstFile, &fileInfo))
		if ((strcmp(fileInfo.cFileName, "..") != 0) and (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			++count;

	while (FindNextFileA(firstFile, &fileInfo))
		if (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			++count;

	return count;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
size_t WindowsConductorImpl::getCountOfFiles(char* fileSignature)
{
	const char* path = fileSignature;
	size_t count = 0;

	WIN32_FIND_DATAA fileInfo;
	HANDLE firstFile = FindFirstFileA(path, &fileInfo);
	if (firstFile == INVALID_HANDLE_VALUE)
		return count;

	while (FindNextFileA(firstFile, &fileInfo))
		if (fileInfo.dwFileAttributes & FILE_ATTRIBUTE_NORMAL & ~FILE_ATTRIBUTE_SYSTEM)
			++count;

	return count;
}

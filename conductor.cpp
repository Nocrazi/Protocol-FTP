
#include "conductor.h"
#include "windowsConductorImpl.h"

using namespace std;

//Conductor
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Conductor::Conductor()
{
	impl = shared_ptr<ConductorImpl>(new WindowsConductorImpl);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
std::shared_ptr<Conductor> Conductor::getInstance()
{
	static shared_ptr<Conductor> conductor = shared_ptr<Conductor>(new Conductor);
	return conductor;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<string> Conductor::getCatalogNames(const char* catalogSignature, size_t size, size_t startPosition)
{
	return impl->getCatalogNames(catalogSignature, size, startPosition);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
vector<string> Conductor::getFileNames(const char* fileSignature, size_t size, size_t startPosition)
{
	return impl->getFileNames(fileSignature, size, startPosition);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
size_t Conductor::getCountOfCatalogs(char* catalogSignature)
{
	return impl->getCountOfCatalogs(catalogSignature);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
size_t Conductor::getCountOfFiles(char* fileSignature)
{
	return impl->getCountOfFiles(fileSignature);
}

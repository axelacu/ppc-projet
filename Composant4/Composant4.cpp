#include "Composant4.h"
#include "Bloc.h"
#include <iostream>
#include <dlfcn.h>

std::string hashBloc(Bloc bloc){
	
	std::string hash = std::string(64,'0');
	return hash;
}

bool verifHash(Bloc bloc, std::string hashCode){
	return true;
}

std::string version(){
	return "1.0";
}

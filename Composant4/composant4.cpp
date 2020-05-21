#include "Composant4.h"
#include "Bloc.h"
#include <iostream>
#include <dlfcn.h>

std::string hashBloc(Bloc bloc){
	return(std::hash(bloc.toString()))
}

bool verifHash(Bloc bloc, std::string hashCode){
	return true;
}

std::string version(){
	return 1;
}

#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include "Bloc.h"
#include "Composant4.h"
#include "Composant3.h"

int main(int argc, char ** argv)
{	

    std::cout<<"Hello World"<<std::endl;
    //Bloc bloc;
    Bloc bloc;

    composant3(bloc);
    std::cout<<"Composant3"<<std::endl;
    std::cout << bloc.getNonce() << '\n';
    std::cout << bloc.getHash();

}
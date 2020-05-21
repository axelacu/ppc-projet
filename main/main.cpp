
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include "Bloc.cpp"
#include "Composant4.cpp"
#include "Composant3.cpp"

int main(int argc, char ** argv)
{	

    std::cout<<"Hello World"<<std::endl;
    //Bloc bloc;
    Bloc bloc;

    composant3(bloc);
    std::cout << bloc.getNonce() << '\n';
    std::cout << bloc.getHash();

}
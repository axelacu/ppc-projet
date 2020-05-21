
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include "../Bloc/Bloc.cpp"
#include "../Composant4/Composant4.cpp"
#include "../Composant3/Composant3.cpp"

int main(int argc, char ** argv)
{	

    std::cout<<"Hello World"<<std::endl;
    //Bloc bloc;
    Bloc bloc;
    std::cout<<"bonjour"<<std::endl;
    composant3(bloc);
    std::cout<<"bonsoir"<<std::endl;
    std::cout << bloc.getNonce() << '\n';    
    std::cout<<"bonsoir1"<<std::endl;
    std::cout << bloc.getHash();    
    std::cout<<"bonsoir2"<<std::endl;

}
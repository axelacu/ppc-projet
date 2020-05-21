
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include "Bloc.h"
#include "Composant4.h"
#include "Composant3.h"

int main(int argc, char ** argv)
{
    Bloc bloc;

    composant3(bloc);
    std::cout << bloc.getNonce() << '\n';
    std::cout << bloc.getHash();
}
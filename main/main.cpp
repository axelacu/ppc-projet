
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include "Bloc.h"
#include "Composant4.h"
#include "Composant3.h"

int main(int argc, char ** argv)
{
    Bloc bloc();
    Composant3::composant3(bloc);
    cout << bloc.getNonce() << '\n';
    cout << bloc.getHash();
}
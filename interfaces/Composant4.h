#pragma once
#ifndef COMPOSANT4_H
#define COMPOSANT4_H

#include <string>
#include "Bloc.h"

std::string hashBloc(Bloc bloc);
bool verifHash(Bloc bloc, std::string hashCode);
Bloc buildBloc(TX transaction);
Bloc buildBlocFull(char prevHash[], TX transaction, TXM trasnsactionMineur, unsigned int nonce, int num);
std::string version();

#endif

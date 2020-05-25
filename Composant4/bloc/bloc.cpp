#include "../interfaces/bloc.h"

Bloc::Bloc()
{
	nonce = 0;
	nbBloc++;
	num = nbBloc;
}

Bloc::Bloc(TX & transac) : Bloc()
{
	tx1 = transac;
}

std::string UTXO::toString()
{
	std::string key = "";
	for (char element : dest)
	{
		key += element;
	}
	return std::to_string(nUTX0) + std::to_string(nBloc) + std::to_string(nTx) + key + std::to_string(montant);
}

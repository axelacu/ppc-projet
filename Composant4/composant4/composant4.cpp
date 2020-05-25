#include "../interfaces/composant4.h"
#include <list>

// MOCK function of composant1
std::list<Bloc> composant1Blocs()
{
	std::list<Bloc> blocs;
	Bloc b = buildBlocFull("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", TX(), TXM(), 0, 0);
	blocs.push_front(b);
}

std::string hashBloc(Bloc bloc)
{
    std::string previous_hash = "";
    for (int i = 0; i < HASH_SIZE; ++i) {
        previous_hash += bloc.previous_hash[i];
    }
	return hash("" + std::to_string(bloc.num) + "|" + previous_hash + "|" + std::to_string(bloc.nonce));
}

bool verifHash(Bloc bloc, std::string hashCode)
{
    return (hashBloc(bloc) == hashCode);
}

Bloc buildBloc(TX transaction)
{
	for (UTXO utxo : transaction.UTXOs)
	{
		int i = 0;
		std::string hashedUtxo = hash(utxo.toString());
		for(std::string::size_type i = 0; i < hashedUtxo.length(); ++i)
		{
			char c = hashedUtxo[i];
			utxo.hash[i] = c;
		}
		/*for (char element : hash(utxo.toString()).c_str())
		{
			utxo.hash[i] = element;
			i++;
		}*/
		if (i < 63)
			for (int j = i; j < 63; j++)
				utxo.hash[j] = '0';
	}
	Bloc b = Bloc(transaction);
	
	//call composant1 pour la liste des blocs;
	//et intégrer le previous hash dedans
	std::list<Bloc> blocs = composant1Blocs();
	for (Bloc bloc : blocs)
	{
		if (bloc.num == b.num - 1)
			strcpy(b.previous_hash,bloc.hash);
	}
	return b;
		
}

Bloc buildBlocFull(char* _prevHash, TX _transaction, TXM _transactionMineur, unsigned int _nonce = 0, int _num = 0)
{
	Bloc b = Bloc();
	b.num = _num;
	b.nonce = _nonce;
	strcpy(b.previous_hash,_prevHash);
	b.tx1 = _transaction;
	b.tx0 = _transactionMineur;
	std::string hs = hashBloc(b);
	int i = 0;
	for (char element : hs)
	{
		b.hash[i] = element;
		i++;
	}
	if (i < 63)
		for (int j = i; j < 63; j++)
			b.hash[j] = '0';
	return b;
}

std::string version()
{
	return "v1.0.0";
}

/*
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hash)
{
	using namespace boost::python;
	def("hash", hashBloc);
	def("vertifHash", verifHash);
	def("buildBloc", buildBloc);
	def("buildBlocFull", buildBlocFull);
	def("version", version);
}
*/
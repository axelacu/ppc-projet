#include <string>
#include "Verificateur_Bloc.h"
#include <iostream>
#include "Bloc.h"

using namespace std;

int difficulte = 4;

bool Verificateur_Bloc::VerificateurBloc(std::string pubkey, Bloc bloc) {
    return VerificateurHash(bloc) && VerificateurDifficulte(bloc) && VerificateurTransaction(pubkey, bloc);
}

bool Verificateur_Bloc::VerificateurTransaction(std::string pubkey, Bloc bloc) {
    std::vector<TXI> entree = bloc.tx1.TXIs;
    bool testEntree;
    for(int i = 0; i<entree.size(); i++){
        testEntree = testEntree && verify(pubkey, bloc.hash, entree.at(i).signature);
    }
    if(!testEntree) {
        cerr << "transaction incorrecte";
        return false;
    }
    else
        return true;
}

bool Verificateur_Bloc::VerificateurDifficulte(Bloc bloc) {
    bool difficulteOk = true;
    for (int i=0; i<4; i++) {
        if (bloc.hash[i] != '0')
            difficulteOk = false;
    }
    if (!difficulteOk)
        cerr << "difficulte incorrecte";

    return difficulteOk
}

bool Verificateur_Bloc::VerificateurHash(Bloc bloc) {
    bool hashOk = verifHash(bloc, bloc.hash);
    if (!hashOk) {
        cerr << "hash incorrect";
        return false;
    }
    return true;
}

//fonctions composant 4
bool Verificateur_Bloc::verifHash(Bloc totest, char *hashtotest) {
    return true;
}
//fonction composant 6
bool Verificateur_Bloc::verify(std::string pubkey, char *hash, unsigned char *signature) {
    return true;
}

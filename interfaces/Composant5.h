#ifndef COMPOSANT5_H
#define COMPOSANT5_H

// interface du composant5

extern "C" int composant5(int p1, int p2);


class Verificateur_Bloc {
public:
    //venant de composant 6
    static bool verify(std::string pubkey, char hash[HASH_SIZE], unsigned char signature[64]);
    //venant de composant 4
    static bool verifHash(Bloc totest, char hashtotest[HASH_SIZE]);
    static bool VerificateurHash(Bloc bloc);
    static bool VerificateurDifficulte(Bloc bloc);
    static bool VerificateurTransaction(std::string pubkey, Bloc bloc);
    static bool VerificateurBloc(std::string pubkey, Bloc bloc);
};

#endif

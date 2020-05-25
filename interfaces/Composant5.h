#ifndef COMPOSANT5_H
#define COMPOSANT5_H

// interface du composant2

extern "C" int composant2(int p1, int p2);


class Verificateur_Bloc {
public:
    static bool verify(std::string pubkey, char hash[HASH_SIZE], unsigned char signature[64]);
    static bool verifHash(Bloc totest, char hashtotest[HASH_SIZE]);
    static bool VerificateurHash(Bloc bloc);
    static bool VerificateurDifficulte(Bloc bloc);
    static bool VerificateurTransaction(std::string pubkey, Bloc bloc);
    static bool VerificateurBloc(std::string pubkey, Bloc bloc);
};

#endif

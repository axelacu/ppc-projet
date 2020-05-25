#ifndef COMPOSANT5_H
#define COMPOSANT5_H

// interface du composant5

extern "C" int composant5(int p1, int p2);


class Verificateur_Bloc {
public:
    static bool VerificateurHash(Bloc bloc);
    static bool VerificateurDifficulte(Bloc bloc);
    static bool VerificateurTransaction(std::string pubkey, Bloc bloc);
    static bool VerificateurBloc(std::string pubkey, Bloc bloc);
};

#endif

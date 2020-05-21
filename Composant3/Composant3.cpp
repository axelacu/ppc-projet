#include "Composant3.h"
#include "Bloc.h"
#include <iostream>
#include <dlfcn.h>
#include <bits/stdc++.h>

bool valid(std::string hash, int difficulty){
	int i;
	for (i = 0; i < difficulty; i++)
	{
		if(hash[i]!=0)
			break;
	}
	if(i==difficulty)
		return true;
	return false;
}

//https://stackoverflow.com/questions/4671328/dlopen-and-global-variables-in-c-c
//nom_composante = ./libComposant4.so
static int getDifficulty(const char* nom_composante,const char* nom_variable_global){
	void *handle = dlopen(nom_composante,RTLD_LAZY);
	void * var_glob_obj = dlsym(handle,nom_variable_global);
	int * prt_var = (int *) var_glob_obj;
	return *prt_var;
}

/**
	Lit charge et execute la fonction hash
	
**/
static std::string hashFunction(Bloc bloc,const char* nom_composante){
	std::string (*func) (Bloc);
	std::string res;
	void *handle;

	
	handle = dlopen(nom_composante,RTLD_LAZY);

	
	if(handle == NULL){
		printf("Erreur dlopen  : %s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	//Changement de la fonction " func"

	*(void **) (&func) = dlsym(handle, "hashBloc");
	
	if(func == NULL){
		printf("Erreur chargement fonction");
		printf("Erreur dlsym : %s\n", dlerror());
		exit(EXIT_FAILURE);
	}	

	//execution de la fonction chargé 

	res = func(bloc);




	//fermeture 

	dlclose(handle);
	return res;
}


void boucle(Bloc &bloc){

	bloc.setNonce(0);
	//TODO : Verifier quel est le groupe 
	//TODO : tester l'appel des fonction exporté par la lib,
	std::cout<<"setNonce"<<std::endl;
	int difficulty = 3;//getDifficulty("./libComposant2.so","difficulty");//
	std::cout<<"difficulty"<<std::endl;
	std::string hash = hashFunction(bloc,"./libComposant4.so");  //call hash function de la librairie partagé. OPEN DL
	std::cout<<"hashFunc"<<std::endl;
	while(!valid(hash, difficulty))
	{
		std::cout<<"valid"<<std::endl;
		bloc.setNonce(bloc.getNonce()+1);
		std::cout<<"setNonce2"<<std::endl;
		///call hash function
		hash = hashFunction(bloc,"./libComposant4.so");
		std::cout<<"hasFunc2"<<std::endl;
	}

	//set hash of the bloc
	
	char* hashArray;
	strcpy(hashArray,hash.c_str());

	bloc.setHash(hashArray);
}


void composant3(Bloc &bloc)
{
	boucle(bloc);
}


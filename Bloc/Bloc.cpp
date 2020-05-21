#include "Bloc.h"
#include <iostream>
#include <dlfcn.h>
#include <bits/stdc++.h>

std::string Bloc::toString(){
	return  std::to_string(nonce);
}

void Bloc::setNonce(int n){
	nonce=n;
}

char* Bloc::getHash(){
	return hash;
}

unsigned int Bloc::getNonce(){
	return nonce;
}
void Bloc::setHash(char h[64]){
	strcpy(hash,h);
}

Bloc::Bloc(){
	char* hashArray;
	for(int i = 0;i<64;i++){

		hash[i] = '1';
	}

	nonce = 0;
}

Bloc* getBlocDynLibPointer(){
	Bloc* bloc = new Bloc;
	return bloc;
}
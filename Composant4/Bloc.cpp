#include "Bloc.h"
#include <iostream>
#include <dlfcn.h>

std::string Bloc::toString(){
	return (string)nonce;
}

void Bloc::setNonce(int n){
	nonce=n;
}
unsigned int Bloc::getNonce(){
	return nonce;
}
void Bloc::setHash(char[] h){
	hash = h;
}

Bloc::Bloc(){
	hash = std::string(64,"1");
	nonce = 0;
}
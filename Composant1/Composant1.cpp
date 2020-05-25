#include <stdio.h>
#include <json-c/json.h>

int main(){
	// déclaration de fonctions:
	void initBlockchain();
	void getAllBlocs();
	void addBloc();

	// Appels de fonction, pour renvoyer tous les blocs de la chaine (pas encore finalisée).
	initBlockchain();
	//getAllBlocs();
	//addBloc();

	//initBlockchain();

	printf("the end !\n");
	return 0;
}

void initBlockchain(){
	FILE *fp = NULL;
	fp = fopen("blockchain.json", "w");
	if(fp == NULL){
		printf("Erreur d'ouverture\n");
	}else{
		fprintf (fp, "{\n");
		fprintf (fp, "\t\"hash\"\t:\t\"example-ijsd4jdonosdijfoijs\",\n");
		fprintf (fp, "\t\"nonce\"\t:\t\"nonce\",\n");
		fprintf (fp, "\t\"previous_hash\"\t:\t\"example-ijsd4jdonosdijfoijs\",\n");
		fprintf (fp, "\t\"num\"\t:\t0,\n");
		fprintf (fp, "\t\"TX\"\t:\t\"tx1 transaction du bloc\",\n");
		fprintf (fp, "\t\"TXM\"\t:\t\"x0 transaction du mineur (coinbase)\"\n");
		fprintf (fp, "}\n");
	}
	fclose(fp);
}

void getAllBlocs(){
	// TODO : intérer sur tous les blocs... 
	FILE *fp = NULL;
	char buffer[20000];

	struct json_object *parsed_json;

	struct json_object *hash;
	struct json_object *nonce;
	struct json_object *previous_hash;
	struct json_object *num;
	struct json_object *TX;
	struct json_object *TXM;

	fp = fopen("blockchain.json", "r");
	fread(buffer, 20000, 1, fp);
	fclose(fp);

	parsed_json = json_tokener_parse(buffer);

	json_object_object_get_ex(parsed_json, "hash", &hash);
	json_object_object_get_ex(parsed_json, "nonce", &nonce);
	json_object_object_get_ex(parsed_json, "previous_hash", &previous_hash);
	json_object_object_get_ex(parsed_json, "num", &num);
	json_object_object_get_ex(parsed_json, "TX", &TX);
	json_object_object_get_ex(parsed_json, "TXM", &TXM);

	printf("hash : %s\n", json_object_get_string(hash));
	printf("nonce : %s\n", json_object_get_string(nonce));
	printf("previous_hash : %s\n", json_object_get_string(previous_hash));
	printf("num : %d\n", json_object_get_int(num));
	printf("TX : %s\n", json_object_get_string(TX));
	printf("TXM : %s\n", json_object_get_string(TXM));
}

void addBloc(){
	// Appel à la fonction de Vérification du bloc avant l'ajout
	FILE *fp = NULL;
	fp = fopen("blockchain.json", "a");
	if(fp == NULL){
		printf("Erreur d'ouverture\n");
	}else{
		// Nouvelles information
		fprintf (fp, "{\n");
		fprintf (fp, "\t\"hash\"\t:\t\"example-ijsd4jdonosdijfoijs\",\n");
		fprintf (fp, "\t\"nonce\"\t:\t\"nonce\",\n");
		fprintf (fp, "\t\"previous_hash\"\t:\t\"example-ijsd4jdonosdijfoijs\",\n");
		fprintf (fp, "\t\"num\"\t:\t0,\n");
		fprintf (fp, "\t\"TX\"\t:\t\"tx1 transaction du bloc\",\n");
		fprintf (fp, "\t\"TXM\"\t:\t\"x0 transaction du mineur (coinbase)\"\n");
		fprintf (fp, "}\n");
	}
	fclose(fp);
}


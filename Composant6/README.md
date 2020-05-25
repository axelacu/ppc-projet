Contenu de la librairie :
La librairie signature contient trois fonctions principales pour gérer la signature de hash chose :
• String GeneratePairKey() : ne prend aucun paramètre et renvoie une chaine de caractère.
 	o Output : le couple (clé publique, clé privée) est renvoyé dans la même chaine de
caractère et séparés par un “-”. Il suffit alors de faire appel à la fonction split (voir la suite) pour
récupérer chacune des clés dans une chaine de caractères séparée.
	o String split(string paireDeClés, int arg ) : cette fonction prend en paramètre la chaine de caractère
ou les deux clés publique et privée sont concaténées et un entier [ arg=0 pour récupérer la clé
publique et arg=1 pour récupérer la clé privée ]. Et retourne à la fin la clé souhaitée selon le
paramètre sous forme de string hexadécimal.
• String sign(string clé_privée, string hash_code) : signer un hash code de type string qui
sera passé en paramètre avec une clé privée générée et retourne la signature sous forme de string en format
hexadécimal.
• Bool verify(string clé_publique, string hash_code, string signature) : cette fonction prend en paramètre la
clé publique générée ( qui vient du couple (clé publique, clé privée) et dont la clé privée a été utilisée pour
signer le hash code), le hash code signé auparavant, et la signature récupérée de la fonction sign. Elle
renvoie un booléen :
	o Vrai : la signature est valide
	o Faux : la signature n'est pas valide

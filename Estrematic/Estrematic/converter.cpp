#include "converter.h"

bool converter::isVowel(const char& c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || 
			c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'À' || c == 'È' || c == 'Ì' || c == 'Ò' || c == 'Ù' ||
			c == 'à' || c == 'è' || c == 'ì' || c == 'ò' || c == 'ù' ||
			c == 'Á' || c == 'É' || c == 'Í' || c == 'Ó' || c == 'Ú' ||
			c == 'á' || c == 'é' || c == 'í' || c == 'ó' || c == 'ú' ||
			c == 'ü' || c == 'ï' || c == 'Ü' || c == 'Ï' );
}

void converter::lowerCapitalize(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		s[i] = tolower(s[i]);
	}
}


string converter::estrematize(string& s) {
	lowerCapitalize(s);

	//Switch amb les excepcions i al default l'algorisme de silabes
	if (s == Exc1 || s == Exc2) return "nepis";
	else if (s == Exc3) return "is";
	else if (s == Exc4) return "on";
	else if (s == Exc5) return "rectecu";
	else if (s == Exc6) return "Rar";
	else if (s == Exc7) return "Narbot";
	else if (s == Exc8) return "Rcma";
	else if (s == Exc9) return "Uap";
	else if (s == Exc10) return "Cro";
	else if (s == Exc11) return "Dijor";
	else if (s == Exc12) return "Coni";
	else {
		//Algorisme (consonant+vocal+consonant ? vocal : 2primeres ! 3primeres)
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (isVowel(s[i])) { //V
				if (i == n - 1) {
					return s;
				}
				else {
					if (isVowel(s[i + 1])) { //VV
						//Tallar segona vocal
						string aux = "";
						aux += s[0];
						aux += s[1];
						string aux2 = s.erase(0, 2);
						return aux2 + aux;
					}
					else { //VC
						if (i+1 == n - 1) {
							/*string aux;
							aux += s[1];
							aux += s[0];
							return aux;*/
							return s;
						}
						else {
							if (isVowel(s[i + 2])) { //VCV
								//Tallem 1ra V
								string aux = "";
								aux += s[0];
								string aux2 = s.erase(0, 1);
								return aux2 + aux;
							}
							else { //VCC
								string aux = "";
								aux += s[0];
								aux += s[1];
								aux += s[2];
								string aux2 = s.erase(0, 3);
								return aux2 + aux;
							}
						}
					}
				}
			}
			else { //C
				if (i == n - 1) {
					return s;
				}
				else {
					if (isVowel(s[i + 1])) { //CV
						if (i + 1 == n - 1) { //CV
							/*string aux;
							aux = "";
							aux += s[1];
							aux += s[0];
							return aux;*/
							return s;
						}
						else {
							if (isVowel(s[i + 2])) {//CVV
								//Tallem segona vocal
								string aux = "";
								aux += s[0];
								aux += s[1];
								aux += s[2];
								string aux2 = s.erase(0, 3);
								return aux2 + aux;
							}
							else { //CVC
								if (i + 2 == n - 1) { //CVC
									string aux = "";
									aux += s[2];
									aux += s[0];
									aux += s[1];
									return aux;
								}
								else {
									if (isVowel(s[i + 3])) {//CVCV
										string aux = "";
										aux += s[0];
										aux += s[1];
										string aux2 = s.erase(0, 2);
										return aux2 + aux;
										//Tallem 2 prim
									}
									else { //CVCC
										string aux = "";
										aux += s[0];
										aux += s[1];
										aux += s[2];
										string aux2 = s.erase(0, 3);
										return aux2 + aux;
										//Tallem 3 prim
									}
								}
							}
						}
					}
					else { //CC
						if (i + 1 == n - 1) {
							/*string aux = "";
							aux += s[1];
							aux += s[0];
							return aux;*/
							return s;
						}
						else {
							if (isVowel(s[i + 2])) { //CCV
								//FALTA ARREGLAR
								string aux = "";
								aux += s[0];
								string aux2 = s.erase(0, 1);
								return aux2 + aux;
								//Tallem 1 vocal
							}
							else { //VCC
								string aux = "";
								aux += s[0];
								aux += s[1];
								aux += s[2];
								string aux2 = s.erase(0, 3);
								return aux2 + aux;
								//Tallem 3 prim
							}
						}
					}
				}

			}
			
		}
	}
}

/*Dumpster

if (s[i] == 'i' && i < n && s[i + 1] == 'x') {
				sendToBack(s, "ix");
				return s;
			}
			else if (s[i] == 't' && i < n && s[i + 1] == 'x') {
				sendToBack(s, "tx");
				return s;
			}
			else if (s[i] == 't' && i < n && s[i + 1] == 'j') {
				sendToBack(s, "tj");
				return s;
			}
			else if (s[i] == 't' && i < n && s[i + 1] == 'g') {
				sendToBack(s, "tg");
				return s;
			}
			else if (s[i] == 'r' && i < n && s[i + 1] == 'r') {
				sendToBack(s, "rr");
				return s;
			}
			else if (s[i] == 's' && i < n && s[i + 1] == 's') {
				sendToBack(s, "ss");
				return s;
			}
			else if (s[i] == 's' && i < n && s[i + 1] == 'c') {
				sendToBack(s, "sc");
				return s;
			}
			else if (s[i] == 'g' && i < n && s[i + 1] == 'u') {
				sendToBack(s, "sc");
				return s;
			}
			else if (s[i] == '.') {
				return ".";
			}
*/
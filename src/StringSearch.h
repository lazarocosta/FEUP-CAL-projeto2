#ifndef SRC_STRINGSEARCH_H_
#define SRC_STRINGSEARCH_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Calcula as diferenças entre duas strings (algoritmo de pesquisa aproximada)
int EditDistance(string name1,string name2);
//Verifica se a função é válida
string VerifyValidName(string name1,string name2);



#endif

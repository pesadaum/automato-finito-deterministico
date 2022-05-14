#include<iostream>
#include<fstream>
#include<string>

#include<vector>

#include"afd.hpp"

using namespace std;

void mostra_se_foi_aceito(bool aceito) {
  aceito ? cout << "Aceito" << endl : cout << "Não aceito" << endl;
  return;
}

int main() {

  AFD teste("teste_2.txt", true);


  mostra_se_foi_aceito(teste.testa_palavra("abbababa", true));


  return 0;
}
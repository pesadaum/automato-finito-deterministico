#include<iostream>

#include"afd.hpp"

using namespace std;

void mostra_se_foi_aceito(bool aceito) {
  aceito
    ? cout << "Aceito" << endl
    : cout << "Não aceito" << endl;
  return;
}

int main() {

  AFD afd1("afd1.txt", true);
  AFD afd2("afd2.txt", true);
  AFD afd3("afd3.txt", true);
  AFD afd4("afd4.txt", true);
  AFD afd5("afd5.txt", true);
  AFD afd6("afd6.txt", true);

  afd1.testa_arquivo_inteiro(true);


  return 0;
}
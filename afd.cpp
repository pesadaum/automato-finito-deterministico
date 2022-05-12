#include"afd.hpp"

#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>

// using namespace std;

/**
 * @brief Função auxiliar que separa espaços de uma string
 * @return Vetor de strings separadas
 */
std::vector<std::string> separa_espacos(std::string s) {
  std::stringstream ss(s);
  std::string token;
  std::vector<std::string> tokens;
  while (ss >> token) {
    tokens.push_back(token);
  }

  return tokens;
}


/**
 * @brief lê a o arquivo com a bagaceira e retorna num vetor de strings
 * @return vector<string>: Um vetor de strings com as linhas do arquivo
*/
AFD::AFD(std::string fname, bool mostra_atributos) {
  std::ifstream arq;
  std::string buffer;
  std::string dados;
  std::vector<std::string> conteudo;

  arq.open(fname, std::ios::in);

  while (std::getline(arq, buffer)) conteudo.push_back(buffer);

  arq.close();

  this->estados = separa_espacos(conteudo[0]);
  this->alfabeto = separa_espacos(conteudo[1]);

  if (mostra_atributos) {
    std::cout << "Estados: |";
    for (const std::string i : this->estados) std::cout << i << "|";
    std::cout << " --- Quantidade de estados: " << this->estados.size();

    std::cout << std::endl;

    std::cout << "Alfabeto: |";
    for (const std::string i : this->alfabeto) std::cout << i << "|";
    std::cout << " --- Tamanho do alfabeto:" << this->alfabeto.size();


  }


}





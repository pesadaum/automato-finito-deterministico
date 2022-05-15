#include"afd.hpp"

#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

/**
 * @brief Função auxiliar para retornar o índice do símbolo no alfabeto
*/
int indice_no_alfabeto(vector<string> alfabeto, string simbolo) {
  for (int i = 0; i < alfabeto.size(); i++) if (alfabeto[i] == simbolo) return i; return -1;
}

/**
 * @brief Função auxiliar que separa espaços de uma string
 * @return Vetor de strings separadas por espaços
 */
vector<string> separa_espacos(string s) {
  stringstream ss(s);
  string token;
  vector<string> tokens;

  while (ss >> token) {
    tokens.push_back(token);
  }

  return tokens;
}


/**
 * @brief lê a o arquivo com a bagaceira e retorna num vetor de strings
 * @return vector<string>: Um vetor de strings com as linhas do arquivo
*/
AFD::AFD(string fname, bool mostra_atributos) {
  ifstream arq;
  string buffer;
  string dados;
  vector<string> conteudo;

  arq.open(fname, ios::in);

  while (getline(arq, buffer)) conteudo.push_back(buffer);

  arq.close();

  this->estados = separa_espacos(conteudo[0]);
  this->alfabeto = separa_espacos(conteudo[1]);


  /**
   * Da segunda linha (onde começam os estados) até a quantidade de estados
   * são lidas as transições e associados ao mapa de transições
  */
  for (int i = 0; i < this->estados.size(); i++) {
    this->mapa_transicoes.insert({ this->estados[i], separa_espacos(conteudo[i + 2]) });
  }

  /**
   * O estado inicial é a primeira linha após o fim das transições
  */
  this->estado_inicial = conteudo[this->estados.size() + 2];

  /**
   * Os estados finais estão na segunda linha após o fim das transições
  */
  this->estados_finais = separa_espacos(conteudo[this->estados.size() + 3]);

  /**
   * Número de testes especificados uma linha após os estados finais
  */
  this->num_testes = stoi(conteudo[this->estados.size() + 4]);

  /**
   * Constrói o vetor de palavras uma linha após a o número de testes
  */
  for (int i = 0; i < this->num_testes; i++) {
    this->palavras_teste.push_back(conteudo[(this->estados.size() + 5) + i]);
  }


  if (mostra_atributos) {
    cout << endl;

    cout << "----- AFD '" << fname << "'-----" << endl;
    cout << "Estados: {";
    for (const string i : this->estados) cout << i << ", ";
    cout << "} --- Quantidade de estados: " << this->estados.size();
    cout << endl;

    cout << "Alfabeto: {";
    for (const string i : this->alfabeto) cout << i << ", ";
    cout << "} --- Tamanho do alfabeto: " << this->alfabeto.size();
    cout << endl;

    cout << "Estado inicial: " << this->estado_inicial;
    cout << endl;

    cout << "Estados finais: {";
    for (const string i : this->estados_finais) cout << i << ", ";
    cout << "} --- Tamanho do conjunto de estados finais: " << this->estados_finais.size();
    cout << endl << endl;

    cout << "Mapa de transições:" << endl;
    for (auto x : this->mapa_transicoes) {
      cout << x.first << ": [ ";
      for (auto t : x.second) cout << t << ", ";
      cout << " ]" << endl;
    }

    cout << "Numero de testes: " << this->num_testes << endl;
    for (const string i : this->palavras_teste) cout << i << endl;
    cout << endl;
  }
}

string AFD::delta(string e_atual, string simbolo) {
  int indice = indice_no_alfabeto(this->alfabeto, simbolo);
  if (indice == -1) {
    cout << "Aviso: o item '" << simbolo << "' não está no alfabeto, revise a entrada de dados";
    return e_atual;
  }
  return this->mapa_transicoes[e_atual][indice];
}


bool AFD::testa_palavra(string palavra) {
  string estado_atual = this->estado_inicial;
  stringstream ss;

  for (int i = 0; i < palavra.size(); i++) {
    string simbolo = string(1, palavra[i]); // pq diabos o char não é assignible to string ?????
    estado_atual = delta(estado_atual, simbolo);
  }

  for (const string estado : this->estados_finais) {
    if (estado_atual == estado) return true;
  }

  return false;
}

bool AFD::testa_palavra(string palavra, bool verboso) {
  string estado_atual = this->estado_inicial;
  stringstream ss;

  if (verboso) cout << estado_atual << "->";

  for (int i = 0; i < palavra.size(); i++) {
    string simbolo = string(1, palavra[i]); // pq diabos o char não é assignible to string ?????
    estado_atual = delta(estado_atual, simbolo);
    if (verboso) cout << estado_atual << "->";
  }


  for (const string estado : this->estados_finais) {
    if (estado_atual == estado) return true;
  }

  return false;
}

void AFD::testa_arquivo_inteiro(bool verboso) {
  for (const string palavra : this->palavras_teste) testa_palavra(palavra, verboso);
}
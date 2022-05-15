#pragma once

#include<string>
#include<vector>
#include<unordered_map>

/**
 * Classe concreta para implementação em arquivo .cpp
 */
class AFD {
private:

  /**
   * @brief Vetor de string com os estados (primeira linha do arquivo)
   */
  std::vector<std::string> estados;


  /**
   * @brief O mapa de transições associa um estado (chave) à uma lista de estados atingíveis (valor) indexados pelo alfabeto
  */
  std::unordered_map<std::string, std::vector<std::string>> mapa_transicoes;


  /**
   * @brief Vetor de string com o alfabeto (segunda linha do arquivo)
   **/
  std::vector<std::string> alfabeto;


  /**
   * @brief String com o estado inicial; lida após as transições
   *
  */
  std::string estado_inicial;


  /**
   * @brief vetor de estados finais. Deveria ser um set pra não constar com elementos repetidos mas vector serve
  */
  std::vector<std::string> estados_finais;

  /**
   * @brief Quantidade de testes especificadas em arquivo.
  */
  int num_testes;

  /**
   * @brief Vetor de strings com as palavras de teste.
  */
  std::vector<std::string> palavras_teste;

public:

  /**
   * @brief construtor da classe AFD
   * @param fname: Nome do arquivo
   * @param mostra_conteudo: Se mostra o conteúdo do AFD ou não
   */
  AFD(std::string fname, bool mostra_atributos = false);


  /**
   * @brief lê um estado atual e um símbolo, e leva para outro estado
   * @param e_atual: Estado atual
   * @param simbolo: Simbolo do alfabeto
   * @return <string>: Estado resultado da transformação \delta
  */
  std::string delta(std::string e_atual, std::string simbolo);

  /**
   * @brief função que testa a palavra fornecida
   * @param palavra: palavra a ser testada
   * @return true se a palavra for reconhecida, false caso contrário
   */
  bool testa_palavra(std::string palavra);
  /**
   * @brief sobrecarga da função que testa a palavra fornecida
   * @param palavra: palavra a ser testada
   * @param verboso: mostra o resultado de forma verbosa
   * @return `true se a palavra for reconhecida, false caso contrário}
   */
  bool testa_palavra(std::string palavra, bool verboso);

  /**
   * @brief função que testa todas as palavras do arquivo
   *  com base na quantidade de testes especificados no próprio arquivo
   * @param verboso: mostra o resultado de forma verbosa
  */
  void testa_arquivo_inteiro(bool verboso);

};
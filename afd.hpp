#pragma once

#include<string>
#include<vector>
#include<unordered_map>
// #include<unordered_set>

/**
 * AFD {
 * estados: []
 * alfabeto: []
 * transicoes: [[]]
 * estado_inicial: str
 * estado_final: str
 * numero_de_testes: int
 * palavras_de_testes: str
 * }
 *
 * */

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
   * @brief O delta mapeia um estado de saída dados um estado atual e um símbolo
   **/

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

  std::vector<std::string> estados_finais; // deveria ser um set, mas vector serve

  // auto get_alfabeto()

public:

  /**
   * @brief construtor da classe AFD
   * @param fname: Nome do arquivo
   * @param mostra_conteudo: Se mostra o conteúdo do AFD ou não
   * @return <bool> Retorna true se leu o arquivo e construiu o AFD, false caso contrário
   */
  AFD(std::string fname, bool mostra_atributos = false);


  /**
   * @brief lê um estado atual e um símbolo, e leva para outro estado
   * @param e_atual: Estado atual
   * @param simbolo: Simbolo do alfabeto
   * @return prox <string>: Estado resultado da transformação \delta
  */
  std::string delta(std::string e_atual, std::string simbolo);

  /**
   * @brief função que testa a palavra fornecida
   * @param palavra: palavra a ser testada
   * @return `true se a palavra for reconhecida, false caso contrário
   */
  bool testa_palavra(std::string palavra);
  /**
   * @brief sobrecarga da função que testa a palavra fornecida
   * @param palavra: palavra a ser testada
   * @param verboso: mostra o resultado de forma verbosa
   * @return `true se a palavra for reconhecida, false caso contrário}
   */
  bool testa_palavra(std::string palavra, bool verboso);

};
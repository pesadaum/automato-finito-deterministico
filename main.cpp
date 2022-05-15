#include<iostream>

#include"afd.hpp"

using namespace std;

int main() {

   AFD afd_1a = AFD("./afd1a.txt", true);
   afd_1a.testa_arquivo_inteiro(true);

   AFD afd_1b = AFD("./afd1b.txt", true);
   afd_1b.testa_arquivo_inteiro(true);

    AFD afd_1c = AFD("./afd1c.txt", true);
    afd_1c.testa_arquivo_inteiro(true);

    AFD afd_2a = AFD("./afd2a.txt", true);
    afd_2a.testa_arquivo_inteiro(true);

   AFD afd_2b = AFD("./afd2b.txt", true);
   afd_2b.testa_arquivo_inteiro(true);

  return 0;
}
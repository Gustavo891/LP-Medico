#include "myHeader.hpp"
#include <iostream>

using namespace std;
/*
 FUNÇÕES PRINCIPAIS
*/
int main() {
  int opcao;
  string senha;

  /*
  MENSAGEM QUE O SISTEMA ENVIA PARA O USUARIO ESCOLHER EM QUAL FUNÇÃO QUER
  ENTRAR.
  */
  while (true) {
    cout << "Seja bem-vindo ao nosso sistema hospitalar." << endl;
    cout << "Acesse com uma das opções abaixo:" << endl;
    cout << "" << endl;
    cout << "1 - Atendente" << endl;
    cout << "2 - Gestor" << endl;
    cout << "3 - Sair" << endl;
    cout << "" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    /*
     OPÇÕES PARA OS USUÁRIOS
    */
    switch (opcao) {
    case 1:
      cout << "Acessando como atendente..." << endl;
      atendente();
      break;

    case 2:
      cout << "Digite a senha para acessar o sistema como Gestor:" << endl;
      ;
      cin >> senha;
      if (senha == "admin") {
        cout << "Senha correta." << endl;
        gestor();
      } else {
        cout << "Senha incorreta, sistema está sendo desligado." << endl;
      }
      break;

    case 3:
      cout << "Sistema desligando... " << endl;
      break;

    default:
      cout << "Opcao invalida." << endl;
    }
  }

  return 0;
}

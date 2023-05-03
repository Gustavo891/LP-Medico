
  /*
	MENU DO GESTOR
 	ONDE ELE PODE GERENCIAR SUAS FUNÇÕES
  */

#include "myHeader.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Medico {
  string nome;
  string especialidade;
};


  /*
  FUNÇÃO DE IMPRIMIR OS MÉDICOS DE ACORDO COM SUA ESPECIALIDADE
  */
void imprimirMedicosPorEspecialidade(string especialidade) {
  ifstream arquivo("medicos.txt"); // abre o arquivo para leitura

  if (arquivo.is_open()) { // verifica se o arquivo foi aberto com sucesso
    string linha;

    while (getline(arquivo, linha)) { // lê cada linha do arquivo
      string nome, esp;
      size_t pos = linha.find(";"); // encontra a posição do separador
      nome = linha.substr(0, pos);  // extrai o nome
      esp = linha.substr(pos + 1);  // extrai a especialidade
      if (esp == especialidade) { // verifica se a especialidade do médico é a
                                  // mesma informada pelo usuário
        cout << "Medico: " << nome << ", Especialidade: " << especialidade
             << endl; // exibe o médico e a especialidade
      }
    }

    arquivo.close(); // fecha o arquivo
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}
  /*
  FUNÇÃO DE REGISTRAR OS MÉDICOS NO SISTEMA
  */
void salvarMedicos(vector<Medico> medicos) {
  ofstream arquivo(
      "medicos.txt",
      ios::app); // abre o arquivo para escrita, usando o modo de adição

  if (arquivo.is_open()) { // verifica se o arquivo foi aberto com sucesso
    for (Medico medico : medicos) {
      arquivo << medico.nome << ";" << medico.especialidade
              << endl; // escreve o nome e a especialidade no arquivo
    }
    arquivo.close(); // fecha o arquivo
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}
  /*
  FUNÇÃO DE LER OS MÉDICOS DO SISTEMA
  */
void lerMedicos() {
  ifstream arquivo("medicos.txt");

  if (arquivo.is_open()) {
    string linha;

    // Imprime o cabeçalho da tabela
    cout << endl << "Medico\t\t\t\t\tEspecialidade" << endl << endl;

    // Lê cada linha do arquivo e exibe os dados em formato de tabela
    while (getline(arquivo, linha)) {
      // Separa os dados da linha utilizando o caractere ';' como delimitador
      stringstream ss(linha);
      vector<string> dados;
      string dado;
      while (getline(ss, dado, ';')) {
        dados.push_back(dado);
      }

      // Verifica se a linha contém todos os dados necessários
      if (dados.size() == 2) {
        // Exibe os dados em formato de tabela
        cout << left << setw(20) << dados[0] << "\t" << dados[1] << endl;
      }
    }

    arquivo.close();
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}
  /*
  FUNÇÃO DE EXCLUIR O MÉDICO DE ACORDO COM SEU NOME
  */
void excluirMedicoPorNome(string nome) {
  ifstream arquivo("medicos.txt"); // abre o arquivo para leitura
  ofstream temp("temp.txt");       // abre um arquivo temporário para escrita

  if (arquivo.is_open() &&
      temp.is_open()) { // verifica se os arquivos foram abertos com sucesso
    string linha;

    while (getline(arquivo, linha)) { // lê cada linha do arquivo
      string medicoNome, esp;
      size_t pos = linha.find(";");      // encontra a posição do separador
      medicoNome = linha.substr(0, pos); // extrai o nome do médico

      if (medicoNome !=
          nome) { // se o nome do médico não for o mesmo informado pelo usuário,
                  // escreve a linha no arquivo temporário
        temp << linha << endl;
      }
    }

    arquivo.close(); // fecha o arquivo original
    temp.close();    // fecha o arquivo temporário

    // exclui o arquivo original e renomeia o arquivo temporário para o nome
    // original
    if (remove("medicos.txt") == 0 && rename("temp.txt", "medicos.txt") == 0) {
      cout << "Medico excluido com sucesso" << endl;
    } else {
      cout << "Nao foi possivel excluir o medico" << endl;
    }
  } else {
    cout << "Nao foi possivel abrir os arquivos" << endl;
  }
}
  /*
  FUNÇÃO DE ALTERAR A ESPECIALIDADE DO MÉDICO DE ACORDO COM SEU NOME.
  */
void alterarEspecialidadePorNome(string nome) {
  ifstream arquivo("medicos.txt");
  ofstream temp("temp.txt");

  if (arquivo.is_open() && temp.is_open()) {
    string linha;

    while (getline(arquivo, linha)) {
      string medicoNome, esp;
      size_t pos = linha.find(";");
      medicoNome = linha.substr(0, pos);

      if (medicoNome == nome) {
        cout << "Digite a nova especialidade para o medico " << nome << ": ";
        cin >> esp;
        temp << nome << ";" << esp << endl;
      } else {
        temp << linha << endl;
      }
    }

    arquivo.close();
    temp.close();

    if (remove("medicos.txt") == 0 && rename("temp.txt", "medicos.txt") == 0) {
      cout << "Especialidade alterada com sucesso" << endl;
    } else {
      cout << "Nao foi possivel alterar a especialidade" << endl;
    }
  } else {
    cout << "Nao foi possivel abrir os arquivos" << endl;
  }
}
  /*
  FUNÇÃO DE LISTAR OS AGENDAMENTOS P/MEDICO
  */
void agendamentosMedico(string nome) {
  ifstream arquivo("agendamento.txt");
  if (arquivo.is_open()) {
    string linha;
    cout << endl << "Agendamentos do medico(a) " << nome << ":" << endl << endl;
    cout << "Data\t\tHorario" << endl;
    while (getline(arquivo, linha)) {
      stringstream ss(linha);
      vector<string> dados;
      string dado;
      while (getline(ss, dado, ';')) {
        dados.push_back(dado);
      }
      if (dados.size() == 3 && dados[0] == nome) {
        cout << dados[1] << "\t" << dados[2] << endl;
      }
    }
    arquivo.close();
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}
  /*
  FUNÇÃO PRINCIPAL DO GESTOR
  */

void gestor() {
  int opt;
  vector<Medico> medicos;
  int numMedicos;
  string especialidade;
  string nome2;
  string nome;

  /*
  FUNÇÃO DE IMPRIMIR OS MÉDICOS DE ACORDO COM SUA ESPECIALIDADE
  */
	
  while (true) {

    string ran;
    string nomeAg;

    cout << "" << endl;
    cout << "Escolha uma das opções:" << endl;
    cout << "1 - Listar médicos." << endl;
    cout << "2 - Listar especialidades." << endl;
    cout << "3 - Adicionar médico." << endl;
    cout << "4 - Consultar agendamentos p/medico." << endl;
    cout << "5 - Alterar especialidade." << endl;
    cout << "6 - Excluir médico." << endl;
    cout << "7 - Voltar." << endl;
    cin >> opt;
    if (opt == 7) {
      break;
    }
    switch (opt) {

    case 1:
      lerMedicos();
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;

    case 2:
      cout << "Digite a especialidade para buscar os medicos: ";
      cin >> especialidade;
      imprimirMedicosPorEspecialidade(especialidade);
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;

    case 3:
      cout << "Quantos medicos voce deseja salvar? ";
      cin >> numMedicos;
      cin.ignore();

      for (int i = 0; i < numMedicos; i++) {
        Medico medico;
        cout << "Digite o nome do medico " << i + 1 << ": ";
        getline(cin, medico.nome);
        cout << "Digite a especialidade do medico " << i + 1 << ": ";
        getline(cin, medico.especialidade);
        medicos.push_back(medico);
      }
      salvarMedicos(medicos);
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;

    case 4:
      cout << "Digite o nome do medico para consultar o agendamento: ";
      cin.ignore();
      getline(cin, nomeAg);
      agendamentosMedico(nomeAg);
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;

    case 5:
      cout << "Digite o nome do medico para alterar a especialidade: ";
      cin.ignore();
      getline(cin, nome2);
      alterarEspecialidadePorNome(nome2);
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;

    case 6:
      cout << "Digite o nome do medico para excluir: ";
      cin.ignore();
      getline(cin, nome);
      excluirMedicoPorNome(nome);
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;

    default:
      cout << "Opção Inválida!";
      break;
    }
  }
  cout << "Sistema finalizado.";
}

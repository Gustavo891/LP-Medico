
/*
      MENU DO ATENDENTE
      ONDE ELE PODE GERENCIAR SUAS FUNÇÕES
*/

#include "myHeader.hpp"
#include <algorithm>
#include <cmath>
#include <fstream>
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
      FUNÇÃO DE LISTAR TODAS ESPECIALIDADES E A QUANTIDADE DE MÉDICOS
*/

void listarEspecialidades() {
  ifstream arquivo("medicos.txt");

  if (arquivo.is_open()) {
    string linha;
    map<string, int> especialidades;

    while (getline(arquivo, linha)) {
      stringstream ss(linha);
      vector<string> dados;
      string dado;
      while (getline(ss, dado, ';')) {
        dados.push_back(dado);
      }

      if (dados.size() == 2) {
        string especialidade = dados[1];
        especialidades[especialidade]++;
      }
    }

    arquivo.close();

    cout << endl << "Especialidade\t\tQuantidade de medicos" << endl << endl;
    for (const auto &[especialidade, quantidade] : especialidades) {
      cout << especialidade << "\t\t\t\t" << quantidade << endl;
    }
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}

/*
      FUNÇÃO DE LISTAR OS AGENDAMENTOS DOS MÉDICOS
*/

void listarAgendamentos() {
  ifstream arquivo("agendamento.txt");

  if (arquivo.is_open()) {
    string linha;

    cout << endl << "Nome do Médico\t\t\tData\t\tHorario" << endl << endl;

    while (getline(arquivo, linha)) {
      stringstream ss(linha);
      vector<string> dados;
      string dado;
      while (getline(ss, dado, ';')) {
        dados.push_back(dado);
      }

      if (dados.size() == 3) {
        cout << dados[0] << "\t\t" << dados[1] << "\t" << dados[2] << endl;
      }
    }

    arquivo.close();
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}

/*
      FUNÇÃO DE SALVAR AGENDAMENTOS DO MÉDICO
*/

void salvarAgendamento() {
  string nomeMedico, dia, horario;

  cout << "Digite o nome do medico: ";
  cin.ignore();
  getline(cin, nomeMedico);
  cout << "Digite o dia do agendamento (dd/mm/aaaa): ";
  cin >> dia;
  cout << "Digite o horario do agendamento (hh:mm): ";
  cin >> horario;

  ofstream arquivo("agendamento.txt", ios::app);

  if (arquivo.is_open()) {
    arquivo << nomeMedico << ";" << dia << ";" << horario << endl;
    arquivo.close();
    cout << endl << "Agendamento salvo com sucesso" << endl;
    cout << nomeMedico << " no dia " << dia << " as " << horario << endl;
  } else {
    cout << "Nao foi possivel abrir o arquivo" << endl;
  }
}

/*
      FUNÇÃO PRINCIPAL DO ATENDENTE
      ONDE TEM AS FUNCIONALIDADES QUE DIRECIONA NAS FUNÇÕES
*/

void atendente() {
  int opt;
  char ran;
  string nome;

  while (true) {

    string nome;
    cout << "" << endl;
    cout << "Escolha uma das opções:" << endl;
    cout << "1 - Listar médicos." << endl;
    cout << "2 - Listar especialidades c/quantidades." << endl;
    cout << "3 - Agendar Horario." << endl;
    cout << "4 - Listar todos agendamentos." << endl;
    cout << "5 - Voltar." << endl;
    cin >> opt;
    if (opt == 5) {
      break;
    }
    switch (opt) {

    case 1:
      lerMedicos();
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;
    case 2:
      listarEspecialidades();
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;
    case 3:
      salvarAgendamento();
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;
    case 4:
      listarAgendamentos();
      cout << endl << "Digite (V) para voltar ao sistema." << endl;
      cin >> ran;
      break;
    default:
      break;
    }
  }
}
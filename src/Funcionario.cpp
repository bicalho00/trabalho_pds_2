#include "Funcionario.hpp"

/**
    Construtor da classe Funcionario
    _nome Nome do funcionario instanciado
    _identificacao Número de identificação
    do funcionario instanciado
    _idade Idade do funcionario instanciado
    _salario Salário do funcionario instanciado
 */
Funcionario::Funcionario(std::string _nome, int _identificacao, int _idade, double _salario){

    this->nome = _nome;
    this->identificacao = _identificacao;
    this->idade = _idade;
    this->salario = _salario;
};

/*
 Destrutor da classe Funcionario
 */
Funcionario::~Funcionario(){};

/*
    Retorna nome do funcionário indicado
    Nome do funcionário
 */
std::string Funcionario::getNome(){
    
    return this->nome;
};

/**
  Retorna identificação do funcionário indicado
  Id do funcionário
 */
int Funcionario::getId(){

    return this->identificacao;
};

/**
    Retorna idade do funcionário indicado
    Idade do funcionário
 */
int Funcionario::getIdade(){

    return this->idade;
};

/*
    Retorna salário do funcionário indicado
    Salário do funcionário
 */
double Funcionario::getSalario(){

    return this->salario;
};

/*
    Imprime na tela todas as informações
    do funcionário
 */
void Funcionario::printInfo(){
    
    std::cout << "Nome: " << this->nome << std::endl
              << "Idade: " << this->idade << std::endl 
              << "Nº Identificação: " << this->identificacao << std::endl
              << "Salário: " << this->salario << std::endl;
};
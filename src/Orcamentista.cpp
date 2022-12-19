#include "Orcamentista.hpp"

/*
    Construtor da classe Orcamentista
    _nome Nome do orçamentista instanciado
    _identificacao Número de identificação do orçamentista instanciado
    _idade Idade do orçamentista instanciado
    _salario Salário do orçamentista instanciado
    _meta Meta do orçamentista instanciado
 */
Orcamentista::Orcamentista(std::string _nome, int _identificacao, int _idade, double _salario, double _meta)
              : Funcionario(_nome, _identificacao, _idade, _salario){

                this->meta = _meta;                
};

/*
    Destrutor da classe Orcamentista
 */
Orcamentista::~Orcamentista(){};

/*
    Soma totas as propostas do orçamentista que viraram contrato
    Valor total dos contratos
 */
double Orcamentista::getTotalFechado(){     

    /*Como não foi automatizado o processo de fechar a proposta e somar o valor para o orcamentista responsável,
      fez-se necessário uma verificação desse montante sempre que for preciso pegar o valor*/
    
    this->totalFechado = 0;

    for(auto it = this->listaPropostas.begin(); it != this->listaPropostas.end(); it ++){
        Proposta* aux = *it;
        
        if(aux->contratoAssinado())
            this->totalFechado += aux->getValor();            
    }
    
    return this->totalFechado;
};

/*
    Retorna meta do orçamentista indicado
    Meta do orçamentista
 */
double Orcamentista::getMeta(){

    return this->meta;
};

/*
    Atribui nova proposta ao orçamentista
    _proposta Proposta que será atribuida
 */
void Orcamentista::adicionarProposta(Proposta* _proposta){

    this->listaPropostas.push_back(_proposta);
    _proposta->setOrcamentista(this->nome);
};

/*
    Imprime na tela todas as propostas em aberto
 */
void Orcamentista::imprimirPropostasAbertas(){
    
    if(!this->listaPropostas.empty()){
        for(auto it = this->listaPropostas.begin(); it != this->listaPropostas.end(); it ++){ 
            Proposta* aux = *it;
        
            if(!aux->contratoAssinado())
                aux->printProposta();            
        }
    } else{
        throw QueueEmptyException();
    }
};

/*
    Imprime na tela todas as propostas que viraram contrato
 */
void Orcamentista::imprimirPropostasFechadas(){

    if(!this->listaPropostas.empty()){
        for(auto it = this->listaPropostas.begin(); it != this->listaPropostas.end(); it ++){    
            Proposta* aux = *it;
        
            if(aux->contratoAssinado())
                aux->printProposta();            
        }  
    } else{
        throw QueueEmptyException();
    }
};

/*
    Calcula e imprime o rendimento do orçamentista de acordo com sua meta
 */
void Orcamentista::progressoMeta(){

    double porcentagem;

    porcentagem = this->getTotalFechado() / this->meta * 100;

    std::cout << "Orcamentista: " << this->nome << std::endl
              << "Total fechado: " << this->totalFechado << std::endl
              << "Meta definida: " << this->meta << std::endl
              << "Porcentagem cumprida: " << std::fixed << std::setprecision(2) << porcentagem << "%"
              << std::endl;
};

/*
    Imprime na tela todas as informações do orçamentista
 */
void Orcamentista::printInfo(){
    
    std::cout << "Nome: " << this->nome << std::endl
              << "Idade: " << this->idade << std::endl 
              << "Nº Identificação: " << this->identificacao << std::endl
              << "Salário: " << this->salario << std::endl
              << "Meta: " << this->meta << std::endl;
};
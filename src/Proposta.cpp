#include "Proposta.hpp"

/**
 * Construtor vazio da classe Proposta
 */
Proposta::Proposta(){};

/**
 *  Destrutor da classe Proposta
 */
Proposta::~Proposta(){};

/**
 * Construtor da classe Proposta
 *  _nomeCliente Nome do cliente responsável
 * pela proposta
 *  _descricao Breve descrição do projeto 
 *  _valor Valor do projeto
 *  _numProposta Número da proposta feita
 */
Proposta::Proposta(std::string _nomeCliente, std::string _descricao, double _valor, int _numProposta){
    
    this->nomeCliente = _nomeCliente;
    this->descricao = _descricao;
    this->numProposta = _numProposta;
    this->valor = _valor;
    this->contratoFechado = false;
};

/**
 *  Retorna nome do cliente
 *  Nome do cliente
 */
std::string Proposta::getNomeCliente(){

    return this->nomeCliente;
};

/**
 *  Retorna descrição do projeto
 * Descrição do projeto
 */
std::string Proposta::getDescricao(){

    return this->descricao;
};

/**
 *  Retorna data que a proposta foi
 * assinada
 *  Data de assinatura
 */
std::string Proposta::getDataAssinatura(){

    return this->dataAssinatura;
};

/**
 *  Retorna data de pagamento
 * Data de pagamento da proposta
 */
std::string Proposta::getDataPagamento(){
        
        return this->dataPagamento;
};

/**
 *  Retorna valor da proposta
 *  Valor da proposta
 */
double Proposta::getValor(){
    
    return this->valor;
};

/**
 *  Retorna número da proposta
 *  Número da proposta
 */
int Proposta::getNumProposta(){

    return this->numProposta;
};

/**
 *  Verifica número da proposta atual
 *  Número que a próxima proposta 
 * instanciada deverá ter
 */
int Proposta::getPropostaAtual(){

    return this->numProposta + 1;    
};

/**
 *  Retorna orçamentista responsável
 *  Orçamentista responsável pela
 * proposta
 */
std::string Proposta::getOrcamentistaResponsavel(){
    
    return this->orcResponsavel;
};

/**
 *  Atribui orçamentista a proposta
 *  _orcResponsavel Orçamentista indicado
 * para a proposta
 */
void Proposta::setOrcamentista(std::string _orcResponsavel){

    this->orcResponsavel = _orcResponsavel;
};

/**
 *  Verifica se o contrato foi fechado
 *  Status do contrato
 */
void Proposta::setContratoFechado(){
    
    this->contratoFechado = true;
};

/**
 *  Verifica pagamento do contrato e imprime 
 * status da transação
 * _valor Valor do contrato
 *  _dataPagamento Data que o pagamento foi
 * efetuado
 */
void Proposta::setContratoPago(double _valor, std::string _dataPagamento){

    if(this->valor == _valor){
        this->contratoPago = true;
        std::cout << "Pagamento realizado com sucesso." << std::endl;
        this->setDataPagamento(_dataPagamento);
    } else{
        std::cout << "Tentativa de Pagamento não condiz com o valor do contrato." << std::endl
                  << "Valor inserido: R$" << std::fixed << std::setprecision(2) << _valor << std::endl
                  << "Valor do contrato: R$" << std::fixed << std::setprecision(2) << this->valor << std::endl;
    }
};

/**
 *  Verifica se o contrato foi assinado
 *  Status da assinatura do contrato
 */
bool Proposta::contratoAssinado(){
    
    return this->contratoFechado;
};

/**
 *  Verifica o pagamento do contrato
 * Status do pagamento
 */
bool Proposta::pagamentoRecebido(){

    return this->contratoPago;
};

/**
 *  Atribui data de assinatura ao contrato
 *  _dataAssinatura Data que o contrato
 * foi assinado
 */
void Proposta::setDataAssinatura(std::string _dataAssinatura){

    this->dataAssinatura = _dataAssinatura;
}

/**
 *  Calcula previsão de pagamento do contrato;
 * Sempre irá somar 30 dias após a data de assinatura
 *  _dataAssinatura Data que o contrato
 * foi assinado
 */
void Proposta:: setPrevisaoPagamento(std::string _dataAssinatura){
    
    std::vector<int>setData;
    std::string aux1 = _dataAssinatura, aux2;
	char limiter;
	int i = 0;
	
	for(auto it = _dataAssinatura.begin(); it != _dataAssinatura.end(); it++){
	    
	    limiter = *it;
	    
	    if(limiter == '/'){
	        
	        aux2 = aux1.substr(0, i);
	        aux1 = aux1.substr(i+1);
	        setData.push_back(std::stoi(aux2));
	        i = 0;
	        continue;
	    }
	    i += 1;
	}
	
	if(aux1.length() > 0)
	    setData.push_back(std::stoi(aux1));
	  
    struct tm dataAssin = { 0 };
    struct tm aux = { 0 };
    dataAssin.tm_mday = setData[0] + prazoPagamento;
    dataAssin.tm_mon = setData[1] - 1;
    dataAssin.tm_year = setData[2] - 1900;
    
    mktime(&dataAssin);
    
    char cacheData[15];
    char cacheData2[15];
    struct tm* getDataAssin = &dataAssin;
    
    strftime(cacheData, 15, "%d/%m/%Y", getDataAssin);
    
    
    this->previsaoPagamento = cacheData;
};

/**
 *  Atribui data de pagamento ao contrato
 *  _dataPagamento Data que o contrato
 * foi pago
 */
void Proposta::setDataPagamento(std::string _dataPagamento){

    this->dataPagamento = _dataPagamento;
};

/**
 *  Imprime na tela as informações de
 * todas as propostas
 */
void Proposta:: printProposta(){
    
    std::cout << "Proposta N°: " << this->numProposta << std::endl
              << "Nome do cliente: " <<  this->nomeCliente << std::endl
              << "Descrição: " << this->descricao << std::endl
              << "Data de assinatura: " << this->dataAssinatura << std::endl
              << "Previsão data para o pagamento: " << this->previsaoPagamento << std::endl
              << "Data de pagamento: " << this->dataPagamento << std::endl
              << "Valor do contrato: R$" << std::fixed << std::setprecision(2) << this->valor << std::endl
              << "Orçamentista responsável: " << this->orcResponsavel << std::endl;
    if(this->contratoFechado == true)
        std::cout << "Esta proposta é uma ordem de serviço." << std::endl << std::endl;
        
    else
        std::cout << "Esta proposta ainda não é uma ordem de serviço." << std::endl << std::endl;
}

/**
 *  Imprime no arquivo as informações de
 * todas as propostas
 *  out Arquivo texto com todas propostas
 * da empresa
 */
void Proposta:: printArquivo(std::ostream& out){
    
    std::stringstream valorContrato;
    valorContrato << std::fixed << std::setprecision(2) << this->valor;
    
    out << this->numProposta << std::endl
        << this->orcResponsavel << std::endl
        << this->nomeCliente << std::endl
        << this->descricao << std::endl
        << this->dataAssinatura << std::endl
        << this->previsaoPagamento << std::endl
        << valorContrato.str() << std::endl;
}

/**
 *  Lê no arquivo as informações de
 * todas as propostas
 *  in Arquivo texto com todas propostas
 * da empresa
 */
void Proposta:: lerArquivo(std::istream& in){
    
    in >> this->numProposta;
    in.ignore();
    getline(in, this->orcResponsavel);
    getline(in, this->nomeCliente);
    getline(in, this->descricao);
    getline(in, this->dataAssinatura);
    getline(in, this->previsaoPagamento);
    in >> this->valor;
}

/**
 * Sobrecarrega operador << para ler objeto 
 * do tipo Proposta no arquivo texto
 *  out Arquivo texto com todas as propostas
 * da empresa
 *  contrato Proposta que será atribuida
 */
std::ostream& operator<< (std::ostream& out, Proposta& contrato){
    
    contrato.printArquivo(out);
    return out;
}

/**
 *  Sobrecarrega operador >> para enviar 
 * informações do objeto para o arquivo texto 
 *  Arquivo texto com todas as propostas
 * da empresa
 *  contrato Proposta que será atribuida
 */
std::istream& operator>> (std::istream& in, Proposta& contrato){
    
    contrato.lerArquivo(in);
    return in;
}
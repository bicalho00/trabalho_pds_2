# trabalho_pds_2

USER_STORIES:

1-Como gerente de contratos, gostaria de visualizar ou inserir uma determinada
ordem de serviço (OS), para verificar as informações do contrato 
firmado com o cliente, o engenheiro responsável, e registrar os serviços prestados.

  *Critérios de aceitação*:
    -Informar uma breve descrição.
    -Informar engenheiro responsável.
    -Informar o cliente final.
    -Mostrar numeração da nova OS.
    -Exibir erro ao tentar atribuir a OS para um engenheiro com mais de 10 tarefas.


2- Como gerente comercial, gostaria de ver o histórico das propostas feitas e o desempenho 
dos orçamentistas, de forma a saber se eles estão cumprindo suas metas e ter controle 
do que foi enviado para os clientes.

  *Critérios de aceitação*:
    -Mostrar uma breve descrição.
    -Informar a condição de pagamento do serviço (pedida pelo cliente e ofertada).
    -Informar prazo de entrega (pedido pelo cliente e ofertado).
    -Informar revisão que a proposta se encontra.
    
3- Como orçamentista, gostaria de ver meu desempenho, para que 
possa planejar as minhas estratégias futuras.

  *Critérios de aceitação*:
    -Informar meta atual.
    -Mostrar quais propostas viraram OS.
    -Informar quanto falta para atingir a meta
  
4- Como engenheiro, gostaria de visualizar minhas atividades, para 
que possa me organizar.

  *Critérios de aceitação*:
    -Informar atividades pendentes.
    -Mostrar atividades já concluídas.
    -Exibir lista de OS sem designação, para o caso dele querer se autodesignar.

5- Como contador, gostaria de registrar pagamento parcial/total de 
uma OS, para organizar as contas da empresa.

  *Critérios de aceitação*:
    -Após registrar pagamento, retornar quanto falta para que todo valor da OS seja recebido.
    -Exibir erro caso o pagamento registrado seja maior que o valor da OS.
    -Exibir erro ao tentar atribuir pagamento à uma OS que já foi 100% paga.
    
6- Como contador, gostaria de monitorar os clientes e a situação das OS’s, de
forma a ter controle dos pagamentos recebidos.

  *Critérios de aceitação*:
    -Mostrar quanto falta para ser recebido em cada OS.
    -Exibir relação de valor recebido x valor a receber.
    -Mostrar quanto o cliente ainda precisa pagar.
    -Mostrar participação do cliente no total recebido pela empresa.
    -Mostrar quantidade de contratos firmados com o cliente.


O projeto tem como objetivo simular um sistema de gestão financeiro no qual é possível Realizar cadastros de propostas de serviços solicitadas por um cliente, Realizar cadastros de ordens de serviços, após concluir a negociação com
o cliente. Neste caso, a proposta se torna uma nova ordem de serviço, Designar um engenheiro responsável para uma ordem de serviço,
Permitir ao engenheiro visualizar as ordens de serviços a ele atribuídas, visualizar informações pessoais de seu perfil como funcionário, fechar uma ordem de serviço quando concluir um projeto, além de adicionar uma nova ordem de serviço para que ele possa trabalhar, Permitir ao contador da empresa validar o pagamento de uma ordem de serviço, visualizar todas as ordens cadastradas, bem como seus respectivos status de pagamento, alpem de verificar a receita, bruta e pendente da empresa, Permitir ao orçamentista armazenar as propostas feitas por ele, verificar suas informações de funcionário, além de visualizar suas propostas que foram vendidas, ou seja, tiveram a confirmação do cliente para início do projeto. Assim, também consegue visualizar o progresso da meta de vendas a ele atribuída. Da mesma forma, consegue visualizar propostas que ainda não se tornaram contratos. 
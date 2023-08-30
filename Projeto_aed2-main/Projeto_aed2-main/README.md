# Fila de prioridades utilizando Espaçonaves

# Autores
Elias Ósbony e João Edson

# Especificações:

  Implemente um sistema de fila de prioridades das espaçonaves presentes próximas à passagem esperando a sua vez,
além das espaçonaves que chegam a cada instante em fuga. Lembre que apenas uma espaçonave deixa a fila por vez e
esta deve ser a de maior prioridade dentre as em espera. Cada espaçonave deve possuir um valor de prioridade. Além
disso, cada uma possui uma lista de passageiros e uma lista de recursos transportados. Cada passageiro possui nome,
idade, planeta de origem, e um identificador único. Considere estes dados fornecidos pelo sistema de controle da galáxia,
ou seja, cada idade e planeta de origem, assim como o identificador, são tais que toda a galáxia assume o mesmo sistema
de medição para cada tal parâmetro. Assim, planetas distintos levam em conta o mesmo sistema para cálculo de idade e
identificação. Considere também que os símbolos usados são idênticos aos usados na Terra, por onde foi feita o primeiro
contato na ligação com a Via Láctea. A pesquisa em comum dos dois sistemas planetários levou a necessidade de unificação
dos sistemas de representação.

  Implemente também um sistema de controle de verificação dos dados informados pela espaçonave ao ser alocado na
fila de prioridade. Esse sistema verifica se as informações fornecidas são válidas para definição da prioridade. Em caso de
negativa, a prioridade é modificada para o valor correto, sendo necessária a definição de uma nova posição na fila para a
espaçonave. Clandestinos podem ser descobertos, levando também a necessidade de realocação de prioridades, bem como
surgimento de doenças a bordo levando ao aumento de prioridade. Verificou-se que uma média de 10% das espaçonaves
necessitam de alteração de prioridade. Para simplificar o sistema, para cada espaçonave que entra na fila, deve-se atribuir
uma nova prioridade com probabilidade de 10%. O novo valor de prioridade deve ser um número aleatório.
A inserção inicial de dados deve ser feita por meio de leitura de um arquivo, onde a descrição da organização das
informações deve estar no próprio arquivo. Dados podem ser inseridos ou removidos pelo usuário do sistema. Faça uma
tela amigável para a execução dos procedimentos.

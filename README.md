# Casevinheria

![logogs-removebg-preview](https://github.com/Rodrigo-Brasileiro/caseHeinz/assets/126472820/2cd126f6-513e-4762-bfc2-2e14e4d12019)

<h2>Problema:</h2>

<p>A vinheira Agnello tem uma tradição em São Paulo, há mais de 15 anos produzindo vinhos, contudo com a pandemia, deseja migrar parcialmente para o meio virtual, com isso, também deseja automatizar o seu monitoramento de vinhos, nessa caminhada enfrentou alguns problemas, pelos quais, nós, o grupo Tech Pulse Global Network, fomos contratados. Nós somos os encarregados de solucionar problemas relacionados as condições de armazenamento dos vinhos, isso inclui questões como: luminosidade, temperatura e umidade da vinheira Agnello, visto que a qualidade dos vinhos é diretamente influenciada por tais circunstâncias. Eles precisavam de um sistema de monitoramento utilizando ESP32, para que enviasse dados a nuvem, além de exibir o resultado dos sensores em uma tela LCD, dado isso, a solução precisa ser instalada no mesmo ambiente no qual os vinhos são armazenados.</p>

<h2>Solução:</h2>
  
  <p>Desse modo, a fim de solucionar a problemática realizamos uma estrutura que por meio de sensores de luminosidade(LDR) e sensor de umidade e temperatura (DHT11), consigam medir continuamente o estado do ambiente em que se encontram os vinhos e consigam avisar e transmitir os dados, isso pode acontecer de duas formas. A primeira é por meio de LEDs, sendo o LED Verde para tudo dentro dos padrões, LED amarelo como fora dos padrões, sendo o primeiro nível de alerta, mas sem muito risco e o segundo nível de alerta com LED vermelho realmente perigoso para os vinhos, em qualquer nível de alerta tocará um buzzer continuamente até o problema ser resolvido e em todos os níveis é mostrado a luminosidade, temperatura e umidade na tela lcd de 5 em 5 segundos. A segunda maneira utiliza o Wi-FI do microncontrolador ESP 32, o qual por meio de um processo chamado Message Queuing Telemetry Transport(MQTT), que é um protocolo de comunicação leve e eficiente projetado para troca de mensagens em redes com largura de banda limitada ao Fiware(plataforma que receberá os dados), consegue receber todos os dados sobre luminosidade, umidade e temperatura e assim, o resposável consegue tomar uma providência sobre a questão.</p>
<p>PS:A solução, pode ser aplicada de dois modos, utilizando o microcontrolador ESP32 e Arduino uno R3. A única diferença é que o ESP 32 tem capacidade de wifi e bluetooth, assim, podendo ser integrado a rede do local e subir dados a nuvem.</p>

<h2>Componentes:</h2>
<p>Para implementar a solução você precisará dos seguintes componentes que estão distribuídos em duas etapas, são elas a etapa física e virtual. Para a etapa física, será necessário::</p>
   <li>Microcontrolador ESP32 ou arduino uno R3;</li>
 <li>LED vermelho, verde e amarelo;</li>
 <li>Buzzer;</li>
 <li>Diversos jumpers (macho-macho, macho-fêmea e fêmea-fêmea);</li>
 <li>Sensor DHT;</li>
 <li>Sensor LDR;</li>
 <li>Display lcd (16x2);</li>
 <li>6 resistores(5 de 220 e um de mil ohm);</li>
 <li>Fio para conectar o ESP32.</li>
 <p>Após ter os componentes, se optar por utilizar o arduino UNO, basta seguir os passos de montagem iguais ao tinkercad, clicando<a href="https://www.tinkercad.com/things/6o91AvSQkax"> aqui</a>, entretanto, pela ausência do sensor DHT11 na plataforma, é preciso utilizar a montagem de um site externo, clicando <a href="https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-umidade-e-temperatura-dht11">aqui</a>, você tem acesso a diversas informações sobre o sensor e como baixar e configurar sua biblioteca externa no IDE do Arduino.</p>
 
  <p>Ao optar por utilizar o microcontrolador ESP32, é necessário seguir alguns passos para configuração da sua plataforma de armazenamento e tratamento de dados. </p>
   <p> A segunda etapa é após o microcontrolador enviar os dados via MQTT, para essa etapa, utilizamos uma plataforma chamada fiware.</p>
   <p>Primeiramente, para a utilização desse software, é necessário alguns pré-requisitos, o primeiro é uma máquina virtual VirtualMachine(VM), a qual simulará um sistema Linux, nesse caso o Ubuntu. Dentro da máquina, realiza-se a instalação de ferramentas que facilitam criação, o gerenciamento e a execução de contêineres de aplicativos que serão usados nessa parte do projeto, por último realiza-se a instação do Fiware, agora mais profundamente, é uma plataforma aberta de código destinados a operação como back-end, com o intuito de facilitar as aplicações para smart cities(cidades inteligentes), Inthernet of Things(IoT ou internet das coisas) e sistemas baseados em dados contextuas em tempo real, tudo que condiz com o propósito da solução.Essa plataforma fornece um conjunto APIs (Interfaces de Programação de Aplicativos) e ferramentas que simplificam a criação de soluções inovadoras para melhorar a qualidade de vida nas cidades e impulsiona a transformação digital em diversos setores. </p>

  <h3>Instação da máquina virtual</h3>
    <p>A princípio, os requisitos de hardware para essa etapa são:</p>

   <ol>Núcleos de Processamento - **1vCPU**</ol>
   <ol>Memória RAM - **1GB** </ol>
   <ol>Armazenamento Secundário Mínimo - **20GB HD e/ou SSD**</ol>
     <p>Tendo essa etapa concluída, primeiro passo é entrar nesse <a href="https://www.virtualbox.org">site</a> e clicar no botão download para fazer a instação da máquina virtual, no nosso caso a VirtualBox. O próximo é instalar o programa que usaremos, nessa situação, o Ubuntu versão 22.04lts, nesse <a href="https://ubuntu.com/download/server">site</a>. O terceiro passo é criar e configurar a máquina, basta clicar no botão "novo" dentro do VirtualBox, em sequência dê o nome "ubuntu" a sua máquina, e clique em próximo até finalizar. Finalizado, marque a máquina criada e selecione a opção "configurações", nesse momento vá em armazenamento e do lado direito estará uma aba para adicionar o arquivo ubuntu que você baixou, após isso só iniciar a máquina e realizar as configuralções iniciais de usuário.</p>
  <h4>Inicialização</h4>
    <p>A primeira etapa após abrir o sistema Linux é abrir o terminal, feito isso, é preciso fazer a instalação de uma ferramenta chamada docker compose que faciliata a criação, gerenciamento e execução de contêiners de aplicativos, para isso, clique <a href="https://docs.docker.com/engine/install/ubuntu/"> aqui</a> e siga as instruções. Conluída essa etapa, seguimos para a instalação e inicialização do Fiware, faça esses comandos no terminal:</p>
      <ol> git clone https://github.com/Rodrigo-Brasileiro/Sprint3edge - para copiar todos os arquivos disponíveis nesse repositório </ol>
      <ol> cd fiware - para entrar na pasta fiware </ol>
      <ol> docker compose up -d - para abrir as portas do fiware </ol>
    <p>Nesse instante, vamos verificar se está tudo correto com as portas abertas, para isso, vamos no site <a href="https://www.postman.com">postman</a> que é site de suporte de API que usaremos como comunicador e receptor de respostas do ESP32, crie uma conta e um "my workspace", jogue os arquivos do repositório desse github, vá na pasta 1.1, crie uma variável chamada url com seu enderço de IP e clique em send, com a resposta OK, a porta está saúdavel.</p>
    <p> Agora, basta testar o programa enviando e solicitando informações com as portas 17 e 18. Quando finalizar o programa, para fechar as portas, basta escrever o comando: docker compose down</p>

  <h3>Componentes Complementares</h3>
   <p>A plataforma do Fiware conta com componentes complementares que vale a pena serem comentados, são eles:</p>
  <h4>Orion Context Broker </h4>
  
  <p>Orion Context Broker é responsável gestão de contextos, que envolve a coleta, armazenamento e disponibilização de informações contextuais relevantes, como dados de sensores, informações de localização e estados de dispositivos, ou seja, útil para gestão das tagid. </p>
  
  <h4>MongoDB</h4>
  
  <p>O MongoDB é um sistema de banco de dados NoSQL usado na plataforma FIWARE para armazenar dados contextuais provenientes do Orion Context Broker e de outros componentes. Ele suporta documentos JSON flexíveis, possui recursos avançados para consultas e escalabilidade horizontal, tornando-o adequado para lidar com grandes volumes de dados na plataforma FIWARE.</p>
  
   <h4>Eclipse-Mosquitto</h4>
   
   <p>O Eclipse Mosquitto é um broker MQTT usado na plataforma FIWARE para facilitar a troca de mensagens entre dispositivos IoT e outros componentes. Ele suporta recursos de autenticação, segurança e controle de acesso, fornecendo uma solução escalável e configurável para a comunicação MQTT na plataforma FIWARE. Os dados são armazenados no tópico TEF (Telemetria e Monitoramento de Equipamentos).</p>
  
<p>Efetuada a montagem, utilize o código disponiblizado, coloque-o no app do arduino e o passe para o microcontrolador, depois só desfrutar.</p>
  
  <h4>STH-Comet</h4>
  <p>O STH-Comet é um componente da plataforma FIWARE que lida com o armazenamento histórico de dados contextuais em larga escala. Ele trabalha em conjunto com o Orion Context Broker para capturar, armazenar e consultar dados históricos. O STH-Comet oferece recursos avançados, como armazenamento eficiente em série temporal, consultas de agregação e consultas de séries temporais. Ele fornece uma API RESTful para interação e permite que os desenvolvedores acessem e analisem dados históricos de forma eficiente. Em resumo, o STH-Comet facilita o armazenamento e consulta de dados contextuais históricos na plataforma FIWARE.</p>
  <p>Curiosidade interessante é que por meio da linguagem python e utilizando a biblioteca Matplotlib é possível gerar gráficos temporais sobre os dados solicitados pelo postman, nesse caso, são dados da luminosidade de 15 minutos do dia 21 de setembro de 2023: </p>
<img src="https://github.com/Rodrigo-Brasileiro/Casevinheria/blob/main/gráfico_de_luminosidade.png" />
<p>Clique <a href="https://colab.research.google.com/drive/1I6ar-LVDiyiXknS___Rxv5jnVItatHoP?usp=sharing">aqui</a> para acessar a código em Python que gera gráficos com o STH-Comet.</p>

<h2>Arquitetura da solução:</h2>
<img src="https://github.com/Rodrigo-Brasileiro/Casevinheria/main/arquitetura_vinheria.png"/>

<h2>Tecnologia usada:</h2>
Para experimentos virtuais usamos o Tinkercad com a linguagem C++.
Link da Simulação Público Tinkercad:
https://www.tinkercad.com/things/6o91AvSQkax

Para a utilização do DHT11, utilizamos uma biblioteca externa do site:
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-umidade-e-temperatura-dht11 

PS:Lembrando que o sensor DHT 11 não está disponível no tinkercad.

<h2>Referências</h2>
 <p>Buscando mais informações e aprimoramento, nossas referências foram:</p>
     <ol><li>Link: https://github.com/fabiocabrini/fiware</li>
         <li>Link: https://www.youtube.com/watch?v=nyWI3xl_LUA </li>
         <li>Link: https://www.youtube.com/watch?v=-djV2392b-s </li>
        <li> Link: https://fiware-sth-comet.readthedocs.io/en/latest/</li>
       <li> Link: https://fiwaretourguide.readthedocs.io/en/latest/core/sth-comet/how-to-generate-the-history-of-Context-Information-using-STH-Comet/</li>
     </ol>

<h2>Obrigado por ler</h2>
<h2> Fotos do nosso projeto</h2>
![image](https://user-images.githubusercontent.com/126472820/236555851-5e7293f3-6dc6-47d6-b66b-c7c3cfdbc2cf.png)
![image](https://user-images.githubusercontent.com/126472820/236555931-ad88ca9a-4666-4caa-884f-d48978da8d6a.png)
![image](https://user-images.githubusercontent.com/126472820/236556103-d687e08c-e21a-4d8d-92c3-b35c585c93be.png)





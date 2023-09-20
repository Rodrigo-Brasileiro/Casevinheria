# Casevinheria

![logogs-removebg-preview](https://github.com/Rodrigo-Brasileiro/caseHeinz/assets/126472820/2cd126f6-513e-4762-bfc2-2e14e4d12019)

<h2>Problema:</h2>

<p>A vinheira Agnello tem uma tradição em São Paulo, há mais de 15 anos produzindo vinhos, contudo com a pandemia, deseja migrar parcialmente para o meio virtual, com isso, também deseja automatizar o seu monitoramento de vinhos, nessa caminhada enfrentou alguns problemas, pelos quais, nós, o grupo Tech Pulse Global Network, fomos contratados. Nós somos os encarregados de solucionar problemas relacionados as condições de armazenamento dos vinhos, isso inclui questões como: luminosidade, temperatura e umidade da vinheira Agnello, visto que a qualidade dos vinhos é diretamente influenciada por tais circunstâncias. Eles precisavam de um sistema de monitoramento utilizando ESP32 e mostrando o resultado dos sensores em uma tela LCD e os guarde em um sistema de nuvem, dado isso, a solução precisa ser instalada no mesmo ambiente no qual os vinhos são armazenados.</p>

<h2>Solução:</h2>
  
  <p>Para solucionar o problema, fizemos um sensor de luminosidade, o qual contém as seguintes características:</p>>
  <li>LDR (mede a luminosidade do local);</li>
  <li>A intensidade luminosa estando entre 70 a 100, acenderá um LED verde, indicando que a luminosidade está OK;</li>
  <li>Em seu primeiro nível de alerta, ele acenderá um LED amarelo, com luminosidade que pode variar entre 20 a 50, agregado a um buzzer;</li>
  <li>Já o segundo nível de alerta, ele acenderá um LED vermelho, além de acionar um buzzer;</li>
  <p>Já para conseguir lidar com a questão da temperatura e umidade usamos:</p>
  <li>Sensor de umidade e temperatura (DHT11);</li>
  <li>Enquanto a umidade estiver fora da faixa ideal, o LED Vermelho deve ficar aceso e o Buzzer deve ligar continuamente;</li>
  <li>Enquanto a temperatura estiver fora da faixa ideal, o LED Amarelo deve ficar aceso e o Buzzer deve ligar continuamente;</li>
  <li>Em todos os níveis é mostrado a luminosidade, temperatura e umidade na tela lcd de 5 em 5 segundos.</li>

<h2>Como fazer:</h2>
<h3> Para verificação do trabalho, montamos o equipamento na bancada, com os seguintes componentes:<h3>
 <ol>-Arduino uno;</ol>
 <ol>-LED vermelho, verde e amarelo;</ol>
 <ol>-Buzzer;</ol>
 <ol>-Diversos jumpers (macho-macho, macho-fêmea e fêmea-fêmea);</ol>
 <ol>-Sensor DHT;</ol>
 <ol>-Sensor LDR;</ol>
 <ol>-Display lcd (16x2);</ol>
 <ol>-6 resistores.</ol>
 <ol>-Fio para conectar no arduino</ol>
 <h3>Após ter os componentes, basta seguir os passos de montagem iguais aos do tinkercad e o DHT11, iguais ao link do sensor, não esquecendo de baixar e configurar a    biblioteca externa dele.</h3>
<h3>Efetuada a montagem, utilize o código disponiblizado, coloque-o no app do arduino e o passe para o microcontrolador, depois só desfrutar.

<h2>Tecnologia usada:</h2>
Para experimentos virtuais usamos o Tinkercad com a linguagem C++.
Link da Simulação Público Tinkercad:
https://www.tinkercad.com/things/6o91AvSQkax

Para a utilização do DHT11, utilizamos uma biblioteca externa do site:
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-umidade-e-temperatura-dht11 

PS:Lembrando que o sensor DHT 11 não está disponível no tinkercad.

<h2>Obrigado por ler</h2>
<h2> Fotos do nosso projeto</h2>
![image](https://user-images.githubusercontent.com/126472820/236555851-5e7293f3-6dc6-47d6-b66b-c7c3cfdbc2cf.png)
![image](https://user-images.githubusercontent.com/126472820/236555931-ad88ca9a-4666-4caa-884f-d48978da8d6a.png)
![image](https://user-images.githubusercontent.com/126472820/236556103-d687e08c-e21a-4d8d-92c3-b35c585c93be.png)





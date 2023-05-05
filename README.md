# Casevinheria

##Problema:
A vinheira Agnello tem uma tradição em São Paulo, há mais de 15 anos produzindo vinhos, contudo com a pandemia, deseja migrar parcialmente para o meio virtual, com isso, também deseja automatizar o seu monitoramento de vinhos, nessa caminhada enfrentou alguns problemas, pelos quais, nós, o grupo SmartDevelopment, fomos contratados. Nós somos os encarregados de solucionar problemas relacionados as condições de armazenamento dos vinhos, isso inclui questões como: luminosidade, temperatura e umidade da vinheira Agnello, visto que a qualidade dos vinhos é diretamente influenciada por tais circunstâncias. Eles precisavam de um sistema de monitoramento utilizando um Arduino e mostrando o resultado dos sensores em uma tela LCD, assim precisando ser instalado no ambiente em que os vinhos são guardados.

##Solução:
Para solucionar o problema, fizemos um sensor de luminosidade, o qual contém as seguintes características: 
1-LDR (mede a luminosidade do local);
1.1-A intensidade luminosa estando entre 70 a 100, acenderá um LED verde, indicando que a luminosidade está OK;
1.2-Em seu primeiro nível de alerta, ele acenderá um LED amarelo, com luminosidade que pode variar entre20 a 50, além de soar um buzzer;
1.3-Já o segundo nível de alerta, ele acenderá um LED vermelho, além de acionar um buzzer;
2-Sensor de umidade e temperatura (DHT11);
2.1-Enquanto a umidade estiver fora da faixa ideal, o LED Vermelho deve ficar aceso e o Buzzer deve ligar continuamente;
2.2-Enquanto a temperatura estiver fora da faixa ideal, o LED Amarelo deve ficar aceso e o Buzzer deve ligar continuamente;
Em todos os níveis é mostrado a luminosidade, temperatura e umidade na tela lcd de 5 em 5 segundos.

##Componentes:
Para verificação do trabalho, montamos o equipamento na bancada, com os seguintes componentes:
-Arduino uno;
-LED vermelho, verde e amarelo;
-Buzzer;
-Diversos jumpers (macho-macho, macho-fêmea e fêmea-fêmea);
-Sensor DHT;
-Sensor LDR;
-Display lcd (16x2);
-6 resistores.

##Tecnologia usada:
Para experimentos virtuais usamos o Tinkercad com a linguagem C++.
Link da Simulação Público Tinkercad:
https://www.tinkercad.com/things/6o91AvSQkax

Para a utilização do DHT11, utilizamos uma biblioteca externa do site:
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-umidade-e-temperatura-dht11 

##Como fazer:
Para fazer você precisará dos seguintes componentes
-Arduino uno;
-LED vermelho, verde e amarelo;
-Buzzer;
-Diversos jumpers (macho-macho, macho-fêmea e fêmea-fêmea);
-Sensor DHT;
-Sensor LDR;
-Display lcd (16x2);
- 6 resistores.


PS:Lembrando que o sensor DHT 11 não está disponível no tinkercad.

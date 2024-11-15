i)        Uma breve descrição do funcionamento e uso para quem quiser reproduzir.
Este trabalho se concentra no desenvolvimento de um sistema IoT específico para monitoramento de níveis de ruído em máquinas industriais. 
Utilizando um sensor de som integrado ao Arduino, o projeto visa avaliar se o nível de ruído de uma máquina ultrapassa o limite definido.
Caso o ruído exceda o padrão aceitável, o sistema dispara uma medida de segurança automaticamente para evitar danos e possíveis acidentes. 
Se o nível de som estiver dentro dos parâmetros normais, a operação da máquina continua sem interrupções.
Nos resultados obtidos no projeto, conseguimos simular o funcionamento do sensor de som/ruidos utilizando uma caixa de som, de forma a simular o ambiente de uma indústria onde uma máquina produz um som alto.
O sensor de som foi capaz de captar o aumento no nível de som, exibindo no Adafruit o valor detectado junto com a mensagem “Som excessivo!”, essa notificação também foi enviada para o aplicativo MQTT-IOT no celular

ii)       O software desenvolvido e a documentação de código.
A documentaçao do codigo esta no arquivo "SensorDeSom.ino". O software utilizado foi o Arduino.

iii)      A descrição do hardware utilizado (plataformas de desenvolvimento, sensores, atuadores, impressão 3D de peças, medidas de peças e caixas etc.)

A plataforma de desenvolvimento utilizada foi o Arduino, utilizamos o borker Adafruit via protocolo MQTT-IOT
Programação do ESP8266: O código do Arduino será desenvolvido para ler os dados do sensor de som. 
Quando o nível de som exceder um limite predefinido, o ESP8266 acionará o LED vermelho e enviará os dados para o broker “Adafruit” via protocolo MQTT. 
Este broker é responsável por gerenciar a comunicação entre dispositivos e permite que os dados sejam visualizados em uma interface gráfica.
Configuração do Broker MQTT: O broker “Adafruit” via protocolo MQTT será configurado para receber os dados do ESP8266. 
Isso pode ser feito utilizando serviços na nuvem ou um servidor local. 
Visualização dos Dados: A interface de visualização será desenvolvida para permitir que os usuários monitorem os níveis de som em tempo real. 
Utilizaremos o dashboard do Adafruit podendo incluir gráficos, alertas e outras funcionalidades úteis para a análise de dados

iv)      A documentação das interfaces, protocolos e módulos de comunicação.
Para as interfaces utilizamos o Adafruit onde vizualizamos o nivel de som e o alerta quando o som passa a ser excessivo. Além disso é possivel vizualizar o historico do aumento do som.

v)       O projeto deve possuir comunicação/controle via internet (TCP/IP) e uso do Protocolo MQTT.
O projeto utiliza comunicaçao via internet e o uso do protocolo MQTT.




// Fonte: https://www.makerhero.com/blog/termistor-ntc-arduino/
/*
 * Leitura de temperatura usando um termistor
 */
 
// Conexão do termistor
const int pinTermistor = A0;
 
// Parâmetros do termistor
const double beta = 3950.0;
const double r0 = 10000.0;
const double t0 = 273.0 + 25.0;
const double rx = r0 * exp(-beta/t0);
 
// Parâmetros do circuito
const double vcc = 4.92;
const double R = 9810.0;
 
// Numero de amostras na leitura
const int nAmostras = 5;
 
// Iniciação
void setup() {
  Serial.begin(9600);
}
 
// Laço perpétuo
void loop() {
  // Le o sensor algumas vezes
  int soma = 0;
  for (int i = 0; i < nAmostras; i++) {
    soma += analogRead(pinTermistor);
    delay (100);
  }
 
  // Determina a resistência do termistor
  double v = (vcc*soma)/(nAmostras*1024.0);
  double rt = (vcc*R)/v - R;
 
  // Calcula a temperatura
  double t = beta / log(rt/rx);
  Serial.println (t-273.0);
 
  // Dá um tempo entre leituras
  delay (1000);
}
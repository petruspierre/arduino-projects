// Interação Arduino com Motor de Passo
// Fazedores.com
#include <Stepper.h> // Incluindo a biblioteca do Motor de Passo
 
const int stepsPerRevolution = 65; // Numero de passo por volta
 
Stepper myStepper(stepsPerRevolution, 8,9,10,11); // Faz a inicialização da Biblioteca usando as portas 8,9,10,11
// setup (executado apenas uma vez)
void setup() {
        myStepper.setSpeed(300); // velocidade do motor definida em 300
}
// laço principal (executado indefinidamente)
void loop() {
  // Estrutura de repetição usada para limitar o tempo que o motor vai girar no sentido anti-horário       
  for (int i = 0; i < 50; i++){
                 myStepper.step(stepsPerRevolution); // sentido anti-horario
                
        }
   // Estrutura de repetição usada para limitar o tempo que o motor vai girar no sentido horário             
  for (int i = 0; i < 50; i++){
                myStepper.step(-stepsPerRevolution); // sentido horario
                
       }
}

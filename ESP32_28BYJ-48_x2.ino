// para hacer girar 2 steppers 28BYJ-48 en forma simultanea

#include <Stepper.h>

// Definición de los pines de control para el primer motor
#define IN1_MOTOR1 19
#define IN2_MOTOR1 18
#define IN3_MOTOR1 5
#define IN4_MOTOR1 17

// Definición de los pines de control para el segundo motor
#define IN1_MOTOR2 12
#define IN2_MOTOR2 14
#define IN3_MOTOR2 27
#define IN4_MOTOR2 26

// Definición de la cantidad de pasos por revolución para cada motor
const int stepsPerRevolution = 2048;

// Crear instancias de los motores
Stepper motor1(stepsPerRevolution, IN1_MOTOR1, IN3_MOTOR1, IN2_MOTOR1, IN4_MOTOR1);
Stepper motor2(stepsPerRevolution, IN1_MOTOR2, IN3_MOTOR2, IN2_MOTOR2, IN4_MOTOR2);

// Variables para el control de los temporizadores
unsigned long tiempoMotor1 = 0;
unsigned long tiempoMotor2 = 0;
const unsigned long intervalo = 5; // Intervalo de tiempo entre pasos (en milisegundos) da la velocidad de giro

void setup() {
  // Establecer la velocidad para cada motor (en rpm)
  motor1.setSpeed(10);
  motor2.setSpeed(10);
}

void loop() {
  // Obtener el tiempo actual
  unsigned long tiempoActual = millis();

  // Verificar si ha pasado el tiempo suficiente para dar otro paso para el motor 1
  if (tiempoActual - tiempoMotor1 >= intervalo) {
    // Dar un paso al motor 1
    motor1.step(1);  // valor positivo gira en un sentido, negativo en el otro
    
    // Actualizar el tiempo del motor 1
    tiempoMotor1 = tiempoActual;
  }

  // Verificar si ha pasado el tiempo suficiente para dar otro paso para el motor 2
  if (tiempoActual - tiempoMotor2 >= intervalo) {
    // Dar un paso al motor 2
    motor2.step(1);
    
    // Actualizar el tiempo del motor 2
    tiempoMotor2 = tiempoActual;
  }
}

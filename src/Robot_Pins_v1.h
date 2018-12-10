#ifndef RobotPins_h
#define RobotPins_h


/* QTR-8RC Reflectance Sensor Array Pins (https://www.pololu.com/product/961)
 * Below shows how the line sensor pins are mapped to the MSP-EXP432P401R */
#define LS_PIN_IR	61 // <- Energia Pin #   Launchpad Pin -> P5.3
#define LS_PIN_1	65 // <- Energia Pin #   Launchpad Pin -> P7.0
#define LS_PIN_2	48 // <- Energia Pin #   Launchpad Pin -> P7.1
#define LS_PIN_3	64 // <- Energia Pin #   Launchpad Pin -> P7.2
#define LS_PIN_4	47 // <- Energia Pin #   Launchpad Pin -> P7.3
#define LS_PIN_5	52 // <- Energia Pin #   Launchpad Pin -> P7.4
#define LS_PIN_6	68 // <- Energia Pin #   Launchpad Pin -> P7.5
#define LS_PIN_7	53 // <- Energia Pin #   Launchpad Pin -> P7.6
#define LS_PIN_8	69 // <- Energia Pin #   Launchpad Pin -> P7.7

/* Pololu Snap-Action Switches (https://www.pololu.com/product/1404)
 * Robot utilizes 6 of these switches.
 * Switches' common pin is connected to ground.
 * NO (normally open) is connected to Launchpad
 */
#define BSW_PIN_1 51 // <- Energia Pin #   Launchpad Pin -> P8.0
#define BSW_PIN_2 60 // <- Energia Pin #   Launchpad Pin -> P8.3
#define BSW_PIN_3 43 // <- Energia Pin #   Launchpad Pin -> P8.4
#define BSW_PIN_4 41 // <- Energia Pin #   Launchpad Pin -> P8.5
#define BSW_PIN_5 57 // <- Energia Pin #   Launchpad Pin -> P8.6
#define BSW_PIN_6 58 // <- Energia Pin #   Launchpad Pin -> P8.7

/* Motor Driver and Power Distribution Board (https://www.pololu.com/product/3543)
 * Pin configuration for the left and right motor's sleep, direction and pwm pin
 */
#define MOTOR_L_SLP_PIN 24  // <- Energia Pin #   Launchpad Pin -> P4.0
#define MOTOR_L_DIR_PIN 25  // <- Energia Pin #   Launchpad Pin -> P4.2
#define MOTOR_L_PWM_PIN 11  // <- Energia Pin #   Launchpad Pin -> P3.6
#define MOTOR_R_SLP_PIN 26  // <- Energia Pin #   Launchpad Pin -> P4.4
#define MOTOR_R_DIR_PIN 27  // <- Energia Pin #   Launchpad Pin -> P4.5
#define MOTOR_R_PWM_PIN 35  // <- Energia Pin #   Launchpad Pin -> P6.4

/* Sharp GP2Y0A21YK0F Analog Distance Sensor (https://www.pololu.com/product/136)
 * Robot utilizes three of these sensors
 */
#define DIST_L_PIN 59 // <- Energia Pin #   Launchpad Pin -> P9.1
#define DIST_C_PIN 23 // <- Energia Pin #   Launchpad Pin -> P6.1
#define DIST_R_PIN 42 // <- Energia Pin #   Launchpad Pin -> P9.0

/* Romi Encoder Pair Kit, 12 CPR, 3.5-18V (https://www.pololu.com/product/3542)
 * Robot utilizes two encoders. One for the left wheel and one for the right wheel
 */
#define ENCODER_ERA_PIN 10 // <- Energia Pin #   Launchpad Pin -> P6.4
#define ENCODER_ERB_PIN 30 // <- Energia Pin #   Launchpad Pin -> P5.5
#define ENCODER_ELA_PIN 17 // <- Energia Pin #   Launchpad Pin -> P5.7
#define ENCODER_ELB_PIN 38 // <- Energia Pin #   Launchpad Pin -> P2.4

#endif
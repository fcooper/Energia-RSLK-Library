/** @file */

#ifndef RSLKPins_h
#define RSLKPins_h

#if defined(USING_RSLK_CLASSIC)
	/* QTR-8RC Reflectance Sensor Array Pins (https://www.pololu.com/product/961)
	 * Below shows how the line sensor pins are mapped to the MSP-EXP432P401R */

	#define TOTAL_LINE_SENSORS    8
	#define QTR_EMITTER_PIN       61 // <- Energia Pin #   Launchpad Pin -> P5.3
	#define QTR_0                 65 // <- Energia Pin #   Launchpad Pin -> P7.0
	#define QTR_1                 48 // <- Energia Pin #   Launchpad Pin -> P7.1
	#define QTR_2                 64 // <- Energia Pin #   Launchpad Pin -> P7.2
	#define QTR_3                 47 // <- Energia Pin #   Launchpad Pin -> P7.3
	#define QTR_4                 52 // <- Energia Pin #   Launchpad Pin -> P7.4
	#define QTR_5                 68 // <- Energia Pin #   Launchpad Pin -> P7.5
	#define QTR_6                 53 // <- Energia Pin #   Launchpad Pin -> P7.6
	#define QTR_7                 69 // <- Energia Pin #   Launchpad Pin -> P7.7

	/* Pololu Snap-Action Switches (https://www.pololu.com/product/1404)
	 * Robot utilizes 6 of these switches.
	 * Switches' common pin is connected to ground.
	 * NO (normally open) is connected to Launchpad
	 */
	#define TOTAL_BP_SWITCHES     6
	#define BP_SW_PIN_0           51 // <- Energia Pin #   Launchpad Pin -> P8.0
	#define BP_SW_PIN_1           60 // <- Energia Pin #   Launchpad Pin -> P8.3
	#define BP_SW_PIN_2           43 // <- Energia Pin #   Launchpad Pin -> P8.4
	#define BP_SW_PIN_3           41 // <- Energia Pin #   Launchpad Pin -> P8.5
	#define BP_SW_PIN_4           57 // <- Energia Pin #   Launchpad Pin -> P8.6
	#define BP_SW_PIN_5           58 // <- Energia Pin #   Launchpad Pin -> P8.7

	/* Motor Driver and Power Distribution Board (https://www.pololu.com/product/3543)
	 * Pin configuration for the left and right motor's sleep, direction and pwm pin
	 */
	#define MOTOR_L_SLP_PIN       24  // <- Energia Pin #   Launchpad Pin -> P4.0
	#define MOTOR_L_DIR_PIN       25  // <- Energia Pin #   Launchpad Pin -> P4.2
	#define MOTOR_L_PWM_PIN       11  // <- Energia Pin #   Launchpad Pin -> P3.6
	#define MOTOR_R_SLP_PIN       26  // <- Energia Pin #   Launchpad Pin -> P4.4
	#define MOTOR_R_DIR_PIN       27  // <- Energia Pin #   Launchpad Pin -> P4.5
	#define MOTOR_R_PWM_PIN       35  // <- Energia Pin #   Launchpad Pin -> P6.4

	/* Sharp GP2Y0A21YK0F Analog Distance Sensor (https://www.pololu.com/product/136)
	 * Robot utilizes three of these sensors
	 */
	#define SHRP_DIST_L_PIN       59 // <- Energia Pin #   Launchpad Pin -> P9.1
	#define SHRP_DIST_C_PIN       23 // <- Energia Pin #   Launchpad Pin -> P6.1
	#define SHRP_DIST_R_PIN       42 // <- Energia Pin #   Launchpad Pin -> P9.0

	/* Romi Encoder Pair Kit, 12 CPR, 3.5-18V (https://www.pololu.com/product/3542)
	 * Robot utilizes two encoders. One for the left wheel and one for the right wheel
	 */
	#define ENCODER_ERA_PIN       10 // <- Energia Pin #   Launchpad Pin -> P6.4
	#define ENCODER_ERB_PIN       30 // <- Energia Pin #   Launchpad Pin -> P5.5
	#define ENCODER_ELA_PIN       17 // <- Energia Pin #   Launchpad Pin -> P5.7
	#define ENCODER_ELB_PIN       38 // <- Energia Pin #   Launchpad Pin -> P2.4

#else
	/* QTR-8RC Reflectance Sensor Array Pins (https://www.pololu.com/product/961)
	 * Below shows how the line sensor pins are mapped to the MSP-EXP432P401R
	 */
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.0
	 */
	#define QTR_0                 65	// <- Energia Pin #   Launchpad Pin -> P7.0
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.1
	 */
	#define QTR_1                 48	// <- Energia Pin #   Launchpad Pin -> P7.1
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.2
	 */
	#define QTR_2                 64	// <- Energia Pin #   Launchpad Pin -> P7.2
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.3
	 */
	#define QTR_3                 47	// <- Energia Pin #   Launchpad Pin -> P7.3
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.4
	 */
	#define QTR_4                 52	// <- Energia Pin #   Launchpad Pin -> P7.4
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.5
	 */
	#define QTR_5                 68	// <- Energia Pin #   Launchpad Pin -> P7.5
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.6
	 */
	#define QTR_6                 53	// <- Energia Pin #   Launchpad Pin -> P7.6
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P7.7
	 */
	#define QTR_7                 69	// <- Energia Pin #   Launchpad Pin -> P7.7
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P5.3
	 */
	#define QTR_EMITTER_PIN_EVEN  61	// <- Energia Pin #   Launchpad Pin -> P5.3
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.2
	 */
	#define QTR_EMITTER_PIN_ODD   45	// <- Energia Pin #   Launchpad Pin -> P9.2

	/* Pololu Snap-Action Switches (https://www.pololu.com/product/1404)
	 * Robot utilizes 6 of these switches.
	 * Switches' common pin is connected to ground.
	 * NO (normally open) is connected to Launchpad
	 */
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P4.0
	 */
	#define BP_SW_PIN_0           24  //    <- Energia Pin #   Launchpad Pin -> P4.0
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P4.2
	 */
	#define BP_SW_PIN_1           25  //    <- Energia Pin #   Launchpad Pin -> P4.2
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P4.3
	 */
	#define BP_SW_PIN_2           6   //    <- Energia Pin #   Launchpad Pin -> P4.3
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P4.5
	 */
	#define BP_SW_PIN_3           27  //    <- Energia Pin #   Launchpad Pin -> P4.5
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P4.6
	 */
	#define BP_SW_PIN_4           8   //    <- Energia Pin #   Launchpad Pin -> P4.6

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P4.7
	 */
	#define BP_SW_PIN_5           28  //    <- Energia Pin #   Launchpad Pin -> P4.7

	/* Motor Driver and Power Distribution Board (https://www.pololu.com/product/3543)
	 * Pin configuration for the left and right motor's sleep, direction and pwm pin
	 */

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P3.7
	 */
	#define MOTOR_L_SLP_PIN       31	//  <- Energia Pin #   Launchpad Pin -> P3.7

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P5.4
	 */
	#define MOTOR_L_DIR_PIN       29	//  <- Energia Pin #   Launchpad Pin -> P5.4

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P2.7
	 */
	#define MOTOR_L_PWM_PIN       40	//  <- Energia Pin #   Launchpad Pin -> P2.7

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P3.6
	 */
	#define MOTOR_R_SLP_PIN       11	//  <- Energia Pin #   Launchpad Pin -> P3.6
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P5.5
	 */
	#define MOTOR_R_DIR_PIN       30	//  <- Energia Pin #   Launchpad Pin -> P5.5

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P2.6
	 */
	#define MOTOR_R_PWM_PIN       39	//  <- Energia Pin #   Launchpad Pin -> P.2.6

	/* Sharp GP2Y0A21YK0F Analog Distance Sensor (https://www.pololu.com/product/136)
	 * Robot utilizes three of these sensors
	 */

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.1
	 */
	#define SHRP_DIST_L_PIN       59	//  <- Energia Pin #   Launchpad Pin -> P9.1
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P6.1
	 */
	#define SHRP_DIST_C_PIN       23	//  <- Energia Pin #   Launchpad Pin -> P6.1
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.0
	 */
	#define SHRP_DIST_R_PIN       42	//  <- Energia Pin #   Launchpad Pin -> P9.0

	/* Romi Encoder Pair Kit, 12 CPR, 3.5-18V (https://www.pololu.com/product/3542)
	 * Robot utilizes two encoders. One for the left wheel and one for the right wheel
	 */
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P5.2
	 */
	#define ENCODER_ELB_PIN       12  // <- Energia Pin #   Launchpad Pin -> P5.2
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P5.0
	 */
	#define ENCODER_ERB_PIN       13  // <- Energia Pin #   Launchpad Pin -> P5.0
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P10.5
	 */
	#define ENCODER_ELA_PIN       72  // <- Energia Pin #   Launchpad Pin -> P10.5
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P10.4
	 */
	#define ENCODER_ERA_PIN       56  // <- Energia Pin #   Launchpad Pin -> P10.4

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P2.4
	 */
	#define SRV_0                 38  // <- Energia Pin #   Launchpad Pin -> P2.4

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P3.5
	 */
	#define SRV_1                 32  // <- Energia Pin #   Launchpad Pin -> P3.5

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P5.7
	 */
	#define SRV_2                 17  // <- Energia Pin #   Launchpad Pin -> P5.7

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P8.4
	 */
	#define SRV_FB0               43  // <- Energia Pin #   Launchpad Pin -> P8.4

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P8.3
	 */
	#define SRV_FB1               60  // <- Energia Pin #   Launchpad Pin -> P8.3
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P8.2
	 */
	#define SRV_FB2               44  // <- Energia Pin #   Launchpad Pin -> P8.2

	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.5
	 */
	#define LCD_SCLK              66  // <- Energia Pin #   Launchpad Pin -> P9.5
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.7
	 */
	#define LCD_MOSI              67  // <- Energia Pin #   Launchpad Pin -> P9.7
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.3
	 */
	#define LCD_RST               62  // <- Energia Pin #   Launchpad Pin -> P9.3
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.4
	 */
	#define LCD_CS                49  // <- Energia Pin #   Launchpad Pin -> P9.4
	/**
	 * @brief   Value represents Energia number for Launchpad Pin P9.6
	 */
	#define LCD_DC                50  // <- Energia Pin #   Launchpad Pin -> P9.6

#endif

#endif
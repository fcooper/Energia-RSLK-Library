#ifndef Romi_Motor_Power_h
#define Romi_Motor_Power_h

#include "Energia.h"

/// \brief Represents a single motor.
///
/// An instance of this class represents a single motor. The function begin()
/// must be called before using any other function.
///
/// Parts: @n
///     - TI-RSLK MAX Chassis Board v1.0 Assembly - https://www.pololu.com/product/3671


class Romi_Motor_Power
{
	private:
		uint8_t slp_pin;
		uint8_t dir_pin;
		uint8_t pwm_pin;
		uint8_t motor_dir;
		uint8_t sleep_speed;
		uint8_t preserve_speed;

	public:
		Romi_Motor_Power();

		/// \brief Initialize the motor and configures important pins.
		///
		/// \param[in] islp_pin pin number on Launchpad connected to motor's sleep pin
		/// \param[in] idir_pin pin number on Launchpad connected to motor's direction pin
		/// \param[in] ipwm_pin pin number on Launchpad connected to motor's PWM pin
		///
		/// Call this function to initialize motor
		bool begin(uint8_t islp_pin, uint8_t idir_pin,uint8_t ipwm_pin);

		/// \brief Disable motor
		///
		/// This function with disable the motor by putting it to sleep. The motor's
		/// speed is also set to 0. After calling this function the motor needs to
		/// be reenabled and be given a speed before it will start working again.
		void disableMotor();

		/// \brief Enable motor
		///
		/// This function with enable the motor by taking it out of sleep. The motor's
		/// speed needs to be reenabled to start working again.
		void enableMotor();


		/// \brief Pause motor
		///
		/// This function with stop the motor and acts just like disableMotor. However,
		/// the motor's speed when pause will be preserved and restored once resumeMotor
		/// is called.
		void pauseMotor();

		/// \brief Resume motor
		///
		/// This function with resume the motor's operation if pauseMotor was previously
		/// called. Unlike enableMotor the motor will start running based on the speed
		/// that was set when the motor was paused.
		void resumeMotor();

		/// \brief Set motor's direction to forward
		///
		/// Spins the wheel in the forward direction.
		void directionForward();

		/// \brief Set motor's direction to backwards
		///
		/// Spins the wheel in the backward direction.
		void directionBackward();

		/// \brief Set motor speed
		///
		/// \param[in] speed Valid values are 0 - 100 mimicing percentage.
		/// 		- 0 to halt motor
		/// 		- ...
		/// 		- 100 run motor at its max speed
		///
		/// Sets the motor speed. This function may be easier for beginners to understand.
		void setSpeed(uint8_t speed);

		/// \brief Set motor's raw speed
		///
		/// \param[in] speed between 0 - 255
		/// 		- 0 to halt motor
		/// 		- ...
		/// 		- 255 run motor at its max speed
		///
		/// Sets the motor speed. Provides finer grain control of the motor's speed then setSpeed.
		void setRawSpeed(uint8_t speed);
};

#endif



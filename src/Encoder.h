/** @file */
#include <stdint.h>

#ifndef Encoder_h
#define Encoder_h

/// \brief Initialize the wheel encoder.
///
/// \param[in] ela_pin pin number on Launchpad connected to ELA pin on encoder.
/// \param[in] elb_pin pin number on Launchpad connected to ELB pin on encoder.
/// \param[in] era_pin pin number on Launchpad connected to ERA pin on encoder.
/// \param[in] erb_pin pin number on Launchpad connected to ERB pin on encoder.
///
/// This function needs to be called before any other encoder function is used.
void setupEncoder(uint8_t ela_pin, uint8_t elb_pin, uint8_t era_pin, uint8_t erb_pin);

/// \brief Return number of encoder ticks from the left wheel.
///
/// \return The number of encoder ticks from the left wheel.
///
uint32_t getEncoderLeftCnt();

/// \brief Return number of encoder ticks from the right wheel.
///
/// \return The number of encoder ticks from the right wheel.
///
uint32_t getEncoderRightCnt();

/// \brief Set the left encoder tick count to 0
///
void resetLeftEncoderCnt();

/// \brief Set the right encoder tick count to 0
///
void resetRightEncoderCnt();

 /**
  * @brief Value used to reference wheel going forward.
  */
#define WHEEL_DIR_FORWARD	1

/**
 * @brief Value used to reference wheel going backwards.
 */
#define WHEEL_DIR_BACKWARD	0

/// \brief Determines if the left wheel is going forward or backwards
///
/// \return 1 for forward or 0 for backwards
///
uint8_t getLeftWheelDir();

/// \brief Determines if the right wheel is going forward or backwards
///
/// \return 1 for forward or 0 for backwards
///
uint8_t getRightWheelDir();

#endif

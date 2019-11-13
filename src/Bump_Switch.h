#ifndef Bump_Switch_h
#define Bump_Switch_h

#include "Energia.h"

/// \brief Represents a single bump switch.
///
/// An instance of this class represents a single Pololus [bump switch](https://www.pololu.com/product/3673). The function begin
/// must be called before using any other function.
///

class Bump_Switch
{
	private:
		uint8_t bump_sw_pin;
		uint8_t num_pins;
		bool configured;

	public:
		Bump_Switch();

		/// \brief Initialize the bump switch class.
		///
		/// \param[in] pin_num Pin number on Launchpad connected to bump switch
		/// \param[in] mode for input pin. Options are the same as standard [Energia](https://energia.nu/reference/en/language/functions/digital-io/pinmode/)/Arduino pin mode.
		///
		/// This function needs to be called before any other function is used.
		bool begin(uint8_t pin_num, uint8_t mode = INPUT_PULLUP);

		/// \brief Read the bump switch value
		///
		/// \return 0 or 1. Value when button pressed or released depends on hardware connection and any pulldown/pullup (internal/external) resistors.
		bool read();
};
#endif
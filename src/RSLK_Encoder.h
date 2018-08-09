#include "Energia.h"

#define DIR_FW 1
#define DIR_BW 2

#define ENCA_ONLY 0
#define ENCA_COUNT_ENCB_COUNT 1
#define ENCA_COUNT_ENCB_DIR 2

class RSLK_Encoder
{
    private:
        uint8_t encoder_pin[2];
        uint32_t encoder_count[2];
        bool configured;
        uint8_t option;
        uint8_t direction;

    public:
		RSLK_Encoder();
		bool begin(uint8_t enc_a_pin, uint8_t enc_a_state,uint8_t enc_b_pin,uint8_t enc_b_state,uint8_t enc_option);
		uint32_t getCount(uint8_t index);
		void clearCount();
		uint32_t getCountClear(uint8_t index);
		uint8_t getDirection();
		void encAIsr();
		void encBIsr();
};




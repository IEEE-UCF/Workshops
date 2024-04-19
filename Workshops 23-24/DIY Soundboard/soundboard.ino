#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "hardware/sync.h"

// Audio PIN is to match some of the design guide shields.
#define AUDIO_PIN 28
#define BUTTON_PIN 26
// VVVVVVV Paste C array from Google Colab here VVVVVVV
//------------------------------------------------------------------

//------------------------------------------------------------------

int wav_position = 0;
bool samplePlayed = false; // Flag to track if the sample has been played

void pwm_interrupt_handler() {
    pwm_clear_irq(pwm_gpio_to_slice_num(AUDIO_PIN));
    if (wav_position < (WAV_DATA_LENGTH << 3) - 1) {
        pwm_set_gpio_level(AUDIO_PIN, WAV_DATA[wav_position >> 3]);
        wav_position++;
    }
}
bool isBoardOn = true;  // Initial state is on

// Button interrupt handler
void button_interrupt_handler(uint gpio, uint32_t events) {
    if (events & GPIO_IRQ_EDGE_FALL) {
        // Button pressed, set the samplePlayed flag to false
        samplePlayed = false;
    }
}


void setup() {
    Serial.begin(115200); // Initialize serial communication for debugging
    set_sys_clock_khz(176000, true);
    gpio_set_function(AUDIO_PIN, GPIO_FUNC_PWM);
    
    // Configure the button pin
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &button_interrupt_handler);

    int audio_pin_slice = pwm_gpio_to_slice_num(AUDIO_PIN);

    pwm_clear_irq(audio_pin_slice);
    pwm_set_irq_enabled(audio_pin_slice, true);
    irq_set_exclusive_handler(PWM_IRQ_WRAP, pwm_interrupt_handler);
    irq_set_enabled(PWM_IRQ_WRAP, true);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 8.0f);
    pwm_config_set_wrap(&config, 250);
    pwm_init(audio_pin_slice, &config, true);

    pwm_set_gpio_level(AUDIO_PIN, 0);
}

void loop() {
    // Check if the sample has been played, and if not, play it
    if (!samplePlayed) {
        samplePlayed = true;
        // Start playing the sample
        wav_position = 0;
    }

    __wfi();
}
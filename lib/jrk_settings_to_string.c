#include "jrk_internal.h"

jrk_error * jrk_settings_to_string(const jrk_settings * settings, char ** string)
{
  if (string == NULL)
  {
    return jrk_error_create("String output pointer is null.");
  }

  *string = NULL;

  if (settings == NULL)
  {
    return jrk_error_create("Settings pointer is null.");
  }

  jrk_string str;
  jrk_string_setup(&str);

  jrk_sprintf(&str, "# Pololu jrk settings file.\n");
  jrk_sprintf(&str, "# " DOCUMENTATION_URL "\n");

  uint32_t product = jrk_settings_get_product(settings);

  {
    const char * product_str = jrk_look_up_product_name_short(product);
    jrk_sprintf(&str, "product: %s\n", product_str);
  }

  // Beginning of auto-generated settings file printing code.

  {
    uint8_t input_mode = jrk_settings_get_input_mode(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_input_mode_names_short, input_mode, &value_str);
    jrk_sprintf(&str, "input_mode: %s\n", value_str);
  }

  {
    uint16_t input_error_minimum = jrk_settings_get_input_error_minimum(settings);
    jrk_sprintf(&str, "input_error_minimum: %u\n", input_error_minimum);
  }

  {
    uint16_t input_error_maximum = jrk_settings_get_input_error_maximum(settings);
    jrk_sprintf(&str, "input_error_maximum: %u\n", input_error_maximum);
  }

  {
    uint16_t input_minimum = jrk_settings_get_input_minimum(settings);
    jrk_sprintf(&str, "input_minimum: %u\n", input_minimum);
  }

  {
    uint16_t input_maximum = jrk_settings_get_input_maximum(settings);
    jrk_sprintf(&str, "input_maximum: %u\n", input_maximum);
  }

  {
    uint16_t input_neutral_minimum = jrk_settings_get_input_neutral_minimum(settings);
    jrk_sprintf(&str, "input_neutral_minimum: %u\n", input_neutral_minimum);
  }

  {
    uint16_t input_neutral_maximum = jrk_settings_get_input_neutral_maximum(settings);
    jrk_sprintf(&str, "input_neutral_maximum: %u\n", input_neutral_maximum);
  }

  {
    uint16_t output_minimum = jrk_settings_get_output_minimum(settings);
    jrk_sprintf(&str, "output_minimum: %u\n", output_minimum);
  }

  {
    uint16_t output_neutral = jrk_settings_get_output_neutral(settings);
    jrk_sprintf(&str, "output_neutral: %u\n", output_neutral);
  }

  {
    uint16_t output_maximum = jrk_settings_get_output_maximum(settings);
    jrk_sprintf(&str, "output_maximum: %u\n", output_maximum);
  }

  {
    bool input_invert = jrk_settings_get_input_invert(settings);
    jrk_sprintf(&str, "input_invert: %s\n",
      input_invert ? "true" : "false");
  }

  {
    uint8_t input_scaling_degree = jrk_settings_get_input_scaling_degree(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_input_scaling_degree_names_short, input_scaling_degree, &value_str);
    jrk_sprintf(&str, "input_scaling_degree: %s\n", value_str);
  }

  {
    bool input_detect_disconnect = jrk_settings_get_input_detect_disconnect(settings);
    jrk_sprintf(&str, "input_detect_disconnect: %s\n",
      input_detect_disconnect ? "true" : "false");
  }

  {
    uint8_t input_analog_samples_exponent = jrk_settings_get_input_analog_samples_exponent(settings);
    jrk_sprintf(&str, "input_analog_samples_exponent: %u\n", input_analog_samples_exponent);
  }

  {
    uint8_t feedback_mode = jrk_settings_get_feedback_mode(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_feedback_mode_names_short, feedback_mode, &value_str);
    jrk_sprintf(&str, "feedback_mode: %s\n", value_str);
  }

  {
    uint16_t feedback_error_minimum = jrk_settings_get_feedback_error_minimum(settings);
    jrk_sprintf(&str, "feedback_error_minimum: %u\n", feedback_error_minimum);
  }

  {
    uint16_t feedback_error_maximum = jrk_settings_get_feedback_error_maximum(settings);
    jrk_sprintf(&str, "feedback_error_maximum: %u\n", feedback_error_maximum);
  }

  {
    uint16_t feedback_minimum = jrk_settings_get_feedback_minimum(settings);
    jrk_sprintf(&str, "feedback_minimum: %u\n", feedback_minimum);
  }

  {
    uint16_t feedback_maximum = jrk_settings_get_feedback_maximum(settings);
    jrk_sprintf(&str, "feedback_maximum: %u\n", feedback_maximum);
  }

  {
    bool feedback_invert = jrk_settings_get_feedback_invert(settings);
    jrk_sprintf(&str, "feedback_invert: %s\n",
      feedback_invert ? "true" : "false");
  }

  {
    bool feedback_detect_disconnect = jrk_settings_get_feedback_detect_disconnect(settings);
    jrk_sprintf(&str, "feedback_detect_disconnect: %s\n",
      feedback_detect_disconnect ? "true" : "false");
  }

  {
    uint8_t feedback_dead_zone = jrk_settings_get_feedback_dead_zone(settings);
    jrk_sprintf(&str, "feedback_dead_zone: %u\n", feedback_dead_zone);
  }

  {
    uint8_t feedback_analog_samples_exponent = jrk_settings_get_feedback_analog_samples_exponent(settings);
    jrk_sprintf(&str, "feedback_analog_samples_exponent: %u\n", feedback_analog_samples_exponent);
  }

  {
    bool feedback_wraparound = jrk_settings_get_feedback_wraparound(settings);
    jrk_sprintf(&str, "feedback_wraparound: %s\n",
      feedback_wraparound ? "true" : "false");
  }

  {
    uint8_t serial_mode = jrk_settings_get_serial_mode(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_serial_mode_names_short, serial_mode, &value_str);
    jrk_sprintf(&str, "serial_mode: %s\n", value_str);
  }

  {
    uint32_t serial_baud_rate = jrk_settings_get_serial_baud_rate(settings);
    jrk_sprintf(&str, "serial_baud_rate: %u\n", serial_baud_rate);
  }

  {
    uint32_t serial_timeout = jrk_settings_get_serial_timeout(settings);
    jrk_sprintf(&str, "serial_timeout: %u\n", serial_timeout);
  }

  {
    uint16_t serial_device_number = jrk_settings_get_serial_device_number(settings);
    jrk_sprintf(&str, "serial_device_number: %u\n", serial_device_number);
  }

  {
    bool never_sleep = jrk_settings_get_never_sleep(settings);
    jrk_sprintf(&str, "never_sleep: %s\n",
      never_sleep ? "true" : "false");
  }

  {
    bool serial_enable_crc = jrk_settings_get_serial_enable_crc(settings);
    jrk_sprintf(&str, "serial_enable_crc: %s\n",
      serial_enable_crc ? "true" : "false");
  }

  {
    bool serial_enable_14bit_device_number = jrk_settings_get_serial_enable_14bit_device_number(settings);
    jrk_sprintf(&str, "serial_enable_14bit_device_number: %s\n",
      serial_enable_14bit_device_number ? "true" : "false");
  }

  {
    bool serial_disable_compact_protocol = jrk_settings_get_serial_disable_compact_protocol(settings);
    jrk_sprintf(&str, "serial_disable_compact_protocol: %s\n",
      serial_disable_compact_protocol ? "true" : "false");
  }

  {
    uint16_t proportional_multiplier = jrk_settings_get_proportional_multiplier(settings);
    jrk_sprintf(&str, "proportional_multiplier: %u\n", proportional_multiplier);
  }

  {
    uint8_t proportional_exponent = jrk_settings_get_proportional_exponent(settings);
    jrk_sprintf(&str, "proportional_exponent: %u\n", proportional_exponent);
  }

  {
    uint16_t integral_multiplier = jrk_settings_get_integral_multiplier(settings);
    jrk_sprintf(&str, "integral_multiplier: %u\n", integral_multiplier);
  }

  {
    uint8_t integral_exponent = jrk_settings_get_integral_exponent(settings);
    jrk_sprintf(&str, "integral_exponent: %u\n", integral_exponent);
  }

  {
    uint16_t derivative_multiplier = jrk_settings_get_derivative_multiplier(settings);
    jrk_sprintf(&str, "derivative_multiplier: %u\n", derivative_multiplier);
  }

  {
    uint8_t derivative_exponent = jrk_settings_get_derivative_exponent(settings);
    jrk_sprintf(&str, "derivative_exponent: %u\n", derivative_exponent);
  }

  {
    uint16_t pid_period = jrk_settings_get_pid_period(settings);
    jrk_sprintf(&str, "pid_period: %u\n", pid_period);
  }

  {
    uint8_t integral_divider_exponent = jrk_settings_get_integral_divider_exponent(settings);
    jrk_sprintf(&str, "integral_divider_exponent: %u\n", integral_divider_exponent);
  }

  {
    uint16_t integral_limit = jrk_settings_get_integral_limit(settings);
    jrk_sprintf(&str, "integral_limit: %u\n", integral_limit);
  }

  {
    bool reset_integral = jrk_settings_get_reset_integral(settings);
    jrk_sprintf(&str, "reset_integral: %s\n",
      reset_integral ? "true" : "false");
  }

  {
    uint8_t pwm_frequency = jrk_settings_get_pwm_frequency(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_pwm_frequency_names_short, pwm_frequency, &value_str);
    jrk_sprintf(&str, "pwm_frequency: %s\n", value_str);
  }

  {
    uint8_t current_samples_exponent = jrk_settings_get_current_samples_exponent(settings);
    jrk_sprintf(&str, "current_samples_exponent: %u\n", current_samples_exponent);
  }

  if (product != JRK_PRODUCT_UMC06A)
  {
    uint8_t hard_overcurrent_threshold = jrk_settings_get_hard_overcurrent_threshold(settings);
    jrk_sprintf(&str, "hard_overcurrent_threshold: %u\n", hard_overcurrent_threshold);
  }

  {
    int16_t current_offset_calibration = jrk_settings_get_current_offset_calibration(settings);
    jrk_sprintf(&str, "current_offset_calibration: %d\n", current_offset_calibration);
  }

  {
    int16_t current_scale_calibration = jrk_settings_get_current_scale_calibration(settings);
    jrk_sprintf(&str, "current_scale_calibration: %d\n", current_scale_calibration);
  }

  {
    bool motor_invert = jrk_settings_get_motor_invert(settings);
    jrk_sprintf(&str, "motor_invert: %s\n",
      motor_invert ? "true" : "false");
  }

  {
    uint16_t max_duty_cycle_while_feedback_out_of_range = jrk_settings_get_max_duty_cycle_while_feedback_out_of_range(settings);
    jrk_sprintf(&str, "max_duty_cycle_while_feedback_out_of_range: %u\n", max_duty_cycle_while_feedback_out_of_range);
  }

  {
    uint16_t max_acceleration_forward = jrk_settings_get_max_acceleration_forward(settings);
    jrk_sprintf(&str, "max_acceleration_forward: %u\n", max_acceleration_forward);
  }

  {
    uint16_t max_acceleration_reverse = jrk_settings_get_max_acceleration_reverse(settings);
    jrk_sprintf(&str, "max_acceleration_reverse: %u\n", max_acceleration_reverse);
  }

  {
    uint16_t max_deceleration_forward = jrk_settings_get_max_deceleration_forward(settings);
    jrk_sprintf(&str, "max_deceleration_forward: %u\n", max_deceleration_forward);
  }

  {
    uint16_t max_deceleration_reverse = jrk_settings_get_max_deceleration_reverse(settings);
    jrk_sprintf(&str, "max_deceleration_reverse: %u\n", max_deceleration_reverse);
  }

  {
    uint16_t max_duty_cycle_forward = jrk_settings_get_max_duty_cycle_forward(settings);
    jrk_sprintf(&str, "max_duty_cycle_forward: %u\n", max_duty_cycle_forward);
  }

  {
    uint16_t max_duty_cycle_reverse = jrk_settings_get_max_duty_cycle_reverse(settings);
    jrk_sprintf(&str, "max_duty_cycle_reverse: %u\n", max_duty_cycle_reverse);
  }

  if (product != JRK_PRODUCT_UMC06A)
  {
    uint16_t encoded_hard_current_limit_forward = jrk_settings_get_encoded_hard_current_limit_forward(settings);
    jrk_sprintf(&str, "encoded_hard_current_limit_forward: %u\n", encoded_hard_current_limit_forward);
  }

  if (product != JRK_PRODUCT_UMC06A)
  {
    uint16_t encoded_hard_current_limit_reverse = jrk_settings_get_encoded_hard_current_limit_reverse(settings);
    jrk_sprintf(&str, "encoded_hard_current_limit_reverse: %u\n", encoded_hard_current_limit_reverse);
  }

  {
    uint32_t brake_duration_forward = jrk_settings_get_brake_duration_forward(settings);
    jrk_sprintf(&str, "brake_duration_forward: %u\n", brake_duration_forward);
  }

  {
    uint32_t brake_duration_reverse = jrk_settings_get_brake_duration_reverse(settings);
    jrk_sprintf(&str, "brake_duration_reverse: %u\n", brake_duration_reverse);
  }

  {
    uint16_t soft_current_limit_forward = jrk_settings_get_soft_current_limit_forward(settings);
    jrk_sprintf(&str, "soft_current_limit_forward: %u\n", soft_current_limit_forward);
  }

  {
    uint16_t soft_current_limit_reverse = jrk_settings_get_soft_current_limit_reverse(settings);
    jrk_sprintf(&str, "soft_current_limit_reverse: %u\n", soft_current_limit_reverse);
  }

  if (product == JRK_PRODUCT_UMC06A)
  {
    uint16_t soft_current_regulation_level_forward = jrk_settings_get_soft_current_regulation_level_forward(settings);
    jrk_sprintf(&str, "soft_current_regulation_level_forward: %u\n", soft_current_regulation_level_forward);
  }

  if (product == JRK_PRODUCT_UMC06A)
  {
    uint16_t soft_current_regulation_level_reverse = jrk_settings_get_soft_current_regulation_level_reverse(settings);
    jrk_sprintf(&str, "soft_current_regulation_level_reverse: %u\n", soft_current_regulation_level_reverse);
  }

  {
    bool coast_when_off = jrk_settings_get_coast_when_off(settings);
    jrk_sprintf(&str, "coast_when_off: %s\n",
      coast_when_off ? "true" : "false");
  }

  {
    uint16_t error_enable = jrk_settings_get_error_enable(settings);
    jrk_sprintf(&str, "error_enable: %u\n", error_enable);
  }

  {
    uint16_t error_latch = jrk_settings_get_error_latch(settings);
    jrk_sprintf(&str, "error_latch: %u\n", error_latch);
  }

  {
    uint16_t error_hard = jrk_settings_get_error_hard(settings);
    jrk_sprintf(&str, "error_hard: %u\n", error_hard);
  }

  {
    int16_t vin_calibration = jrk_settings_get_vin_calibration(settings);
    jrk_sprintf(&str, "vin_calibration: %d\n", vin_calibration);
  }

  {
    bool disable_i2c_pullups = jrk_settings_get_disable_i2c_pullups(settings);
    jrk_sprintf(&str, "disable_i2c_pullups: %s\n",
      disable_i2c_pullups ? "true" : "false");
  }

  {
    bool analog_sda_pullup = jrk_settings_get_analog_sda_pullup(settings);
    jrk_sprintf(&str, "analog_sda_pullup: %s\n",
      analog_sda_pullup ? "true" : "false");
  }

  {
    bool always_analog_sda = jrk_settings_get_always_analog_sda(settings);
    jrk_sprintf(&str, "always_analog_sda: %s\n",
      always_analog_sda ? "true" : "false");
  }

  {
    bool always_analog_fba = jrk_settings_get_always_analog_fba(settings);
    jrk_sprintf(&str, "always_analog_fba: %s\n",
      always_analog_fba ? "true" : "false");
  }

  {
    uint8_t fbt_method = jrk_settings_get_fbt_method(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_fbt_method_names_short, fbt_method, &value_str);
    jrk_sprintf(&str, "fbt_method: %s\n", value_str);
  }

  {
    uint8_t fbt_timing_clock = jrk_settings_get_fbt_timing_clock(settings);
    const char * value_str = "";
    jrk_code_to_name(jrk_fbt_timing_clock_names_short, fbt_timing_clock, &value_str);
    jrk_sprintf(&str, "fbt_timing_clock: %s\n", value_str);
  }

  {
    bool fbt_timing_polarity = jrk_settings_get_fbt_timing_polarity(settings);
    jrk_sprintf(&str, "fbt_timing_polarity: %s\n",
      fbt_timing_polarity ? "true" : "false");
  }

  {
    uint16_t fbt_timing_timeout = jrk_settings_get_fbt_timing_timeout(settings);
    jrk_sprintf(&str, "fbt_timing_timeout: %u\n", fbt_timing_timeout);
  }

  {
    uint8_t fbt_samples = jrk_settings_get_fbt_samples(settings);
    jrk_sprintf(&str, "fbt_samples: %u\n", fbt_samples);
  }

  {
    uint8_t fbt_divider_exponent = jrk_settings_get_fbt_divider_exponent(settings);
    jrk_sprintf(&str, "fbt_divider_exponent: %u\n", fbt_divider_exponent);
  }

  // End of auto-generated settings file printing code.

  if (str.data == NULL)
  {
    return &jrk_error_no_memory;
  }
  else
  {
    *string = str.data;
    return NULL;
  }
}

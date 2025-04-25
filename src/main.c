#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define DELAY_TIME 200
#define LED_PIN 2

static const struct device *gpio0 =
	DEVICE_DT_GET(DT_NODELABEL(gpio0));

int main(void)
{
	gpio_pin_configure(gpio0, LED_PIN, GPIO_OUTPUT_ACTIVE);

	while (true)
	{
		gpio_pin_set_raw(gpio0, LED_PIN, 1);
		k_msleep(DELAY_TIME);

		gpio_pin_set_raw(gpio0, LED_PIN, 0);
		k_msleep(DELAY_TIME);
	}
	return 0;
}

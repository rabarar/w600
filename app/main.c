#include <wm_include.h>

/* Empty template
static void
UserTask(void* taskParam)
{
  while (true) {
    tls_os_time_delay(1);
  }
}

void
UserMain()
{
  static OS_STK stack[2048];
  tls_os_task_create(NULL, NULL, UserTask, NULL, (u8*)stack, sizeof(stack) / sizeof(stack[0]), 32, 0);
}
*/

/* LED Blink! */
void UserMain()
{
  bool isOn = 0;
  tls_gpio_cfg(WM_IO_PB_08, WM_GPIO_DIR_OUTPUT, WM_GPIO_ATTR_FLOATING);

  while (true) {
    tls_gpio_write(WM_IO_PB_08, isOn);
    tls_os_time_delay(HZ);
    isOn = !isOn;
  }
}

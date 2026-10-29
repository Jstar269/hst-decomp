/* Manager object that owns a screen object at offset 0x3c (constructor 0x2637c8, deleting destructor 0x2635b4). */
#ifndef HST_SCREEN_MANAGER_H
#define HST_SCREEN_MANAGER_H

#include "hst/screen_obj.h"

typedef struct ScreenManager {
  void *vtable;       /* 0x00 */
  char pad04[0x38];
  ScreenObj *screen;  /* 0x3c owned screen, created by the constructor */
} ScreenManager;

#endif

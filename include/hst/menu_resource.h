/* Menu resource object that owns an install thread: its thread handle and the last result code. */
#ifndef HST_MENU_RESOURCE_H
#define HST_MENU_RESOURCE_H

typedef struct MenuResource {
  char pad00[4];
  int unk4;        /* 0x04 passed to the file-bundle read */
  char pad08[0x14];
  int result;      /* 0x1c last result code of the thread, negative on error */
  char pad20[4];
  int thread;      /* 0x24 kernel thread handle, negative when none */
} MenuResource;

#endif

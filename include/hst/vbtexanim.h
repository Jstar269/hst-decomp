/* VBlank texture animation object: copies a rectangle of the frame buffer into its own buffer while active. */
#ifndef HST_VBTEXANIM_H
#define HST_VBTEXANIM_H

#define VBTEXANIM_STRIDE 512 /* pixels per frame buffer row */

typedef struct VbTexAnim {
  void *vptr;
  unsigned char active;    /* 0x04 set while the vblank handler is installed */
  char pad5[0x14 - 5];
  int x;                   /* 0x14 source rectangle */
  int y;                   /* 0x18 */
  int w;                   /* 0x1c */
  int h;                   /* 0x20 */
  int bpp;                 /* 0x24 bytes per pixel */
  int *handles;            /* 0x28 array of count texture handles; each is released and set to -1 on destruction */
  unsigned int count;      /* 0x2c */
  int pad30;
  char *buf;               /* 0x34 copy of the rectangle */
  void (**hook)(void);     /* 0x38 where the vblank handler is installed */
} VbTexAnim;

#endif

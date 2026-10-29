/* Render-to-texture object (0x90 bytes, global singleton): owns a camera and renders a character into a texture. */
#ifndef HST_RENDER_TARGET_H
#define HST_RENDER_TARGET_H

enum { RENDER_TARGET_SIZE = 0x90 }; /* allocation size of one object */

typedef struct RenderTarget {
  const void *vtable;       /* 0x00 */
  char pad04[0x3c - 4];
  void *camera;             /* 0x3c owned, released by the destructor */
  void *chara;              /* 0x40 object that is rendered */
  unsigned char dirty;      /* 0x44 set when the camera setup has to be redone */
  unsigned char unk45;      /* 0x45 */
  char pad46[2];
  int width;                /* 0x48 */
  int height;               /* 0x4c */
  int unk50;                /* 0x50 */
  int unk54;                /* 0x54 */
  int unk58;                /* 0x58 */
  char pad5c[4];
  float unk60[4];           /* 0x60 */
  float unk70[3];           /* 0x70 */
  void *fn7c;               /* 0x7c callbacks installed by the constructor */
  void *fn80;               /* 0x80 */
  void *fn84;               /* 0x84 */
  char pad88[8];
} RenderTarget;

#endif


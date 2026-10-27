/* HSTMATCH module=hstp_trans_main.prx start=0x00061070 end=0x000611b8 symbol=FUN_00061070 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* VBlank texture animation (vbtexanim.cpp, from the Sharing build's assert strings) switched on or off: on, it
   asserts that no other instance is active (s_pThis == NULL, line 62), copies the w x h source rectangle at (x, y)
   of the current frame buffer (sceDisplayGetFrameBuf wrapper 0x615dc, 512-pixel stride, bpp bytes per pixel) into
   its buffer, registers itself as s_pThis (DAT_003da70c) and installs the vblank handler 0x61610 in *hook; off, it
   clears both again. The EBOOT twin (0x60224) is the same source with an empty ASSERT. */
struct VbTexAnim {
  void *vptr;
  unsigned char active;
  char pad5[0x14 - 5];
  int x;
  int y;
  int w;
  int h;
  int bpp;
  int *handles;
  unsigned int count;
  int pad30;
  char *buf;
  void (**hook)(void);
};

extern "C" {
extern VbTexAnim *DAT_003da70c;
extern char DAT_00376ea8[];
extern char DAT_00376ef8[];
extern char DAT_00376ee8[];
void FUN_00060f58(...);
char *FUN_000615dc(void);
void FUN_00011090(void *, const void *, int);
void FUN_00061610(void);
}

#define ASSERT(c, line) if (!(c)) { FUN_00060f58(DAT_00376ea8, DAT_00376ef8, DAT_00376ee8, line); for (;;) {} }

extern "C" void FUN_00061070(VbTexAnim *self, int on)
{
  if (on) {
    if (self->active)
      return;
    ASSERT(DAT_003da70c == 0, 62);
    char *base = FUN_000615dc();
    if (base) {
      char *src = base + self->bpp * (self->x + self->y * 512);
      char *dst = self->buf;
      for (int i = 0; i < self->h; i++) {
        FUN_00011090(dst, src, self->bpp * self->w);
        src += self->bpp * 512;
        dst += self->bpp * self->w;
      }
    }
    self->active = 1;
    DAT_003da70c = self;
    *self->hook = FUN_00061610;
  } else if (self->active) {
    *self->hook = 0;
    DAT_003da70c = 0;
    self->active = 0;
  }
}

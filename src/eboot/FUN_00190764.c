/* HSTMATCH module=EBOOT.BIN start=0x00190764 end=0x00190830 symbol=FUN_00190764 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272
#define OVERLAY_COLOR 0x50000000 /* translucent black */

extern unsigned char DAT_00341771;

/* Object whose pointer at 0x3c leads to the drawing context. */
typedef struct Owner {
  char pad[0x3c];
  char *context; /* 0x3c */
} Owner;

typedef struct Context {
  char pad[8];
  int state;                /* 0x08 */
  char pad2[0x31c - 0xc];
  void *overlay;            /* 0x31c sprite drawn over the whole screen */
} Context;

extern void FUN_00051490(void *sprite, int a, int b, int w, int h, int c, int d);
extern void FUN_00051398(void *sprite, float f);
extern void FUN_00051714(void *sprite);
extern void FUN_00051478(void *sprite, int cmd);
extern void FUN_000513a0(void *sprite, int a);
extern void FUN_00051a10(void *sprite, float f1, float f2, float f3, float f4, float f5, int a);
extern void FUN_0005185c(void *sprite);

/* Draws a translucent full-screen overlay when the flag is set or the context is in state 20. */
void FUN_00190764(Owner *self)
{
  Context *ctx = (Context *)self->context;

  if (DAT_00341771 == 0) {
    if (ctx->state != 20)
      return;
  }
  FUN_00051490(ctx->overlay, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  FUN_00051398(ctx->overlay, 200000.0f);
  FUN_00051714(ctx->overlay);
  FUN_00051478(ctx->overlay, 0xdf000032);
  FUN_000513a0(ctx->overlay, 0);
  FUN_00051a10(ctx->overlay, 0.0f, 0.0f, 480.0f, 272.0f, 65535.0f, OVERLAY_COLOR);
  FUN_0005185c(ctx->overlay);
}

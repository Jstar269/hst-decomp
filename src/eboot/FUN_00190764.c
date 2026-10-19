/* HSTMATCH module=EBOOT.BIN start=0x00190764 end=0x00190830 symbol=FUN_00190764 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_00341771;

typedef struct {
  char pad[0x3c];
  char *f3c;
} Self;

typedef struct {
  char pad[8];
  int f8;
  char pad2[0x31c - 0xc];
  void *f31c;
} Obj;

extern void FUN_00051490(void *tex, int a, int b, int w, int h, int c, int d);
extern void FUN_00051398(void *tex, float f);
extern void FUN_00051714(void *tex);
extern void FUN_00051478(void *tex, int cmd);
extern void FUN_000513a0(void *tex, int a);
extern void FUN_00051a10(void *tex, float f1, float f2, float f3, float f4, float f5, int a);
extern void FUN_0005185c(void *tex);

void FUN_00190764(Self *self)
{
  Obj *g = (Obj *)self->f3c;

  if (DAT_00341771 == 0) {
    if (g->f8 != 20)
      return;
  }
  FUN_00051490(g->f31c, 0, 0, 480, 272, 0, 0);
  FUN_00051398(g->f31c, 200000.0f);
  FUN_00051714(g->f31c);
  FUN_00051478(g->f31c, 0xdf000032);
  FUN_000513a0(g->f31c, 0);
  FUN_00051a10(g->f31c, 0.0f, 0.0f, 480.0f, 272.0f, 65535.0f, 0x50000000);
  FUN_0005185c(g->f31c);
}

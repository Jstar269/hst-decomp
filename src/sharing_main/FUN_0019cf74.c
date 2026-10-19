/* HSTMATCH module=hstp_trans_main.prx start=0x0019cf74 end=0x0019d040 symbol=FUN_0019cf74 lang=c99 */
/* Clone of src/eboot/FUN_00190764.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern unsigned char DAT_003eaab1;

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

extern void FUN_00051e30(void *tex, int a, int b, int w, int h, int c, int d);
extern void FUN_00051d38(void *tex, float f);
extern void FUN_00052178(void *tex);
extern void FUN_00051e18(void *tex, int cmd);
extern void FUN_00051d40(void *tex, int a);
extern void FUN_000524d0(void *tex, float f1, float f2, float f3, float f4, float f5, int a);
extern void FUN_000522c0(void *tex);

void FUN_0019cf74(Self *self)
{
  Obj *g = (Obj *)self->f3c;

  if (DAT_003eaab1 == 0) {
    if (g->f8 != 20)
      return;
  }
  FUN_00051e30(g->f31c, 0, 0, 480, 272, 0, 0);
  FUN_00051d38(g->f31c, 200000.0f);
  FUN_00052178(g->f31c);
  FUN_00051e18(g->f31c, 0xdf000032);
  FUN_00051d40(g->f31c, 0);
  FUN_000524d0(g->f31c, 0.0f, 0.0f, 480.0f, 272.0f, 65535.0f, 0x50000000);
  FUN_000522c0(g->f31c);
}

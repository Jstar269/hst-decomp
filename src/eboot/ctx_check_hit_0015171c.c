/* HSTMATCH module=EBOOT.BIN start=0x0015171c end=0x001517cc symbol=FUN_0015171c lang=c99 data=0x002dc524 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc524-0x002dc53f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Inner { char pad0[0x34]; int a; int b; char pad1[0x20]; unsigned char hit; };
struct Ctx { int key; int pad[2]; struct Inner *in; };

extern unsigned char DAT_003402f0;
extern int *FUN_0014c384(int, int);
extern void FUN_0014d044(struct Ctx *);
extern void FUN_0014fd94(char *, int, int);
extern unsigned char FUN_0022bc14(int, int, int);

int FUN_0015171c(int unused, struct Ctx *ctx)
{
  struct Inner *in; int v; int a; int b;
  in = ctx->in;
  a = in->a;
  b = in->b;
  v = *FUN_0014c384(ctx->key, 8);
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("CmdCheckMatchProc(%d, %d)\n", a, v);
  }
  if (FUN_0022bc14(a, b, v) != 0) {
    in->hit = 1;
  }
  return 0;
}

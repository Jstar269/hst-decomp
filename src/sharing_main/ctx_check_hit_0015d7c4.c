/* HSTMATCH module=hstp_trans_main.prx start=0x0015d7c4 end=0x0015d874 symbol=FUN_0015d7c4 lang=c99 */
/* Clone of src/eboot/ctx_check_hit_0015171c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Inner { char pad0[0x34]; int a; int b; char pad1[0x20]; unsigned char hit; };
struct Ctx { int key; int pad[2]; struct Inner *in; };

extern unsigned char DAT_003e9630;
extern char DAT_00383a0c[];
extern int *FUN_00157e10(int, int);
extern void FUN_00158b2c(struct Ctx *);
extern void FUN_0015bb68(char *, int, int);
extern unsigned char FUN_0023b520(int, int, int);

int FUN_0015d7c4(int unused, struct Ctx *ctx)
{
  struct Inner *in; int v; int a; int b;
  in = ctx->in;
  a = in->a;
  b = in->b;
  v = *FUN_00157e10(ctx->key, 8);
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(ctx);
    FUN_0015bb68(DAT_00383a0c, a, v);
  }
  if (FUN_0023b520(a, b, v) != 0) {
    in->hit = 1;
  }
  return 0;
}

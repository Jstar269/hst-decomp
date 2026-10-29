/* HSTMATCH module=EBOOT.BIN start=0x0015171c end=0x001517cc symbol=FUN_0015171c lang=c99 data=0x002dc524 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc524-0x002dc53f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* The context's actor: two check values and a hit flag set by the command. */
struct Actor { char pad0[0x34]; int unk34; int unk38; char pad3c[0x20]; unsigned char hit; };
struct Ctx { int regs; int pad[2]; struct Actor *actor; };

#define MATCH_REG 8 /* register holding the match value */

extern unsigned char DAT_003402f0; /* script trace flag */
extern int *FUN_0014c384(int, int); /* register slot of a script register bank */
extern void FUN_0014d044(struct Ctx *);
extern void FUN_0014fd94(char *, int, int);
extern unsigned char FUN_0022bc14(int, int, int);

/* Script command "CmdCheckMatchProc": trace the actor's first check value and the register value, and set the
   actor's hit flag when the check passes. */
int FUN_0015171c(int unused, struct Ctx *ctx)
{
  struct Actor *actor; int value; int first; int second;
  actor = ctx->actor;
  first = actor->unk34;
  second = actor->unk38;
  value = *FUN_0014c384(ctx->regs, MATCH_REG);
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("CmdCheckMatchProc(%d, %d)\n", first, value);
  }
  if (FUN_0022bc14(first, second, value) != 0) {
    actor->hit = 1;
  }
  return 0;
}

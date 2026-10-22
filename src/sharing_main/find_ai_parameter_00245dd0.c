/* HSTMATCH module=hstp_trans_main.prx start=0x00245dd0 end=0x00245e7c symbol=FUN_00245dd0 lang=c99 */
/* Clone of src/eboot/find_ai_parameter_00235ca4.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern int FUN_000146ec(char *, char *);
extern void FUN_000143b0(char *, char *, char *);
extern void FUN_001104b0(char *, int);
extern char DAT_0039da7c[];
struct Self
{
  char pad0[0x14];
  char *f14;
  unsigned f18;
};

unsigned FUN_00245dd0(struct Self *self, char *name)
{
  unsigned i = 0;
  if (self->f18 != 0)
  {
    do
    {
      if (FUN_000146ec(name, self->f14 + i * 7 * 0x50 + 4) == 0)
        return i;
      i++;
    } while (i < self->f18);
  }
  char buf[256];
  FUN_000143b0(buf, DAT_0039da7c, name);
  FUN_001104b0(buf, 0);
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x0017d880 end=0x0017d910 symbol=FUN_0017d880 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed structs, the byte parameter is copied into an unsigned char local (retail's andi 0xff at entry), do/while loop; exact match verified; names and types await human review. */
typedef struct Inner { char pad[0x68]; void *f68; } Inner;
typedef struct Obj { char pad[8]; Inner **f8; char pad1[0x2d8]; int f2e4; } Obj;
extern void FUN_000575fc(void *, int, unsigned char);
extern int FUN_001fe984(void *, int, int);

void FUN_0017d880(Obj *o, int unused, int idx, unsigned char flag)
{
  void *p;
  int i;
  unsigned char f = flag;
  if (FUN_001fe984(&o->f2e4, idx, 0) == 0) {
    p = o->f8[idx]->f68;
    if (p != 0) {
      i = 0;
      do {
        FUN_000575fc(p, i, f);
        i++;
      } while (i < 6);
    }
  }
}

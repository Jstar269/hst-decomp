/* HSTMATCH module=hstp_trans_main.prx start=0x00189f74 end=0x0018a004 symbol=FUN_00189f74 lang=c99 */
/* Clone of src/eboot/broadcast_slot_flag_0017d880.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed structs, the byte parameter is copied into an unsigned char local (retail's andi 0xff at entry), do/while loop; exact match verified; names and types await human review. */
typedef struct Inner { char pad[0x68]; void *f68; } Inner;
typedef struct Obj { char pad[8]; Inner **f8; char pad1[0x2d8]; int f2e4; } Obj;
extern void FUN_00058250(void *, int, unsigned char);
extern int FUN_0020d154(void *, int, int);

void FUN_00189f74(Obj *o, int unused, int idx, unsigned char flag)
{
  void *p;
  int i;
  unsigned char f = flag;
  if (FUN_0020d154(&o->f2e4, idx, 0) == 0) {
    p = o->f8[idx]->f68;
    if (p != 0) {
      i = 0;
      do {
        FUN_00058250(p, i, f);
        i++;
      } while (i < 6);
    }
  }
}

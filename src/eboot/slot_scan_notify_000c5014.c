/* HSTMATCH module=EBOOT.BIN start=0x000c5014 end=0x000c50c4 symbol=FUN_000c5014 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: byte entries as a typed 7-byte struct array (unsigned char flag, lbu), for-loop with signed bound (blez) and index declared before use; exact match verified; names and types await human review. */
typedef struct Ent { unsigned char on; char pad[6]; } Ent;
typedef struct Obj { char pad0[0x5e]; Ent ent[4]; char pad1[0x198 - 0x5e - 28]; int cur; } Obj;

extern Obj * DAT_00338ac4;
extern unsigned char DAT_003417b8;
extern void FUN_000bb190(Obj *);
extern void FUN_000bd568(Obj *);

void FUN_000c5014(void)
{
  if (DAT_00338ac4 != 0) {
    int cur = DAT_00338ac4->cur;
    int n;
    int i;
    if (DAT_003417b8 == 0) {
      n = 2;
    }
    else {
      n = 4;
    }
    for (i = 0; i < n; i++) {
      if (DAT_00338ac4->ent[i].on != 0 && i == cur) {
        FUN_000bd568(DAT_00338ac4);
      }
    }
    FUN_000bb190(DAT_00338ac4);
  }
}

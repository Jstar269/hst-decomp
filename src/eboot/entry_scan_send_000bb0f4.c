/* HSTMATCH module=EBOOT.BIN start=0x000bb0f4 end=0x000bb190 symbol=FUN_000bb0f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: 7-byte entries as a typed struct array with an unsigned char flag (lbu), for-loop index declared first (s1/s0 order), typed pointer arguments; exact match verified; names and types await human review. */
typedef struct Ent { char name[6]; unsigned char on; } Ent;
typedef struct Obj { char pad0[0x58]; Ent ent[16]; char pad1[0x16c - 0x58 - 0x70]; int h; char pad2[0x198 - 0x170]; int cur; } Obj;

extern char DAT_002d5258[];
extern void FUN_000ba3ac(char *, int);
extern int FUN_002b7dc8(int, char *, int, int);

int FUN_000bb0f4(Obj *param_1, int param_2)
{
  int i;
  for (i = 0; i < 16; i++) {
    if (param_1->ent[i].on != 0 && i != param_1->cur) {
      int r = FUN_002b7dc8(param_1->h, param_1->ent[i].name, 6, param_2);
      if (r < 0) {
        FUN_000ba3ac(DAT_002d5258, r);
      }
    }
  }
  return 1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x000be53c end=0x000be5d8 symbol=FUN_000be53c lang=c99 */
/* Clone of src/eboot/entry_scan_send_000bb0f4.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: 7-byte entries as a typed struct array with an unsigned char flag (lbu), for-loop index declared first (s1/s0 order), typed pointer arguments; exact match verified; names and types await human review. */
typedef struct Ent { char name[6]; unsigned char on; } Ent;
typedef struct Obj { char pad0[0x58]; Ent ent[16]; char pad1[0x16c - 0x58 - 0x70]; int h; char pad2[0x198 - 0x170]; int cur; } Obj;

extern char DAT_0037bb64[];
extern void FUN_000bd6f0(char *, int);
extern int FUN_002c7b50(int, char *, int, int);

int FUN_000be53c(Obj *param_1, int param_2)
{
  int i;
  for (i = 0; i < 16; i++) {
    if (param_1->ent[i].on != 0 && i != param_1->cur) {
      int r = FUN_002c7b50(param_1->h, param_1->ent[i].name, 6, param_2);
      if (r < 0) {
        FUN_000bd6f0(DAT_0037bb64, r);
      }
    }
  }
  return 1;
}

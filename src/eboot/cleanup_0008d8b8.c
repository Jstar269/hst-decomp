/* HSTMATCH module=EBOOT.BIN start=0x0008d8b8 end=0x0008d8fc symbol=FUN_0008d8b8 lang=c99 */
/* Clone of src/sharing_main/cleanup_0008f050.c (hstclone.py tag x1237e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the object as a struct with an unsigned byte flag (lbu) and pointer members; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad_00[0x3c];
  void *f3c;
  void *f40;
  unsigned char f44;
} Obj;

extern void FUN_0008c434(void *);
extern void FUN_00281090(void *);
extern void FUN_00283c14(void *);

void FUN_0008d8b8(Obj *param_1)
{
  if (param_1->f44 != 0) {
    param_1->f44 = 0;
    FUN_00281090(param_1->f40);
  }
  FUN_00283c14(param_1->f40);
  FUN_0008c434(param_1->f3c);
}

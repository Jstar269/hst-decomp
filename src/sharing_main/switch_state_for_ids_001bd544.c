/* HSTMATCH module=hstp_trans_main.prx start=0x001bd544 end=0x001bd5cc symbol=FUN_001bd544 lang=c99 */
/* Clone of src/eboot/switch_state_for_ids_001afe6c.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed object with a volatile state field read into a local before the table entry (retail loads it first), loop index declared before the walking pointer (s1/s0 order); exact match verified; names and types await human review. */
typedef struct Obj { char pad0[0x7cc]; volatile int cur; } Obj;
extern int DAT_0038d2a0[];
extern int DAT_0038d2a8[3];
extern int DAT_0038d2b4[];
extern void FUN_001bde64(Obj *, int);
extern void FUN_001be2d4(Obj *, int *, int);

void FUN_001bd544(Obj *param_1)
{
  unsigned i;
  int *p;
  FUN_001be2d4(param_1, DAT_0038d2b4, 2);
  FUN_001be2d4(param_1, DAT_0038d2a0, 2);
  for (i = 0, p = DAT_0038d2a8; i < 3; i++) {
    int c = param_1->cur;
    int v = *p;
    if (c != v) {
      FUN_001bde64(param_1, v);
    }
    p++;
  }
}

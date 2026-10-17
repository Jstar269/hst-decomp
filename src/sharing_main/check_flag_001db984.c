/* HSTMATCH module=hstp_trans_main.prx start=0x001db984 end=0x001db9e8 symbol=FUN_001db984 lang=c99 */
/* Clone of src/eboot/check_flag_001cd2a8.c (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_003e48b4;
extern int FUN_00298b14(char *);

struct Obj { char pad[0x114]; char flag; };

int FUN_001db984(struct Obj *o)
{
  int r = 0;
  if (DAT_003e48b4 != 0) {
    int ok = FUN_00298b14(DAT_003e48b4 + 0x1320) != 0;
    if (!ok) {
      ok = o->flag != 0;
    }
    if (ok) {
      r = 1;
    }
  }
  return r;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0028a8c0 end=0x0028a92c symbol=FUN_0028a8c0 lang=c99 */
/* Clone of src/eboot/mode_getter_f138_002795dc.c (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003a7370[];
extern void FUN_00280834();

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int f118[4];
  int f128[4];
  int f138[4];
  int f148[4];
} Obj;

int FUN_0028a8c0(Obj *o)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->f138[mode - 1];
  default:
    FUN_00280834(DAT_003a7370, mode);
    return 0;
  }
}

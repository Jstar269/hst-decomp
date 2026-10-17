/* HSTMATCH module=hstp_trans_main.prx start=0x0013d310 end=0x0013d370 symbol=FUN_0013d310 lang=c99 */
/* Clone of src/eboot/not_flag_indexed_00131d58.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: int return and int flag with !b (sltu/xori, no andi), signed char table byte (lb), typed Rec/Obj pointers; exact match verified; names and types await human review. */
typedef struct Rec { char pad[0x58]; int idx; char pad1[0x78 - 0x5c]; unsigned char on; } Rec;
typedef struct Obj { char pad[0x80]; Rec *rec; char pad1[0x8c - 0x84]; int mode; } Obj;
extern char DAT_003e4919[];

int FUN_0013d310(Obj *param_1)
{
  int b;

  b = 0;
  if (param_1->mode == 3) {
    b = 0;
  }
  else if (param_1->rec->on != 0) {
    b = DAT_003e4919[param_1->rec->idx * 0x58] != 0;
  }
  return !b;
}

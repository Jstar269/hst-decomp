/* HSTMATCH module=hstp_trans_main.prx start=0x002bf730 end=0x002bf77c symbol=FUN_002bf730 lang=c99 */
/* Clone of src/eboot/reset_global_obj_002afce0.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct for the global (+0xc int, +0x52 byte), global read into a local for the two stores and re-read for the call, float first argument 203000.0f (0x48463e00); exact match verified; names and types await human review. */
typedef struct Obj { char pad0[0xc]; int f0c; char pad1[0x42]; unsigned char f52; } Obj;
extern Obj *DAT_003daec4;
extern int DAT_003f4918;
extern void FUN_0006433c(float, Obj *);
extern void FUN_002c00bc(int);

void FUN_002bf730(int param_1)
{
  if (param_1 == 0) {
    Obj *o = DAT_003daec4;
    o->f0c = 0;
    o->f52 = 0;
    FUN_0006433c(203000.0f, DAT_003daec4);
  }
  FUN_002c00bc(DAT_003f4918);
}

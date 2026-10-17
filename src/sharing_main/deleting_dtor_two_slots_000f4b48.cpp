/* HSTMATCH module=hstp_trans_main.prx start=0x000f4b48 end=0x000f4c2c symbol=FUN_000f4b48 lang=c++ */
/* Clone of src/eboot/deleting_dtor_two_slots_000ef480.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5, variant v17c) corrected by hand: flag byte typed unsigned char, the global pointer read once into a local inside the flag block, locals declared index/walking pointer/element; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char undefined;

extern "C" {
extern undefined DAT_003b0bc0;
extern char * DAT_003daec4;
extern void FUN_00000a00(...);
extern int FUN_0005c688(...);
extern undefined4 * FUN_001087a8(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_000f4b48(undefined4 *param_1,short param_2)
{
  int iVar4;
  undefined4 *puVar3;
  int *piVar2;

  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0bc0);
    if (param_1[0x27] != 0) {
      FUN_0005c688(param_1[0x27],1);
      param_1[0x27] = 0;
    }
    iVar4 = 0;
    puVar3 = param_1;
    do {
      piVar2 = (int *)puVar3[0x25];
      if (piVar2 != (int *)0x0) {
        delete ((VC_0 *)(piVar2));
        puVar3[0x25] = 0;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < 2);
    if (*(unsigned char *)((int)param_1 + 0x55) != 0) {
      char *g = DAT_003daec4;
      *(undefined4 *)(g + 0xc) = 0;
      *(undefined *)(g + 0x52) = 0;
    }
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

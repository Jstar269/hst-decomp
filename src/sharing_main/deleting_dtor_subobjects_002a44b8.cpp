/* HSTMATCH module=hstp_trans_main.prx start=0x002a44b8 end=0x002a45ac symbol=FUN_002a44b8 lang=c++ */
/* Clone of src/eboot/deleting_dtor_subobjects_00292eac.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: declared loop counter before walking pointer to fix s2/s3 register allocation; exact match verified; names and types await human review. */

typedef unsigned int undefined4;

extern "C" {
extern char DAT_003b30b4;
extern char DAT_003b30c4;
extern void FUN_00000a00(void *);
extern int FUN_0005c688(int, int);
}

struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" undefined4 * FUN_002a44b8(undefined4 *param_1, short param_2)
{
  int i;
  undefined4 *puVar3;
  int *piVar1;
  int obj4;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b30b4);
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b30c4);
      piVar1 = (int *)param_1[3];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        param_1[3] = 0;
      }
      obj4 = param_1[4];
      if (obj4 != 0) {
        FUN_0005c688(obj4, 1);
        param_1[4] = 0;
      }
      i = 0;
      puVar3 = param_1;
      do {
        piVar1 = (int *)puVar3[6];
        if (piVar1 != (int *)0x0) {
          delete ((VC_1 *)(piVar1));
          puVar3[6] = 0;
        }
        i = i + 1;
        puVar3 = puVar3 + 1;
      } while (i < 7);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

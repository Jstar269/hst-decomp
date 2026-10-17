/* HSTMATCH module=hstp_trans_main.prx start=0x0001bb40 end=0x0001bc2c symbol=FUN_0001bb40 lang=c99 */
/* Clone of src/eboot/fun_0001c010.c (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: removed cc=gcc171-Os (retail is MWCC), typed 60.0f float literal for FUN_00062fd4, reordered *(uchar *)(param_1 + 0x1009) != 0 branch first, and added callback null check; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003b7e9c;
extern char DAT_00375104[];
extern void FUN_0001b6b4(char *, int);
extern int FUN_0001b928(int, int, int);
extern void FUN_0001bc34(int *);
extern int FUN_000465ec(void);
extern void FUN_00062fd4(float param_1);
extern void FUN_002c7690(void);
extern void FUN_002c7818(void);

int FUN_0001bb40(int *param_1, int param_2, uchar param_3)
{
  int iVar1;
  
  FUN_002c7690();
  FUN_0001bc34(param_1);
  FUN_0001b6b4(DAT_00375104, param_2);
  *(uchar *)(param_1 + 0x1009) = param_3;
  if (*(uchar *)(param_1 + 0x1009) != 0) {
    *param_1 = param_2;
    DAT_003b7e9c = 0x7fffffff;
  }
  else {
    *param_1 = FUN_0001b928(param_2, param_1[6], param_1[7]);
  }
  if ((*param_1 != 0) && ((void (*)(void))param_1[0x100a] != 0)) {
    ((void (*)(void))param_1[0x100a])();
  }
  if (FUN_000465ec() != 0) {
    for (iVar1 = 0; iVar1 < 3; iVar1++) {
      FUN_00062fd4(60.0f);
      FUN_002c7818();
    }
  }
  return *param_1 != 0;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001e8e6c end=0x001e8ed8 symbol=FUN_001e8e6c lang=c99 */
/* Clone of src/eboot/apply_vector_and_update_001dad88.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the float vector and helper argument order; exact match verified; names and types await human review. */
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
extern undefined4 DAT_003e19f0;
extern int FUN_00089f84(undefined4);
extern float *FUN_0009575c(int);
extern void FUN_001e8f98(float, void *, const float *);
extern void FUN_001e9328(void *);
void FUN_001e8e6c(void *param_1)
{
  int value = FUN_00089f84(DAT_003e19f0);
  float *source = FUN_0009575c(*(int *)(value + 0x5bc));
  float local[4];
  local[0] = source[0];
  local[1] = source[1];
  local[2] = source[2];
  local[3] = source[3];
  FUN_001e8f98(0.0f, param_1, local);
  FUN_001e9328(param_1);
}




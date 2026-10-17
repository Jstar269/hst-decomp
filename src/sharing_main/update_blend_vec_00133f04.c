/* HSTMATCH module=hstp_trans_main.prx start=0x00133f04 end=0x00133f7c symbol=FUN_00133f04 lang=c99 */
/* Clone of src/eboot/update_blend_vec_00128c94.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a/v2) corrected by hand: used a four-word float output local with an explicit pad; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern float FUN_0000c6f4(float param_1,float param_2);
struct Vec4 { float x, y, z; undefined4 pad; };
extern void FUN_00022540(struct Vec4 *, undefined1 (*) [12]);

void FUN_00133f04(int param_1,undefined1 (*param_2) [12],int param_3)
{
  float fVar1;
  struct Vec4 local_10;
  
  *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(param_1 + 0x1e4);
  FUN_00022540(&local_10,param_2);
  local_10.pad = 0;
  fVar1 = FUN_0000c6f4(local_10.x,local_10.z);
  *(float *)(param_1 + 0x1e4) = fVar1;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(param_1 + 0x1b0);
    *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x1b4);
    *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x1b8);
    *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x1bc);
    *(undefined1 *)(param_1 + 0x1e0) = 0;
  }
  return;
}

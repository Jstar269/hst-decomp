/* HSTMATCH module=EBOOT.BIN start=0x0024dd8c end=0x0024de20 symbol=FUN_0024dd8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a signed nonnegative loop edge and an offset-first sample address; exact match verified; names and types await human review. */
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


float FUN_0024dd8c(float param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  fVar4 = 0.0f;
  bVar1 = false;
  iVar3 = 8;
  iVar2 = param_2 + 0x20;
  do {
    if (*(float *)(iVar2 + 0x30) < param_1) {
      if (iVar3 == 8) {
        fVar4 = 1.0f;
        bVar1 = true;
      }
      else {
        iVar2 = iVar3 * 4;
        iVar2 = iVar2 + param_2;
        fVar4 = *(float *)(iVar2 + 0x30);
        bVar1 = true;
        fVar4 = (param_1 - fVar4) / (*(float *)(iVar2 + 0x34) - fVar4);
      }
      break;
    }
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + -4;
  } while (iVar3 >= 0);
  if (!bVar1) {
    fVar4 = param_1 / *(float *)(param_2 + 0x30);
  }
  return fVar4;
}

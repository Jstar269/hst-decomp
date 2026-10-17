/* HSTMATCH module=EBOOT.BIN start=0x002917ac end=0x00291868 symbol=FUN_002917ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed the mixed float arguments, stack depth float, and final color argument; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern void FUN_00051490(void *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7);
extern void FUN_0005185c(void *param_1);
extern void FUN_00051894(void *tex,float u0,float v0,float x0,float y0,float u1,float v1,float x1,float y1,float z,uint color);

void FUN_002917ac(void *param_1)
{
  float fVar2;
  int iVar1;
  
  FUN_00051490(param_1,0,0,0x1e0,0x110,0,0);
  fVar2 = 0.0f;
  iVar1 = 0;
  do {
    FUN_00051894(param_1,fVar2,0.0f,fVar2,0.0f,fVar2 + 120.0f,272.0f,fVar2 + 120.0f,272.0f,65535.0f,0x80808080);
    iVar1 = iVar1 + 1;
    fVar2 = fVar2 + 120.0f;
  } while (iVar1 < 4);
  FUN_0005185c(param_1);
  return;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x002a2db8 end=0x002a2e74 symbol=FUN_002a2db8 lang=c99 */
/* Clone of src/eboot/initialize_texture_grid_002917ac.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00051e30(void *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7);
extern void FUN_000522c0(void *param_1);
extern void FUN_00052354(void *tex,float u0,float v0,float x0,float y0,float u1,float v1,float x1,float y1,float z,uint color);

void FUN_002a2db8(void *param_1)
{
  float fVar2;
  int iVar1;
  
  FUN_00051e30(param_1,0,0,0x1e0,0x110,0,0);
  fVar2 = 0.0f;
  iVar1 = 0;
  do {
    FUN_00052354(param_1,fVar2,0.0f,fVar2,0.0f,fVar2 + 120.0f,272.0f,fVar2 + 120.0f,272.0f,65535.0f,0x80808080);
    iVar1 = iVar1 + 1;
    fVar2 = fVar2 + 120.0f;
  } while (iVar1 < 4);
  FUN_000522c0(param_1);
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x00216e90 end=0x00216f14 symbol=FUN_00216e90 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern int FUN_001039d8(void *param_1,const char *param_2,int param_3);

void FUN_00216e90(int *out,void *owner,const char **names,int count)
{
  int i;
  for (i = 0; i < count; i++) {
    int result = FUN_001039d8(owner,names[i],0);
    if (result != 0) out[i] = result;
  }
}

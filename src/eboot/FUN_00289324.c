/* HSTMATCH module=EBOOT.BIN start=0x00289324 end=0x00289330 symbol=FUN_00289324 lang=c99 */
/* Clone of src/eboot/FUN_00103474.c (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002fec0c;
extern void FUN_00286acc();

void FUN_00289324(void)
{
  FUN_00286acc((int)&DAT_002fec0c);
  return;
}

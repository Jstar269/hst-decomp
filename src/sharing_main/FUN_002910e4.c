/* HSTMATCH module=hstp_trans_main.prx start=0x002910e4 end=0x00291130 symbol=FUN_002910e4 lang=c99 */
/* Clone of src/eboot/FUN_0027fc70.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002db018;

void FUN_002910e4(uint *param_1,uint *param_2,uint param_3)
{
  *param_2 = *param_2 & 0xffffff | (uint)(byte)(&DAT_002db018)[*param_1 % 0x1e] << 0x18;
  *param_1 = *param_1 + (param_3 & 0xff);
  return;
}

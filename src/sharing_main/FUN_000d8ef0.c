/* HSTMATCH module=hstp_trans_main.prx start=0x000d8ef0 end=0x000d8f34 symbol=FUN_000d8ef0 lang=c99 */
/* Clone of src/eboot/FUN_000d5200.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0808;
extern int FUN_00000bcc();

void FUN_000d8ef0(int param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00000bcc(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = (unsigned int)(&DAT_003b0808);
    puVar1[1] = *(undefined4 *)(param_1 + 4);
  }
  return;
}

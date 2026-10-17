/* HSTMATCH module=hstp_trans_main.prx start=0x0017be40 end=0x0017be94 symbol=FUN_0017be40 lang=c99 */
/* Clone of src/eboot/FUN_0016fbf4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0017788c();
extern void FUN_0017cef0();
extern void FUN_0017d068();

void FUN_0017be40(int param_1)
{
  (**(code **)(param_1 + 0x53c))(*(undefined4 *)(param_1 + 0xb8));
  FUN_0017788c(*(undefined4 *)(param_1 + 0xbc));
  FUN_0017cef0(param_1,0);
  if (*(uchar *)(param_1 + 0x3e) != '\0') {
    FUN_0017d068(param_1);
  }
  return;
}

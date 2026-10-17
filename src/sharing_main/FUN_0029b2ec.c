/* HSTMATCH module=hstp_trans_main.prx start=0x0029b2ec end=0x0029b304 symbol=FUN_0029b2ec lang=c99 */
/* Clone of src/eboot/FUN_000b5d60.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


undefined4 * FUN_0029b2ec(undefined4 *param_1,undefined4 *param_2)
{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  return param_1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00121de8 end=0x00121eb4 symbol=FUN_00121de8 lang=c99 */
/* Clone of src/eboot/FUN_00116ecc.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b1274;
extern char DAT_003801d0[];
extern char DAT_003801f0[];
extern char DAT_00380210[];
extern uint * FUN_000114c0();
extern undefined4 * FUN_0001ec44();
extern void FUN_00121eb4();
extern void FUN_00121f3c();

undefined4 * FUN_00121de8(undefined4 *param_1)
{
  undefined4 *puVar1;
  
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b1274);
  param_1[0xf] = 4;
  *(undefined1 *)(param_1 + 0x10) = 0;
  puVar1 = param_1 + 0x20;
  do {
    puVar1[0xb] = 1;
    FUN_000114c0(puVar1,0,0x40);
    puVar1[0x10] = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0;
    *(undefined1 *)(puVar1 + 0x18) = 0;
    *(undefined1 *)((int)puVar1 + 0x61) = 0;
    puVar1 = puVar1 + 0x1c;
  } while (puVar1 < param_1 + 0x11c);
  FUN_00121eb4(DAT_003801d0,0x3f0);
  FUN_00121eb4(DAT_003801f0,0x90);
  FUN_00121eb4(DAT_00380210,0x24);
  FUN_00121f3c(param_1);
  return param_1;
}

/* HSTMATCH module=EBOOT.BIN start=0x001340d8 end=0x00134210 symbol=FUN_001340d8 lang=c99 rodata=0x002c1620 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
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

extern void FUN_00134210();
extern void FUN_00134414();
extern void FUN_00134548();
extern void FUN_00134e1c();
extern void FUN_001357dc();
extern void FUN_00136080();
extern void FUN_00136a28();
extern void FUN_00136b5c();
extern void FUN_00136c90();
extern void FUN_00136e94();
extern void FUN_00136fc8();
extern void FUN_001370fc();
extern void FUN_00137300();
extern void FUN_00137308();
extern void FUN_0013743c();
extern void FUN_00137570();

void FUN_001340d8(int param_1)
{
  switch(*(undefined4 *)(param_1 + 0x1364)) {
  case 0:
  case 10:
  case 0xb:
  case 0xc:
  case 0x13:
    break;
  case 1:
    FUN_00134210(param_1);
    break;
  case 2:
    FUN_00134414(param_1);
    break;
  case 3:
    FUN_00134548(param_1);
    break;
  case 4:
    FUN_00134e1c(param_1);
    break;
  case 5:
    FUN_001357dc(param_1);
    break;
  case 6:
    FUN_00136080(param_1);
    break;
  case 7:
    FUN_00136a28(param_1);
    break;
  case 8:
    FUN_00136b5c(param_1);
    break;
  case 9:
    FUN_00136c90(param_1);
    break;
  case 0xd:
    FUN_00136e94(param_1);
    break;
  case 0xe:
    FUN_00136fc8(param_1);
    break;
  case 0xf:
    FUN_001370fc(param_1);
    break;
  case 0x10:
    FUN_00137300();
    break;
  case 0x11:
    FUN_00137308(param_1);
    break;
  case 0x12:
    FUN_0013743c(param_1);
    break;
  case 0x14:
    FUN_00137570(param_1);
    break;
  default:
    goto switchD_00134104_default;
  }
switchD_00134104_default:
  return;
}

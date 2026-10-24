/* HSTMATCH module=EBOOT.BIN start=0x0020f540 end=0x0020f83c symbol=FUN_0020f540 lang=c99 rodata=0x002c953c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef unsigned int undefined4;

extern uint FUN_0001342c();

undefined4 FUN_0020f540(undefined4 param_1, undefined4 param_2, uint param_3)
{
  undefined4 uVar1;
  uint uVar2;

  uVar1 = 3;
  switch (param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    uVar1 = 1;
    break;
  case 2:
    uVar1 = 2;
    break;
  case 3:
    if ((param_3 & 1) != 0) {
      uVar1 = 0;
    }
    else {
      uVar2 = FUN_0001342c();
      uVar1 = (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f < 0.5f ? 1 : 2;
    }
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    if ((int)param_3 > 1) {
      uVar1 = 0;
      break;
    }
    uVar2 = FUN_0001342c();
    uVar1 = (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f < 0.5f ? 1 : 2;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    if ((int)param_3 > 1) {
      uVar2 = FUN_0001342c();
      uVar1 = (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f < 0.5f ? 1 : 2;
    }
    else {
      uVar1 = 0;
    }
    break;
  case 0xc:
    uVar1 = 0;
    break;
  case 0xd:
    uVar1 = 1;
    break;
  case 0xe:
    uVar1 = 0;
    break;
  case 0xf:
    uVar2 = FUN_0001342c();
    uVar1 = (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f < 0.5f ? 1 : 2;
    break;
  case 0x10:
    uVar1 = 0;
    break;
  case 0x11:
    uVar1 = 2;
    break;
  case 0x12:
    uVar1 = 2;
    break;
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
    if ((int)param_3 > 1) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
    break;
  case 0x17:
    uVar1 = 0;
    break;
  case 0x18:
    uVar1 = 1;
    break;
  case 0x19:
    uVar1 = 2;
    break;
  case 0x1a:
    uVar1 = 0;
    break;
  case 0x1b:
    uVar1 = 1;
    break;
  case 0x1c:
    uVar1 = 2;
    break;
  case 0x1d:
    uVar1 = 0;
    break;
  case 0x1e:
    uVar1 = 1;
    break;
  case 0x1f:
    uVar1 = 2;
    break;
  case 0x20:
    uVar1 = 0;
    break;
  case 0x21:
    uVar1 = 1;
    break;
  case 0x22:
    uVar1 = 2;
    break;
  case 0x23:
    uVar1 = 0;
    break;
  case 0x24:
    uVar1 = 1;
    break;
  case 0x25:
    uVar1 = 2;
    break;
  case 0x26:
    uVar1 = 0;
    break;
  case 0x27:
    uVar1 = 1;
    break;
  case 0x28:
    uVar1 = 0;
    break;
  case 0x29:
    uVar1 = 1;
    break;
  case 0x2a:
    if ((param_3 & 1) != 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    break;
  case 0x2b:
    uVar1 = 0;
    break;
  case 0x2c:
    uVar1 = 1;
    break;
  case 0x2d:
    uVar1 = 2;
    break;
  case 0x2e:
    uVar1 = 0;
    break;
  case 0x2f:
    uVar1 = 1;
    break;
  case 0x30:
    uVar1 = 2;
    break;
  case 0x31:
    uVar1 = 0;
    break;
  case 0x32:
    uVar1 = 0;
    break;
  case 0x33:
    uVar1 = 1;
    break;
  case 0x34:
    uVar1 = 0;
    break;
  case 0x35:
    uVar1 = 1;
    break;
  case 0x36:
    uVar1 = 2;
    break;
  case 0x37:
    uVar1 = 2;
  }
  return uVar1;
}

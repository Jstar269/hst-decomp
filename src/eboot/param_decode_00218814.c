/* HSTMATCH module=EBOOT.BIN start=0x00218814 end=0x00218a24 symbol=FUN_00218814 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;

void FUN_00218814(int *param_1, uint *param_2, uint param_3)
{
  if (param_3 == 0xcc) {
    *param_1 = 0;
    *param_2 = 0x11;
  }
  else if (param_3 == 0xcd) {
    *param_1 = 0;
    *param_2 = 0x1c;
  }
  else if (param_3 == 0xce) {
    *param_1 = 0;
    *param_2 = 0x1e;
  }
  else if (param_3 == 0xcf) {
    *param_1 = 0;
    *param_2 = 0x22;
  }
  else if (param_3 == 0xd0) {
    *param_1 = 0;
    *param_2 = 0x2d;
  }
  else if (param_3 == 0xfa) {
    *param_1 = 0;
    *param_2 = 0x2e;
  }
  else if (param_3 == 0xfb) {
    *param_1 = 0;
    *param_2 = 0x39;
  }
  else if (param_3 == 0xfc) {
    *param_1 = 0;
    *param_2 = 0x3d;
  }
  else if (param_3 == 0xfd) {
    *param_1 = 1;
    *param_2 = 4;
  }
  else if (param_3 == 0xfe) {
    *param_1 = 1;
    *param_2 = 6;
  }
  else if (param_3 == 0xff) {
    *param_1 = 1;
    *param_2 = 9;
  }
  else if (param_3 == 0x100) {
    *param_1 = 1;
    *param_2 = 0xb;
  }
  else if (param_3 == 0x101) {
    *param_1 = 1;
    *param_2 = 0x12;
  }
  else if (param_3 == 0x102) {
    *param_1 = 1;
    *param_2 = 0x13;
  }
  else if ((int)param_3 >= 600) {
    *param_1 = 7;
    *param_2 = param_3 - 600;
  }
  else if ((int)param_3 >= 500) {
    *param_1 = 6;
    *param_2 = param_3 - 500;
  }
  else if ((int)param_3 >= 400) {
    *param_1 = 5;
    *param_2 = param_3 - 400;
  }
  else if ((int)param_3 >= 300) {
    *param_1 = 4;
    *param_2 = param_3 - 300;
  }
  else {
    *param_1 = (int)param_3 / 64;
    *param_2 = (int)param_3 % 64;
  }
}

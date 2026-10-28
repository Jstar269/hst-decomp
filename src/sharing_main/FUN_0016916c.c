/* HSTMATCH module=hstp_trans_main.prx start=0x0016916c end=0x00169290 symbol=FUN_0016916c lang=c99 */
/* Clone of src/eboot/FUN_0015cbc4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0016916c(int param_1,u32 *param_2,int *param_3)
{
  if (param_1 < 4) {
    *param_2 = 10;
    *param_3 = param_1;
  }
  else if (param_1 + -4 < 0x3c) {
    *param_2 = 0;
    *param_3 = param_1 + -4;
  }
  else if (param_1 + -0x40 < 0x10) {
    *param_2 = 0xb;
    *param_3 = param_1 + -0x40;
  }
  else if (param_1 + -0x50 < 0x10) {
    *param_2 = 2;
    *param_3 = param_1 + -0x50;
  }
  else if (param_1 + -0x60 < 0x20) {
    *param_2 = 1;
    *param_3 = param_1 + -0x60;
  }
  else if (param_1 + -0x80 < 0x20) {
    *param_2 = 3;
    *param_3 = param_1 + -0x80;
  }
  else if (param_1 + -0xa0 < 0x10) {
    *param_2 = 4;
    *param_3 = param_1 + -0xa0;
  }
  else if (param_1 + -0xb0 < 0x20) {
    *param_2 = 5;
    *param_3 = param_1 + -0xb0;
  }
  else if (param_1 + -0xd0 < 0x10) {
    *param_2 = 6;
    *param_3 = param_1 + -0xd0;
  }
  else if (param_1 + -0xe4 < 0xc) {
    *param_2 = 7;
    *param_3 = param_1 + -0xe4;
  }
  else {
    *param_2 = 0xffffffff;
    *param_3 = -1;
  }
}

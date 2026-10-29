/* HSTMATCH module=EBOOT.BIN start=0x00218814 end=0x00218a24 symbol=FUN_00218814 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Ids 0..299 are group*ID_PAGE_SIZE+index; later bands start a new group. */
enum { ID_PAGE_SIZE = 64, ID_BAND_1 = 300, ID_BAND_2 = 400, ID_BAND_3 = 500, ID_BAND_4 = 600 };

void FUN_00218814(int *group, u32 *index, u32 id)
{
  if (id == 0xcc) {
    *group = 0;
    *index = 0x11;
  }
  else if (id == 0xcd) {
    *group = 0;
    *index = 0x1c;
  }
  else if (id == 0xce) {
    *group = 0;
    *index = 0x1e;
  }
  else if (id == 0xcf) {
    *group = 0;
    *index = 0x22;
  }
  else if (id == 0xd0) {
    *group = 0;
    *index = 0x2d;
  }
  else if (id == 0xfa) {
    *group = 0;
    *index = 0x2e;
  }
  else if (id == 0xfb) {
    *group = 0;
    *index = 0x39;
  }
  else if (id == 0xfc) {
    *group = 0;
    *index = 0x3d;
  }
  else if (id == 0xfd) {
    *group = 1;
    *index = 4;
  }
  else if (id == 0xfe) {
    *group = 1;
    *index = 6;
  }
  else if (id == 0xff) {
    *group = 1;
    *index = 9;
  }
  else if (id == 0x100) {
    *group = 1;
    *index = 0xb;
  }
  else if (id == 0x101) {
    *group = 1;
    *index = 0x12;
  }
  else if (id == 0x102) {
    *group = 1;
    *index = 0x13;
  }
  else if ((int)id >= ID_BAND_4) {
    *group = 7;
    *index = id - ID_BAND_4;
  }
  else if ((int)id >= ID_BAND_3) {
    *group = 6;
    *index = id - ID_BAND_3;
  }
  else if ((int)id >= ID_BAND_2) {
    *group = 5;
    *index = id - ID_BAND_2;
  }
  else if ((int)id >= ID_BAND_1) {
    *group = 4;
    *index = id - ID_BAND_1;
  }
  else {
    *group = (int)id / ID_PAGE_SIZE;
    *index = (int)id % ID_PAGE_SIZE;
  }
}

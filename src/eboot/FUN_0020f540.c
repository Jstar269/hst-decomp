/* HSTMATCH module=EBOOT.BIN start=0x0020f540 end=0x0020f83c symbol=FUN_0020f540 lang=c99 rodata=0x002c953c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

/* Result for an out-of-range code. */
#define DEFAULT_CHOICE 3

/* Picks 1 or 2 from a random word: clears its low 11 bits, scales by 2^-31 and compares with 0.5. */
#define COIN_FLIP(rnd) ((float)(int)((rnd) & 0xfffff800) * 4.656613e-10f < 0.5f ? 1 : 2)

/* Maps a code (0..0x37) and a count to a choice 0..2 (DEFAULT_CHOICE for other codes); some codes choose at random. */
u32 FUN_0020f540(u32 self, u32 code, u32 count)
{
  u32 result;
  u32 rnd;

  result = DEFAULT_CHOICE;
  switch (code) {
  case 0:
    result = 0;
    break;
  case 1:
    result = 1;
    break;
  case 2:
    result = 2;
    break;
  case 3:
    if ((count & 1) != 0) {
      result = 0;
    }
    else {
      rnd = FUN_0001342c();
      result = COIN_FLIP(rnd);
    }
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    if ((int)count > 1) {
      result = 0;
      break;
    }
    rnd = FUN_0001342c();
    result = COIN_FLIP(rnd);
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    if ((int)count > 1) {
      rnd = FUN_0001342c();
      result = COIN_FLIP(rnd);
    }
    else {
      result = 0;
    }
    break;
  case 0xc:
    result = 0;
    break;
  case 0xd:
    result = 1;
    break;
  case 0xe:
    result = 0;
    break;
  case 0xf:
    rnd = FUN_0001342c();
    result = COIN_FLIP(rnd);
    break;
  case 0x10:
    result = 0;
    break;
  case 0x11:
    result = 2;
    break;
  case 0x12:
    result = 2;
    break;
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
    if ((int)count > 1) {
      result = 1;
    }
    else {
      result = 0;
    }
    break;
  case 0x17:
    result = 0;
    break;
  case 0x18:
    result = 1;
    break;
  case 0x19:
    result = 2;
    break;
  case 0x1a:
    result = 0;
    break;
  case 0x1b:
    result = 1;
    break;
  case 0x1c:
    result = 2;
    break;
  case 0x1d:
    result = 0;
    break;
  case 0x1e:
    result = 1;
    break;
  case 0x1f:
    result = 2;
    break;
  case 0x20:
    result = 0;
    break;
  case 0x21:
    result = 1;
    break;
  case 0x22:
    result = 2;
    break;
  case 0x23:
    result = 0;
    break;
  case 0x24:
    result = 1;
    break;
  case 0x25:
    result = 2;
    break;
  case 0x26:
    result = 0;
    break;
  case 0x27:
    result = 1;
    break;
  case 0x28:
    result = 0;
    break;
  case 0x29:
    result = 1;
    break;
  case 0x2a:
    if ((count & 1) != 0) {
      result = 0;
    }
    else {
      result = 1;
    }
    break;
  case 0x2b:
    result = 0;
    break;
  case 0x2c:
    result = 1;
    break;
  case 0x2d:
    result = 2;
    break;
  case 0x2e:
    result = 0;
    break;
  case 0x2f:
    result = 1;
    break;
  case 0x30:
    result = 2;
    break;
  case 0x31:
    result = 0;
    break;
  case 0x32:
    result = 0;
    break;
  case 0x33:
    result = 1;
    break;
  case 0x34:
    result = 0;
    break;
  case 0x35:
    result = 1;
    break;
  case 0x36:
    result = 2;
    break;
  case 0x37:
    result = 2;
  }
  return result;
}

/* HSTMATCH module=EBOOT.BIN start=0x00278f7c end=0x00279138 symbol=FUN_00278f7c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: used a signed divisor and positive loop bound to reproduce retail digit extraction; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/shop_scene.h"

extern char DAT_002fe59c[];
extern void FUN_000143b0(void *, void *, int);
extern void FUN_000ffb3c(DigitPart *, int);
extern DigitPart * FUN_001026b8(u32, void *);

/* Shows the second number (digit parts DIGIT_COUNT..2*DIGIT_COUNT-1): all digit parts hidden when show is 0, otherwise value printed without leading zeros
   (the last digit is always shown). */
void FUN_00278f7c(ShopScene *screen,int value,u8 show)
{
  bool started;
  DigitPart *hide_part;
  DigitPart *digit_part;
  int index;
  int divisor;
  int digit;
  u8 name_hide [64];
  u8 name_digit [64];
  
  if (show == 0) {
    index = DIGIT_COUNT;
    do {
      FUN_000143b0(name_hide,DAT_002fe59c,index);
      hide_part = FUN_001026b8(screen->layout,name_hide);
      FUN_000ffb3c(hide_part,1);
      index = index + 1;
    } while (index < 2 * DIGIT_COUNT);
  }
  else {
    started = false;
    divisor = DIGIT_FIRST_DIVISOR;
    index = DIGIT_COUNT;
    do {
      digit = value / divisor;
      if (digit != 0) {
        started = true;
      }
      if (started) {
        FUN_000143b0(name_digit,DAT_002fe59c,index);
        digit_part = FUN_001026b8(screen->layout,name_digit);
        digit_part->unk24 = digit_part->unk28 + digit;
        hide_part = FUN_001026b8(screen->layout,name_digit);
        FUN_000ffb3c(hide_part,0);
      }
      else if (divisor == 1) {
        FUN_000143b0(name_digit,DAT_002fe59c,index);
        digit_part = FUN_001026b8(screen->layout,name_digit);
        digit_part->unk24 = digit_part->unk28;
        hide_part = FUN_001026b8(screen->layout,name_digit);
        FUN_000ffb3c(hide_part,0);
      }
      else {
        FUN_000143b0(name_digit,DAT_002fe59c,index);
        hide_part = FUN_001026b8(screen->layout,name_digit);
        FUN_000ffb3c(hide_part,1);
      }
      value = value - digit * divisor;
      divisor = divisor / 10;
      index = index + 1;
    } while (divisor > 0);
  }
}

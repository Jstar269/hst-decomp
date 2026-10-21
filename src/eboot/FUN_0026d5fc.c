/* HSTMATCH module=EBOOT.BIN start=0x0026d5fc end=0x0026d714 symbol=FUN_0026d5fc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane u6cr1-1, hstgen tag a1 origin) corrected by hand: the type/subtype tests are one && condition and the loop count is re-read once for the loop test; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
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

extern void FUN_00277a1c();
extern void FUN_00279b24();

struct Item_26d5fc {
  unsigned char byte0;
  unsigned char small;
  unsigned char flag;
  char pad03[0x11];
  int type;
  int subtype;
};

struct ItemVector_26d5fc {
  struct Item_26d5fc **data;
  unsigned int count;
};

void FUN_0026d5fc(int param_1,undefined4 param_2)
{
  struct ItemVector_26d5fc *items;
  struct Item_26d5fc *item;
  unsigned int index;
  unsigned int count;
  
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0x104);
  *(undefined4 *)(param_1 + 0x104) = param_2;
  *(undefined1 *)(param_1 + 0x110) = 1;
  *(undefined4 *)(param_1 + 0x180) = 0xffffffff;
  FUN_00279b24();
  *(undefined4 *)(param_1 + 0x458) = 0;
  FUN_00277a1c(param_1,*(undefined4 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x104));
  *(undefined1 *)(param_1 + 0x8c3) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined1 *)(param_1 + 0x8c4) = 0;
  *(undefined4 *)(param_1 + 0x8bc) = 0;
  *(undefined4 *)(param_1 + 0x8c8) = 0;
  if (*(int *)(param_1 + 0x104) != 7 && *(int *)(param_1 + 0x104) != 1) {
    *(undefined1 *)(param_1 + 0xf8) = 0;
  }
  *(undefined4 *)(param_1 + 0x99c) = 0;
  *(undefined4 *)(param_1 + 0x9a0) = 0;
  *(undefined4 *)(param_1 + 0x9a4) = 0;
  *(undefined4 *)(param_1 + 0x9a8) = 0;
  *(undefined4 *)(param_1 + 0x9ac) = 0;
  *(undefined1 *)(param_1 + 0x8ce) = 0;
  items = (struct ItemVector_26d5fc *)(param_1 + 0xd8);
  index = 0;
  if (items->count != 0) {
    do {
      item = items->data[index];
      if (item->flag == 1) {
        item->small = 0;
      }
      item = items->data[index];
      if (item->type == 4 && item->subtype == 5) {
        item->flag = 0;
      }
      count = items->count;
      index = index + 1;
    } while (index < count);
  }
  return;
}
// Near miss: two words differ at +0xe8; this source emits bnel v1,a0 with the count load in its delay slot, while retail emits bne v1,a0 with a nop.
// Combined, nested, goto, and continue forms changed the loop layout or retained this branch and delay-slot difference.
// near miss from lane u6cr1-1 (unreviewed)

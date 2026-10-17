/* HSTMATCH module=EBOOT.BIN start=0x001aa770 end=0x001aa850 symbol=FUN_001aa770 lang=c99 */
typedef unsigned int uint;
typedef unsigned char uchar;

extern void FUN_000ffb3c();
extern uint FUN_0019d474();

void FUN_001aa770(int self)
{
  int *first;
  char *state;
  int *second;
  int *third;
  int value;

  FUN_0019d474(self);
  state = (char *)FUN_0019d474() + 0x318;
  first = (int *)(self + 0x250);
  second = (int *)(self + 0x264);
  third = (int *)(self + 0x278);

  if (*(int *)state == 0) {
    if (*(int *)(state + 4) == 0) {
      FUN_000ffb3c(*first, 1);
      FUN_000ffb3c(*second, 1);
      FUN_000ffb3c(*third, 1);
      return;
    }
  }
  FUN_000ffb3c(*first, 0);
  value = *(int *)(*first + 0x28);
  value += *(int *)state;
  *(int *)(*first + 0x24) = value;
  FUN_000ffb3c(*second, 0);
  value = *(int *)(*second + 0x28);
  value += *(int *)(state + 4);
  *(int *)(*second + 0x24) = value;
  FUN_000ffb3c(*third, 0);
}
// Near miss: 6 words differ at the two add instructions after field-plus-state updates; direct expressions and a reused local accumulator were tried, and both produced the opposite addu operand order.
// near miss from lane cx9 (unreviewed)

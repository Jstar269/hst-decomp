/* HSTMATCH module=EBOOT.BIN start=0x00106bb4 end=0x00106c08 symbol=FUN_00106bb4 lang=c99 */

struct List { int count; int pad; char *data; };
struct Owner { char pad[0x54]; struct List *f54; };

void *FUN_00106bb4(struct Owner *self, int idx)
{
  struct List *list;
  int count;

  list = self->f54;
  if (list == 0) {
    return (char *)self + 0x59;
  }
  count = list->count;
  if (idx < 0) {
    return (char *)self + 0x59;
  }
  if (count < 2) {
    return (char *)self + 0x59;
  }
  if (idx + 1 >= count) {
    return (char *)self + 0x59;
  }
  return list->data + idx * 0x80;
}
// NEAR 17/21 words (0x00106bb4). The four guards (null list, negative index, count < 2,
// idx+1 >= count) and the `list->data + idx * 0x80` result are right, and hoisting `list->count`
// into a local right after the null test is what puts the load in the bnezl delay. Left: retail
// also emits an explicit `b` to the shared default block (`addiu v0,self+0x59` in its delay) and
// jumps there from the idx test with `bltzl`; ours keeps the addiu at each return site and inverts
// the idx test to `bgezl`. The single-return `if (list && idx >= 0 && ...)` form is worse (20/21
// words, 20 differ) because it turns the null test into beqzl.
// near miss from lane fm5 (unreviewed)

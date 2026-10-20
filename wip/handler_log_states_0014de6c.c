/* HSTMATCH module=EBOOT.BIN start=0x0014de6c end=0x0014df40 symbol=FUN_0014de6c lang=c99 */

typedef struct {
  char pad[8];
  int state;
} Sub;

typedef struct {
  char pad[0x18];
  int count;
  Sub *sub;
} Obj;

extern unsigned char DAT_003402f0;
extern char DAT_002ec240[];
extern char DAT_002ec24c[];
extern char DAT_002ec314[];
extern void FUN_0014c610(const char *fmt);
extern void FUN_0014f3cc(void *out, void *list, int *pos);

int FUN_0014de6c(void *self, Obj *obj)
{
  void *out;
  int pos;
  int state;
  int i;

  pos = (int)obj->sub;
  FUN_0014f3cc(&out, &obj->count, &pos);
  if (DAT_003402f0 == 0)
    return 0;
  state = 0;
  if (obj->count > 0)
    state = obj->sub->state;
  if (state == 1 || state == 2)
    return 0;
  if (DAT_003402f0 == 0)
    goto last;
  FUN_0014c610(DAT_002ec240);
  if (obj->count + 1 > 0) {
    i = 0;
    do {
      FUN_0014c610(DAT_002ec24c);
      i++;
    } while (i < obj->count + 1);
  }
last:
  FUN_0014c610(DAT_002ec314);
  return 0;
}
// Best form (55/53 words): structure is right (list erase via 0x14f3cc, flag guard, state from
// obj->f1c->f8, two skipped state values, then three variadic debug-print calls 0x2ec240/0x2ec24c/
// 0x2ec314 with a print loop for obj->count+1). Open points: retail tests the two states with two
// `xori/sltiu/../bnez` bool forms (ours uses `sltiu at,v0,2` or bnel compares), keeps the loop counter
// in v1 ACROSS the jal (it treats the variadic stub 0x14c610 as preserving v1), and keeps `lbu a0` live
// for a second `beqz a0` test that is never taken. Tried: ||, bitwise |, bool locals, two separate ifs.
// near miss from lane ds6 (unreviewed)

// NEAR 2/77 words: only the FRAME SIZE is left (ours 32, retail 48); every instruction matches.
// The 13-word colouring gap closed by declaring `unsigned int i;` BEFORE `unsigned char *src;`
// (later-declared locals get the lower s-register): that gives retail's i=s3 / src=s2. The earlier
// note's permutations all kept `src` first.
// The 16 unused bytes at 32..47(sp) are the last word: retail allocates a 32-byte local area with
// nothing referencing it above offset 8. Ruled out: unused `char buf[16]`, `volatile char pad[16]`,
// and an address-taken `char buf[16]` handed to a `__inline` no-op (all keep the 32-byte frame).
// The slot is probably a by-value 16-byte object or a 4-word outgoing area that never gets stored;
// no call in the body has stack arguments.
/* HSTMATCH module=EBOOT.BIN start=0x00102824 end=0x00102958 symbol=FUN_00102824 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned char bool;

extern undefined1 DAT_0033b394;
extern undefined1 DAT_0033a6e0;
extern int DAT_0033b45c;
extern undefined1 DAT_002d8a28;
extern void FUN_000114c0(void *, int, int);
extern void FUN_000149a8(void *, void *);
extern void FUN_00014788(void *, undefined1 *);

void FUN_00102824(int *param_1)
{
  unsigned int i;
  unsigned char *src;
  int *p;
  int *e;
  int v;
  unsigned char *dst;
  int more;

  p = (int *)param_1[1];
  more = !(p == (int *)param_1[1] + param_1[2]);
  while (more) {
    e = (int *)*p;
    v = *(int *)((int)e + 0x54);
    src = (unsigned char *)e + 0x59;
    if (DAT_0033b45c == 0) {
      FUN_000114c0(&DAT_0033b394,0,200);
    }
    for (i = 0; i < 50; i++) {
      if (((int *)&DAT_0033b394)[i] == 0) {
        dst = (unsigned char *)&DAT_0033a6e0 + i * 65;
        FUN_000149a8(dst,src);
        FUN_00014788(dst,&DAT_002d8a28);
        ((int *)&DAT_0033b394)[i] = v;
        DAT_0033b45c = DAT_0033b45c + 1;
        break;
      }
    }
    p = p + 1;
    more = !(p == (int *)param_1[1] + param_1[2]);
  }
}
// improved by lane fm5 (unreviewed): 69 -> 2 differing words

/* HSTMATCH module=EBOOT.BIN start=0x00270738 end=0x002708ac symbol=FUN_00270738 lang=c++ */
struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

extern "C" int FUN_002791a4(int, int);
extern "C" int FUN_00279578(int, int);
extern "C" void FUN_0001ca58(int, int, int, int, int, int);
extern "C" void FUN_0001cb88(int);
extern "C" int FUN_00000bcc(int);
extern "C" int FUN_00094fa4(int);
extern "C" unsigned char FUN_00095104(int, int, int, int, int);
extern "C" char DAT_0030ebf4[];
extern "C" char DAT_002fe2b4[];
extern "C" char DAT_002fe330[];
extern "C" char DAT_002fe2d0[];

extern "C" void FUN_00270738(int param_1)
{
  int iVar2;
  int iVar3;
  int uVar4;
  RefObj *p;
  unsigned char cVar1;

  iVar2 = FUN_002791a4(param_1,4);
  iVar3 = FUN_00279578(param_1,4);
  iVar2 = iVar2 + iVar3 * 4;
  if (*(int *)(param_1 + 0x180) < 0) {
    return;
  }
  iVar2 = iVar2 * 0x30;
  FUN_0001ca58(0x30ebf4,(int)DAT_002fe2b4,(int)DAT_002fe330,(int)DAT_002fe330,
               *(int *)(*(int *)(param_1 + 0x90) + iVar2 + 8) / 10,(int)DAT_002fe2d0);
  p = *(RefObj **)(param_1 + 0xf0);
  if (p != 0) {
    if (p != 0) {
      p->Release(1);
    }
    *(int *)(param_1 + 0xf0) = 0;
  }
  iVar3 = FUN_00000bcc(0x1c0);
  *(int *)(param_1 + 0xf0) = iVar3;
  uVar4 = iVar3;
  if (iVar3 != 0) {
    uVar4 = FUN_00094fa4(iVar3);
    *(int *)(param_1 + 0xf0) = uVar4;
  }
  cVar1 = FUN_00095104(uVar4,5,*(int *)(*(int *)(param_1 + 0x90) + iVar2 + 8) / 10,0,0);
  if (cVar1 == 0) {
    p = *(RefObj **)(param_1 + 0xf0);
    if (p != 0) {
      if (p != 0) {
        p->Release(1);
      }
      *(int *)(param_1 + 0xf0) = 0;
    }
  }
  FUN_0001cb88(0x30ebf4);
}
// NEAR (93/93 words, 22 differing): the allocation block, the two release guards and the second
// panel call now match exactly. The 22 remaining words are one scheduling permutation in the first
// call's argument setup: retail loads the table base into v1 before the magic constant
// (`lw v1,144(s1); lui v0,0x6666; ...; addu v1,v1,s0; lw v1,8(v1); ori v0,v0,0x6667; mult v0,v1`),
// ours hoists the magic and uses a0 for the base. What got here:
// - the three 0x2fe... constants must be *symbol addresses*, not integer literals: as literals MWCC
//   shares one `lui 0x2f` and oris the low halves (2 words short), while `(int)DAT_...` arrays give
//   retail's `lui 0x30; addiu -7376` pairs and the exact word count. 0x30ebf4 stays a literal
//   (`lui 0x31; ori`), which is also retail's form.
// - the alloc/init block is `p = alloc(); self->f0 = p; uVar4 = p; if (p) { uVar4 = init(p);
//   self->f0 = uVar4; }` — storing the raw result before the test is what puts retail's
//   `sw v0,240(s1)` in the `beqzl` delay slot, and keeping uVar4 in the same register as p removes
//   the `move v0,zero` / `b` pair.
// - the panel test must use an `unsigned char` return type; `char` adds a `seb` (that was the extra
//   word in the previous candidate).
// Ruled out: computing the element into a local (69 words), a two-step load (85), an `int *tbl`
// pointer (91), and every literal/symbol mix other than three-symbols-plus-literal-lead.
// improved by lane fm5 (unreviewed): 75 -> 22 differing words
// improved by lane ag2 (unreviewed): no comparable result -> 22 differing words
// improved by lane sn8 (unreviewed): no comparable result -> 22 differing words

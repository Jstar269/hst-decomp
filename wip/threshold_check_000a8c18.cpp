/* HSTMATCH module=EBOOT.BIN start=0x000a8c18 end=0x000a8c98 symbol=FUN_000a8c18 lang=c++ */
/* Hand-written reconstruction from the disassembly; near miss (8 words, FPR numbering only); names and types await human review. */
struct Ctx { char pad[0x24]; float f24; };
struct Obj { char pad[4]; float f4; };
extern "C" {
extern float DAT_003411fc;
extern Ctx *FUN_000b3c68(void);
}

extern "C" int FUN_000a8c18(void *a, Obj *p)
{
    Ctx *c = FUN_000b3c68();
    if (p->f4 > DAT_003411fc * 0.01f * -(c->f24 * 0.01f) && p->f4 < 0.0f) return 1;
    return 0;
}
// Only the float register numbering differs: ours c24=$f0 x=$f3 K=$f2 prod=$f1, retail c24=$f0 x=$f1 K=$f3 prod=$f2
// (c.ngt.s f1,f0 / c.lt.s f1,f0, branch layout and both mul/neg orders are exact). A single `&&` in one if is the only
// shape that gives retail's `bc1tl; move v0,zero` / `bc1f; nop; b; li 1; move 0` tail (nested ifs, early returns,
// int r variables and ternaries are 17-24 words off or add andi).
// Ruled out (all give the same FPR numbering): float locals for x / c->f24 / DAT in every declaration order, partial
// results in locals (na, b, t), trivial inline getters on any of the three loads, an inline Cm(v)=v*0.01f helper,
// swapped product order, mirrored compares (T < x), !(x <= T), lang=c99. With x used only once ($f0 for x, $f1
// for c24, K=$f3, prod=$f2) the numbering moves toward retail, so retail's x probably has a different live range.

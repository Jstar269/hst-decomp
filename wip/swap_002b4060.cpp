/* HSTMATCH module=EBOOT.BIN start=0x002b4060 end=0x002b40b0 symbol=FUN_002b4060 lang=c++ */
struct S { int w00; char a04[32]; char a24[32]; char c44,c45,c46; unsigned char b47,b48; char c49,c4a,c4b; int w4c,w50; char a54[16]; S() {} };
extern "C" S *FUN_002b4194(S *, const S *);
extern "C" S *FUN_002b40b0(S *, const S *);
extern "C" void FUN_002b4060(S *a, S *b)
{
    S tmp; FUN_002b4194(&tmp, a); FUN_002b40b0(a, b); FUN_002b40b0(b, &tmp);
}
// Near miss (sn7): 6 words differ, only the s0/s1 naming: ours a=s1,b=s0 (move s1,a0; move s0,a1), retail a=s0,b=s1.
// Ruled out (~25 compiles): typed struct S (assign_002b40b0 layout) and plain T[100], C and C++, extern "C" helpers returning S*,
// local copies p/q in all 4 declaration orders (tmp before/after), inline swap(T*,T*)/swap(T&,T&)/inline ctor+operator=,
// inline cp() wrappers, const S* second param, reference params, t=&tmp local, unused result local, static same-file helpers (UNPLACED).
// Untried: a hidden extra use of param a (use-count priority, NOTES 2026-10-15 0x1b8da8) that emits no code.
// near miss from lane sn7 (unreviewed)

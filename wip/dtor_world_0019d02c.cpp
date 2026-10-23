/* HSTMATCH module=EBOOT.BIN start=0x0019d02c end=0x0019d1a4 symbol=FUN_0019d02c lang=c++ */
// NEAR MISS (structural notes only, not yet compiled to a lower count): 94 words, generated
// draft 80 differ.  This is the deleting destructor of the "world/scene" object; the retail
// body, in order:
//   if (self == 0) return;  *self = &DAT_00309230;                       (vptr, 0x309230)
//   if (DAT_0034a81c != 0 && FUN_002911c0(DAT_0034a818) != 0) FUN_002911cc(DAT_0034a818);
//   if (DAT_0034a81c != 0) { if (DAT_0034a81c != 0) delete DAT_0034a81c; DAT_0034a81c = 0; }
//       (two nested null tests, the inner one is delete's own; virtual slot 0 = offset 8, a1 = 1)
//   FUN_00291340(); FUN_001b3e2c(&DAT_0034179c); FUN_001b338c(&DAT_0034179c, 0xd);
//   FUN_001b2c70(&DAT_0034179c);
//   if (self[0x23] != 0) { delete self[0x23]; self[0x23] = 0; }          (+0x8c, beqzl with
//       `sw zero,140(s1)` copied into its delay slot, and the store repeated after the call)
//   if (self[0x15] != 0) { FUN_000006e8(self[0x15], FUN_000510c0); self[0x15] = 0; }  (+0x54)
//   *(void **)((char *)self + 0xa0) = &DAT_0030926c; FUN_00102ea4((char *)self + 0xa0, 0);
//   FUN_000462a0((char *)self + 0x74, -1); FUN_00004138((char *)self + 0x68, 0);
//   FUN_00102ea4(self, 0);
//   if (0 < flag) operator delete(self);
//   return self;
// The three `beqzl <address-of-subobject>` tests retail keeps (`addiu a0,s1,160` /
// `addiu v0,s1,104` feeding a `beqzl` to the join) are the `if (this)` null checks of
// INLINED member destructors, so this only has a chance as a real C++ class model: a class
// whose member at +0xa0 derives from a base with an out-of-line destructor at 0x102ea4, a
// member at +0x68 with two sub-destructors (0x462a0/-1 at +0x74 and 0x4138/0 at +0x68), a
// `Del *` at +0x8c and a raw pointer at +0x54 released through FUN_000006e8.  Building that
// class hierarchy (and the vtable symbol for +0xa0, 0x30926c) is the next step; the plain
// C transcription loses all three dead null tests and the delay-slot stores.
// near miss from lane fm5 (unreviewed)

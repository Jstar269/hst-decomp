/* HSTMATCH module=EBOOT.BIN start=0x000d98ac end=0x000d9910 symbol=__dt__10C_000d98acFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct A_000d98ac { int a; };
class B_000d9f40 { public: int b; ~B_000d9f40(); };
class M_000d98ac : public B_000d9f40 { public: ~M_000d98ac() {} };
class N_000d98ac : public M_000d98ac { public: ~N_000d98ac() {} };
class C_000d98ac : public A_000d98ac, public N_000d98ac { public: ~C_000d98ac(); };
// d2.cpp variant (N as a member at +4 instead of a base) also matches exactly.
C_000d98ac::~C_000d98ac() {}

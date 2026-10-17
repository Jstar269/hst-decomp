/* HSTMATCH module=EBOOT.BIN start=0x000b7d6c end=0x000b7dd8 symbol=__dt__10C_000b7d6cFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x30731c, 0x307388, 0x3073ac) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_003073ac { public: virtual void key_003073ac(); virtual ~A_003073ac() {} };
class B_00307388 : public A_003073ac { public: virtual void key_00307388(); virtual ~B_00307388() {} };
class C_000b7d6c : public B_00307388 { public: virtual void key_000b7d6c(); virtual ~C_000b7d6c(); };
C_000b7d6c::~C_000b7d6c() {}

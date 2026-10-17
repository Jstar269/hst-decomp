/* HSTMATCH module=hstp_trans_main.prx start=0x000bd240 end=0x000bd2bc symbol=__dt__10D_000bd240Fv */
/* Clone of src/eboot/dtor_000b9efc.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Four-level polymorphic hierarchy with empty virtual destructors (extends the three-level chain of dtor_000b7d6c.cpp by one derived class): each level restores its own vtable (0x3b05a0, 0x3b05e8, 0x3b0654, 0x3b0678) before the deleting tail; the inner destructors are inline so each keeps its own `if (this)`. The key functions keep the vtables out of this unit. Names provisional. */
class A_003b0678 { public: virtual void key_003b0678(); virtual ~A_003b0678() {} };
class B_003b0654 : public A_003b0678 { public: virtual void key_003b0654(); virtual ~B_003b0654() {} };
class C_000b7d6c : public B_003b0654 { public: virtual void key_000b7d6c(); virtual ~C_000b7d6c() {} };
class D_000bd240 : public C_000b7d6c { public: virtual void key_000bd240(); virtual ~D_000bd240(); };
D_000bd240::~D_000bd240() {}

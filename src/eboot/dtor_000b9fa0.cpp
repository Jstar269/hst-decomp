/* HSTMATCH module=EBOOT.BIN start=0x000b9fa0 end=0x000ba01c symbol=__dt__10D_000b9fa0Fv */
/* Clone of src/eboot/dtor_000b9efc.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Four-level polymorphic hierarchy with empty virtual destructors (extends the three-level chain of dtor_000b7d6c.cpp by one derived class): each level restores its own vtable (0x3072f8, 0x30731c, 0x307388, 0x3073ac) before the deleting tail; the inner destructors are inline so each keeps its own `if (this)`. The key functions keep the vtables out of this unit. Names provisional. */
class A_003073ac { public: virtual void key_003073ac(); virtual ~A_003073ac() {} };
class B_00307388 : public A_003073ac { public: virtual void key_00307388(); virtual ~B_00307388() {} };
class C_000b7d6c : public B_00307388 { public: virtual void key_000b7d6c(); virtual ~C_000b7d6c() {} };
class D_000b9fa0 : public C_000b7d6c { public: virtual void key_000b9fa0(); virtual ~D_000b9fa0(); };
D_000b9fa0::~D_000b9fa0() {}

/* HSTMATCH module=EBOOT.BIN start=0x000ce820 end=0x000ce88c symbol=__dt__10C_000ce820Fv */
/* Clone of src/eboot/dtor_000b7d6c.cpp (hstclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x307564, 0x307550, 0x30753c) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_0030753c { public: virtual void key_0030753c(); virtual ~A_0030753c() {} };
class B_00307550 : public A_0030753c { public: virtual void key_00307550(); virtual ~B_00307550() {} };
class C_000ce820 : public B_00307550 { public: virtual void key_000ce820(); virtual ~C_000ce820(); };
C_000ce820::~C_000ce820() {}

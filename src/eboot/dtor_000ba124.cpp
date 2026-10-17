/* HSTMATCH module=EBOOT.BIN start=0x000ba124 end=0x000ba190 symbol=__dt__10C_000ba124Fv */
/* Clone of src/eboot/dtor_000b7d6c.cpp (hstclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x307364, 0x307388, 0x3073ac) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_003073ac { public: virtual void key_003073ac(); virtual ~A_003073ac() {} };
class B_00307388 : public A_003073ac { public: virtual void key_00307388(); virtual ~B_00307388() {} };
class C_000ba124 : public B_00307388 { public: virtual void key_000ba124(); virtual ~C_000ba124(); };
C_000ba124::~C_000ba124() {}

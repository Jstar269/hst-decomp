/* HSTMATCH module=EBOOT.BIN start=0x0014ec8c end=0x0014ecf8 symbol=__dt__10C_0014ec8cFv */
/* Clone of src/eboot/dtor_000b7d6c.cpp (hstclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x308310, 0x30832c, 0x30840c) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_0030840c { public: virtual void key_0030840c(); virtual ~A_0030840c() {} };
class B_0030832c : public A_0030840c { public: virtual void key_0030832c(); virtual ~B_0030832c() {} };
class C_0014ec8c : public B_0030832c { public: virtual void key_0014ec8c(); virtual ~C_0014ec8c(); };
C_0014ec8c::~C_0014ec8c() {}

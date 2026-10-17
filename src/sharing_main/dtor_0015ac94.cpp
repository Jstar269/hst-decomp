/* HSTMATCH module=hstp_trans_main.prx start=0x0015ac94 end=0x0015ad00 symbol=__dt__10C_0015ac94Fv */
/* Clone of src/eboot/dtor_000b7d6c.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x3b15dc, 0x3b15f8, 0x3b16d8) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_003b16d8 { public: virtual void key_003b16d8(); virtual ~A_003b16d8() {} };
class B_003b15f8 : public A_003b16d8 { public: virtual void key_003b15f8(); virtual ~B_003b15f8() {} };
class C_0015ac94 : public B_003b15f8 { public: virtual void key_0015ac94(); virtual ~C_0015ac94(); };
C_0015ac94::~C_0015ac94() {}

/* HSTMATCH module=hstp_trans_main.prx start=0x000bb05c end=0x000bb0c8 symbol=__dt__10C_000bb05cFv */
/* Clone of src/eboot/dtor_000b7d6c.cpp (hstclone.py tag x18): addresses substituted; exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x3b05e8, 0x3b0654, 0x3b0678) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_003b0678 { public: virtual void key_003b0678(); virtual ~A_003b0678() {} };
class B_003b0654 : public A_003b0678 { public: virtual void key_003b0654(); virtual ~B_003b0654() {} };
class C_000bb05c : public B_003b0654 { public: virtual void key_000bb05c(); virtual ~C_000bb05c(); };
C_000bb05c::~C_000bb05c() {}

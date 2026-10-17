/* HSTMATCH module=hstp_trans_main.prx start=0x000d241c end=0x000d2488 symbol=__dt__10C_000d241cFv */
/* Clone of src/eboot/dtor_000b7d6c.cpp (hstclone.py tag x18): addresses substituted; exact match verified; names and types await human review. */
/* Three-level polymorphic hierarchy with empty virtual destructors: each level restores its own vtable
   (0x3b0830, 0x3b081c, 0x3b0808) before the deleting tail. The key functions keep the vtables out of this
   unit. Names provisional. */
class A_003b0808 { public: virtual void key_003b0808(); virtual ~A_003b0808() {} };
class B_003b081c : public A_003b0808 { public: virtual void key_003b081c(); virtual ~B_003b081c() {} };
class C_000d241c : public B_003b081c { public: virtual void key_000d241c(); virtual ~C_000d241c(); };
C_000d241c::~C_000d241c() {}

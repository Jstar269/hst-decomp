/* HSTMATCH module=hstp_trans_main.prx start=0x000dd818 end=0x000dd87c symbol=__dt__10C_000dd818Fv */
/* Clone of src/eboot/dtor_000d98ac.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct A_000dd818 { int a; };
class B_000ddf00 { public: int b; ~B_000ddf00(); };
class M_000dd818 : public B_000ddf00 { public: ~M_000dd818() {} };
class N_000dd818 : public M_000dd818 { public: ~N_000dd818() {} };
class C_000dd818 : public A_000dd818, public N_000dd818 { public: ~C_000dd818(); };
// d2.cpp variant (N as a member at +4 instead of a base) also matches exactly.
C_000dd818::~C_000dd818() {}

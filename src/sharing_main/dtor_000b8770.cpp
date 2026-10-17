/* HSTMATCH module=hstp_trans_main.prx start=0x000b8770 end=0x000b87dc symbol=__dt__10C_000b8770Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000b886c(void *self);
struct Blob_000b8770 { int v; ~Blob_000b8770() {} };
class B_000b8770 { public: Blob_000b8770 *data; ~B_000b8770() { FUN_000b886c(this); delete data; } };
class C_000b8770 : public B_000b8770 { public: int count; ~C_000b8770(); };
C_000b8770::~C_000b8770() { count = 0; }

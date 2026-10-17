/* HSTMATCH module=hstp_trans_main.prx start=0x0006ed80 end=0x0006edec symbol=__dt__10C_0006ed80Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0006edec(void *self);
struct Blob_0006ed80 { int v; ~Blob_0006ed80() {} };
class B_0006ed80 { public: Blob_0006ed80 *data; ~B_0006ed80() { FUN_0006edec(this); delete data; } };
class C_0006ed80 : public B_0006ed80 { public: int count; ~C_0006ed80(); };
C_0006ed80::~C_0006ed80() { count = 0; }

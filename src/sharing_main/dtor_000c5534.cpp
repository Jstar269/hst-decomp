/* HSTMATCH module=hstp_trans_main.prx start=0x000c5534 end=0x000c55a0 symbol=__dt__10C_000c5534Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000c55a0(void *self);
struct Blob_000c5534 { int v; ~Blob_000c5534() {} };
class B_000c5534 { public: Blob_000c5534 *data; ~B_000c5534() { FUN_000c55a0(this); delete data; } };
class C_000c5534 : public B_000c5534 { public: int count; ~C_000c5534(); };
C_000c5534::~C_000c5534() { count = 0; }

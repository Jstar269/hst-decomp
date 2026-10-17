/* HSTMATCH module=hstp_trans_main.prx start=0x000ee5d8 end=0x000ee644 symbol=__dt__10C_000ee5d8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000ee644(void *self);
struct Blob_000ee5d8 { int v; ~Blob_000ee5d8() {} };
class B_000ee5d8 { public: Blob_000ee5d8 *data; ~B_000ee5d8() { FUN_000ee644(this); delete data; } };
class C_000ee5d8 : public B_000ee5d8 { public: int count; ~C_000ee5d8(); };
C_000ee5d8::~C_000ee5d8() { count = 0; }

/* HSTMATCH module=hstp_trans_main.prx start=0x000db2f8 end=0x000db364 symbol=__dt__10C_000db2f8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000db5d4(void *self);
struct Blob_000db2f8 { int v; ~Blob_000db2f8() {} };
class B_000db2f8 { public: Blob_000db2f8 *data; ~B_000db2f8() { FUN_000db5d4(this); delete data; } };
class C_000db2f8 : public B_000db2f8 { public: int count; ~C_000db2f8(); };
C_000db2f8::~C_000db2f8() { count = 0; }

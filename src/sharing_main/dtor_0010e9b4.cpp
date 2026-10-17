/* HSTMATCH module=hstp_trans_main.prx start=0x0010e9b4 end=0x0010ea20 symbol=__dt__10C_0010e9b4Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0010ea20(void *self);
struct Blob_0010e9b4 { int v; ~Blob_0010e9b4() {} };
class B_0010e9b4 { public: Blob_0010e9b4 *data; ~B_0010e9b4() { FUN_0010ea20(this); delete data; } };
class C_0010e9b4 : public B_0010e9b4 { public: int count; ~C_0010e9b4(); };
C_0010e9b4::~C_0010e9b4() { count = 0; }

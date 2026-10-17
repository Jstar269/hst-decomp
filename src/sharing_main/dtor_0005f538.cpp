/* HSTMATCH module=hstp_trans_main.prx start=0x0005f538 end=0x0005f5a4 symbol=__dt__10C_0005f538Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0005f5a4(void *self);
struct Blob_0005f538 { int v; ~Blob_0005f538() {} };
class B_0005f538 { public: Blob_0005f538 *data; ~B_0005f538() { FUN_0005f5a4(this); delete data; } };
class C_0005f538 : public B_0005f538 { public: int count; ~C_0005f538(); };
C_0005f538::~C_0005f538() { count = 0; }

/* HSTMATCH module=hstp_trans_main.prx start=0x0005ada4 end=0x0005ae10 symbol=__dt__10C_0005ada4Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0005ae10(void *self);
struct Blob_0005ada4 { int v; ~Blob_0005ada4() {} };
class B_0005ada4 { public: Blob_0005ada4 *data; ~B_0005ada4() { FUN_0005ae10(this); delete data; } };
class C_0005ada4 : public B_0005ada4 { public: int count; ~C_0005ada4(); };
C_0005ada4::~C_0005ada4() { count = 0; }

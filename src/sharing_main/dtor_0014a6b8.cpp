/* HSTMATCH module=hstp_trans_main.prx start=0x0014a6b8 end=0x0014a724 symbol=__dt__10C_0014a6b8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014a844(void *self);
struct Blob_0014a6b8 { int v; ~Blob_0014a6b8() {} };
class B_0014a6b8 { public: Blob_0014a6b8 *data; ~B_0014a6b8() { FUN_0014a844(this); delete data; } };
class C_0014a6b8 : public B_0014a6b8 { public: int count; ~C_0014a6b8(); };
C_0014a6b8::~C_0014a6b8() { count = 0; }

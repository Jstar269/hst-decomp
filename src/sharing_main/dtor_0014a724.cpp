/* HSTMATCH module=hstp_trans_main.prx start=0x0014a724 end=0x0014a790 symbol=__dt__10C_0014a724Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014a820(void *self);
struct Blob_0014a724 { int v; ~Blob_0014a724() {} };
class B_0014a724 { public: Blob_0014a724 *data; ~B_0014a724() { FUN_0014a820(this); delete data; } };
class C_0014a724 : public B_0014a724 { public: int count; ~C_0014a724(); };
C_0014a724::~C_0014a724() { count = 0; }

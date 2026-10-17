/* HSTMATCH module=hstp_trans_main.prx start=0x0014a790 end=0x0014a7fc symbol=__dt__10C_0014a790Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0014a7fc(void *self);
struct Blob_0014a790 { int v; ~Blob_0014a790() {} };
class B_0014a790 { public: Blob_0014a790 *data; ~B_0014a790() { FUN_0014a7fc(this); delete data; } };
class C_0014a790 : public B_0014a790 { public: int count; ~C_0014a790(); };
C_0014a790::~C_0014a790() { count = 0; }

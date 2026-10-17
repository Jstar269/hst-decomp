/* HSTMATCH module=hstp_trans_main.prx start=0x00172800 end=0x0017286c symbol=__dt__10C_00172800Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_001728fc(void *self);
struct Blob_00172800 { int v; ~Blob_00172800() {} };
class B_00172800 { public: Blob_00172800 *data; ~B_00172800() { FUN_001728fc(this); delete data; } };
class C_00172800 : public B_00172800 { public: int count; ~C_00172800(); };
C_00172800::~C_00172800() { count = 0; }

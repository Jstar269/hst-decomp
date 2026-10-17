/* HSTMATCH module=hstp_trans_main.prx start=0x0010e948 end=0x0010e9b4 symbol=__dt__10C_0010e948Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0010ea44(void *self);
struct Blob_0010e948 { int v; ~Blob_0010e948() {} };
class B_0010e948 { public: Blob_0010e948 *data; ~B_0010e948() { FUN_0010ea44(this); delete data; } };
class C_0010e948 : public B_0010e948 { public: int count; ~C_0010e948(); };
C_0010e948::~C_0010e948() { count = 0; }

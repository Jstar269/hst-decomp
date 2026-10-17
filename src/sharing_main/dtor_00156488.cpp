/* HSTMATCH module=hstp_trans_main.prx start=0x00156488 end=0x001564f4 symbol=__dt__10C_00156488Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00156584(void *self);
struct Blob_00156488 { int v; ~Blob_00156488() {} };
class B_00156488 { public: Blob_00156488 *data; ~B_00156488() { FUN_00156584(this); delete data; } };
class C_00156488 : public B_00156488 { public: int count; ~C_00156488(); };
C_00156488::~C_00156488() { count = 0; }

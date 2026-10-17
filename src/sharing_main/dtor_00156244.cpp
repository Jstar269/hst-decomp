/* HSTMATCH module=hstp_trans_main.prx start=0x00156244 end=0x001562b0 symbol=__dt__10C_00156244Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00156614(void *self);
struct Blob_00156244 { int v; ~Blob_00156244() {} };
class B_00156244 { public: Blob_00156244 *data; ~B_00156244() { FUN_00156614(this); delete data; } };
class C_00156244 : public B_00156244 { public: int count; ~C_00156244(); };
C_00156244::~C_00156244() { count = 0; }

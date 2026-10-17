/* HSTMATCH module=hstp_trans_main.prx start=0x001564f4 end=0x00156560 symbol=__dt__10C_001564f4Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00156560(void *self);
struct Blob_001564f4 { int v; ~Blob_001564f4() {} };
class B_001564f4 { public: Blob_001564f4 *data; ~B_001564f4() { FUN_00156560(this); delete data; } };
class C_001564f4 : public B_001564f4 { public: int count; ~C_001564f4(); };
C_001564f4::~C_001564f4() { count = 0; }

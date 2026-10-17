/* HSTMATCH module=hstp_trans_main.prx start=0x001561d8 end=0x00156244 symbol=__dt__10C_001561d8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00156638(void *self);
struct Blob_001561d8 { int v; ~Blob_001561d8() {} };
class B_001561d8 { public: Blob_001561d8 *data; ~B_001561d8() { FUN_00156638(this); delete data; } };
class C_001561d8 : public B_001561d8 { public: int count; ~C_001561d8(); };
C_001561d8::~C_001561d8() { count = 0; }

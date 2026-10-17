/* HSTMATCH module=hstp_trans_main.prx start=0x002487d0 end=0x0024883c symbol=__dt__10C_002487d0Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00248a78(void *self);
struct Blob_002487d0 { int v; ~Blob_002487d0() {} };
class B_002487d0 { public: Blob_002487d0 *data; ~B_002487d0() { FUN_00248a78(this); delete data; } };
class C_002487d0 : public B_002487d0 { public: int count; ~C_002487d0(); };
C_002487d0::~C_002487d0() { count = 0; }

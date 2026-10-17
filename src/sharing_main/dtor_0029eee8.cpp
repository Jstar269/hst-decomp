/* HSTMATCH module=hstp_trans_main.prx start=0x0029eee8 end=0x0029ef54 symbol=__dt__10C_0029eee8Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0029f074(void *self);
struct Blob_0029eee8 { int v; ~Blob_0029eee8() {} };
class B_0029eee8 { public: Blob_0029eee8 *data; ~B_0029eee8() { FUN_0029f074(this); delete data; } };
class C_0029eee8 : public B_0029eee8 { public: int count; ~C_0029eee8(); };
C_0029eee8::~C_0029eee8() { count = 0; }

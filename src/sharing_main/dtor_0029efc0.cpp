/* HSTMATCH module=hstp_trans_main.prx start=0x0029efc0 end=0x0029f02c symbol=__dt__10C_0029efc0Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0029f02c(void *self);
struct Blob_0029efc0 { int v; ~Blob_0029efc0() {} };
class B_0029efc0 { public: Blob_0029efc0 *data; ~B_0029efc0() { FUN_0029f02c(this); delete data; } };
class C_0029efc0 : public B_0029efc0 { public: int count; ~C_0029efc0(); };
C_0029efc0::~C_0029efc0() { count = 0; }

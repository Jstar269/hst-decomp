/* HSTMATCH module=hstp_trans_main.prx start=0x0028c954 end=0x0028c9c0 symbol=__dt__10C_0028c954Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0028c9c0(void *self);
struct Blob_0028c954 { int v; ~Blob_0028c954() {} };
class B_0028c954 { public: Blob_0028c954 *data; ~B_0028c954() { FUN_0028c9c0(this); delete data; } };
class C_0028c954 : public B_0028c954 { public: int count; ~C_0028c954(); };
C_0028c954::~C_0028c954() { count = 0; }

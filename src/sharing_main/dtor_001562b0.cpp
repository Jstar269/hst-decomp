/* HSTMATCH module=hstp_trans_main.prx start=0x001562b0 end=0x0015631c symbol=__dt__10C_001562b0Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_001565f0(void *self);
struct Blob_001562b0 { int v; ~Blob_001562b0() {} };
class B_001562b0 { public: Blob_001562b0 *data; ~B_001562b0() { FUN_001565f0(this); delete data; } };
class C_001562b0 : public B_001562b0 { public: int count; ~C_001562b0(); };
C_001562b0::~C_001562b0() { count = 0; }

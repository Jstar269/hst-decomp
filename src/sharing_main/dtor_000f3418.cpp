/* HSTMATCH module=hstp_trans_main.prx start=0x000f3418 end=0x000f3484 symbol=__dt__10C_000f3418Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000f3484(void *self);
struct Blob_000f3418 { int v; ~Blob_000f3418() {} };
class B_000f3418 { public: Blob_000f3418 *data; ~B_000f3418() { FUN_000f3484(this); delete data; } };
class C_000f3418 : public B_000f3418 { public: int count; ~C_000f3418(); };
C_000f3418::~C_000f3418() { count = 0; }

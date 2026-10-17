/* HSTMATCH module=hstp_trans_main.prx start=0x000ee480 end=0x000ee4ec symbol=__dt__10C_000ee480Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000ee68c(void *self);
struct Blob_000ee480 { int v; ~Blob_000ee480() {} };
class B_000ee480 { public: Blob_000ee480 *data; ~B_000ee480() { FUN_000ee68c(this); delete data; } };
class C_000ee480 : public B_000ee480 { public: int count; ~C_000ee480(); };
C_000ee480::~C_000ee480() { count = 0; }

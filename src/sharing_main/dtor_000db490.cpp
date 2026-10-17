/* HSTMATCH module=hstp_trans_main.prx start=0x000db490 end=0x000db4fc symbol=__dt__10C_000db490Fv */
/* Clone of src/eboot/dtor_0005a0ec.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_000db58c(void *self);
struct Blob_000db490 { int v; ~Blob_000db490() {} };
class B_000db490 { public: Blob_000db490 *data; ~B_000db490() { FUN_000db58c(this); delete data; } };
class C_000db490 : public B_000db490 { public: int count; ~C_000db490(); };
C_000db490::~C_000db490() { count = 0; }

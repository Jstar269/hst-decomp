/* HSTMATCH module=EBOOT.BIN start=0x000b7e34 end=0x000b7e7c symbol=__dt__10C_000b7e34Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class with an empty virtual destructor: store the class vtable, then the deleting tail.
   key() keeps the vtable out of this unit. Names provisional. */
class C_000b7e34 { public: virtual void key(); virtual ~C_000b7e34(); };
C_000b7e34::~C_000b7e34() {}

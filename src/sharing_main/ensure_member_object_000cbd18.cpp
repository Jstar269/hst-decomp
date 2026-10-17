/* HSTMATCH module=hstp_trans_main.prx start=0x000cbd18 end=0x000cbd60 symbol=FUN_000cbd18 lang=c++ */
/* Clone of src/eboot/ensure_member_object_000c8178.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub;
struct Owner {
    char pad[0x44];
    Sub *p44;
};

extern "C" Sub *FUN_000d2258(void *mem);
void *operator new(unsigned int size);

extern "C" int FUN_000cbd18(Owner *o)
{
    if (o->p44 == 0) {
        void *mem = operator new(0x4c);
        if (mem)
            mem = FUN_000d2258(mem);
        o->p44 = (Sub *)mem;
    }
    return 1;
}

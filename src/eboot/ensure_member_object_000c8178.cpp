/* HSTMATCH module=EBOOT.BIN start=0x000c8178 end=0x000c81c0 symbol=FUN_000c8178 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub;
struct Owner {
    char pad[0x44];
    Sub *p44;
};

extern "C" Sub *FUN_000ce65c(void *mem);
void *operator new(unsigned int size);

extern "C" int FUN_000c8178(Owner *o)
{
    if (o->p44 == 0) {
        void *mem = operator new(0x4c);
        if (mem)
            mem = FUN_000ce65c(mem);
        o->p44 = (Sub *)mem;
    }
    return 1;
}

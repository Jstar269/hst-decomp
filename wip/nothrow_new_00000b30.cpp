/* HSTMATCH module=EBOOT.BIN start=0x00000b30 end=0x00000bcc symbol=FUN_00000b30 lang=c++ */

typedef void (*new_handler_t)();
extern new_handler_t DAT_0030a034;

extern "C" void * FUN_000104b0(unsigned int size);

namespace std {
    class bad_alloc {
    public:
        bad_alloc();
        virtual ~bad_alloc();
    };
}

extern "C" void * FUN_00000b30(unsigned int size) throw()
{
    if (size == 0) {
        size = 1;
    }
    void *p;
    goto first;
    do {
        new_handler_t h = DAT_0030a034;
        if (h) {
            try {
                h();
            } catch (std::bad_alloc) {
                return 0;
            }
        } else {
            return 0;
        }
first:
        p = FUN_000104b0(size);
    } while (p == 0);
    return p;
}

// Differing words: 32 / 39 (shifted by 1 word due to delay slot hoisting).
// Ruled out:
// - Non-throw() exception specification (requires throw() to emit __unexpected trap at 0xba4).
// - catch(...) vs catch(std::bad_alloc) (catch by value of class with dtor generates __end__catch cleanup at 0xb74).
// - while(true) and for(;;) without goto: puts malloc call at top instead of bottom.
// Remaining difference:
// - Retail has `beqz v0, 0xb54; nop;` at the loop bottom with `lui v0, 0x31` un-hoisted at 0xb54.
// - MWCC build 219 hoists `lui v0, 0x31` into `beqzl v0, 0xb54` slot, shifting the body by 1 instruction.
// near miss from lane ag5 (unreviewed)

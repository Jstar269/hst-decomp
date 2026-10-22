/* HSTMATCH module=EBOOT.BIN start=0x000042cc end=0x0000430c symbol=FUN_000042cc lang=c++ */
/* NEAR MISS: the function is a C++ exception frame: it saves the stack pointer in s8
   (in the delay slot of the call), and the EH landing pad restores sp from s8, calls
   FUN_00015ec with the address of the frame slot at s8+24 and then loops forever. */
extern "C" void FUN_00002ae8(int *);
extern "C" void FUN_00015ec(void *);

extern "C" void FUN_000042cc(int *p)
{
  int local;
  try {
    FUN_00002ae8(p + 1);
  } catch (...) {
    FUN_00015ec(&local);
    for (;;) ;
  }
}
// Ruled out:
//  - `catch (...)` alone: MWCC emits `sw sp,44(s8)` after the call and passes a0 = 0
//    to the handler (retail passes s8+24 and has no `sw sp,44(s8)`).
//  - `catch (E &e)`: the handler loads the exception pointer with `lw a0,36(s8)`.
//  - `catch (E e)`: the handler copies the object and passes s8+20.
//  - a callee declared `throw()`: MWCC removes the whole try/catch and the EH frame.
//  - the exception frame also needs the EH table in .data, which hstmatch would have
//    to place with `data=`; the frame slot of the caught object (s8+24) is not
//    reproducible without knowing the caught type.
// near miss from lane om1 (unreviewed)

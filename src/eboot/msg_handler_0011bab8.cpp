/* HSTMATCH module=EBOOT.BIN start=0x0011bab8 end=0x0011bb50 symbol=FUN_0011bab8 lang=c++ */
/* Clone of src/eboot/msg_handler_0011b3d0.cpp (hstclone.py tag c42): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Message handler: for messages 8, 0xe/0x18 and 0x12 call 0x1f1fc(self, 0) and clear a byte flag; 0xe/0x18
   also clear the member at +0xcc. A switch whose compare chain tests the case labels in reverse source order
   while the bodies stay in source order. Names provisional. */
extern "C" {
extern unsigned char DAT_0033b488;
void FUN_0001f1fc(void *self, int n);
}
struct Obj_0011bab8 { char pad[0xcc]; int cc; };
extern "C" int FUN_0011bab8(Obj_0011bab8 *self, int msg)
{
    switch (msg) {
    case 8:
        FUN_0001f1fc(self, 0);
        DAT_0033b488 = 0;
        break;
    case 0xe:
    case 0x18:
        FUN_0001f1fc(self, 0);
        DAT_0033b488 = 0;
        self->cc = 0;
        break;
    case 0x12:
        FUN_0001f1fc(self, 0);
        DAT_0033b488 = 0;
        break;
    }
    return 0;
}

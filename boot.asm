[org 0x7c00]        ; BIOS loads the bootloader at this address

start:
    mov ah, 0x0e    ; BIOS teletype function
    mov al, 'A'      ; Character to print
    int 0x10         ; Call BIOS interrupt

    mov al, '2'
    int 0x10

    mov al, 'Z'
    int 0x10

    hlt              ; Halt the CPU

times 510-($-$$) db 0 ; Fill the rest of the boot sector with zeros
dw 0xaa55             ; Boot signature (magic number)

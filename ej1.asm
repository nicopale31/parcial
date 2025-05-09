extern strcmp
global invocar_habilidad

; Completar las definiciones o borrarlas (en este ejercicio NO serán revisadas por el ABI enforcer)
DIRENTRY_NAME_OFFSET EQU 0
DIRENTRY_PTR_OFFSET EQU 16
DIRENTRY_SIZE EQU 24

FANTASTRUCO_DIR_OFFSET EQU 0
FANTASTRUCO_ENTRIES_OFFSET EQU 8
FANTASTRUCO_ARCHETYPE_OFFSET EQU 16
FANTASTRUCO_FACEUP_OFFSET EQU 24
FANTASTRUCO_SIZE EQU 32

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio

section .text

; void invocar_habilidad(void* carta, char* habilidad);
invocar_habilidad:
	; Te recomendamos llenar una tablita acá con cada parámetro y su
	; ubicación según la convención de llamada. Prestá atención a qué
	; valores son de 64 bits y qué valores son de 32 bits o 8 bits.
	;
	; r/m64 = void*    card ; Vale asumir que card siempre es al menos un card_t*
	; r/m64 = char*    habilidad

	; puntero a carta generica rdi
	; puntero a nombbre habilidad en rsi

	push rbp
	mov rbp, rsp
	push r12
	push r13
	push r14
	push r15
	push rbx

	mov r12, rdi  ; puntero a carta generica
	mov r13, rsi  ; nombre


.loop:



	movz r15, BYTE [rdi + FANTASTRUCO_ENTRIES_OFFSET]

	cmp rbx, r15
	je .siguientecarta




.siguientecarta:

	mov r12, [r12+ FANTASTRUCO_ARCHETYPE_OFFSET]
	cmp r12, 0
	je final
	jmp loop



.final:
	pop rbx
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbp
	ret ;No te olvides el ret!

	.file	"4.cpp"
	.intel_syntax noprefix
	.text
	.section	.text$_ZN13PlainOldClass3setEi,"x"
	.linkonce discard
	.align 2
	.globl	PlainOldClass::set(int)
	.def	PlainOldClass::set(int);	.scl	2;	.type	32;	.endef
	.seh_proc	PlainOldClass::set(int)
PlainOldClass::set(int):
.LFB0:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	DWORD PTR 24[rbp], edx
	mov	rax, QWORD PTR 16[rbp]
	mov	edx, DWORD PTR 24[rbp]
	mov	DWORD PTR [rax], edx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClass3setEi,"x"
	.linkonce discard
	.align 2
	.globl	CoolClass::set(int)
	.def	CoolClass::set(int);	.scl	2;	.type	32;	.endef
	.seh_proc	CoolClass::set(int)
CoolClass::set(int):
.LFB2:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	DWORD PTR 24[rbp], edx
	mov	rax, QWORD PTR 16[rbp]
	mov	edx, DWORD PTR 24[rbp]
	mov	DWORD PTR 8[rax], edx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClass3getEv,"x"
	.linkonce discard
	.align 2
	.globl	CoolClass::get()
	.def	CoolClass::get();	.scl	2;	.type	32;	.endef
	.seh_proc	CoolClass::get()
CoolClass::get():
.LFB3:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	eax, DWORD PTR 8[rax]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN4BaseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	Base::Base()
	.def	Base::Base();	.scl	2;	.type	32;	.endef
	.seh_proc	Base::Base()
Base::Base():
.LFB7:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	lea	rdx, vtable for Base[rip+16]
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR [rax], rdx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClassC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	CoolClass::CoolClass()
	.def	CoolClass::CoolClass();	.scl	2;	.type	32;	.endef
	.seh_proc	CoolClass::CoolClass()
CoolClass::CoolClass():
.LFB10:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	rcx, rax
	call	Base::Base()
	lea	rdx, vtable for CoolClass[rip+16]  // u rdx je vtable
	mov	rax, QWORD PTR 16[rbp]          // trenutni objekt
	mov	QWORD PTR [rax], rdx            // postavlja vtable na prvo mjesto u objektu
	nop
	add	rsp, 32
	pop	rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 56
	.seh_stackalloc	56
	lea	rbp, 48[rsp]
	.seh_setframe	rbp, 48
	.seh_endprologue
	call	__main
	mov	ecx, 16
	call	operator new(unsigned long long)
	mov	rbx, rax
	mov	rcx, rbx
	call	CoolClass::CoolClass()
	mov	QWORD PTR -8[rbp], rbx
	lea	rax, -12[rbp]
	mov	edx, 42
	mov	rcx, rax
	call	PlainOldClass::set(int)
	mov	rax, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR [rax]
	mov	r8, QWORD PTR [rax]
	mov	rax, QWORD PTR -8[rbp]
	mov	edx, 42
	mov	rcx, rax
	call	r8
	mov	eax, 0
	add	rsp, 56
	pop	rbx
	pop	rbp
	ret
	.seh_endproc
	.globl	vtable for CoolClass
	.section	.rdata$_ZTV9CoolClass,"dr"
	.linkonce same_size
	.align 8
vtable for CoolClass:
	.quad	0
	.quad	typeinfo for CoolClass
	.quad	CoolClass::set(int)
	.quad	CoolClass::get()
	.globl	vtable for Base
	.section	.rdata$_ZTV4Base,"dr"
	.linkonce same_size
	.align 8
vtable for Base:
	.quad	0
	.quad	typeinfo for Base
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.globl	typeinfo for CoolClass
	.section	.rdata$_ZTI9CoolClass,"dr"
	.linkonce same_size
	.align 8
typeinfo for CoolClass:
	.quad	vtable for __cxxabiv1::__si_class_type_info+16
	.quad	typeinfo name for CoolClass
	.quad	typeinfo for Base
	.globl	typeinfo name for CoolClass
	.section	.rdata$_ZTS9CoolClass,"dr"
	.linkonce same_size
	.align 8
typeinfo name for CoolClass:
	.ascii "9CoolClass\0"
	.globl	typeinfo for Base
	.section	.rdata$_ZTI4Base,"dr"
	.linkonce same_size
	.align 8
typeinfo for Base:
	.quad	vtable for __cxxabiv1::__class_type_info+16
	.quad	typeinfo name for Base
	.globl	typeinfo name for Base
	.section	.rdata$_ZTS4Base,"dr"
	.linkonce same_size
typeinfo name for Base:
	.ascii "4Base\0"
	.weak	__cxa_pure_virtual
	.ident	"GCC: (Rev5, Built by MSYS2 project) 13.2.0"
	.def	operator new(unsigned long long);	.scl	2;	.type	32;	.endef
	.def	__cxa_pure_virtual;	.scl	2;	.type	32;	.endef

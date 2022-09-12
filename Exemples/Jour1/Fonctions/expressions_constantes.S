	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 0
	.file	"expressions_constantes.cpp"
	.def	__cxx_global_var_init;
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90                         # -- Begin function __cxx_global_var_init
__cxx_global_var_init:                  # @__cxx_global_var_init
.seh_proc __cxx_global_var_init
# %bb.0:
	subq	$40, %rsp
	.seh_stackalloc 40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	callq	_ZNSt8ios_base4InitC1Ev
	leaq	__dtor__ZStL8__ioinit(%rip), %rcx
	callq	atexit
	nop
	addq	$40, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	__dtor__ZStL8__ioinit;
	.scl	3;
	.type	32;
	.endef
	.p2align	4, 0x90                         # -- Begin function __dtor__ZStL8__ioinit
__dtor__ZStL8__ioinit:                  # @__dtor__ZStL8__ioinit
.seh_proc __dtor__ZStL8__ioinit
# %bb.0:
	subq	$40, %rsp
	.seh_stackalloc 40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	callq	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$40, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	main;
	.scl	2;
	.type	32;
	.endef
	.section	.rdata,"dr"
	.p2align	3                               # -- Begin function main
.LCPI2_0:
	.quad	0x4008000000000000              # double 3
.LCPI2_1:
	.quad	0x4090000000000000              # double 1024
.LCPI2_2:
	.quad	0xc010000000000000              # double -4
.LCPI2_3:
	.quad	0x4014000000000000              # double 5
.LCPI2_4:
	.quad	0x402921fb54442d18              # double 12.566370614359172
	.text
	.globl	main
	.p2align	4, 0x90
main:                                   # @main
.seh_proc main
# %bb.0:
	pushq	%rbp
	.seh_pushreg %rbp
	subq	$304, %rsp                      # imm = 0x130
	.seh_stackalloc 304
	leaq	128(%rsp), %rbp
	.seh_setframe %rbp, 128
	.seh_endprologue
	callq	__main
	movl	$0, 172(%rbp)
	movl	$10, 168(%rbp)
	movl	$20, 164(%rbp)
	movl	$30, 160(%rbp)
	movq	.L__const.main.circle(%rip), %rax
	movq	%rax, -8(%rbp)
	movsd	.LCPI2_4(%rip), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -16(%rbp)
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.L.str(%rip), %rdx
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movsd	.LCPI2_4(%rip), %xmm1           # xmm1 = mem[0],zero
	callq	_ZNSolsEd
	movq	%rax, %rcx
	leaq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	callq	_ZNSolsEPFRSoS_E
	movq	.L__const.main.u(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	.L__const.main.u+8(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	.L__const.main.u+16(%rip), %rax
	movq	%rax, -24(%rbp)
	movsd	.LCPI2_3(%rip), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -48(%rbp)
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.L.str.1(%rip), %rdx
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movsd	.LCPI2_3(%rip), %xmm1           # xmm1 = mem[0],zero
	callq	_ZNSolsEd
	movq	%rax, %rcx
	leaq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	callq	_ZNSolsEPFRSoS_E
	leaq	-72(%rbp), %rcx
	xorps	%xmm1, %xmm1
	movsd	.LCPI2_0(%rip), %xmm2           # xmm2 = mem[0],zero
	movsd	.LCPI2_2(%rip), %xmm3           # xmm3 = mem[0],zero
	callq	_ZN6VectorC2Eddd
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.L.str.2(%rip), %rdx
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, -96(%rbp)                 # 8-byte Spill
	leaq	-72(%rbp), %rcx
	callq	_ZNK6Vector6normL2Ev
	movq	-96(%rbp), %rcx                 # 8-byte Reload
	movaps	%xmm0, %xmm1
	callq	_ZNSolsEd
	movq	%rax, %rcx
	leaq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	callq	_ZNSolsEPFRSoS_E
	movsd	.LCPI2_1(%rip), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -80(%rbp)
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.L.str.3(%rip), %rdx
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movsd	-80(%rbp), %xmm1                # xmm1 = mem[0],zero
	callq	_ZNSolsEd
	movq	%rax, %rcx
	leaq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	callq	_ZNSolsEPFRSoS_E
	movsd	.LCPI2_0(%rip), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, -88(%rbp)
	xorl	%eax, %eax
	addq	$304, %rsp                      # imm = 0x130
	popq	%rbp
	retq
	.seh_endproc
                                        # -- End function
	.def	_ZN6VectorC2Eddd;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZN6VectorC2Eddd,"xr",discard,_ZN6VectorC2Eddd
	.globl	_ZN6VectorC2Eddd                # -- Begin function _ZN6VectorC2Eddd
	.p2align	4, 0x90
_ZN6VectorC2Eddd:                       # @_ZN6VectorC2Eddd
.seh_proc _ZN6VectorC2Eddd
# %bb.0:
	subq	$32, %rsp
	.seh_stackalloc 32
	.seh_endprologue
	movq	%rcx, 24(%rsp)
	movsd	%xmm1, 16(%rsp)
	movsd	%xmm2, 8(%rsp)
	movsd	%xmm3, (%rsp)
	movq	24(%rsp), %rax
	movsd	16(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	%xmm0, (%rax)
	movsd	8(%rsp), %xmm0                  # xmm0 = mem[0],zero
	movsd	%xmm0, 8(%rax)
	movsd	(%rsp), %xmm0                   # xmm0 = mem[0],zero
	movsd	%xmm0, 16(%rax)
	addq	$32, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	_ZNK6Vector6normL2Ev;
	.scl	2;
	.type	32;
	.endef
	.section	.text$_ZNK6Vector6normL2Ev,"xr",discard,_ZNK6Vector6normL2Ev
	.globl	_ZNK6Vector6normL2Ev            # -- Begin function _ZNK6Vector6normL2Ev
	.p2align	4, 0x90
_ZNK6Vector6normL2Ev:                   # @_ZNK6Vector6normL2Ev
.seh_proc _ZNK6Vector6normL2Ev
# %bb.0:
	subq	$40, %rsp
	.seh_stackalloc 40
	.seh_endprologue
	movq	%rcx, 32(%rsp)
	movq	32(%rsp), %rax
	movsd	(%rax), %xmm1                   # xmm1 = mem[0],zero
	movsd	(%rax), %xmm2                   # xmm2 = mem[0],zero
	movsd	8(%rax), %xmm0                  # xmm0 = mem[0],zero
	mulsd	8(%rax), %xmm0
	mulsd	%xmm2, %xmm1
	addsd	%xmm0, %xmm1
	movsd	16(%rax), %xmm0                 # xmm0 = mem[0],zero
	movsd	16(%rax), %xmm2                 # xmm2 = mem[0],zero
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	callq	_Z10squareRootd
	nop
	addq	$40, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	_Z10squareRootd;
	.scl	2;
	.type	32;
	.endef
	.section	.rdata,"dr"
	.p2align	3                               # -- Begin function _Z10squareRootd
.LCPI5_0:
	.quad	0x3ff0000000000000              # double 1
.LCPI5_1:
	.quad	0x4008000000000000              # double 3
.LCPI5_2:
	.quad	0x3c9cd2b297d889bc              # double 9.9999999999999997E-17
.LCPI5_3:
	.quad	0x4010000000000000              # double 4
.LCPI5_4:
	.quad	0x4000000000000000              # double 2
	.section	.text$_Z10squareRootd,"xr",discard,_Z10squareRootd
	.globl	_Z10squareRootd
	.p2align	4, 0x90
_Z10squareRootd:                        # @_Z10squareRootd
.seh_proc _Z10squareRootd
# %bb.0:
	subq	$72, %rsp
	.seh_stackalloc 72
	.seh_endprologue
	movsd	%xmm0, 64(%rsp)
	movsd	.LCPI5_0(%rip), %xmm0           # xmm0 = mem[0],zero
	movsd	%xmm0, 56(%rsp)
	movsd	64(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	%xmm0, 48(%rsp)
.LBB5_1:                                # =>This Inner Loop Header: Depth=1
	movsd	48(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	.LCPI5_1(%rip), %xmm1           # xmm1 = mem[0],zero
	ucomisd	%xmm1, %xmm0
	jb	.LBB5_3
# %bb.2:                                #   in Loop: Header=BB5_1 Depth=1
	movsd	.LCPI5_4(%rip), %xmm0           # xmm0 = mem[0],zero
	mulsd	56(%rsp), %xmm0
	movsd	%xmm0, 56(%rsp)
	movsd	48(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	.LCPI5_3(%rip), %xmm1           # xmm1 = mem[0],zero
	divsd	%xmm1, %xmm0
	movsd	%xmm0, 48(%rsp)
	jmp	.LBB5_1
.LBB5_3:
	movsd	48(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	%xmm0, 40(%rsp)
	movsd	48(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	.LCPI5_0(%rip), %xmm1           # xmm1 = mem[0],zero
	subsd	%xmm1, %xmm0
	movsd	%xmm0, 32(%rsp)
.LBB5_4:                                # =>This Inner Loop Header: Depth=1
	movsd	32(%rsp), %xmm0                 # xmm0 = mem[0],zero
	callq	_ZSt3absd
	movsd	.LCPI5_2(%rip), %xmm1           # xmm1 = mem[0],zero
	ucomisd	%xmm1, %xmm0
	jbe	.LBB5_6
# %bb.5:                                #   in Loop: Header=BB5_4 Depth=1
	movsd	40(%rsp), %xmm0                 # xmm0 = mem[0],zero
	movsd	40(%rsp), %xmm1                 # xmm1 = mem[0],zero
	mulsd	32(%rsp), %xmm1
	movsd	.LCPI5_4(%rip), %xmm2           # xmm2 = mem[0],zero
	divsd	%xmm2, %xmm1
	subsd	%xmm1, %xmm0
	movsd	%xmm0, 40(%rsp)
	movsd	32(%rsp), %xmm0                 # xmm0 = mem[0],zero
	mulsd	32(%rsp), %xmm0
	movsd	32(%rsp), %xmm1                 # xmm1 = mem[0],zero
	movsd	.LCPI5_1(%rip), %xmm2           # xmm2 = mem[0],zero
	subsd	%xmm2, %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LCPI5_3(%rip), %xmm1           # xmm1 = mem[0],zero
	divsd	%xmm1, %xmm0
	movsd	%xmm0, 32(%rsp)
	jmp	.LBB5_4
.LBB5_6:
	movsd	56(%rsp), %xmm0                 # xmm0 = mem[0],zero
	mulsd	40(%rsp), %xmm0
	addq	$72, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.def	_ZSt3absd;
	.scl	2;
	.type	32;
	.endef
	.section	.rdata,"dr"
	.p2align	4                               # -- Begin function _ZSt3absd
.LCPI6_0:
	.quad	0x7fffffffffffffff              # double NaN
	.quad	0x7fffffffffffffff              # double NaN
	.section	.text$_ZSt3absd,"xr",discard,_ZSt3absd
	.globl	_ZSt3absd
	.p2align	4, 0x90
_ZSt3absd:                              # @_ZSt3absd
.seh_proc _ZSt3absd
# %bb.0:
	pushq	%rax
	.seh_stackalloc 8
	.seh_endprologue
	movsd	%xmm0, (%rsp)
	movsd	(%rsp), %xmm0                   # xmm0 = mem[0],zero
	movaps	.LCPI6_0(%rip), %xmm1           # xmm1 = [NaN,NaN]
	pand	%xmm1, %xmm0
	popq	%rax
	retq
	.seh_endproc
                                        # -- End function
	.def	_GLOBAL__sub_I_expressions_constantes.cpp;
	.scl	3;
	.type	32;
	.endef
	.text
	.p2align	4, 0x90                         # -- Begin function _GLOBAL__sub_I_expressions_constantes.cpp
_GLOBAL__sub_I_expressions_constantes.cpp: # @_GLOBAL__sub_I_expressions_constantes.cpp
.seh_proc _GLOBAL__sub_I_expressions_constantes.cpp
# %bb.0:
	subq	$40, %rsp
	.seh_stackalloc 40
	.seh_endprologue
	callq	__cxx_global_var_init
	nop
	addq	$40, %rsp
	retq
	.seh_endproc
                                        # -- End function
	.lcomm	_ZStL8__ioinit,1                # @_ZStL8__ioinit
	.section	.rdata,"dr"
	.p2align	3                               # @__const.main.circle
.L__const.main.circle:
	.quad	0x4000000000000000              # double 2

.L.str:                                 # @.str
	.asciz	"Aire du cercle : "

	.p2align	3                               # @__const.main.u
.L__const.main.u:
	.quad	0x0000000000000000              # double 0
	.quad	0x4008000000000000              # double 3
	.quad	0xc010000000000000              # double -4

.L.str.1:                               # @.str.1
	.asciz	"Norme de u : "

.L.str.2:                               # @.str.2
	.asciz	"Norme de v : "

.L.str.3:                               # @.str.3
	.asciz	"2.^10 = "

	.section	.ctors,"dw"
	.p2align	3
	.quad	_GLOBAL__sub_I_expressions_constantes.cpp
	.section	.drectve,"yn"
	.section	.rdata$.refptr._ZSt4cout,"dr",discard,.refptr._ZSt4cout
	.p2align	3
	.globl	.refptr._ZSt4cout
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.addrsig
	.addrsig_sym __cxx_global_var_init
	.addrsig_sym __dtor__ZStL8__ioinit
	.addrsig_sym atexit
	.addrsig_sym _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	.addrsig_sym _ZNSolsEd
	.addrsig_sym _ZNSolsEPFRSoS_E
	.addrsig_sym _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.addrsig_sym _ZNK6Vector6normL2Ev
	.addrsig_sym _Z10squareRootd
	.addrsig_sym _ZSt3absd
	.addrsig_sym _GLOBAL__sub_I_expressions_constantes.cpp
	.addrsig_sym _ZStL8__ioinit
	.addrsig_sym _ZSt4cout

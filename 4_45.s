	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_bobble_i
	.align	4, 0x90
_bobble_i:                              ## @bobble_i
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	12(%ebp), %eax
	cmpl	$2, %eax
	jl	LBB0_7
## BB#1:
	movl	8(%ebp), %ecx
	.align	4, 0x90
LBB0_3:                                 ## %.lr.ph
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_4 Depth 2
	decl	%eax
	xorl	%edx, %edx
	.align	4, 0x90
LBB0_4:                                 ##   Parent Loop BB0_3 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	4(%ecx,%edx,4), %esi
	movl	(%ecx,%edx,4), %edi
	cmpl	%edi, %esi
	jge	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=2
	movl	%edi, 4(%ecx,%edx,4)
	movl	%esi, (%ecx,%edx,4)
LBB0_6:                                 ##   in Loop: Header=BB0_4 Depth=2
	incl	%edx
	cmpl	%eax, %edx
	jl	LBB0_4
## BB#2:                                ## %.loopexit
                                        ##   in Loop: Header=BB0_3 Depth=1
	cmpl	$2, %eax
	jge	LBB0_3
LBB0_7:                                 ## %._crit_edge
	popl	%esi
	popl	%edi
	popl	%ebp
	retl


.subsections_via_symbols

	.data
	f: .dword 0x0000000012345678
	g: .dword 0x8000000000000001
	.text
	LDR x9, f
	LSR X10, X9, 27
	LDR x9, g
	LSR X10, X9, 63
end:
infloop: B infloop

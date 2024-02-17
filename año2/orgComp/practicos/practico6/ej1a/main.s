	.data
	f: .dword 1
	g: .dword 2
	h: .dword 3
	i: .dword 4
	j: .dword 5
	.text
	LDR x0, f
	LDR x1, g
	LDR x2, h
	LDR x3, i
	LDR x4, j
	ADD X0, X1, X2
	ADD X0, X0, X3
	ADD X0, X0, X4
end:
infloop: B infloop

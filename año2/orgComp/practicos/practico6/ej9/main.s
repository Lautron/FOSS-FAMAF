	.data
	f: .dword 1
	.text
	MOVZ X9, 0xCDEF, LSL 0
	MOVK X9, 0x89AB, LSL 16
	MOVK X9, 0x4567, LSL 32
	MOVK X9, 0x0123, LSL 48
	STUR X9, [XZR, #0]
	LDURB X0, [XZR, #0]
end:
infloop: B infloop

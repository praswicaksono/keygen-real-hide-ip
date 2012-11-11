Reversing Project
=================

	Target : Real Hide IP
	Difficulty : 4/10
	Protection : RSA-128
	Language : Masm 32 bit
	Library Used : Bignum & cryptohash

Short Tutorial
==============

	Public Key (N) : 1CC74813BE6F01D6DF007E5E5944CF23
	Private Key (D) : 175DDFAB4688289098139063930917DB

Get machine code start from 3rd char until 19th char, i will save
into variable M. Then do PowMod

	M ^ N mod D

then convert the result into base 16 and youre done ;)


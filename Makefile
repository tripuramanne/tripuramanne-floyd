 all : lcs floyd

 lcs: manne_tripura_pa3_lcs.c
	gcc -o lcs manne_tripura_pa3_lcs.c

floyd: manne_tripura_pa3_floyd.c
	gcc -o floyd manne_tripura_pa3_floyd.c

 clean:
	rm -f  lcs floyd 
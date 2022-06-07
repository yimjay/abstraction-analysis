test:
#	sh PatternAnal.sh -DCONTIG= -DHAVE_EXECUTECOMMANDLINE -DUSE_ARPACK -DUSE_ISO_C_BINDINGS -Delmersolver_EXPORTS -I/home/qyi/elmer-build -I/home/qyi/elmer-build/fem/src -I/home/qyi/elmerfem-release-8.2/fhutiter/src -I/home/qyi/elmer-build/fem/src/binio -I/home/qyi/elmer-build/fhutiter/src -O2 -g -DNDEBUG -module /home/qyi/elmer-build/fmodules -fPIC -c /home/qyi/elmerfem-release-8.2/fem/src/CRSMatrix.F90 
	sh FindLoops.sh /home/qyi/Benchmarks/Lulesh /home/qyi/SLICE/trunk/POET_ROSE/rose_pcg  rose "" -DUSE_MPI=0 -debuglocalinfocollect
	make annot
#	sh FindLoops.sh /home/qyi/elmerfem-release-8.2/fem/src/CRSMatrix.F90  ../src/pcg
#	sh FindLoops.sh /Users/qyi/Benchmarks/Lulesh ../src/pcg
#	sh FindLoops.sh /Users/qyi/Benchmarks/parsec-3.0/pkgs/apps ../src/pcg
#	sh FindLoops.sh /Users/qyi/Benchmarks/parsec-3.0/pkgs/kernels ../src/pcg
#	sh FindLoops.sh /Users/qyi/Benchmarks/parsec-3.0/pkgs/netapps ../src/pcg

annot:
	../src/pcg -dp -pin=annotations.txt -pout=annot-new.txt merge_annot.pt
	mv annot-new.txt annotations.txt
	diff annotations.txt funcs.annot


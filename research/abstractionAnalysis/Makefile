input=SinglyLinkedList.h_orig
output=
debug=

now:
	~/POET/trunk/src/pcg $(debug) -L../../trunk/lib -pinputFile=testfiles/$(input) -poutputFile=$(output) -pspecFile=semantics/abstractions.spec abstractionAnalysis.pt

stack:
	pcg $(debug) -L../../trunk/lib -pinputFile=testfiles/$(input) -poutputFile=$(output) -pspecFile=semantics/abstractions.spec abstractionAnalysis.pt

queue:
	pcg $(debug) -L../../trunk/lib -pinputFile=testfiles/$(input) -poutputFile=$(output) -pspecFile=semantics/abstractions_queue.spec abstractionAnalysis.pt
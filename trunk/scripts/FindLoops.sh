#set -e
if [ "$#" -lt 2 ] || ! [ -e "$1" ] || ! [ -e "$2" ]; then 
  echo "Usage: $0 DIRECTORY <pcg location> ...... " >& 2
  exit 1
fi
path=$1; 
find $path -name "*.[fhcC]" > files.txt
find $path -name "*.cpp" >> files.txt
find $path -name "*.cc" >> files.txt
find $path -name "*.F90" >> files.txt
if [ "$#" -gt 2 ]; then ext=$3; else ext=""; fi
if [ "$#" -gt 3 ]; then incl=$4; else incl="."; fi
if [ "$#" -gt 4 ]; then extra=$5; else extra=""; fi
if [ "$#" -gt 5 ]; then extra="$extra $6"; else extra=$extra; fi;
echo "ext=" $ext;
echo "extra=" $extra;
echo "digraph {" > CallGraph.dot; 
echo "" > FoundLoops.txt; 
echo "" > annotations.txt; 
echo "" > CallGraph_now.txt;
cat files.txt | awk -v pcg=$2 -v ext=$ext -v incl=$incl -v extra="$extra" '{print "echo \"" $0 "\"; \
                      echo \"\" > FoundLoops_now.txt; \
                      echo \"" $0 "\" >> FoundLoops.txt; \
                      " pcg " -pext=\"" ext "\" -L" incl " -pcall=\"CallGraph_now.txt\" -pout=\"FoundLoops_now.txt\" -pannot=\"annot_now.txt\" -pin=\"" $0 "\" FindLoops.pt " extra "; \
                      cat FoundLoops_now.txt >> FoundLoops.txt; \
                      cat annot_now.txt >> annotations.txt; \
                      cat CallGraph_now.txt >> CallGraph.dot"; }' | sh -v -e; 
echo "}" >> CallGraph.dot

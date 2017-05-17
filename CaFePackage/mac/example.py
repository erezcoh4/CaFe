import sys
from ROOT import gSystem
gSystem.Load("libCaFe_CaFePackage")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing CaFePackage..."

sys.exit(0)


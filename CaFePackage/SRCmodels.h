/**
 * \file SRCmodels.h
 *
 * \ingroup CaFePackage
 * 
 * \brief Class def header for a class SRCmodels
 *
 * @author erezcohen
 */

/** \addtogroup CaFePackage

    @{*/
#ifndef SRCMODELS_H
#define SRCMODELS_H

#include <iostream>
#include "myIncludes.h"
#include "TCalculations.h"
#include "nucleon.h"
#include "nucleus.h"

/**
   \class SRCmodels
   User defined class SRCmodels ... these comments are used to generate
   doxygen documentation!
 */
class SRCmodels{

public:

    SRCmodels();
  ~SRCmodels(){}

    TF1 *   CFGMomentumDist ();
    Float_t      MFnucleons ();
    Float_t              Tp ();
    Float_t          MeanTp ();
    Float_t     p_SRCk4Tail ();
    Float_t     p_MeanField ();
    
    
    
    void SetKFermi (Float_t  fkF = 250){kF = fkF;};

    Float_t  kF;
    
    TF1 * SRCk4Tail;
    
};

#endif
/** @} */ // end of doxygen group 


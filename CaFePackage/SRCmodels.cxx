#ifndef SRCMODELS_CXX
#define SRCMODELS_CXX

#include "SRCmodels.h"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// May-17,2017
SRCmodels::SRCmodels(){
    
    SRCk4Tail = CFGMomentumDist();
    cout << "set SRCk4Tail" << endl;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// May-17,2017
Float_t SRCmodels::p_SRCk4Tail(){
    return SRCk4Tail -> GetRandom();
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// May-17,2017
TF1* SRCmodels::CFGMomentumDist(){
    
    // Correlated Fermi Gas (CFG) distribution
    TH1F* hCFG;
    
    Double_t        c0 = 4.16 ; // +/- 0.95..
    Double_t       E_F = kF * kF / (2. * 940.); // non relativistic
    Double_t      E_F0 = 12.5 / ( ( pow(2.,2./3) - 1 ) * (3./5.));
    Double_t       kF0 = sqrt( 2. * 940. * E_F0 );
    Double_t  rho2rho0 = pow( ( pow(2.,2./3) - 1 ) * (3./5.) * (E_F/12.5)   , 3./2.);
    Double_t    lambda = 2.75 ;// +/- 0.25 high-momentum cutoff
    Double_t       pi2 = pow(TMath::Pi(),2);
    Double_t        A0 = (3 * pi2 / pow(kF0,3)) * (1./rho2rho0) * (1 - (1 - (1./lambda)*pow(rho2rho0,1./3.)) * (c0 / pi2 ));
    TF1 * SRCk4Tail = new TF1("tail",Form("%f*%f/(x**4)",c0,kF),kF,lambda*kF0);
    
    int Nbins = 100;
    float bin_content , k;
    
    // Correlated Fermi Gas momentum dist.
    hCFG = new TH1F("hCFG" , "Correlated Fermi Gas momentum dist." , Nbins , 0 , lambda*kF0 );
    for (int bin = 0; bin < Nbins ; bin++){
        k = hCFG -> GetXaxis() -> GetBinCenter( bin );
        bin_content = ( k < kF ) ? A0 : SRCk4Tail -> Eval(k);
        hCFG -> SetBinContent( bin , bin_content );
    }
    
    return SRCk4Tail;
}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// May-17,2017
Float_t SRCmodels::p_MeanField(){
    return gRandom -> Uniform( 0 , kF );
}



#endif

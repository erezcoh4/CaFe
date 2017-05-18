
from CaFe_tools import *
'''
    usage:
    -------
    python mac/run_src_models.py -nruns=3
'''


modelname = 'MeanField'
models = SRCmodels()
models.SetKFermi(250)

N = 20
Z = 20
A = N+Z
Nnuclei = flags.NumberOfRuns
target_name = 'Ca40'
filename = "/Users/erezcohen/Desktop/CaFe/Estimations/SRCmodels/"+target_name+'_'+modelname+".csv"

Nnucleons = Nnuclei*(N+Z)

for nucleus in range(Nnuclei): #{
    
    if nucleus%(Nnuclei/10)==0: print '%.0f'%(100*float(nucleus)/Nnuclei)+'%'

    for nucleon in range(A):#{
    
        # decide neutron or proton
        if nucleon < N:#{
            nucleon_name = 'proton'
            m = 938.3
        #}
        else:#{
            nucleon_name = 'neutron'
            m = 939.6
        #}


        # generate momentum from our model
        if modelname == 'MeanField':#{
            p = models.p_MeanField()
            E = np.sqrt( m*m + p*p )
            T = E - m
        #}
    
        target = pd.DataFrame({'nucleus':nucleus
                              ,'nucleon':nucleon
                              ,'name':nucleon_name
                              ,'p':p
                              ,'E':E
                              ,'T':T
                              ,'m':m
                              }
                              ,index=[0])
    
        stream_dataframe_to_file( target, filename  )
    #}
#}



print 'done.'
# This program generate a list of all DNAs
out = open( 'G:\\TCC\\data\\V3\\data\\out' ,'w')

for fileName in range(2,641): #641
    arq = open( 'G:\\TCC\\data\\V3\\data\\DNAs\\Zephyr1\\' + str(fileName) ,'r')
    out.write( str(fileName) + ": " + arq.read() + "\n" )
    arq.close()

arq.close()
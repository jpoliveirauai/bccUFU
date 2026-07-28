# This program generate a list of all DNAs
osName = 'Zephyr3'
out = open( 'DNAs\\' + osName + '.txt','w')

for fileName in range(2,641): #641
    arq = open( 'DNAs\\' + osName + '\\' + str(fileName) ,'r')
    out.write( str(fileName) + ": " + arq.read() + "\n" )
    arq.close()

arq.close()
from pathlib import Path
import pandas as pd
import info as inf
import os

rootFolder="../"
# Criação da matriz de distâncias
def generateTree( containerFolder , disMatrixPath, soName):
    command = "ncd -d /home/" + soName +" /home/" + soName
    toDistanceMatrixCommand = " > " + disMatrixPath
    dockerCommand="docker run -it -v " + containerFolder + ":/home complearn " + command + toDistanceMatrixCommand
    print(dockerCommand)
    os.system(dockerCommand)

    mediaMatriz(disMatrixPath, soName)
    print("../trees/distanceMatrixes/" + soName + ".ndm")
    print("../trees/" + soName + ".tree")
    treeGen = rootFolder + inf.programsFolder + "BIONJ "
    os.system(treeGen)

def mediaMatriz(disMatrixPath, soName):
    matrix = []
    line = []
    ids = []
    finalFile= ""
    arq = open( disMatrixPath,'r')
    for linha in arq.readlines():
        linha = linha.split(' ')
        linha.pop()
        ids.append( linha.pop(0) )
        for value in linha:
            line.append( float(value) )
        matrix.append( line )
        line=[]
    arq.close()

    for i in range(0, len(matrix) ):
        finalFile = finalFile + str(ids[i]) + " "
        for j in range(0, len(matrix) ):
            matrix[i][j] = (matrix[i][j] + matrix[j][i])/2
            matrix[j][i] = matrix[i][j]
            finalFile = finalFile + str( matrix[j][i] ) + " "
        finalFile = finalFile + "\n"
    finalFile = str( len( matrix) ) + "\n" + finalFile
    arq = open( rootFolder + inf.distanceMatrixFolder + soName + ".ndm",'w')
    arq.write(finalFile)
    arq.close

def mapData( csvPath , hashFile ):
    data = pd.read_csv( csvPath )
    hash={}
    existsHashFile = os.path.isfile(hashFile)
    if existsHashFile:
        hash = eval( open(hashFile, 'r').read() )
    for coluna in data.columns.tolist()[1:]:
        elementosUnicos = eval('data.' + coluna + '.unique()' )
        print("Coluna " + str(coluna) + ": " + str(elementosUnicos))
        for elem in elementosUnicos:
            if existsHashFile:
                value = hash[ str(elem) ]
            else:
                value = input('DNA de  ' + str(elem) + ' ('+ coluna +')' + ': ')
            hash[str(elem)] = value
    arq = open( hashFile ,'w')
    arq.write( str(hash) )
    arq.close()

    for coluna in data.columns.tolist()[1:]:
        i=0
        while(True):
            if(i>len(data)-1):
                break
            data.loc[i,coluna] = hash[str(data.loc[i,str(coluna)])]
            i = i+1
    return data

def generateDNA( data , soName):
    arquivos = []
    i=0
    nomeArq=2
    functionName = data.loc[i, 'Name']
    arquivos.append(functionName)
    os.system("mkdir " + rootFolder + inf.dnaFolders + soName + '/')
    while(True):
        if(i>len(data)-2):
            break
        previousFileName = data.loc[i, 'File']
        fileName = data.loc[i+1, 'File']
        functionName = ""
        for coluna in data.columns.tolist()[1:]:
            functionName = functionName + data.loc[i+1, coluna]
        if fileName == previousFileName:
            arquivos[len(arquivos) - 1] += functionName
        if fileName != previousFileName or i+1 > len(data)-2 :
            arquivos.append(functionName)
            arq = open( rootFolder + inf.dnaFolders + soName + '/' + str(nomeArq),'w')
            nomeArq = nomeArq + 1
            arq.write( str(arquivos[ len(arquivos) - 2 ]) )
            arq.close()
        i+=1
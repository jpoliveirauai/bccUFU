import TreeGenerator as tg
import info as inf

soName="Zephyr3"
# TODO: Usar caminhos de arquivo no argumento das funções
dataMapped = tg.mapData("../data/sorted/" + soName + ".csv", "../data/mapped/" + soName + ".hash")
tg.generateDNA( dataMapped , soName )
tg.generateTree("/home/jpveira/Documents/TCC/GitHub/data/DNAs", "../trees/distanceMatrixes/" + soName + ".dm", soName)

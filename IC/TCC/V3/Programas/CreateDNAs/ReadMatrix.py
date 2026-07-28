import pandas as pd

data = pd.read_csv("FreeRTOS.csv")

# data = data.sort_values(by=['File'])
# data = data.reset_index(drop=True)

arquivos = []
i=0
indexVetor = 0
functionName = data.loc[i, 'Name']
arquivos.append(functionName)
while(True):
    if(i>len(data)-2):
        break
    previousFileName = data.loc[i, 'File']
    previousFunctionName = data.loc[i, 'Name']
    fileName = data.loc[i+1, 'File']
    functionName = data.loc[i+1, 'Name']
    if fileName == previousFileName:
        # arquivos[len(arquivos) - 1] += functionName
        # arquivos[len(arquivos) - 1] += functionName
    # else:
    if fileName != previousFileName:
        arquivos.append(functionName)
    i+=1

print("\n".join(arquivos))
# print(arquivos)
# print(len(arquivos))
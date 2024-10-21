import pandas as pd
import matplotlib.pyplot as plt
import json
import numpy as np
import seaborn as sns

testCO2 = 'testCO2.txt'
testCxHy = 'testCxHy.txt'
file1 = 'country_side.txt'
file2 = 'kalunborg_harbor.txt'
file3 = 'kalundborg_refinery.txt'
file4 = 'kalunborg_refinery_aista.txt'
file5 = 'farevajle_beach.txt'
file6 = 'ordrup_shore.txt'
file7 = 'pig_farm.txt'
record_data = [file1, file2, file3, file4, file5, file6, file7]

dfs = { }

# test our hardware
#data = []
#with open(testCO2, 'r') as file:
#    for line in file:
#        timestamp, json_data = line.split(': ', 1)
#        parsed_data = json.loads(json_data)
#        parsed_data["timestamp"] = timestamp
#        data.append(parsed_data)
#
#with open(testCxHy, 'r') as file:
#    for line in file:
#        timestamp, json_data = line.split(': ', 1)
#        parsed_data = json.loads(json_data)
#        parsed_data["timestamp"] = timestamp
#        data.append(parsed_data)
#
#df = pd.DataFrame(data)
#df['timestamp'] = pd.to_datetime(df['timestamp'])
#columns_to_iterate = ['C3H8', 'CH4', 'CO', 'CO2', 'H2S', 'LPG', 'NH3', 'NO2', 'VOC']
#colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k', '#FF5733', '#33FF57']
#drap = df['DRAP']
#for i, cols in enumerate(columns_to_iterate):
#    # last_ = df[cols].head(500)
#    df[cols].plot(label=f'{cols}', legend=True, color=colors[i])
#    avg_col = df[cols].mean()
#    plt.axhline(y=avg_col, color=colors[i], linestyle='--', label=f'Average {cols}')
#
#plt.title(f'test CO2 and CxHy', fontdict={'fontsize': 16, 'fontweight': 'bold', 'fontfamily': 'serif'})
## plt.legend(loc='upper right')
#plt.xlabel('Time, sec')
#plt.ylabel(f'Conc, ppm')
#plt.grid(True)
#
#plt.show()
#--------------------------------------------------------------------------------
#show pollutant data

for item in record_data:
    data = []
    with open(item, 'r') as file:
        for line in file:
            timestamp, json_data = line.split(': ', 1)
            parsed_data = json.loads(json_data)
            parsed_data["timestamp"] = timestamp
            data.append(parsed_data)

    df = pd.DataFrame(data)
    df['timestamp'] = pd.to_datetime(df['timestamp'])
    dfs[item.split('.')[0]] = df

for filename, df in dfs.items():
    print(f"Data from {filename}:")
    print(df.head())
#
#
columns_to_iterate = ['C3H8', 'CH4', 'CO', 'CO2', 'H2S','LPG','NH3','NO2','VOC']
colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k', '#FF5733', '#33FF57']
drap = df['DRAP']

for cols in columns_to_iterate:

    for i, (filename, df) in  enumerate(dfs.items()):

        last_ = df[cols].head(500)
        last_.plot(label=f'{filename}', legend=True, color = colors[i])
        avg_col = df[cols].mean()
        plt.axhline(y=avg_col, color=colors[i], linestyle='--', label=f'Average {cols}')

    plt.title(f'{cols} in different locations', fontdict={'fontsize': 16, 'fontweight': 'bold', 'fontfamily': 'serif'})
    #plt.legend(loc='upper right')
    plt.xlabel('Time, sec')
    plt.ylabel(f'{cols} Conc, ppm')
    plt.grid(True)


    plt.show()
#---------------------------------------------------------------------------------------------------------------------
#show radiation data

#start = 0
#end = 60
#sum_data_set=[]
#
#drap_dict = {}
#
#for i, (filename, df) in  enumerate(dfs.items()):
#
#    first = df['DRAP'].head(900)
#
#    start = 0
#    end = 60
#    for j in range(15):
#        line_sum = (first.iloc[start:end])
#        sumVal = line_sum.sum()/264
#        sumVal = sumVal.round(4)
#        start +=60
#        end +=60
#        sum_data_set.append(sumVal)
#    avg_drap = sum(sum_data_set)/len(sum_data_set)
#    print(sum_data_set)
#    drap_dict[i] = sum_data_set
#    sum_data_set = []
#    plt.plot(drap_dict[i], label=f'{filename}', color=colors[i], linewidth=3, marker='o', markersize=2)
#    plt.bar(range(len(drap_dict[i])), drap_dict[i], label=f'{filename}', color=colors[i], width=0.75)
#    plt.axhline(y=avg_drap, color=colors[i], linestyle='--', label=f'Average')
##print(drap_dict)
#
#
# #Add labels and title
#plt.xlabel('time, min')
#plt.ylabel('µSv/h')
#plt.title(f'Radiation dose, µSv/h', fontdict={'fontsize': 16, 'fontweight': 'bold', 'fontfamily': 'serif'})
#plt.legend(loc='upper right')
#plt.show()

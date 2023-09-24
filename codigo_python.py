import requests
import matplotlib.pyplot as plt
import json
from datetime import datetime

# Fazer a solicitação HTTP para a API
url = 'http://46.17.108.113:8666/STH/v1/contextEntities/type/Lamp/id/urn:ngsi-ld:Lamp:001/attributes/luminosity?dateFrom=2023-09-21T09:00:00.237&dateTo=2023-09-21T09:15:00.237&lastN=90'
headers = {
    'fiware-service': 'smart',
    'fiware-servicepath': '/'
}

response = requests.get(url, headers=headers)

# Verificar se a solicitação foi bem-sucedida
if response.status_code == 200:
    data = json.loads(response.text)

    # Extrair as leituras de luminosidade
    luminosity_data = data['contextResponses'][0]['contextElement']['attributes'][0]['values']

    # Extrair os valores de luminosidade e as datas/horas
    luminosity_values = [entry['attrValue'] for entry in luminosity_data]
    recv_times = [entry['recvTime'] for entry in luminosity_data]

    # Converter timestamps para objetos de data e hora
    recv_times = [datetime.fromisoformat(ts[:-1]) for ts in recv_times]

    # Criar um gráfico de linha
    plt.figure(figsize=(10, 6))
    plt.plot(recv_times, luminosity_values, marker='o', linestyle='-')
    plt.title('Luminosidade por Tempo entre 9h - 9h15minutos')
    plt.xlabel('Tempo')
    plt.ylabel('Luminosidade')
    plt.xticks(rotation=45)
    plt.grid(True)
    plt.tight_layout()

    # Exibir o gráfico
    plt.show()
else:
    print(f"A solicitação falhou com o código de status {response.status_code}")
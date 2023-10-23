"""
author: Ugur AKYEL

m: A's length
n: B's length

Time Complexity: O(m+n)
Space Complexity: O(m+n)
"""
import requests

def merge(A: list, B: list) -> list:
    i = 0   # pointer for A
    j = 0   # pointer for B
    k = 0   # pointer for result arr
    m = len(A)  # A's length
    n = len(B)  # B's length
    
    merged = [None]*(m+n)
    
    while i < m and j < n:
        if A[i] <= B[j]:
            merged[k] = A[i]
            i += 1
        else:
            merged[k] = B[j]
            j += 1
        k += 1
        
    while i < m:
        merged[k] = A[i]
        i += 1
        k += 1

    while j < n:
        merged[k] = B[j]
        j += 1
        k += 1           
    
    return merged

def find_median(arr: list):
    l = len(arr)
    if l % 2 == 1:
        return arr[l // 2]
    else:
        mid1 = arr[(l // 2) - 1]
        mid2 = arr[l // 2]
        return (mid1 + mid2) / 2
    

def get_account_info(algorand_address):
    url = f'https://mainnet-api.algonode.cloud/v2/accounts/{algorand_address}'
    headers = {
        'accept': 'application/json'
    }
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        return response.json()  
    else:
        return {'error': f'{response.status_code} - {response.text}'} 


if __name__ == '__main__':
    # SLGYSO6ZRYW5FOJCYPLXSBMKFAGOV3QUZ3AZZ3LRAJMSJDDH63RIJDYJUU
    
    r = get_account_info('SLGYSO6ZRYW5FOJCYPLXSBMKFAGOV3QUZ3AZZ3LRAJMSJDDH63RIJDYJUU')
    if 'error' not in r:
        print(f"address: {r['address']}\namount: {r['amount']}\nstatus: {r['status']}")
    else:
        print(r['error'])
    
    # input1 = input("input1: ").split()
    # input2 = input("input2: ").split()
    
    # input1 = [float(num) if '.' in num else int(num) for num in input1]
    # input2 = [float(num) if '.' in num else int(num) for num in input2]
    
    # concated_arr = merge(input1, input2)
    # median_result = find_median(concated_arr)
    # print(f"output: {median_result}")
    
    
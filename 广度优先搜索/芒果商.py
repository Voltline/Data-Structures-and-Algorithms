from collections import deque

from sympy import per
def isMangoSeller(name : str) -> bool:
    if name == 'thom':
        return True
    else:
        return False
graph = {}
graph["you"] = ['alice', 'bob', 'clarie']
graph['bob'] = ['anuj', 'peggy']
graph['alice'] = ['peggy']
graph['clarie'] = ['thom', 'jonny']
graph['peggy'] = []
graph['anuj'] = []
graph['thom'] = []
graph['jonny'] = []
def search(name : str) -> bool:
    search_deque = deque()
    search_deque += graph['you']
    searched = []
    check = False
    while search_deque:
        person = search_deque.popleft()
        if person not in searched:
            if isMangoSeller(person):
                print(person + " is a Mango Seller!")
                return True
            else:
                search_deque += graph[person]
            searched.append(person)
    if not check:
        print("Not Found!")
        return False

search('you')
from collections import Counter

def getValueOfFace(value):
    if value == "T":
        return "10"
    elif value == "J":
        return "11"
    elif value == "Q":
        return "12"
    elif value == "K":
        return "13"
    elif value == "A":
        return "14"
    else:
        return value 

def getRank(p):
    player = map(lambda card: getValueOfFace(card[:-1]) + card[-1], p)
    values = sorted(map(lambda card: int(card[:-1]), player), reverse=True)
    count = Counter(values)
    freq = count.values()

    flush = all(card[-1] == player[0][-1] for card in player)
    straight = values == range(min(values), max(values) + 1)[::-1]
    
    if flush and straight and max(values) == 14:
        return [10]
    elif flush and straight:
        return [9, max(values)]
    elif 4 in freq:
        return [8, (key for key, value in count.items() if value == 4).next(), 
                   (key for key, value in count.items() if value == 1).next()]
    elif 3 in freq and 2 in freq:
        return [7, (key for key, value in count.items() if value == 3).next(), 
                   (key for key, value in count.items() if value == 2).next()]
    elif flush:
        return [6] + values
    elif straight:
        return [5, max(values)]
    elif 3 in freq:
        return ([4, (key for key, value in count.items() if value == 3).next()] + 
                    sorted(list(key for key, value in count.items() if value != 3), reverse=True))
    elif len(filter(lambda v: v == 2, freq)) == 2:
        return ([3] + sorted(list(key for key, value in count.items() if value == 2), reverse=True)
                    + [(key for key, value in count.items() if value != 2).next()])
    elif 2 in freq:
        return ([2, (key for key, value in count.items() if value == 2).next()] + 
                    sorted(list(key for key, value in count.items() if value != 2), reverse=True))
    else:
        return [1] + values
        
p1wins = 0
with open("p054_poker.txt", "r") as f:
    for line in f:
        hands = line.strip().split(" ")
        p1hand = getRank(hands[:5])
        p2hand = getRank(hands[5:])
        if p1hand > p2hand:
            p1wins += 1

print p1wins

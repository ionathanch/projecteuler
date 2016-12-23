for i in range(125874, 166667, 3):
    multiples = map(lambda j: j*i, range(2, 7))
    counters = map(lambda j: sorted(list(str(j))), multiples)
    if all(counter == counters[0] for counter in counters):
        print i, multiples
        break

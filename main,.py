x = [[1, 0, 0, 1], [0, 1, 1, 0]]

ok = True
nRobos = x[0].count(1)

for i in range(len(x)):
    if x[i].count(1) != nRobos:
        ok = False
        break

    if i == 0:
        continue

    linhaAnterior = x[i - 1]
    linhaAtual = x[i]

    prev = []
    curr = []

    for j in range(len(linhaAnterior)):
        if linhaAnterior[j] == 1:
            prev.append(j)

        if linhaAtual[j] == 1:
            curr.append(j)

    for h in range(len(curr)):
        if abs(prev[h] - curr[h]) > 1:
            ok = False
            break

print(ok)
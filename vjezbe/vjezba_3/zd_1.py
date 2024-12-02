n = input()
list = [int(num) for num in n.split()]


def generiraj_podskupove(skup):
    def rekurzivno_generiraj_podskupove(trenutni_podskup, indeks):
        if indeks == len(skup):
            svi_podskupovi.append(trenutni_podskup)
            return
        rekurzivno_generiraj_podskupove(trenutni_podskup, indeks + 1)
        rekurzivno_generiraj_podskupove(trenutni_podskup + [skup[indeks]], indeks + 1)

    svi_podskupovi = []
    rekurzivno_generiraj_podskupove([], 0)
    return svi_podskupovi

podskupovi = generiraj_podskupove(list)

for skup in podskupovi:
    print(skup)
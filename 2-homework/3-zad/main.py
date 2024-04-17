def mymax(iterable, key):
    # incijaliziraj maksimalni element i maksimalni ključ
    max_x = max_key = None
    # obiđi sve elemente
    for x in iterable:
    # ako je key(x) najveći -> ažuriraj max_x i max_key
        if max_key is None or key(x) > max_key:
            max_x = x
            max_key = key(x)

    # vrati rezultat
    return max_x

def mymaxModified(iterable, key = lambda x: x):
    max_x = max_key = None
    for x in iterable:
        if max_key is None or key(x) > max_key:
            max_x = x
            max_key = key(x)
    return max_x

if __name__ == '__main__':
    ##prvi dio - trazi se najdulja rijec, a ne najveca!
    strComparisonFunc = lambda x: len(x)
    strArr = [
    "Gle", "malu", "vocku", "poslije", "kise",
    "Puna", "je", "kapi", "pa", "ih", "njise"]
    maxStr = mymax(strArr, strComparisonFunc)
    print(f"Najveci element liste stringova {strArr} je: {maxStr}")

    ##drugi dio - anonimna funkcija definirana je kao default parametar
    ##gledamo najveci element, ne najduzi
    maxint = mymaxModified([1, 3, 5, 7, 4, 6, 9, 2, 0])
    maxchar = mymaxModified("Suncana strana ulice")
    maxstring = mymaxModified([
        "Gle", "malu", "vocku", "poslije", "kise",
        "Puna", "je", "kapi", "pa", "ih", "njise"])
    print(f"Najveci element liste integera je: {maxint}")
    print(f"Najveci element liste charova je: {maxchar}")
    print(f"Najveci element liste stringova je: {maxstring}")

    ##treci dio - dictionary
    D = {'burek': 8, 'buhtla': 5}
    dictionaryAnonFunc = lambda x: D[x]
    print(f"Najveci element rjecnika je: {mymaxModified(D, dictionaryAnonFunc)}");

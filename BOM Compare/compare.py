def extract_dictionary(file):
    rtrn = dict()
    for line in file:
        keys, tab, value = line.rpartition('\t')
        tokens = keys.split()
        for i in tokens:
            rtrn[i] = value
    return rtrn

files = [open("file1.txt", 'r'), open("file2.txt", 'r')]
dicts = [extract_dictionary(files[0]), extract_dictionary(files[1])]
closer = lambda x: x.close()
map(closer, files)

for i in list(dicts[0]):
    if dicts[0][i] != dicts[1][i]:
        print(i, ": ", dicts[0][i], "->", dicts[1][i])

